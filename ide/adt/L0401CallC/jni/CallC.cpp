#include <jni.h>
#include "Math.h"
#include "cn_eoe_callc_Num.h"

jint JNICALL Java_cn_eoe_callc_Num_getNum
  (JNIEnv *env, jobject _this){
	return 9;
}

jint JNICALL Java_cn_eoe_callc_Num_max
  (JNIEnv *env, jobject _this, jint a, jint b){
	return Math::max(a,b);
}
