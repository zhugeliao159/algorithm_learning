#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Linked_List
{
    int num;
    Linked_List *Next;
};

//�����½ڵ�
struct Linked_List* createNode(int data)
{
    struct Linked_List* newNode=(struct Linked_List*)malloc(sizeof(struct Linked_List));
    if(newNode==NULL)
    {
        cout<<"�ڴ����ʧ��"<<endl;
        exit(1);
    }
    newNode->num=data;
    newNode->Next=NULL;
    return newNode;
}

//����һ����������
struct Linked_List* createSortNode(int length,int min,int max)
{
    if(length<=0||min>max)
        return NULL;
    struct Linked_List* head=createNode(0);
    struct Linked_List* p=head;
    for(int i=0;i<length;i++)
    {
        int newValue=rand()%(max-p->num)+p->num;
        p->Next=createNode(newValue);
        p=p->Next;
    }
    return head;
}

//��ʾ����
void Disp_List(struct Linked_List*Head)
{
    Linked_List* p=Head;
    while(p->Next!=NULL)
    {
        cout<<p->Next->num<<' ';
        p=p->Next;
    }
    cout<<endl;
}





/// @brief �ϲ���������,���ǵ�һ���Լ����,�õ���˫ָ����Ա���Լ�������
struct Linked_List* Merge_SortList(struct Linked_List*P1,struct Linked_List *P2)
{
    struct Linked_List* head=createNode(0);
    struct Linked_List* p=head;
    P1=P1->Next;
    P2=P2->Next;

    while(P1!=NULL&&P2!=NULL)
    {
        if(P1->num<P2->num)
        {
            p->Next=P1;
            P1=P1->Next;
            p=p->Next;
        }
        else
        {
            p->Next=P2;
            P2=P2->Next;
            p=p->Next;
        }
    }
    if(P1==NULL)
        p->Next=P2;
    else
        p->Next=P1;
    return head;
}



/// @brief �ϲ��������飬�������ĺ�ĵڶ��ַ���,������
struct Linked_List* Merge_SortList2(struct Linked_List*P1,struct Linked_List *P2)
{
    struct Linked_List* head=P1->Next->num>P2->Next->num?P2:P1;
    struct Linked_List* cur1=head->Next->Next;//��ǰ�����������һ��
    struct Linked_List* cur2=head==P1?P2->Next:P1->Next;//��һ���������һ��
    struct Linked_List* pre=head->Next;//��¼������
    while(cur1!=NULL&&cur2!=NULL)
    {
        if(cur1->num<=cur2->num)
        {
            pre->Next=cur1;
            cur1=cur1->Next;
        }
        else
        {
            pre->Next=cur2;
            cur2=cur2->Next;
        }
        pre=pre->Next;
    }
    pre->Next=cur1==NULL?cur2:cur1;
    return head;
}

int main()
{
    srand((unsigned int)time(NULL));
    struct Linked_List* P1=createSortNode(5,1,100);
    cout<<"��ʾ��������1:"<<endl;
    Disp_List(P1);
    struct Linked_List* P2=createSortNode(7,1,100);
    cout<<"��ʾ��������2:"<<endl;
    Disp_List(P2);
    struct Linked_List* P3=Merge_SortList2(P1,P2);
    cout<<"�ϲ������������Ϊ"<<endl;
    Disp_List(P3);

    
    return 0;
}

