LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := CallC
LOCAL_SRC_FILES := CallC.cpp Math.cpp

include $(BUILD_SHARED_LIBRARY)
