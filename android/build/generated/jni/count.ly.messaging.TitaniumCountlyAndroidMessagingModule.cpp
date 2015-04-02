/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2013 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "count.ly.messaging.TitaniumCountlyAndroidMessagingModule.h"

#include "AndroidUtil.h"
#include "EventEmitter.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "Proxy.h"
#include "ProxyFactory.h"
#include "TypeConverter.h"
#include "V8Util.h"



#include "count.ly.messaging.ExampleProxy.h"

#include "org.appcelerator.kroll.KrollModule.h"

#define TAG "TitaniumCountlyAndroidMessagingModule"

using namespace v8;

		namespace count {
		namespace ly {
		namespace messaging {


Persistent<FunctionTemplate> TitaniumCountlyAndroidMessagingModule::proxyTemplate = Persistent<FunctionTemplate>();
jclass TitaniumCountlyAndroidMessagingModule::javaClass = NULL;

TitaniumCountlyAndroidMessagingModule::TitaniumCountlyAndroidMessagingModule(jobject javaObject) : titanium::Proxy(javaObject)
{
}

void TitaniumCountlyAndroidMessagingModule::bindProxy(Handle<Object> exports)
{
	if (proxyTemplate.IsEmpty()) {
		getProxyTemplate();
	}

	// use symbol over string for efficiency
	Handle<String> nameSymbol = String::NewSymbol("TitaniumCountlyAndroidMessaging");

	Local<Function> proxyConstructor = proxyTemplate->GetFunction();
	Local<Object> moduleInstance = proxyConstructor->NewInstance();
	exports->Set(nameSymbol, moduleInstance);
}

void TitaniumCountlyAndroidMessagingModule::dispose()
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Dispose();
		proxyTemplate = Persistent<FunctionTemplate>();
	}

	titanium::KrollModule::dispose();
}

Handle<FunctionTemplate> TitaniumCountlyAndroidMessagingModule::getProxyTemplate()
{
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate;
	}

	LOGD(TAG, "GetProxyTemplate");

	javaClass = titanium::JNIUtil::findClass("count/ly/messaging/TitaniumCountlyAndroidMessagingModule");
	HandleScope scope;

	// use symbol over string for efficiency
	Handle<String> nameSymbol = String::NewSymbol("TitaniumCountlyAndroidMessaging");

	Handle<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(
		titanium::KrollModule::getProxyTemplate()
, javaClass, nameSymbol);

	proxyTemplate = Persistent<FunctionTemplate>::New(t);
	proxyTemplate->Set(titanium::Proxy::inheritSymbol,
		FunctionTemplate::New(titanium::Proxy::inherit<TitaniumCountlyAndroidMessagingModule>)->GetFunction());

	titanium::ProxyFactory::registerProxyPair(javaClass, *proxyTemplate);

	// Method bindings --------------------------------------------------------
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "example", TitaniumCountlyAndroidMessagingModule::example);

	Local<ObjectTemplate> prototypeTemplate = proxyTemplate->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = proxyTemplate->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------

	// Dynamic properties -----------------------------------------------------
	instanceTemplate->SetAccessor(String::NewSymbol("exampleProp"),
			TitaniumCountlyAndroidMessagingModule::getter_exampleProp
			, TitaniumCountlyAndroidMessagingModule::setter_exampleProp
, Handle<Value>(), DEFAULT);

	// Accessors --------------------------------------------------------------

	return proxyTemplate;
}

// Methods --------------------------------------------------------------------
Handle<Value> TitaniumCountlyAndroidMessagingModule::example(const Arguments& args)
{
	LOGD(TAG, "example()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(TitaniumCountlyAndroidMessagingModule::javaClass, "example", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'example' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		Handle<Value> jsException = titanium::JSException::fromJavaException();
		env->ExceptionClear();
		return jsException;
	}

	if (jResult == NULL) {
		return Null();
	}

	Handle<Value> v8Result = titanium::TypeConverter::javaStringToJsString(env, jResult);

	env->DeleteLocalRef(jResult);


	return v8Result;

}

// Dynamic property accessors -------------------------------------------------

Handle<Value> TitaniumCountlyAndroidMessagingModule::getter_exampleProp(Local<String> property, const AccessorInfo& info)
{
	LOGD(TAG, "get exampleProp");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(TitaniumCountlyAndroidMessagingModule::javaClass, "getExampleProp", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getExampleProp' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(info.Holder());

	if (!proxy) {
		return Undefined();
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		Handle<Value> jsException = titanium::JSException::fromJavaException();
		env->ExceptionClear();
		return jsException;
	}

	if (jResult == NULL) {
		return Null();
	}

	Handle<Value> v8Result = titanium::TypeConverter::javaStringToJsString(env, jResult);

	env->DeleteLocalRef(jResult);


	return v8Result;

}

void TitaniumCountlyAndroidMessagingModule::setter_exampleProp(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
	LOGD(TAG, "set exampleProp");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, exampleProp wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(TitaniumCountlyAndroidMessagingModule::javaClass, "setExampleProp", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setExampleProp' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(info.Holder());
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	
	
	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




}



		} // messaging
		} // ly
		} // count
