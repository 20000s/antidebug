//
// Created by 24657 on 2021/3/4.
//

#include "anti.h"

JNIEXPORT void JNICALL Java_com_antidebug_demo12_usendk_antidebug
        (JNIEnv *env, jclass clazz){



}
void my_sigtrap(int sig){
    char change_bkp[] = {0x00,0x46};
    memcpy(g_addr+2,change_bkp,2);
    __clear_cache((void*)g_addr,(void *)(g_addr+8) );
    LOGD("change bpk to nop\n");


}
void anti4(){
    int ret,size;
    char * addr,*tmpaddr;
    signal(SIGTRAP,my_sigtrap);
    addr = (char *)malloc(PAGE_SIZE*2);
    memset(addr,0,PAGE_SIZE*2);
    g_addr = (char *)(((int)addr + PAGE_SIZE-1) & ~(PAGE_SIZE-1));
    LOGD("addr : %p. g_addr : %p \n",addr,g_addr);
    ret = mprotect(g_addr,PAGE_SIZE,PROT_READ|PROT_WRITE|PROT_EXEC);
    if(ret != 0){
        LOGD("mprotect error\n");
        return;
    }
    size = 8;
    memcpy(g_addr,dynamic_ccode,size);
    __clear_cache((void *)g_addr,(void *)(g_addr+size));
    __asm__(
            "push {r0-r4,lr}\n\t"
            "mov r0,pc\n\t"
            "add r0,r0,#4\n\t"
            "mov lr,r0\n\t"
            "mov pc,%0\n\t"
            "pop {r0-r5}\n\t"
            "mov lr,r5\n\t"
            :
            :"r"(g_addr)
            :);
    LOGD("hi, im here\n");
    free(addr);

}
