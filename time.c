#include <time.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    struct tm *tm = NULL;
    time_t tNow = -1;
    time_t tNow2 = -1;
    time(&tNow);
    time(&tNow2);
    char *timeN = ctime(&tNow);
    char *tmNow;
    tm = gmtime(&tNow);
    printf("time:%ld\n", tNow);
    printf("ctime:%s", timeN);
    printf("gmtime:%d年%d月%d日 %d时\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour + 8);
    struct tm *tm2;
    tm2 = localtime(&tNow2);
    strftime(tmNow, 96, "%Y年%m月%d日 (%A) %H时%M分%S秒 %Z", tm2);
    printf("strftime:%s\n", tmNow);
    printf("localtime:%d年%d月%d日 %d时\n", tm2->tm_year + 1900, tm2->tm_mon + 1, tm2->tm_mday, tm2->tm_hour);
    tmNow = asctime(tm);
    printf("asctime:%s", tmNow);
    return 0;
}
