#include <stdio.h>
#include <iostream>
#include <fstream>
#include <CString>
#include <io.h>
#include <fcntl.h>

struct single_node
{   int node_num;
    int node_sum;
	char * data;
	struct single_node *link;
};
typedef single_node Single_Node;
typedef Single_Node *Single_Node_List;

int main(void)
{
	using namespace std;
	string ifile = "920204.s01";
	string ofile = "920204.w01";
	Single_Node * numlist=new Single_Node;
	Single_Node * current;
	Single_Node * innptr;
	Single_Node * newnode;
	Single_Node * ListArray[10];
	int node_length=0; 
	int sum=0;
  //  top->data="9";
	
	
	ifstream fin;
	ofstream fout;
	
	fin.open(ifile.c_str(),ios_base::in);
	fout.open(ofile.c_str(),ios_base::binary);
	current = numlist;
	char temp[100];
	fin >> temp;
    int length=strlen(temp);
	while(fin.good())
	{
		newnode=new Single_Node;
		newnode->data=new char[length+1];
		strcpy(newnode->data,temp);
		current->link=newnode;
		current=newnode;

		fin >> temp;
	}
	current->link=NULL;
	current=numlist->link;
	do
	{
		cout << "The data node: " << current->data << endl;
		current=current->link;
		
	}while(current->link!=NULL);
	cout << "The final data node: " << current->data << endl;
	current=numlist->link;
	int i=0;
	char * errmsg;
	do
	{
		Single_Node * ListCurrent;
		ListArray[i]=new Single_Node;
		length=strlen(current->data);
		ListArray[i]->data=new char[length+1];
		strcpy(ListArray[i]->data,current->data);
		ListArray[i]->link=NULL;
		ListCurrent = ListArray[i];
		innptr=current->link;
		int headdata=(int)strtod(current->data, &errmsg); 
        sum=headdata;
		node_length++;
		while(innptr!=NULL)
		{
			int inndata=(int)strtod(innptr->data, &errmsg);
			if( inndata>headdata)
			{
				node_length++;
				sum+=inndata;
				newnode=new Single_Node;
				length=strlen(innptr->data);
				newnode->data=new char[length+1];
				newnode->link=NULL;
				strcpy(newnode->data,innptr->data);
				ListCurrent->link=newnode;
				ListCurrent=ListCurrent->link;
				headdata=inndata;
				
			}
			
			innptr=innptr->link;
			
		}
		ListArray[i]->node_num=node_length;
		ListArray[i]->node_sum=sum;
		node_length=0;
		sum=0;
		current=current->link;
		i++;
	}while(current!=NULL);

	for(int j=0; j<i; j++)
	{
		current=ListArray[j];
		cout << "SubList[ " << j << " ]: "<<endl;
		cout << "Node num: " << current->node_num << endl;
		cout << "Node sum: " << current->node_sum << endl;
		while(current!=NULL)
		{
			cout << current->data << " -> ";
			current=current->link;			
		}
		cout << endl;	
		cout << "============================" << endl;
		
	}

    delete newnode;
	system("pause");
	fin.close();
	fout.close();
	
	return 0;
}