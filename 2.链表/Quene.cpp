#include <iostream>
using namespace std;
//�������ݽṹ�Ĵ����Ͳ���


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//���������ʽ���ж��д����Ͳ���

//���нڵ�
struct Node
{
    int val;
    struct Node* Next;
};
//���нṹ��
struct Quene
{
    Node *front;//ͷ�ڵ�
    Node *rear;//β�ڵ�
};

/// @brief  ����һ���ڵ� 
struct Node* Node_Generate(int val)
{
    struct Node* new_Node=(struct Node*)malloc(sizeof(struct Node));    
    new_Node->Next=NULL;
    new_Node->val=val;
    return new_Node;
}

/// @brief ��������
struct Quene* Quene_Genereate(void)
{
    struct Quene* new_Quene=(struct Quene*)malloc(sizeof(struct Quene));
    new_Quene->front=NULL;
    new_Quene->rear=NULL;
    return new_Quene;
}


/// @brief �������Ƿ�Ϊ��
/// @param quene ����
/// @return Ϊ�շ���1�����򷵻�0
bool Quene_is_empty(struct Quene*quene)
{
    if(quene->front==NULL)
        return true;
    else
        return false;
}

/// @brief ������н�ֵ,��rear����
/// @param quene 
/// @param num 
void Quene_Insert(struct Quene *quene,int num)
{
    struct Node *new_Node=Node_Generate(num);
    if(Quene_is_empty(quene))
    {
        quene->front=new_Node;
        quene->rear=new_Node;
    }
    else
    {
        quene->rear->Next=new_Node;
        quene->rear=quene->rear->Next;
    }
}

void Quene_Out(struct Quene *quene)
{
    if(quene->front==NULL)
    {
        cout<<"���п���,�޷����"<<endl;
        return;
    }

    struct Node *temp_Node=quene->front;
    quene->front=quene->front->Next;
    delete(temp_Node);
}


/// @brief ��ӡ����
/// @param quene 
void printQuene(struct Quene*quene)
{
    if(Quene_is_empty(quene))
    {
        cout<<"����Ϊ��"<<endl;
        return;
    }
    struct Node *p=quene->front;

    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->Next;
    }
    cout<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//���������ʽ��������,ǰ��������������󳤶���֪,�����Ϳ�����������������
struct Quene_array
{
    //������ݽṹ������ǰ֪��������󳤶ȣ�Ȼ�����ǿ��ٵ�����Ҫ��Ȼ��߱�����һ��
    int *array=new int[100];
    int front;//����ͷ��
    int rear;//����β��
};

/// @brief ���д���
struct Quene_array* Quene_create_array()
{
    struct Quene_array *Quene_new=(struct Quene_array*)malloc(sizeof(struct Quene_array));
    Quene_new->front=0;
    Quene_new->rear=0;    
    return Quene_new;
}

/// @brief �������Ƿ�Ϊ����
/// @param quene 
/// @return Ϊ1��ʾ����Ϊ��
bool Quene_is_empty_array(struct Quene_array* quene)
{
    if(quene->front==quene->rear)
        return 1;
    else
        return 0;
}
/// @brief ���еĽ���
/// @param quene 
/// @param val 
void enquene(struct Quene_array*quene,int val)
{
    quene->array[quene->rear]=val;
    quene->rear++;
}

/// @brief ���еĳ���
/// @param quene 
void dequene(struct Quene_array *quene)
{
    if(Quene_is_empty_array(quene))
    {
        cout<<"�����ˣ�����Ҫ����������"<<endl;
        return;
    }
    quene->front++;
}

/// @brief ���еĴ�ӡ
/// @param quene 
void printQuene_array(struct Quene_array *quene)
{
    if(Quene_is_empty_array(quene))
    {
        cout<<"����Ϊ��"<<endl;
        return;
    }
    for(int i=quene->front;i<quene->rear;i++)
    {
        cout<<quene->array[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    struct Quene *quene1=Quene_Genereate();
    Quene_Insert(quene1,1);
    Quene_Insert(quene1,3);
    Quene_Insert(quene1,5);
    Quene_Insert(quene1,9);
    cout<<"��һ�δ�ӡ����"<<endl;
    printQuene(quene1);
    Quene_Out(quene1);
    cout<<"�ڶ��δ�ӡ����"<<endl;
    printQuene(quene1);
    Quene_Out(quene1);
    cout<<"�����δ�ӡ����"<<endl;
    printQuene(quene1);
    Quene_Insert(quene1,16);
    cout<<"���Ĵδ�ӡ����"<<endl;
    printQuene(quene1);
    Quene_Out(quene1);
    Quene_Out(quene1);
    Quene_Out(quene1);
    cout<<"����δ�ӡ����"<<endl;
    printQuene(quene1);
    Quene_Out(quene1);

    //�����������
    struct Quene_array *quene2=Quene_create_array();
    enquene(quene2,7);
    enquene(quene2,4);
    enquene(quene2,6);
    cout<<"��ʼ������еĴ�ӡ"<<endl;
    cout<<"��ʼ��һ�δ�ӡ"<<endl;
    printQuene_array(quene2);
    dequene(quene2);
    cout<<"��ʼ�ڶ��δ�ӡ"<<endl;
    printQuene_array(quene2);
    enquene(quene2,11);
    cout<<"��ʼ�����δ�ӡ"<<endl;
    dequene(quene2);
    dequene(quene2);
    dequene(quene2);
    cout<<"��ʼ���Ĵδ�ӡ"<<endl;
    printQuene_array(quene2);
    dequene(quene2);


    
}