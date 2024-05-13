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
//放函数声明
//实现某些功能，包括显示，查找，添加，修改，删除,输出个人信息





//结构体声明
typedef struct person {//个人信息
	char name[MAX_NMAE];//姓名

	int telephone[MAX_TELE];//固定电话号码
	int mobilephone[MAX_MOBIL];//移动电话号码
	char email[MAX_EMAIL];//电子邮箱
	int QQ[MAX_QQ];//QQ号

	char address[ADDRESS];//住址
}PER;

typedef struct date {
	//看作通讯录的集合，多个人信息存储
	//个人信息存放再链表date中
	
	 PER per[MAX_PER];

	 int count;//计数器,记录联系人数量
	//struct date* next;//链表的实现；
}DATE;

void InitDATE(DATE* pc);

void AddPeo(DATE *con);

void showPeo(DATE *con);

void DelContact(DATE* con);

void SearchContact(DATE*con);

void ModifyContact(DATE* con);

void SortContact(DATE* con);