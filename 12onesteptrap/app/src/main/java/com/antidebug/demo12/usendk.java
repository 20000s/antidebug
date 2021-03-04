package com.antidebug.demo12;

public class usendk {
    static {
        System.loadLibrary("anti");
    }
    public native static void antidebug();
}
