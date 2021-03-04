//
// Created by 24657 on 2021/3/4.
//

#include "anti.h"
bool checksystem(){
    int pipefd[2];
    if(-1 == pipe(pipefd)){
        LOGD("pipe() error \n");
        return false;
    }
    pid_t pid = fork();
    LOGD("child process is %d",pid);
    LOGD("parent procss is %d",getpid());
    if(pid == -1){
        LOGD("fork error");
        return false;
    }
    int childtracepid = 0;
    if(pid == 0){
        LOGD("now is child pid");
          int iret = ptrace(PTRACE_TRACEME,0,0,0,0);
          if(iret ==-1){
              LOGD("ptrace failed");
              exit(0);
          }
          LOGD("ptrace success");
          char pathbuff[0x100] = {0};
          char readbuff[100] = {0};
          sprintf(pathbuff,"/proc/%d/status",getpid());
          int fd = openat(NULL,pathbuff,O_RDONLY);
          if(-1 == fd){
              LOGD("openat failed");
              return false;
          }
          read(fd,readbuff,100);
          close(fd);
          uint8_t  * start = (uint8_t*)readbuff;
          uint8_t des[100] = {0x54,0x72,0x61,0x63,0x65,0x72,0x50,0x69,0x64,0x3a,0x09};
          int i = 100;
          bool flag = false;
          while(--i){
              if(0 == memcmp(start,des,10)){
                  start =  start + 11;
                  childtracepid = atoi((char *)start);
                  flag = true;
                  break;
              }else{
                  start = start + 1;
                  flag = false;
              }
          }
          if(false == flag){
              LOGD("tracepid failed\n");
              return false;
          }
          close(pipefd[0]);
          write(pipefd[1],(void *)&childtracepid,4);
          close(pipefd[1]);
          LOGD("child succeed, finish.\n");
          exit(0);
    }else{
        LOGD("waiting for child process");
        waitpid(pid,NULL,NULL);
        int buf2 = 0;
        close(pipefd[1]);
        read(pipefd[0],(void *)&buf2,4);
        close(pipefd[0]);
        LOGD("child proceee traceid : %d\n",buf2);
        if(0 == buf2){
            LOGD("code has been destory");
        }else{
            LOGD("code is not changed");
        }

        return true;
    }


}
JNIEXPORT void JNICALL Java_com_antidebug_demo11_usendk_checksystem
        (JNIEnv *env, jclass clazz){
    checksystem();
}
