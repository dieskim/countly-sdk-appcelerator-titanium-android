# Count.ly Titanium Android Messaging Module

Countly is an innovative, real-time, open source mobile analytics application. It collects data from mobile phones, and visualizes this information to analyze mobile application usage and end-user behavior. There are two parts of Countly: the server that collects and analyzes data, and mobile SDK that sends this data (for iOS & Android).

Countly:

- [Countly (Countly)](https://count.ly)

Countly Server;

- [Countly Server (countly-server)](https://github.com/Countly/countly-server)

Titanium Countly Messaging Modules

- [Countly Titanium Android Messaging Module](https://github.com/dieskim/Titanium-Count.ly-Android-Messaging)
- [Countly Titanium iOS Messaging Module](https://github.com/dieskim/Titanium-Count.ly-Messaging)

Other Countly SDK repositories;

- [Countly Android SDK (countly-sdk-android)](https://github.com/Countly/countly-sdk-android)
- [Countly iOS SDK (countly-sdk-ios)](https://github.com/Countly/countly-sdk-ios)

Countly SDK Guides;
- [Countly Android Messaging Guide](http://resources.count.ly/v1.0/docs/countly-push-for-android)
- [Countly iOS Messaging Guide](http://resources.count.ly/v1.0/docs/countly-push-for-ios)

## This Titanium Android module is written to take use of all the Count.ly functions - including events,userData and Messaging.
## It is written with functions as close to the iOS module as possible to create uniformed functions.
## Please note that this Module is under development.
## Please log issues via github issues
## Any pull requests and suggestio welcome!
## Author: Dieskim
## Development Sponsor: http://Hamsane.com - Friend who loves your way of working - Thanks!

## Installation

1. Go to: https://github.com/dieskim/Titanium-Count.ly-Android-Messaging
2. Download: count.ly-messaging-android-x.x.x.zip
3. Move Zip to root of your Application 

### Register your module with your application by editing `tiapp.xml` and adding your module.

```
<modules>
<module platform="android">count.ly.messaging</module>
</modules>
```

## Usage

**Require the Count.ly Module**

```
var Countly = require('count.ly.messaging');
```

**Start Count.ly without Messaging**
```
Countly.start('API_KEY','http://yourserver.com OR https://cloud.count.ly');

```

### SETUP Count.ly WITH Messaging - Push

**Require the Count.ly Module**
```
var Countly = require('count.ly.messaging');
```

**START Countly with Messaging - DEVELOPMENT TEST**
```
// enableDebug if needed
Countly.enableDebug();

// START Countly with Messaging - DEVELOPMENT TEST
Countly.startMessagingTest('COUNLY_APP_KEY','http://yourserver.com','GCM_PROJECT_ID');
```

**START Countly with Messaging - PRODUCTION**
```
// START Countly with Messaging - PRODUCTION
//Countly.startMessaging('COUNLY_APP_KEY','http://yourserver.com','GCM_PROJECT_ID');
```

**Receive and Process push on Titanium side**
```
// ADD EVENTLISTENTER AND FUNCTION TO MODULE
Countly.addEventListener('receivePush',function(pushMessageData){

// *** IN ANDROID THERE IS NO NEED TO RUN recordPushOpen as it happens Automaticall on the Native Module side **//

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
```
**Set User Location - Enterprise Only**

```
// Countly Set user location
// - Takes two strings: latitudeString and longitudeString of 2 digit lengths
var latitudeString = 12;
var longitudeString = 10;
Countly.setLocation(latitudeString,longitudeString);
```

### Record Events

**Set any of the following Fields in an Object**

```
var segmentation = {device:"iPhone 4S", country:"USA"};
var eventData = {name: "keySegmentationCountSum", segmentation:segmentation, count: 1, sum: 0.99};
```

- name (required) : Name of the event to track  
- _(example - Track clicks on the help button "clickedHelp" )_
- count (required) : Number to increment the event in the db
- _(example - User purchases item increment by 1 )_
- sum : If the event is tied to an overall numerical data, such as a purchase, we can use sum to keep track of that
- _(example - 0.99)_
- segmentation : Categorization of the event
- _(example - User is from USA and uses an iPhone 4S so the segmentation will be {device:"iPhone 4S", country:"USA"} )_

**Track Events Examples**

```
var segmentation = {device:"iPhone 4S", country:"USA"};

Ti.API.log("Send keyCount Event");
var eventData = {name: "keyCount", count: 1};
Countly.event(eventData);

Ti.API.log("Send keyCountSum Event");
var eventData = {name: "keyCountSum", count: 1, sum: 0.99};
Countly.event(eventData);

Ti.API.log("Send keySegmentationCount Event");
var eventData = {name: "keySegmentationCount", segmentation:segmentation, count: 1};
Countly.event(eventData);

Ti.API.log("Send keySegmentationCountSum Event");
var eventData = {name: "keySegmentationCountSum", segmentation:segmentation, count: 1, sum: 0.99};
Countly.event(eventData);
```

### Set UserData

**Set any of the following Fields in an Object**

**Set userData{} as information about user
**Possible keys are:

- name - (String) providing user's full name
- username - (String) providing user's nickname
- email - (String) providing user's email address
- organization - (String) providing user's organization's name where user works
- phone - (String) providing user's phone number
- picture - (String) providing WWW URL to user's avatar or profile picture
- picturePath - (String) providing local path to user's avatar or profile picture
- gender - (String) providing user's gender as M for male and F for female
- byear - (int) providing user's year of birth as integer

```
var userData = {	name: "testName",
username: "testUsername",
email: "testemail@gmail.com",
organization: "testOrg",
phone: "testPhone",
picture: "https://count.ly/wp-content/uploads/2014/10/logo.png",
picturePath: "/images/appicon.png",
gender: "M",
byear: "1980",
};
```

**Set customUserData{} as information about user with custom properties
**In customUserData you can provide any string key values to be stored with user

```
var customUserData = {	key1: "value1",
key2:"value2",
};
```

**Set Userdata as set in userData and customData
**Can contain both userData and customData - or just userdata

```
Ti.API.log("Set UserData");
var args = {	userData:userData,
customUserData:customUserData,
};


Countly.userData(args);
```

## Author

Author: Dieskim

## License

MIT as in License.txt