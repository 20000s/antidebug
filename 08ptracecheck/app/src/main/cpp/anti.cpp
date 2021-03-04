//
// Created by 24657 on 2021/3/3.
//

#include "anti.h"
JNIEXPORT void JNICALL Java_com_antidebug_demo08_usendk_ptracecheck
        (JNIEnv *env, jclass clazz){

    int ret = ptrace(PTRACE_TRACEME,0,0,0);
    if(ret == -1){
        LOGD("this program is being debugged");
    }else{
        LOGD(" ret :%d",ret);

    }
    return;

}
