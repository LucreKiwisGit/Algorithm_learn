/*
    查找
*/
#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;

int main()
{
    int number_num,serach_times;
    scanf("%d %d",&number_num, &serach_times);


    int list[number_num+1];
    for(int i=1;i <= number_num;i++)
        scanf("%d",&list[i]);


    int key;
    map<int, int> pos_key;

    for(int i=1;i <= serach_times;i++)
    {
        scanf("%d",&key);

        map<int, int>::iterator iter = pos_key.find(key);
        if(iter != pos_key.end()){
            printf("%d ",iter->second);
            continue;
        }

        int left = 1,right = number_num;
        int mid;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(list[mid] == key)
            {
                //需要检查是不是第一个出现的
                while(list[mid] == key && mid > 0)
                {
                    mid--;
                }
                printf("%d ",mid+1);
                pos_key[key] = mid + 1;
                break;
            }    
            if(list[mid] < key) left = mid + 1;
            else right = mid - 1;
        }
        if(left > right) printf("-1 ");
    }
    printf("\n");
    return 0;
}
