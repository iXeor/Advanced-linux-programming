#include <time.h>
#include <stdio.h>

void main()
{
    struct tm *tm;
    time_t tNow = -1;
    time(&tNow);
    char *timeN = ctime(&tNow);
    char *tmNow;
    tm = gmtime(&tNow);
    printf("time:%ld\n", tNow);
    printf("ctime:%s", timeN);
    printf("gmtime:%d年%d月%d日 %d时\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour + 8);
    tm = localtime(&tNow);
    printf("localtime:%d年%d月%d日 %d时\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour);
    tNow = mktime(tm);
    strftime(tmNow, 96, "%Y年%m月%d日 (%A) %H时%M分%S秒 %Z", tm);
    printf("strftime:%s\n", tmNow);
    tmNow = asctime(tm);
    printf("asctime:%s", tmNow);
    printf("mktime:%ld\n", tNow);
}