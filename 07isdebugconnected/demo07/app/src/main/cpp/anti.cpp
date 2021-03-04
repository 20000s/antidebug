//
// Created by 24657 on 2021/3/3.
//

#include "anti.h"
typedef unsigned char wbool;
typedef wbool (*ppp)();
JNIEXPORT void JNICALL Java_com_antidebug_demo07_usendk_isdebugconnected
        (JNIEnv *env, jclass clazz){

    void * handle;

     handle = dlopen("/system/lib/libdvm.so",RTLD_LAZY);
     if(handle==NULL){
         LOGD("cannot open libdvm.so");
     }
  ppp a =  (ppp)dlsym(handle,"_Z25dvmDbgIsDebuggerConnectedv");
     if(a == NULL){
         LOGD("cannot dlsym");
     }else{
         wbool ret = a();
         if(ret == 1){
             LOGD("is deing debug");
         }
     }
    return;

}