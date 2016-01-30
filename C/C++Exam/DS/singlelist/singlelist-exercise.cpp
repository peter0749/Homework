#include <stdio.h>
#include <iostream>
#include <fcntl.h>
#include <fstream>
struct single_node
{      
  int node_num;
  int node_sum;
  char * data;
  struct single_node * list;
       };
typedef single_node Single_List;
typedef Single_List * single_node_list;
class singlelist
{
    
      };
int main(void)
{
    using namespace std;
    string infile  = "920204.s01";
    string outfile = "920204.w01";
    fstream fin;
    fin.open(infile.c_str(), ios_base::in);
    string temp;
    fin >> temp;
    while(fin.good())
    {
      cout<<"input : " << temp << endl;
      fin >> temp;
                     
                     }
    fin.close();
    system("pause");
    return 0;
}
