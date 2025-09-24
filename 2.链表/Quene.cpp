#include <iostream>
using namespace std;
//链表数据结构的创建和操作


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//用链表的形式进行队列创建和操作

//队列节点
struct Node
{
    int val;
    struct Node* Next;
};
//队列结构体
struct Quene
{
    Node *front;//头节点
    Node *rear;//尾节点
};

/// @brief  创建一个节点 
struct Node* Node_Generate(int val)
{
    struct Node* new_Node=(struct Node*)malloc(sizeof(struct Node));    
    new_Node->Next=NULL;
    new_Node->val=val;
    return new_Node;
}

/// @brief 创建队列
struct Quene* Quene_Genereate(void)
{
    struct Quene* new_Quene=(struct Quene*)malloc(sizeof(struct Quene));
    new_Quene->front=NULL;
    new_Quene->rear=NULL;
    return new_Quene;
}


/// @brief 检测队列是否为空
/// @param quene 队列
/// @return 为空返回1，否则返回0
bool Quene_is_empty(struct Quene*quene)
{
    if(quene->front==NULL)
        return true;
    else
        return false;
}

/// @brief 插入队列进值,从rear插入
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
        cout<<"队列空了,无法离队"<<endl;
        return;
    }

    struct Node *temp_Node=quene->front;
    quene->front=quene->front->Next;
    delete(temp_Node);
}


/// @brief 打印队列
/// @param quene 
void printQuene(struct Quene*quene)
{
    if(Quene_is_empty(quene))
    {
        cout<<"队列为空"<<endl;
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
//以数组的形式创建链表,前提必须是链表的最大长度已知,这样就可以用数组来建立了
struct Quene_array
{
    //这个数据结构必须提前知道队列最大长度，然后我们开辟的数组要相等或者比它大一点
    int *array=new int[100];
    int front;//队列头部
    int rear;//队列尾部
};

/// @brief 队列创建
struct Quene_array* Quene_create_array()
{
    struct Quene_array *Quene_new=(struct Quene_array*)malloc(sizeof(struct Quene_array));
    Quene_new->front=0;
    Quene_new->rear=0;    
    return Quene_new;
}

/// @brief 检测队列是否为空捏
/// @param quene 
/// @return 为1表示队列为空
bool Quene_is_empty_array(struct Quene_array* quene)
{
    if(quene->front==quene->rear)
        return 1;
    else
        return 0;
}
/// @brief 队列的进队
/// @param quene 
/// @param val 
void enquene(struct Quene_array*quene,int val)
{
    quene->array[quene->rear]=val;
    quene->rear++;
}

/// @brief 队列的出队
/// @param quene 
void dequene(struct Quene_array *quene)
{
    if(Quene_is_empty_array(quene))
    {
        cout<<"别走了，队列要爆了呜呜呜"<<endl;
        return;
    }
    quene->front++;
}

/// @brief 队列的打印
/// @param quene 
void printQuene_array(struct Quene_array *quene)
{
    if(Quene_is_empty_array(quene))
    {
        cout<<"队列为空"<<endl;
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
    cout<<"第一次打印队列"<<endl;
    printQuene(quene1);
    Quene_Out(quene1);
    cout<<"第二次打印队列"<<endl;
    printQuene(quene1);
    Quene_Out(quene1);
    cout<<"第三次打印队列"<<endl;
    printQuene(quene1);
    Quene_Insert(quene1,16);
    cout<<"第四次打印队列"<<endl;
    printQuene(quene1);
    Quene_Out(quene1);
    Quene_Out(quene1);
    Quene_Out(quene1);
    cout<<"第五次打印队列"<<endl;
    printQuene(quene1);
    Quene_Out(quene1);

    //创建数组队列
    struct Quene_array *quene2=Quene_create_array();
    enquene(quene2,7);
    enquene(quene2,4);
    enquene(quene2,6);
    cout<<"开始数组队列的打印"<<endl;
    cout<<"开始第一次打印"<<endl;
    printQuene_array(quene2);
    dequene(quene2);
    cout<<"开始第二次打印"<<endl;
    printQuene_array(quene2);
    enquene(quene2,11);
    cout<<"开始第三次打印"<<endl;
    dequene(quene2);
    dequene(quene2);
    dequene(quene2);
    cout<<"开始第四次打印"<<endl;
    printQuene_array(quene2);
    dequene(quene2);


    
}