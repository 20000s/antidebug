#include <jni.h>
#include <string>
#include <cstdio>
#include <signal.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
//IDA会首先截获信号，导致进程无法接收到信号，导致不会执行信号处理函数。将关键流程
//放在信号处理函数中，如果没有执行，就是被调试状态
int g_ret = 0;
extern "C" JNIEXPORT jstring JNICALL
Java_com_antidebug_demo13_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
void myhandler(int sig){
    printf("myhanlder.\n");
    return;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_antidebug_demo13_MainActivity_antida(JNIEnv *env, jobject thiz) {
    g_ret = (int)signal(SIGTRAP,myhandler);
    if((int) SIG_ERR == g_ret)
        printf("signal ret value is SIG_ERR\n");
    printf("signal ret value is %X\n",(unsigned char *)g_ret);
    raise(SIGTRAP);
    raise(SIGTRAP);
    raise(SIGTRAP);
    kill(getpid(),SIGTRAP);
    printf("main\n");
    return 0;


}

