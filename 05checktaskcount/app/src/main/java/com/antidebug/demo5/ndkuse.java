package com.antidebug.demo5;
// normal apk can use many process to run but if you use your own out to load so,in thisway the process is only one
public class ndkuse {
    static {
        System.loadLibrary("anti");
    }
    public native static void checktaskcounts();
}
