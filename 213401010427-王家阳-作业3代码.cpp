#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
typedef struct Lnode
{
	double coef;//系数
	int expn;//指数
	Lnode* next;//指向下一个链表结点
}Lnode, * LinkList;//链表变量名称
LinkList CreatList(FILE* fp,int n)//初始化创建链表并向链表中输入数据
{
	int i = 0;
	char ch = 0;
	double co = 0;
	int ex = 0;
	LinkList L =(Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
	LinkList p;
	p = L;
	for(i = 0 ; i < n ; i++)//尾插法建立链表
	{
		Lnode* q = (Lnode*)malloc(sizeof(Lnode));
		fscanf(fp, "%lf %d ", &co, &ex);//从文件中将内容写入链表中
		q->coef = co;
		q->expn = ex;
		q->next = NULL;
		p->next = q;
		p = q;   
	}            
	return (L);  
}
void sortlist1(LinkList& L)//对输入的两个多项式进行排序
{
	int temp1 = 0;
	double temp2 = 0;
	for (Lnode* p = L->next; p; p = p->next)//选择排序
	{
		for (Lnode* pre = p->next; pre; pre = pre->next)
		{
			if (p->expn > pre->expn)
			{
				temp1 = p->expn;
				p->expn = pre->expn;
				pre->expn = temp1;
				temp2 = p->coef;
				p->coef = pre->coef;
				pre->coef = temp2;
			}
		}
	}
}
void sortlist2(LinkList& L)//对结果多项式进行降序排序
{
	int temp1 = 0;
	double temp2 = 0;
	for (Lnode* p = L->next; p; p = p->next)//选择排序
	{
		for (Lnode* pre = p->next; pre; pre = pre->next)
		{
			if (p->expn < pre->expn)
			{
				temp1 = p->expn;
				p->expn = pre->expn;
				pre->expn = temp1;
				temp2 = p->coef;
				p->coef = pre->coef;
				pre->coef = temp2;
			}
		}
	}
}
void add(LinkList La, LinkList Lb)//两个项式加法
{
	Lnode* ha, * hb, * pa, * pb;
	ha = La;//指向La头结点
	hb = Lb;//指向Lb头结点
	pa = ha->next;//指向La头结点的下一个结点
	pb = hb->next;//指向Lb头结点的下一个结点
	int a = 0;
	int b = 0;
	double sum = 0;
	while (pa && pb)//当pa与pb任何一个为空则循环结束代表已经遍历完其中一个表
	{
		a = pa->expn;//记录La当前结点的指数
		b = pb->expn;//记录Lb当前结点的指数
		if (a < b)//若La当前结点指数小于Lb当前结点的指数
		{
			ha = pa;
			pa = pa->next;
		}//跳到La当前结点的下一个进行比较
		if (a == b)//若La当前结点等于Lb当前结点
		{
			sum = pa->coef + pb->coef;//将两个链表当前结点的系数相加
			if (sum != 0)//当sum不为零
			{
				pa->coef = sum;
				ha = pa;
			}//将sum的值赋给表La当前结点系数的位置
			else
			{
				ha->next = pa->next;
				delete pa;
			}//若sum为0则删除当前La结点并往下进行
			hb->next = pb->next;
			delete pb;
			pb = hb->next;
			pa = ha->next;//表Lb也往下一个结点进行
		}
		if (a > b)//若La当前结点大于于Lb当前结点
		{
			hb->next = pb->next;
			pb->next = ha->next;
			ha->next = pb;
			pb = hb->next;
		}//将Lb当前结点插入到La当前结点之前
	}
	if (pb != NULL)//剩下没有遍历的Lb中的结点说明指数都大与前面的结点所以直接链接到La表的尾部
	{
		ha->next = pb;
		delete hb;//删除Lb表的头结点
	}
}
void sub(LinkList La, LinkList Lb)//两个项式减法 
{
	Lnode* ha, * hb, * pa, * pb;
	ha = La;//指向La头结点
	hb = Lb;//指向Lb头结点
	pa = ha->next;//指向La头结点的下一个结点
	pb = hb->next;//指向Lb头结点的下一个结点
	int a = 0;
	int b = 0;
	double sum = 0;
	while (pa && pb)//当pa与pb任何一个为空则循环结束代表已经遍历完其中一个表
	{
		a = pa->expn;//记录La当前结点的指数
		b = pb->expn;//记录Lb当前结点的指数
		if (a < b)//若La当前结点指数小于Lb当前结点的指数
		{
			ha = pa;
			pa = pa->next;
		}//跳到La当前结点的下一个进行比较
		if (a == b)//若La当前结点等于Lb当前结点
		{
			sum = pa->coef - pb->coef;//将两个链表当前结点的系数相减
			if (sum != 0)
			{
				pa->coef = sum;
				ha = pa;
			}//将sum的值赋给表La当前结点系数的位置
			else
			{
				ha->next = pa->next;
				delete pa;
			}
			hb->next = pb->next;
			delete pb;
			pb = hb->next;
			pa = ha->next;//表Lb也往下一个结点进行
		}
		if (a > b)
		{
			pb->coef = -pb->coef;//先将Lb当前结点的系数变为负数
			hb->next = pb->next;
			pb->next = ha->next;
			ha->next = pb;
			pb = hb->next;
		}//将Lb当前结点插入到La当前结点之前
	}
	while(pb != NULL)//若Lb还没遍历到空则先循环将剩下结点的系数转为负数
	{
		ha->next = pb;
		pb->coef = -pb->coef;
		ha = pb;
		pb = pb->next;
	}//剩下没有遍历的Lb中的结点说明指数都大与前面的结点所以直接链接到La表的尾部
	delete hb;//删除Lb表的头结点
}
void output(LinkList& L,int n)//输出链表内容
{
	Lnode* p;
	p = L->next;
	int len = n;
	while (p != NULL)
	{
		//控制输出结果为一元多项式的形式
		if (len >= 1&&len < n)
		{
			if (p->coef > 0)
			{
            cout << " + ";
			}
		}
		cout << p->coef << "X^" << p->expn<<" ";
		len--;
		p = p->next;
	}
}
int LinkLength(LinkList L)//求链表长度
{
	int i = 0;
	Lnode* p;
	p = L->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
int  main()
{
	cout << "~~~~~~~~~数据结构课程设计~~~~~~~~~" << endl;
	cout << "~~~~~~~~~一元多项式的计算~~~~~~~~~" << endl;
	cout << "~~~~~~~~~ 建立一元多项式 ~~~~~~~~~" << endl;
	cout << "从键盘输入多项式，并以文件形式存储" << endl;
	cout << "实现两个多项式相加,并建立输出多项式" << endl;
	cout << "实现两个多项式相减,并建立输出多项式" << endl;
	cout << "        按照以下提示输入数据       " << endl;
	int i = 0, n = 0, m = 0, t = 0,len = 0;
	double a[20] = { 0 };
	int b[20] = { 0 };
	//文件操作
	FILE* fp1, * fp2, * fp3, * fp4;//文件操作
	fp1= fopen("D://text1.txt", "w");
	fp2= fopen("D://text2.txt", "w");//将两个一元多项式保存到文件当中 
	fp3= fopen("D://text1.txt", "r");
	fp4= fopen("D://text2.txt", "r");//将两个一元多项式读取
	cout << "输入第一组一元多项式的数量" << endl;
	cin >> n;
	cout << "输入第一组一元多项式" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (i = 0; i < n; i++)
	{ 
		fprintf(fp1, "%lf %d ", a[i], b[i]);
	}
	fclose(fp1);
	fp1 = NULL;
	cout << "输入第一组二元多项式的数量" << endl;
	cin >> m;
	cout << "输入第一组二元多项式" << endl;
	for (i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (i = 0; i < m; i++)
	{
		fprintf(fp2, "%lf %d ", a[i], b[i]);
	}
	fclose(fp2);
	fp2 = NULL;
	//初始化链表并向其赋值
	LinkList La;
	La = CreatList(fp3, n);//调用函数创建链表并赋值
	len = LinkLength(La);//求链表的长度
	sortlist2(La);//降序排序
	cout << "降序输出表La"<<endl;
	output(La, len);//输出表La
	cout << endl;
	LinkList Lb;
	Lb = CreatList(fp4,m);//调用函数创建链表并赋值
	len = LinkLength(Lb);//求链表的长度
	sortlist2(Lb);//降序排序
	cout << "降序输出表Lb"<<endl;
	output(Lb, len);//输出表Lb
	cout << endl;
	sortlist1(La);//对链表进行升序排序
	sortlist1(Lb);//对链表进行升序排序方便对链表进行一元多项式相加或相减
	cout << "1.一元多项式加法" << endl;
	cout << "2.一元多项式减法" << endl;
	cin >> t;//选择模式
	if (t == 1)
	{
	add(La, Lb);//一元多项式加法
	}
	if (t == 2)
	{
	sub(La, Lb);//一元多项式减法
	}
	sortlist1(La);
	len=LinkLength(La);//求合成后的链表的长度
	output(La,len);//输出一元多项式结果
	return 0;
}
/*
3
3 1
2 6
4 5
3
2 5
7 8
2 1


3
3 1
5.6 5
9.3 3
3
1 3
5.6 5
3 2



3
32767 32767
32767 32767
32767 32767
3
32767 32767
32767 32767
32767 32767


4
2.89 1
9.63 8
445 5
999.85 100
4
2.06 125
70.89 105
25.25 1
1568.45 7
*/
