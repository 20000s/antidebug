//
// Created by 24657 on 2021/3/4.
//
#include <jni.h>
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
#define true 1
#define false 0
#define bool int
typedef uint8_t u8;
typedef uint32_t u32;
#ifndef DEMO10_ANTI_H
#define DEMO10_ANTI_H

#endif //DEMO10_ANTI_H
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_antidebug_demo10_usendk
 * Method:    antidebug
 * Signature: ()V
 */

JNIEXPORT void JNICALL Java_com_antidebug_demo10_usendk_antidebug
(JNIEnv *, jclass);
bool checkbkpt(u8 * addr,u32 size);

#ifdef __cplusplus
}
#endif

