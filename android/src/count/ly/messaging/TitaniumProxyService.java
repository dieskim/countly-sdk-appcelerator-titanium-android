package count.ly.messaging;

import android.app.ActivityManager;
import android.app.IntentService;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.NotificationCompat;
import android.util.Log;

import java.util.HashMap;
import java.util.List;
import java.util.Set;

import org.appcelerator.titanium.util.TiConvert;
import org.appcelerator.titanium.TiApplication;
import org.appcelerator.titanium.TiProperties;

import count.ly.messaging.Countly;

/**
* Created by dieskim
*/
public class TitaniumProxyService extends IntentService {
    public static final String TAG = "CountlyTitaniumProxyService";  
    
    public TitaniumProxyService() {
        super(TAG);
        Log.d(TAG, "Inside TitaniumProxyService");
    }

    @Override
    protected void onHandleIntent (Intent intent) {
    	Log.d(TAG, "Inside onHandleIntent");
    	
    	// get extras bundle from intent
    	Bundle extras = intent.getExtras();
    	
        if (!extras.isEmpty()) {
        	// get msg from extras bundle
        	Message intentMessage = extras.getParcelable(CountlyMessaging.EXTRA_MESSAGE);
        	
            if (intentMessage.isValid()) {
            	Log.d(TAG, "Got a message from intent: " + intentMessage);
            	
            	
            // Create HashMap of Notification info and add data
			HashMap pushMessage = new HashMap();
			pushMessage.put("id", intentMessage.getId());
			pushMessage.put("message", intentMessage.getNotificationMessage());
			
			if (intentMessage.hasLink()){
				pushMessage.put("type", "hasLink");
				pushMessage.put("link", intentMessage.getLink());
			}else if (intentMessage.hasReview()){
				pushMessage.put("type", "hasReview");
			}else if (intentMessage.hasMessage()) {
				pushMessage.put("type", "hasMessage");
			}
			
			if (intentMessage.hasSoundUri()){
				pushMessage.put("sound", intentMessage.getSoundUri());
			}
			
			pushMessage.put("data", bundleToHashMap(intentMessage.getData()));						
			
			// log pushMessage HashMap
			Log.d(TAG, "pushMessage HashMap: " + pushMessage);
			
			// Set pushMessage into TiProperties
			TiProperties appProperties = TiApplication.getInstance().getAppProperties();
			appProperties.setString("pushMessage", TiConvert.toJSONString(pushMessage));	 
			
			// Create the Intent to launch the App
			Intent launch = getApplicationContext().getPackageManager().getLaunchIntentForPackage(getApplicationContext().getPackageName());
			intent.addCategory("android.intent.category.LAUNCHER");
			launch.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK|Intent.FLAG_ACTIVITY_SINGLE_TOP);
			
			// Run Intent to Launch App
			getApplicationContext().startActivity(launch);	


			//Make sure we have countly initialized before recording the message event.
			if (!Countly.sharedInstance().isInitialized()) {
                    if (!CountlyMessaging.initCountly(getApplicationContext())) {
                        Log.e(TAG, "Cannot init Countly in background");
                    } else { 	
                    	Log.e(TAG, "Countly initialized");
                    }
                }
				
				// Set TitaniumCountlyAndroidMessagingModule.message
	            TitaniumCountlyAndroidMessagingModule.message = intentMessage;
	            
				// Process callback to open Notification in Application 
	            // if application was just in background this will process the notification
	            // else application will start and check TiProperties for pushMessage on startup
				TitaniumCountlyAndroidMessagingModule.processPushCallBack();

				// mark message open
            	CountlyMessaging.recordMessageOpen(intentMessage.getId());
				
            }else{
            	Log.d(TAG, "No Valid Message Found");
            }
        }
    }
    
    private static String printBundle(Bundle bundle) {
		StringBuilder sb = new StringBuilder();
		for (String key : bundle.keySet()) {			
			sb.append("\nkey:" + key + ", value:" + bundle.getString(key));
		}
		return sb.toString();
	}
    
    private static HashMap<String, String> bundleToHashMap(Bundle bundle){
		HashMap<String, String> hash = new HashMap<String, String>();
		Set<String> keys = bundle.keySet();
		for (String key : keys) {		    	    	
			String value = bundle.get(key).toString();	
			if (value == null || value.isEmpty()){
				value = "null";
			}
			hash.put(key, value);
		}
		return hash;
	}
}
