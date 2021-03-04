package com.antidebug.demo10;

public class usendk {
    static {
        System.loadLibrary("anti");
    }
    public native static void antidebug();
}
