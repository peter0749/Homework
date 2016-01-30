#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class student
{
private:
    int height, weight;
public:
    void show(int, int);
};

void student::show(int h, int w)
{
    this->height = h;
    this->weight = w;
    cout << this->height << "\n" << this->weight << "\n";
}

int main(void)
{
    student peter;
    peter.show(180,75);

    return 0;
}
