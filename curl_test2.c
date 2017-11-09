#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include <curl/curl.h>

#define POSTDATA "{\"username\":\"gailun\", \"password\":\"123123\"}"

int main(int argc, char *argv[])
{

    CURL *curl = NULL;
    CURLcode res;
    
    curl = curl_easy_init();
    if (curl == NULL) {
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8090/");


    //����curlΪpost����
    curl_easy_setopt(curl, CURLOPT_POST, 1);

    //��post�����ṩһЩpost����
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, POSTDATA);


    //��Զ���ύ����
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {

        printf("perform error res = %d\n", res);
        return -1;
    }

    //�����������Ӧ����


    curl_easy_cleanup(curl);
    

        return 0;
}
