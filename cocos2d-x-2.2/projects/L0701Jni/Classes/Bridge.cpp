/*
 * Bridge.cpp
 *
 *  Created on: 2013-10-18
 *      Author: plter
 */

#include "Bridge.h"
#include "HelloWorldScene.h"

JNIEnv* Bridge::jniEnv;
jclass Bridge::bridgeClass;

Bridge::Bridge() {
	// TODO Auto-generated constructor stub

}

void Bridge::setJniEnv(JNIEnv* env){
	Bridge::jniEnv = env;
}

JNIEnv* Bridge::getJniEnv(){
	return Bridge::jniEnv;
}

void Bridge::setClass(jclass c){
	Bridge::bridgeClass = c;
}

jclass Bridge::getClass(){
	return Bridge::bridgeClass;
}

void Bridge::onCCInit(){
	Bridge::getJniEnv()->CallStaticVoidMethod(Bridge::getClass(),
			Bridge::getJniEnv()->GetStaticMethodID(Bridge::getClass(),"onCCInit","()V"));
}

void Bridge::addImg(const char* img){
	HelloWorld::sharedHelloWorld()->addImg(img);
}

Bridge::~Bridge() {
	// TODO Auto-generated destructor stub
}

