#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class student
{
public:
    int id, score;
    string name;
};

int main(void)
{
    student stu[5];
    int i;
    for(i=0;i<5;i++)
    {
        cout << "Please enter the score and name of student " << i+1 << " : ";
        cin >> stu[i].score >> stu[i].name;
        stu[i].id = i+1;
    }

    for(i=0;i<5;i++)
    {
        cout << setw(3) << right << stu[i].id;
        cout << " " << setw(8) << right << stu[i].name;
        cout << " " << setw(4) << right << stu[i].score;
        cout << "\n";
    }
    return 0;
}
