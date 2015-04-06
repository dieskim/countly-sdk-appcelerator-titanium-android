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
        	final Message msg = extras.getParcelable(CountlyMessaging.EXTRA_MESSAGE);
        	
            if (msg.isValid()) {
            	Log.d(TAG, "Got a message from intent: " + msg);
            	
            	// mark message open
            	CountlyMessaging.recordMessageOpen(msg.getId());
            	
            	// Create HashMap of Notification info and add data
				HashMap pushMessage = new HashMap();
				pushMessage.put("id", msg.getId());
				pushMessage.put("message", msg.getNotificationMessage());
				
				if (msg.hasLink()){
					pushMessage.put("type", "hasLink");
					pushMessage.put("link", msg.getLink());
				}else if (msg.hasReview()){
					pushMessage.put("type", "hasReview");
				}else if (msg.hasMessage()) {
					pushMessage.put("type", "hasMessage");
				}
				
				if (msg.hasSoundUri()){
					pushMessage.put("sound", msg.getSoundUri());
				}
				
				pushMessage.put("data", bundleToHashMap(msg.getData()));						
				
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
				
				// Set TitaniumCountlyAndroidMessagingModule.message
	            TitaniumCountlyAndroidMessagingModule.message = msg;
	            
				// Process callback to open Notification in Application 
	            // if application was just in background this will process the notification
	            // else application will start and check TiProperties for pushMessage on startup
				TitaniumCountlyAndroidMessagingModule.processPushCallBack();
				
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
		    	hash.put(key, bundle.get(key).toString());
		}
		return hash;
	}
}
