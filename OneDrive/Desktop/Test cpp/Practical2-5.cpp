#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Loan
{
    private:
    int loanID;
    string applicantName;
    float loanAmount;
    float interestRate;
    int loanTerm;
    public:
    Loan()
    {
        loanID=0;
        applicantName="N/A";
        loanAmount=0.0;
        interestRate=0.0;
        loanTerm=0;
    }
    Loan(int id,string name,float amount,float rate,int term)
    {
        loanID=id;
        applicantName=name;
        loanAmount=amount;
        interestRate=rate;
        loanTerm=term;
    }


    int calculateEMI()
    {
        float P=loanAmount;
        float R=interestRate/(12*100);
        int T=loanTerm;
        float EMI;
        EMI=(P*R*pow(1+R,T))/(pow(1+R,T)-1);
        cout<<"EMI="<<EMI;
        return EMI;
    }
    void display()
    {
        cout<<"Loan ID is="<<loanID<<endl;
        cout<<"Applicant Name is="<<applicantName<<endl;
        cout<<"Loan Amount is="<<loanAmount<<endl;
        cout<<"Interest Rate is="<<interestRate<<endl;
        cout<<"Loan Term is="<<loanTerm<<endl;
    }
};
int main()
{
    Loan l1;
    l1.display();
    l1.calculateEMI();


    cout<<"\n";
    Loan l2(1234,"John",5000,5.5,60);
    l2.display();
    l2.calculateEMI();
    cout<<"\n";

    return 0;
}
