package com.antidebug.demo11;

public class usendk {
    static {
        System.loadLibrary("anti");
    }
    public native static void checksystem();
}
