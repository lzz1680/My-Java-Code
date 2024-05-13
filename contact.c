//实现函数功能区域
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"


//pc==con

#define _CRT_SECURE_NO_WARNINGS
#include"Management.h"

//per是一个数组


//1
void InitDATE(DATE* pc)
{
	pc->count = 0;

	memset(pc->per->address, 0, sizeof(pc->per->address));
	memset(pc->per->email, 0, sizeof(pc->per->email));
	memset(pc->per->mobilephone, 0, sizeof(pc->per->mobilephone));
	memset(pc->per->name, 0, sizeof(pc->per->name));
	memset(pc->per->QQ, 0, sizeof(pc->per->QQ));
	memset(pc->per->telephone, 0, sizeof(pc->per->telephone));

}



void AddPeo(DATE* con) {//增加人员数据
	if (con->count == 100)
	{
		printf("通讯录已经满了");
	malloc(sizeof(DATE));


	}
	else
	{

		//添加人员信息
		printf("输入姓名:\n");
		scanf("%s", &con->per[con->count].name);
			
		printf("输入移动电话号码:\n");
		scanf("%s", &con->per[con->count].mobilephone);
		 
		printf("输入固定电话号码:\n");
		scanf("%s", &con->per[con->count].telephone);

		printf("输入QQ号:\n");
		scanf("%s", &con->per[con->count].QQ);

		printf("输入Email:\n");
		scanf("%s", &con->per[con->count].email);

		printf("输入地址:\n");
		scanf("%s", &con->per[con->count].address);

		con->count++;
		printf("增加成功\n\t");
		printf("****************************************************************\t");
		//sleep(25);
	}

}

//**************************************

void showPeo(DATE* con) {
	assert(con);
	for (int i = 0; i < con->count; i++)
	{
		printf("姓名:%s\n", con->per[i].name);
		printf("移动电话:%11d\n", con->per[i].mobilephone);
		printf("固定电话:%12d\n", con->per[i].telephone);
		printf("QQ号:%11s\n", con->per[i].QQ);
		printf("电子邮箱:%s\n", con->per[i].email);
		printf("地址:%s\n", con->per[i].address);
	}
}

//*********************************
int FindByName(DATE*con,char name[]) {
	assert(con);
	
	for (int i = 0; i < con->count; i++)
	{
		if (0 == strcmp(con->per[i].name,name));//循环比较name的字符
		{
			return i;//返回值为真即可
		}
	}
	return -1;
}



void DelContact(DATE* con)
{
	char name[MAX_SIZE] = { 0 };
	assert(con);
	if (con->count == 0)
	{
		printf("通讯录为空");
		return;
	}
	printf("请输入要删除的人的名字");
	scanf("%s", name);
	//调用查询的函数
	//查询结果分类1,查无此人，2找到了
	int pos = FindByName(con, name);//pos记录查找到函数返回值结果
	if(pos==-1)
	{ 
		printf("要删除的人不存在\n");
		return;
	}
	//2实现删除功能
	for (int i = pos; i < con->count; i++)
	{
		con->per[i] = con->per[i + 1];//其实是用后面的数据顶替掉要删除的数据
	}


	con->count--;
	printf("删除成功\n");

}

void SearchContact(DATE* con)
{
	assert(con);
	char name[MAX_SIZE];
	printf("输入查找的人的姓名");
	scanf("%s",&name);
	//查找是否存在此人
	//熟练调用自己写的函数
	int pos = FindByName(con, name);//pos记录查找到函数返回值结果
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}

	//找到后打印
	else {
		printf("姓名:%s\n", con->per[pos].name);
		printf("移动电话:%11d\n", con->per[pos].mobilephone);
		printf("固定电话:%12d\n", con->per[pos].telephone);
		printf("QQ号:%11d\n", con->per[pos].QQ);
		printf("电子邮箱:%s\n", con->per[pos].email);
		printf("地址:%s\n", con->per[pos].address);
	}
}


void ModifyContact(DATE* con)
{
	//先找
	char name[MAX_SIZE];
	printf("输入要修改的人的名字");
	scanf("%s", name);
	int pos = FindByName(con, name);//pos记录查找到函数返回值结果,pos接受find函数的返回的索引处下标。
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return ;
	}

	printf("输入姓名>\n");
	scanf("%s", con->per[pos].name);

	printf("输入移动电话>\n");
	scanf("%d", con->per[pos].mobilephone);

	printf("输入固定电话>\n");
	scanf("%d", con->per[pos].telephone);

	printf("输入QQ号>\n");
	scanf("%s", con->per[pos].QQ);

	printf("输入email>\n");
	scanf("%s", con->per[pos].email);

	printf("输入地址>\n");
	scanf("%s", con->per[pos].address);

	printf("修改成功\n");
}

//*******************************
//排序
int cmp_peo_by_name(const void* e1, const void* e2)
{
	int a=strcmp(((DATE*)e1)->per->name, ((DATE*)e2)->per->name);
	return a;
}
void SortContact(DATE* con) {
	assert(con);
	qsort(con->per, con->count, sizeof(DATE),cmp_peo_by_name);//按照名字排序

	printf("排序完成");
	showPeo(con);
}