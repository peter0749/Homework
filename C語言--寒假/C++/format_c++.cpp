#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{
    cout << "==For BaseField==";
    cout << "\nIn base 10\n";
    cout << 12345 ;
    cout << "\nIn base 8\n";
    cout.setf(ios::oct, ios::basefield);
    cout << 12345;
    cout.setf(ios::hex, ios::basefield);
    cout << "\nIn base 16\n";
    cout << 12345;
    cout.unsetf(ios::basefield);
    cout.setf(ios::showbase);
    cout.setf(ios::oct,ios::basefield);
    cout << "\nIn base 8\n" << 12345;
    cout.setf(ios::hex, ios::basefield);
    cout << "\nIn base 16\n" << 12345 << endl;
    cout.unsetf(ios::basefield);
    cout.unsetf(ios::showbase);

    cout << showbase << hex << 12345 << endl;
    cout << noshowbase;

    cout << endl << "==For Toupper==" << endl;
    cout << uppercase << showbase << hex << 2047 << endl;
    cout << nouppercase << noshowbase;

    cout << "\n==For Floating Point==\n";
    cout << 3.1415926 << "\n";
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(11);
    cout << 3.1415926 << endl;
    cout << setprecision(3) << 3.1415926 << endl;
    cout.setf(ios::scientific, ios::floatfield);
    cout << 3.1415926 << endl;
    cout.unsetf(ios::floatfield);

    cout << "==For Bool==" << endl;
    cout << true << endl;
    cout.setf(ios::boolalpha);
    cout << true << endl;
    cout.unsetf(ios::boolalpha);

    cout << "==For showpos==" << endl;
    cout << +123.123456 << endl;
    cout << -123.123456 << endl;
    cout.setf(ios::showpos);
    cout << +123.123456 << endl;
    cout << -123.123456 << endl;
    cout.unsetf(ios::showpos);

    cout << "==For Format==" << endl;
    cout.fill('*');
    cout.width(30);
    cout.setf(ios::left, ios::adjustfield);
    cout << "C++ test" <<endl;
    //cout.width(30);
    //cout.setf(ios::right, ios::adjustfield);
    //cout.unsetf(ios::adjustfield);
    cout << setfill('#') << setw(30) << right << "C++ test" << endl;
    cout.unsetf(ios::adjustfield);

    return 0;
}
