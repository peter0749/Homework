#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// prints the cube of integer n
void PrintCube(int n)
{
    cout << n * n * n << " " ;
}

int main()
{
    const int VECTOR_SIZE = 8 ;

    // Define a template class vector of integers
    typedef vector<int > IntVector ;

    //Define an iterator for template class vector of integer
    typedef IntVector::iterator IntVectorIt ;

    IntVector Numbers(VECTOR_SIZE) ;   //vector containing numbers

    IntVectorIt start, end, it ;

    int i ;

    // Initialize vector Numbers
    for (i = 0; i < VECTOR_SIZE; i++)
        Numbers[i] = i + 1 ;

    start = Numbers.begin() ;   // location of first
                                // element of Numbers

    end = Numbers.end() ;       // one past the location
                                // last element of Numbers

    // print content of Numbers
    cout << "Numbers { " ;
    for(it = start; it != end; it++)
        cout << *it << " " ;
    cout << " }\n" << endl ;

    // for each element in the range [first, last)
    // print the cube of the element
    for_each(start, end, PrintCube) ;
    cout << "\n\n" ;
    system("pause");
    return 0;
}
