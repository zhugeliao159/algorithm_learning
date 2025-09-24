#include <iostream>
using namespace std;
#include <string.h>  
#include <cstdlib>
#include <ctime>

// 生成随机整数数组
int* generateRandomIntArray(int length, int minValue, int maxValue) 
{
    if (length <= 0 || minValue > maxValue) return nullptr;

    int* arr = new int[length];
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // 设置随机种子

    for (int i = 0; i < length; ++i) {
        arr[i] = minValue + std::rand() % (maxValue - minValue + 1);
    }
    return arr;
}

//显示数组
void Show_Arr(int *arr,int length)
{
    for(int i=0;i<length;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

//插入排序
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


//判断一个数是否在有序数组中————二分搜索
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

//遍历数组搜索
bool Search_O1(int arr[],int num,int length)
{
    if(arr==NULL||length==0)
    return false;
    return false;
}


//二分搜索有序数组大于等于某一个值的第一个数的位置,如果没有返回-1
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

//二分搜索有序数组小于等于某一个值的第一个数的位置,如果没有返回-1
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
    //数组长度
    bool res;
    int length=10,target;
    int *arr=generateRandomIntArray(length,1,20);
    insertSort(arr,length);
    Show_Arr(arr,length);
    target=1+rand() % (20- 1 + 1);
    cout<<"要寻找的值为"<<target<<endl;
    cout<<"开始搜索数组中是否有目标值"<<endl;
    res=exist_erfen(arr,target,length);
    res?cout<<"目标值在数组中"<<endl:cout<<"目标值不在数组中"<<endl;
    cout<<"第一轮搜索结束"<<endl;

    
    //二分搜索找大于等于目标值的最左边
    cout<<"开始搜索不小于目标值数的最左索引"<<endl;
    int res2;
    res2=binary_search_ceiling(arr,target,length);
    if(res2!=-1)
        cout<<"目标值对应的索引为"<<res2<<endl;
    else
        cout<<"数组中没有不小于目标值的数"<<endl;
    cout<<"第二轮搜索结束"<<endl;


    //二分搜索找小于等于目标值的最右边
    cout<<"开始搜索不大于目标值数的最右索引"<<endl;
    int res3;
    res3=binary_search_Threshold(arr,target,length);
    if(res3!=-1)
        cout<<"目标值对应的索引为"<<res3<<endl;
    else
        cout<<"数组中没有不大于目标值的数"<<endl;
    cout<<"第三轮搜索结束"<<endl;

    return 0;
}
