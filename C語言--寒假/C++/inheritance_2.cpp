#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class studentA
{
public:
    int getmax(int , int);
};
int studentA::getmax(int a, int b)
{
    return a>b?a:b;
}

class studentB
{
public:
    void getf(int);
};
void studentB::getf(int n)
{
    int i, f0=0, f1=1, f2;
    for(i=0;i<n;i++)
    {
        f2 = f0 + f1;
        cout<<f2<<" ";
        f0 = f1;
        f1 = f2;
    }
    cout<<"\n";
}

class studentC:public studentA, public studentB
{
public:
    int getgcd(int , int);
};
int studentC::getgcd(int a, int b)
{
    return a%b ? this->getgcd(b,a%b) : b;
}

int main(void)
{
    studentC mary;
    cout<<mary.getmax(10,20)<<"\n";
    mary.getf(30);
    cout<<mary.getgcd(30,18)<<"\n";
    return 0;
}
