#pragma once
#ifndef LORAWANCMD_LORAWANCMD_H
#define LORAWANCMD_LORAWANCMD_H

#endif //LORAWANCMD_LORAWANCMD_H

#define OK "OK"     //��Ӧ����
#define ER00 "ER00" //�﷨����
#define ER01 "ER01" //�﷨����
#define ER02 "ER02" //�ܾ�����͹���
#define ER03 "ER03" //ģ��δ��������
#define ER04 "ER04" //����æ
#define ER05 "ER05" //���ܻ�����������
#define ER06 "ER06" //Flash�����
#define ER07 "ER07" //��������ʧ��
#define ER08 "ER08" //���þܾ�
#define ER09 "ER09" //��ѯ�ܾ�

#include <stdint.h>
#include <stdio.h>

void sendData(char data[]);