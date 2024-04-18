#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
typedef struct Lnode
{
	double coef;//ϵ��
	int expn;//ָ��
	Lnode* next;//ָ����һ��������
}Lnode, * LinkList;//�����������
LinkList CreatList(FILE* fp,int n)//��ʼ��������������������������
{
	int i = 0;
	char ch = 0;
	double co = 0;
	int ex = 0;
	LinkList L =(Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
	LinkList p;
	p = L;
	for(i = 0 ; i < n ; i++)//β�巨��������
	{
		Lnode* q = (Lnode*)malloc(sizeof(Lnode));
		fscanf(fp, "%lf %d ", &co, &ex);//���ļ��н�����д��������
		q->coef = co;
		q->expn = ex;
		q->next = NULL;
		p->next = q;
		p = q;   
	}            
	return (L);  
}
void sortlist1(LinkList& L)//���������������ʽ��������
{
	int temp1 = 0;
	double temp2 = 0;
	for (Lnode* p = L->next; p; p = p->next)//ѡ������
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
void sortlist2(LinkList& L)//�Խ������ʽ���н�������
{
	int temp1 = 0;
	double temp2 = 0;
	for (Lnode* p = L->next; p; p = p->next)//ѡ������
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
void add(LinkList La, LinkList Lb)//������ʽ�ӷ�
{
	Lnode* ha, * hb, * pa, * pb;
	ha = La;//ָ��Laͷ���
	hb = Lb;//ָ��Lbͷ���
	pa = ha->next;//ָ��Laͷ������һ�����
	pb = hb->next;//ָ��Lbͷ������һ�����
	int a = 0;
	int b = 0;
	double sum = 0;
	while (pa && pb)//��pa��pb�κ�һ��Ϊ����ѭ�����������Ѿ�����������һ����
	{
		a = pa->expn;//��¼La��ǰ����ָ��
		b = pb->expn;//��¼Lb��ǰ����ָ��
		if (a < b)//��La��ǰ���ָ��С��Lb��ǰ����ָ��
		{
			ha = pa;
			pa = pa->next;
		}//����La��ǰ������һ�����бȽ�
		if (a == b)//��La��ǰ������Lb��ǰ���
		{
			sum = pa->coef + pb->coef;//����������ǰ����ϵ�����
			if (sum != 0)//��sum��Ϊ��
			{
				pa->coef = sum;
				ha = pa;
			}//��sum��ֵ������La��ǰ���ϵ����λ��
			else
			{
				ha->next = pa->next;
				delete pa;
			}//��sumΪ0��ɾ����ǰLa��㲢���½���
			hb->next = pb->next;
			delete pb;
			pb = hb->next;
			pa = ha->next;//��LbҲ����һ��������
		}
		if (a > b)//��La��ǰ��������Lb��ǰ���
		{
			hb->next = pb->next;
			pb->next = ha->next;
			ha->next = pb;
			pb = hb->next;
		}//��Lb��ǰ�����뵽La��ǰ���֮ǰ
	}
	if (pb != NULL)//ʣ��û�б�����Lb�еĽ��˵��ָ��������ǰ��Ľ������ֱ�����ӵ�La���β��
	{
		ha->next = pb;
		delete hb;//ɾ��Lb���ͷ���
	}
}
void sub(LinkList La, LinkList Lb)//������ʽ���� 
{
	Lnode* ha, * hb, * pa, * pb;
	ha = La;//ָ��Laͷ���
	hb = Lb;//ָ��Lbͷ���
	pa = ha->next;//ָ��Laͷ������һ�����
	pb = hb->next;//ָ��Lbͷ������һ�����
	int a = 0;
	int b = 0;
	double sum = 0;
	while (pa && pb)//��pa��pb�κ�һ��Ϊ����ѭ�����������Ѿ�����������һ����
	{
		a = pa->expn;//��¼La��ǰ����ָ��
		b = pb->expn;//��¼Lb��ǰ����ָ��
		if (a < b)//��La��ǰ���ָ��С��Lb��ǰ����ָ��
		{
			ha = pa;
			pa = pa->next;
		}//����La��ǰ������һ�����бȽ�
		if (a == b)//��La��ǰ������Lb��ǰ���
		{
			sum = pa->coef - pb->coef;//����������ǰ����ϵ�����
			if (sum != 0)
			{
				pa->coef = sum;
				ha = pa;
			}//��sum��ֵ������La��ǰ���ϵ����λ��
			else
			{
				ha->next = pa->next;
				delete pa;
			}
			hb->next = pb->next;
			delete pb;
			pb = hb->next;
			pa = ha->next;//��LbҲ����һ��������
		}
		if (a > b)
		{
			pb->coef = -pb->coef;//�Ƚ�Lb��ǰ����ϵ����Ϊ����
			hb->next = pb->next;
			pb->next = ha->next;
			ha->next = pb;
			pb = hb->next;
		}//��Lb��ǰ�����뵽La��ǰ���֮ǰ
	}
	while(pb != NULL)//��Lb��û������������ѭ����ʣ�½���ϵ��תΪ����
	{
		ha->next = pb;
		pb->coef = -pb->coef;
		ha = pb;
		pb = pb->next;
	}//ʣ��û�б�����Lb�еĽ��˵��ָ��������ǰ��Ľ������ֱ�����ӵ�La���β��
	delete hb;//ɾ��Lb���ͷ���
}
void output(LinkList& L,int n)//�����������
{
	Lnode* p;
	p = L->next;
	int len = n;
	while (p != NULL)
	{
		//����������ΪһԪ����ʽ����ʽ
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
int LinkLength(LinkList L)//��������
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
	cout << "~~~~~~~~~���ݽṹ�γ����~~~~~~~~~" << endl;
	cout << "~~~~~~~~~һԪ����ʽ�ļ���~~~~~~~~~" << endl;
	cout << "~~~~~~~~~ ����һԪ����ʽ ~~~~~~~~~" << endl;
	cout << "�Ӽ����������ʽ�������ļ���ʽ�洢" << endl;
	cout << "ʵ����������ʽ���,�������������ʽ" << endl;
	cout << "ʵ����������ʽ���,�������������ʽ" << endl;
	cout << "        ����������ʾ��������       " << endl;
	int i = 0, n = 0, m = 0, t = 0,len = 0;
	double a[20] = { 0 };
	int b[20] = { 0 };
	//�ļ�����
	FILE* fp1, * fp2, * fp3, * fp4;//�ļ�����
	fp1= fopen("D://text1.txt", "w");
	fp2= fopen("D://text2.txt", "w");//������һԪ����ʽ���浽�ļ����� 
	fp3= fopen("D://text1.txt", "r");
	fp4= fopen("D://text2.txt", "r");//������һԪ����ʽ��ȡ
	cout << "�����һ��һԪ����ʽ������" << endl;
	cin >> n;
	cout << "�����һ��һԪ����ʽ" << endl;
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
	cout << "�����һ���Ԫ����ʽ������" << endl;
	cin >> m;
	cout << "�����һ���Ԫ����ʽ" << endl;
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
	//��ʼ���������丳ֵ
	LinkList La;
	La = CreatList(fp3, n);//���ú�������������ֵ
	len = LinkLength(La);//������ĳ���
	sortlist2(La);//��������
	cout << "���������La"<<endl;
	output(La, len);//�����La
	cout << endl;
	LinkList Lb;
	Lb = CreatList(fp4,m);//���ú�������������ֵ
	len = LinkLength(Lb);//������ĳ���
	sortlist2(Lb);//��������
	cout << "���������Lb"<<endl;
	output(Lb, len);//�����Lb
	cout << endl;
	sortlist1(La);//�����������������
	sortlist1(Lb);//����������������򷽱���������һԪ����ʽ��ӻ����
	cout << "1.һԪ����ʽ�ӷ�" << endl;
	cout << "2.һԪ����ʽ����" << endl;
	cin >> t;//ѡ��ģʽ
	if (t == 1)
	{
	add(La, Lb);//һԪ����ʽ�ӷ�
	}
	if (t == 2)
	{
	sub(La, Lb);//һԪ����ʽ����
	}
	sortlist1(La);
	len=LinkLength(La);//��ϳɺ������ĳ���
	output(La,len);//���һԪ����ʽ���
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
