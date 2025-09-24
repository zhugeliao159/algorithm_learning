#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

int* generateArray(int length, int minValue, int maxValue) {
    if (minValue > maxValue) std::swap(minValue, maxValue);
    if (length <= 0) return nullptr;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int* arr = new int[length];
    arr[0] = minValue + std::rand() % (maxValue - minValue + 1);

    for (int i = 1; i < length; i++) {
        int value;
        do {
            value = minValue + std::rand() % (maxValue - minValue + 1);
        } while (value == arr[i - 1]);
        arr[i] = value;
    }

    return arr; // 注意: 需要调用者 delete[] 释放
}


/// @brief 函数作用:找到无序且相邻不重复数组中任意一个极大值对应的索引.极大值的定义:这个数大于左边的数组且大于右边的数组
/// @param arr 数组
/// @param length 数组长度
/// @return 任一峰值
int Find_Peak_binary_search(int arr[],int length)
{
    //空数组就不管了
    if(arr==NULL||length==0)
        return -1;
    //如果数组只有一个值,那他本身就是我们要求得值
    if(length==1)
        return 0;
    //如果第一个值比第二个值大,那它就是极大值
    if(arr[0]>arr[1])
        return 0;
    //如果最后一个值比前一个值大,那他就是极大值
    if(arr[length-1]>arr[length-2])
        return length-1;
    
    //特例部分结束,开始正篇
    int  l=1,r=length-2,m=0;
    while(l<=r)
    {
        m=l+((r-l)>>1);
        cout<<m;
        if(arr[m]>arr[m-1]&&arr[m]>arr[m+1])
            return m;
        else if(arr[m]<arr[m-1])
        {
            r=m-1;
        }
        else 
        {
            l=m+1;
        }
    }
    return -1;
}


int main()
{
    int length = 20;
    int* arr = generateArray(length, 1, 20);

    std::cout << "Generated array: ";
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    //开始寻找峰值
    int ans=Find_Peak_binary_search(arr,length);
    if(ans==-1)
        cout<<"数组为空或者你的算法错了"<<endl;
    else
    {
        cout<<"找到极大值的索引为"<<ans<<endl;
        if(ans!=0&&ans!=length-1)
            cout<<"对应的三个值分别为["<<arr[ans-1]<<' '<<arr[ans]<<' '<<arr[ans+1]<<']'<<endl;
    }

    delete[] arr; // 释放内存

    return 0;    
}