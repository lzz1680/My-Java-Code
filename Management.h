#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NMAE 20
#define MAX_TELE 20
#define MAX_MOBIL 20
#define MAX_EMAIL 20
#define MAX_QQ 20
#define MAX_PER 20
#define ADDRESS 20
#define MAX_SIZE 20

#include"string.h"
#include"assert.h"
#include"stdlib.h"
#include"time.h"
//�ź�������
//ʵ��ĳЩ���ܣ�������ʾ�����ң���ӣ��޸ģ�ɾ��,���������Ϣ





//�ṹ������
typedef struct person {//������Ϣ
	char name[MAX_NMAE];//����

	int telephone[MAX_TELE];//�̶��绰����
	int mobilephone[MAX_MOBIL];//�ƶ��绰����
	char email[MAX_EMAIL];//��������
	int QQ[MAX_QQ];//QQ��

	char address[ADDRESS];//סַ
}PER;

typedef struct date {
	//����ͨѶ¼�ļ��ϣ��������Ϣ�洢
	//������Ϣ���������date��
	
	 PER per[MAX_PER];

	 int count;//������,��¼��ϵ������
	//struct date* next;//�����ʵ�֣�
}DATE;

void InitDATE(DATE* pc);

void AddPeo(DATE *con);

void showPeo(DATE *con);

void DelContact(DATE* con);

void SearchContact(DATE*con);

void ModifyContact(DATE* con);

void SortContact(DATE* con);