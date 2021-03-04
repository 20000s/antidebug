//
// Created by 24657 on 2021/3/2.
//

#include "antidebug.h"
JNIEXPORT void JNICALL Java_com_antidebug_demo02_usejni_antirpocess
        (JNIEnv *env, jclass clazz){
    FILE *pfile = NULL;
    char buf[1000] = {0};
    pfile = popen("ps","r");
    if(pfile != NULL){
        LOGD("cannot open ps");
    }
    while(fgets(buf,sizeof(buf),pfile)){
        LOGD("start traveling");
        char * stra=NULL;
        char * strb=NULL;
        char * strc=NULL;
        char * strd=NULL;
        stra = strstr(buf,"gdb");
        strb = strstr(buf,"gdbserver");
        strc = strstr(buf,"android_server");
        strd = strstr(buf,"android_server64");
        if(stra || strb || strc || strd){
            LOGD("find process");
        }
    }
    LOGD("cannot find");
    pclose(pfile);
}
