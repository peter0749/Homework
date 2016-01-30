#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class student
{
private:
    static int counter;
public:
    int weight, height;
    student()
    {
        weight = height = 0;
        counter++;
    }
    student(int w, int h)
    {
        weight = w;
        height = h;
        counter++;
    }
    static void getObjectNum()
    {
        cout << "Generate " << counter << " objects" << "\n\n";
    }
};

int student::counter = 0;

int main(void)
{
    student peter;
    peter.weight = 65;
    peter.height = 165;
    cout << peter.weight << "\n" << peter.height << "\n";
    student::getObjectNum();

    student david(70,180);
    cout << david.weight << "\n" << david.height << "\n";
    david.getObjectNum();

    return 0;
}
