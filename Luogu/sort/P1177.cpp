/*
    快速排序
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int Partition(int *arr, int low, int high)
{  
    int pivot = arr[(low+high)/2];
    swap(arr[(low+high)/2],arr[low]);
    while(low < high)
    {
        while(low <high&& arr[high] >= pivot)
            high--;
        arr[low] = arr[high];
        while(low < high&& arr[low] <= pivot)
            low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void quicksrot(int *arr,int low,int high)
{
    if(low < high)
    {
        int pivot = Partition(arr, low, high);
        quicksrot(arr,low,pivot-1);
        quicksrot(arr,pivot+1,high);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i < n;i++)
    {
        cin>>arr[i];
    }
    quicksrot(arr,0,n-1);
    for(int i=0;i < n;i++)
        cout<<arr[i]<<" ";
    return 0;
}