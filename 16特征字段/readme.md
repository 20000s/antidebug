进程信息结构检测

第一种:

/proc/pid/status

/proc/pid/task/pid/status

TracerPid非0

statue字段写入t

第二种:

/proc/pid/stat

/proc/pid/task/pid/stat

第二个字段是t(T)



第三种:

/proc/pid/wchan

/proc/pid/task/pid/wchan

ptrace_stop