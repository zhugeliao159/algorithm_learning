#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Linked_List
{
    int num;
    Linked_List *Next;
};

//创建新节点
struct Linked_List* createNode(int data)
{
    struct Linked_List* newNode=(struct Linked_List*)malloc(sizeof(struct Linked_List));
    if(newNode==NULL)
    {
        cout<<"内存分配失败"<<endl;
        exit(1);
    }
    newNode->num=data;
    newNode->Next=NULL;
    return newNode;
}


//头节点为空的链表
//生成一个链表
struct Linked_List* List_Generate(int length,int MIN,int MAX)
{
    struct Linked_List* Head=(struct Linked_List*)malloc(sizeof(struct Linked_List)); 
    int i=0,temp;
    struct Linked_List* p=Head;
    while(i++<length)
    {
        temp=rand()%(MAX-MIN)+MIN;
        p->Next=createNode(temp);
        p=p->Next;
    }
    return Head;
}

//显示链表
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


//反转链表
struct Linked_List* flip_List(struct Linked_List*Head)
{
    struct Linked_List *pre=NULL,*head=NULL,*next=NULL;
    head=Head->Next;
    while(head!=NULL)
    {
        next=head->Next;
        head->Next=pre;
        pre=head;
        head=next;
    }
    struct Linked_List *New_Head=(struct Linked_List*)malloc(sizeof(struct Linked_List));
    New_Head->Next=pre;
    return New_Head;
}


//链表基础部分
int main()
{
    srand((unsigned int)time(NULL));
    struct Linked_List* head=List_Generate(10,1,20);
    cout<<"显示创建的随机链表"<<endl;
    Disp_List(head);
    head=flip_List(head);
    cout<<"显示反转后的链表"<<endl;
    Disp_List(head);
    return 0;
}