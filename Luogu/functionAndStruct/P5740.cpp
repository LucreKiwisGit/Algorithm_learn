/*
    最厉害的学生
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int student_num;
    cin>>student_num;
    char best_student_name[10];
    int best_student_scores = -1;
    int best_scores[5];
    for(int i=1;i <= student_num;i++)
    {
        char student_name[10];
        cin>>student_name;
        int chinese_scores,english_scores,math_scores;
        cin>>chinese_scores>>math_scores>>english_scores;
        if(best_student_scores < chinese_scores + english_scores + math_scores)
        {
            strcpy(best_student_name, student_name);
            best_scores[1] = chinese_scores;
            best_scores[2] = math_scores;
            best_scores[3] = english_scores;
            best_student_scores = best_scores[1] + best_scores[2] + best_scores[3];
        }
    }
    cout<<best_student_name<<" "<<best_scores[1]<<" "<<best_scores[2]<<" "<<best_scores[3];
    return 0;
}

#
paddle_lite_opt --model_file=model.pdmodel --param_file=model.pdiparams --valid_targets=arm --optimize_out=yolov3_opt