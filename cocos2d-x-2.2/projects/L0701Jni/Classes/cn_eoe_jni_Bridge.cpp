/*
 * cn_eoe_jni_Bridge.cpp
 *
 *  Created on: 2013-10-18
 *      Author: plter
 */


#include <jni.h>
#include "cocos2d.h"
#include "cn_eoe_jni_Bridge.h"
#include "Bridge.h"

USING_NS_CC;

void Java_cn_eoe_jni_Bridge_startListen
  (JNIEnv *env, jclass c){
	Bridge::setClass(c);
	Bridge::setJniEnv(env);
}


void JNICALL Java_cn_eoe_jni_Bridge_addImage
  (JNIEnv *env, jclass, jstring img){
	const char* cStr = env->GetStringUTFChars(img,NULL);
	Bridge::addImg(cStr);
}
