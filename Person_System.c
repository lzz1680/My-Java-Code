#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"Management.h"
//放数据的输入输出

//个人的信息存放在一个结构体中


void static showscrit() {
	//信息界面
	printf("*********************************\n");
	printf("****0-退出***********************\n");
	printf("****1-添加联系人*****************\n");
	printf("****2-删除联系人*****************\n");
	printf("****3-查找联系人*****************\n");
	printf("****4-修改联系人*****************\n");//修改信息
	printf("****5-显示联系人*****************\n");
	printf("****6-排序联系人*****************\n");
	printf("*********************************\n");
}

int main()
{	
int n = 0;
		//结构体类型变量
		DATE con;
		InitDATE(&con);//初始化信息栏
	do {
		//放一个初始化con的函数
		//信息界面
		showscrit();	
		//DATE con;// 链表的信息
		printf("输入选项:\n");
		scanf_s("%d",&n);
		if (n>=0&&n<=6)
		{
			switch (n)
			{
			case 1:
				//添加
				AddPeo(&con); 
				break;
			case 2:
				//查删
				DelContact(&con);
				break;
			case 3:
				//查找
				SearchContact(&con);
				break;
			case 4:
				//查改
				ModifyContact(&con);
				break;
			case 5:
				//显示信息
			 showPeo(&con);
				break;
			case 6:
				//排序信息
				SortContact(&con);
				break;
			case 0:
				//退出
				return;
				break;

			default:
				break;
			}
		}
		else
		{
			printf("没有此项功能,请重新输入\n");
		}

	} while (n);


	return 0;
}