#include <iostream>
using namespace std;
#include <string.h>  
#include <cstdlib>
#include <ctime>

// ���������������
int* generateRandomIntArray(int length, int minValue, int maxValue) 
{
    if (length <= 0 || minValue > maxValue) return nullptr;

    int* arr = new int[length];
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // �����������

    for (int i = 0; i < length; ++i) {
        arr[i] = minValue + std::rand() % (maxValue - minValue + 1);
    }
    return arr;
}

//��ʾ����
void Show_Arr(int *arr,int length)
{
    for(int i=0;i<length;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

//��������
void insertSort(int arr[],int leng)
{
    for(int i=1;i<leng;i++)
    {
        for(int j=i-1;j>=0&&arr[j+1]<arr[j];j--)
        {
            int temp;
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}


//�ж�һ�����Ƿ������������С���������������
bool exist_erfen(int arr[],int num,int length)
{
    if(arr==NULL||length ==0)
        return false;
    
    int l=0,r=length-1,m;
    
    while(l<=r)
    {
        m=(l+r)>>1;
        if(arr[m]==num)
            return true;
        else if(arr[m]<num)
            l=m+1;
        else
            r=m-1;
    }
    return false;
}

//������������
bool Search_O1(int arr[],int num,int length)
{
    if(arr==NULL||length==0)
    return false;
    return false;
}


//������������������ڵ���ĳһ��ֵ�ĵ�һ������λ��,���û�з���-1
int binary_search_ceiling(int arr[],int num,int length)
{
    if(arr==NULL||length==0)
        return false;
    int ans=-1;
    int l=0,r=length-1,m=0;
    while(l<=r)
    {
        m=(l+r)>>1;
        if(arr[m]>=num)
        {
            ans=m;
            r=m-1;
        }
        else
            l=m+1;
    } 
    return ans;
}

//����������������С�ڵ���ĳһ��ֵ�ĵ�һ������λ��,���û�з���-1
int binary_search_Threshold(int arr[],int num,int length)
{
    if(arr==NULL||length==0)
        return false;
    int ans=-1;
    int l=0,r=length-1,m=0;
    while(l<=r)
    {
        m=(l+r)>>1;
        if(arr[m]>num)
            r=m-1;
        else
        {
            ans=m;
            l=m+1;
        }
    } 
    return ans;
}


int main()
{
    //���鳤��
    bool res;
    int length=10,target;
    int *arr=generateRandomIntArray(length,1,20);
    insertSort(arr,length);
    Show_Arr(arr,length);
    target=1+rand() % (20- 1 + 1);
    cout<<"ҪѰ�ҵ�ֵΪ"<<target<<endl;
    cout<<"��ʼ�����������Ƿ���Ŀ��ֵ"<<endl;
    res=exist_erfen(arr,target,length);
    res?cout<<"Ŀ��ֵ��������"<<endl:cout<<"Ŀ��ֵ����������"<<endl;
    cout<<"��һ����������"<<endl;

    
    //���������Ҵ��ڵ���Ŀ��ֵ�������
    cout<<"��ʼ������С��Ŀ��ֵ������������"<<endl;
    int res2;
    res2=binary_search_ceiling(arr,target,length);
    if(res2!=-1)
        cout<<"Ŀ��ֵ��Ӧ������Ϊ"<<res2<<endl;
    else
        cout<<"������û�в�С��Ŀ��ֵ����"<<endl;
    cout<<"�ڶ�����������"<<endl;


    //����������С�ڵ���Ŀ��ֵ�����ұ�
    cout<<"��ʼ����������Ŀ��ֵ������������"<<endl;
    int res3;
    res3=binary_search_Threshold(arr,target,length);
    if(res3!=-1)
        cout<<"Ŀ��ֵ��Ӧ������Ϊ"<<res3<<endl;
    else
        cout<<"������û�в�����Ŀ��ֵ����"<<endl;
    cout<<"��������������"<<endl;

    return 0;
}
