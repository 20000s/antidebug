原理：
IDA采用递归下降算法来反汇编指令，而该算法最大的缺点在于它无法处理间接代码路径，
无法识别动态算出来的跳转。而arm架构下由于存在arm和thumb指令集，就涉及到指令集
切换，IDA在某些情况下无法智能识别arm和thumb指令，进一步导致无法进行伪代码还原。
在IDA动态调试时，仍然存在该问题，若在指令识别错误的地点写入断点，有可能使得调试
器崩溃。（ 可能写断点 ,不知道写ARM还是THUMB ,造成的崩溃）

```c#if(JUDGE_THUMB)
#define GETPC_KILL_IDAF5_SKATEBOARD \
__asm __volatile( \
"mov r0,pc \n\t" \
"adds r0,0x9 \n\t" \
"push {r0} \n\t" \
"pop {r0} \n\t" \
"bx r0 \n\t" \
\
".byte 0x00 \n\t" \
".byte 0xBF \n\t" \
\
".byte 0x00 \n\t" \
".byte 0xBF \n\t" \
\
".byte 0x00 \n\t" \
".byte 0xBF \n\t" \
:::"r0" \
);
#else
#define GETPC_KILL_IDAF5_SKATEBOARD \
__asm __volatile( \
"mov r0,pc \n\t" \
"add r0,0x10 \n\t" \
"push {r0} \n\t" \
"pop {r0} \n\t" \
"bx r0 \n\t" \
".int 0xE1A00000 \n\t" \
".int 0xE1A00000 \n\t" \
".int 0xE1A00000 \n\t" \
".int 0xE1A00000 \n\t" \
:::"r0" \
);
#endif
// 常量标签版本
#if(JUDGE_THUMB)
#define IDAF5_CONST_1_2 \
__asm __volatile( \
"b T1 \n\t" \
"T2: \n\t" \
"adds r0,1 \n\t" \
"bx r0 \n\t" \
"T1: \n\t" \
"mov r0,pc \n\t" \
"b T2 \n\t" \
:::"r0" \
);
#else
#define IDAF5_CONST_1_2 \
__asm __volatile( \
"b T1 \n\t" \
"T2: \n\t" \
"bx r0 \n\t" \
"T1: \n\t" \
"mov r0,pc \n\t" \
"b T2 \n\t" \
:::"r0" \
);
#endif
```

