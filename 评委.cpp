#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>

#define LEN sizeof(S_MESSAGE) 
#define N 7

typedef struct songer
{
	long num;
	char name[20];
	float grades[N];
	double ave;
	struct songer*next;
}S_MESSAGE;

S_MESSAGE*head;
S_MESSAGE*tail;
int n=0;
void creat();
void del();
void search();
void print();
void rank();
void update();
void menu();
void menu_select();
void browse();
void save();
void quit();

void rank()
{
	S_MESSAGE*p1,*p2,*endpt,*p;
	n=0;
	p1=head;
	
	if(head==NULL&&tail==NULL)
	{
		printf("\n-------当前信息记录为空-------\n");
		
	}
	else
	{
		p1=(S_MESSAGE*)malloc(LEN);
		p1->next=head;
		head=p1;
		for(endpt=NULL;endpt!=head;endpt=p)
		{
			for(p=p1=head;p1->next->next!=endpt;p1=p1->next)
				{
					if(p1->next->ave<p1->next->next->ave)
					{
						p2=p1->next->next;
						p1->next->next=p2->next;
						p2->next=p1->next;
						p1->next=p2;
						p=p1->next->next;
					}
				}		
		}
	p1=head;
	head=head->next;
	free(p1);
	printf("\n--------选手成绩排名信息如下-------\n");
	printf("-------|-------|-------|--------\n");
	printf(" 编号| 姓名 | 平均成绩| 名次 \n");
	p1=head;
	while(p1!=NULL)
		{
			printf("-------|-------|-------|--------\n");
			printf("%-9d%-9s%-9.1lf%-5d\n",p1->name,p1->name,p1->ave,n+1);
			n++;
			p1=p1->next;
		}
			printf("-------|-------|-------|--------\n");
	}
		getchar();
}

void print()
{
	S_MESSAGE*p1=(S_MESSAGE*)malloc(LEN);
	int check=0,i;
	long seeknum;
	printf("\n请输入要查找的选手编号：");
	scanf("%d",&seeknum);
	if(head==NULL&&tail==NULL)
	{
		printf("\对不起，当前记录为空！\n");
	} 
	else
	{
		p1=head;
		printf("\n--------你要找的选手的成绩如下--------\n");
		printf("-------|-------|-------|--------\n");
		printf("编号|姓名|成绩|1|2|3|4|5|6|7|平均成绩\n");
		printf("-------|-------|-------|--------\n");
		while(p1!=NULL)
		{
			if(p1->num==seeknum)
			{
				printf("%-7d%-6s",p1->num,p1->name);
				printf(" ");
				for(i=0;i<N;i++)
				{
					printf("%.1f",p1->grades[i]);
				}
				printf("%-6.2lf\n",p1->ave);
				check=1;
				getchar();
				return;
			}
			else
			{
				p1=p1->next;
			}
		 } 
	}
	if(head!=NULL&&check==0)
	{
		printf("\n对不起，你查看的选手成绩不存在!\n");
	}
	getchar();
}

void search()
{
	int c;
	printf("\n请选择查询内容：\n");
	printf("1.选手详细成绩查询  2.选手排名查询\n 输入你的选择： ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:system("cls");print();break;
		case 2:system("cls");rank();break;
	 } 
}

void save()
{
	FILE*fp;
	S_MESSAGE*p1=(S_MESSAGE*)malloc(LEN);
	p1=head;
	fp=fopen("参赛选手名单.txt","w");
	fprintf(fp,"-------|-------\n");
	fprintf(fp,"编号|姓名\n");
	while(p1!=NULL)
	{
		fprintf(fp,"-------|-------\n");
		fprintf(fp,"%-9d%-6s\n",p1->num,p1->name);
		p1=p1->next;
	}
	fprintf(fp,"---------|-------\n");
	fclose(fp);
	printf("\n\t文件已将保持到\"参赛选手名单.txt\"");
	
}

void browse()
{
	S_MESSAGE*p1;
	if(head==NULL&&tail==NULL)
	{
		printf("\n-------当前信息记录为空-------\n");
	}
	else
	{
		printf("\n-------你要浏览的选手信息如下-------\n");
		printf("---------|-------\n");
		printf("编号|姓名\n");
		p1=head;
		while(p1!=NULL)
		{
			printf("---------|-------\n");
			printf("%-9d%-6s\n",p1->num,p1->name);
			p1=p1->next;
		}
		printf("---------|-------\n");
	}
}

void creat()
{
	int i,j;
	float t;
	char c='y';
	while(c=='y'||c=='Y')
	{
		S_MESSAGE*p1=(S_MESSAGE*)malloc(LEN);
		printf("\n 请输入要录入的选手信息：\n");
		printf("\n 选手编号：");
		scanf("%d",&p1->num);
		 
	}
 } 

