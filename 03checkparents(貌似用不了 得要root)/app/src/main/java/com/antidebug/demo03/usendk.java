package com.antidebug.demo03;

import android.content.Context;

//sometimes you may write a elf to load its so ,this time its parent process is not zygote but on the other times even if you attach it to debug
//its parentprocess is still zygote so we can use this method to judge wherther the so ising being debugged
public class usendk {
    static {
        System.loadLibrary("antidebug");
    }
    public native static void checkparents();
    public native static void getname(Context context);
}
