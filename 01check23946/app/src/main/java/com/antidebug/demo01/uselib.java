package com.antidebug.demo01;

public class uselib {
    static{
        System.loadLibrary("antidebug");
    }
    public native static void antoida();
}
