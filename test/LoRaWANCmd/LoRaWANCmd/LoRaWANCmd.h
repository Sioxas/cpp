#pragma once
#ifndef LORAWANCMD_LORAWANCMD_H
#define LORAWANCMD_LORAWANCMD_H

#endif //LORAWANCMD_LORAWANCMD_H

#define OK "OK"     //响应正常
#define ER00 "ER00" //语法错误
#define ER01 "ER01" //语法错误
#define ER02 "ER02" //拒绝进入低功耗
#define ER03 "ER03" //模块未加入网络
#define ER04 "ER04" //发送忙
#define ER05 "ER05" //接受缓冲区无数据
#define ER06 "ER06" //Flash块错误
#define ER07 "ER07" //发送数据失败
#define ER08 "ER08" //配置拒绝
#define ER09 "ER09" //查询拒绝

#include <stdint.h>
#include <stdio.h>

void sendData(char data[]);