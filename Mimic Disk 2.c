#include "stdio.h"
#include "stdlib.h"

int num_of_disk = 0;//磁盘的个数

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
	//提示创建磁盘列表
	printf("现在开始创建磁盘和分配磁盘空间\n");
	Disk  first_disk;//注意：这是无意义的！！
	Disk * temp = &first_disk;
	do
	{
		fflush(stdin);
		temp->next = (Disk *)malloc(sizeof(Disk));
		temp = temp->next;
		allot(temp);
		num_of_disk++;
	} while (getchar() != 'q');
	printf("\n磁盘分配结束,共有%d个磁盘分区\n",num_of_disk);
	show_disk(&first_disk);
	system("pause");
	
	
	system("cls");
	printf("磁盘模拟器MDisk\n\n功能列表：\n1.在磁盘下建立文件（夹)\n2.删除文件（夹）\n3.输出磁盘所有的信息\n4.修改文件（夹）信息\n\n请选择功能：");
	int choice;



	int a, b;
	while (scanf("%d", &choice) == 1)
	{
		system("cls");
		switch (choice)
		{
		case 1:
			printf("该磁盘当前信息为：\n");
			show_disk(&first_disk);
			printf("请选择需要建立文件夹的磁盘序号：");
			scanf("%d", &a);
			if (a > num_of_disk || a <= 0)
			{
				printf("错误操作");
				break;
			}
			else
			{
				printf("重写磁盘请按1，添加请按2:");
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
					printf("\n要添加到第几个文件后？\n");
					int offset;
					scanf("%d", &offset);
					Disk * temp = visit_disk(&first_disk, a);
					//要先访问磁盘，再访问文件夹
					//注意要Malloc
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
		printf("功能列表：\n1.在磁盘下建立文件（夹)\n2.删除文件（夹）\n3.输出磁盘所有的信息\n4.修改文件（夹）信息\n\\n请选择功能:");
	}



	system("pause");
	return 0;
}

void allot(Disk * hook)
{
	printf("请输入盘符:");
	scanf("%c", &hook->name);
	printf("请输入大小:");
	scanf("%f", &hook->capacity);
	printf("选择文件系统（1--NTFS 2--FAT32）:\n[在数字后直接加上q来结束]");
	scanf("%d", &hook->filesys);
	return;
}

void show_disk(Disk * head)//显示当前磁盘信息
{
	printf("\n");
	Disk * temp = head->next;
	for (int k = 0; k < num_of_disk; k++)
	{
		printf("磁盘%c        容量:%f个存储单位     文件系统:",temp->name,temp->capacity);
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
		printf("操作错误\n");
	}
	else
	{
		Disk * temp = head->next;//规定head后一个为偏移量1
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
	printf("请输入文件名:");
	scanf("%s",hook->name);
	printf("请输入大小:");
	scanf("%f", &hook->size);
	printf("选择文件属性（1--只读 2--隐藏 0--无）");
	scanf("%d", &hook->attribute);
	hook->next = NULL;
	return;
}

Floder * visit_floder(Floder * head, int offset)
{
	if (offset < 0)
	{
		printf("操作错误\n");
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
		printf("文件名%s        大小:%f个存储单位     文件属性:", temp->name, temp->size);
		if (temp->attribute == 1) printf("只读\n");
		else if (temp->attribute == 2) printf("隐藏\n");
		else if (temp->attribute == 0) printf("NULL");		
	}
	printf("\n");
}

