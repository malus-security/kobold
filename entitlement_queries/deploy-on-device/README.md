# Deploy Custom Executable on Device

These scripts are used to build a custom iOS executable (i.e. using custom entitlements) and deploy and run it as a CLI app on a device.

Follow the steps below:

1. Create an executable that can be deployed as a CLI app on a jailbroken iOS-running device. You can use the [tool here](https://github.com/razvand/ios-command-line-tool).

2. Create a `run.config` by copying and updating the `run.config.sample` file.

3. Update the `run.config` file accordingly. Get the `ip_addr` variable by investigating the iPhone WiFi configuration.

4. Create a results database file by running the `./createLogsDatabase.py`. It creates a `logs` database file. The database file contains 2 tables `appOutput` and `run`. `appOutput` table contain details regarding the output of the fuzzing app; `run` table contains details about the run (device version, filemon output file, crash logs folder, etc.)

5. Make sure you have the `filemon` executable in the home of the `root` user on the device. If not get it from [here](http://newosxbook.com/tools/filemon.html) and copy it on the device using SSH.

6. Run the `run.sh` script.

7. See results in `results/` subfolder and in the `logs` database file.
