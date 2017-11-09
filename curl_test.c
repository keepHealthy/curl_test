/*************************************************************************
    > File Name: curl_test.c
    > Author: YeKai
    > Company: www.itcast.cn 
    > Created Time: 2017年11月09日 星期四 15时18分20秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <curl/curl.h>
int main(int argc,char *argv[])
{
    CURL *curl = NULL;
    CURLcode res ;
    
    curl = curl_easy_init();
    if(curl==NULL)
    {
        printf("curl_init error\n");
        exit(1);
    }

    res = curl_easy_setopt(curl,CURLOPT_URL,"http://www.baidu.com");
    if(res!=CURLE_OK)
    {
        printf("curl setopt url error\n");
        exit(1);
    }

    res = curl_easy_setopt(curl,CURLOPT_POST,0);
    if(res!=CURLE_OK)
    {
        printf("curl setopt get error\n");
        exit(1);
    }

    res = curl_easy_perform(curl);
    if(res!=CURLE_OK)
    {
        printf("curl perform error\n");
        exit(1);
    }

    curl_easy_cleanup(curl);

    return 0;
}
