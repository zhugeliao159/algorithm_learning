#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



// 生成随机整数数组
int* generateRandomIntArray(int leng, int minValue, int maxValue) 
{
    if (leng <= 0 || minValue > maxValue) return nullptr;

    int* arr = new int[leng];
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // 设置随机种子

    for (int i = 0; i < leng; ++i) {
        arr[i] = minValue + std::rand() % (maxValue - minValue + 1);
    }
    return arr;
}

// 复制整型数组
int* copyIntArray(const int* source, int leng) {
    if (!source || leng <= 0) return nullptr;

    int* copy = new int[leng];
    for (int i = 0; i < leng; ++i) {
        copy[i] = source[i];
    }
    return copy;
}

// 比较两个整型数组是否完全相同
bool areArraysEqual(const int* arr1, const int* arr2, int length) {
    if (!arr1 || !arr2 || length <= 0) return false;

    for (int i = 0; i < length; ++i) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

//选择排序
void selectionSort(int arr[],int leng)
{
    for (int i=0;i<leng;i++)
    {
        //i~n-1，找到最小值放到i位置
        int temp,temp_index;
        temp_index=i;
        for(int j=i;j<leng;j++)
        {
            if(arr[temp_index]>arr[j])
            {
                temp_index=j;
            }
        }
        temp=arr[temp_index];
        arr[temp_index]=arr[i];
        arr[i]=temp;
    }
}

//冒泡排序
void bubbleSort(int arr[],int leng)
{
    for(int i=0;i<leng;i++)
    {
        for(int j=0;j<leng-i-1;j++)
        {
            int temp;
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
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

int main()
{
    int leng = 20;
    int minValue = 0;
    int maxValue = 100;
    for (int TestTimes=0;TestTimes<30;TestTimes++)
    {
        // 获取随机生成的数组
        int* arr = generateRandomIntArray(leng, minValue, maxValue);
        int* arr1 = copyIntArray(arr,leng);
        int* arr2 = copyIntArray(arr,leng);
        int* arr3 = copyIntArray(arr,leng);

        selectionSort(arr1,leng);
        bubbleSort(arr2,leng);
        insertSort(arr3,leng);
        if(!areArraysEqual(arr1,arr2,leng)||!areArraysEqual(arr2,arr3,leng))
        {
            cout<<"出错了"<<endl;

        }

        delete[] arr;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;

    }
    cout<<"测试结束"<<endl;





 
    // cout<<"冒泡排序结果:";
    // for (int i=0;i<length;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;



    // cout<<"插入排序结果:";
    // for (int i=0;i<length;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    
    return 0;
}