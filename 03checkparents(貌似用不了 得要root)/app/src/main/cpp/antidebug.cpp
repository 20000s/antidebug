//
// Created by 24657 on 2021/3/3.
//

#include "antidebug.h"
JNIEXPORT void JNICALL Java_com_antidebug_demo03_usendk_checkparents
        (JNIEnv *env, jclass clazz){
    char strPpidCmdline[0x1000] = {0};
    snprintf(strPpidCmdline,sizeof(strPpidCmdline),"/proc/%d/cmdline",getppid());
    int file= open(strPpidCmdline,O_RDWR);
    if(file<0){
        LOGD("cannot open file");
        return;
    }
    memset(strPpidCmdline,0,sizeof(strPpidCmdline));
    ssize_t ret = read(file,strPpidCmdline,sizeof(strPpidCmdline));
    if(ret ==-1){
        LOGD("cannot read file");
        return;
    }
     char *ret1 = strstr(strPpidCmdline,"zygote");
    if(ret1 == NULL){
        LOGD("debug");
    }
    LOGD("not denug");



}

JNIEXPORT void JNICALL
Java_com_antidebug_demo03_usendk_getname(JNIEnv *env, jclass clazz, jobject context) {


   jclass clz = env->GetObjectClass(context);
   jmethodID m_id =env->GetMethodID(clz,"get","()Ljava/lang/String;");
   jstring str = (jstring)env->CallObjectMethod(context,m_id);

   LOGD("%s",env->GetStringUTFChars(str,NULL));

}