//
// Created by 24657 on 2021/3/2.
//

#include "antidebug.h"

JNIEXPORT void JNICALL Java_com_antidebug_demo01_uselib_antoida
        (JNIEnv *env, jclass clazz){
    FILE *pfile = NULL;
    char * str = "cat /proc/net/tcp |grep :5D8A";
    pfile = popen(str,"r");
    if(pfile == NULL){
        LOGD("cannot open tcp\n");
        return;
    }
    LOGD("can open tcp\n");
    char buff[1000] = {0};
    while(fgets(buff,sizeof(buff),pfile)){
        LOGD("ida content:\n");
        LOGD("%s",buff);
    }
    pclose(pfile);

}
