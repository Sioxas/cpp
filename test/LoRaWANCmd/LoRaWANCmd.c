//
// Created by sioxa on 2017/4/18 0018.
//
#include "LoRaWANCmd.h"

void sendData(char data[]){
    int n=0;
    while(data[n++]!='\0');
    n--;
    char str[n*2+1];
    char t[2];
    int i;
    for(i=0;i<n;i++){
        sprintf(t,"%x",data[i]);
        str[i*2]=t[0];
        str[i*2+1]=t[1];
    }
    str[2*n]='\0';
    printf("%d",n);
    printf("%s",str);
    //printf("%d\n",2*n);


//    sprintf(t,"%x",2*n);
//    printf("AT+TX=02+00+%s+%s",t,str);
}

