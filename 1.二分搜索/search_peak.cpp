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

    return arr; // ע��: ��Ҫ������ delete[] �ͷ�
}


/// @brief ��������:�ҵ����������ڲ��ظ�����������һ������ֵ��Ӧ������.����ֵ�Ķ���:�����������ߵ������Ҵ����ұߵ�����
/// @param arr ����
/// @param length ���鳤��
/// @return ��һ��ֵ
int Find_Peak_binary_search(int arr[],int length)
{
    //������Ͳ�����
    if(arr==NULL||length==0)
        return -1;
    //�������ֻ��һ��ֵ,���������������Ҫ���ֵ
    if(length==1)
        return 0;
    //�����һ��ֵ�ȵڶ���ֵ��,�������Ǽ���ֵ
    if(arr[0]>arr[1])
        return 0;
    //������һ��ֵ��ǰһ��ֵ��,�������Ǽ���ֵ
    if(arr[length-1]>arr[length-2])
        return length-1;
    
    //�������ֽ���,��ʼ��ƪ
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


    //��ʼѰ�ҷ�ֵ
    int ans=Find_Peak_binary_search(arr,length);
    if(ans==-1)
        cout<<"����Ϊ�ջ�������㷨����"<<endl;
    else
    {
        cout<<"�ҵ�����ֵ������Ϊ"<<ans<<endl;
        if(ans!=0&&ans!=length-1)
            cout<<"��Ӧ������ֵ�ֱ�Ϊ["<<arr[ans-1]<<' '<<arr[ans]<<' '<<arr[ans+1]<<']'<<endl;
    }

    delete[] arr; // �ͷ��ڴ�

    return 0;    
}