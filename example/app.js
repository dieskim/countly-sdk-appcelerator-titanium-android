// This is a test harness for your module
// You should do something interesting in this harness
// to test out the module and to provide instructions
// to users on how to use it by example.


// open a single window
var win = Ti.UI.createWindow({
	backgroundColor:'white'
});
var label = Ti.UI.createLabel();
win.add(label);
win.open();

// Start Countly
var Countly = require('count.ly.messaging');

// enableDebug if needed
Countly.enableDebug();

// START Countly with Messaging - DEVELOPMENT TEST
Countly.startMessagingTest('COUNLY_APP_KEY','http://yourserver.com','GCM_PROJECT_ID');
	
// START Countly with Messaging - PRODUCTION
//Countly.startMessaging('COUNLY_APP_KEY','http://yourserver.com','GCM_PROJECT_ID');
		
// ADD EVENTLISTENTER AND FUNCTION TO MODULE
Countly.addEventListener('receivePush',function(pushMessageData){
         
	// Ti.API.info Raw pushMessage
	Ti.API.info("Received Push");  
    Ti.API.info(JSON.stringify(pushMessageData));  
	 
	var pushID = pushMessageData.id;
	var pushAlertMessage = pushMessageData.message;
	var pushType = pushMessageData.type || 'unknownType';
	var pushLink = pushMessageData.link || '';
	var pushSound = pushMessageData.sound || '';
	var pushData = pushMessageData.data;						// all message data if needed
	
	Ti.API.info("pushID: " + pushID + " pushAlertMessage: " + pushAlertMessage + "pushType: " + pushType + " pushData: " + pushData + " pushSound: " + pushSound);
	
	if (pushType == "hasLink"){
		
		 ///////////////////////////////////////////////////////////
        //              SHOW AN LINK ALERT HERE                 //
        // 1. Use info  - pushType
        //              - pushLink
        //              - pushAlertMessage
        // 2. Once user Takes action log action with recordPushAction using pushID

        // Count.ly record Push Action  
        // Countly.recordPushAction(pushID);    
		
	}else if (pushType == "hasReview"){
		
		// SHOW AN REVIEW ALERT HERE 
		
	}else if (pushType == "hasMessage"){
		
		// SHOW NORMAL ALERT HERE
		
	};
	
});

// Countly Set user location
// - Takes two strings: latitudeString and longitudeString of 2 digit lengths

var latitudeString = 12;
var longitudeString = 10;
Countly.setLocation(latitudeString,longitudeString);