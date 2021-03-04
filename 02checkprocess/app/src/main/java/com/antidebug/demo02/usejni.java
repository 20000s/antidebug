package com.antidebug.demo02;

public class usejni {
    static {
        System.loadLibrary("antidebug");
    }
    public static native void antirpocess();
}
