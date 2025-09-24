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


//ͷ�ڵ�Ϊ�յ�����
//����һ������
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


//��ת����
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


//�����������
int main()
{
    srand((unsigned int)time(NULL));
    struct Linked_List* head=List_Generate(10,1,20);
    cout<<"��ʾ�������������"<<endl;
    Disp_List(head);
    head=flip_List(head);
    cout<<"��ʾ��ת�������"<<endl;
    Disp_List(head);
    return 0;
}