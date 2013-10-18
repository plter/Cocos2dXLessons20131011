/*
 * Bridge.h
 *
 *  Created on: 2013-10-18
 *      Author: plter
 */

#ifndef BRIDGE_H_
#define BRIDGE_H_

#include <jni.h>

class Bridge {
public:
	Bridge();
	static void setJniEnv(JNIEnv* env);
	static JNIEnv* getJniEnv();
	static void setClass(jclass c);
	static jclass getClass();
	static void addImg(const char * img);
	static void onCCInit();
	virtual ~Bridge();

private:
	static JNIEnv* jniEnv;
	static jclass bridgeClass;
};

#endif /* BRIDGE_H_ */
