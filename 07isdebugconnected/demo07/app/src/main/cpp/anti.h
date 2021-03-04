//
// Created by 24657 on 2021/3/3.
//
#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define LOG_TAG "TAG"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG ,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG ,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG ,__VA_ARGS__)

#ifndef DEMO07_ANTI_H
#define DEMO07_ANTI_H

#endif //DEMO07_ANTI_H
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_antidebug_demo07_usendk
 * Method:    isdebugconnected
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_antidebug_demo07_usendk_isdebugconnected
        (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
