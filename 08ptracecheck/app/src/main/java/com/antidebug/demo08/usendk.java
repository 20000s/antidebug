package com.antidebug.demo08;

public class usendk {
    static {
        System.loadLibrary("anti");
    }
    public native static void ptracecheck();
}
