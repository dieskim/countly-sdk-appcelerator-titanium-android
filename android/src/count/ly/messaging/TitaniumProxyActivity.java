package count.ly.messaging;

import org.appcelerator.titanium.TiApplication;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

/**
* Created by artem on 14/10/14.
*/
public class TitaniumProxyActivity extends Activity {
	
	public static final String TAG = "CountlyMessagingModule";
	
    @Override
    protected void onCreate (Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    protected void onNewIntent (Intent intent) {
        super.onNewIntent(intent);
    }

    @Override
    protected void onStart () {
        super.onStart();
        
        Log.d(TAG, "TitaniumProxyActivity");
        
        Bundle extras = getIntent().getExtras();
        final Message msg = extras.getParcelable(CountlyMessaging.EXTRA_MESSAGE);
        
        if (msg != null) {
           
        	Log.d(TAG, "TitaniumProxyActivity Message: " + msg);
        	
        	// mark message open
            CountlyMessaging.recordMessageOpen(msg.getId());
            
            // Set Module wide VARS for MESSAGE
            TitaniumCountlyAndroidMessagingModule.message = msg;
    		
         	// Process callback to open Notification in App
            TitaniumCountlyAndroidMessagingModule.processPushCallBack();
            
        }
    }

    @Override
    protected void onStop () {
        super.onStop();
    }
    

}
