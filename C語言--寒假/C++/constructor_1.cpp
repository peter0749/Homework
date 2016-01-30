#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class student
{
private:
    int height, weight;
public:
    student();
    student(int,int);
    student(int);
    void setWeight(int);
    void setHeight(int);
    void getShow();
    ~student();
};

student::student()
{
    weight = 4;
    height = 50;
}

student::student(int w)
{
    setWeight(w);
    height = 50;
}

student::student(int w, int h)
{
    setWeight(w);
    setHeight(h);
}

student::~student()
{
    cout << "In destructor..." << "\n";
}

void student::setWeight(int w)
{
    weight = (w>4 ? w : 4);
}

void student::setHeight(int h)
{
    height = (h>50 ? h : 50);
}

void student::getShow(void)
{
    cout << "Height: " << height << "\n";
    cout << "Weight: " << weight << "\n";
}

int main(void)
{
    student peter;
    peter.getShow();
    student david(70);
    david.getShow();
    student john(60,180);
    john.getShow();

    return 0;
}
