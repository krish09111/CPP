#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int superDigit(string n,int k)
{
    if(n.length()==1)
    {
        return (n[0]-'0');
    }
    string conc="";
    for(int i=0;i<k;i++)
    {
        conc += n;
    }
    long long sum=0;
    for(char i:conc)
    {
        sum = sum + i-'0';
    }
    return superDigit(to_string(sum),1);
}
int main()
{
    int k;
    string n;
    cout<<"enter a number  : "<<endl;
    cin>>n;
    cout<<"enter how many times you want to concate this number : "<<endl;
    cin>>k;
    cout<<"super digit of number " <<n<<" is : "<<superDigit(n,k)<<endl;
    return 0;
}

