/*
 * Protocols for /System/Library/PrivateFrameworks/GenerationalStorage.framework/revisiond
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/TVRemoteCore.framework/XPCServices/TVRemoteConnectionService.xpc/TVRemoteConnectionService
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol TVRDaemonServerProtocol <NSObject>
- (void)stopVoiceRecordingForDeviceWithIdentifier:(NSString *)arg1;
- (void)startVoiceRecordingForDeviceWithIdentifier:(NSString *)arg1;
- (void)cancelAuthenticationChallengeForDeviceWithIdentifier:(NSString *)arg1;
- (void)sendLocallyEnteredCode:(NSString *)arg1 toDeviceWithIdentifier:(NSString *)arg2;
- (void)sendTextInputReturnKeyToDeviceWithIdentifier:(NSString *)arg1;
- (void)sendTextInputText:(NSString *)arg1 toDeviceWithIdentifier:(NSString *)arg2;
- (void)getTextInputTextAndAttributesForDeviceWithIdentifier:(NSString *)arg1 withCompletion:(void (^)(NSString *, TVRCKeyboardAttributes *, NSError *))arg2;
- (void)setVoiceRecorderAutomaticRecording:(_Bool)arg1 forDeviceWithIdentifier:(NSString *)arg2;
- (void)disconnectFromDeviceWithIdentifier:(NSString *)arg1;
- (void)sendGameControllerEvent:(TVRCGameControllerEvent *)arg1 toDeviceWithIdentifier:(NSString *)arg2;
- (void)sendTouchEvent:(TVRCTouchEvent *)arg1 toDeviceWithIdentifier:(NSString *)arg2;
- (void)sendButtonEvent:(TVRCButtonEvent *)arg1 toDeviceWithIdentifier:(NSString *)arg2;
- (void)getDeviceNameForIdentifier:(NSString *)arg1 withCompletion:(void (^)(NSString *, NSError *))arg2;
- (void)getSupportedButtonsForDeviceWithIdentifier:(NSString *)arg1 withCompletion:(void (^)(NSSet *, NSError *))arg2;
- (void)connectToDeviceWithIdentifier:(NSString *)arg1;
- (void)getPreferredDeviceIdentifier:(void (^)(NSString *))arg1;
- (void)getAllDevices:(void (^)(NSArray *, NSError *))arg1;
@end

@protocol TVRCDeviceDelegate <NSObject>

@optional
- (void)device:(TVRCDevice *)arg1 removedSupportedButtons:(NSSet *)arg2 added:(NSSet *)arg3;
- (void)deviceNameChanged:(TVRCDevice *)arg1;
- (void)device:(TVRCDevice *)arg1 disconnectedForReason:(long long)arg2 error:(NSError *)arg3;
- (void)deviceConnected:(TVRCDevice *)arg1;
- (void)device:(TVRCDevice *)arg1 encounteredAuthenticationChallenge:(TVRCDeviceAuthenticationChallenge *)arg2;
- (_Bool)deviceShouldAllowConnectionAuthentication:(TVRCDevice *)arg1;
- (void)deviceBeganConnecting:(TVRCDevice *)arg1;
@end

@protocol TVRDaemonClientProtocol <NSObject>

@optional
- (void)connectedDeviceWithInfo:(TVRDeviceInfo *)arg1 encounteredAuthenticationChallegeOfType:(long long)arg2;
- (void)connectedDeviceWithInfo:(TVRDeviceInfo *)arg1 updatedTextAttributes:(TVRCKeyboardAttributes *)arg2;
- (void)connectedDeviceWithInfo:(TVRDeviceInfo *)arg1 updatedInputText:(NSString *)arg2;
- (void)connectedDeviceWithInfoEndedTextEditing:(TVRDeviceInfo *)arg1;
- (void)connectedDeviceWithInfo:(TVRDeviceInfo *)arg1 beganTextEditingWithAttributes:(TVRCKeyboardAttributes *)arg2;
- (void)connectedDeviceWithInfo:(TVRDeviceInfo *)arg1 removedSupportedButtons:(NSSet *)arg2 added:(NSSet *)arg3;
- (void)connectedDeviceWithInfo:(TVRDeviceInfo *)arg1 changedDeviceName:(NSString *)arg2;
- (void)connectionDisconnectedFromDeviceWithInfo:(TVRDeviceInfo *)arg1 forReason:(long long)arg2 error:(NSError *)arg3;
- (void)connectedToDeviceWithInfo:(TVRDeviceInfo *)arg1;
- (void)connectionRequestStartedForDeviceWithInfo:(TVRDeviceInfo *)arg1;
- (void)connectionDidUpdateDevices:(NSArray *)arg1;
- (void)connectionDidUpdateNetworkState:(unsigned long long)arg1;
@end

@protocol TVRCDeviceQueryDelegate <NSObject>

@optional
- (void)deviceQueryDidUpdateDevices:(TVRCDeviceQuery *)arg1;
@end

@protocol TVRCKeyboardControllerDelegate <NSObject>

@optional
- (void)keyboardController:(TVRCKeyboardController *)arg1 didUpdateAttributes:(TVRCKeyboardAttributes *)arg2;
- (void)keyboardController:(TVRCKeyboardController *)arg1 didUpdateText:(NSString *)arg2;
- (void)keyboardControllerEndedTextEditing:(TVRCKeyboardController *)arg1;
- (void)keyboardController:(TVRCKeyboardController *)arg1 beganTextEditingWithAttributes:(TVRCKeyboardAttributes *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/PersonaKit.framework/personad
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/CallHistory.framework/Support/CallHistorySyncHelper
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol SyncProtocol <NSObject>
- (void)moveCallsFromTempDatabase;
- (void)bootUp:(void (^)(unsigned char))arg1;
- (void)migrateCallDB:(NSArray *)arg1 withReply:(void (^)(_Bool))arg2;
- (void)clearSyncToken:(void (^)(NSString *))arg1;
- (void)sync:(void (^)(NSString *))arg1;
- (void)appendTransactions:(NSArray *)arg1;
- (void)resetCallTimers:(void (^)(_Bool))arg1;
@end


/*
 * Protocols for /usr/libexec/nanoregistrylaunchd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NRLaunchDaemonXPCDaemonDelegate <NSObject>
- (void)xpcGetBackupHashWithCompletion:(void (^)(NSData *, NSError *))arg1;
- (void)xpcUnquarantineDataWithStoreUUID:(NSUUID *)arg1 services:(NSSet *)arg2 completion:(void (^)(NSError *))arg3;
- (void)xpcDeleteQuarantinedDataWithStoreUUID:(NSUUID *)arg1 completion:(void (^)(void))arg2;
- (void)xpcQuarantineDataWithStoreUUID:(NSUUID *)arg1 services:(NSSet *)arg2 completion:(void (^)(NSError *))arg3;
- (void)xpcCleanupPairingStoreWithUUIDs:(NSArray *)arg1 withCompletion:(void (^)(NSError *))arg2;
- (void)xpcDeletePairedStoreWithUUID:(NSUUID *)arg1 withCompletion:(void (^)(NSError *))arg2;
- (void)xpcEnableNanoDaemonsWithBool:(_Bool)arg1 withCompletion:(void (^)(NSError *))arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/MediaStream.framework/Support/mstreamd
 */

@protocol MSPauseManagerDelegate <NSObject>

@optional
- (void)pauseManagerDidUnpause:(MSPauseManager *)arg1;
- (void)pauseManagerDidPause:(MSPauseManager *)arg1;
@end

@protocol MSPowerBudgetDelegate <NSObject>
- (void)MSPowerBudgetGotSignificantEvent:(MSPowerBudget *)arg1;
- (void)MSPowerBudget:(MSPowerBudget *)arg1 didRequestStorageOfPersistedValues:(NSDictionary *)arg2;
- (NSDictionary *)MSPowerBudgetDidRequestPersistedValues:(MSPowerBudget *)arg1;
@end

@protocol APSConnectionDelegate <NSObject>
- (void)connection:(APSConnection *)arg1 didReceivePublicToken:(NSData *)arg2;

