package com.antidebug.demo07;

public class usendk {
    static {
        System.loadLibrary("anti");
    }
    public native static void isdebugconnected();


}
