#include <iostream>
#include<algorithm>
using namespace std;
int tmp[500001];
void display(int arr[],int len)
{
    for(int i=0;i<len;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
//选择排序
void select_sort(int arr[],int len)
{
    for(int i=0;i<len-1;i++)
    {
        int min=i;
        for(int j=i+1;j<len;j++)
            if(arr[j]<arr[min])
                min=j;
        swap(arr[i],arr[min]);
    }
}
//优化选择排序
void opt_select_Sort(int args[],int len)
{
    int start=0;
    int end=len-1;
    while(start<end)
    {
        int min=start,max=end;
        for(int i=start;i<end;i++)
        {
            if(args[i]<args[min])
                min=i;
            if(args[i]>args[max])
                max=i;
        }
        swap(args[start],args[min]);
        swap(args[end],args[max]);
        start++;
        end--;
    }
}
//冒泡排序
void bubbleSort(int args[],int len)
{
    for(int i=1;i<len;i++)
        for(int j=0;j<len-i;j++)
            if(args[j+1]<args[j])
                swap(args[j+1],args[j]);
}
//合并排序
void merge(int a[],int l,int m,int r)//合并子序列
{
   int i=l,k=l,j=m+1;
   while(i<=m&&j<=r)
   {
       if(a[i]<a[j])
           tmp[k++]=a[i++];
       else
           tmp[k++]=a[j++];
   }
   //排序剩下的
   while(i<=m)tmp[k++]=a[i++];
   while(j<=r)tmp[k++]=a[j++];
   for(int i=l;i<=r;i++)
       a[i]=tmp[i];
}
//归并排序
void mergeSort(int a[],int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
//快速排序

void quickSort(int arr[],int left,int right)
{
    if(left>right)
        return;
    int standard=arr[left];
    int i=left,j=right;
    while(i!=j)
    {
        while(i<j&&arr[j]>=standard)
            j--;
        while(i<j&&arr[i]<=standard)
            i++;
        if(i<j)
        swap(arr[i],arr[j]);
    }
    swap(arr[i],arr[left]);
    quickSort(arr,left,i-1);
    quickSort(arr,i+1,right);
}

//插入排序
void insertSort(int arr[],int len) {
    for (int i = 1; i < len; i++) { //插入排序一般从原数组的第二个元素进行比较，默认第一个元素已经是排好序的，
        if (arr[i] < arr[i - 1]) {  //当前方已经排好序的元素比当前元素大时，用temp临时变量存储
            int temp = arr[i];
            int j;
            for (j = i - 1; j >= 0 && arr[j] > temp; j--) {    //检查前面所有已经排好的元素
                arr[j + 1] = arr[j];//所有元素往后挪动一位
            }
            arr[j + 1] = temp;//将temp里的值复制到插入位置
        }
    }
}
int T;
double startTime;

void init()
{
    startTime=clock();
    T=20;
}
void dis(int a[],int len)
{
    for(int i=0;i<len;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int size=100000;
    int arr[size];
    //选择排序
    init();
    while(T--)
    {
        for(int i=0;i<size;i++)
            arr[i]=rand();
        select_sort(arr,size);
    }
    cout<<"Time of selectSort:"<<(clock()-startTime)/20<<endl;

    //优化后
    init();
    while(T--)
    {
        for(int i=0;i<size;i++)
            arr[i]=rand();
        opt_select_Sort(arr,size);
    }
    cout<<"Time of opt_selectSort:"<<(clock()-startTime)/20<<endl;

    //冒泡排序
    init();
    while(T--)
    {
        for(int i=0;i<size;i++)
            arr[i]=rand();
        bubbleSort(arr,size);
    }
    cout<<"Time of bubbleSort:"<<(clock()-startTime)/20<<endl;

    //归并排序
    init();
    while(T--)
    {
        for(int i=0;i<size;i++)
            arr[i]=rand();
        mergeSort(arr, 0, size-1);
    }
    cout<<"Time of mergeSort:"<<(clock()-startTime)/20<<endl;

    //快速排序
    init();
    while(T--)
    {
        for(int i=0;i<size;i++)
            arr[i]=rand();
        quickSort(arr, 0, size-1);
    }
    cout<<"Time of quickSort:"<<(clock()-startTime)/20<<endl;

    //插入排序
    init();
    while(T--)
    {
        for(int i=0;i<size;i++)
            arr[i]=rand();
        insertSort(arr,size);
    }
    cout<<"Time of insertSort:"<<(clock()-startTime)/20<<endl;
}
