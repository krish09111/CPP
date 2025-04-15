#include<iostream>
#include<string>
using namespace std;
class InventoryItem
{
   private:
   int itemID;
   string itemName;
   float price;
   int quantity;
   public:
   InventoryItem()
   {
    price=0,quantity=0;
    cout<<"Enter itemID=";
    cin>>itemID;
    cout<<"Enter itemName=";
    cin>>itemName;
   }
   InventoryItem(int a,string b,float c,int d)
   {
    itemID=a;
    itemName=b;
    price=c;
    quantity=d;
   }
   void addStock(int qty)
   {
    cout<<"Enter add qty=";
    cin>>qty;
    quantity+=qty;
    cout<<"Total Item="<<quantity<<endl;
   }
   void sellItem(int qty)
     {
    cout<<"Enter sell qty=";
    cin>>qty;
    if(qty<=quantity)
    {
        quantity=quantity-qty;
          cout<<"Total Item="<<quantity<<endl;
    }
    else
    {
        cout<<"please enter valid number.";
    }
   }
   void display()
   {
        cout<<"Item ID="<<itemID<<endl;
        cout<<"Item Name="<<itemName<<endl;
        cout<<"Item price="<<price<<endl;
        cout<<"Item quantity="<<quantity<<endl;
   }
};
int main()
{
    int qty;
    InventoryItem
p1[2]={InventoryItem(24,"pen",10,10),InventoryItem(4543,"pencil",2,10)};
    cout<<"Item 1:"<<endl;
    p1[0].display();
    p1[0].addStock(qty);
    p1[0].sellItem(qty);
    cout<<"Item 2:"<<endl;
     p1[1].display();
    p1[1].addStock(qty);
    p1[1].sellItem(qty);

    return 0;
}

