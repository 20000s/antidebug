void thread_watchDumpPagemap(){
    LOGD("-------------------------watchDump:Pagemap--------------------");
   char dirName[NAME_MAX] = {0};
   snprintf(dirName,NAME_MAX,"/proc/%d/pagemap",getpid());
   int fd = inotify_init();
   if(fd < 0){
       LOGD("inotify_init err. \n");
       return;
   }  

   int wd = inotify_add_watch(fd,dirname,IN_ALL_EVENTS);

   if(wd < 0){
       LOGD("inotify_add_watch err \n");
       close(fd);
       return;
   }
   const int buflen = sizeof(struct inotify_event) * 0x100;
   char buf[buflen] = {0};
   fd_set readfds;

   while(1){
       FD_ZERO(&readfds);
       FD_SET(fd,&readfds);
       int iRet = select(fd+1,&readfds,0,0,0);
       LOGD("iret的返回值 %d",iRet);
   
if(-1==iRet)
break;
if (iRet)
{
memset(buf,0,buflen);
int len = read(fd,buf,buflen);
int i=0;
while(i < len)
{
struct inotify_event *event = (struct inotify_even
t*)&buf[i];
LOGB("1 event mask的数值为:%d\n",event->mask);
if( (event->mask==IN_OPEN) )
{
// 此处判定为有true,执行崩溃.
LOGB("2 有人打开pagemap,第%d次.\n\n",i);
//__asm __volatile(".int 0x8c89fa98");
}
i += sizeof (struct inotify_event) + event->len;
}
LOGA("-----3 退出小循环-----\n");
}
}
inotify_rm_watch(fd,wd);
close(fd);
LOGA("-----4 退出大循环,关闭监视-----\n");
return;
}
void smain()
{
// 监控/proc/pid/mem
pthread_t ptMem,t,ptPageMap;
int iRet=0;
// 监控/proc/pid/pagemap
iRet=pthread_create(&ptPageMap,NULL,(PPP)thread_watchDumpPagema
p,NULL);
if (0!=iRet)
{
LOGA("Create,thread_watchDumpPagemap,error!\n");
return;
}
iRet=pthread_detach(ptPageMap);
if (0!=iRet)
{
LOGA("pthread_detach,thread_watchDumpPagemap,error!\n");
return;
}
LOGA("-------------------smain-------------------\n");
LOGB("pid:%d\n",getpid());
return;
}