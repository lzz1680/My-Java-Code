#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"Management.h"
//�����ݵ��������

//���˵���Ϣ�����һ���ṹ����


void static showscrit() {
	//��Ϣ����
	printf("*********************************\n");
	printf("****0-�˳�***********************\n");
	printf("****1-�����ϵ��*****************\n");
	printf("****2-ɾ����ϵ��*****************\n");
	printf("****3-������ϵ��*****************\n");
	printf("****4-�޸���ϵ��*****************\n");//�޸���Ϣ
	printf("****5-��ʾ��ϵ��*****************\n");
	printf("****6-������ϵ��*****************\n");
	printf("*********************************\n");
}

int main()
{	
int n = 0;
		//�ṹ�����ͱ���
		DATE con;
		InitDATE(&con);//��ʼ����Ϣ��
	do {
		//��һ����ʼ��con�ĺ���
		//��Ϣ����
		showscrit();	
		//DATE con;// �������Ϣ
		printf("����ѡ��:\n");
		scanf_s("%d",&n);
		if (n>=0&&n<=6)
		{
			switch (n)
			{
			case 1:
				//���
				AddPeo(&con); 
				break;
			case 2:
				//��ɾ
				DelContact(&con);
				break;
			case 3:
				//����
				SearchContact(&con);
				break;
			case 4:
				//���
				ModifyContact(&con);
				break;
			case 5:
				//��ʾ��Ϣ
			 showPeo(&con);
				break;
			case 6:
				//������Ϣ
				SortContact(&con);
				break;
			case 0:
				//�˳�
				return;
				break;

			default:
				break;
			}
		}
		else
		{
			printf("û�д����,����������\n");
		}

	} while (n);


	return 0;
}