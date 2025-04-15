#include<iostream>
using namespace std;
class Rectangle_room
{
   private:
   int length;
   int width;
   public:
   void setDimensions(int l,int w)
   {
    cout<<"Enter the length=";
    cin>>length;
    cout<<"Enter the width=";
    cin>>width;
   }
   void area()
   {
    int area;
    area=(length*width);
    cout<<"Area="<<area<<endl;
   }
   void Perimeter()
   {
    int per;
    per=2*(length+width);
    cout<<"Perimeter="<<per;
   }
};
int main()
{
    int l,w;
    Rectangle_room p1,p2;
    cout<<"For p1"<<endl;
    p1.setDimensions(l,w);
    p1.area();
    p1.Perimeter();
    cout<<"\n";
    cout<<"For p2"<<endl;
    p2.setDimensions(l,w);
    p2.area();
    p2.Perimeter();

    return 0;
}
