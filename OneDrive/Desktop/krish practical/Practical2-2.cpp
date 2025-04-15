#include<iostream>
using namespace std;
class Student
{
   public:
   int rollNumber;
   string name;
   int marks[3];
   Student()
   {
     rollNumber=0,name="N/A";
   }
   Student(int r,string n,int m[])
   {
    rollNumber=r;


    name=n;
    marks[0]=m[0];
    marks[1]=m[1];
    marks[2]=m[2];
   }
   void details()
     {
     cout<<"Student's name:"<<name<<endl;
     cout<<"Student's roll number:"<<rollNumber<<endl;
     cout<<"Student's marks:"<<marks[0]<<" "<<marks[1]<<" "<<marks[2]<<"
"<<endl;
   }
   float avg()
   {
    int sum=0;
    for(int i=0;i<3;i++)
    {
      sum+=marks[i];
    }
      float average;
      average=sum/3;
      cout<<"Average="<<average<<endl;
      return average;
   }
};
int main()
{
    Student p1;
    p1.details();
    int a[]={50,80,90};
    Student p2(68,"Prince",a);
    p2.details();
    cout<<"Average="<<p2.avg()<<endl;

    return 0;
}
