LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := camera.cpp
LOCAL_MULTILIB := 32
LOCAL_MODULE := libcamera_shim
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := ims_shimmy.cpp
LOCAL_MULTILIB := 32
LOCAL_MODULE := libims_shim
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

