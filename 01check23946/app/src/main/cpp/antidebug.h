//
// Created by 24657 on 2021/3/2.
//
#include <jni.h>
#include <android/log.h>
#include <cstdlib>
#include <cstdio>

#define LOG_TAG "TAG"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG ,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG ,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG ,__VA_ARGS__)
#ifndef DEMO01_ANTIDEBUG_H
#define DEMO01_ANTIDEBUG_H

#endif //DEMO01_ANTIDEBUG_H
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_antidebug_demo01_uselib
 * Method:    antoida
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_antidebug_demo01_uselib_antoida
(JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif

