#include "stdio.h"
#include "stdlib.h"

int num_of_disk = 0;//���̵ĸ���

typedef struct disk Disk;
typedef struct floder Floder;
typedef struct files File;

void allot(Disk * hook);
void show_disk(Disk * head);
Floder * visit_floder(Floder * head, int offset);
void create_floder(Floder * hook);
Disk * visit_disk(Disk * head, int offset);
void show_floder(Floder * head);



struct disk
{
	char name;
	float capacity;
	int filesys;//1--NTFS 2--FAT32
	char demo[128];
	Floder * floder0;
	Disk * next;
};

struct floder
{
	char name[128];
	float size;
	int attribute;//1--read only 2--hide 0--NULL
	char demo[128];
	File * file0;
	Floder * next;
};

struct files
{
	char name[128];
	float size;
	int attribute;
	char demo[128];
	File * next;
};


int main()
{
	//��ʾ���������б�
	printf("���ڿ�ʼ�������̺ͷ�����̿ռ�\n");
	Disk  first_disk;//ע�⣺����������ģ���
	Disk * temp = &first_disk;
	do
	{
		fflush(stdin);
		temp->next = (Disk *)malloc(sizeof(Disk));
		temp = temp->next;
		allot(temp);
		num_of_disk++;
	} while (getchar() != 'q');
	printf("\n���̷������,����%d�����̷���\n",num_of_disk);
	show_disk(&first_disk);
	system("pause");
	
	
	system("cls");
	printf("����ģ����MDisk\n\n�����б�\n1.�ڴ����½����ļ�����)\n2.ɾ���ļ����У�\n3.����������е���Ϣ\n4.�޸��ļ����У���Ϣ\n\n��ѡ���ܣ�");
	int choice;



	int a, b;
	while (scanf("%d", &choice) == 1)
	{
		system("cls");
		switch (choice)
		{
		case 1:
			printf("�ô��̵�ǰ��ϢΪ��\n");
			show_disk(&first_disk);
			printf("��ѡ����Ҫ�����ļ��еĴ�����ţ�");
			scanf("%d", &a);
			if (a > num_of_disk || a <= 0)
			{
				printf("�������");
				break;
			}
			else
			{
				printf("��д�����밴1������밴2:");
				scanf("%d", &b);
				if (b == 1)
				{
					Disk * temp_disk = visit_disk(&first_disk, a);
					Floder * _template = temp_disk->floder0 = (Floder *)malloc(sizeof(Floder));
					fflush(stdin);
					create_floder(_template);
				}
				else if (b == 2)
				{
					printf("\nҪ��ӵ��ڼ����ļ���\n");
					int offset;
					scanf("%d", &offset);
					Disk * temp = visit_disk(&first_disk, a);
					//Ҫ�ȷ��ʴ��̣��ٷ����ļ���
					//ע��ҪMalloc
					Floder * _template = temp->floder0 = (Floder *)malloc(sizeof(Floder));
					Floder * temp_floder = visit_floder(_template, offset);
					Floder * swapper = temp_floder->next;
					temp_floder->next = (Floder *)malloc(sizeof(Floder));
					fflush(stdin);
					create_floder(temp_floder->next);
					temp_floder->next->next = swapper;
				}
			}
			break;
		case 2:

			break;
		case 3:
			show_disk(&first_disk);
			for (int i = 1; i <= num_of_disk;i++)
				show_floder(visit_disk(&first_disk,i)->floder0);
			
			break;
		case 4:

			break;
		default:
			break;
		}
		printf("�����б�\n1.�ڴ����½����ļ�����)\n2.ɾ���ļ����У�\n3.����������е���Ϣ\n4.�޸��ļ����У���Ϣ\n\\n��ѡ����:");
	}



	system("pause");
	return 0;
}

void allot(Disk * hook)
{
	printf("�������̷�:");
	scanf("%c", &hook->name);
	printf("�������С:");
	scanf("%f", &hook->capacity);
	printf("ѡ���ļ�ϵͳ��1--NTFS 2--FAT32��:\n[�����ֺ�ֱ�Ӽ���q������]");
	scanf("%d", &hook->filesys);
	return;
}

void show_disk(Disk * head)//��ʾ��ǰ������Ϣ
{
	printf("\n");
	Disk * temp = head->next;
	for (int k = 0; k < num_of_disk; k++)
	{
		printf("����%c        ����:%f���洢��λ     �ļ�ϵͳ:",temp->name,temp->capacity);
		if (temp->filesys == 1) printf("NTFS\n");
		if (temp->filesys == 2) printf("FAT32\n");
		temp = temp->next;
	}
	printf("\n");
}

Disk * visit_disk(Disk * head,int offset)
{
	if (offset <= 0)
	{
		printf("��������\n");
	}
	else
	{
		Disk * temp = head->next;//�涨head��һ��Ϊƫ����1
		for (int k = 1; k < offset; k++)
		{
			temp = temp->next;
		}
		return temp;
	}
	return;
}

void create_floder(Floder * hook)
{
	printf("�������ļ���:");
	scanf("%s",hook->name);
	printf("�������С:");
	scanf("%f", &hook->size);
	printf("ѡ���ļ����ԣ�1--ֻ�� 2--���� 0--�ޣ�");
	scanf("%d", &hook->attribute);
	hook->next = NULL;
	return;
}

Floder * visit_floder(Floder * head, int offset)
{
	if (offset < 0)
	{
		printf("��������\n");
	}
	else
	{
		Floder * temp = head;
		for (int k = 1; k < offset; k++)
		{
			temp = temp->next;
		}
		return temp;
	}
	return NULL;
}

void show_floder(Floder * head)
{
	printf("\n");
	Floder * temp = head;
	for (; temp!= NULL; temp = temp->next)
	{
		printf("�ļ���%s        ��С:%f���洢��λ     �ļ�����:", temp->name, temp->size);
		if (temp->attribute == 1) printf("ֻ��\n");
		else if (temp->attribute == 2) printf("����\n");
		else if (temp->attribute == 0) printf("NULL");		
	}
	printf("\n");
}

