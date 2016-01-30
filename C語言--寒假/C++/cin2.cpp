#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define LEN 30
using namespace std;

int main(void)
{
    char bkname[LEN];
    int price;
    double discount;
    cout<<"Book Name: ";
    cin.getline(bkname,LEN-1);
    cout<<"Price: ";
    cin>>price;
    cout<<"Discount: ";
    cin>>discount;
    cout<<"\nFollowing is the result: \n";
    cout<<"Book: "<<bkname<<"\n";
    cout<<"Discount: "<<discount<<"\n";
    cout<<"Price: "<<price<<"\n";
    cout<<"Total: "<<price*discount<<"\n";

    return 0;
}
