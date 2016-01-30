#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class STUDENT
{
private:
    string NAME;
    int ID;
public:
    void set_NAME(char*);
    string get_NAME(void);
    void set_ID(int);
    int get_ID(void);
};

void STUDENT::set_NAME(char *str)
{
    NAME = str;
}

void STUDENT::set_ID(int id)
{
    this->ID = id;
}

int STUDENT::get_ID(void)
{
    return ID;
}

string STUDENT::get_NAME(void)
{
    return this->NAME;
}

void MY_SORT(STUDENT s[], int n)    //From A~Z by Dic
{
    int i, j, MAX;
    STUDENT temp;
    for(i=n-1;i>0;i--)
    {
        MAX = i;
        for(j=0;j<i;j++)
        {
            if( s[j].get_NAME() > s[MAX].get_NAME() )
            {
                MAX = j;
            }
        }
        if(MAX!=i)
        {
            temp = s[i];
            s[i] = s[MAX];
            s[MAX] = temp;
        }
    }
}

int main(void)
{
    STUDENT STU[5];
    int ID;
    char NAME[30];
    int i;
    for(i=0;i<5;i++)
    {
        cout << "Please enter the Name of the student " << i+1 << ": ";
        cin.getline(NAME,29);
        STU[i].set_NAME(NAME);
        STU[i].set_ID(i+1);
    }

    MY_SORT(STU,5);

    for(i=0;i<5;i++)
    {
        cout << setw(3) << right << STU[i].get_ID();
        cout << " " << setw(8) << right << STU[i].get_NAME();
        cout << "\n";
    }
    return 0;
}
