#include<iostream>

using namespace std;
int main()
{

int array[10];
cout<<"Enter array"<<endl;
for(int i=0;i<10;i++)//for loop for entering array;
{
cin>>array[i];
}
int anyno,y,x=0;
cout<<"             "<<endl;
cout<<"Enter no which you want to search in array"<<endl;
cin>>anyno;
for(int j=0;j<10;j++)
{
if (anyno==array[j])
{x=x+1;}// x work as counter ;


}
cout<<"I found "<<x<<" times"<<endl;

return 0;
}
