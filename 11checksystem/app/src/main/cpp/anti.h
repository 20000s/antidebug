//
// Created by 24657 on 2021/3/4.
//
#include <jni.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/ptrace.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <android/log.h>
#define LOG_TAG "TAG"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG ,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG ,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG ,__VA_ARGS__)
using namespace std;

#ifndef DEMO11_ANTI_H
#define DEMO11_ANTI_H

#endif //DEMO11_ANTI_H
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_antidebug_demo11_usendk
 * Method:    checksystem
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_antidebug_demo11_usendk_checksystem
(JNIEnv *, jclass);


#ifdef __cplusplus
}
#endif

bool checksystem();