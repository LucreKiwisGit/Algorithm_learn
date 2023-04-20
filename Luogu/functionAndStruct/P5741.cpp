/*
    旗鼓相当的对手 - 加强版

*/
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct{
    int chinese_grade,math_grade,english_grade;
    int scores;
    string name;
}student;

//降序
bool operator<(student &a, student &b)
{
    return a.scores > b.scores;
}

bool cmp_dict(string name_a, string name_b)
{
    if(name_a > name_b)
    {
        
    }
}

int main()
{
    vector<student> students;
    int n;
    scanf("%d",&n);
    for(int i=1;i <= n;i++)
    {
        student new_student;
        scanf("%s %d %d %d",&new_student.name,&new_student.chinese_grade,&new_student.math_grade,&new_student.english_grade);
        new_student.scores = new_student.chinese_grade + new_student.math_grade + new_student.english_grade;
        students.push_back(new_student);
    }
    sort(students.begin(),students.end());
    for(int i=0;i < students.size();i++)
    {
        for(int j = i + 1;j < students.size();j++)
        {
            if(students[j].scores > students[i].scores + 10)
                break;
            if(abs(students[j].chinese_grade- students[i].chinese_grade) <= 5)
                if(abs(students[j].math_grade- students[i].math_grade) <= 5)
                    if(abs(students[j].english_grade- students[i].english_grade) <= 5)
                        printf("%s %s\n",students[i].name,students[j].name);
        }
    }
    return 0;

}