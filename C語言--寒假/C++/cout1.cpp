#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(void)
{
    char bookname[]="Cout練習";
    int num=123;
    double df=0.3;
    cout<<bookname<<"這是第二個字串\n";
    cout<<"整數:"<<num<<"\n\n";
    cout<<"浮點數:"<<df<<"\n\n";
    cout<<"Enter any key to exit";
    getchar();
    return 0;
}
