//
// Created by 24657 on 2021/3/4.
//
#include <jni.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <android/log.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>
#define LOG_TAG "TAG"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG ,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG ,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG ,__VA_ARGS__)

#ifndef DEMO12_ANTI_H
#define DEMO12_ANTI_H

#endif //DEMO12_ANTI_H
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_antidebug_demo12_usendk
 * Method:    antidebug
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_antidebug_demo12_usendk_antidebug
(JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
unsigned char dynamic_ccode[] = {
        0x1f,0xb4,    //push {r0-r4}
        0x01,0xde,    //breakpoint
        0x1f,0xbc,    //pop {r0-r4}
        0xf7,0x46};    // mov pc,lr
char * g_addr = 0;
