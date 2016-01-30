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
class SingleList
{
public:
	Single_Node * slist;
	int nodecounts;
	int nodevalue;
public:
	SingleList();
//	SingleList SingleList::operator<<(const SingleList & SList);
	bool SingleList::operator>(const SingleList & SList);
	bool SingleList::isNULL();
	SingleList & SingleList::operator++();
	SingleList & SingleList::PointTo(const SingleList & SList);
	SingleList & SingleList::operator<<(const Single_Node );

};
SingleList & SingleList::operator<<(const Single_Node SN)
{
	slist->link = SN.link;
	return *this;
};
SingleList::SingleList()
{
	nodecounts=0;
	nodevalue=0;
	slist->link=NULL;
	slist->node_num=0;
	slist->node_sum=0;
};

/*
SingleList SingleList::operator <<(const SingleList & SList)
{
                                                                                                                                                                                                                                                                                             	SingleList tempnode;
	return tempnode;
};
*/
bool SingleList::operator>(const SingleList & SList)
{
	return true;
};
bool SingleList::isNULL()
{
	if(slist->link==NULL) return true;
	else false;
};
SingleList & SingleList::operator ++()
{
	slist=slist->link;
	return *this;
};
SingleList & SingleList::PointTo(const SingleList & SList)
{
	slist=SList.slist->link;	
	return *this;
};
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
	Single_Node * tempnode;
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
	while(fin.good()) //將資料讀入串列
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
		innptr=current->link;
		int headdata=(int)strtod(current->data, &errmsg); 
		int temphead=headdata;
		while(innptr!=NULL)
		{
			int inndata=(int)strtod(innptr->data, &errmsg);
			if( inndata>headdata)
			{
				Single_Node * ListCurrent;
				ListArray[i]=new Single_Node; //new a ListArray
				length=strlen(current->data);
				ListArray[i]->data=new char[length+1];
				strcpy(ListArray[i]->data,current->data);
				ListArray[i]->link=NULL;
				ListCurrent = ListArray[i];
				sum=headdata+inndata;
				node_length+=2;

			//	node_length++;
			//	sum+=inndata;
				newnode=new Single_Node;  //new temp node
				length=strlen(innptr->data);
				newnode->data=new char[length+1]; 
				newnode->link=NULL;       //new temp link : to NULL
				strcpy(newnode->data,innptr->data); //copy list node data
				ListCurrent->link=newnode; //ArrayList link to the new node
				ListCurrent=ListCurrent->link; //travse to new insert point
				headdata=inndata; 
				tempnode=innptr->link;
				int tempinndata=inndata;
				while(tempnode!=NULL)
				{
					int tempdata=(int)strtod(tempnode->data, &errmsg);
					if(tempdata>inndata)
					{
						node_length++;
						sum+=tempdata;
						newnode=new Single_Node;
						length=strlen(tempnode->data);
						newnode->data=new char[length+1];
						
						newnode->link=NULL;
						strcpy(newnode->data,tempnode->data);
						ListCurrent->link=newnode;
						ListCurrent=ListCurrent->link;

						inndata=tempdata;
					}
					tempnode=tempnode->link;
				}
				inndata=tempinndata;
				ListArray[i]->node_num=node_length;
				ListArray[i]->node_sum=sum;
				node_length=0;
				sum=0;
				i++;
			} 
			
			innptr=innptr->link;
			headdata=temphead;
			
		}
		node_length=0;
		sum=0;
		current=current->link;
		
	}while(current!=NULL);

	int maxnode=0;
	int maxvalue=0;
	int max_index=0;
    maxnode=ListArray[0]->node_num;
	maxvalue=ListArray[0]->node_sum;
    SingleList testlist;	
        
	for(int j=0; j<i; j++)
	{		
		current=ListArray[j];
		if(current->node_num > maxnode)
		{
			max_index=j;
			maxnode=current->node_num;
			maxvalue=current->node_sum;
		}
		else if(current->node_num==maxnode)	
			if(current->node_sum > maxvalue)
			{
				max_index=j;
				maxnode=current->node_num;
				maxvalue=current->node_sum;
			}
		
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
    current=ListArray[max_index];
	cout << " The Longest List : " << endl;
    while(current!=NULL)
		{
			cout << current->data ;
			fout << current->data ;
			if(current->link!=NULL)
			{
				cout << " -> ";
				fout << "、";
			}
			current=current->link;			
		}
		cout << endl;	
	cout << "The Sum is : " << maxvalue << endl;
    
    delete newnode;
	system("pause");
	fin.close();
	fout.close();
	
	return 0;
}