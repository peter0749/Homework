#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class STUDENT
{
public:
    string name;
    int id, score;
};

int main(void)
{
    int num;
    int i;
    cout << "Number of students: ";
    cin >> num;

    if(num<1)   return -1;

    STUDENT *ptr;
    ptr = new STUDENT[num];
    for(i=0;i<num;i++)
    {
        cout << "The " << i+1 << "th student(id name score): ";
        cin >> ptr->id >> ptr->name >> ptr->score;
        ptr++;
    }

    ptr-=num;

    for(i=0;i<num;i++)
    {
        cout << setw(3) << right << ptr->id;
        cout << setw(15) << right << ptr->name;
        cout << setw(5) << right << ptr->score;
        cout << "\n";
        ptr++;
    }

    ptr-=num;

    delete ptr;

    return 0;
}
