#!/bin/bash

# Prerequisites: 
# brew: /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
# node: brew install node
# ios-deploy: npm install -g ios-deploy

APP_NAME=$1
XCODE_APP_PATH="/Users/mihai.carabas/Library/Developer/Xcode/DerivedData/Build/Products/Debug-iphoneos/CallingMethodsApp.app/"
CERT_ID="C65635347FCA662912D273CBEF7E5165E05BA9BE"

#Build the app
APP_NAME=`xcodebuild -project "$APP_NAME/CallingMethodsApp.xcodeproj" ARCHS="arm64" -scheme CallingMethodsApp build | grep builtin-validationUtility | xargs | cut -d " " -f2`

#Sign with entitlements
codesign --remove-signature $XCODE_APP_PATH
JDEBUG=1 jtool -arch arm64 --inplace --sign --ent ent.xml "$XCODE_APP_PATH/CallingMethodsApp"
codesign -fs $CERT_ID "$XCODE_APP_PATH"

# Run the app (I only have 1 device connected; haven't specified which device to use)
#ios-deploy --debug --bundle $APP_NAME

