//ʵ�ֺ�����������
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"


//pc==con

#define _CRT_SECURE_NO_WARNINGS
#include"Management.h"

//per��һ������


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



void AddPeo(DATE* con) {//������Ա����
	if (con->count == 100)
	{
		printf("ͨѶ¼�Ѿ�����");
	malloc(sizeof(DATE));


	}
	else
	{

		//�����Ա��Ϣ
		printf("��������:\n");
		scanf("%s", &con->per[con->count].name);
			
		printf("�����ƶ��绰����:\n");
		scanf("%s", &con->per[con->count].mobilephone);
		 
		printf("����̶��绰����:\n");
		scanf("%s", &con->per[con->count].telephone);

		printf("����QQ��:\n");
		scanf("%s", &con->per[con->count].QQ);

		printf("����Email:\n");
		scanf("%s", &con->per[con->count].email);

		printf("�����ַ:\n");
		scanf("%s", &con->per[con->count].address);

		con->count++;
		printf("���ӳɹ�\n\t");
		printf("****************************************************************\t");
		//sleep(25);
	}

}

//**************************************

void showPeo(DATE* con) {
	assert(con);
	for (int i = 0; i < con->count; i++)
	{
		printf("����:%s\n", con->per[i].name);
		printf("�ƶ��绰:%11d\n", con->per[i].mobilephone);
		printf("�̶��绰:%12d\n", con->per[i].telephone);
		printf("QQ��:%11s\n", con->per[i].QQ);
		printf("��������:%s\n", con->per[i].email);
		printf("��ַ:%s\n", con->per[i].address);
	}
}

//*********************************
int FindByName(DATE*con,char name[]) {
	assert(con);
	
	for (int i = 0; i < con->count; i++)
	{
		if (0 == strcmp(con->per[i].name,name));//ѭ���Ƚ�name���ַ�
		{
			return i;//����ֵΪ�漴��
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
		printf("ͨѶ¼Ϊ��");
		return;
	}
	printf("������Ҫɾ�����˵�����");
	scanf("%s", name);
	//���ò�ѯ�ĺ���
	//��ѯ�������1,���޴��ˣ�2�ҵ���
	int pos = FindByName(con, name);//pos��¼���ҵ���������ֵ���
	if(pos==-1)
	{ 
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//2ʵ��ɾ������
	for (int i = pos; i < con->count; i++)
	{
		con->per[i] = con->per[i + 1];//��ʵ���ú�������ݶ����Ҫɾ��������
	}


	con->count--;
	printf("ɾ���ɹ�\n");

}

void SearchContact(DATE* con)
{
	assert(con);
	char name[MAX_SIZE];
	printf("������ҵ��˵�����");
	scanf("%s",&name);
	//�����Ƿ���ڴ���
	//���������Լ�д�ĺ���
	int pos = FindByName(con, name);//pos��¼���ҵ���������ֵ���
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}

	//�ҵ����ӡ
	else {
		printf("����:%s\n", con->per[pos].name);
		printf("�ƶ��绰:%11d\n", con->per[pos].mobilephone);
		printf("�̶��绰:%12d\n", con->per[pos].telephone);
		printf("QQ��:%11d\n", con->per[pos].QQ);
		printf("��������:%s\n", con->per[pos].email);
		printf("��ַ:%s\n", con->per[pos].address);
	}
}


void ModifyContact(DATE* con)
{
	//����
	char name[MAX_SIZE];
	printf("����Ҫ�޸ĵ��˵�����");
	scanf("%s", name);
	int pos = FindByName(con, name);//pos��¼���ҵ���������ֵ���,pos����find�����ķ��ص��������±ꡣ
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return ;
	}

	printf("��������>\n");
	scanf("%s", con->per[pos].name);

	printf("�����ƶ��绰>\n");
	scanf("%d", con->per[pos].mobilephone);

	printf("����̶��绰>\n");
	scanf("%d", con->per[pos].telephone);

	printf("����QQ��>\n");
	scanf("%s", con->per[pos].QQ);

	printf("����email>\n");
	scanf("%s", con->per[pos].email);

	printf("�����ַ>\n");
	scanf("%s", con->per[pos].address);

	printf("�޸ĳɹ�\n");
}

//*******************************
//����
int cmp_peo_by_name(const void* e1, const void* e2)
{
	int a=strcmp(((DATE*)e1)->per->name, ((DATE*)e2)->per->name);
	return a;
}
void SortContact(DATE* con) {
	assert(con);
	qsort(con->per, con->count, sizeof(DATE),cmp_peo_by_name);//������������

	printf("�������");
	showPeo(con);
}