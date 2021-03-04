//
// Created by 24657 on 2021/3/3.
//

#include "anti.h"

JNIEXPORT void JNICALL Java_com_antidebug_demo5_ndkuse_checktaskcounts
        (JNIEnv * env, jclass clazz){
    char buf[0x100] = {0};
    char * str =  "/proc/%d/task";
    snprintf(buf,sizeof(buf),str,getpid());
    DIR *pdir = opendir(buf);
    if(!pdir){
        LOGD("cannor open dir");
        return;
    }
    struct dirent * pde = NULL;
    int count =0;
    while (pde = readdir(pdir)){
        LOGD(" dir name :%s",pde->d_name);
        if(pde->d_name[0]>='0' && pde->d_name[0]<='9'){
            LOGD("process name %s",pde->d_name);
            count++;
        }

    }
    LOGD("Count : %d",count);
    return;

}
