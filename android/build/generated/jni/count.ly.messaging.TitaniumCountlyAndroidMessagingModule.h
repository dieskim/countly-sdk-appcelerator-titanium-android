/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2016 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This is generated, do not edit by hand. **/

#include <jni.h>

#include "Proxy.h"

namespace count {
namespace ly {
namespace messaging {

class TitaniumCountlyAndroidMessagingModule : public titanium::Proxy
{
public:
	explicit TitaniumCountlyAndroidMessagingModule();

	static void bindProxy(v8::Local<v8::Object>, v8::Local<v8::Context>);
	static v8::Local<v8::FunctionTemplate> getProxyTemplate(v8::Isolate*);
	static void dispose(v8::Isolate*);

	static jclass javaClass;

private:
	static v8::Persistent<v8::FunctionTemplate> proxyTemplate;

	// Methods -----------------------------------------------------------
	static void enableDebug(const v8::FunctionCallbackInfo<v8::Value>&);
	static void startCrashReporting(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getOUDID(const v8::FunctionCallbackInfo<v8::Value>&);
	static void userData(const v8::FunctionCallbackInfo<v8::Value>&);
	static void startMessagingTest(const v8::FunctionCallbackInfo<v8::Value>&);
	static void startCrashReportingWithSegments(const v8::FunctionCallbackInfo<v8::Value>&);
	static void recordUncaughtException(const v8::FunctionCallbackInfo<v8::Value>&);
	static void start(const v8::FunctionCallbackInfo<v8::Value>&);
	static void recordPushAction(const v8::FunctionCallbackInfo<v8::Value>&);
	static void sendNotification(const v8::FunctionCallbackInfo<v8::Value>&);
	static void addCrashLog(const v8::FunctionCallbackInfo<v8::Value>&);
	static void startMessaging(const v8::FunctionCallbackInfo<v8::Value>&);
	static void crashTest(const v8::FunctionCallbackInfo<v8::Value>&);
	static void stopCount(const v8::FunctionCallbackInfo<v8::Value>&);
	static void recordHandledException(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setLocation(const v8::FunctionCallbackInfo<v8::Value>&);
	static void event(const v8::FunctionCallbackInfo<v8::Value>&);
	static void sendQueuedNotification(const v8::FunctionCallbackInfo<v8::Value>&);

	// Dynamic property accessors ----------------------------------------

};

} // messaging
} // ly
} // count
