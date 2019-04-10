#!/bin/bash

. run.config


function error_exit {
    echo "$1"
    exit "${2:-1}"  ## Return a code specified by $2 or 1 by default.
}

function execute_on_device {
    ssh $user@$ip_addr $1
}

function prepare_variables {
    runID=$(sqlite3 fuzzing.db 'select max(id) from runs')
    [[ $runID ]] || runID=0
    echo "runID = " $runID

    if test -z "$deviceID"; then
        exit 1
    fi

    # Output file names+path
    filemon_file=$FILEMON_FOLDER/filemon_$runID
    crash_reporter_local_folder=$CRASH_REPORTER_FOLDER/run_$runID
    app_output_file=$APP_OUTPUT_FOLDER/run_$runID.txt
    results_ent_file=$ENTS_FOLDER/ents_$runID.xml
    timestamp=`date +%d-%m-%Y_%H:%M`

}

function prepare_host {
    # Make sure device is available
    output=$(ping $ip_addr -c 1 -t 1) || error_exit "Device not found"

    # Create results folder
    mkdir -p $CRASH_REPORTER_FOLDER
    mkdir -p $FILEMON_FOLDER
    mkdir -p $APP_OUTPUT_FOLDER
    mkdir -p $ENTS_FOLDER

    rm -f run.out

    echo "Device found; host setup DONE"
}

function prepare_device {
    output=$(execute_on_device "/bin/bash -l -c 'which filemon'") || echo "filemon is not in PATH. No filemon support available!"

    # Clean device
    execute_on_device "rm -rf $DEVICE_CRASH_REPORTER_FOLDER/*"
    echo "Removed " $DEVICE_CRASH_REPORTER_FOLDER

    execute_on_device "rm -f out.exec"
}

function deploy_app {
    execute_on_device ./filemon > $filemon_file &

    echo "Start app"
    ./all.sh $binary_app $ent_file $user@$ip_addr

    # Terminate filemon
    execute_on_device "killall filemon"
    echo "Filemon Killed"
}

function post_process {
    echo "Adding logs to db"
    output=$(ls run.out) || error_exit "No output file"

    python -c 'import createLogsDatabase as db; db.add_log("run.out", '$runID')'
    python -c 'import createLogsDatabase as db; db.insert_run(
                    "'$results_ent_file'","'$app_output_file'", "'$crash_reporter_local_folder'",
                    "'$filemon_file'", "'$timestamp'", '$deviceID')'

    echo "Copying logs to results folder (CrashLogs & App Output)"

    #Crash Logs
    mkdir -p $crash_reporter_local_folder
    scp -r $user@$ip_addr:$DEVICE_CRASH_REPORTER_FOLDER/* $crash_reporter_local_folder

    #App Output
    cp run.out $app_output_file

    #Filemon output was redirected in *deploy_app*

    #Copy ent file
    cp $ent_file $results_ent_file
}

prepare_variables
prepare_host
prepare_device
deploy_app
post_process