@optional
- (void)connectionDidReconnect:(APSConnection *)arg1;
- (void)connection:(APSConnection *)arg1 didChangeConnectedStatus:(_Bool)arg2;
- (void)connection:(APSConnection *)arg1 didFailToSendOutgoingMessage:(APSOutgoingMessage *)arg2 error:(NSError *)arg3;
- (void)connection:(APSConnection *)arg1 didSendOutgoingMessage:(APSOutgoingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveMessageForTopic:(NSString *)arg2 userInfo:(NSDictionary *)arg3;
- (void)connection:(APSConnection *)arg1 didReceiveIncomingMessage:(APSIncomingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveToken:(NSData *)arg2 forTopic:(NSString *)arg3 identifier:(NSString *)arg4;
@end

@protocol MSDaemonProtocols <NSObject>
- (void)forgetEverythingForPersonID:(NSString *)arg1;
- (void)unpauseForUUID:(NSString *)arg1;
- (void)pauseForUUID:(NSString *)arg1;
- (void)abortAllActivityForPersonID:(NSString *)arg1;
- (void)resetServerStateForPersonID:(NSString *)arg1;
- (void)refreshServerSideConfigurationForPersonID:(NSString *)arg1;
- (void)serverSideConfigurationForPersonID:(NSString *)arg1 reply:(void (^)(NSDictionary *))arg2;
- (void)pollForSubscriptionUpdatesTriggeredByPushNotificationForPersonID:(NSString *)arg1;
- (void)retryOutstandingActivities;
- (void)pollForSubscriptionUpdatesForPersonID:(NSString *)arg1;
- (void)deleteAssetCollections:(NSArray *)arg1 personID:(NSString *)arg2;
- (void)dequeueAssetCollectionWithGUIDs:(NSArray *)arg1 personID:(NSString *)arg2 reply:(void (^)(NSDictionary *))arg3;
- (void)enqueueAssetCollections:(NSArray *)arg1 personID:(NSString *)arg2 reply:(void (^)(NSDictionary *))arg3;
- (void)isBusyCompletionBlock:(void (^)(_Bool))arg1;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/iCloudNotification.framework/ind
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol INDaemonProtocol <NSObject>
- (void)notifyDeviceStorageLevel:(long long)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)updateOfferForAccountWithID:(NSString *)arg1 offerId:(NSString *)arg2 buttonId:(NSString *)arg3 completion:(void (^)(_Bool, NSError *))arg4;
- (void)iCloudServerOfferForAccountWithID:(NSString *)arg1 options:(NSDictionary *)arg2 completion:(void (^)(NSDictionary *, NSError *))arg3;
- (void)diagnosticReportWithCompletion:(void (^)(INDiagnosticReport *, NSError *))arg1;
- (void)clearAllRegistrationDigestsWithCompletion:(void (^)(_Bool, NSError *))arg1;
- (void)unregisterAccountWithID:(NSString *)arg1 fromiCloudNotificationsWithCompletion:(void (^)(_Bool, NSError *))arg2;
- (void)registerAccountWithID:(NSString *)arg1 foriCloudNotificationsWithReason:(unsigned long long)arg2 completion:(void (^)(_Bool, NSError *))arg3;
@end

@protocol APSConnectionDelegate <NSObject>
- (void)connection:(APSConnection *)arg1 didReceivePublicToken:(NSData *)arg2;

@optional
- (void)connectionDidReconnect:(APSConnection *)arg1;
- (void)connection:(APSConnection *)arg1 didChangeConnectedStatus:(_Bool)arg2;
- (void)connection:(APSConnection *)arg1 didFailToSendOutgoingMessage:(APSOutgoingMessage *)arg2 error:(NSError *)arg3;
- (void)connection:(APSConnection *)arg1 didSendOutgoingMessage:(APSOutgoingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveMessageForTopic:(NSString *)arg2 userInfo:(NSDictionary *)arg3;
- (void)connection:(APSConnection *)arg1 didReceiveIncomingMessage:(APSIncomingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveToken:(NSData *)arg2 forTopic:(NSString *)arg3 identifier:(NSString *)arg4;
@end

@protocol FAFamilyNotificationDelegate <NSObject>
- (void)didClearFamilyNotification:(FAFamilyNotification *)arg1;
- (void)didDismissFamilyNotification:(FAFamilyNotification *)arg1;
- (void)didActivateFamilyNotification:(FAFamilyNotification *)arg1;
@end


/*
 * Protocols for /usr/libexec/wcd
 */

@protocol WCXPCPrivateManagerDaemonProtocol <NSObject>
- (void)reconnect;
- (void)fakeIncomingPayloadOnSubService:(NSString *)arg1 ofType:(NSString *)arg2 clientData:(NSData *)arg3 resource:(NSURL *)arg4 resourceSandboxToken:(NSData *)arg5 completionHandler:(void (^)(NSError *))arg6;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol WCXPCManagerDaemonProtocol <NSObject>
- (void)acknowledgeUserInfoResultIndexWithIdentifier:(NSString *)arg1 clientPairingID:(NSString *)arg2;
- (void)acknowledgeUserInfoIndexWithIdentifier:(NSString *)arg1 clientPairingID:(NSString *)arg2;
- (void)acknowledgeFileResultIndexWithIdentifier:(NSString *)arg1 clientPairingID:(NSString *)arg2;
- (void)acknowledgeFileIndexWithIdentifier:(NSString *)arg1 clientPairingID:(NSString *)arg2;
- (void)cancelAllOutstandingMessages;
- (void)cancelSendWithIdentifier:(NSString *)arg1;
- (void)transferUserInfo:(WCSessionUserInfoTransfer *)arg1 withURL:(NSURL *)arg2 clientPairingID:(NSString *)arg3 errorHandler:(void (^)(NSError *))arg4;
- (void)transferFile:(WCSessionFileTransfer *)arg1 sandboxToken:(NSData *)arg2 clientPairingID:(NSString *)arg3 errorHandler:(void (^)(NSError *))arg4;
- (void)updateApplicationContext:(NSData *)arg1 clientPairingID:(NSString *)arg2 errorHandler:(void (^)(NSError *))arg3;
- (void)sendMessage:(WCMessage *)arg1 clientPairingID:(NSString *)arg2 acceptanceHandler:(void (^)(_Bool, _Bool))arg3;
- (void)sessionReadyForInitialStateForClientPairingID:(NSString *)arg1 supportsActiveDeviceSwitch:(_Bool)arg2 withErrorHandler:(void (^)(NSError *))arg3;
@end

@protocol WCDPKClientDelegate <NSObject>
- (void)clientRequestingComplicationUnregister:(WCDPKClient *)arg1;
- (void)clientRequestingComplicationRegister:(WCDPKClient *)arg1;
- (void)clientXPCConnectionDidDisconnect:(WCDPKClient *)arg1;
@end

@protocol IDSServiceDelegate <NSObject>

@optional
- (void)service:(IDSService *)arg1 didSwitchActivePairedDevice:(IDSDevice *)arg2 acknowledgementBlock:(void (^)(void))arg3;
- (void)serviceAllowedTrafficClassifiersDidReset:(IDSService *)arg1;
- (void)serviceSpaceDidBecomeAvailable:(IDSService *)arg1;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4 withContext:(NSData *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4 withOptions:(NSDictionary *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 hasBeenDeliveredWithContext:(id)arg4;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 didSendWithSuccess:(_Bool)arg4 error:(NSError *)arg5 context:(IDSMessageContext *)arg6;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 didSendWithSuccess:(_Bool)arg4 error:(NSError *)arg5;
- (void)service:(IDSService *)arg1 connectedDevicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 nearbyDevicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 devicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 activeAccountsChanged:(NSSet *)arg2;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingResourceAtURL:(NSURL *)arg3 metadata:(NSDictionary *)arg4 fromID:(NSString *)arg5 context:(IDSMessageContext *)arg6;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingResourceAtURL:(NSURL *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingUnhandledProtobuf:(IDSProtobuf *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingData:(NSData *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingMessage:(NSDictionary *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
@end

@protocol APSConnectionDelegate <NSObject>
- (void)connection:(APSConnection *)arg1 didReceivePublicToken:(NSData *)arg2;

@optional
- (void)connectionDidReconnect:(APSConnection *)arg1;
- (void)connection:(APSConnection *)arg1 didChangeConnectedStatus:(_Bool)arg2;
- (void)connection:(APSConnection *)arg1 didFailToSendOutgoingMessage:(APSOutgoingMessage *)arg2 error:(NSError *)arg3;
- (void)connection:(APSConnection *)arg1 didSendOutgoingMessage:(APSOutgoingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveMessageForTopic:(NSString *)arg2 userInfo:(NSDictionary *)arg3;
- (void)connection:(APSConnection *)arg1 didReceiveIncomingMessage:(APSIncomingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveToken:(NSData *)arg2 forTopic:(NSString *)arg3 identifier:(NSString *)arg4;
@end

@protocol WCDClientDelegate <NSObject>
- (void)clientReachabilityDidChange:(NSObject *)arg1;
- (void)clientXPCConnectionDidDisconnect:(NSObject *)arg1;
@end

@protocol NSXPCConnectionDelegate <NSObject>

@optional
- (void)connection:(NSXPCConnection *)arg1 handleInvocation:(NSInvocation *)arg2 isReply:(_Bool)arg3;
- (id <NSSecureCoding>)replacementObjectForXPCConnection:(NSXPCConnection *)arg1 encoder:(NSXPCCoder *)arg2 object:(id)arg3;
@end

@protocol WCDSystemObserver <NSObject>

@optional
- (void)systemObserverProcessStateChangedForBundleID:(NSString *)arg1;
- (void)systemObserverAppDidTerminateForBundleID:(NSString *)arg1;
- (void)systemObserverAppDidSuspendForBundleID:(NSString *)arg1;
- (void)systemObserverWatchAppUIStatesChanged:(NSDictionary *)arg1;
- (void)systemObserverActiveComplicationsChanged;
- (void)systemObserverRemainingComplicationUserInfoTransfersReset;
- (void)systemObserverComplicationsInstalledChanged;
- (void)systemObserverWatchAppsInstalledChanged;
- (void)systemObserverInstalledApplicationsChanged;
- (void)systemObserverRemoteFirstUnlockedChanged;
- (void)systemObserverPairedListChanged;
- (void)systemObserverActiveDeviceConnectedChanged;
- (void)systemObserverActiveDeviceSwitchStarted;
- (void)systemObserverInitialSetUpComplete;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/AssistantServices.framework/XPCServices/com.apple.siri.embeddedspeech.xpc/com.apple.siri.embeddedspeech
 */

@protocol _EARSpeechRecognitionResultStream <NSObject>
- (void)speechRecognizer:(_EARSpeechRecognizer *)arg1 didRecognizeFinalResults:(NSArray *)arg2;
- (void)speechRecognizer:(_EARSpeechRecognizer *)arg1 didFinishRecognitionWithError:(NSError *)arg2;
- (void)speechRecognizer:(_EARSpeechRecognizer *)arg1 didRecognizePartialResult:(_EARSpeechRecognitionResult *)arg2;

@optional
- (void)speechRecognizer:(_EARSpeechRecognizer *)arg1 didProduceEndpointFeaturesWithWordCount:(long long)arg2 trailingSilenceDuration:(long long)arg3 eosLikelihood:(double)arg4 pauseCounts:(NSArray *)arg5 silencePosterior:(double)arg6 processedAudioDurationInMilliseconds:(long long)arg7;
- (void)speechRecognizer:(_EARSpeechRecognizer *)arg1 didRecognizeRawEagerRecognitionCandidate:(_EARSpeechRecognition *)arg2;
- (void)speechRecognizer:(_EARSpeechRecognizer *)arg1 didProcessAudioDuration:(double)arg2;
- (void)speechRecognizer:(_EARSpeechRecognizer *)arg1 didRecognizeFinalResultPackage:(_EARSpeechRecognitionResultPackage *)arg2;
- (void)speechRecognizer:(_EARSpeechRecognizer *)arg1 didRecognizeFinalResults:(NSArray *)arg2 tokenSausage:(NSArray *)arg3 nBestChoices:(NSArray *)arg4;
@end

@protocol AFSpeechService <NSObject>
- (oneway void)runAdaptationRecipeEvaluation:(NSDictionary *)arg1 localSpeechDESRecord:(SiriCoreLocalSpeechDESRecord *)arg2 attachments:(NSArray *)arg3 completion:(void (^)(NSDictionary *, NSData *, NSError *))arg4;
- (oneway void)fetchUserDataForLanguage:(NSString *)arg1 completion:(void (^)(SiriCoreLocalSpeechUserData *))arg2;
- (oneway void)fetchAssetsForLanguage:(NSString *)arg1 completion:(void (^)(NSString *, NSError *))arg2;
- (oneway void)getOfflineDictationStatusIgnoringCache:(_Bool)arg1 withCompletion:(void (^)(NSDictionary *, NSError *))arg2;
- (oneway void)updateSpeechProfileWithLanguage:(NSString *)arg1 existingProfile:(NSData *)arg2 existingAssetPath:(NSString *)arg3 completion:(void (^)(NSData *, NSString *, NSError *))arg4;
- (oneway void)createSpeechProfileWithLanguage:(NSString *)arg1 existingProfile:(NSData *)arg2 userData:(SiriCoreLocalSpeechUserData *)arg3 completion:(void (^)(NSData *, NSError *))arg4;
- (oneway void)createSpeechProfileWithLanguage:(NSString *)arg1 JSONData:(NSData *)arg2 completion:(void (^)(NSData *, NSError *))arg3;
- (oneway void)finishAudio;
- (oneway void)addAudioPacket:(NSData *)arg1;
- (oneway void)startSpeechRecognitionWithLanguage:(NSString *)arg1 task:(NSString *)arg2 context:(NSArray *)arg3 profile:(NSData *)arg4 narrowband:(_Bool)arg5 detectUtterances:(_Bool)arg6 censorSpeech:(_Bool)arg7 maximumRecognitionDuration:(double)arg8 farField:(_Bool)arg9 overrides:(NSDictionary *)arg10 modelOverrideURL:(NSURL *)arg11 didStartHandler:(void (^)(NSString *, NSError *))arg12;
- (oneway void)startRequestActivityWithCompletion:(void (^)(void))arg1;
- (oneway void)preheatSpeechRecognitionWithLanguage:(NSString *)arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/ManagedConfiguration.framework/Support/teslad
 */

@protocol MCTeslaServiceInterface <NSObject>
- (void)unenrollWithCompletionBlock:(void (^)(_Bool, NSDictionary *, NSError *))arg1;
- (void)fetchConfigurationWithCompletionBlock:(void (^)(_Bool, NSDictionary *, NSError *))arg1;
- (void)provisionallyEnrollWithNonce:(NSString *)arg1 completionBlock:(void (^)(_Bool, NSDictionary *, NSError *))arg2;
@end

@protocol NSURLSessionDelegate <NSObject>

@optional
- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession *)arg1;
- (void)URLSession:(NSURLSession *)arg1 didReceiveChallenge:(NSURLAuthenticationChallenge *)arg2 completionHandler:(void (^)(long long, NSURLCredential *))arg3;
- (void)URLSession:(NSURLSession *)arg1 didBecomeInvalidWithError:(NSError *)arg2;
@end

@protocol NSURLSessionDataDelegate <NSURLSessionTaskDelegate>

@optional
- (void)URLSession:(NSURLSession *)arg1 dataTask:(NSURLSessionDataTask *)arg2 willCacheResponse:(NSCachedURLResponse *)arg3 completionHandler:(void (^)(NSCachedURLResponse *))arg4;
- (void)URLSession:(NSURLSession *)arg1 dataTask:(NSURLSessionDataTask *)arg2 didReceiveData:(NSData *)arg3;
- (void)URLSession:(NSURLSession *)arg1 dataTask:(NSURLSessionDataTask *)arg2 didBecomeStreamTask:(NSURLSessionStreamTask *)arg3;
- (void)URLSession:(NSURLSession *)arg1 dataTask:(NSURLSessionDataTask *)arg2 didBecomeDownloadTask:(NSURLSessionDownloadTask *)arg3;
- (void)URLSession:(NSURLSession *)arg1 dataTask:(NSURLSessionDataTask *)arg2 didReceiveResponse:(NSURLResponse *)arg3 completionHandler:(void (^)(long long))arg4;
@end

@protocol NSURLSessionTaskDelegate <NSURLSessionDelegate>

@optional
- (void)URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 didCompleteWithError:(NSError *)arg3;
- (void)URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 didFinishCollectingMetrics:(NSURLSessionTaskMetrics *)arg3;
- (void)URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 didSendBodyData:(long long)arg3 totalBytesSent:(long long)arg4 totalBytesExpectedToSend:(long long)arg5;
- (void)URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 needNewBodyStream:(void (^)(NSInputStream *))arg3;
- (void)URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 didReceiveChallenge:(NSURLAuthenticationChallenge *)arg3 completionHandler:(void (^)(long long, NSURLCredential *))arg4;
- (void)URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 willPerformHTTPRedirection:(NSHTTPURLResponse *)arg3 newRequest:(NSURLRequest *)arg4 completionHandler:(void (^)(NSURLRequest *))arg5;
- (void)URLSession:(NSURLSession *)arg1 taskIsWaitingForConnectivity:(NSURLSessionTask *)arg2;
- (void)URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 willBeginDelayedRequest:(NSURLRequest *)arg3 completionHandler:(void (^)(long long, NSURLRequest *))arg4;
@end


/*
 * Protocols for /System/Library/TextInput/kbd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol TIKeyboardActivityObserving <NSObject>
- (void)keyboardActivityDidTransition:(TIKeyboardActivityContext *)arg1;

@optional
- (void)handleMemoryPressureLevel:(unsigned long long)arg1 excessMemoryInBytes:(unsigned long long)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/DragUI.framework/Support/druid
 */

@protocol FBSSceneDelegate <NSObject>
- (void)scene:(FBSScene *)arg1 didReceiveActions:(NSSet *)arg2;
- (void)scene:(FBSScene *)arg1 didUpdateWithDiff:(FBSSceneSettingsDiff *)arg2 transitionContext:(FBSSceneTransitionContext *)arg3 completion:(void (^)(FBSWorkspaceSceneUpdateResponse *))arg4;
@end

@protocol DRTouchTrackingWindowDelegate <NSObject>
- (void)trackedTouchesCancelled:(NSSet *)arg1;
- (void)trackedTouchesEnded:(NSSet *)arg1 pairedWithVelocities:(NSSet *)arg2;
- (void)trackedTouchesMoved:(NSSet *)arg1;
- (void)trackedTouchesBegan:(NSSet *)arg1;
@end

@protocol BKSTouchDeliveryObserving <NSObject>

@optional
- (void)touchDetachedForIdentifier:(unsigned int)arg1 context:(unsigned int)arg2 pid:(int)arg3;
- (void)touchUpOccuredForIdentifier:(unsigned int)arg1 detached:(_Bool)arg2 context:(unsigned int)arg3 pid:(int)arg4;
@end

@protocol DRViewControllerDelegate <NSObject>
- (void)viewController:(DRViewController *)arg1 requestImagesForSessionID:(unsigned int)arg2 client:(id <_DUIClientSessionCommon>)arg3 itemIndexes:(NSIndexSet *)arg4;
@end

@protocol DRDataTransferSessionDelegate <NSObject>

@optional
- (void)dataTransferSessionFinished:(DRDataTransferSession *)arg1;
- (void)dataTransferSessionBegan:(DRDataTransferSession *)arg1;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol DRDragSessionDelegate <NSObject>
- (void)dragSession:(DRDragSession *)arg1 moveToLocation:(struct CGPoint)arg2;
- (void)dragSession:(DRDragSession *)arg1 enableKeyboardIfNeeded:(_Bool)arg2;
- (void)dragSessionDidEnd:(DRDragSession *)arg1;
- (void)dragSessionWillEnd:(DRDragSession *)arg1;
- (void)dragSessionAnimateOutVisibleItems:(DRDragSession *)arg1;
- (void)dragSession:(DRDragSession *)arg1 findVisibleDroppedItemsAndRemove:(_Bool)arg2 replyingOnQueue:(NSObject<OS_dispatch_queue> *)arg3 with:(void (^)(NSArray *, BKSAnimationFenceHandle *))arg4;
- (void)dragSession:(DRDragSession *)arg1 updatedPotentialDrop:(_DUIPotentialDrop *)arg2 forDestinationClient:(id <_DUIClientSessionCommon>)arg3;
- (void)dragSession:(DRDragSession *)arg1 addedItems:(NSArray *)arg2;
- (void)dragSession:(DRDragSession *)arg1 updateDetail:(_DUIItemDetail *)arg2 forClient:(id <_DUIClientSessionCommon>)arg3 itemIndex:(unsigned long long)arg4;
- (void)dragSession:(DRDragSession *)arg1 invalidateImageForClient:(id <_DUIClientSessionCommon>)arg2 itemIndex:(unsigned long long)arg3;
- (void)dragSession:(DRDragSession *)arg1 updateImageComponents:(NSArray *)arg2 preview:(_DUIPreview *)arg3 andDetail:(_DUIItemDetail *)arg4 forClient:(id <_DUIClientSessionCommon>)arg5 itemIndex:(unsigned long long)arg6 withFence:(BKSAnimationFenceHandle *)arg7;
@end

@protocol UIApplicationDelegate <NSObject>

@optional
@property(retain, nonatomic) UIWindow *window;
- (void)application:(UIApplication *)arg1 userDidAcceptCloudKitShareWithMetadata:(CKShareMetadata *)arg2;
- (void)application:(UIApplication *)arg1 didUpdateUserActivity:(NSUserActivity *)arg2;
- (void)application:(UIApplication *)arg1 didFailToContinueUserActivityWithType:(NSString *)arg2 error:(NSError *)arg3;
- (_Bool)application:(UIApplication *)arg1 continueUserActivity:(NSUserActivity *)arg2 restorationHandler:(void (^)(NSArray *))arg3;
- (_Bool)application:(UIApplication *)arg1 willContinueUserActivityWithType:(NSString *)arg2;
- (void)application:(UIApplication *)arg1 didDecodeRestorableStateWithCoder:(NSCoder *)arg2;
- (void)application:(UIApplication *)arg1 willEncodeRestorableStateWithCoder:(NSCoder *)arg2;
- (_Bool)application:(UIApplication *)arg1 shouldRestoreApplicationState:(NSCoder *)arg2;
- (_Bool)application:(UIApplication *)arg1 shouldSaveApplicationState:(NSCoder *)arg2;
- (UIViewController *)application:(UIApplication *)arg1 viewControllerWithRestorationIdentifierPath:(NSArray *)arg2 coder:(NSCoder *)arg3;
- (_Bool)application:(UIApplication *)arg1 shouldAllowExtensionPointIdentifier:(NSString *)arg2;
- (unsigned long long)application:(UIApplication *)arg1 supportedInterfaceOrientationsForWindow:(UIWindow *)arg2;
- (void)applicationProtectedDataDidBecomeAvailable:(UIApplication *)arg1;
- (void)applicationProtectedDataWillBecomeUnavailable:(UIApplication *)arg1;
- (void)applicationWillEnterForeground:(UIApplication *)arg1;
- (void)applicationDidEnterBackground:(UIApplication *)arg1;
- (void)application:(UIApplication *)arg1 handleIntent:(INIntent *)arg2 completionHandler:(void (^)(INIntentResponse *))arg3;
- (void)applicationShouldRequestHealthAuthorization:(UIApplication *)arg1;
- (void)application:(UIApplication *)arg1 handleWatchKitExtensionRequest:(NSDictionary *)arg2 reply:(void (^)(NSDictionary *))arg3;
- (void)application:(UIApplication *)arg1 handleEventsForBackgroundURLSession:(NSString *)arg2 completionHandler:(void (^)(void))arg3;
- (void)application:(UIApplication *)arg1 performActionForShortcutItem:(UIApplicationShortcutItem *)arg2 completionHandler:(void (^)(_Bool))arg3;
- (void)application:(UIApplication *)arg1 performFetchWithCompletionHandler:(void (^)(unsigned long long))arg2;
- (void)application:(UIApplication *)arg1 didReceiveRemoteNotification:(NSDictionary *)arg2 fetchCompletionHandler:(void (^)(unsigned long long))arg3;
- (void)application:(UIApplication *)arg1 handleActionWithIdentifier:(NSString *)arg2 forLocalNotification:(UILocalNotification *)arg3 withResponseInfo:(NSDictionary *)arg4 completionHandler:(void (^)(void))arg5;
- (void)application:(UIApplication *)arg1 handleActionWithIdentifier:(NSString *)arg2 forRemoteNotification:(NSDictionary *)arg3 completionHandler:(void (^)(void))arg4;
- (void)application:(UIApplication *)arg1 handleActionWithIdentifier:(NSString *)arg2 forRemoteNotification:(NSDictionary *)arg3 withResponseInfo:(NSDictionary *)arg4 completionHandler:(void (^)(void))arg5;
- (void)application:(UIApplication *)arg1 handleActionWithIdentifier:(NSString *)arg2 forLocalNotification:(UILocalNotification *)arg3 completionHandler:(void (^)(void))arg4;
- (void)application:(UIApplication *)arg1 didReceiveLocalNotification:(UILocalNotification *)arg2;
- (void)application:(UIApplication *)arg1 didReceiveRemoteNotification:(NSDictionary *)arg2;
- (void)application:(UIApplication *)arg1 didFailToRegisterForRemoteNotificationsWithError:(NSError *)arg2;
- (void)application:(UIApplication *)arg1 didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)arg2;
- (void)application:(UIApplication *)arg1 didRegisterUserNotificationSettings:(UIUserNotificationSettings *)arg2;
- (void)application:(UIApplication *)arg1 didChangeStatusBarFrame:(struct CGRect)arg2;
- (void)application:(UIApplication *)arg1 willChangeStatusBarFrame:(struct CGRect)arg2;
- (void)application:(UIApplication *)arg1 didChangeStatusBarOrientation:(long long)arg2;
- (void)application:(UIApplication *)arg1 willChangeStatusBarOrientation:(long long)arg2 duration:(double)arg3;
- (void)applicationSignificantTimeChange:(UIApplication *)arg1;
- (void)applicationWillTerminate:(UIApplication *)arg1;
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)arg1;
- (_Bool)application:(UIApplication *)arg1 openURL:(NSURL *)arg2 options:(NSDictionary *)arg3;
- (_Bool)application:(UIApplication *)arg1 openURL:(NSURL *)arg2 sourceApplication:(NSString *)arg3 annotation:(id)arg4;
- (_Bool)application:(UIApplication *)arg1 handleOpenURL:(NSURL *)arg2;
- (void)applicationWillResignActive:(UIApplication *)arg1;
- (void)applicationDidBecomeActive:(UIApplication *)arg1;
- (_Bool)application:(UIApplication *)arg1 didFinishLaunchingWithOptions:(NSDictionary *)arg2;
- (_Bool)application:(UIApplication *)arg1 willFinishLaunchingWithOptions:(NSDictionary *)arg2;
- (void)applicationDidFinishLaunching:(UIApplication *)arg1;
@end


/*
 * Protocols for /usr/libexec/gamed
 */

@protocol GKPreferencesDelegate <NSObject>

@optional
- (void)gameCenterDidBecomeRestricted;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol GKLockStatusObserver <NSObject>
- (void)lockStatusDidChange;
@end

@protocol _GKStateMachineDelegate <NSObject>

@optional
- (NSString *)missingTransitionFromState:(NSString *)arg1 toState:(NSString *)arg2;
- (void)stateDidChange;
- (void)stateWillChange;
@end

@protocol APSConnectionDelegate <NSObject>
- (void)connection:(APSConnection *)arg1 didReceivePublicToken:(NSData *)arg2;

@optional
- (void)connectionDidReconnect:(APSConnection *)arg1;
- (void)connection:(APSConnection *)arg1 didChangeConnectedStatus:(_Bool)arg2;
- (void)connection:(APSConnection *)arg1 didFailToSendOutgoingMessage:(APSOutgoingMessage *)arg2 error:(NSError *)arg3;
- (void)connection:(APSConnection *)arg1 didSendOutgoingMessage:(APSOutgoingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveMessageForTopic:(NSString *)arg2 userInfo:(NSDictionary *)arg3;
- (void)connection:(APSConnection *)arg1 didReceiveIncomingMessage:(APSIncomingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveToken:(NSData *)arg2 forTopic:(NSString *)arg3 identifier:(NSString *)arg4;
@end

@protocol GKClientProtocol <NSObject>
- (oneway void)setLogBits:(int)arg1;
- (oneway void)refreshContentsForDataType:(unsigned int)arg1 userInfo:(NSDictionary *)arg2;
- (oneway void)setBadgeCount:(unsigned long long)arg1 forType:(unsigned long long)arg2;
- (oneway void)achievementSelected:(GKAchievementInternal *)arg1;
- (oneway void)scoreSelected:(GKScoreInternal *)arg1;
- (oneway void)challengeCompleted:(GKChallengeInternal *)arg1;
- (oneway void)challengeReceived:(GKChallengeInternal *)arg1;
- (oneway void)completedChallengeSelected:(GKChallengeInternal *)arg1;
- (oneway void)receivedChallengeSelected:(GKChallengeInternal *)arg1;
- (oneway void)fetchTurnBasedData;
- (oneway void)session:(GKGameSession *)arg1 didReceiveMessage:(NSString *)arg2 withData:(NSData *)arg3 fromPlayer:(GKCloudPlayer *)arg4;
- (oneway void)session:(GKGameSession *)arg1 didReceiveData:(NSData *)arg2 fromPlayer:(GKCloudPlayer *)arg3;
- (oneway void)session:(GKGameSession *)arg1 player:(GKCloudPlayer *)arg2 didSaveData:(NSData *)arg3;
- (oneway void)session:(GKGameSession *)arg1 player:(GKCloudPlayer *)arg2 didChangeConnectionState:(long long)arg3;
- (oneway void)session:(GKGameSession *)arg1 removedPlayer:(GKCloudPlayer *)arg2;
- (oneway void)session:(GKGameSession *)arg1 addedPlayer:(GKCloudPlayer *)arg2;
- (oneway void)didReceiveData:(NSData *)arg1 reliably:(_Bool)arg2 forRecipients:(NSArray *)arg3 fromSender:(NSString *)arg4;
- (oneway void)didDisconnectFromParticipantWithID:(NSString *)arg1;
- (oneway void)didConnectToParticipantWithID:(NSString *)arg1;
- (oneway void)relayPushNotification:(NSDictionary *)arg1;
- (oneway void)cancelGameInvite:(NSString *)arg1;
- (oneway void)declineInviteWithNotification:(NSDictionary *)arg1;
- (oneway void)acceptInviteWithNotification:(NSDictionary *)arg1;
- (oneway void)acceptMultiplayerGameInvite;
- (oneway void)respondedToNearbyInvite:(NSDictionary *)arg1;
- (oneway void)friendRequestSelected:(GKFriendRequestInternal *)arg1;
- (oneway void)completedOptimisticAuthenticationWithResponse:(GKAuthenticateResponse *)arg1 error:(NSError *)arg2;
- (oneway void)authenticatedPlayersDidChange:(NSArray *)arg1 reply:(void (^)(void))arg2;
- (oneway void)setCurrentGame:(GKGameInternal *)arg1 serverEnvironment:(long long)arg2 reply:(void (^)(void))arg3;
- (oneway void)setPreferencesValues:(NSDictionary *)arg1;
- (oneway void)resetNetworkActivity;
- (oneway void)endNetworkActivity;
- (oneway void)beginNetworkActivity;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/CompanionCamera.framework/Support/companioncamerad
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NMSMessageCenterDelegate <NSObject>

@optional
- (void)messageCenter:(NMSMessageCenter *)arg1 didResolveIDSIdentifierForRequest:(NMSOutgoingRequest *)arg2;
- (void)messageCenter:(NMSMessageCenter *)arg1 didReceiveUnpairedResponse:(NMSUnpairedResponse *)arg2;
- (void)messageCenter:(NMSMessageCenter *)arg1 didReceiveUnknownRequest:(NMSIncomingRequest *)arg2;
- (void)messageCenter:(NMSMessageCenter *)arg1 didChangeConnectedState:(_Bool)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/IDS.framework/identityservicesd.app/identityservicesd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol IDSDGroupContextNotifyingObserverDelegate <NSObject>
- (void)didReceiveRegistrationIdentityUpdate;
- (void)didReceiveDecryptionFailureForGroup:(ENGroup *)arg1;
- (void)didUpdateGroup:(ENGroup *)arg1 withNewGroup:(ENGroup *)arg2;
- (void)didCacheGroup:(ENGroup *)arg1;
- (void)didCreateGroup:(ENGroup *)arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/NanoAppRegistry.framework/Support/nanoappregistryd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/PairedUnlock.framework/pairedunlockd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol PUUnlockServer <NSObject>
- (void)requestDeviceSetWristDetectionDisabled:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)queryRemoteDeviceState:(void (^)(PURemoteDeviceState *, NSError *))arg1;
- (void)didCompleteRemoteAction:(_Bool)arg1 error:(NSError *)arg2;
- (void)requestRemoteDeviceRemoveLockout;
- (void)requestRemoteDeviceUnlockNotification;
- (void)requestRemoteDeviceRemoteAction:(long long)arg1 type:(long long)arg2;
- (void)disableOnlyRemoteUnlock;
- (void)enableOnlyRemoteUnlockWithPasscode:(NSString *)arg1;
- (void)unpairForUnlock;
- (void)pairForUnlockWithPasscode:(NSString *)arg1;
- (void)checkIn;
@end

@protocol PUPairedSyncObserverDelegate <NSObject>
- (void)syncObserverRequestsWristDetectionReset:(PUPairedSyncObserver *)arg1;
@end

@protocol MCProfileConnectionObserver <NSObject>

@optional
- (void)profileConnectionDidReceiveAppWhitelistChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
- (void)profileConnectionDidReceiveDefaultsChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
- (void)profileConnectionDidReceiveEffectiveSettingsChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
- (void)profileConnectionDidReceiveProfileListChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
- (void)profileConnectionDidReceivePasscodePolicyChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
- (void)profileConnectionDidReceivePasscodeChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
- (void)profileConnectionDidReceiveRestrictionChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
@end

@protocol PUPeerDelegate <NSObject>
- (void)peer:(PUPeer *)arg1 wantsNotificationOfNextUnlock:(_Bool)arg2;
- (void)peer:(PUPeer *)arg1 remoteDeviceRequestsRemoteAction:(long long)arg2 type:(long long)arg3 existingPasscode:(NSString *)arg4 completionHandler:(void (^)(PURemoteDeviceState *, NSError *))arg5;
- (void)peer:(PUPeer *)arg1 didNotifyRemoteState:(PURemoteDeviceState *)arg2 error:(NSError *)arg3;
- (void)peerRemoteDeviceDidUnlock:(PUPeer *)arg1;
- (void)peer:(PUPeer *)arg1 didPairForUnlock:(_Bool)arg2 error:(NSError *)arg3;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/NanoSystemSettings.framework/nanosystemsettingsd
 */

@protocol IDSServiceDelegate <NSObject>

@optional
- (void)service:(IDSService *)arg1 didSwitchActivePairedDevice:(IDSDevice *)arg2 acknowledgementBlock:(void (^)(void))arg3;
- (void)serviceAllowedTrafficClassifiersDidReset:(IDSService *)arg1;
- (void)serviceSpaceDidBecomeAvailable:(IDSService *)arg1;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4 withContext:(NSData *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4 withOptions:(NSDictionary *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 hasBeenDeliveredWithContext:(id)arg4;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 didSendWithSuccess:(_Bool)arg4 error:(NSError *)arg5 context:(IDSMessageContext *)arg6;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 didSendWithSuccess:(_Bool)arg4 error:(NSError *)arg5;
- (void)service:(IDSService *)arg1 connectedDevicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 nearbyDevicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 devicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 activeAccountsChanged:(NSSet *)arg2;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingResourceAtURL:(NSURL *)arg3 metadata:(NSDictionary *)arg4 fromID:(NSString *)arg5 context:(IDSMessageContext *)arg6;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingResourceAtURL:(NSURL *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingUnhandledProtobuf:(IDSProtobuf *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingData:(NSData *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingMessage:(NSDictionary *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NSSServerProtocol <NSObject>
- (void)enableAirplaneMode:(_Bool)arg1 completionHandler:(void (^)(NSError *))arg2;
@end

@protocol NSSConnectionHandlerDelegate <NSObject>
- (void)connectionHandlerLostConnection:(NSSConnectionHandler *)arg1;
@end


/*
 * Protocols for /usr/libexec/findmydeviced
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/VideoProcessing.framework/mediaanalysisd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/CoreRecents.framework/recentsd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/FamilyNotification.framework/familynotificationd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol FAFamilyNotifierAgentProtocol <NSObject>
- (void)setDelegateMachServiceName:(NSString *)arg1;
- (void)setClientIdentifier:(NSString *)arg1;
- (void)pendingNotificationsWithIdentifier:(NSString *)arg1 replyBlock:(void (^)(NSArray *, NSError *))arg2;
- (void)removeAllNotifications;
- (void)removeNotificationWithIdentifier:(NSString *)arg1;
- (void)deliverNotificaton:(FAFamilyNotification *)arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/CoreFollowUp.framework/followupd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol FLDaemonProtocol <NSObject>
- (void)postHSA2PasswordResetNotification:(FLHSA2PasswordResetNotification *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)didActivateHSA2LoginNotificationNotification:(FLHSA2LoginNotification *)arg1;
- (void)tearDownHSA2LoginNotificationWithPushMessageID:(NSString *)arg1;
- (void)postHSA2PasswordChangeForAppleID:(NSString *)arg1 completion:(void (^)(unsigned long long, NSError *))arg2;
- (void)postHSA2LoginCode:(NSNumber *)arg1 withNotification:(FLHSA2LoginNotification *)arg2 completion:(void (^)(unsigned long long, NSError *))arg3;
- (void)postHSA2LoginNotification:(FLHSA2LoginNotification *)arg1 completion:(void (^)(unsigned long long, NSError *))arg2;
- (void)clearNotificationForItem:(FLFollowUpItem *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)clearPendingFollowUpItemsForClientIdentifier:(NSString *)arg1 uniqueIdentifiers:(NSArray *)arg2 completion:(void (^)(_Bool, NSError *))arg3;
- (void)clearPendingFollowUpItemsForClientIdentifier:(NSString *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)pendingFollowUpItemsForClientIdentifier:(NSString *)arg1 completion:(void (^)(NSArray *, NSError *))arg2;
- (void)countOfPendingFollowUpItemsForClientIdentifier:(NSString *)arg1 completion:(void (^)(unsigned long long, NSError *))arg2;
- (void)postFollowUpItem:(FLFollowUpItem *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
@end

@protocol ClientInterfaceDelegate <NSObject>
- (void)clientInterface:(ClientInterface *)arg1 wasInvalidatedWithError:(NSError *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/CoreAccessories.framework/Support/accessoryd
 */

@protocol ACCBLEPairingXPCServerProtocol <NSObject>
- (void)stopBLEUpdates:(NSString *)arg1 blePairingUUID:(NSData *)arg2;
- (void)deviceUpdatePairingInfo:(NSString *)arg1 blePairingUUID:(NSData *)arg2 pairType:(unsigned char)arg3 pairInfo:(NSData *)arg4;
- (void)devicePairingData:(NSString *)arg1 blePairingUUID:(NSData *)arg2 pairType:(unsigned char)arg3 pairData:(NSData *)arg4;
- (void)deviceStateUpdate:(NSString *)arg1 blePairingUUID:(NSData *)arg2 bRadioOn:(_Bool)arg3 pairState:(int)arg4 bPairModeOn:(_Bool)arg5;
- (void)startBLEUpdates:(NSString *)arg1 blePairingUUID:(NSData *)arg2 pairType:(unsigned char)arg3 bRadioUpdatesOn:(_Bool)arg4 bPairInfoUpdatesOn:(_Bool)arg5;
- (void)initConnection:(void (^)(_Bool))arg1;
@end

@protocol ACCAssistiveTouchXPCServerProtocol <NSObject>
- (void)notifyEnabledState:(_Bool)arg1 provider:(NSString *)arg2;
- (void)initConnection:(void (^)(_Bool))arg1;
@end

@protocol AccessoryHIDXPCServerProtocol <NSObject>
- (void)componentUpdate:(NSString *)arg1 componentID:(NSNumber *)arg2 enabled:(_Bool)arg3 withReply:(void (^)(_Bool))arg4;
- (void)getReport:(NSString *)arg1 componentID:(NSNumber *)arg2 reportType:(NSNumber *)arg3 reportID:(NSNumber *)arg4 withReply:(void (^)(_Bool))arg5;
- (void)outReport:(NSString *)arg1 componentID:(NSNumber *)arg2 report:(NSData *)arg3 withReply:(void (^)(_Bool))arg4;
- (void)initConnection:(void (^)(_Bool))arg1;
@end

@protocol ACCMediaLibraryXPCServerProtocol <NSObject>
- (void)resetUpdate:(NSString *)arg1 accessory:(NSString *)arg2;
- (void)update:(NSString *)arg1 revision:(NSString *)arg2 content:(NSDictionary *)arg3 accessory:(NSString *)arg4;
- (void)update:(NSString *)arg1 updates:(NSArray *)arg2 accessory:(NSString *)arg3;
- (void)notify:(NSString *)arg1 stateChange:(int)arg2 enabled:(_Bool)arg3;
- (void)notifyAvailableLibraries:(NSArray *)arg1 provider:(NSString *)arg2;
- (void)initConnection:(void (^)(_Bool))arg1;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol AccessoryNowPlayingXPCServerProtocol <NSObject>
- (void)playbackQueueListInfoResponse:(NSString *)arg1 requestID:(NSString *)arg2 info:(NSDictionary *)arg3;
- (void)playbackQueueListChanged;
- (void)playbackAttributesHaveChanged:(NSDictionary *)arg1 withReply:(void (^)(_Bool))arg2;
- (void)mediaItemArtworkHasChanged:(NSData *)arg1 withReply:(void (^)(_Bool))arg2;
- (void)mediaItemAttributesHaveChanged:(NSDictionary *)arg1 withReply:(void (^)(_Bool))arg2;
- (void)initConnection:(void (^)(_Bool))arg1;
@end

@protocol AccessoryCameraXPCServerProtocol <NSObject>
- (void)captureStillImage:(NSString *)arg1 forCameraIds:(NSArray *)arg2 withReply:(void (^)(int))arg3;
- (void)stopLivePreview:(NSString *)arg1 forCameraIds:(NSArray *)arg2 withReply:(void (^)(int))arg3;
- (void)startLivePreview:(NSString *)arg1 forCameraIds:(NSArray *)arg2 withIndex:(unsigned short)arg3 withReply:(void (^)(int))arg4;
- (void)setCameraProperties:(NSString *)arg1 forCameraId:(unsigned short)arg2 withProperties:(NSDictionary *)arg3 withReply:(void (^)(int))arg4;
- (void)stopCameraUpdates:(NSString *)arg1 forCameraIds:(NSArray *)arg2 withReply:(void (^)(int))arg3;
- (void)startCameraUpdates:(NSString *)arg1 forCameraIds:(NSArray *)arg2 withProperties:(NSDictionary *)arg3 withCapabilities:(NSDictionary *)arg4 withReply:(void (^)(int))arg5;
- (void)stopCameraInfo:(NSString *)arg1 forCameraIds:(NSArray *)arg2 withReply:(void (^)(int))arg3;
- (void)startCameraInfo:(NSString *)arg1 forCameraIds:(NSArray *)arg2 withReply:(void (^)(int))arg3;
- (void)initConnection:(void (^)(_Bool))arg1;
@end

@protocol ACCVoiceOverXPCServerProtocol <NSObject>
- (void)update:(NSString *)arg1 cursorInfo:(NSDictionary *)arg2;
- (void)update:(NSString *)arg1 info:(NSDictionary *)arg2;
- (void)initConnection:(void (^)(_Bool))arg1;
@end

@protocol ACCAudioXPCServerProtocol <NSObject>
- (void)deviceAudioStatesWithReply:(void (^)(NSArray *))arg1;
- (void)supportedDigitalAudioSampleRatesWithReply:(void (^)(NSArray *))arg1;
- (void)supportedDigitalAudioSampleRate:(unsigned int)arg1 withReply:(void (^)(unsigned int))arg2;
- (void)setDigitalAudioSampleRate:(unsigned int)arg1 withReply:(void (^)(_Bool))arg2;
- (void)initConnectionToServer:(void (^)(_Bool))arg1;
@end

@protocol ACCNavigationXPCServerProtocol <NSObject>
- (void)notifyOfProvider:(NSString *)arg1;
- (void)routeGuidance:(NSString *)arg1 laneGuidanceInfo:(NSDictionary *)arg2 componentIdList:(NSArray *)arg3;
- (void)routeGuidance:(NSString *)arg1 maneuverUpdateInfo:(NSDictionary *)arg2 componentIdList:(NSArray *)arg3;
- (void)routeGuidance:(NSString *)arg1 updateInfo:(NSDictionary *)arg2 componentIdList:(NSArray *)arg3;
- (void)initConnection:(void (^)(_Bool))arg1;
@end

@protocol ACCCommunicationsXPCServerProtocol <NSObject>
- (void)commStatusDidChange:(NSDictionary *)arg1;
- (void)callStateDidChange:(NSDictionary *)arg1;
- (void)initConnection:(void (^)(_Bool))arg1;
@end

@protocol ACCOOBBTPairingXPCServerProtocol <NSObject>
- (void)requestLegacyConnectionIDForAccessoryUID:(NSString *)arg1;
- (void)notifyOfProvider:(NSString *)arg1;
- (void)linkKeyInfo:(NSString *)arg1 oobBtPairingUID:(NSString *)arg2 linkKey:(NSData *)arg3 deviceMacAddr:(NSData *)arg4;
- (void)stopOOBBTPairing:(NSString *)arg1;
- (void)startOOBBTPairing:(NSString *)arg1;
- (void)initConnection:(void (^)(_Bool))arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/NanoLeash.framework/companionfindlocallyd
 */

@protocol IDSServiceDelegate <NSObject>

@optional
- (void)service:(IDSService *)arg1 didSwitchActivePairedDevice:(IDSDevice *)arg2 acknowledgementBlock:(void (^)(void))arg3;
- (void)serviceAllowedTrafficClassifiersDidReset:(IDSService *)arg1;
- (void)serviceSpaceDidBecomeAvailable:(IDSService *)arg1;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4 withContext:(NSData *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4 withOptions:(NSDictionary *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 hasBeenDeliveredWithContext:(id)arg4;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 didSendWithSuccess:(_Bool)arg4 error:(NSError *)arg5 context:(IDSMessageContext *)arg6;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 didSendWithSuccess:(_Bool)arg4 error:(NSError *)arg5;
- (void)service:(IDSService *)arg1 connectedDevicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 nearbyDevicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 devicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 activeAccountsChanged:(NSSet *)arg2;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingResourceAtURL:(NSURL *)arg3 metadata:(NSDictionary *)arg4 fromID:(NSString *)arg5 context:(IDSMessageContext *)arg6;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingResourceAtURL:(NSURL *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingUnhandledProtobuf:(IDSProtobuf *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingData:(NSData *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingMessage:(NSDictionary *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NFMCompanionFindMyController <NSObject>
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/UserActivity.framework/Agents/useractivityd
 */

@protocol UAUserActivityClientProtocol <NSObject>
- (void)doGetLoggingFileForClient:(NSString *)arg1 options:(NSDictionary *)arg2 completionHandler:(void (^)(NSFileHandle *, NSError *))arg3;
- (void)doDetermineIfUserActivityIsCurrent:(NSUUID *)arg1 completionHandler:(void (^)(_Bool, NSString *, int, NSString *, NSError *))arg2;
- (void)doGetCurrentUserActivityInfo:(void (^)(NSUUID *, NSString *, NSError *))arg1;
- (void)doPinUserActivityInfo:(UAUserActivityInfo *)arg1 completionHandler:(void (^)(NSUUID *, NSError *))arg2;
- (void)doMarkUserActivityAsDirty:(NSUUID *)arg1 forceImmediate:(_Bool)arg2 webpageURL:(NSURL *)arg3 expiration:(NSDate *)arg4 hasiCloudDocument:(_Bool)arg5 hasUnsynchronizediCloudDoc:(_Bool)arg6;
- (void)doRemoveDynamicUserActivity:(NSString *)arg1 matching:(NSString *)arg2;
- (void)doAddDynamicUserActivity:(NSString *)arg1 matching:(NSString *)arg2;
- (void)doDeleteUserActivityWithUUID:(NSUUID *)arg1;
- (void)doUpdateUserActivityWithUUID:(NSUUID *)arg1 setActive:(_Bool)arg2;
- (void)doUpdateUserActivityInfo:(UAUserActivityInfo *)arg1 makeCurrent:(_Bool)arg2 completionHandler:(void (^)(NSError *))arg3;
- (void)doFetchUserActivityInfoWithUUID:(NSUUID *)arg1 completionHandler:(void (^)(UAUserActivityInfo *, NSError *))arg2;
- (void)doInitializeWithClientVersion:(long long)arg1 clientInfo:(NSDictionary *)arg2 completionHandler:(void (^)(long long, NSDictionary *, NSError *))arg3;
@end

@protocol SFCompanionAdvertiserDelegate <NSObject>

@optional
- (void)advertiser:(SFCompanionAdvertiser *)arg1 didReceiveInputStream:(NSInputStream *)arg2 outputStream:(NSOutputStream *)arg3;
@end

@protocol UAResumableActivitiesSysdiagnoseSupportProtocol <NSObject>
- (void)doCopyRecentActions:(NSDictionary *)arg1 completionHandler:(void (^)(NSArray *))arg2;
- (void)doGetSysdiagnoseStringsIncludingPrivateData:(_Bool)arg1 completionHandler:(void (^)(NSArray *))arg2;
- (void)doNOP:(NSString *)arg1 withCompletionHandler:(void (^)(NSString *, NSError *))arg2;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol UAUserActivityDebugLoggingProtocol <NSObject>
- (void)doGetLoggingFileForClient:(NSString *)arg1 options:(NSDictionary *)arg2 completionHandler:(void (^)(NSFileHandle *, NSError *))arg3;
@end

@protocol UABestAppSuggestionManagerProtocol <NSObject>
- (void)doLaunchFollowUp:(NSUUID *)arg1 interactionType:(unsigned long long)arg2 cancelled:(_Bool)arg3;
- (void)doQueueFetchOfPayloadForBestAppSuggestion:(NSUUID *)arg1 completionHandler:(void (^)(NSError *))arg2;
- (void)doUnregisterForBestAppChangeNotification;
- (void)doRegisterForBestAppChangeNotification;
- (void)doRemoveBestAppSuggestion:(NSUUID *)arg1 options:(NSDictionary *)arg2;
- (void)doDetermineBestAppSuggestions:(long long)arg1 completionHandler:(void (^)(NSArray *, NSError *))arg2;
- (void)doDetermineBestAppSuggestionWithCompletionHandler:(void (^)(NSUUID *, unsigned long long, NSString *, NSString *, NSDate *, double, NSString *, NSString *, NSString *))arg1;
- (void)doStartBestAppSuggestion:(double)arg1;
- (void)doConnected;
@end

@protocol UASharedPasteboardControllProtocol <NSObject>
- (void)startConnection:(int)arg1;
@end

@protocol UAResumableActivitiesAdministrativeProtocol <NSObject>
- (void)doGetSFActivityAdvertisement:(NSDictionary *)arg1 completionHandler:(void (^)(NSData *, NSDate *, NSUUID *, NSError *))arg2;
- (void)doSetLocalPasteboardReflection:(_Bool)arg1;
- (void)doSetRemotePasteboardAvalible:(_Bool)arg1;
- (void)doReplayCommands:(NSArray *)arg1 completionHandler:(void (^)(_Bool, NSError *))arg2;
- (void)getCurrentPeersAndClear:(_Bool)arg1 completionHandler:(void (^)(UAPingResults *))arg2;
- (void)stopAdvertisingPing;
- (void)startAdvertisingPingWithTimeInterval:(double)arg1;
- (void)doSetupRendevous:(NSString *)arg1 domain:(NSString *)arg2 activate:(_Bool)arg3;
- (void)doSetupNetworkedPairs:(NSString *)arg1 port:(long long)arg2;
- (void)doBroadcastPing:(void (^)(UAPingResults *))arg1;
- (void)doWillSaveDelegate:(NSUUID *)arg1 completionHandler:(void (^)(NSError *))arg2;
- (void)doSetDefaults:(NSString *)arg1 value:(NSObject<NSSecureCoding> *)arg2;
- (void)doCopyDefaults:(_Bool)arg1 completionHandler:(void (^)(NSDictionary *, NSError *))arg2;
- (void)doCopySimulatorStatusString:(NSDictionary *)arg1 completionHandler:(void (^)(NSString *))arg2;
- (void)doInjectBTLE:(NSUUID *)arg1 type:(unsigned long long)arg2 identifier:(NSString *)arg3 title:(NSString *)arg4 activityPayload:(NSData *)arg5 frameworkPayload:(NSData *)arg6 payloadDelay:(double)arg7;
- (void)doGetCurrentAdvertisedItemUUID:(void (^)(NSUUID *))arg1;
- (void)doTerminateServer;
- (void)doCopyDynamicUserActivitiesString:(NSDictionary *)arg1 completionHandler:(void (^)(NSString *))arg2;
- (void)doCopyStatusString:(NSString *)arg1 options:(NSDictionary *)arg2 completionHandler:(void (^)(NSString *))arg3;
- (void)doCopyRecentActions:(NSDictionary *)arg1 completionHandler:(void (^)(NSArray *))arg2;
- (void)doCopyDebuggingInfo:(NSDictionary *)arg1 completionHandler:(void (^)(NSDictionary *))arg2;
- (void)doCopyEnabledUUIDsWithCompletionHandler:(void (^)(NSArray *))arg1;
- (void)doCopyAllUUIDsOfType:(unsigned long long)arg1 withCompletionHandler:(void (^)(NSArray *))arg2;
- (void)doCopyAdvertisedUUIDWithCompletionHandler:(void (^)(NSUUID *))arg1;
- (void)doFindMatchingUserActivityForString:(NSString *)arg1 withCompletionHandler:(void (^)(NSUUID *))arg2;
- (void)doSetDebugOption:(NSString *)arg1 value:(id)arg2;
- (void)doNOP:(NSString *)arg1 withCompletionHandler:(void (^)(NSString *, NSError *))arg2;
@end

@protocol UASharedPasteboardManagerProtocol <NSObject>
- (void)setReturnPasteboardDataEarlyWithCompletion:(void (^)(_Bool))arg1;
- (void)fetchRemotePasteboardForProcess:(int)arg1 withCompletion:(void (^)(UASharedPasteboardInfo *, NSError *))arg2;
- (void)fetchRemotePasteboardTypesForProcess:(int)arg1 withCompletion:(void (^)(UASharedPasteboardInfo *, NSError *))arg2;
- (void)localPasteboardTypesDidChange:(UASharedPasteboardInfo *)arg1 forGeneration:(unsigned long long)arg2;
- (void)clearLocalPasteboardInformation;
- (void)fetchRemotePasteboardStatus:(void (^)(_Bool))arg1;
@end

@protocol UASharedPasteboardAUXProtocol <NSObject>
- (void)setReturnPasteboardDataEarlyWithCompletion:(void (^)(_Bool))arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/NanoTimeKitCompanion.framework/nanotimekitcompaniond
 */

@protocol NTKDFaceSnapshotControllerObserver <NSObject>
- (void)faceSnapshotChangedForKey:(NSString *)arg1;
@end

@protocol NTKDComplicationStoreObserver <NSObject>
- (void)complicationStore:(NTKDComplicationStore *)arg1 didRemoveComplicationForClientIdentifier:(NSString *)arg2 seqId:(NSNumber *)arg3;
- (void)complicationStore:(NTKDComplicationStore *)arg1 didUpdateLocalizableSampleTemplate:(CLKComplicationTemplate *)arg2 forClientIdentifier:(NSString *)arg3 family:(long long)arg4 seqId:(NSNumber *)arg5;
- (void)complicationStore:(NTKDComplicationStore *)arg1 loadFullCollectionWithLocalizableSampleTemplates:(NSDictionary *)arg2 seqId:(NSNumber *)arg3;
@end

@protocol NTKCollectionServer <NSObject>
- (void)flushUpdatesWithIdentifier:(NSString *)arg1;
- (void)resetCollection;
- (void)upgradeFace:(NTKFace *)arg1 forUUID:(NSUUID *)arg2;
- (void)removeFaceForUUID:(NSUUID *)arg1;
- (void)addFace:(NTKFace *)arg1 forUUID:(NSUUID *)arg2;
- (void)updateFaceForUUID:(NSUUID *)arg1 withResourceDirectory:(NSString *)arg2;
- (void)updateFaceForUUID:(NSUUID *)arg1 withConfiguration:(NTKFaceConfiguration *)arg2;
- (void)setOrderedFaceUUIDs:(NSArray *)arg1;
- (void)setSelectedFaceUUID:(NSUUID *)arg1;
- (void)registerForCollectionIdentifier:(NSString *)arg1 deviceUUID:(NSUUID *)arg2 withSeqId:(NSNumber *)arg3;
@end

@protocol NTKComplicationStoreServer <NSObject>
- (void)removeComplicationForClientIdentifier:(NSString *)arg1;
- (void)updateLocalizableSampleDataTemplate:(CLKComplicationTemplate *)arg1 forClientIdentifier:(NSString *)arg2 family:(long long)arg3;
- (void)registerForCollectionIdentifier:(NSString *)arg1 deviceUUID:(NSUUID *)arg2 withSeqId:(NSNumber *)arg3;
@end

@protocol NTKDCollectionStoreObserver <NSObject>
- (void)collectionStore:(NTKDCollectionStore *)arg1 didUpgradeFace:(NTKFace *)arg2 forUUID:(NSUUID *)arg3 seqId:(NSNumber *)arg4;
- (void)collectionStore:(NTKDCollectionStore *)arg1 didRemoveFaceOfStyle:(long long)arg2 forUUID:(NSUUID *)arg3 seqId:(NSNumber *)arg4 acknowledge:(void (^)(void))arg5;
- (void)collectionStore:(NTKDCollectionStore *)arg1 didAddFace:(NTKFace *)arg2 forUUID:(NSUUID *)arg3 seqId:(NSNumber *)arg4;
- (void)collectionStore:(NTKDCollectionStore *)arg1 didUpdateFaceForUUID:(NSUUID *)arg2 withResourceDirectory:(NSString *)arg3 seqId:(NSNumber *)arg4 acknowledge:(void (^)(void))arg5;
- (void)collectionStore:(NTKDCollectionStore *)arg1 didUpdateFaceForUUID:(NSUUID *)arg2 withConfiguration:(NTKFaceConfiguration *)arg3 seqId:(NSNumber *)arg4;
- (void)collectionStore:(NTKDCollectionStore *)arg1 didUpdateOrderedUUIDs:(NSArray *)arg2 seqId:(NSNumber *)arg3;
- (void)collectionStore:(NTKDCollectionStore *)arg1 didUpdateSelectedUUID:(NSUUID *)arg2 seqId:(NSNumber *)arg3;
- (void)collectionStore:(NTKDCollectionStore *)arg1 loadOrderedUUIDs:(NSArray *)arg2 selectedUUID:(NSUUID *)arg3 facesByUUID:(NSDictionary *)arg4 seqId:(NSNumber *)arg5 acknowledge:(void (^)(void))arg6;

@optional
- (void)resetCollectionStore:(NTKDCollectionStore *)arg1;
@end


/*
 * Protocols for /usr/libexec/securityd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/CryptoTokenKit.framework/ctkd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/Frameworks/WatchKit.framework/Support/companionappd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol SPDaemonManagerTransactionObserver <NSObject>

@optional
- (void)daemonManagerWillEndXPCTransaction;
- (void)daemonManagerDidBeginXPCTransaction;
@end

@protocol SPLocalServerProtocol <NSObject>
- (void)wakeExtensionForWatchApp:(NSString *)arg1;
- (void)hideUserNotification;
- (void)showUserNotification:(long long)arg1 applicationName:(NSString *)arg2;
- (void)xcodeWillInstallSockPuppetAppWithCompanionAppIdentifier:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (void)getCompanionExtensionPIDForCompanionAppWithIdentifier:(NSString *)arg1 completion:(void (^)(NSError *, int))arg2;
- (void)getSockPuppetAppRunningStatusForCompanionAppWithIdentifier:(NSString *)arg1 completion:(void (^)(NSError *, _Bool))arg2;
- (void)terminateSockPuppetAppForCompanionAppWithIdentifier:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (void)launchSockPuppetAppForCompanionAppWithIdentifier:(NSString *)arg1 options:(NSDictionary *)arg2 completion:(void (^)(_Bool, NSError *))arg3;
- (void)activeComplicationsWithCompletion:(void (^)(NSArray *))arg1;
- (void)fetchInstalledApplicationsWithCompletion:(void (^)(NSDictionary *))arg1;
@end

@protocol SPTransportDelegate <NSObject>
- (_Bool)unlockedSinceBoot;

@optional
- (NSDate *)dateOfFirstUnlock;
- (void)didReceiveSecureData;
- (void)incomingProtobuf:(IDSProtobuf *)arg1;
- (void)logDataSent:(unsigned long long)arg1 application:(NSString *)arg2;
- (void)incomingData:(NSData *)arg1;
@end

@protocol SPCompanionAppServerProtocol <NSObject>
- (void)extensionWithIdentifier:(NSString *)arg1 gotUnknownInterfaceController:(NSString *)arg2;
- (void)launchCompanionAppForGizmoAppWithIdentifier:(NSString *)arg1 withUserInfoData:(NSData *)arg2 reply:(void (^)(NSDictionary *, NSError *, long long, NSString *))arg3;
- (void)requestTimingData:(NSString *)arg1 timingMetaData:(NSDictionary *)arg2;
- (void)fetchNotificationForNotificationID:(NSString *)arg1 completion:(void (^)(NSDictionary *, NSData *, NSData *, NSError *))arg2;
- (void)sendData:(NSData *)arg1 identifier:(NSString *)arg2 clientIdentifiers:(NSArray *)arg3 reply:(void (^)(NSData *, NSError *))arg4;
- (void)sendData:(NSData *)arg1 identifier:(NSString *)arg2 clientIdentifiers:(NSArray *)arg3;
- (void)sendCacheRequest:(NSData *)arg1 identifier:(NSString *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/MapsSupport.framework/nanomapscd
 */

@protocol GEOResourceManifestTileGroupObserver <NSObject>

@optional
- (void)resourceManifestManager:(GEOResourceManifestManager *)arg1 didChangeActiveTileGroup:(GEOActiveTileGroup *)arg2 fromOldTileGroup:(GEOActiveTileGroup *)arg3;
- (void)resourceManifestManagerDidChangeActiveTileGroup:(GEOResourceManifestManager *)arg1;
- (void)resourceManifestManagerWillChangeActiveTileGroup:(GEOResourceManifestManager *)arg1;
@end

@protocol GEOExperimentConfigurationObserver <NSObject>

@optional
- (void)experimentConfigurationDidChange:(GEOExperimentConfiguration *)arg1;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NMDeviceConnectionObserver <NSObject>

@optional
- (void)connectionNeedsStateSynchronization:(NMDeviceConnection *)arg1;
- (void)connection:(NMDeviceConnection *)arg1 didChangeDeviceNearby:(_Bool)arg2;
- (void)connection:(NMDeviceConnection *)arg1 didChangeDeviceConnectivity:(_Bool)arg2;
@end

@protocol NMCSyncManagerDelegate <NSObject>
- (void)syncManager:(NMCSyncManager *)arg1 didRequestInitialSync:(void (^)(NSError *))arg2;
- (void)syncManagerDidUpdate:(NMCSyncManager *)arg1;
@end

@protocol NMCServerXPCInterface <GEONavXPCInterface>
- (void)invalidateNavigationSessionWithRouteContext:(NSData *)arg1;
- (void)pingForNavigationBarrier:(void (^)(void))arg1;
@end

@protocol NRDevicePropertyObserver <NSObject>
- (void)device:(NRDevice *)arg1 propertyDidChange:(NSString *)arg2 fromValue:(id)arg3;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/VisualVoicemail.framework/vmd
 */

@protocol VMServerXPCProtocol <NSObject>
- (void)reportTranscriptionRatedAccurate:(_Bool)arg1 forIdentifier:(long long)arg2;
- (void)reportTranscriptionProblemForIdentifier:(long long)arg1;
- (void)changePassword:(NSString *)arg1 completionBlock:(void (^)(NSError *))arg2;
- (void)removeAllVoicemails;
- (void)retrieveDataForIdentifier:(long long)arg1;
- (void)setReadForIdentifiers:(NSArray *)arg1;
- (void)setReadForIdentifier:(long long)arg1;
- (void)setDeletedForIdentifiers:(NSArray *)arg1;
- (void)setDeletedForIdentifier:(long long)arg1;
- (void)removeVoicemailFromTrashWithIdentifier:(long long)arg1;
- (void)setTrashedForIdentifiers:(NSArray *)arg1;
- (void)setVoicemailGreeting:(VMVoicemailGreeting *)arg1 completionBlock:(void (^)(NSError *))arg2;
- (void)retrieveVoicemailGreeting:(void (^)(VMVoicemailGreeting *, NSError *))arg1;
- (void)allVoicemails:(void (^)(NSOrderedSet *))arg1;
- (void)synchronize;
- (void)requestInitialState:(void (^)(VMVoicemailCapabilities *, NSOrderedSet *, _Bool, _Bool, _Bool))arg1;
@end


/*
 * Protocols for /usr/libexec/addressbooksyncd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/DeviceCheckInternal.framework/devicecheckd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol DCDeviceMetadataProtocol <NSObject>
- (void)fetchOpaqueBlobWithCompletion:(void (^)(NSData *, NSError *))arg1;
@end


/*
 * Protocols for /System/Library/Frameworks/Contacts.framework/Support/contactsd
 */

@protocol CNXPCDataMapperService <NSObject>
- (void)reindexSearchableItemsWithIdentifiers:(NSArray *)arg1 withReply:(void (^)(void))arg2;
- (void)writeFavoritesPropertyListData:(NSData *)arg1 toPath:(NSString *)arg2 withReply:(void (^)(_Bool, NSError *))arg3;
- (void)favoritesEntryDictionariesAtPath:(NSString *)arg1 withReply:(void (^)(NSArray *, NSError *))arg2;
- (void)clearChangeHistoryForClientIdentifier:(NSString *)arg1 toChangeAnchor:(CNChangeHistoryAnchor *)arg2 withReply:(void (^)(NSNumber *, NSError *))arg3;
- (void)changeHistoryWithFetchRequest:(CNChangeHistoryFetchRequest *)arg1 withReply:(void (^)(CNChangeHistoryResult *, NSError *))arg2;
- (void)unregisterChangeHistoryClientIdentifier:(NSString *)arg1 withReply:(void (^)(NSNumber *, NSError *))arg2;
- (void)registerChangeHistoryClientIdentifier:(NSString *)arg1 withReply:(void (^)(NSNumber *, NSError *))arg2;
- (void)userActivityForContact:(CNContact *)arg1 withReply:(void (^)(NSDictionary *))arg2;
- (void)contactWithUserActivityUserInfo:(NSDictionary *)arg1 keysToFetch:(NSArray *)arg2 withReply:(void (^)(CNContact *))arg3;
- (void)setBestMeIfNeededForGivenName:(NSString *)arg1 familyName:(NSString *)arg2 email:(NSString *)arg3 withReply:(void (^)(NSNumber *, NSError *))arg4;
- (void)setMeContact:(CNContact *)arg1 forContainer:(CNContainer *)arg2 withReply:(void (^)(NSNumber *, NSError *))arg3;
- (void)setMeContact:(CNContact *)arg1 withReply:(void (^)(NSNumber *, NSError *))arg2;
- (void)defaultContainerIdentifierWithReply:(void (^)(NSString *, NSError *))arg1;
- (void)subgroupsOfGroupWithIdentifier:(NSString *)arg1 withReply:(void (^)(NSArray *, NSError *))arg2;
- (void)groupsMatchingPredicate:(NSPredicate *)arg1 withReply:(void (^)(NSArray *, NSError *))arg2;
- (void)accountsMatchingPredicate:(NSPredicate *)arg1 withReply:(void (^)(NSArray *, NSError *))arg2;
- (void)policyForContainerWithIdentifier:(NSString *)arg1 withReply:(void (^)(CNPolicy *, NSError *))arg2;
- (void)serverSearchContainersMatchingPredicate:(NSPredicate *)arg1 withReply:(void (^)(NSArray *, NSError *))arg2;
- (void)containersMatchingPredicate:(NSPredicate *)arg1 withReply:(void (^)(NSArray *, NSError *))arg2;
- (void)executeSaveRequest:(CNSaveRequest *)arg1 withReply:(void (^)(_Bool, CNSaveResponse *, NSError *))arg2;
- (void)meContactIdentifiersWithReply:(void (^)(NSArray *, NSError *))arg1;
- (void)progressiveContactsForFetchRequest:(CNContactFetchRequest *)arg1 progressHandler:(id <ProgressiveResultsHandlerProtocol>)arg2 reply:(void (^)(id <CNCancelable>))arg3;
- (void)nextEncodedContactsForCursor:(id <CNEncodedFetchCursor>)arg1 withReply:(void (^)(NSData *, _Bool, NSError *))arg2;
- (void)encodedContactsAndCursorForFetchRequest:(CNContactFetchRequest *)arg1 withReply:(void (^)(NSData *, id <CNEncodedFetchCursor>, NSError *))arg2;
- (void)contactsForFetchRequest:(CNContactFetchRequest *)arg1 withMatchInfoReply:(void (^)(NSArray *, NSDictionary *, NSError *))arg2;
- (void)unifiedContactCountWithReply:(void (^)(NSNumber *, NSError *))arg1;
- (void)identifierWithReply:(void (^)(NSString *, NSError *))arg1;
- (void)configureServiceWithOptions:(NSDictionary *)arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/MusicLibrary.framework/Support/medialibraryd
 */

@protocol ML3MusicLibraryDelegate <NSObject>

@optional
- (void)library:(ML3MusicLibrary *)arg1 didRollbackDatabaseTransactionWithConnection:(ML3DatabaseConnection *)arg2;
- (void)library:(ML3MusicLibrary *)arg1 didCommitDatabaseTransactionWithConnection:(ML3DatabaseConnection *)arg2;
- (void)library:(ML3MusicLibrary *)arg1 didBeginDatabaseTransactionWithConnection:(ML3DatabaseConnection *)arg2;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol MLDDiagnosticCollection <NSObject>
- (void)collectDiagnostic:(MLDMutableDiagnostic *)arg1;
@end

@protocol MLMediaLibraryServiceProtocol <NSObject>
- (void)performMaintenanceTasksForDatabaseAtPath:(NSString *)arg1 withCompletionHandler:(void (^)(_Bool, NSError *))arg2;
- (void)performRestoreOfLatestBackupForDatabaseAtPath:(NSString *)arg1 withCompletion:(void (^)(_Bool, NSError *))arg2;
- (void)performBackupOfDatabaseAtPath:(NSString *)arg1 withCompletion:(void (^)(_Bool, NSError *))arg2;
- (void)updateSpotlightIndexMetadataForItemsWithIdentifiers:(NSArray *)arg1 bundleID:(NSString *)arg2 withCompletion:(void (^)(_Bool, NSError *))arg3;
- (void)updateSpotlightIndexForBundleID:(NSString *)arg1 withCompletion:(void (^)(_Bool, NSError *))arg2;
- (void)setDeviceSharedLibraryPath:(NSString *)arg1 withCompletion:(void (^)(_Bool, NSError *))arg2;
- (void)getDeviceSharedLibraryPath:(void (^)(NSString *))arg1;
- (void)getLanguageResourcesWithCompletion:(void (^)(ML3LanguageResources *, NSError *))arg1;
- (void)unlockDatabaseWithCompletion:(void (^)(_Bool, NSError *))arg1;
- (void)lockDatabaseForReason:(NSString *)arg1 withCompletion:(void (^)(_Bool, NSError *))arg2;
- (void)cancelImportOperation:(unsigned long long)arg1 completionHandler:(void (^)(_Bool, NSError *))arg2;
- (void)performImport:(ML3DatabaseImport *)arg1 fromSource:(unsigned long long)arg2 withUUID:(NSUUID *)arg3 completionHandler:(void (^)(_Bool, NSError *, NSData *))arg4;
- (void)setOptions:(NSDictionary *)arg1 withCompletionHandler:(void (^)(_Bool, NSError *))arg2;
- (void)performDatabaseOperation:(unsigned long long)arg1 withAttributes:(NSDictionary *)arg2 options:(NSDictionary *)arg3 completionHandler:(void (^)(_Bool, NSError *))arg4;
- (void)endTransaction:(NSUUID *)arg1 shouldCommit:(_Bool)arg2 withCompletionHandler:(void (^)(_Bool, NSError *))arg3;
- (void)executeQuery:(NSString *)arg1 withParameters:(NSArray *)arg2 options:(NSDictionary *)arg3 onTransaction:(NSUUID *)arg4 withCompletionHandler:(void (^)(NSData *, NSError *))arg5;
- (void)executeUpdate:(NSString *)arg1 withParameters:(NSArray *)arg2 onTransaction:(NSUUID *)arg3 withCompletionHandler:(void (^)(_Bool, NSError *))arg4;
- (void)beginTransactionForDatabaseAtPath:(NSString *)arg1 withPriorityLevel:(unsigned long long)arg2 options:(unsigned long long)arg3 completionHandler:(void (^)(NSUUID *, NSError *))arg4;
- (void)recreateDatabaseAtPath:(NSString *)arg1 withCompletionHandler:(void (^)(_Bool, NSError *))arg2;
- (void)performDiagnosticWithCompletionHandler:(void (^)(NSString *, NSError *))arg1;
- (void)attemptDatabaseFileRecoveryAtPath:(NSString *)arg1 withCompletionHandler:(void (^)(_Bool, NSError *))arg2;
- (void)validateDatabaseAtPath:(NSString *)arg1 withCompletionHandler:(void (^)(_Bool, NSError *))arg2;
@end

@protocol MLDMediaLibraryWriterDelegate <NSObject>

@optional
- (void)mediaLibraryWriter:(MLDMediaLibraryWriter *)arg1 didDestroyTransaction:(MLDActiveTransaction *)arg2;
- (void)mediaLibraryWriter:(MLDMediaLibraryWriter *)arg1 terminatedTransaction:(MLDActiveTransaction *)arg2 withError:(NSError *)arg3;
@end

@protocol NSXPCConnectionDelegate <NSObject>

@optional
- (void)connection:(NSXPCConnection *)arg1 handleInvocation:(NSInvocation *)arg2 isReply:(_Bool)arg3;
- (id <NSSecureCoding>)replacementObjectForXPCConnection:(NSXPCConnection *)arg1 encoder:(NSXPCCoder *)arg2 object:(id)arg3;
@end


/*
 * Protocols for /usr/libexec/pipelined
 */

@protocol CLIndoorProtocolPrivate <CLIndoorProtocol>
- (void)changeLocationGroups:(NSArray *)arg1;
- (void)selectLocationGroup:(NSString *)arg1;
- (void)selectLocationGroups:(NSArray *)arg1;
- (void)playbackDatarun:(NSString *)arg1;
- (void)setApiKey:(NSString *)arg1 onServer:(NSString *)arg2;
- (void)setApiKey:(NSString *)arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/PairedSync.framework/Support/pairedsyncd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol PSYSyncStateProviderInterface <NSObject>
- (oneway void)registerSyncStateObserverIfNeeded;
- (oneway void)requestDeviceSyncStateEntriesForPairingIDs:(NSArray *)arg1 completion:(void (^)(NSDictionary *))arg2;
@end

@protocol PSDSyncInitiatorDelegate <NSObject>
- (void)syncInitiatorStateChangedTo:(unsigned long long)arg1;
@end

@protocol PSYSyncSessionProviderInterface <NSObject>
- (oneway void)requestActiveSyncSessionWithCompletion:(void (^)(PSYSyncSession *, NSSet *, NSError *))arg1;
- (oneway void)checkin:(void (^)(_Bool))arg1;
@end

@protocol PSDSchedulerObserver <NSObject>

@optional
- (void)scheduler:(PSDScheduler *)arg1 didClearSyncSession:(PSYSyncSession *)arg2 withBlock:(void (^)(void))arg3;
- (void)scheduler:(PSDScheduler *)arg1 didUpdateSyncSessionWithUpdate:(PSYSyncSessionUpdate *)arg2;
- (void)scheduler:(PSDScheduler *)arg1 willStartSyncSession:(PSYSyncSession *)arg2;
@end


/*
 * Protocols for /private/var/staged_system_apps/MobileMail.app/MobileMail
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /usr/libexec/sharingd
 */

@protocol SDConnectionManagerDelegate <NSObject>
- (void)connectionManagerDidInvalidate:(SDConnectionManager *)arg1;
@end

@protocol SDUnlockXPCSesssionDelegate <NSObject>
- (void)unlockSessionDidFinish:(SDUnlockXPCSession *)arg1;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol SDCompanionStreamDelegate <NSObject>

@optional
- (void)companionStreamClosedStreams:(SDCompanionStream *)arg1;
- (void)continuationStream:(SDCompanionStream *)arg1 connectedToService:(SFCompanionService *)arg2 withFileHandle:(NSFileHandle *)arg3 acceptHandler:(void (^)(_Bool))arg4;
@end

@protocol SDXPCDaemonProtocol <NSObject>
- (void)establishConnectionWithCompletionHandler:(void (^)(void))arg1;
@end

@protocol SDCompanionPublisherProtocol <NSObject>

@optional
- (void)manager:(SDStreamManager *)arg1 connectedToService:(SFCompanionService *)arg2 withFileHandle:(NSFileHandle *)arg3 acceptHandler:(void (^)(_Bool))arg4;
- (void)publisher:(SDStreamManager *)arg1 companionStreamForService:(SFCompanionService *)arg2 streamHandler:(SDStreamHandler *)arg3;
- (void)publisher:(SDStreamManager *)arg1 didConnectToService:(SFCompanionService *)arg2 withStreamHandler:(SDStreamHandler *)arg3;
@end

@protocol NSXPCConnectionDelegate <NSObject>

@optional
- (void)connection:(NSXPCConnection *)arg1 handleInvocation:(NSInvocation *)arg2 isReply:(_Bool)arg3;
- (id <NSSecureCoding>)replacementObjectForXPCConnection:(NSXPCConnection *)arg1 encoder:(NSXPCCoder *)arg2 object:(id)arg3;
@end

@protocol SFCompanionXPCManagerProtocol <NSObject>
- (void)createHotspotSessionForClientProxy:(id <SFRemoteHotspotClient>)arg1 reply:(void (^)(id <SFRemoteHotspotProtocol>, NSError *))arg2;
- (void)appleAccountSignedOut;
- (void)appleAccountSignedIn;
- (void)createUnlockManagerWithReply:(void (^)(id <SFUnlockProtocol>, NSError *))arg1;
- (void)createContinuityScannerForClientProxy:(id <SFContinuityScannerClient>)arg1 reply:(void (^)(id <SFContinuityScannerProtocol>, NSError *))arg2;
- (void)createActivityAdvertiserForClientProxy:(id <SFActivityAdvertiserClient>)arg1 reply:(void (^)(id <SFActivityAdvertiserProtocol>, NSError *))arg2;
- (void)createStreamsForMessage:(NSDictionary *)arg1 reply:(void (^)(NSFileHandle *, NSError *))arg2;
- (void)createCompanionServiceManagerWithIdentifier:(NSString *)arg1 clientProxy:(id <SFCompanionServiceManagerClient>)arg2 reply:(void (^)(id <SFCompanionServiceManagerProtocol>, NSString *, NSString *, NSString *, NSError *))arg3;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/MapsSupport.framework/mapspushd
 */

@protocol MapsPushDelegate <NSObject>
- (void)pushManager:(MapsPushManager *)arg1 receivedFixedProblemNotification:(GEORPProblemStatusResponse *)arg2 manifestToken:(NSString *)arg3;
- (void)pushManager:(MapsPushManager *)arg1 gotPushData:(NSData *)arg2;
@end

@protocol MSPMapsPushDaemonProxy <MSPRemoteModelAccess>
- (void)fetchUserRoutingPreferencesWithCompletion:(void (^)(MSPUserRoutingPreferences *, NSError *))arg1;
- (void)mapsLocationAuthorizationStatusChanged;
- (void)handleMapsApplicationRemoval:(void (^)(NSError *))arg1;
- (void)eraseRAPData;
- (oneway void)updateMapsModelBackupAttributesIfNeeded;
- (void)clearParkedCarBulletin;
- (void)showParkedCarReplacementBulletinForEvent:(RTVehicleEvent *)arg1 replacingEvent:(RTVehicleEvent *)arg2 afterDelay:(double)arg3;
- (void)showParkedCarReplacementBulletinForEvent:(RTVehicleEvent *)arg1 replacingEvent:(RTVehicleEvent *)arg2;
- (void)showParkedCarBulletinForEvent:(RTVehicleEvent *)arg1 afterDelay:(double)arg2;
- (void)showParkedCarBulletinForEvent:(RTVehicleEvent *)arg1;
- (void)clearLowFuelAlertBulletin;
- (void)showLowFuelAlertBulletinForLowFuelDetails:(MSPLowFuelDetails *)arg1;
- (void)clearPredictedRouteTrafficIncidentBulletin;
- (void)showPredictedRouteTrafficIncidentBulletinForCommuteDetails:(MNCommuteNotificationDetails *)arg1 afterDelay:(double)arg2;
- (void)showPredictedRouteTrafficIncidentBulletinForCommuteDetails:(MNCommuteNotificationDetails *)arg1;
- (void)clearTransitAlightAlertBulletin;
- (void)showTransitAlightAlertWithTitle:(NSString *)arg1 message:(NSString *)arg2;
- (void)clearTrafficIncidentsBulletin;
- (void)clearTrafficIncidentBulletinWithAlertID:(NSData *)arg1;
- (void)showTrafficIncidentAlertWithID:(NSData *)arg1 type:(unsigned long long)arg2 title:(NSString *)arg3 description:(NSString *)arg4;
- (void)clearTrafficConditionsBulletin;
- (void)showTrafficConditionsBulletinWithTitle:(NSString *)arg1 message:(NSString *)arg2 actionURL:(NSURL *)arg3;
- (void)removeProblemStatusResponseWithNotificationID:(NSString *)arg1;
- (void)problemStatusResponseWithNotificationID:(NSString *)arg1 completion:(void (^)(GEORPProblemStatusResponse *))arg2;
- (void)clearBulletinWithRecordID:(NSString *)arg1;
- (void)fetchCurrentAnnouncement:(void (^)(GEOAnnouncement *))arg1;
- (void)resetShownAnnouncements;
- (void)clearCurrentAnnouncement;
- (void)simulateAnnouncement:(GEOAnnouncement *)arg1;
- (void)checkin;
- (void)fetchDevicePushToken:(void (^)(NSData *))arg1;
- (void)setShouldUseDevAPNS:(_Bool)arg1;
- (void)shouldUseDevAPNS:(void (^)(_Bool))arg1;
- (void)fetchProblemStatus;
- (void)simulateProblemResolution;
- (void)registerForTopic;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol MSPRemoteModelAccess <NSObject>
- (void)noteMapstoolChangedFavoritesOnDisk;
- (void)noteMapstoolChangedHistoryOnDisk;
- (void)testByNotingHistoryChangedOnDisk;
- (void)eraseHistorySerializedRepresentationWithCompletion:(void (^)(NSError *))arg1;
- (void)fetchLastKnownHistoryOperationIdentifier:(void (^)(NSUUID *))arg1;
- (void)commitHistorySerializedRepresentation:(NSData *)arg1 earliestKnownSyncDate:(NSDate *)arg2 operationIdentifier:(NSUUID *)arg3 completion:(void (^)(NSError *))arg4;
- (void)fetchHistorySerializedRepresentationWithCompletion:(void (^)(NSData *, NSError *))arg1;
- (void)eraseFavoritesSerializedRepresentationWithCompletion:(void (^)(NSError *))arg1;
- (void)fetchLastKnownFavoritesOperationIdentifier:(void (^)(NSUUID *))arg1;
- (void)commitFavoritesSerializedRepresentation:(NSData *)arg1 operationIdentifier:(NSUUID *)arg2 completion:(void (^)(NSError *))arg3;
- (void)fetchFavoritesSerializedRepresentationWithCompletion:(void (^)(NSData *, NSError *))arg1;
@end

@protocol AnnouncementsManagerDelegate <NSObject>
- (void)announcementsManager:(AnnouncementsManager *)arg1 didChangeActiveAnnouncement:(GEOAnnouncement *)arg2;
@end

@protocol MapsBBDataProviderDelegate <NSObject>
- (void)dataProvider:(MapsBBDataProvider *)arg1 didClearAnnouncementWithID:(unsigned int)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/ContinuousDialogManagerService.framework/assistant_cdmd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol CDMXPCListenerService <NSObject>
- (void)handleClientAceUpdate:(NSDictionary *)arg1;

@optional
- (void)handleClientAceRequest:(NSDictionary *)arg1 withReply:(void (^)(NSDictionary *))arg2;
@end

@protocol CDMSetupXPCListenerService <NSObject>
- (void)invalidateClientFlowCacheWithCompletion:(void (^)(NSError *))arg1;
- (void)getClientFlowStatusWithReply:(void (^)(NSArray *))arg1;
- (void)getNLAssetStatusForType:(NSString *)arg1 withReply:(void (^)(NSDictionary *, NSError *))arg2;
@end


/*
 * Protocols for /usr/libexec/locationd
 */

@protocol CLRoutineMonitorServiceProtocol <CLIntersiloServiceProtocol>
- (void)stopMonitoringScenarioTriggerOfType:(unsigned long long)arg1 forClient:(byref id <CLRoutineMonitorClientProtocol>)arg2;
- (void)startMonitoringScenarioTriggerOfType:(unsigned long long)arg1 forClient:(byref id <CLRoutineMonitorClientProtocol>)arg2;
- (void)fetchLocationOfInterestAtLocation:(CLLocation *)arg1 withHandler:(void (^)(RTLocationOfInterest *, NSError *))arg2;
- (void)stopLeechingLowConfidenceVisitsForClient:(byref id <CLRoutineMonitorClientProtocol>)arg1;
- (void)startLeechingLowConfidenceVisitsForClient:(byref id <CLRoutineMonitorClientProtocol>)arg1;
- (void)stopLeechingVisitsForClient:(byref id <CLRoutineMonitorClientProtocol>)arg1;
- (void)startLeechingVisitsForClient:(byref id <CLRoutineMonitorClientProtocol>)arg1;
- (void)stopMonitoringVisitsForClient:(byref id <CLRoutineMonitorClientProtocol>)arg1;
- (void)startMonitoringVisitsForClient:(byref id <CLRoutineMonitorClientProtocol>)arg1;
- (void)fetchPredictedLocationsOfInterestOnDate:(NSDate *)arg1 withReply:(void (^)(NSArray *, NSError *))arg2;
- (void)fetchNextPredictedLocationsOfInterestFromLocation:(CLLocation *)arg1 startDate:(NSDate *)arg2 timeInterval:(double)arg3 withReply:(void (^)(NSArray *, NSError *))arg4;
- (void)fetchRecentLocationsOfInterestWithReply:(void (^)(NSArray *, NSError *))arg1;
- (void)fetchLocationsOfInterestOfType:(long long)arg1 withReply:(void (^)(NSArray *, NSError *))arg2;
- (void)fetchLocationsOfInterestWithinDistance:(double)arg1 ofLocation:(CLLocation *)arg2 withReply:(void (^)(NSArray *, NSError *))arg3;
- (void)fetchLocationsOfInterestAssociatedToIdentifier:(NSString *)arg1 withReply:(void (^)(NSArray *, NSError *))arg2;
- (void)fetchRoutineModeFromLocation:(CLLocation *)arg1 withReply:(void (^)(long long, NSError *))arg2;
@end

@protocol CLLocationManagerRoutineServerInterface <NSObject>
- (void)stopUpdatingPredictedApplications;
- (void)startUpdatingPredictedApplications;
- (void)fetchPredictedApplicationsAtLocation:(CLLocation *)arg1 reply:(void (^)(NSArray *, NSError *))arg2;
- (void)stopUpdatingLocation;
- (void)startUpdatingLocation;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NSFileManagerDelegate <NSObject>

@optional
- (_Bool)fileManager:(NSFileManager *)arg1 shouldProceedAfterError:(NSError *)arg2 removingItemAtURL:(NSURL *)arg3;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldProceedAfterError:(NSError *)arg2 removingItemAtPath:(NSString *)arg3;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldRemoveItemAtURL:(NSURL *)arg2;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldRemoveItemAtPath:(NSString *)arg2;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldProceedAfterError:(NSError *)arg2 linkingItemAtURL:(NSURL *)arg3 toURL:(NSURL *)arg4;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldProceedAfterError:(NSError *)arg2 linkingItemAtPath:(NSString *)arg3 toPath:(NSString *)arg4;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldLinkItemAtURL:(NSURL *)arg2 toURL:(NSURL *)arg3;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldLinkItemAtPath:(NSString *)arg2 toPath:(NSString *)arg3;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldProceedAfterError:(NSError *)arg2 movingItemAtURL:(NSURL *)arg3 toURL:(NSURL *)arg4;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldProceedAfterError:(NSError *)arg2 movingItemAtPath:(NSString *)arg3 toPath:(NSString *)arg4;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldMoveItemAtURL:(NSURL *)arg2 toURL:(NSURL *)arg3;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldMoveItemAtPath:(NSString *)arg2 toPath:(NSString *)arg3;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldProceedAfterError:(NSError *)arg2 copyingItemAtURL:(NSURL *)arg3 toURL:(NSURL *)arg4;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldProceedAfterError:(NSError *)arg2 copyingItemAtPath:(NSString *)arg3 toPath:(NSString *)arg4;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldCopyItemAtURL:(NSURL *)arg2 toURL:(NSURL *)arg3;
- (_Bool)fileManager:(NSFileManager *)arg1 shouldCopyItemAtPath:(NSString *)arg2 toPath:(NSString *)arg3;
@end

@protocol CLLocationSmootherServerInterface <NSObject>

@optional
- (void)smoothLocations:(NSArray *)arg1 handler:(void (^)(NSArray *, NSError *))arg2;
- (void)smoothLocations:(NSArray *)arg1 useType:(NSNumber *)arg2;
@end

@protocol CLDiagnosticManagerServiceProtocol <CLIntersiloServiceProtocol>
- (void)unregisterFileForCollection:(NSURL *)arg1;
- (void)registerFileForCollection:(NSURL *)arg1;
@end

@protocol CLSuggestedActionClientProtocol <CLIntersiloClientProtocol>
- (void)onPredictedApplications:(NSArray *)arg1;
@end

@protocol CLIntersiloClientProtocol <CLIntersiloProxyDelegateProtocol>
@end

@protocol CLSmootherMonitorServiceProtocol <CLIntersiloServiceProtocol>
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/StoreBookkeeperClient.framework/Support/storebookkeeperd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol SBCPlaybackPositionServiceProtocol_Internal <SBCPlaybackPositionServiceProtocol, SBCDomainSyncServiceProtocol_Internal>
- (oneway void)setClientConfiguration:(SBCClientConfiguration *)arg1;
@end

@protocol SBDPushNotificationControllerDelegate <NSObject>

@optional
- (void)pushNotificationController:(SBDPushNotificationController *)arg1 didReceiveUpdateRequestForBookkeeperDomain:(NSString *)arg2 toDomainRevision:(NSString *)arg3;
@end

@protocol SBCPlaybackPositionServiceProtocol <SBCDomainSyncServiceProtocol, SBCDomainValueServiceProtocol>
@end


/*
 * Protocols for /usr/libexec/keybagd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol BDBubbled <NSObject>
- (void)bubbleShouldPop;
@end

@protocol RDClient <NSObject>
- (void)bubbleDidPop;
- (void)uploadContentWithCompletionHandler:(void (^)(void))arg1;
- (void)userSwitchTaskListDidUpdate;
- (void)readyToSwitchToUser:(NSDictionary *)arg1 completionHandler:(void (^)(void))arg2;
- (void)willSwitchToUser:(NSDictionary *)arg1 completionHandler:(void (^)(void))arg2;
@end


/*
 * Protocols for /usr/libexec/eventkitsyncd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /Applications/AdSheet.app/AdSheet
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol ADClientStateDelegate <NSObject>
- (void)clientStateDidChange:(ADClientState *)arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/SetupAssistant.framework/budd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol BYClientDaemonCloudSyncProtocol <NSObject>
- (void)syncCompletedWithErrors:(NSArray *)arg1;
- (void)syncProgress:(double)arg1;
@end

@protocol BYDaemonCloudSyncProtocol <NSObject>
- (void)startSync;
- (void)needsToSync:(void (^)(unsigned long long))arg1;
@end


/*
 * Protocols for /usr/libexec/resourcegrabberd
 */

@protocol IDSServiceDelegate <NSObject>

@optional
- (void)service:(IDSService *)arg1 didSwitchActivePairedDevice:(IDSDevice *)arg2 acknowledgementBlock:(void (^)(void))arg3;
- (void)serviceAllowedTrafficClassifiersDidReset:(IDSService *)arg1;
- (void)serviceSpaceDidBecomeAvailable:(IDSService *)arg1;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4 withContext:(NSData *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4 withOptions:(NSDictionary *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 hasBeenDeliveredWithContext:(id)arg4;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 didSendWithSuccess:(_Bool)arg4 error:(NSError *)arg5 context:(IDSMessageContext *)arg6;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 didSendWithSuccess:(_Bool)arg4 error:(NSError *)arg5;
- (void)service:(IDSService *)arg1 connectedDevicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 nearbyDevicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 devicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 activeAccountsChanged:(NSSet *)arg2;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingResourceAtURL:(NSURL *)arg3 metadata:(NSDictionary *)arg4 fromID:(NSString *)arg5 context:(IDSMessageContext *)arg6;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingResourceAtURL:(NSURL *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingUnhandledProtobuf:(IDSProtobuf *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingData:(NSData *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingMessage:(NSDictionary *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NanoResourceGrabberIDSXPC <NSObject>
- (void)xpcGetIconForBundleID:(NSString *)arg1 iconVariant:(int)arg2 withTimeout:(double)arg3 reply:(void (^)(NSData *))arg4;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/WatchListKit.framework/Support/watchlistd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol WLDClientConnectionDelegate <NSObject>

@optional
- (void)clientConnectionDidInvalidate:(WLDClientConnection *)arg1;
@end

@protocol WLKConnectionServerProtocol <NSObject>
- (void)ping;
- (void)fetchSettings:(void (^)(NSDictionary *))arg1;
- (void)postSettings:(NSDictionary *)arg1 replyHandler:(void (^)(_Bool))arg2;
- (void)writeSettingsStore:(NSDictionary *)arg1 replyHandler:(void (^)(_Bool))arg2;
- (void)readSettingsStore:(void (^)(NSDictionary *))arg1;
- (void)setNextConfigurationEK:(NSString *)arg1;
- (void)invalidateConfiguration:(void (^)(void))arg1;
- (void)fetchConfigurationCache:(void (^)(WLKServerConfigurationResponse *))arg1;
- (void)fetchConfiguration:(void (^)(WLKServerConfigurationResponse *))arg1;
- (void)fetchApplications:(void (^)(NSDictionary *))arg1;
- (void)deletePlaybackActivityWithIdentifier:(NSString *)arg1 bundleID:(NSString *)arg2;
- (void)requestConsentForBundleID:(NSString *)arg1 forceAuth:(_Bool)arg2 replyHandler:(void (^)(_Bool))arg3;
- (void)requestPlaybackSummaryForID:(NSNumber *)arg1 completion:(void (^)(WLKPlaybackSummary *))arg2;
- (void)requestPlaybackSummary:(void (^)(WLKPlaybackSummary *))arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/AssistantServices.framework/assistantd
 */

@protocol AFAnalyticsObservationService <NSObject>
- (oneway void)flushWithCompletion:(void (^)(void))arg1;
- (oneway void)observeWithCompletion:(void (^)(void))arg1;
@end

@protocol AFSettingsService <NSObject>
- (oneway void)getDevicesWithAvailablePHSAssetsForLanguage:(NSString *)arg1 completion:(void (^)(NSArray *))arg2;
- (oneway void)disableAndDeleteCloudSyncWithCompletion:(void (^)(NSError *))arg1;
- (oneway void)fetchExperimentContextWithCompletion:(void (^)(AFExperimentContext *, NSError *))arg1;
- (oneway void)fetchExperimentConfigurationsWithCompletion:(void (^)(NSArray *, NSError *))arg1;
- (oneway void)sendMetricsToServerWithCompletion:(void (^)(NSError *))arg1;
- (oneway void)resetAnalyticsStoreWithCompletion:(void (^)(NSError *))arg1;
- (oneway void)purgeAnalyticsStoreWithCompletion:(void (^)(NSError *))arg1;
- (oneway void)fetchEventRecordsFromAnalyticsStoreAtPath:(NSString *)arg1 completion:(void (^)(NSArray *, NSError *))arg2;
- (oneway void)setDESPolicyCDNOverride:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (oneway void)disableDESWithCompletion:(void (^)(NSError *))arg1;
- (oneway void)setDESLotteryWinOverrideEnabled:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (oneway void)setDESRecordingAlwaysIsEnabled:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (oneway void)runLiveAdaptationRecipeEvaluationWithBaseURL:(NSURL *)arg1 completion:(void (^)(NSError *))arg2;
- (oneway void)runAdaptationRecipeEvaluation:(NSDictionary *)arg1 language:(NSString *)arg2 completion:(void (^)(NSArray *, NSArray *))arg3;
- (oneway void)stopAllAudioPlaybackRequests:(_Bool)arg1;
- (oneway void)stopAudioPlaybackRequest:(AFAudioPlaybackRequest *)arg1 immediately:(_Bool)arg2;
- (oneway void)startAudioPlaybackRequest:(AFAudioPlaybackRequest *)arg1 completion:(void (^)(NSError *))arg2;
- (oneway void)getPeerIdentifiers:(void (^)(NSArray *))arg1;
- (oneway void)startRemoteRequest:(AFRequestInfo *)arg1 onPeer:(NSString *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)startUIRequestWithSpeechAudioFileURL:(NSURL *)arg1;
- (oneway void)startUIRequestWithText:(NSString *)arg1;
- (oneway void)setOfflineDictationProfileOverridePath:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (oneway void)createOfflineSpeechProfileWithLanguage:(NSString *)arg1 JSONData:(NSData *)arg2 completion:(void (^)(NSData *, NSError *))arg3;
- (oneway void)updateOfflineSpeechProfileWithLanguage:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (oneway void)getOfflineDictationStatusWithCompletion:(void (^)(NSDictionary *, NSError *))arg1;
- (oneway void)setLanguage:(NSString *)arg1 withCompletion:(void (^)(void))arg2;
- (oneway void)setOutputVoice:(AFVoiceInfo *)arg1 withCompletion:(void (^)(void))arg2;
- (oneway void)getAvailableVoicesIncludingAssetInfo:(_Bool)arg1 completion:(void (^)(NSArray *))arg2;
- (oneway void)_runServiceMaintenance;
- (oneway void)_startDeepSyncVerificationForKeys:(NSArray *)arg1;
- (void)_setSyncVerificationNeededAndFullReportNeeded:(_Bool)arg1 shouldPostNotification:(_Bool)arg2 completion:(void (^)(NSArray *))arg3;
- (oneway void)_fetchPeerData:(void (^)(void))arg1;
- (oneway void)_syncDataWithAnchorKeys:(NSArray *)arg1 forceReset:(_Bool)arg2 reason:(NSString *)arg3 reply:(void (^)(NSArray *))arg4;
- (oneway void)_clearSyncNeededForKey:(NSString *)arg1;
- (oneway void)_setSyncNeededForReason:(NSString *)arg1;
- (oneway void)barrierWithReply:(void (^)(void))arg1;
- (oneway void)_killDaemon;
- (oneway void)setDictationEnabled:(_Bool)arg1;
- (oneway void)setAssistantEnabled:(_Bool)arg1;
- (oneway void)setActiveAccountIdentifier:(NSString *)arg1;
- (oneway void)deleteAccountWithIdentifier:(NSString *)arg1;
- (oneway void)saveAccountWithMessageDictionary:(NSDictionary *)arg1 setActive:(_Bool)arg2;
- (oneway void)retrieveAccountMessageDictionariesWithReply:(void (^)(NSArray *))arg1;
- (oneway void)fetchSupportedLanguagesWithReply:(void (^)(NSArray *, NSError *))arg1;
@end

@protocol ADCommandCenterRequestDelegate <NSObject>
- (void)adRequestEncounteredIntermediateError:(NSError *)arg1;
- (void)adRequestDidCompleteWithSuccess:(_Bool)arg1 error:(NSError *)arg2;
- (void)adRequestDidReceiveCommand:(AceObject<SAAceCommand> *)arg1 reply:(void (^)(AceObject<SAAceCommand> *))arg2;
- (void)adRequestWillReceiveCommand:(AceObject<SAAceCommand> *)arg1;
@end

@protocol ADCommandCenterSyncDelegate <NSObject>
- (void)adSyncVerificationServerReport:(NSDictionary *)arg1;
- (void)adSyncVerificationPartialResult:(NSDictionary *)arg1;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol CSSpeechControllerDelegate <NSObject>
- (void)speechControllerLPCMRecordBufferAvailable:(CSSpeechController *)arg1 buffer:(NSData *)arg2;
- (void)speechControllerRecordBufferAvailable:(CSSpeechController *)arg1 buffers:(NSArray *)arg2 recordedAt:(unsigned long long)arg3;

@optional
- (void)speechControllerRequestsOperation:(unsigned long long)arg1 forReason:(unsigned long long)arg2;
- (void)speechControllerEndRecordInterruption:(CSSpeechController *)arg1;
- (void)speechControllerBeginRecordInterruption:(CSSpeechController *)arg1 withContext:(NSDictionary *)arg2;
- (void)speechControllerBeginRecordInterruption:(CSSpeechController *)arg1;
- (void)speechControllerRecordHardwareConfigurationDidChange:(CSSpeechController *)arg1 toConfiguration:(long long)arg2;
- (void)speechControllerDidDetectEndpoint:(CSSpeechController *)arg1 ofType:(long long)arg2 atTime:(double)arg3;
- (void)speechControllerDidDetectStartpoint:(CSSpeechController *)arg1;
- (void)speechControllerDidStopRecording:(CSSpeechController *)arg1 forReason:(long long)arg2;
- (void)speechControllerDidStartRecording:(CSSpeechController *)arg1 successfully:(_Bool)arg2 error:(NSError *)arg3;
- (void)speechControllerDidDetectVoiceTriggerTwoShot:(CSSpeechController *)arg1 atTime:(double)arg2;
@end

@protocol CSEndpointAnalyzerDelegate <NSObject>
- (void)endpointer:(id <CSEndpointAnalyzer>)arg1 didDetectHardEndpointAtTime:(double)arg2 withMetrics:(CSEndpointerMetrics *)arg3;
- (void)endpointer:(id <CSEndpointAnalyzer>)arg1 didDetectStartpointAtTime:(double)arg2;
@end

@protocol ADCommandCenterClient <ADCommandCenterRequestDelegate, ADCommandCenterSpeechDelegate>
- (void)adAudioPlaybackRequestDidStop:(AFAudioPlaybackRequest *)arg1 error:(NSError *)arg2;
- (void)adAudioPlaybackRequestDidNotStart:(AFAudioPlaybackRequest *)arg1 error:(NSError *)arg2;
- (void)adAudioPlaybackRequestDidStart:(AFAudioPlaybackRequest *)arg1;
- (void)adAudioPlaybackRequestWillStart:(AFAudioPlaybackRequest *)arg1;
- (void)adStartUIRequestWithText:(NSString *)arg1 completion:(void (^)(_Bool))arg2;
- (void)adHandleIntent:(INIntent *)arg1 inBackgroundAppWithBundleId:(NSString *)arg2 reply:(void (^)(INIntentResponse *, NSError *))arg3;
- (void)adExtensionRequestFinishedForApplication:(NSString *)arg1 error:(NSError *)arg2;
- (void)adExtensionRequestWillStartForApplication:(NSString *)arg1;
- (void)adWantsToCacheImage:(INImage *)arg1;
- (void)adQuickStopWasHandledWithActions:(unsigned long long)arg1;
- (void)adRequestRequestedDismissAssistant;
- (void)adServerRequestsTTSStateUnmuted:(_Bool)arg1;
- (void)adInvalidateCurrentUserActivity;
- (void)adSetUserActivityInfo:(NSDictionary *)arg1 webpageURL:(NSURL *)arg2;
- (void)adAcousticIDRequestDidFinishSuccessfully:(_Bool)arg1;
- (void)adMusicWasDetected;
- (void)adAcousticIDRequestWillStart;
- (_Bool)adTextToSpeechIsMuted;
- (void)adGetBulletinContext:(void (^)(NSArray *))arg1;
- (void)adRequestRequestedOpenURL:(NSURL *)arg1 completion:(void (^)(_Bool))arg2;
- (void)adRequestRequestedOpenApplicationWithBundleID:(NSString *)arg1 URL:(NSURL *)arg2 completion:(void (^)(_Bool))arg3;
@end

@protocol SiriCoreLocalSpeechRecognizerDelegate <NSObject>
- (void)localSpeechRecognizer:(SiriCoreLocalSpeechRecognizer *)arg1 didCompletionRecognitionWithStatistics:(NSDictionary *)arg2 error:(NSError *)arg3;
- (void)localSpeechRecognizer:(SiriCoreLocalSpeechRecognizer *)arg1 didRecognizePackage:(AFSpeechPackage *)arg2;
- (void)localSpeechRecognizer:(SiriCoreLocalSpeechRecognizer *)arg1 didRecognizeRawEagerRecognitionCandidate:(AFSpeechRecognition *)arg2;
- (void)localSpeechRecognizer:(SiriCoreLocalSpeechRecognizer *)arg1 didProcessAudioDuration:(double)arg2;
- (void)localSpeechRecognizer:(SiriCoreLocalSpeechRecognizer *)arg1 didRecognizeTokens:(NSArray *)arg2;
@end

@protocol ADSpeechCapturing <NSObject>
- (void)enforcePreviousEndpointHint;
- (void)updateEndpointHintForDuration:(double)arg1 completion:(void (^)(_Bool, NSArray *))arg2;
- (void)updateServerEndpointFeatures:(CSServerEndpointFeatures *)arg1;
- (void)playRecordingStartAlert;
- (void)getLastStartpointTimestampAndCurrentTime:(void (^)(double, double))arg1;
- (void)setIsDriving:(_Bool)arg1;
- (void)forceSuccessAudioAlertOnStop;
- (void)setFingerprintingEnabled:(_Bool)arg1;
- (void)cancelSpeechCaptureSuppressingAlert:(_Bool)arg1;
- (void)stopSpeechCaptureForEvent:(long long)arg1 suppressAlert:(_Bool)arg2;
- (void)setFingerprintWasRecognized;
- (void)setSpeechWasRecognizedForElapsedTime:(double)arg1 isFinal:(_Bool)arg2;
- (void)setSpeechRequestOptions:(AFSpeechRequestOptions *)arg1;
- (void)suspendAutomaticEndpointingInRange:(struct AFTimeRange)arg1;
- (void)setUseAutomaticEndpointing:(_Bool)arg1;
- (void)releaseAudioSession;
- (void)setDelegate:(id <ADSpeechCapturingDelegate>)arg1;
- (id)initWithQueue:(NSObject<OS_dispatch_queue> *)arg1;
- (id)init;
@end

@protocol AFAnalyticsService <NSObject>
- (oneway void)stageEvents:(NSArray *)arg1 completion:(void (^)(void))arg2;

@optional
- (oneway void)stageEvents:(NSArray *)arg1;
- (oneway void)stageEvent:(AFAnalyticsEvent *)arg1;
@end

@protocol ADCommandCenterSpeechDelegate <NSObject>
- (_Bool)adWaitingForAudioFile;
- (void)adSpeechRecordingDidRecognizePhrases:(NSArray *)arg1 sessionUUID:(NSString *)arg2 refId:(NSString *)arg3;
- (void)adSpeechRecordingDidRecognizeTokens:(NSArray *)arg1 sessionUUID:(NSString *)arg2;
- (void)adSpeechRecognizedPartialResult:(SASSpeechPartialResult *)arg1 usingSpeechModel:(NSString *)arg2;
- (void)adSpeechRecognitionDidFail:(NSError *)arg1 sessionUUID:(NSString *)arg2;
- (void)adSpeechRecognized:(SASSpeechRecognized *)arg1 usingSpeechModel:(NSString *)arg2 sessionUUID:(NSString *)arg3;
- (void)adSpeechRecordingDidFail:(NSError *)arg1 sessionUUID:(NSString *)arg2;
- (void)adSpeechRecordingDidCancelWithSessionUUID:(NSString *)arg1;
- (void)adSpeechRecordingDidEndWithSessionUUID:(NSString *)arg1;
- (void)adSpeechRecordingDidChangeAVRecordRoute:(NSString *)arg1 sessionUUID:(NSString *)arg2;
- (void)adSpeechRecordingDidBeginOnAVRecordRoute:(NSString *)arg1 audioSessionID:(unsigned int)arg2 sessionUUID:(NSString *)arg3;
- (void)adSpeechRecordingWillBeginWithInputAudioPowerXPCWrapper:(AFXPCWrapper *)arg1 sessionUUID:(NSString *)arg2;

@optional
- (void)adSpeechRecordingDidRecognizePhrases:(NSArray *)arg1 utterances:(NSArray *)arg2;
- (void)adSpeechRecognitionWillBeginRecognitionUpdateForTask:(NSString *)arg1;
- (void)adSpeechRecognitionDidFinishUpdateWithError:(NSError *)arg1;
- (void)adSpeechRecordingPerformTwoShotPromptWithType:(long long)arg1 sessionUUID:(NSString *)arg2 completion:(void (^)(double, double, NSError *))arg3;
- (void)adSpeechRecordingDidDetectStartPointWithSessionUUID:(NSString *)arg1;
- (void)adSpeechDidFindVoiceSearchFinalResult:(SASVoiceSearchFinalResult *)arg1;
- (void)adSpeechDidFindVoiceSearchPartialResult:(SASVoiceSearchPartialResult *)arg1;
- (void)adPronunciationRecognized:(SASPronunciationRecognized *)arg1 usingSpeechModel:(NSString *)arg2 sessionUUID:(NSString *)arg3;
- (void)adAudioFileFinishedWriting:(NSFileHandle *)arg1 error:(NSError *)arg2 sessionUUID:(NSString *)arg3;
- (void)adSpeechRecognizedStructuredResult:(SAStructuredDictationResult *)arg1 usingSpeechModel:(NSString *)arg2 sessionUUID:(NSString *)arg3;
@end

@protocol ADAcousticFingerprinterDelegate <NSObject>
- (void)acousticFingerprinter:(ADAcousticFingerprinter *)arg1 hasFingerprint:(NSData *)arg2 duration:(double)arg3;
@end

@protocol PSYSyncCoordinatorDelegate <NSObject>

@optional
- (void)syncCoordinatorDidReceiveStartSyncCommand:(PSYSyncCoordinator *)arg1;
- (void)supportsMigrationSync;
- (void)syncCoordinatorDidChangeSyncRestriction:(PSYSyncCoordinator *)arg1;
- (void)syncCoordinator:(PSYSyncCoordinator *)arg1 didInvalidateSyncSession:(PSYServiceSyncSession *)arg2;
- (void)syncCoordinator:(PSYSyncCoordinator *)arg1 beginSyncSession:(PSYServiceSyncSession *)arg2;
@end

@protocol ADAudioStateListening <NSObject>
- (void)audioStateAnnouncer:(id <ADAudioStateAnnouncing>)arg1 didChangeAudioStateFrom:(AFAudioState *)arg2 to:(AFAudioState *)arg3;
@end

@protocol AFClientService <NSObject>
- (oneway void)_sendFeedbackToAppPreferencesPredictorForMetricsContext:(NSString *)arg1 selectedBundleId:(NSString *)arg2;
- (oneway void)_refreshAssistantValidation;
- (oneway void)_startSpeechWithURL:(NSURL *)arg1 isNarrowBand:(_Bool)arg2;
- (oneway void)_requestBarrierWithReply:(void (^)(void))arg1;
- (oneway void)_barrierWithReply:(void (^)(void))arg1;
- (oneway void)_clearAssistantInfoForAccountIdentifier:(NSString *)arg1;
- (oneway void)_fetchAppContextForApplicationInfo:(AFApplicationInfo *)arg1 reply:(void (^)(NSArray *))arg2;
- (oneway void)_broadcastCommandDictionary:(NSDictionary *)arg1;
- (oneway void)_performTaskCommandDictionary:(NSDictionary *)arg1 forBundleIdentifier:(NSString *)arg2 reply:(void (^)(NSDictionary *, NSError *))arg3;
- (oneway void)_performCommandDictionary:(NSDictionary *)arg1 forBundleIdentifier:(NSString *)arg2 reply:(void (^)(NSDictionary *, NSError *))arg3;
- (oneway void)_sendLargeData:(NSData *)arg1 reply:(void (^)(NSString *, NSData *))arg2;
- (oneway void)_pingServiceForIdentifier:(NSString *)arg1 reply:(void (^)(NSDictionary *))arg2;
- (oneway void)_listInstalledServicesWithReply:(void (^)(NSDictionary *))arg1;
- (oneway void)adviseSessionArbiterToContinueWithPreviousWinner:(_Bool)arg1;
- (oneway void)reportIssueForError:(NSError *)arg1 type:(long long)arg2 context:(NSDictionary *)arg3;
- (oneway void)updateSpeechSynthesisRecord:(AFSpeechSynthesisRecord *)arg1;
- (oneway void)endUpdateOutputAudioPower;
- (oneway void)beginUpdateOutputAudioPowerWithReply:(void (^)(AFXPCWrapper *))arg1;
- (oneway void)stopAllAudioPlaybackRequests:(_Bool)arg1;
- (oneway void)stopAudioPlaybackRequest:(AFAudioPlaybackRequest *)arg1 immediately:(_Bool)arg2;
- (oneway void)startAudioPlaybackRequest:(AFAudioPlaybackRequest *)arg1 reply:(void (^)(NSError *))arg2;
- (oneway void)getSerializedCachedObjectsWithIdentifiers:(NSSet *)arg1 completion:(void (^)(NSDictionary *))arg2;
- (oneway void)getDeferredObjectsWithIdentifiers:(NSArray *)arg1 completion:(void (^)(NSArray *, NSError *))arg2;
- (oneway void)recordCancellationMetrics;
- (oneway void)recordFailureMetricsForError:(NSError *)arg1;
- (oneway void)recordSuccessMetrics;
- (oneway void)recordUIMetrics:(AFMetrics *)arg1;
- (oneway void)recordRequestMetric:(NSString *)arg1 withTimestamp:(double)arg2;
- (oneway void)telephonyRequestCompleted;
- (oneway void)prepareForPhoneCall;
- (oneway void)setAlertContextDirty;
- (oneway void)setOverriddenApplicationContext:(NSString *)arg1 withContext:(id)arg2;
- (oneway void)setApplicationContextForApplicationInfos:(NSArray *)arg1 withRefId:(NSString *)arg2;
- (oneway void)setApplicationContext:(SASetApplicationContext *)arg1;
- (oneway void)willSetApplicationContextWithRefId:(NSString *)arg1;
- (oneway void)rollbackClearContext;
- (oneway void)clearContext;
- (oneway void)performGenericAceCommand:(NSDictionary *)arg1 interruptOutstandingRequest:(_Bool)arg2 reply:(void (^)(_Bool))arg3;
- (oneway void)requestStateUpdateWithReply:(void (^)(_Bool, unsigned int))arg1;
- (oneway void)stopSpeechWithOptions:(AFSpeechRequestOptions *)arg1;
- (oneway void)rollbackRequest;
- (oneway void)cancelRequest;
- (oneway void)updateSpeechOptions:(AFSpeechRequestOptions *)arg1;
- (oneway void)continuePendingSpeechRequestWithId:(unsigned long long)arg1 fromTimestamp:(double)arg2;
- (oneway void)startAcousticIDRequestWithOptions:(AFSpeechRequestOptions *)arg1 context:(NSString *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)startSpeechPronunciationRequestWithOptions:(AFSpeechRequestOptions *)arg1 context:(SASPronunciationContext *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)startRecordingForPendingSpeechRequestWithOptions:(AFSpeechRequestOptions *)arg1 requestId:(unsigned long long)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)startRequestWithInfo:(AFRequestInfo *)arg1 completion:(void (^)(NSError *))arg2;
- (oneway void)endSession;
- (oneway void)didDismissUI;
- (oneway void)willPresentUIWithReply:(void (^)(void))arg1;
- (oneway void)setConfiguration:(AFClientConfiguration *)arg1;
- (oneway void)setCarDNDActive:(_Bool)arg1;
- (oneway void)setIsStark:(_Bool)arg1;
- (oneway void)setLockState:(_Bool)arg1 showingLockScreen:(_Bool)arg2;
- (oneway void)forceAudioSessionInactive;
- (oneway void)forceAudioSessionActiveWithCompletion:(void (^)(unsigned int, NSError *))arg1;
- (oneway void)forceAudioSessionActive;
- (oneway void)boostedPreheatWithStyle:(long long)arg1 completion:(void (^)(void))arg2;
- (oneway void)preheatWithStyle:(long long)arg1 forOptions:(AFSpeechRequestOptions *)arg2;
@end

@protocol AFDictationService <NSObject>
- (oneway void)requestOfflineDictationSupportForLanguage:(NSString *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (oneway void)getInstalledOfflineLanguagesWithCompletion:(void (^)(NSArray *))arg1;
- (oneway void)_sendEngagementFeedback:(long long)arg1 voiceQueryIdentifier:(NSString *)arg2;
- (oneway void)_startDictationWithURL:(NSURL *)arg1 isNarrowBand:(_Bool)arg2 language:(NSString *)arg3 options:(AFDictationOptions *)arg4;
- (oneway void)recordFailureMetricsForError:(NSError *)arg1;
- (oneway void)endSession;
- (oneway void)preheatWithRecordDeviceIdentifier:(NSString *)arg1;
- (oneway void)preheat;
- (oneway void)sendSpeechCorrectionInfo:(AFSpeechCorrectionInfo *)arg1 forCorrectionContext:(NSDictionary *)arg2;
- (oneway void)updateSpeechOptions:(AFSpeechRequestOptions *)arg1;
- (oneway void)addRecordedSpeechSampleData:(NSData *)arg1;
- (oneway void)startRecordedAudioDictationWithOptions:(AFDictationOptions *)arg1 language:(NSString *)arg2 narrowband:(_Bool)arg3;
- (oneway void)stopSpeechWithOptions:(AFSpeechRequestOptions *)arg1;
- (oneway void)cancelSpeech;
- (oneway void)startDictationWithLanguageCode:(NSString *)arg1 options:(AFDictationOptions *)arg2 speechOptions:(AFSpeechRequestOptions *)arg3;
- (oneway void)startRecordingForPendingDictationWithLanguageCode:(NSString *)arg1 options:(AFDictationOptions *)arg2 speechOptions:(AFSpeechRequestOptions *)arg3 reply:(void (^)(NSXPCListenerEndpoint *))arg4;
- (oneway void)startRequestActivityWithCompletion:(void (^)(void))arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/WelcomeKit.framework/matd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/MapsSupport.framework/navd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol GEONavdXPCInterface <NSObject>
- (void)forceCacheRefresh;
- (void)didPostUINotification:(unsigned long long)arg1 forDestination:(GEOPlannedDestination *)arg2 fromClient:(GEONavdClientInfo *)arg3;
- (void)stopMonitoringDestination:(GEOPlannedDestination *)arg1 forClient:(GEONavdClientInfo *)arg2 uuid:(NSUUID *)arg3;
- (void)onlyPerformLocalUpdatesForPlannedDestination:(GEOPlannedDestination *)arg1 client:(GEONavdClientInfo *)arg2;
- (void)requestRefreshForPlannedDestination:(GEOPlannedDestination *)arg1 client:(GEONavdClientInfo *)arg2;
- (void)startMonitoringDestination:(GEOPlannedDestination *)arg1 forClient:(GEONavdClientInfo *)arg2 uuid:(NSUUID *)arg3;
- (void)statusWithCallback:(void (^)(NSDictionary *))arg1;
@end


/*
 * Protocols for /usr/libexec/tipsd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NSURLSessionDelegate <NSObject>

@optional
- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession *)arg1;
- (void)URLSession:(NSURLSession *)arg1 didReceiveChallenge:(NSURLAuthenticationChallenge *)arg2 completionHandler:(void (^)(long long, NSURLCredential *))arg3;
- (void)URLSession:(NSURLSession *)arg1 didBecomeInvalidWithError:(NSError *)arg2;
@end

@protocol TPSDWelcomeDelegate <NSObject>
- (void)majorVersionChanged:(TPSDWelcome *)arg1;
- (void)welcomeNotificationReminderEnded:(TPSDWelcome *)arg1;
- (void)welcomeNotificationShown:(TPSDWelcome *)arg1;
- (_Bool)welcomeCanContinueWelcomeFlow:(TPSDWelcome *)arg1;
@end

@protocol TPSXPCServerInterface <NSObject>
- (oneway void)activateCollectionIdentifier:(NSString *)arg1 context:(NSDictionary *)arg2;
- (oneway void)tipsAppLaunchedWithTipIDs:(NSArray *)arg1;
- (oneway void)tipNotificationInteractedByUser;
- (oneway void)clearBulletin;
@end

@protocol NSURLSessionDataDelegate <NSURLSessionTaskDelegate>

@optional
- (void)URLSession:(NSURLSession *)arg1 dataTask:(NSURLSessionDataTask *)arg2 willCacheResponse:(NSCachedURLResponse *)arg3 completionHandler:(void (^)(NSCachedURLResponse *))arg4;
- (void)URLSession:(NSURLSession *)arg1 dataTask:(NSURLSessionDataTask *)arg2 didReceiveData:(NSData *)arg3;
- (void)URLSession:(NSURLSession *)arg1 dataTask:(NSURLSessionDataTask *)arg2 didBecomeStreamTask:(NSURLSessionStreamTask *)arg3;
- (void)URLSession:(NSURLSession *)arg1 dataTask:(NSURLSessionDataTask *)arg2 didBecomeDownloadTask:(NSURLSessionDownloadTask *)arg3;
- (void)URLSession:(NSURLSession *)arg1 dataTask:(NSURLSessionDataTask *)arg2 didReceiveResponse:(NSURLResponse *)arg3 completionHandler:(void (^)(long long))arg4;
@end


/*
 * Protocols for /System/Library/CoreServices/SafariSupport.bundle/SafariBookmarksSyncAgent
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol WBSSafariBookmarksSyncAgentProtocol <WBSCyclerCloudBookmarksAssistant>
- (void)fetchSyncedCloudTabDevicesAndCloseRequestsWithCompletionHandler:(void (^)(NSArray *, NSArray *))arg1;
- (void)deleteCloudTabCloseRequestsWithUUIDStrings:(NSArray *)arg1 completionHandler:(void (^)(NSError *))arg2;
- (void)deleteDevicesWithUUIDStrings:(NSArray *)arg1 completionHandler:(void (^)(NSError *))arg2;
- (void)saveCloudTabCloseRequestWithDictionaryRepresentation:(NSDictionary *)arg1 closeRequestUUIDString:(NSString *)arg2 completionHandler:(void (^)(NSError *))arg3;
- (void)saveTabsForCurrentDeviceWithDictionaryRepresentation:(NSDictionary *)arg1 deviceUUIDString:(NSString *)arg2;
- (void)collectDiagnosticsDataWithCompletionHandler:(void (^)(NSData *))arg1;
- (void)beginMigrationFromDAV;
- (void)observeRemoteMigrationStateForSecondaryMigration;
- (void)fetchRemoteMigrationStateWithCompletionHandler:(void (^)(long long, NSString *, NSError *))arg1;
- (void)fetchUserIdentityWithCompletionHandler:(void (^)(NSString *, NSError *))arg1;
- (void)userAccountDidChange:(long long)arg1;
- (void)userDidUpdateBookmarkDatabase;
- (void)setUsesOpportunisticPushTopic:(_Bool)arg1;
- (void)registerForPushNotificationsIfNeeded;
@end

@protocol APSConnectionDelegate <NSObject>
- (void)connection:(APSConnection *)arg1 didReceivePublicToken:(NSData *)arg2;

@optional
- (void)connectionDidReconnect:(APSConnection *)arg1;
- (void)connection:(APSConnection *)arg1 didChangeConnectedStatus:(_Bool)arg2;
- (void)connection:(APSConnection *)arg1 didFailToSendOutgoingMessage:(APSOutgoingMessage *)arg2 error:(NSError *)arg3;
- (void)connection:(APSConnection *)arg1 didSendOutgoingMessage:(APSOutgoingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveMessageForTopic:(NSString *)arg2 userInfo:(NSDictionary *)arg3;
- (void)connection:(APSConnection *)arg1 didReceiveIncomingMessage:(APSIncomingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveToken:(NSData *)arg2 forTopic:(NSString *)arg3 identifier:(NSString *)arg4;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/CloudPhotoLibrary.framework/Support/cloudphotod
 */

@protocol CPLResourceProgressDelegate <NSObject>
- (void)libraryManager:(CPLLibraryManager *)arg1 uploadDidFinishForResourceTransferTask:(CPLResourceTransferTask *)arg2 withError:(NSError *)arg3;
- (void)libraryManager:(CPLLibraryManager *)arg1 uploadDidStartForResourceTransferTask:(CPLResourceTransferTask *)arg2;
- (void)libraryManager:(CPLLibraryManager *)arg1 backgroundDownloadDidFinishForResource:(CPLResource *)arg2;
- (void)libraryManager:(CPLLibraryManager *)arg1 inMemoryDownloadDidFinishForResourceTransferTask:(CPLResourceTransferTask *)arg2 data:(NSData *)arg3 withError:(NSError *)arg4;
- (void)libraryManager:(CPLLibraryManager *)arg1 downloadDidFinishForResourceTransferTask:(CPLResourceTransferTask *)arg2 withError:(NSError *)arg3;
- (void)libraryManager:(CPLLibraryManager *)arg1 downloadDidStartForResourceTransferTask:(CPLResourceTransferTask *)arg2;

@optional
- (void)sizeOfResourcesToUploadDidChangeForLibraryManager:(CPLLibraryManager *)arg1;
- (void)libraryManager:(CPLLibraryManager *)arg1 uploadDidProgress:(float)arg2 forResourceTransferTask:(CPLResourceTransferTask *)arg3;
- (void)libraryManager:(CPLLibraryManager *)arg1 downloadDidProgress:(float)arg2 forResourceTransferTask:(CPLResourceTransferTask *)arg3;
- (void)libraryManager:(CPLLibraryManager *)arg1 backgroundDownloadDidFailForResource:(CPLResource *)arg2;
@end

@protocol CPLLibraryManagerDelegate <NSObject>
- (void)libraryManagerHasChangesToPull:(CPLLibraryManager *)arg1;
- (void)libraryManagerDidStartSynchronization:(CPLLibraryManager *)arg1;
- (void)libraryManagerStatusDidChange:(CPLLibraryManager *)arg1;

@optional
- (NSString *)displayableNameForLibraryManager:(CPLLibraryManager *)arg1;
- (void)libraryManagerHasStatusChanges:(CPLLibraryManager *)arg1;
- (void)libraryManagerDidChangeConfiguration:(CPLLibraryManager *)arg1;
@end

@protocol UMUserSyncStakeholder <UMUserSwitchStakeholder>
- (void)uploadContent;
@end

@protocol CPLDaemonLibraryManagerProtocol <CPLDaemonLibraryManagerMinimalProtocol>
- (void)acknowledgeChangedStatuses:(NSArray *)arg1;
- (void)deleteResources:(NSArray *)arg1 checkServerIfNecessary:(_Bool)arg2 completionHandler:(void (^)(NSArray *, NSDictionary *))arg3;
- (void)commitChangeBatch:(CPLChangeBatch *)arg1 withCompletionHandler:(void (^)(NSError *, unsigned long long, CPLPushChangeTasks *, NSString *))arg2;
- (void)acknowledgeChangeBatch:(CPLChangeBatch *)arg1 withCompletionHandler:(void (^)(NSError *, NSString *))arg2;
- (void)getChangeBatchWithCompletionHandler:(void (^)(NSError *, CPLChangeBatch *))arg1;
- (void)finalizeSessionWithCompletionHandler:(void (^)(NSError *))arg1;
- (void)beginPullSessionWithKnownLibraryVersion:(NSString *)arg1 context:(CPLChangeSessionContext *)arg2 completionHandler:(void (^)(NSError *))arg3;
- (void)beginPushSessionWithKnownLibraryVersion:(NSString *)arg1 context:(CPLChangeSessionContext *)arg2 completionHandler:(void (^)(NSError *))arg3;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol CPLFileWatcherDelegate <NSObject>
- (void)fileWatcherFileDidDisappear:(CPLFileWatcher *)arg1;
- (void)fileWatcherFileDidAppear:(CPLFileWatcher *)arg1;
@end

@protocol CPLDaemonLibraryManagerDelegate <NSObject>
- (void)startSyncTask;
- (void)daemonLibraryManagerIsDeactivatingLibrary:(CPLDaemonLibraryManager *)arg1;
- (void)daemonLibraryManagerHasBeenDisconnected:(CPLDaemonLibraryManager *)arg1;
- (CPLEngineLibrary *)daemonLibraryManager:(CPLDaemonLibraryManager *)arg1 engineLibraryWithClientLibraryBaseURL:(NSURL *)arg2 cloudLibraryStateStorageURL:(NSURL *)arg3 cloudLibraryResourceStorageURL:(NSURL *)arg4 libraryIdentifier:(NSString *)arg5 error:(id *)arg6;
@end

@protocol CPLBatterySaverWatcherDelegate <NSObject>
- (void)batterySaverWatcherDidChangeState:(CPLBatterySaverWatcher *)arg1;
@end

@protocol APSConnectionDelegate <NSObject>
- (void)connection:(APSConnection *)arg1 didReceivePublicToken:(NSData *)arg2;

@optional
- (void)connectionDidReconnect:(APSConnection *)arg1;
- (void)connection:(APSConnection *)arg1 didChangeConnectedStatus:(_Bool)arg2;
- (void)connection:(APSConnection *)arg1 didFailToSendOutgoingMessage:(APSOutgoingMessage *)arg2 error:(NSError *)arg3;
- (void)connection:(APSConnection *)arg1 didSendOutgoingMessage:(APSOutgoingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveMessageForTopic:(NSString *)arg2 userInfo:(NSDictionary *)arg3;
- (void)connection:(APSConnection *)arg1 didReceiveIncomingMessage:(APSIncomingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveToken:(NSData *)arg2 forTopic:(NSString *)arg3 identifier:(NSString *)arg4;
@end

@protocol CPLCameraWatcherDelegate <NSObject>
- (void)cameraWatcherDidChangeState:(CPLCameraWatcher *)arg1;
@end

@protocol NSXPCConnectionDelegate <NSObject>

@optional
- (void)connection:(NSXPCConnection *)arg1 handleInvocation:(NSInvocation *)arg2 isReply:(_Bool)arg3;
- (id <NSSecureCoding>)replacementObjectForXPCConnection:(NSXPCConnection *)arg1 encoder:(NSXPCCoder *)arg2 object:(id)arg3;
@end

@protocol CPLEngineLibraryOwner <NSObject>
- (void)engineLibrary:(CPLEngineLibrary *)arg1 getStatusDictionaryWithCompletionHandler:(void (^)(NSDictionary *, NSError *))arg2;
- (void)engineLibrary:(CPLEngineLibrary *)arg1 getStatusWithCompletionHandler:(void (^)(NSString *, NSError *))arg2;
- (NSString *)ownerNameForEngineLibrary:(CPLEngineLibrary *)arg1;
- (void)engineLibrary:(CPLEngineLibrary *)arg1 noteClientIsInForeground:(_Bool)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/VoiceServices.framework/Support/voiced
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol VSSpeechXPCServiceProtocol <NSObject>
- (oneway void)getLogToFile:(void (^)(_Bool))arg1;
- (oneway void)setLogToFile:(_Bool)arg1;
- (oneway void)getVoiceInfoForLanguageCode:(NSString *)arg1 footprint:(long long)arg2 gender:(long long)arg3 type:(long long)arg4 reply:(void (^)(VSVoiceAsset *))arg5;
- (oneway void)getVoiceResourceForLanguage:(NSString *)arg1 reply:(void (^)(VSVoiceResourceAsset *))arg2;
- (oneway void)getAutoDownloadedVoiceAssets:(void (^)(NSArray *))arg1;
- (oneway void)setAutoDownloadedVoiceAssets:(NSArray *)arg1;
- (oneway void)getLocalVoiceResourcesReply:(void (^)(NSArray *, NSError *))arg1;
- (oneway void)getLocalVoicesReply:(void (^)(NSArray *, NSError *))arg1;
- (oneway void)cleanUnusedAssets:(void (^)(NSError *))arg1;
- (oneway void)getSpeechIsActiveForConnectionReply:(void (^)(_Bool))arg1;
- (oneway void)getSpeechIsActiveReply:(void (^)(_Bool))arg1;
- (oneway void)getFootprintsForVoiceName:(NSString *)arg1 languageCode:(NSString *)arg2 reply:(void (^)(NSArray *))arg3;
- (oneway void)getVoiceNamesForLanguage:(NSString *)arg1 reply:(void (^)(NSArray *))arg2;
- (oneway void)stopPresynthesizedAudioRequest;
- (oneway void)startPresynthesizedAudioRequest:(VSPresynthesizedAudioRequest *)arg1;
- (oneway void)stopSpeechRequestAtMark:(long long)arg1;
- (oneway void)continueSpeechRequest;
- (oneway void)pauseSpeechRequestAtMark:(long long)arg1;
- (oneway void)startSynthesisRequest:(VSSpeechRequest *)arg1;
- (oneway void)startSpeechRequest:(VSSpeechRequest *)arg1;
- (oneway void)prewarmIfNeededWithRequest:(VSSpeechRequest *)arg1;
- (oneway void)updateWithConnectionIdentifier:(NSString *)arg1;
@end

@protocol VSSpeechServiceDelegate <NSObject>
- (oneway void)presynthesizedAudioRequestSuccessWithInstrumentMetrics:(VSInstrumentMetrics *)arg1 error:(NSError *)arg2;
- (oneway void)presynthesizedAudioRequestDidStopAtEnd:(_Bool)arg1 error:(NSError *)arg2;
- (oneway void)presynthesizedAudioRequestDidStart;
- (oneway void)synthesisRequestDidFinishWithInstrumentMetrics:(VSInstrumentMetrics *)arg1 error:(NSError *)arg2;
- (oneway void)speechRequestDidReceiveTimingInfo:(NSArray *)arg1;
- (oneway void)speechRequestSuccessWithInstrumentMetrics:(VSInstrumentMetrics *)arg1;
- (oneway void)speechRequestDidStopWithSuccess:(_Bool)arg1 phonemesSpoken:(NSString *)arg2 error:(NSError *)arg3;
- (oneway void)speechRequestMark:(long long)arg1 didStartForRange:(struct _NSRange)arg2;
- (oneway void)speechRequestDidContinue;
- (oneway void)speechRequestDidPause;
- (oneway void)speechRequestDidStart;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/AuthKit.framework/akd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/Frameworks/ReplayKit.framework/PlugIns/RPBroadcastActivityViewControllerExtension.appex/RPBroadcastActivityViewControllerExtension
 */

@protocol NSXPCConnectionDelegate <NSObject>

@optional
- (void)connection:(NSXPCConnection *)arg1 handleInvocation:(NSInvocation *)arg2 isReply:(_Bool)arg3;
- (id <NSSecureCoding>)replacementObjectForXPCConnection:(NSXPCConnection *)arg1 encoder:(NSXPCCoder *)arg2 object:(id)arg3;
@end

@protocol RPClientProtocol <NSObject>
- (oneway void)recordingTimerDidUpdate:(NSString *)arg1;
- (oneway void)recordingLockInterrupted:(NSError *)arg1;
- (oneway void)captureHandlerWithAudioSample:(NSData *)arg1 absdData:(NSData *)arg2 itemCount:(long long)arg3 bufferType:(long long)arg4 timingData:(NSData *)arg5;
- (oneway void)captureHandlerWithSample:(RPIOSurfaceObject *)arg1 timingData:(NSData *)arg2;
- (oneway void)updateBroadcastURL:(NSURL *)arg1;
- (oneway void)updateBroadcastServiceInfo:(NSDictionary *)arg1;
- (oneway void)stopRecordingWithError:(NSError *)arg1 movieURL:(NSURL *)arg2;
- (oneway void)updateScreenRecordingState:(_Bool)arg1;
@end

@protocol RPDaemonProtocol <NSObject>
- (oneway void)reportCameraUsage:(int)arg1;
- (oneway void)setMicrophoneEnabledPersistent:(_Bool)arg1;
- (oneway void)setBroadcastURL:(NSString *)arg1;
- (oneway void)setHasUserConsentForMicrophone:(_Bool)arg1;
- (oneway void)setHasUserConsentForCamera:(_Bool)arg1;
- (oneway void)synchronousGetCurrentState:(void (^)(NSDictionary *))arg1;
- (oneway void)clientDidResignActive;
- (oneway void)clientDidBecomeActive;
- (oneway void)discardRecordingWithHandler:(void (^)(void))arg1;
- (oneway void)updateProcessIDForAudioCaptureWithPID:(int)arg1;
- (oneway void)setMicrophoneEnabled:(_Bool)arg1;
- (oneway void)resumeRecordingWithWindowLayerContextID:(unsigned int)arg1;
- (oneway void)pauseRecording;
- (oneway void)saveVideoToCameraRoll:(NSURL *)arg1 handler:(void (^)(NSError *))arg2;
- (oneway void)stopRecordingWithStartClipDuration:(double)arg1 endClipDuration:(double)arg2 handler:(void (^)(NSURL *, NSError *))arg3;
- (oneway void)stopRecordingWithHandler:(void (^)(NSURL *, NSError *))arg1;
- (oneway void)getSystemBroadcastExtensionInfo:(void (^)(NSArray *, NSError *))arg1;
- (oneway void)getCurrentBroadcastImages:(void (^)(UIImage *, UIImage *))arg1;
- (oneway void)setupBroadcastWithHostBundleID:(NSString *)arg1 broadcastExtensionBundleID:(NSString *)arg2 broadcastConfigurationData:(NSData *)arg3 userInfo:(NSDictionary *)arg4 handler:(void (^)(NSError *))arg5;
- (oneway void)startRecordingWindowLayerContextIDs:(NSArray *)arg1 windowSize:(struct CGSize)arg2 microphoneEnabled:(_Bool)arg3 cameraEnabled:(_Bool)arg4 broadcast:(_Bool)arg5 systemRecording:(_Bool)arg6 captureEnabled:(_Bool)arg7 listenerEndpoint:(NSXPCListenerEndpoint *)arg8 withHandler:(void (^)(NSError *, _Bool, _Bool))arg9;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/InstallCoordination.framework/Support/installcoordinationd
 */

@protocol IXClientProtocol <NSObject>
- (oneway void)_remote_IXSPromisedOutOfBandStreamingZipTransfer:(NSUUID *)arg1 setArchiveBytesConsumed:(unsigned long long)arg2;
- (oneway void)_remote_IXSPromisedStreamingZipTransfer:(NSUUID *)arg1 consumeExtractedBytesAtPath:(NSURL *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSPromisedStreamingZipTransfer:(NSUUID *)arg1 setArchiveBytesConsumed:(unsigned long long)arg2;
- (oneway void)_remote_IXSPromisedTransferToPath:(NSUUID *)arg1 setShouldCopy:(_Bool)arg2;
- (oneway void)_remote_IXSPromisedTransferToPath:(NSUUID *)arg1 setTransferPath:(NSURL *)arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 setConfigurationCompleteWithCompletion:(void (^)(NSError *))arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 getPlugInPlaceholderPromises:(void (^)(NSArray *, NSError *))arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 hasPlugInPlaceholderPromises:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 setPlugInPlaceholderPromiseUUIDs:(NSArray *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 getEntitlementsPromise:(void (^)(IXDataPromiseSeed *, NSError *))arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 hasEntitlementsPromise:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 setEntitlementsPromiseUUID:(NSUUID *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 getLocalizationDictionary:(void (^)(NSDictionary *, NSError *))arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 setLocalizationPromiseUUID:(NSUUID *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 getIconPromise:(void (^)(IXDataPromiseSeed *, NSError *))arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 hasIconPromise:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 setIconPromiseUUID:(NSUUID *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 getAttributesWithCompletion:(void (^)(IXPlaceholderAttributes *, NSError *))arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 setAttributes:(IXPlaceholderAttributes *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 getLaunchProhibitedWithCompletion:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 setLaunchProhibited:(_Bool)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 getSinfDataWithCompletion:(void (^)(NSData *, NSError *))arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 setSinfPromiseUUID:(NSUUID *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 getMetadataWithCompletion:(void (^)(MIStoreMetadata *, NSError *))arg2;
- (oneway void)_remote_IXSPlaceholder:(NSUUID *)arg1 setMetadataPromiseUUID:(NSUUID *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSOwnedDataPromise:(NSUUID *)arg1 getStagedPath:(void (^)(NSURL *, NSError *))arg2;
- (oneway void)_remote_IXSOwnedDataPromise:(NSUUID *)arg1 setStagedPath:(NSURL *)arg2;
- (oneway void)_remote_IXSDataPromise:(NSUUID *)arg1 getErrorInfo:(void (^)(unsigned long long, NSError *))arg2;
- (oneway void)_remote_IXSDataPromise:(NSUUID *)arg1 resetWithCompletion:(void (^)(NSError *))arg2;
- (oneway void)_remote_IXSDataPromise:(NSUUID *)arg1 cancelForReason:(NSError *)arg2 client:(unsigned long long)arg3 completion:(void (^)(NSError *))arg4;
- (oneway void)_remote_IXSDataPromise:(NSUUID *)arg1 setIsComplete:(_Bool)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSDataPromise:(NSUUID *)arg1 getIsComplete:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSDataPromise:(NSUUID *)arg1 setPercentComplete:(double)arg2;
- (oneway void)_remote_IXSDataPromise:(NSUUID *)arg1 getPercentComplete:(void (^)(double, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 getCoordinationState:(void (^)(unsigned long long, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 prioritizeWithCompletion:(void (^)(NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 getIsPausedWithCompletion:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 setIsPaused:(_Bool)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 fireObserversWithCompletion:(void (^)(NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 getErrorInfo:(void (^)(unsigned long long, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 getIsComplete:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 getPreparationPromise:(void (^)(IXDataPromiseSeed *, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 setPreparationPromiseUUID:(NSUUID *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 getUserDataRestoreShouldBegin:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 hasUserDataPromise:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 getUserDataPromise:(void (^)(IXDataPromiseSeed *, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 setUserDataPromiseUUID:(NSUUID *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 hasInitialODRAssetPromises:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 getInitialODRAssetPromises:(void (^)(NSArray *, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 setInitialODRAssetPromiseUUIDs:(NSArray *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 isUserInitiated:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 setUserInitiated:(_Bool)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 hasAutoEnabledExtensionTypes:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 setAutoEnabledExtensionTypes:(NSArray *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 hasInstallOptions:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 setInstallOptionsPromiseUUID:(NSUUID *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 setAppAssetPromiseDRI:(unsigned long long)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 getAppAssetPromiseDRI:(void (^)(unsigned long long, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 appAssetPromiseHasBegunFulfillment:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 hasAppAssetPromise:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 getAppAssetPromise:(void (^)(IXDataPromiseSeed *, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 setAppAssetPromiseUUID:(NSUUID *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 hasPlaceholderPromise:(void (^)(_Bool, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 getPlaceholderPromise:(void (^)(IXDataPromiseSeed *, NSError *))arg2;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 setPlaceholderPromiseUUID:(NSUUID *)arg2 completion:(void (^)(NSError *))arg3;
- (oneway void)_remote_IXSCoordinatedAppInstall:(NSUUID *)arg1 cancelForReason:(NSError *)arg2 client:(unsigned long long)arg3 completion:(void (^)(NSError *))arg4;
- (void)_remote_displayUserPresentableErrorForApps:(NSArray *)arg1 code:(long long)arg2;
- (void)_remote_displayUserPresentableErrorForApp:(NSString *)arg1 code:(long long)arg2;
- (void)_remote_registerTransientObserver:(NSXPCListenerEndpoint *)arg1 forClientIdentifiers:(NSSet *)arg2 respondingToSelectors:(unsigned long long)arg3;
- (void)_remote_registerObserverMachServiceName:(NSString *)arg1 forClientIdentifiers:(NSSet *)arg2 respondingToSelectors:(unsigned long long)arg3;
- (void)_remote_uninstallAppWithBundleID:(NSString *)arg1 requestUserConfirmation:(_Bool)arg2 completion:(void (^)(NSError *))arg3;
- (void)_remote_prioritizeCoordinatorForAppWithBundleID:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (void)_remote_setIsPaused:(_Bool)arg1 forCoordinatorForAppWithBundleID:(NSString *)arg2 completion:(void (^)(NSError *))arg3;
- (void)_remote_cancelCoordinatorsForAppsWithBundleIDs:(NSArray *)arg1 reason:(NSError *)arg2 client:(unsigned long long)arg3 completion:(void (^)(NSError *))arg4;
- (void)_remote_cancelCoordinatorForAppWithBundleID:(NSString *)arg1 reason:(NSError *)arg2 client:(unsigned long long)arg3 completion:(void (^)(NSError *))arg4;
- (void)_remote_setRemovability:(unsigned long long)arg1 forAppWithBundleID:(NSString *)arg2 completion:(void (^)(NSError *))arg3;
- (void)_remote_removabilityForAppWithBundleID:(NSString *)arg1 completion:(void (^)(unsigned long long, NSError *))arg2;
- (void)_remote_setTestingEnabled:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)_remote_pingDaemonWithCompletion:(void (^)(NSError *))arg1;
- (void)_remote_killDaemonForTestingWithCompletion:(void (^)(NSError *))arg1;
- (void)_remote_purgeRegisteredCoordinatorsAndPromisesForCreator:(unsigned long long)arg1 completion:(void (^)(NSError *))arg2;
- (void)_remote_fetchRegisteredDataPromiseInfoForCreator:(unsigned long long)arg1 completion:(void (^)(NSArray *, NSError *))arg2;
- (void)_remote_fetchSeedsForCoordinatorsWithIntent:(unsigned long long)arg1 completion:(void (^)(NSArray *, NSError *))arg2;
- (void)_remote_removeObserverForCoordinatorWithUUID:(NSUUID *)arg1;
- (void)_remote_addObserversForCoordinatorsWithUUIDs:(NSSet *)arg1 fireObserverMethods:(_Bool)arg2;
- (void)_remote_createAppInstallCoordinatorWithSeed:(IXAppInstallCoordinatorSeed *)arg1 createIfNotExisting:(_Bool)arg2 completion:(void (^)(IXAppInstallCoordinatorSeed *, _Bool, NSError *))arg3;
- (void)_remote_removeObserverForDataPromiseWithUUID:(NSUUID *)arg1;
- (void)_remote_addObserversForDataPromisesWithUUIDs:(NSSet *)arg1;
- (void)_remote_createOutOfBandStreamingZipTransferDataPromiseWithSeed:(IXPromisedOutOfBandStreamingZipTransferSeed *)arg1 completion:(void (^)(IXPromisedOutOfBandStreamingZipTransferSeed *, NSError *))arg2;
- (void)_remote_createOutOfBandTransferPromiseWithSeed:(IXPromisedOutOfBandTransferSeed *)arg1 completion:(void (^)(IXPromisedOutOfBandTransferSeed *, NSError *))arg2;
- (void)_remote_createInMemoryDictionaryPromiseWithSeed:(IXPromisedInMemoryDictionarySeed *)arg1 dictionary:(NSDictionary *)arg2 completion:(void (^)(IXPromisedInMemoryDictionarySeed *, NSError *))arg3;
- (void)_remote_createInMemoryDataPromiseWithSeed:(IXPromisedInMemoryDataSeed *)arg1 data:(NSData *)arg2 completion:(void (^)(IXPromisedInMemoryDataSeed *, NSError *))arg3;
- (void)_remote_createStreamingZipTransferDataPromiseWithSeed:(IXPromisedStreamingZipTransferSeed *)arg1 completion:(void (^)(IXPromisedStreamingZipTransferSeed *, NSError *))arg2;
- (void)_remote_createTransferToPathDataPromiseWithSeed:(IXPromisedTransferToPathSeed *)arg1 completion:(void (^)(IXPromisedTransferToPathSeed *, NSError *))arg2;
- (void)_remote_createPlaceholderDataPromiseWithSeed:(IXPlaceholderSeed *)arg1 completion:(void (^)(IXPlaceholderSeed *, NSError *))arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/ManagedConfiguration.framework/Support/mdmd
 */

@protocol MCMDMXPCProtocol <NSObject, MCMDMClientProtocol>
- (void)processDeviceRequest:(NSDictionary *)arg1 completion:(void (^)(NSError *, NSDictionary *))arg2;
- (void)uprootMDMWithCompletion:(void (^)(NSError *))arg1;
- (void)migrateMDMWithContext:(int)arg1 completion:(void (^)(NSError *))arg2;
- (void)retryNotNowWithCompletion:(void (^)(NSError *))arg1;
- (void)simulatePushIfNetworkTetheredWithCompletion:(void (^)(NSError *))arg1;
- (void)simulatePushWithCompletion:(void (^)(NSError *))arg1;
- (void)scheduleTokenUpdateIfNecessaryWithCompletion:(void (^)(NSError *))arg1;
- (void)scheduleTokenUpdateWithCompletion:(void (^)(NSError *))arg1;
- (void)notifyNewConfigurationWithCompletion:(void (^)(NSError *))arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/PrintKit.framework/XPCServices/com.apple.PrintKit.PrinterTool.xpc/com.apple.PrintKit.PrinterTool
 */

@protocol WPDeviceScannerDelegate <NSObject>
- (void)deviceScannerDidUpdateState:(WPDeviceScanner *)arg1;

@optional
- (void)scanner:(WPDeviceScanner *)arg1 foundAnyDevice:(NSUUID *)arg2 withData:(NSDictionary *)arg3;
- (void)scanner:(WPDeviceScanner *)arg1 didFailToRegisterDevices:(NSDictionary *)arg2 withError:(NSError *)arg3;
- (void)scanner:(WPDeviceScanner *)arg1 foundRequestedDevices:(NSArray *)arg2;
- (void)scanner:(WPDeviceScanner *)arg1 foundDevice:(NSUUID *)arg2 withData:(NSDictionary *)arg3;
@end

@protocol PKBrowserProtocol <NSObject>
- (void)aggdDiscoveredPrinterStatistics;
- (void)stopBrowsing;
- (void)startBrowsing;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/AssistantServices.framework/XPCServices/com.apple.siri.ClientFlow.ClientScripter.xpc/com.apple.siri.ClientFlow.ClientScripter
 */

@protocol CFCommandProcessing <NSObject>
- (void)isDeviceLockedWithPasscodeWithCompletion:(void (^)(_Bool))arg1;
- (void)handleCommand:(SABaseCommand *)arg1 reply:(void (^)(SABaseCommand *))arg2;
- (void)handleOneWayCommand:(SABaseCommand *)arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/NanoBackup.framework/nanobackupd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NBServerProtocol <NSObject>
- (void)deleteBackupID:(NSUUID *)arg1 completionHandler:(void (^)(NSError *))arg2;
- (void)createBackupForPairingID:(NSUUID *)arg1 completionHandler:(void (^)(NBBackup *, NSError *))arg2;
- (void)restoreFromPairingID:(NSUUID *)arg1 forPairingID:(NSUUID *)arg2 completionHandler:(void (^)(NSError *))arg3;
- (void)restoreFromBackupID:(NSUUID *)arg1 forPairingID:(NSUUID *)arg2 completionHandler:(void (^)(NSError *))arg3;
- (void)listBackupsWithCompletionHandler:(void (^)(NSArray *, NSError *))arg1;
@end


/*
 * Protocols for /System/Library/CoreServices/ScreenSharingServer.app/ScreenSharingServer
 */

@protocol IDSSessionDelegate <NSObject>

@optional
- (void)session:(NSString *)arg1 didReceiveData:(NSData *)arg2;
- (void)sessionEnded:(IDSSession *)arg1 withReason:(unsigned int)arg2 error:(NSError *)arg3;
- (void)sessionEnded:(IDSSession *)arg1;
- (void)sessionStarted:(IDSSession *)arg1;
- (void)session:(IDSSession *)arg1 receivedInvitationCancelFromID:(NSString *)arg2;
- (void)session:(IDSSession *)arg1 receivedInvitationDeclineFromID:(NSString *)arg2;
- (void)session:(IDSSession *)arg1 receivedInvitationAcceptFromID:(NSString *)arg2;
@end


/*
 * Protocols for /usr/libexec/nsurlsessiond
 */

@protocol NSURLSessionTaskDelegatePrivate <NSURLSessionTaskDelegate>

@optional
- (void)URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 _conditionalRequirementsChanged:(_Bool)arg3;
- (void)URLSession:(NSURLSession *)arg1 _taskIsWaitingForConnection:(NSURLSessionTask *)arg2;
- (void)URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 _isWaitingForConnectionWithReason:(long long)arg3;
- (void)URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 _isWaitingForConnectionWithError:(NSError *)arg3;
- (void)URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 _willSendRequestForEstablishedConnection:(NSURLRequest *)arg3 completionHandler:(void (^)(NSURLRequest *))arg4;
- (void)URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 _schemeUpgraded:(NSURLRequest *)arg3 completionHandler:(void (^)(NSURLRequest *))arg4;
@end

@protocol NDBackgroundSessionProtocol <NSObject>
- (void)avAggregateAssetDownloadTaskWithDownloadToken:(unsigned long long)arg1 serializedMediaSelections:(NSArray *)arg2 assetTitle:(NSString *)arg3 assetArtworkData:(NSData *)arg4 options:(NSDictionary *)arg5 childDownloadSessionIdentifier:(NSString *)arg6 identifier:(unsigned long long)arg7 uniqueIdentifier:(NSString *)arg8 reply:(void (^)(_Bool))arg9;
- (void)avAssetDownloadTaskWithDownloadToken:(unsigned long long)arg1 URL:(NSURL *)arg2 destinationURL:(NSURL *)arg3 temporaryDestinationURL:(NSURL *)arg4 assetTitle:(NSString *)arg5 assetArtworkData:(NSData *)arg6 options:(NSDictionary *)arg7 identifier:(unsigned long long)arg8 uniqueIdentifier:(NSString *)arg9 reply:(void (^)(_Bool))arg10;
- (void)setPropertyOnStreamWithIdentifier:(unsigned long long)arg1 propDict:(NSDictionary *)arg2 propKey:(NSString *)arg3 withReply:(void (^)(_Bool))arg4;
- (void)invalidateWithReply:(void (^)(void))arg1;
- (void)resetStorageWithReply:(void (^)(void))arg1;
- (void)setBytesPerSecondLimit:(long long)arg1 forTaskWithIdentifier:(unsigned long long)arg2;
- (void)setLoadingPoolPriority:(double)arg1 forTaskWithIdentifier:(unsigned long long)arg2;
- (void)setPriority:(long long)arg1 forTaskWithIdentifier:(unsigned long long)arg2;
- (void)setDescription:(NSString *)arg1 forTask:(unsigned long long)arg2;
- (void)resumeTaskWithIdentifier:(unsigned long long)arg1 withProperties:(NSDictionary *)arg2;
- (void)suspendTaskWithIdentifier:(unsigned long long)arg1;
- (void)cancelTaskWithIdentifier:(unsigned long long)arg1 byProducingResumeData:(void (^)(NSData *))arg2;
- (void)cancelTaskWithIdentifier:(unsigned long long)arg1;
- (void)downloadTaskWithResumeData:(NSData *)arg1 identifier:(unsigned long long)arg2 uniqueIdentifier:(NSString *)arg3 reply:(void (^)(_Bool))arg4;
- (void)dataTaskWithRequest:(NSURLRequest *)arg1 originalRequest:(NSURLRequest *)arg2 identifier:(unsigned long long)arg3 uniqueIdentifier:(NSString *)arg4 reply:(void (^)(_Bool))arg5;
- (void)uploadTaskWithRequest:(NSURLRequest *)arg1 originalRequest:(NSURLRequest *)arg2 fromFile:(NSURL *)arg3 sandboxExtensionData:(NSData *)arg4 identifier:(unsigned long long)arg5 uniqueIdentifier:(NSString *)arg6 potentialCredentials:(NSDictionary *)arg7 reply:(void (^)(_Bool))arg8;
- (void)downloadTaskWithRequest:(NSURLRequest *)arg1 originalRequest:(NSURLRequest *)arg2 downloadFilePath:(NSString *)arg3 identifier:(unsigned long long)arg4 uniqueIdentifier:(NSString *)arg5 reply:(void (^)(_Bool))arg6;
@end

@protocol NDCallbackQueueDelegate <NSObject>
- (NSString *)descriptionForTaskWithIdentifier:(unsigned long long)arg1;
- (id <NSXPCProxyCreating><NDBackgroundSessionClient>)getClientProxy;
- (void)clientAcknowledgedTerminalCallbackForTask:(unsigned long long)arg1;
- (void)errorOccurredDuringAuthCallbackDelivery:(NSError *)arg1 completionHandler:(void (^)(long long, NSURLCredential *))arg2;
- (void)errorOccurredDuringFinishedCallbackDelivery:(NSError *)arg1;
- (void)wakeUpClient;
@end

@protocol NSURLSessionDataDelegate_Internal <NSURLSessionDataDelegate>
- (void)_URLSession:(NSURLSession *)arg1 dataTask:(NSURLSessionDataTask *)arg2 didReceiveData:(NSData *)arg3 completionHandler:(void (^)(void))arg4;
@end

@protocol NSURLSessionDownloadDelegate_Private <NSURLSessionDownloadDelegate>
- (NSURL *)_URLSession:(NSURLSession *)arg1 downloadTaskNeedsDownloadDirectory:(NSURLSessionDownloadTask *)arg2;
- (void)_URLSession:(NSURLSession *)arg1 downloadTask:(NSURLSessionDownloadTask *)arg2 didReceiveResponse:(NSURLResponse *)arg3;
@end

@protocol NDCredentialStorageDelegate <NSObject>
- (id <NSXPCProxyCreating><NDBackgroundSessionClient>)getClientProxy;
@end

@protocol NDApplicationObserver <NSObject>

@optional
- (void)applicationEndedExtendedNonDiscretionaryBackgroundGracePeriod:(NDApplication *)arg1;
- (void)applicationEndedNonDiscretionaryBackgroundGracePeriod:(NDApplication *)arg1;
- (void)applicationNoLongerInForeground:(NDApplication *)arg1;
- (void)applicationEnteredForeground:(NDApplication *)arg1;
- (void)applicationWasSuspended:(NDApplication *)arg1;
- (void)backgroundUpdatesDisabledForApplication:(NDApplication *)arg1;
- (void)applicationWasQuitFromAppSwitcher:(NDApplication *)arg1;
@end

@protocol NSURLSessionDelegate_Internal <NSURLSessionDelegate>
- (void)_URLSession:(NSURLSession *)arg1 task:(NSURLSessionTask *)arg2 getAuthHeadersForResponse:(NSURLResponse *)arg3 completionHandler:(void (^)(_Bool, NSDictionary *))arg4;

@optional
- (void)_URLSession:(NSURLSession *)arg1 needConnectedSocketToHost:(NSString *)arg2 port:(unsigned long long)arg3 completionHandler:(void (^)(int, struct))arg4;
- (void)_URLSession:(NSURLSession *)arg1 companionAvailabilityChanged:(_Bool)arg2;
- (void)_URLSession:(NSURLSession *)arg1 openFileAtPath:(NSString *)arg2 mode:(int)arg3 completionHandler:(void (^)(int))arg4;
@end

@protocol NSURLSessionDownloadDelegate <NSURLSessionTaskDelegate>
- (void)URLSession:(NSURLSession *)arg1 downloadTask:(NSURLSessionDownloadTask *)arg2 didFinishDownloadingToURL:(NSURL *)arg3;

@optional
- (void)URLSession:(NSURLSession *)arg1 downloadTask:(NSURLSessionDownloadTask *)arg2 didResumeAtOffset:(long long)arg3 expectedTotalBytes:(long long)arg4;
- (void)URLSession:(NSURLSession *)arg1 downloadTask:(NSURLSessionDownloadTask *)arg2 didWriteData:(long long)arg3 totalBytesWritten:(long long)arg4 totalBytesExpectedToWrite:(long long)arg5;
@end

@protocol NDBackgroundSessionDelegate <NSObject>
- (void)sessionCompleted:(NDBackgroundSession *)arg1 withCompletionHandler:(void (^)(void))arg2;
@end

@protocol NDBackgroundSessionManagerProtocol <NSObject>
- (void)obliterateAllSessionsWithReply:(void (^)(void))arg1;
- (void)getActiveSessionIdentifiersWithReply:(void (^)(NSArray *))arg1;
- (void)okayToSendPendingCallbacksForIdentifier:(NSString *)arg1 reply:(void (^)(void))arg2;
- (void)releaseAssertionForSession:(NSString *)arg1 reply:(void (^)(void))arg2;
- (void)sendPendingCallbacksForIdentifier:(NSString *)arg1 reply:(void (^)(void))arg2;
- (void)createSessionWithConfiguration:(NSURLSessionConfiguration *)arg1 clientProxy:(id <NDBackgroundSessionClient>)arg2 cachesDirectory:(NSURL *)arg3 options:(NSDictionary *)arg4 reply:(void (^)(id <NDBackgroundSessionProtocol>, NSDictionary *, _Bool))arg5;
- (void)dropBoost;
- (void)boost;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/DistributedEvaluation.framework/XPCServices/com.apple.siri-distributed-evaluation.xpc/com.apple.siri-distributed-evaluation
 */

@protocol DESService <NSObject>
- (void)runLiveEvaluationForAllBundlesWithBaseURL:(NSURL *)arg1 localeIdentifier:(NSString *)arg2 completion:(void (^)(NSError *))arg3;
- (void)runLiveEvaluationForBundleId:(NSString *)arg1 baseURL:(NSURL *)arg2 localeIdentifier:(NSString *)arg3 completion:(void (^)(NSError *))arg4;
- (void)runEvaluationForBundleId:(NSString *)arg1 recipe:(NSDictionary *)arg2 recordUUID:(NSUUID *)arg3 attachments:(NSArray *)arg4 completion:(void (^)(NSDictionary *, NSError *))arg5;
- (void)runEvaluationForBundleId:(NSString *)arg1 recipe:(NSDictionary *)arg2 recordInfo:(NSDictionary *)arg3 recordData:(NSData *)arg4 attachments:(NSArray *)arg5 completion:(void (^)(NSDictionary *, NSError *))arg6;
- (void)deleteSavedRecordForBundleId:(NSString *)arg1 identfier:(NSUUID *)arg2 completion:(void (^)(NSError *))arg3;
- (void)deleteAllSavedRecordsForBundleId:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (void)fetchSavedRecordInfoForBundleId:(NSString *)arg1 completion:(void (^)(NSDictionary *, NSError *))arg2;
- (void)saveRecordForBundleId:(NSString *)arg1 data:(NSData *)arg2 recordInfo:(NSDictionary *)arg3 completion:(void (^)(NSUUID *, NSError *))arg4;
- (void)fetchInstalledBundlesIdsWithCompletion:(void (^)(NSArray *, NSError *))arg1;
@end


/*
 * Protocols for /usr/sbin/wirelessproxd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol WPXPCDaemonProtocol <NSObject>

@optional
- (void)disconnectFromLEPipePeer:(NSUUID *)arg1;
- (void)sendDatatoLePipe:(NSData *)arg1 forPeer:(NSUUID *)arg2;
- (void)unregisterEndpoint:(NSString *)arg1;
- (void)registerEndpoint:(NSString *)arg1;
- (void)enableBubbleTestMode;
- (void)dumpDaemonState;
- (void)registerForAnyScanResults:(_Bool)arg1;
- (void)disableScanning;
- (void)getPowerLogStats:(void (^)(NSDictionary *))arg1;
- (void)enableTestMode;
- (void)registerWithDaemon:(NSString *)arg1 forProcess:(NSString *)arg2 machName:(NSString *)arg3 shouldHoldVoucherForConnections:(_Bool)arg4;
- (void)listenToBandwidthNotifications;
- (void)checkAllowDuplicates:(void (^)(_Bool))arg1;
- (void)getAllTrackedZones;
- (void)stopTrackingAllZones;
- (void)stopTrackingZones:(NSArray *)arg1;
- (void)startTrackingZone:(WPZoneTrackingRequest *)arg1;
- (void)sendDataToCharacteristic:(WPCharacteristic *)arg1 inService:(NSString *)arg2 forPeer:(NSUUID *)arg3;
- (void)shouldSubscribe:(_Bool)arg1 toPeer:(NSUUID *)arg2 withCharacteristic:(NSString *)arg3 inService:(NSString *)arg4;
- (void)discoverCharacteristicsAndServices:(NSDictionary *)arg1 forPeripheral:(NSUUID *)arg2;
- (void)disconnectFromPeer:(NSUUID *)arg1;
- (void)connectToPeer:(NSUUID *)arg1 withOptions:(NSDictionary *)arg2;
- (void)connectToPeer:(NSUUID *)arg1;
- (void)stopTrackingPeerWithRequest:(WPPeerTrackingRequest *)arg1;
- (void)startTrackingPeerWithRequest:(WPPeerTrackingRequest *)arg1;
- (void)stopScanning:(WPScanRequest *)arg1;
- (void)startScanning:(WPScanRequest *)arg1;
- (void)stopAdvertising:(WPAdvertisingRequest *)arg1;
- (void)startAdvertising:(WPAdvertisingRequest *)arg1;
- (void)addCharacteristic:(WPCharacteristic *)arg1 forService:(NSUUID *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/NanoPreferencesSync.framework/nanoprefsyncd
 */

@protocol IDSServiceDelegate <NSObject>

@optional
- (void)service:(IDSService *)arg1 didSwitchActivePairedDevice:(IDSDevice *)arg2 acknowledgementBlock:(void (^)(void))arg3;
- (void)serviceAllowedTrafficClassifiersDidReset:(IDSService *)arg1;
- (void)serviceSpaceDidBecomeAvailable:(IDSService *)arg1;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4 withContext:(NSData *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4 withOptions:(NSDictionary *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 hasBeenDeliveredWithContext:(id)arg4;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 didSendWithSuccess:(_Bool)arg4 error:(NSError *)arg5 context:(IDSMessageContext *)arg6;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 didSendWithSuccess:(_Bool)arg4 error:(NSError *)arg5;
- (void)service:(IDSService *)arg1 connectedDevicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 nearbyDevicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 devicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 activeAccountsChanged:(NSSet *)arg2;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingResourceAtURL:(NSURL *)arg3 metadata:(NSDictionary *)arg4 fromID:(NSString *)arg5 context:(IDSMessageContext *)arg6;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingResourceAtURL:(NSURL *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingUnhandledProtobuf:(IDSProtobuf *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingData:(NSData *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingMessage:(NSDictionary *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
@end

@protocol NPSServerProtocol <NSObject>
- (void)synchronizeUserDefaultsDomain:(NSString *)arg1 keys:(NSSet *)arg2 container:(NSString *)arg3 appGroupContainer:(NSString *)arg4 cloudEnabled:(_Bool)arg5;
@end

@protocol PSYSyncCoordinatorDelegate <NSObject>

@optional
- (void)syncCoordinatorDidReceiveStartSyncCommand:(PSYSyncCoordinator *)arg1;
- (void)supportsMigrationSync;
- (void)syncCoordinatorDidChangeSyncRestriction:(PSYSyncCoordinator *)arg1;
- (void)syncCoordinator:(PSYSyncCoordinator *)arg1 didInvalidateSyncSession:(PSYServiceSyncSession *)arg2;
- (void)syncCoordinator:(PSYSyncCoordinator *)arg1 beginSyncSession:(PSYServiceSyncSession *)arg2;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/Frameworks/CoreTelephony.framework/Support/CommCenter
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol CTCellularPlanClient <NSObject>
- (void)setActivePlan:(NSData *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)shouldShowAddNewRemotePlan:(void (^)(_Bool))arg1;
- (void)getRemoteInfo:(void (^)(NSDictionary *, NSError *))arg1;
- (void)setAutoPlanSelection:(_Bool)arg1;
- (void)getAutoPlanSelectionWithCompletion:(void (^)(_Bool))arg1;
- (void)deleteAllRemoteProfiles;
- (void)deleteRemoteProfile:(NSString *)arg1;
- (void)selectRemoteProfile:(NSString *)arg1;
- (void)fetchRemoteProfiles:(NSString *)arg1;
- (void)userDidProvideConsentResponse:(_Bool)arg1 iccid:(NSString *)arg2 completion:(void (^)(_Bool, NSError *))arg3;
- (void)eraseAllRemotePlansWithCompletion:(void (^)(_Bool, NSError *))arg1;
- (void)remotePlansSignupParamsForCsn:(NSData *)arg1 completion:(void (^)(NSDictionary *))arg2;
- (void)remotePlanLaunchInfoForCsn:(NSData *)arg1 completion:(void (^)(NSString *, NSDictionary *, NSError *))arg2;
- (void)didCancelRemotePlan;
- (void)didPurchaseRemotePlanForEid:(NSString *)arg1 imei:(NSString *)arg2 meid:(NSString *)arg3 iccid:(NSString *)arg4 alternateSmdpFqdn:(NSString *)arg5 completion:(void (^)(_Bool))arg6;
- (void)didDeleteRemotePlanItem:(CTCellularPlanItem *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)didSelectRemotePlanItem:(CTCellularPlanItem *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)remotePlanItemsWithUpdateFetch:(_Bool)arg1 completion:(void (^)(NSArray *, NSError *))arg2;
- (void)manageAccountForRemotePlan:(CTCellularPlanItem *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)addNewRemotePlanWithAddress:(NSString *)arg1 matchingId:(NSString *)arg2 oid:(NSString *)arg3 confirmationCode:(NSString *)arg4 isPairing:(_Bool)arg5 userConsent:(long long)arg6 completion:(void (^)(NSError *))arg7;
- (void)addNewRemotePlanWithCardData:(NSString *)arg1 confirmationCode:(NSString *)arg2 isPairing:(_Bool)arg3 userConsent:(long long)arg4 completion:(void (^)(NSError *))arg5;
- (void)addNewRemotePlan:(_Bool)arg1 userConsent:(long long)arg2 completion:(void (^)(NSError *))arg3;
- (void)finishRemoteProvisioningWithCompletion:(void (^)(_Bool))arg1;
- (void)startRemoteProvisioningWithCompletion:(void (^)(_Bool))arg1;
- (void)shouldShowAddNewRemotePlanWithFlowType:(void (^)(_Bool, unsigned long long, NSError *))arg1;
- (void)isRemotePlanCapable:(void (^)(_Bool))arg1;
- (void)launchDataActivationNextWithUrl:(NSString *)arg1;
- (void)updatePlansDatabase;
- (void)expirePlan;
- (void)launchSequoia;
- (void)setLatitude:(NSNumber *)arg1 andLongitude:(NSNumber *)arg2;
- (void)latitudeLongitudeOverride:(void (^)(double, double))arg1;
- (void)setMcc:(long long)arg1 andMnc:(long long)arg2;
- (void)mccMncOverride:(void (^)(long long, long long))arg1;
- (void)setSelectedProxy:(long long)arg1;
- (void)getSelectedProxy:(void (^)(long long))arg1;
- (void)setSelectedEnv:(long long)arg1;
- (void)getSelectedEnv:(void (^)(long long))arg1;
- (void)setESimServerURL:(NSString *)arg1;
- (void)getESimServerURL:(void (^)(NSString *))arg1;
- (void)setIMEIPrefix:(NSString *)arg1;
- (void)getIMEIPrefix:(void (^)(NSString *))arg1;
- (void)getCurrentPlanType:(void (^)(long long))arg1;
- (void)openInternalUrlId:(long long)arg1;
- (void)getDeviceInfo:(void (^)(NSDictionary *))arg1;
- (void)retrieveRequestSettings:(void (^)(NSDictionary *, NSDictionary *, NSDictionary *))arg1;
- (void)fetchNewProfilesWithCompletion:(void (^)(_Bool, NSError *))arg1 additionalParameters:(NSDictionary *)arg2;
- (void)registerHasNewProfileCompletion:(void (^)(_Bool, _Bool))arg1;
- (void)setUserInPurchaseFlow:(_Bool)arg1;
- (void)didProvisionEsimWithIccid:(NSString *)arg1;
- (void)didPurchasePlanWithIccid:(NSString *)arg1 downloadProfile:(_Bool)arg2;
- (void)remoteSignIdMapForSessionId:(NSString *)arg1 locationRequired:(_Bool)arg2 withCompletion:(void (^)(NSString *, NSError *))arg3;
- (void)signIdMapForSessionId:(NSString *)arg1 locationRequired:(_Bool)arg2 withCompletion:(void (^)(NSString *, NSError *))arg3 latitude:(NSNumber *)arg4 longitude:(NSNumber *)arg5;
- (void)manageAccountForPlan:(CTCellularPlanItem *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)didSelectPlanItem:(CTCellularPlanItem *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)willDisplayPlanItems;
- (void)planItemsWithCompletion:(void (^)(NSArray *, NSError *))arg1;
- (void)shouldShowPlanList:(void (^)(_Bool))arg1;
- (void)isAddButtonEnabled:(void (^)(_Bool))arg1;
- (void)triggerAddNewDataPlan:(void (^)(NSError *))arg1;
- (void)isRoamingPlanSupportAvailable:(void (^)(_Bool))arg1;
- (void)isMultipleDataPlanSupportAvailable:(void (^)(_Bool))arg1;
- (void)isNewDataPlanCapable:(void (^)(_Bool))arg1;
- (void)ping;
@end

@protocol NSXPCConnectionDelegate <NSObject>

@optional
- (void)connection:(NSXPCConnection *)arg1 handleInvocation:(NSInvocation *)arg2 isReply:(_Bool)arg3;
- (id <NSSecureCoding>)replacementObjectForXPCConnection:(NSXPCConnection *)arg1 encoder:(NSXPCCoder *)arg2 object:(id)arg3;
@end

@protocol CTCarrierSpaceServiceInterface <NSObject>
- (void)refreshAppsInfo:(void (^)(NSError *))arg1;
- (void)refreshPlansInfo:(void (^)(NSError *))arg1;
- (void)refreshUsageInfo:(void (^)(NSError *))arg1;
- (void)userDidAcceptPlanTerms:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)authenticationDidFail:(NSError *)arg1 completion:(void (^)(NSError *))arg2;
- (void)authenticationDidComplete:(CTCarrierSpaceAuthInfo *)arg1 completion:(void (^)(NSError *))arg2;
- (void)setUserInAuthFlow:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)testMode:(_Bool)arg1 config:(NSDictionary *)arg2 completion:(void (^)(NSError *))arg3;
- (void)ping:(void (^)(NSError *))arg1;
- (void)fetchDataPlanMetrics:(void (^)(CTCarrierSpaceDataPlanMetrics *, NSError *))arg1;
- (void)purchasePlan:(CTCarrierSpacePlanGroupOptionInfo *)arg1 completion:(void (^)(NSError *))arg2;
- (void)refreshAllInfo:(void (^)(NSError *))arg1;
- (void)fetchAppsInfo:(_Bool)arg1 completion:(void (^)(CTCarrierSpaceAppsInfo *, NSError *))arg2;
- (void)fetchPlansInfo:(_Bool)arg1 completion:(void (^)(CTCarrierSpacePlansInfo *, NSError *))arg2;
- (void)fetchUsageInfo:(_Bool)arg1 completion:(void (^)(CTCarrierSpaceUsageInfo *, NSError *))arg2;
- (void)setUserConsent:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)getUserConsentFlowInfo:(void (^)(CTCarrierSpaceUserConsentFlowInfo *, NSError *))arg1;
- (void)getCapabilities:(void (^)(CTCarrierSpaceCapabilities *, NSError *))arg1;
@end

@protocol CTCarrierSpaceClientProxyDelegate <NSObject>
- (void)proxyDidBecomeInvalidated:(CTCarrierSpaceClientProxy *)arg1;
@end


/*
 * Protocols for /private/var/staged_system_apps/Tips.app/PlugIns/TipsNotificationExtension.appex/TipsNotificationExtension
 */

@protocol UNNotificationContentExtension <NSObject>
- (void)didReceiveNotification:(UNNotification *)arg1;

@optional
@property(readonly, copy, nonatomic) UIColor *mediaPlayPauseButtonTintColor;
@property(readonly, nonatomic) struct CGRect mediaPlayPauseButtonFrame;
@property(readonly, nonatomic) unsigned long long mediaPlayPauseButtonType;
- (void)mediaPause;
- (void)mediaPlay;
- (void)didReceiveNotificationResponse:(UNNotificationResponse *)arg1 completionHandler:(void (^)(unsigned long long))arg2;
@end

@protocol TPSSingleTipViewControllerDelegate <NSObject>
- (void)singleTipViewControllerContentSizeChanged:(TPSSingleTipViewController *)arg1;
@end


/*
 * Protocols for /Applications/CheckerBoard.app/CheckerBoard
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol CBSServerProtocol <CBSRemoteAlertServerProtocol, CBSSystemServicesProtocol>
@end


/*
 * Protocols for /usr/libexec/feedbackarchiverd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol AchiverdProtocol <NSObject>
- (void)clientDidFinishBackgroundUpdates;
- (void)fetchJobStatesWithCompletion:(void (^)(NSArray *, NSArray *, NSString *))arg1;
- (void)ping;
- (void)archiveDirectory:(NSURL *)arg1;
@end

@protocol ADSpringBoardDelegate <NSObject>
- (void)failedToOpenClientWithError:(NSError *)arg1;
- (void)didOpenClient;
- (void)clientWasTerminatedAfterBackgroundLaunch;
@end


/*
 * Protocols for /System/Library/Frameworks/FileProvider.framework/Support/fileproviderd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol APSConnectionDelegate <NSObject>
- (void)connection:(APSConnection *)arg1 didReceivePublicToken:(NSData *)arg2;

@optional
- (void)connectionDidReconnect:(APSConnection *)arg1;
- (void)connection:(APSConnection *)arg1 didChangeConnectedStatus:(_Bool)arg2;
- (void)connection:(APSConnection *)arg1 didFailToSendOutgoingMessage:(APSOutgoingMessage *)arg2 error:(NSError *)arg3;
- (void)connection:(APSConnection *)arg1 didSendOutgoingMessage:(APSOutgoingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveMessageForTopic:(NSString *)arg2 userInfo:(NSDictionary *)arg3;
- (void)connection:(APSConnection *)arg1 didReceiveIncomingMessage:(APSIncomingMessage *)arg2;
- (void)connection:(APSConnection *)arg1 didReceiveToken:(NSData *)arg2 forTopic:(NSString *)arg3 identifier:(NSString *)arg4;
@end

@protocol FPDProcessMonitorDelegate <NSObject>
- (void)processMonitor:(FPDProcessMonitor *)arg1 didBecomeForeground:(_Bool)arg2;
@end


/*
 * Protocols for /private/var/staged_system_apps/Maps.app/Maps
 */

@protocol DirectionsManagerObserver <NSObject>

@optional
- (void)directionsManager:(DirectionsManager *)arg1 didChangeChromeTransportType:(long long)arg2;
- (void)directionsManager:(DirectionsManager *)arg1 displayDirectionsToSelectedRouteWithNavigationOfType:(int)arg2 options:(long long)arg3;
- (void)directionsManager:(DirectionsManager *)arg1 displayDirectionsToSelectedRouteWithoutNavigationWithOptions:(long long)arg2;
- (void)directionsManager:(DirectionsManager *)arg1 willStartDirectionsToCurrentRouteWithOptions:(long long)arg2;
- (void)directionsManager:(DirectionsManager *)arg1 needsPromptToSimulateForOptions:(long long)arg2;
- (void)directionsManagerDidUpdateUserLocation:(DirectionsManager *)arg1;
- (void)directionsManagerDidUpdateToStepIndex:(DirectionsManager *)arg1 stepIndex:(NSNumber *)arg2;
- (void)directionsManagerDidSwitchToNewRoute:(DirectionsManager *)arg1 route:(Route *)arg2;
- (void)directionsManagerWillClear:(DirectionsManager *)arg1;
- (void)directionsManagerDidReset:(DirectionsManager *)arg1;
- (void)directionsManagerWillReset:(DirectionsManager *)arg1;
- (void)directionsManagerDidCancelLoad:(DirectionsManager *)arg1;
- (void)directionsManagerDidFailToLoadInitialRoutes:(DirectionsManager *)arg1 withError:(NSError *)arg2;
- (void)directionsManager:(DirectionsManager *)arg1 didLoadRoute:(Route *)arg2;
- (void)directionsManager:(DirectionsManager *)arg1 didLoadWaypointsForStart:(DirectionsWaypoint *)arg2 end:(DirectionsWaypoint *)arg3;
- (void)directionsManagerDidStartLoad:(DirectionsManager *)arg1;
@end

@protocol CustomSearchManagerObserver <NSObject>
- (void)customSearchManager:(CustomSearchManager *)arg1 didModifyCustomSearchResult:(SearchResult *)arg2 coordinateChanged:(_Bool)arg3;
- (void)customSearchManager:(CustomSearchManager *)arg1 didReplaceCustomSearchResult:(SearchResult *)arg2 animated:(_Bool)arg3 shouldSelectOnMap:(_Bool)arg4 context:(id <NSObject><NSCopying>)arg5;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/HomeSharing.framework/Support/itunescloudd
 */

@protocol CloudPushNotificationControllerDelegate <NSObject>
- (void)pushNotificationController:(CloudPushNotificationController *)arg1 didReceivePushForService:(int)arg2 message:(ICPushNotificationMessage *)arg3;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol SSAuthenticateRequestDelegate <SSRequestDelegate>

@optional
- (void)authenticateRequest:(SSAuthenticateRequest *)arg1 didReceiveResponse:(SSAuthenticateResponse *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/CoreParsec.framework/parsecd
 */

@protocol FlusherXPC <NSObject>
- (void)sendDataToSendingStreamListener:(NSArray *)arg1;
- (void)sendDataToReceivingStreamListener:(_CPParsecFeedback *)arg1;
- (NSXPCListenerEndpoint *)endpoint;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NSXPCConnectionDelegate <NSObject>

@optional
- (void)connection:(NSXPCConnection *)arg1 handleInvocation:(NSInvocation *)arg2 isReply:(_Bool)arg3;
- (id <NSSecureCoding>)replacementObjectForXPCConnection:(NSXPCConnection *)arg1 encoder:(NSXPCCoder *)arg2 object:(id)arg3;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/NanoPassKit.framework/NPKCompanionAgent
 */

@protocol NPDCompanionPassLibraryDataSource <NSObject>
- (PKPaymentWebService *)paymentWebService;
- (NSArray *)secureElementIdentifiers;
@end

@protocol NPKGizmoDatabaseMigrationDataSource <NSObject>
- (NSArray *)secureElementIdentifiers;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NPKRemoteAdminConnectionServiceAgentDelegate <NSObject>
- (void)didReceiveCheckCompanionPeerPaymentState;
- (void)didReceivePaymentSetupRequestForApplicationName:(NSString *)arg1;
- (void)paymentPassWithUniqueIdentifier:(NSString *)arg1 didRemoveTransactionWithIdentifier:(NSString *)arg2;
- (void)paymentPassWithUniqueIdentifier:(NSString *)arg1 didReceiveTransaction:(PKPaymentTransaction *)arg2;
@end

@protocol IDSServiceDelegate <NSObject>

@optional
- (void)service:(IDSService *)arg1 didSwitchActivePairedDevice:(IDSDevice *)arg2 acknowledgementBlock:(void (^)(void))arg3;
- (void)serviceAllowedTrafficClassifiersDidReset:(IDSService *)arg1;
- (void)serviceSpaceDidBecomeAvailable:(IDSService *)arg1;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4 withContext:(NSData *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4 withOptions:(NSDictionary *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 inviteReceivedForSession:(IDSSession *)arg3 fromID:(NSString *)arg4;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 hasBeenDeliveredWithContext:(id)arg4;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 didSendWithSuccess:(_Bool)arg4 error:(NSError *)arg5 context:(IDSMessageContext *)arg6;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 identifier:(NSString *)arg3 didSendWithSuccess:(_Bool)arg4 error:(NSError *)arg5;
- (void)service:(IDSService *)arg1 connectedDevicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 nearbyDevicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 devicesChanged:(NSArray *)arg2;
- (void)service:(IDSService *)arg1 activeAccountsChanged:(NSSet *)arg2;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingResourceAtURL:(NSURL *)arg3 metadata:(NSDictionary *)arg4 fromID:(NSString *)arg5 context:(IDSMessageContext *)arg6;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingResourceAtURL:(NSURL *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingUnhandledProtobuf:(IDSProtobuf *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingData:(NSData *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
- (void)service:(IDSService *)arg1 account:(IDSAccount *)arg2 incomingMessage:(NSDictionary *)arg3 fromID:(NSString *)arg4 context:(IDSMessageContext *)arg5;
@end

@protocol NPKCompanionServerProtocol <NSObject>
- (void)handlePotentialExpressPass:(PKPaymentPass *)arg1 withCompletionHandler:(void (^)(_Bool, NSSet *))arg2;
- (void)felicaStateWithPassUniqueIdentifier:(NSString *)arg1 paymentApplication:(PKPaymentApplication *)arg2 completion:(void (^)(PKFelicaTransitAppletState *))arg3;
- (void)deletePaymentTransactionWithIdentifier:(NSString *)arg1 passUniqueIdentifier:(NSString *)arg2 fromDeviceWithPairingID:(NSUUID *)arg3 completion:(void (^)(NSError *))arg4;
- (void)transactionsForPaymentPassWithUniqueIdentifier:(NSString *)arg1 withTransactionSource:(unsigned long long)arg2 withBackingData:(unsigned long long)arg3 limit:(long long)arg4 completion:(void (^)(NSSet *))arg5;
- (void)initiateLostModeExitAuthWithCompletion:(void (^)(NSError *))arg1;
- (void)peerPaymentAccountForPairingID:(NSUUID *)arg1 withCompletion:(void (^)(PKPeerPaymentAccount *))arg2;
- (void)setPeerPaymentAccount:(PKPeerPaymentAccount *)arg1 forPairingID:(NSUUID *)arg2 completion:(void (^)(void))arg3;
- (void)sharedPeerPaymentWebServiceContextForPairingID:(NSUUID *)arg1 withCompletion:(void (^)(PKPeerPaymentWebServiceContext *))arg2;
- (void)setSharedPeerPaymentWebServiceContext:(PKPeerPaymentWebServiceContext *)arg1 forPairingID:(NSUUID *)arg2 completion:(void (^)(void))arg3;
- (void)sharedPaymentWebServiceContextForPairingID:(NSUUID *)arg1 withCompletion:(void (^)(PKPaymentWebServiceContext *))arg2;
- (void)setSharedPaymentWebServiceContext:(PKPaymentWebServiceContext *)arg1 forPairingID:(NSUUID *)arg2 completion:(void (^)(void))arg3;
- (void)handlePendingiCloudSignoutWithCompletion:(void (^)(void))arg1;
- (void)handlePendingUnpairingWithCompletion:(void (^)(void))arg1;
- (void)redownloadAllPaymentPassesWithCompletion:(void (^)(void))arg1;
- (void)initiateConsistencyCheckWithCompletion:(void (^)(void))arg1;
- (void)setDefaultPaymentApplication:(PKPaymentApplication *)arg1 forPassWithUniqueID:(NSString *)arg2 completion:(void (^)(PKPaymentPass *))arg3;
- (void)defaultPaymentApplicationForPassWithUniqueID:(NSString *)arg1 completion:(void (^)(PKPaymentApplication *))arg2;
- (void)defaultCard:(void (^)(NSString *))arg1;
- (void)setDefaultCard:(NSString *)arg1 completion:(void (^)(_Bool))arg2;
- (void)removePaymentPassWithUniqueID:(NSString *)arg1 forPairingID:(NSUUID *)arg2 requireRemoteConfirmation:(_Bool)arg3 completion:(void (^)(_Bool, NSError *))arg4;
- (void)savePaymentPassAtURL:(NSURL *)arg1 withUniqueID:(NSString *)arg2 forPairingID:(NSUUID *)arg3 completion:(void (^)(_Bool))arg4;
- (void)paymentPassWithDeviceAccountIdentifier:(NSString *)arg1 completion:(void (^)(PKPaymentPass *))arg2;
- (void)paymentPassesWithPrimaryAccountIdentifier:(NSString *)arg1 completion:(void (^)(NSSet *))arg2;
- (void)paymentPassWithUniqueID:(NSString *)arg1 reply:(void (^)(PKPaymentPass *))arg2;
- (void)paymentPassUniqueIDs:(void (^)(NSSet *))arg1;
- (void)noteProvisioningPreflightCompleteWithSuccess:(_Bool)arg1 error:(NSError *)arg2 completion:(void (^)(void))arg3;
- (void)beginProvisioningFromWatchOfferForPaymentPass:(PKPaymentPass *)arg1 withCompletion:(void (^)(_Bool, NSError *))arg2;
- (void)noteWatchOfferDisplayedForPaymentPassWithUniqueID:(NSString *)arg1;
- (void)connect;
@end

@protocol NPDCardSetupReminderNotificationSchedulerDelegate <NSObject>
- (void)removeReminderNotificationForPassWithUniqueID:(NSString *)arg1;
- (void)postVerifyReminderNotificationForPassWithUniqueID:(NSString *)arg1;
- (void)postAddReminderNotificationForPassWithUniqueID:(NSString *)arg1;
- (_Bool)hasAnyWatchPaymentPasses;
- (_Bool)hasCompanionPaymentPassWithUniqueID:(NSString *)arg1;
- (_Bool)hasWatchPaymentPassRequiringVerificationWithUniqueID:(NSString *)arg1;
- (_Bool)hasWatchPaymentPassWithUniqueID:(NSString *)arg1;
@end

@protocol PSYSyncCoordinatorDelegate <NSObject>

@optional
- (void)syncCoordinatorDidReceiveStartSyncCommand:(PSYSyncCoordinator *)arg1;
- (void)supportsMigrationSync;
- (void)syncCoordinatorDidChangeSyncRestriction:(PSYSyncCoordinator *)arg1;
- (void)syncCoordinator:(PSYSyncCoordinator *)arg1 didInvalidateSyncSession:(PSYServiceSyncSession *)arg2;
- (void)syncCoordinator:(PSYSyncCoordinator *)arg1 beginSyncSession:(PSYServiceSyncSession *)arg2;
@end


/*
 * Protocols for /usr/libexec/replayd
 */

@protocol RPRecordingSessionDelegate <NSObject>
- (void)broadcastSession:(RPRecordingSession *)arg1 didUpdateDuration:(double)arg2;
- (void)broadcastSession:(RPRecordingSession *)arg1 didUpdateServiceInfo:(NSDictionary *)arg2;
- (void)recordingSession:(RPRecordingSession *)arg1 stoppedWithError:(NSError *)arg2;
@end

@protocol MCProfileConnectionObserver <NSObject>

@optional
- (void)profileConnectionDidReceiveAppWhitelistChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
- (void)profileConnectionDidReceiveDefaultsChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
- (void)profileConnectionDidReceiveEffectiveSettingsChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
- (void)profileConnectionDidReceiveProfileListChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
- (void)profileConnectionDidReceivePasscodePolicyChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
- (void)profileConnectionDidReceivePasscodeChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
- (void)profileConnectionDidReceiveRestrictionChangedNotification:(MCProfileConnection *)arg1 userInfo:(NSDictionary *)arg2;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol RPBroadcastDaemonProtocol <NSObject>
- (void)finishBroadcastWithError:(NSError *)arg1;
- (void)updateBroadcastURL:(NSURL *)arg1;
- (void)updateServiceInfo:(NSDictionary *)arg1;
- (void)ping;
@end

@protocol RPBroadcastExtensionProtocol <NSObject>
- (void)processPayload:(NSDictionary *)arg1 completion:(void (^)(void))arg2;
@end

@protocol RPClientProtocol <NSObject>
- (oneway void)recordingTimerDidUpdate:(NSString *)arg1;
- (oneway void)recordingLockInterrupted:(NSError *)arg1;
- (oneway void)captureHandlerWithAudioSample:(NSData *)arg1 absdData:(NSData *)arg2 itemCount:(long long)arg3 bufferType:(long long)arg4 timingData:(NSData *)arg5;
- (oneway void)captureHandlerWithSample:(RPIOSurfaceObject *)arg1 timingData:(NSData *)arg2;
- (oneway void)updateBroadcastURL:(NSURL *)arg1;
- (oneway void)updateBroadcastServiceInfo:(NSDictionary *)arg1;
- (oneway void)stopRecordingWithError:(NSError *)arg1 movieURL:(NSURL *)arg2;
- (oneway void)updateScreenRecordingState:(_Bool)arg1;
@end

@protocol FBSDisplayLayoutObserver <NSObject>

@optional
- (void)layoutMonitor:(FBSDisplayLayoutMonitor *)arg1 didUpdateDisplayLayout:(FBSDisplayLayout *)arg2 withContext:(FBSDisplayLayoutTransitionContext *)arg3;
- (void)layoutMonitor:(FBSDisplayLayoutMonitor *)arg1 didUpdateDisplayLayout:(FBSDisplayLayout *)arg2;
@end

@protocol CXCallObserverDelegate <NSObject>
- (void)callObserver:(CXCallObserver *)arg1 callChanged:(CXCall *)arg2;
@end

@protocol SBSStatusBarStyleOverridesCoordinatorDelegate <NSObject>
- (void)statusBarCoordinator:(SBSStatusBarStyleOverridesCoordinator *)arg1 invalidatedRegistrationWithError:(NSError *)arg2;

@optional
- (_Bool)statusBarCoordinator:(SBSStatusBarStyleOverridesCoordinator *)arg1 receivedTapWithContext:(id <SBSStatusBarTapContext>)arg2 completionBlock:(void (^)(void))arg3;
@end

@protocol RPDaemonProtocol <NSObject>
- (oneway void)reportCameraUsage:(int)arg1;
- (oneway void)setMicrophoneEnabledPersistent:(_Bool)arg1;
- (oneway void)setBroadcastURL:(NSString *)arg1;
- (oneway void)setHasUserConsentForMicrophone:(_Bool)arg1;
- (oneway void)setHasUserConsentForCamera:(_Bool)arg1;
- (oneway void)synchronousGetCurrentState:(void (^)(NSDictionary *))arg1;
- (oneway void)clientDidResignActive;
- (oneway void)clientDidBecomeActive;
- (oneway void)discardRecordingWithHandler:(void (^)(void))arg1;
- (oneway void)updateProcessIDForAudioCaptureWithPID:(int)arg1;
- (oneway void)setMicrophoneEnabled:(_Bool)arg1;
- (oneway void)resumeRecordingWithWindowLayerContextID:(unsigned int)arg1;
- (oneway void)pauseRecording;
- (oneway void)saveVideoToCameraRoll:(NSURL *)arg1 handler:(void (^)(NSError *))arg2;
- (oneway void)stopRecordingWithStartClipDuration:(double)arg1 endClipDuration:(double)arg2 handler:(void (^)(NSURL *, NSError *))arg3;
- (oneway void)stopRecordingWithHandler:(void (^)(NSURL *, NSError *))arg1;
- (oneway void)getSystemBroadcastExtensionInfo:(void (^)(NSArray *, NSError *))arg1;
- (oneway void)getCurrentBroadcastImages:(void (^)(UIImage *, UIImage *))arg1;
- (oneway void)setupBroadcastWithHostBundleID:(NSString *)arg1 broadcastExtensionBundleID:(NSString *)arg2 broadcastConfigurationData:(NSData *)arg3 userInfo:(NSDictionary *)arg4 handler:(void (^)(NSError *))arg5;
- (oneway void)startRecordingWindowLayerContextIDs:(NSArray *)arg1 windowSize:(struct CGSize)arg2 microphoneEnabled:(_Bool)arg3 cameraEnabled:(_Bool)arg4 broadcast:(_Bool)arg5 systemRecording:(_Bool)arg6 captureEnabled:(_Bool)arg7 listenerEndpoint:(NSXPCListenerEndpoint *)arg8 withHandler:(void (^)(NSError *, _Bool, _Bool))arg9;
@end

@protocol BBRemoteDataProvider <BBDataProvider>
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/AppStoreDaemon.framework/appstored.bundle/appstored
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/VoiceMemos.framework/Support/voicememod
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NSXPCConnectionDelegate <NSObject>

@optional
- (void)connection:(NSXPCConnection *)arg1 handleInvocation:(NSInvocation *)arg2 isReply:(_Bool)arg3;
- (id <NSSecureCoding>)replacementObjectForXPCConnection:(NSXPCConnection *)arg1 encoder:(NSXPCCoder *)arg2 object:(id)arg3;
@end

@protocol RCSSavedRecordingServiceProtocol <NSObject>
- (oneway void)updateSearchMetadataWithRecordingURIsToInsert:(NSArray *)arg1 recordingURIsToUpdate:(NSArray *)arg2 recordingURIsToDelete:(NSArray *)arg3 completionBlock:(void (^)(NSError *))arg4;
- (oneway void)clearAndReloadSearchMetadataWithCompletionBlock:(void (^)(NSError *))arg1;
- (oneway void)reloadExistingSearchMetadataWithCompletionBlock:(void (^)(NSError *))arg1;
- (oneway void)fetchCompositionAVURLsBeingModified:(void (^)(NSSet *))arg1;
- (oneway void)fetchCompositionAVURLsBeingExported:(void (^)(NSSet *))arg1;
- (oneway void)enableOrphanHandlingWithCompletionBlock:(void (^)(NSError *))arg1;
- (oneway void)disableOrphanHandlingWithCompletionBlock:(void (^)(NSError *))arg1;
- (oneway void)enableOrphanedFragmentCleanupForCompositionAVURL:(NSURL *)arg1;
- (oneway void)disableOrphanedFragmentCleanupForCompositionAVURL:(NSURL *)arg1 completionBlock:(void (^)(NSError *))arg2;
- (oneway void)endAccessSessionWithToken:(RCSSavedRecordingAccessToken *)arg1;
- (oneway void)removeAllUserDataWithCompletion:(void (^)(NSError *))arg1;
- (oneway void)prepareToTrimCompositionAVURL:(NSURL *)arg1 accessRequestHandler:(void (^)(RCSSavedRecordingAccessToken *, NSError *))arg2;
- (oneway void)prepareToExportCompositionAVURL:(NSURL *)arg1 cacheWaveform:(_Bool)arg2 accessRequestHandler:(void (^)(RCSSavedRecordingAccessToken *, NSError *))arg3;
- (oneway void)prepareToPreviewCompositionAVURL:(NSURL *)arg1 accessRequestHandler:(void (^)(RCSSavedRecordingAccessToken *, NSError *))arg2;
- (oneway void)prepareToCaptureToCompositionAVURL:(NSURL *)arg1 accessRequestHandler:(void (^)(RCSSavedRecordingAccessToken *, NSError *))arg2;
- (oneway void)importRecordingWithSourceAudioURL:(NSURL *)arg1 name:(NSString *)arg2 date:(NSDate *)arg3 importCompletionBlock:(void (^)(NSURL *, NSError *))arg4;
@end

@protocol AssetAccessSessionControllerDelegate <NSObject>
- (void)assetAccessSessionController:(AssetAccessSessionController *)arg1 sessionDidChangedFromActiveSessions:(NSArray *)arg2 toActiveSessions:(NSArray *)arg3;
@end


/*
 * Protocols for /usr/libexec/wifivelocityd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol W5XPCConnectionDelegate <NSObject>
- (void)xpcConnection:(W5XPCConnection *)arg1 cancelWiFiSnifferWithUUID:(NSUUID *)arg2 peerID:(NSString *)arg3 reply:(void (^)(NSError *))arg4;
- (void)xpcConnection:(W5XPCConnection *)arg1 cancelPerformanceTestWithUUID:(NSUUID *)arg2 peerID:(NSString *)arg3 reply:(void (^)(NSError *))arg4;
- (void)xpcConnection:(W5XPCConnection *)arg1 cancelCollectLogsWithUUID:(NSUUID *)arg2 peerID:(NSString *)arg3 reply:(void (^)(NSError *))arg4;
- (void)xpcConnection:(W5XPCConnection *)arg1 cancelDiagnosticsWithUUID:(NSUUID *)arg2 peerID:(NSString *)arg3 reply:(void (^)(NSError *))arg4;
- (void)xpcConnection:(W5XPCConnection *)arg1 runPerformanceTest:(W5PerfConfiguration *)arg2 uuid:(NSUUID *)arg3 reply:(void (^)(NSError *, W5PerfResult *))arg4;
- (void)xpcConnection:(W5XPCConnection *)arg1 runWiFiSnifferOnChannel:(W5WiFiChannel *)arg2 duration:(double)arg3 peer:(W5Peer *)arg4 uuid:(NSUUID *)arg5 reply:(void (^)(NSError *, NSURL *))arg6;
- (void)xpcConnection:(W5XPCConnection *)arg1 collectLogItems:(NSArray *)arg2 compress:(_Bool)arg3 peer:(W5Peer *)arg4 uuid:(NSUUID *)arg5 reply:(void (^)(NSError *, NSArray *, NSURL *))arg6;
- (void)xpcConnection:(W5XPCConnection *)arg1 setDebugConfiguration:(W5DebugConfiguration *)arg2 peer:(W5Peer *)arg3 reply:(void (^)(NSError *))arg4;
- (void)xpcConnection:(W5XPCConnection *)arg1 queryDebugConfigurationForPeer:(W5Peer *)arg2 reply:(void (^)(NSError *, W5DebugConfiguration *))arg3;
- (void)xpcConnection:(W5XPCConnection *)arg1 runDiagnosticsTests:(NSArray *)arg2 peer:(W5Peer *)arg3 uuid:(NSUUID *)arg4 reply:(void (^)(NSError *, NSArray *))arg5;
- (void)xpcConnection:(W5XPCConnection *)arg1 queryStatusForPeer:(W5Peer *)arg2 reply:(void (^)(NSError *, W5Status *))arg3;
- (void)xpcConnection:(W5XPCConnection *)arg1 queryLocalPeerAndReply:(void (^)(NSError *, W5Peer *))arg2;
- (void)xpcConnection:(W5XPCConnection *)arg1 queryPeerCacheAndReply:(void (^)(NSError *, NSArray *))arg2;
- (void)xpcConnection:(W5XPCConnection *)arg1 stopMonitoringEvents:(NSArray *)arg2 reply:(void (^)(NSError *))arg3;
- (void)xpcConnection:(W5XPCConnection *)arg1 startMonitoringEvents:(NSArray *)arg2 reply:(void (^)(NSError *))arg3;
- (void)xpcConnection:(W5XPCConnection *)arg1 stopBrowsingAndReply:(void (^)(NSError *))arg2;
- (void)xpcConnection:(W5XPCConnection *)arg1 startBrowsingAndReply:(void (^)(NSError *))arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/ManagedConfiguration.framework/Support/profiled
 */

@protocol MCXPCProtocol <NSObject>
- (void)mayShareToAirDropForOriginatingAppBundleID:(NSString *)arg1 originatingAccountIsManaged:(_Bool)arg2 completion:(void (^)(_Bool, NSError *))arg3;
- (void)mayShareToMessagesForOriginatingAppBundleID:(NSString *)arg1 originatingAccountIsManaged:(_Bool)arg2 completion:(void (^)(_Bool, NSError *))arg3;
- (void)cancelFeaturePromptWithIdentifier:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (void)showFeaturePromptForSetting:(NSString *)arg1 configurationUUID:(NSString *)arg2 promptOptions:(NSDictionary *)arg3 promptIdentifier:(NSString *)arg4 completion:(void (^)(int, NSError *))arg5;
- (void)shutDownWithCompletion:(void (^)(NSError *))arg1;
- (void)validateAppBundleIDs:(NSArray *)arg1 completion:(void (^)(NSError *))arg2;
- (void)setupAssistantDidFinishCompletion:(void (^)(NSError *))arg1;
- (void)filteredMailAccountsWithSourceAccountManagement:(int)arg1 completion:(void (^)(NSArray *, NSError *))arg2;
- (void)allowedKeyboardBundleIDsAfterApplyingFilterToBundleIDs:(NSArray *)arg1 hostAppBundleID:(NSString *)arg2 accountIsManaged:(_Bool)arg3 completion:(void (^)(NSArray *))arg4;
- (void)unstashWhitelistURLStringsWithCompletion:(void (^)(NSError *))arg1;
- (void)stashWhitelistURLStringsWithCompletion:(void (^)(NSError *))arg1;
- (void)unstashBlacklistURLStringsWithCompletion:(void (^)(NSError *))arg1;
- (void)stashBlacklistURLStringsWithCompletion:(void (^)(NSError *))arg1;
- (void)removeWebContentFilterUserBlacklistedURLString:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (void)unstashUserBookmarksFromLabel:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (void)stashUserBookmarks:(NSArray *)arg1 withLabel:(NSString *)arg2 completion:(void (^)(NSError *))arg3;
- (void)setUserBookmarks:(NSArray *)arg1 completion:(void (^)(NSError *))arg2;
- (void)storeActivationRecord:(NSDictionary *)arg1 completion:(void (^)(NSError *))arg2;
- (void)createActivationLockBypassCodeWithCompletion:(void (^)(NSString *, NSError *))arg1;
- (void)cloudConfigurationStoreDetails:(NSDictionary *)arg1 completion:(void (^)(NSError *))arg2;
- (void)cloudConfigurationMachineInfoDataWithCompletion:(void (^)(NSData *, NSError *))arg1;
- (void)rereadManagedAppAttributesWithCompletion:(void (^)(NSError *))arg1;
- (void)markStoredProfileForPurposeAsInstalled:(int)arg1 completion:(void (^)(NSError *))arg2;
- (void)profileDataStoredForPurpose:(int)arg1 completion:(void (^)(NSData *, NSError *))arg2;
- (void)storeProfileData:(NSData *)arg1 configurationSource:(int)arg2 purpose:(int)arg3 completion:(void (^)(NSError *))arg4;
- (void)removeExpiredProfilesWithCompletion:(void (^)(NSError *))arg1;
- (void)managedAppIDsWithFlags:(int)arg1 completion:(void (^)(NSArray *, NSError *))arg2;
- (void)setUserInfo:(NSDictionary *)arg1 forClientUUID:(NSString *)arg2 completion:(void (^)(NSError *))arg3;
- (void)resetAllSettingsToDefaultsIsUserInitiated:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)recomputePerClientUserComplianceWithCompletion:(void (^)(NSError *))arg1;
- (void)recomputeUserComplianceWarningWithCompletion:(void (^)(NSError *))arg1;
- (void)notifyHaveSeenComplianceMessageWithLastLockDate:(NSDate *)arg1 completion:(void (^)(NSError *))arg2;
- (void)notifyStartComplianceTimer:(NSDate *)arg1 completion:(void (^)(NSError *))arg2;
- (void)removeProvisioningProfileWithUUID:(NSString *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)installProvisioningProfileData:(NSData *)arg1 managingProfileIdentifer:(NSString *)arg2 completion:(void (^)(NSError *))arg3;
- (void)storeCertificateData:(NSData *)arg1 forIPCUIdentifier:(NSString *)arg2 completion:(void (^)(NSError *))arg3;
- (void)openSensitiveURL:(NSString *)arg1 unlock:(_Bool)arg2 completion:(void (^)(NSError *))arg3;
- (void)removeValueSetting:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (void)removeBoolSetting:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (void)setParametersForSettingsByType:(NSDictionary *)arg1 configurationUUID:(NSString *)arg2 toSystem:(_Bool)arg3 user:(_Bool)arg4 passcode:(NSString *)arg5 credentialSet:(NSData *)arg6 completion:(void (^)(NSError *))arg7;
- (void)migratePostMDMDataMigratorWithContext:(int)arg1 completion:(void (^)(NSError *))arg2;
- (void)migrateWithContext:(int)arg1 passcodeWasSetInBackup:(_Bool)arg2 completion:(void (^)(NSError *))arg3;
- (void)managedWiFiNetworkNamesWithCompletion:(void (^)(NSArray *, NSError *))arg1;
- (void)managedSystemConfigurationServiceIDsWithCompletion:(void (^)(NSArray *, NSError *))arg1;
- (void)removeOrphanedClientRestrictionsWithCompletion:(void (^)(NSError *))arg1;
- (void)clearPasscodeWithEscrowKeybagData:(NSData *)arg1 secret:(NSData *)arg2 completion:(void (^)(NSError *))arg3;
- (void)changePasscode:(NSString *)arg1 oldPasscode:(NSString *)arg2 completion:(void (^)(_Bool, NSError *))arg3;
- (void)applyRestrictionDictionary:(NSDictionary *)arg1 appsAndOptions:(NSArray *)arg2 clientType:(NSString *)arg3 clientUUID:(NSString *)arg4 localizedClientDescription:(NSString *)arg5 localizedWarningMessage:(NSString *)arg6 completion:(void (^)(_Bool, _Bool, NSError *))arg7;
- (void)removeProtectedProfileWithIdentifier:(NSString *)arg1 installationType:(long long)arg2 completion:(void (^)(NSError *))arg3;
- (void)removeProfileWithIdentifier:(NSString *)arg1 installationType:(long long)arg2 completion:(void (^)(NSError *))arg3;
- (void)updateProfileIdentifier:(NSString *)arg1 interactive:(_Bool)arg2 completion:(void (^)(NSString *, NSError *))arg3;
- (void)popProvisioningProfileFromHeadOfInstallationQueueWithCompletion:(void (^)(NSData *, NSError *))arg1;
- (void)popProfileDataFromHeadOfInstallationQueueWithCompletion:(void (^)(NSData *, NSError *))arg1;
- (void)queueProfileDataForInstallation:(NSData *)arg1 originalFileName:(NSString *)arg2 originatingBundleID:(NSString *)arg3 transitionToUI:(_Bool)arg4 completion:(void (^)(NSString *, NSError *))arg5;
- (void)installProfileData:(NSData *)arg1 interactive:(_Bool)arg2 options:(NSDictionary *)arg3 completion:(void (^)(NSString *, NSError *))arg4;
- (void)isProfileInstalledWithIdentifier:(NSString *)arg1 completion:(void (^)(NSError *, _Bool))arg2;
- (void)defaultAppBundleIDForCommunicationServiceType:(NSString *)arg1 forAccountWithIdentifier:(NSString *)arg2 completion:(void (^)(NSString *, NSError *))arg3;
- (void)notifyDeviceUnlockedWithCompletion:(void (^)(NSError *))arg1;
- (void)waitForMigrationIncludingPostRestoreMigration:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)addBookmark:(NSDictionary *)arg1 completion:(void (^)(NSError *))arg2;
- (void)addAllowedURLString:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (void)setAllowedURLStrings:(NSArray *)arg1 completion:(void (^)(NSError *))arg2;
- (void)setDictationAllowed:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)setSpellCheckAllowed:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)setKeyboardShortcutsAllowed:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)setPredictiveKeyboardAllowed:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)setSmartPunctuationAllowed:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)setAutoCorrectionAllowed:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)allowedImportFromAppBundleIDs:(NSArray *)arg1 importingAppBundleID:(NSString *)arg2 importingIsManaged:(_Bool)arg3 completion:(void (^)(NSArray *, NSError *))arg4;
- (void)allowedOpenInAppBundleIDs:(NSArray *)arg1 originatingAppBundleID:(NSString *)arg2 originatingIsManaged:(_Bool)arg3 completion:(void (^)(NSArray *, NSError *))arg4;
- (void)checkCarrierProfileAndForceReinstallation:(_Bool)arg1 completion:(void (^)(NSError *))arg2;
- (void)checkInWithCompletion:(void (^)(NSError *))arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/AssistantServices.framework/assistant_service
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol AFServiceHelper <NSObject>
- (_Bool)isTimeoutSuspended;
- (void)handleCommand:(SABaseCommand *)arg1 completion:(void (^)(SABaseCommand *, NSError *))arg2;
- (_Bool)isDeviceLockedWithPasscode;
- (NSString *)assistantLocalizedStringForKey:(NSString *)arg1 table:(NSString *)arg2 bundle:(NSBundle *)arg3;
- (void)dismissAssistant;
- (_Bool)openSensitiveURL:(NSURL *)arg1;
@end

@protocol AFProviderService <NSObject>
- (oneway void)runMaintenanceWorkForServicePath:(NSString *)arg1 className:(NSString *)arg2 completion:(void (^)(void))arg3;
- (oneway void)preheatBundleForServicePath:(NSString *)arg1;
- (oneway void)clearDomainObjectsForServicePath:(NSString *)arg1 className:(NSString *)arg2;
- (oneway void)fetchCurrentSyncSnapshotForServicePath:(NSString *)arg1 className:(NSString *)arg2 key:(NSString *)arg3 completion:(void (^)(AFSyncSnapshot *))arg4;
- (oneway void)beginSyncForServicePath:(NSString *)arg1 className:(NSString *)arg2 requestUUID:(NSUUID *)arg3 info:(AFSyncInfo *)arg4 reply:(void (^)(void))arg5;
- (oneway void)doCommandForServicePath:(NSString *)arg1 className:(NSString *)arg2 infoDictionary:(NSDictionary *)arg3 reply:(void (^)(NSDictionary *, NSArray *, NSError *))arg4;
@end


/*
 * Protocols for /Applications/AccountAuthenticationDialog.app/AccountAuthenticationDialog
 */

@protocol OOPAWebViewControllerDelegate <NSObject>
- (void)webViewController:(OOPAWebViewController *)arg1 didFinishWithSuccess:(_Bool)arg2 response:(NSDictionary *)arg3;
@end

@protocol UIApplicationDelegate <NSObject>

@optional
@property(retain, nonatomic) UIWindow *window;
- (void)application:(UIApplication *)arg1 userDidAcceptCloudKitShareWithMetadata:(CKShareMetadata *)arg2;
- (void)application:(UIApplication *)arg1 didUpdateUserActivity:(NSUserActivity *)arg2;
- (void)application:(UIApplication *)arg1 didFailToContinueUserActivityWithType:(NSString *)arg2 error:(NSError *)arg3;
- (_Bool)application:(UIApplication *)arg1 continueUserActivity:(NSUserActivity *)arg2 restorationHandler:(void (^)(NSArray *))arg3;
- (_Bool)application:(UIApplication *)arg1 willContinueUserActivityWithType:(NSString *)arg2;
- (void)application:(UIApplication *)arg1 didDecodeRestorableStateWithCoder:(NSCoder *)arg2;
- (void)application:(UIApplication *)arg1 willEncodeRestorableStateWithCoder:(NSCoder *)arg2;
- (_Bool)application:(UIApplication *)arg1 shouldRestoreApplicationState:(NSCoder *)arg2;
- (_Bool)application:(UIApplication *)arg1 shouldSaveApplicationState:(NSCoder *)arg2;
- (UIViewController *)application:(UIApplication *)arg1 viewControllerWithRestorationIdentifierPath:(NSArray *)arg2 coder:(NSCoder *)arg3;
- (_Bool)application:(UIApplication *)arg1 shouldAllowExtensionPointIdentifier:(NSString *)arg2;
- (unsigned long long)application:(UIApplication *)arg1 supportedInterfaceOrientationsForWindow:(UIWindow *)arg2;
- (void)applicationProtectedDataDidBecomeAvailable:(UIApplication *)arg1;
- (void)applicationProtectedDataWillBecomeUnavailable:(UIApplication *)arg1;
- (void)applicationWillEnterForeground:(UIApplication *)arg1;
- (void)applicationDidEnterBackground:(UIApplication *)arg1;
- (void)application:(UIApplication *)arg1 handleIntent:(INIntent *)arg2 completionHandler:(void (^)(INIntentResponse *))arg3;
- (void)applicationShouldRequestHealthAuthorization:(UIApplication *)arg1;
- (void)application:(UIApplication *)arg1 handleWatchKitExtensionRequest:(NSDictionary *)arg2 reply:(void (^)(NSDictionary *))arg3;
- (void)application:(UIApplication *)arg1 handleEventsForBackgroundURLSession:(NSString *)arg2 completionHandler:(void (^)(void))arg3;
- (void)application:(UIApplication *)arg1 performActionForShortcutItem:(UIApplicationShortcutItem *)arg2 completionHandler:(void (^)(_Bool))arg3;
- (void)application:(UIApplication *)arg1 performFetchWithCompletionHandler:(void (^)(unsigned long long))arg2;
- (void)application:(UIApplication *)arg1 didReceiveRemoteNotification:(NSDictionary *)arg2 fetchCompletionHandler:(void (^)(unsigned long long))arg3;
- (void)application:(UIApplication *)arg1 handleActionWithIdentifier:(NSString *)arg2 forLocalNotification:(UILocalNotification *)arg3 withResponseInfo:(NSDictionary *)arg4 completionHandler:(void (^)(void))arg5;
- (void)application:(UIApplication *)arg1 handleActionWithIdentifier:(NSString *)arg2 forRemoteNotification:(NSDictionary *)arg3 completionHandler:(void (^)(void))arg4;
- (void)application:(UIApplication *)arg1 handleActionWithIdentifier:(NSString *)arg2 forRemoteNotification:(NSDictionary *)arg3 withResponseInfo:(NSDictionary *)arg4 completionHandler:(void (^)(void))arg5;
- (void)application:(UIApplication *)arg1 handleActionWithIdentifier:(NSString *)arg2 forLocalNotification:(UILocalNotification *)arg3 completionHandler:(void (^)(void))arg4;
- (void)application:(UIApplication *)arg1 didReceiveLocalNotification:(UILocalNotification *)arg2;
- (void)application:(UIApplication *)arg1 didReceiveRemoteNotification:(NSDictionary *)arg2;
- (void)application:(UIApplication *)arg1 didFailToRegisterForRemoteNotificationsWithError:(NSError *)arg2;
- (void)application:(UIApplication *)arg1 didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)arg2;
- (void)application:(UIApplication *)arg1 didRegisterUserNotificationSettings:(UIUserNotificationSettings *)arg2;
- (void)application:(UIApplication *)arg1 didChangeStatusBarFrame:(struct CGRect)arg2;
- (void)application:(UIApplication *)arg1 willChangeStatusBarFrame:(struct CGRect)arg2;
- (void)application:(UIApplication *)arg1 didChangeStatusBarOrientation:(long long)arg2;
- (void)application:(UIApplication *)arg1 willChangeStatusBarOrientation:(long long)arg2 duration:(double)arg3;
- (void)applicationSignificantTimeChange:(UIApplication *)arg1;
- (void)applicationWillTerminate:(UIApplication *)arg1;
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)arg1;
- (_Bool)application:(UIApplication *)arg1 openURL:(NSURL *)arg2 options:(NSDictionary *)arg3;
- (_Bool)application:(UIApplication *)arg1 openURL:(NSURL *)arg2 sourceApplication:(NSString *)arg3 annotation:(id)arg4;
- (_Bool)application:(UIApplication *)arg1 handleOpenURL:(NSURL *)arg2;
- (void)applicationWillResignActive:(UIApplication *)arg1;
- (void)applicationDidBecomeActive:(UIApplication *)arg1;
- (_Bool)application:(UIApplication *)arg1 didFinishLaunchingWithOptions:(NSDictionary *)arg2;
- (_Bool)application:(UIApplication *)arg1 willFinishLaunchingWithOptions:(NSDictionary *)arg2;
- (void)applicationDidFinishLaunching:(UIApplication *)arg1;
@end


/*
 * Protocols for /private/var/staged_system_apps/Tips.app/Tips
 */

@protocol TPSXPCClientInterface <NSObject>
- (oneway void)latestFeedFetchedByDaemon:(NSDictionary *)arg1;
@end

@protocol TPSCollectionsControllerDelegate <NSObject>
- (void)collectionsController:(TPSCollectionsController *)arg1 collectionsMap:(NSDictionary *)arg2;
- (int)collectionsControllerCollectionCount:(TPSCollectionsController *)arg1 collection:(TPSCollection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/AccountNotification.framework/and
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /usr/libexec/rapportd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /usr/libexec/backboardd
 */

@protocol BKSAlternateSystemAppServerProtocol <NSObject>
- (void)unblockSystemAppForAlternateSystemApp;
- (void)terminateAlternateSystemAppWithBundleID:(NSString *)arg1;
- (void)openAlternateSystemAppWithBundleID:(NSString *)arg1;
- (void)blockSystemAppForAlternateSystemApp;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol BKEventFocusManagerServerInterface <NSObject>
- (void)setObservesTouchDelivery:(_Bool)arg1 forTouchIdentifier:(unsigned int)arg2;
- (void)setObservesFocusDeferralChanges:(_Bool)arg1;
@end

@protocol NSXPCConnectionDelegate <NSObject>

@optional
- (void)connection:(NSXPCConnection *)arg1 handleInvocation:(NSInvocation *)arg2 isReply:(_Bool)arg3;
- (id <NSSecureCoding>)replacementObjectForXPCConnection:(NSXPCConnection *)arg1 encoder:(NSXPCCoder *)arg2 object:(id)arg3;
@end

@protocol BKSTouchDeliveryPolicyServerInterface <NSObject>
- (void)ipc_addPolicy:(BKSTouchDeliveryPolicy *)arg1;
@end


/*
 * Protocols for /usr/libexec/fmfd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/Pasteboard.framework/Support/pasted
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol PBClientToServerProtocol <NSObject>
- (void)getAllPasteboardsCompletionBlock:(void (^)(NSArray *, NSError *))arg1;
- (void)performJanitorialTasksCompletionBlock:(void (^)(void))arg1;
- (void)didPasteContentsFromPasteboardWithName:(NSString *)arg1 UUID:(NSUUID *)arg2 completionBlock:(void (^)(void))arg3;
- (void)requestItemFromPasteboardWithName:(NSString *)arg1 UUID:(NSUUID *)arg2 itemIndex:(unsigned long long)arg3 typeIdentifier:(NSString *)arg4 completionBlock:(void (^)(NSData *, PBSecurityScopedURLWrapper *, NSError *))arg5;
- (void)deletePersistentPasteboardWithName:(NSString *)arg1 completionBlock:(void (^)(unsigned long long, NSError *))arg2;
- (void)savePasteboard:(PBItemCollection *)arg1 dataProviderEndpoint:(NSXPCListenerEndpoint *)arg2 completionBlock:(void (^)(unsigned long long, long long, NSError *))arg3;
- (void)localGeneralPasteboardCompletionBlock:(void (^)(PBItemCollection *, NSError *))arg1;
- (void)pasteboardWithName:(NSString *)arg1 createIfNeeded:(_Bool)arg2 completionBlock:(void (^)(PBItemCollection *, NSError *))arg3;
- (void)helloCompletionBlock:(void (^)(void))arg1;
@end

@protocol UAPasteboardClientProtocol <NSObject>
- (void)pasteboardWillBeFetched:(void (^)(void))arg1;
- (void)remotePasteboardAvailable:(_Bool)arg1;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/AppConduit.framework/Support/appconduitd
 */

@protocol ACXDeviceConnectionProtocol <NSObject>
- (void)updatePreferencesForApplicationWithIdentifier:(NSString *)arg1 preferences:(NSDictionary *)arg2 forDeviceWithPairingID:(NSUUID *)arg3 completion:(void (^)(NSError *))arg4;
- (void)fetchProvisioningProfilesForApplicationWithBundleID:(NSString *)arg1 forDeviceWithPairingID:(NSUUID *)arg2 completion:(void (^)(NSDictionary *, NSError *))arg3;
- (void)fetchProvisioningProfilesForDeviceWithPairingID:(NSUUID *)arg1 completion:(void (^)(NSDictionary *, NSError *))arg2;
- (void)removeProvisioningProfileWithID:(NSString *)arg1 fromDeviceWithPairingID:(NSUUID *)arg2 completion:(void (^)(_Bool, NSError *))arg3;
- (void)installProvisioningProfileWithData:(NSData *)arg1 onDeviceWithPairingID:(NSUUID *)arg2 completion:(void (^)(_Bool, NSError *))arg3;
- (void)disableObservers;
- (void)enableObservers;
- (void)getAlwaysInstallForDeviceWithPairingID:(NSUUID *)arg1 completion:(void (^)(_Bool))arg2;
- (void)removeApplication:(NSString *)arg1 fromDeviceWithPairingID:(NSUUID *)arg2 completion:(void (^)(long long))arg3;
- (void)installApplication:(NSString *)arg1 withProvisioningProfileInfo:(NSDictionary *)arg2 forTestFlight:(_Bool)arg3 onDeviceWithPairingID:(NSUUID *)arg4 completion:(void (^)(long long, NSError *))arg5;
- (void)retryPendingAppInstallationsOnDeviceWithPairingID:(NSUUID *)arg1;
- (void)cancelPendingInstallations;
- (void)installAllApplications;
- (void)fetchWatchAppBundleIDForCompanionAppBundleID:(NSString *)arg1 completion:(void (^)(NSString *, NSError *))arg2;
- (void)fetchWatchAppBundleURLWithinCompanionAppWithWatchAppIdentifier:(NSString *)arg1 completion:(void (^)(NSURL *, NSError *))arg2;
- (void)fetchInfoForApplicationWithBundleID:(NSString *)arg1 forDeviceWithPairingID:(NSUUID *)arg2 completion:(void (^)(NSDictionary *, NSError *))arg3;
- (void)fetchApplicationWithContainingApplicationBundleID:(NSString *)arg1 completion:(void (^)(NSDictionary *, NSError *))arg2;
- (void)fetchInstalledCompatibleApplicationsForDeviceWithPairingID:(NSUUID *)arg1 completion:(void (^)(NSDictionary *, NSError *))arg2;
- (void)activeComplicationsForDeviceWithPairingID:(NSUUID *)arg1 completion:(void (^)(NSArray *, NSError *))arg2;
- (void)fetchInstalledComplicationsForDeviceWithPairingID:(NSUUID *)arg1 completion:(void (^)(NSDictionary *, NSError *))arg2;
- (void)fetchInstalledApplicationsForDeviceWithPairingID:(NSUUID *)arg1 completion:(void (^)(NSDictionary *, NSError *))arg2;
@end


/*
 * Protocols for /System/Library/AppRemovalServices/com.apple.tips.appremoval.xpc/com.apple.tips.appremoval
 */

@protocol LSAppRemovalServiceProtocol <NSObject>
- (void)removeAppWithReply:(void (^)(NSError *))arg1;
@end


/*
 * Protocols for /System/Library/CoreServices/SpringBoard.app/SpringBoard
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol SBCardItemsControllerRemoteInterface <NSObject>
- (void)getCardItemsForControllerWithIdentifier:(NSString *)arg1 withHandler:(void (^)(NSArray *, NSError *))arg2;
- (void)setCardItems:(NSArray *)arg1 forControllerWithIdentifier:(NSString *)arg2;
@end

@protocol SBStatusBarStyleOverridesAssertionServer <NSObject>
- (void)setRegisteredOverrides:(NSNumber *)arg1 reply:(void (^)(NSError *))arg2;
- (void)setStatusString:(NSString *)arg1 forAssertionWithIdentifier:(NSString *)arg2;
- (void)deactivateStatusBarStyleOverridesAssertionsWithIdentifiers:(NSSet *)arg1;
- (void)activateStatusBarStyleOverridesAssertions:(NSSet *)arg1 reply:(void (^)(NSDictionary *))arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/BookLibrary.framework/Support/bookassetd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /usr/libexec/fmflocatord
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/iTunesStore.framework/Support/itunesstored
 */

@protocol pjRPsXEyBJiXQnH9 <NSObject>
- (void)getScoreMessageWithIdentifier:(NSString *)arg1 nonce:(NSData *)arg2 completion:(void (^)(NSData *, NSError *))arg3;
- (void)computeScoresUsingSettings:(VD9LmqazgfzMqjuy *)arg1 completion:(void (^)(NSString *, NSData *, NSError *))arg2;
@end

@protocol UMUserSwitchStakeholder <NSObject>
- (void)willSwitchUser;
@end


/*
 * Protocols for /usr/libexec/dmd
 */

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol CATTaskServerDelegate <NSObject>
- (void)server:(CATTaskServer *)arg1 clientSession:(CATTaskSession *)arg2 didInterruptWithError:(NSError *)arg3;
- (CATTaskOperation *)server:(CATTaskServer *)arg1 clientSession:(CATTaskSession *)arg2 operationForRequest:(CATTaskRequest *)arg3 error:(id *)arg4;

@optional
- (void)serverDidInvalidate:(CATTaskServer *)arg1;
- (void)server:(CATTaskServer *)arg1 clientSessionDidInvalidate:(CATTaskSession *)arg2;
- (void)server:(CATTaskServer *)arg1 clientSessionDidDisconnect:(CATTaskSession *)arg2;
- (void)server:(CATTaskServer *)arg1 clientSessionDidConnect:(CATTaskSession *)arg2;
- (void)server:(CATTaskServer *)arg1 clientSession:(CATTaskSession *)arg2 enqueueOperation:(NSOperation *)arg3;
- (void)server:(CATTaskServer *)arg1 clientSession:(CATTaskSession *)arg2 didReceiveNotificationWithName:(NSString *)arg3 userInfo:(NSDictionary *)arg4;
- (_Bool)server:(CATTaskServer *)arg1 clientSession:(CATTaskSession *)arg2 shouldConnectWithTransport:(CATTransport *)arg3;
@end


/*
 * Protocols for /System/Library/PrivateFrameworks/MapsSuggestions.framework/destinationd
 */

@protocol MapsSuggestionsSourceDelegate <NSObject>
- (_Bool)detachSource:(id <MapsSuggestionsSource>)arg1;
- (_Bool)attachSource:(id <MapsSuggestionsSource>)arg1;
- (CLLocation *)currentBestLocation;
- (unsigned long long)deleteEntries:(struct NSArray *)arg1 source:(struct NSString *)arg2;
- (unsigned long long)addOrUpdateSuggestionEntries:(struct NSArray *)arg1 source:(struct NSString *)arg2 deleteMissing:(_Bool)arg3;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol MapsSuggestionsLocationUpdaterDelegate <MapsSuggestionsObject>
- (void)updateLocation:(CLLocation *)arg1;
@end

@protocol MapsSuggestionsSourceProxy <NSObject>
- (void)forceEarlyUpdateWithCompletionBlock:(void (^)(void))arg1;
- (void)stopMonitoringWithCompletionBlock:(void (^)(void))arg1;
- (void)startMonitoringWithCompletionBlock:(void (^)(void))arg1;
@end

@protocol MapsSuggestionsSourceDelegateProxy <NSObject>
- (void)deleteEntriesData:(NSData *)arg1 sourceNameData:(NSData *)arg2 completionBlock:(void (^)(void))arg3;
- (void)addOrUpdateSuggestionEntriesData:(NSData *)arg1 sourceNameData:(NSData *)arg2 deleteMissing:(_Bool)arg3 completionBlock:(void (^)(void))arg4;
@end

@protocol MapsSuggestionsSource <MapsSuggestionsObject>
+ (unsigned long long)disposition;
+ (_Bool)isEnabled;
@property(nonatomic) __weak id <MapsSuggestionsSourceDelegate> delegate;
- (_Bool)canProduceEntriesOfType:(unsigned long long)arg1;
- (double)updateSuggestionEntries;
- (void)stop;
- (void)start;
- (id)init;
- (id)initWithDelegate:(id <MapsSuggestionsSourceDelegate>)arg1;
@end


/*
 * Protocols for /usr/libexec/nanoregistryd
 */

@protocol CBPairingAgentDelegate <NSObject>

@optional
- (void)pairingAgent:(CBPairingAgent *)arg1 peerDidRequestPairing:(CBPeer *)arg2 type:(long long)arg3 passkey:(NSNumber *)arg4;
- (void)pairingAgent:(CBPairingAgent *)arg1 peerDidUnpair:(CBPeer *)arg2;
- (void)pairingAgent:(CBPairingAgent *)arg1 peerDidFailToCompletePairing:(CBPeer *)arg2 error:(NSError *)arg3;
- (void)pairingAgent:(CBPairingAgent *)arg1 peerDidCompletePairing:(CBPeer *)arg2;
@end

@protocol NRRemoteObjectCloudDelegate <NSObject>
- (void)remoteObject:(NRRemoteObjectCloud *)arg1 receivedMigratedAwayWithAdvertisedName:(NSString *)arg2;
- (void)remoteObject:(NRRemoteObjectCloud *)arg1 receivedMigrationRequestWithShouldCancel:(_Bool)arg2 responseBlock:(void (^)(int))arg3;
@end

@protocol NRRecoveryStep <NSObject>
- (double)start:(id <NRRecoveryManagerStepDelegate>)arg1;

@optional
@property(readonly, nonatomic) NSSet *dependencies;
- (id)migrateWithDictionary:(NSDictionary *)arg1;
- (void)invalidate;
- (void)timeoutHandler;
@end

@protocol NRRegistryProxyDelegate <NSObject>
@property(readonly, nonatomic) NRRecoveryManager *activeRecoveryManager;
@property(readonly, nonatomic) NRStateMachine *activeMachine;
@property(readonly, nonatomic) NSObject<OS_dispatch_queue> *deviceQueue;
@property(readonly, nonatomic) _Bool pairing;
- (void)startRecovery;
- (void)_unpairWithDeviceID:(id)arg1 shouldObliterate:(_Bool)arg2 shouldBrick:(_Bool)arg3 shouldPreserveESim:(_Bool)arg4 caller:(NSString *)arg5 operationHasBegun:(void (^)(NSError *))arg6;
- (void)xpcSwitchActiveDeviceWithDeviceID:(NSUUID *)arg1 requestorPID:(int)arg2 withAssertionHandler:(void (^)(NSError *, NSString *))arg3;
- (NRSecureDevicePropertyStore *)secureProperties;
- (_Bool)isSecureDataAvailable;
- (void)xpcGetDeviceCollectionWithNoEntitlementBlock:(void (^)(NRMutableDeviceCollection *, unsigned long long))arg1;
- (void)xpcGetDiffSinceIndex:(unsigned long long)arg1 withNoEntitlementBlock:(void (^)(NRDeviceCollectionDiff *, _Bool, unsigned long long))arg2;
- (void)handleDeadPairingClientWithName:(NSString *)arg1;
- (void)abortPairing;
@end

@protocol NRRemoteObjectClassADelegate <NSObject>
@end

@protocol CBScalablePipeManagerDelegate <NSObject>
- (void)scalablePipeManager:(CBScalablePipeManager *)arg1 pipeDidDisconnect:(CBScalablePipe *)arg2 error:(NSError *)arg3;
- (void)scalablePipeManager:(CBScalablePipeManager *)arg1 pipeDidConnect:(CBScalablePipe *)arg2;
- (void)scalablePipeManager:(CBScalablePipeManager *)arg1 didUnregisterEndpoint:(NSString *)arg2;
- (void)scalablePipeManager:(CBScalablePipeManager *)arg1 didRegisterEndpoint:(NSString *)arg2 error:(NSError *)arg3;
- (void)scalablePipeManagerDidUpdateState:(CBScalablePipeManager *)arg1;
@end

@protocol NSXPCListenerDelegate <NSObject>

@optional
- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;
@end

@protocol NRStateMachineDelegate <NSObject>
- (void)unpairNRDeviceWithDeviceID:(NSUUID *)arg1;
- (NSUUID *)pairedPairingIDForBluetoothID:(NSUUID *)arg1;
- (void)setPairingID:(NSUUID *)arg1 forBluetoothID:(NSUUID *)arg2;
- (NSUUID *)updateNRMutableDeviceFromEPDevice:(EPDevice *)arg1 withNRUUID:(NSUUID *)arg2;
- (void)deleteUnexpectedIDSPairedDevices;
- (_Bool)shouldCollectPairingPerfStackshots;
- (void)connectIDSDuringPairing;
- (NSUUID *)createDeviceFromCompanionOOBPairingRequest:(NSString *)arg1;
- (void)processEvent:(NSString *)arg1;
- (void)pushVersion4CompatibilityMessageIfNeeded;
- (void)activateDevice:(NSUUID *)arg1;
- (_Bool)isInternalInstall;
- (_Bool)hasRecoverySteps;
- (void)setRedisplayRunBridgeDialogTimer;
- (void)clearRedisplayRunBridgeAlertTimer;
- (_Bool)isDeviceUnlocked;
- (void)clearPairingAgentDelegate;
- (void)setPairingAgentDelegate;
- (long long)minPairingCompatibilityVersion;
- (long long)maxPairingCompatibilityVersion;
- (void)updateLastUnpairReason:(unsigned long long)arg1;
- (NSString *)_pathToNanoRegistryStateDirectory;
- (void)startRecovery;
- (NRRecoveryManager *)sharedRecoveryManager;
- (void)sendXPCBTPairRequestMessage:(NSUUID *)arg1;
- (void)requestGizmoTransitionToCompatibilityState:(unsigned short)arg1;
- (void)displayRunBridgeDialog;
- (void)displayUpdateCompanionDialog;
- (void)deleteAccounts;
- (CBPeer *)getPairedPeer:(NSUUID *)arg1;
- (NSUUID *)getBluetoothIDForPairingID:(NSUUID *)arg1;
- (CBPeer *)getPeerForPairingID:(NSUUID *)arg1;
- (void)unpairBluetoothDevicesWithPeers:(NSArray *)arg1 andQueue:(NSObject<OS_dispatch_queue> *)arg2 andCompletion:(void (^)(_Bool))arg3;
- (void)getBluetoothPairedPeersWithQueue:(NSObject<OS_dispatch_queue> *)arg1 andCompletion:(void (^)(_Bool, NSArray *))arg2;
- (void)sendXPCOOBKeyChanged:(NSData *)arg1;
- (NSData *)getOOBKey;
- (void)beginDiscoveryWithDeviceToDiscover:(NSUUID *)arg1;
- (NSString *)getAdvertisedNameFromDevice:(NSUUID *)arg1;
- (void)logStateMachineTimeout:(NSString *)arg1 withReason:(NSString *)arg2;
- (void)restartStateMachineTimeout:(NSString *)arg1;
- (void)clearStateMachineTimeout:(NSString *)arg1;
- (void)createStateMachineTimeout:(NSString *)arg1 withDuration:(double)arg2;
- (void)resumeStateMachineTimeout:(NSString *)arg1;
- (void)suspendStateMachineTimeout:(NSString *)arg1;
- (void)clearStateMachineTimeouts;
- (void)IDSLocalPairingSetupCompletedWithBlock:(void (^)(_Bool))arg1;
- (void)IDSLocalPairingConnectDeviceWithBlock:(void (^)(_Bool))arg1;
- (void)IDSAddPairedDevice:(NSUUID *)arg1 withBlock:(void (^)(_Bool))arg2;
- (void)setOOBPairingEnabled:(_Bool)arg1;
- (_Bool)isBluetoothPaired:(NSUUID *)arg1;
- (void)notifyStateChanged;
- (_Bool)isIDSPaired:(NSUUID *)arg1;
- (void)setIsPaired:(_Bool)arg1 withPairingID:(NSUUID *)arg2;
- (void)deleteLocalPairingStore:(NSUUID *)arg1;
- (_Bool)createLocalPairingStore:(NSUUID *)arg1 andNotifyPairingBeginning:(_Bool)arg2;
- (void)enableDaemons;
- (void)refreshPropertyCache;
- (void)sendXPCDeviceNeedsPasscodeMessage:(NSUUID *)arg1 passcode:(NSNumber *)arg2;
- (void)failBluetoothPairingRequest:(NSUUID *)arg1;
- (void)respondToBluetoothPasscodePairingRequest:(NSUUID *)arg1 key:(NSNumber *)arg2;
- (void)respondToBluetoothOOBPairingRequest:(NSUUID *)arg1 key:(NSData *)arg2;
- (void)cancelCompanionBluetoothPairingRequest:(NSUUID *)arg1;
- (void)sendCompanionBluetoothPairingRequest:(NSUUID *)arg1;
- (void)forceEndDiscovery;
- (void)forceEndAdvertising;
@end

@protocol NSSecureCoding <NSCoding>
+ (_Bool)supportsSecureCoding;
@end

@protocol NRRemoteObjectDelegate <NRRemoteObjectConnectivityObserver, NRRemoteObjectTrafficClassDelegate>
@end

@protocol EPUpdateLastUnpairReason <NSObject>
- (void)updateLastUnpairReason:(unsigned long long)arg1;
@end

@protocol NRPairedSyncAdvisorObserver <NSObject>

@optional
- (void)pairedSyncAdvisorSyncCompleted:(NRPairedSyncAdvisor *)arg1;
- (void)pairedSyncAdvisorNeedsSync:(NRPairedSyncAdvisor *)arg1 isInitialSync:(_Bool)arg2;
@end

@protocol NRRemoteObjectClassDDelegate <NSObject>
- (long long)minPairingCompatibilityVersion;
- (long long)maxPairingCompatibilityVersion;
- (void)remoteObject:(NRRemoteObjectClassD *)arg1 receivedUnpairRequestWithAdvertisedName:(NSString *)arg2 shouldObliterate:(_Bool)arg3 shouldBrick:(_Bool)arg4 shouldPreserveESim:(_Bool)arg5 withPairingFailureCode:(NSNumber *)arg6 withAbortReason:(NSString *)arg7 withRequestIdentifier:(id)arg8 fromIDSBTUUID:(NSUUID *)arg9;

@optional
- (void)remoteObjectReceivedWatchMigrationCompletion:(unsigned long long)arg1;
- (void)receivedPingRequestOfType:(int)arg1;
@end

@protocol NRPrivateProxyDelegate <NSObject>
@end

@protocol EPSetServiceDisconnection <NSObject>
- (void)setServiceDisconnectionWithBool:(_Bool)arg1;
@end

@protocol EPResourceOwnerDelegate <NSObject>

@optional
- (void)resourceAvailabilityDidChange:(id <EPResourceProtocol>)arg1;
@end

@protocol NRActiveDeviceAssertionManagerObserver <NSObject>
- (void)activeDeviceAssertionManagerChangedState;
@end

@protocol NRRemoteObjectClassCDelegate <NSObject>
- (void)remoteObject:(NRRemoteObjectClassC *)arg1 receivedPropertyRequestWithRequestIdentifier:(id)arg2 fromIDSBTUUID:(NSUUID *)arg3;
- (void)remoteObject:(NRRemoteObjectClassC *)arg1 receivedPropertyChanges:(NSDictionary *)arg2 isAllProperties:(_Bool)arg3 fromIDSBTUUID:(NSUUID *)arg4;
@end

@protocol NRSwitchProgressTrackerObserver <NSObject>

@optional
- (void)switchProgressTracker:(NRSwitchProgressTracker *)arg1 didAbortSwitch:(NSUUID *)arg2;
- (void)switchProgressTracker:(NRSwitchProgressTracker *)arg1 didFinishSwitch:(NSUUID *)arg2;
- (void)switchProgressTracker:(NRSwitchProgressTracker *)arg1 didChangeProgressTo:(unsigned long long)arg2 forSwitchID:(NSUUID *)arg3;
- (void)switchProgressTracker:(NRSwitchProgressTracker *)arg1 didStartSwitch:(NSUUID *)arg2;
@end

@protocol NRXPCProxyDelegate <NSObject>
- (void)xpcProxyLostConnection:(NRXPCProxy *)arg1;
@end

@protocol NRRecoveryManagerDelegate <NSObject>

@optional
- (void)recoveryManager:(NRRecoveryManager *)arg1 activeStateDidChange:(_Bool)arg2;
- (void)recoveryManagerDidEndRecovery:(NRRecoveryManager *)arg1;
- (void)recoveryManagerDidBeginRecovery:(NRRecoveryManager *)arg1;
@end

@protocol NRCreateUnpairTriggerFile <NSObject>
- (_Bool)unpairTriggerFileDoesNotExist;
- (void)createUnpairTriggerFile:(_Bool)arg1;
@end

@protocol CBCentralManagerDelegate <NSObject>
- (void)centralManagerDidUpdateState:(CBCentralManager *)arg1;

@optional
- (void)centralManager:(CBCentralManager *)arg1 didDisconnectPeripheral:(CBPeripheral *)arg2 error:(NSError *)arg3;
- (void)centralManager:(CBCentralManager *)arg1 didFailToConnectPeripheral:(CBPeripheral *)arg2 error:(NSError *)arg3;
- (void)centralManager:(CBCentralManager *)arg1 didConnectPeripheral:(CBPeripheral *)arg2;
- (void)centralManager:(CBCentralManager *)arg1 didDiscoverPeripheral:(CBPeripheral *)arg2 advertisementData:(NSDictionary *)arg3 RSSI:(NSNumber *)arg4;
- (void)centralManager:(CBCentralManager *)arg1 willRestoreState:(NSDictionary *)arg2;
@end


