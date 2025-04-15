#include<iostream>
#include<string>
using namespace std;
class Management
{
   public:


   int ID;
   string Name;
   int quantity;
   float Price;
   public:
   void Data()
   {
    cout<<"Enter the ID of product=";
    cin>>ID;
    cout<<"Enter the product Name=";
    cin>>Name;
    cout<<"Enter the product quantity=";
    cin>>quantity;
    cout<<"Enter price=";
    cin>>Price;
   }
   void cost()
   {
    int product;
    cout<<"Enter additional quantity to add:";
    cin>>product;
    quantity+=product;
   }
   void display()

   {
    int totalcost=Price*quantity;
    cout<<"Total cost="<<totalcost<<endl;

   }
};
int main()
{
    Management p1;
    p1.Data();
    p1.cost();
    p1.display();
    return 0;
}
