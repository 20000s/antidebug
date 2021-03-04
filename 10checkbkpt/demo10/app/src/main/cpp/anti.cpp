//
// Created by 24657 on 2021/3/4.
//

#include "anti.h"
JNIEXPORT void JNICALL Java_com_antidebug_demo10_usendk_antidebug
        (JNIEnv * env, jclass clazz){



}
bool checkbkpt(u8 * addr,u32 size){
    bool uret = false;
    u8 arm_bkpt[4]={0};
    arm_bkpt[0] = 0xf0;
    arm_bkpt[1] = 0x01;
    arm_bkpt[2] = 0xf0;
    arm_bkpt[3] = 0xe7;
    u8 thumbbkpt[2] = {0};
    thumbbkpt[0] = 0x10;
    thumbbkpt[1] = 0xde;
    int mode = (u32)addr%2;
    if(mode==1){
        LOGD("this is thumb mode");
        u8*start = (u8*)((u32)addr-1);
        u8*end = (u8*)((u32)addr-1+size);
        while (1){
            if(start>= end){
                LOGD("this program is not debugged");
                break;
            }
            if(0== memcmp(start,thumbbkpt,2)){
                LOGD("this program is being debugged");
                uret = true;
                break;
            }
            start = start + 2;

        }
    }else{
        LOGD("this is arm mode");
        u8*start = (u8*)((u32) addr);
        u8 * end = (u8*)((u32) addr + size);
        while (1){
            if(start >= end){
                LOGD("this is arm mode");
                break;
            }
            if(0 == memcmp(start,arm_bkpt,4)){
                LOGD("this program is  debing debugged");
                uret = true;
                break;
            }
            start +=4;
        }
    }

    return uret;

}