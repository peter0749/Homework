#include <stdio.h>
#include <string>
#include <CString>
#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100
typedef struct graph_node
{
	int data;
	struct graph_node * link;

}GNode;

class GraphClass
{
private:
	GNode* GArray[MAX];
	int visited[MAX];
	const int GNode_num;
public:
	GraphClass(int gnum);
	void Build_Adjust_List(int size,int array[MAX][MAX]);
	GNode * find_last_node(GNode * glist);
	void Print_Adjust_List();
};

GraphClass::GraphClass(int gnum):GNode_num(gnum)
{
	int i;
//	GNode* ptr;
	for(i=1;i<=gnum;i++)
	{
		GArray[i]=new GNode;
		GArray[i]->data=i;
		GArray[i]->link=NULL;
		visited[i]=false;
   	}
}

void GraphClass::Build_Adjust_List(int size,int array[MAX][MAX])
{
	int i,j;
	GNode* ptr;
	GNode* last;
	for(i=1;i<=size;i++)
	{		
		for(j=1;j<=size;j++)
		{
			if(array[i][j]>0)
			{
				ptr=new GNode;
				ptr->data=j;
				ptr->link=NULL;
				last=find_last_node(GArray[i]);
				last->link=ptr;
			}
		}
	}
	
}

GNode * GraphClass::find_last_node(GNode * glist)
{
	GNode * prev;
	GNode * tlist;
	if(glist==NULL) return NULL;
	tlist=glist;
	while(tlist!=NULL)
	{
		prev=tlist;
		tlist=tlist->link;
	}
	return prev;

}

void GraphClass::Print_Adjust_List()
{
	GNode * tlist;
	int i;
	cout << "Head    adjacency nodes\n";
	cout << "------------------------------\n";
	for (i = 1; i <= GNode_num; i++) 
	{
		cout << "V" << GArray[i]->data << " ";
		tlist=GArray[i]->link;
		while(tlist!=NULL)
		{
			cout << "--> V" << tlist->data << " ";
			tlist=tlist->link;
		}
		cout<<endl;
	}


}
int main(void)
{
	string ifile="dfs.dat";
	string ofile="dfs.out";
	ifstream fin;
	ofstream fout;
	string temp;
	
	int i,j,itemp;
	fin.open(ifile.c_str(), ios_base::in);
	fout.open(ofile.c_str(), ios_base::binary);
    int node_size;
	fin>>node_size;
    int adjust[MAX][MAX];
    GraphClass adjust_graph(node_size);
	while(fin.good())
	{
		for(i=1;i<=node_size;i++)
		{			
			for(j=1;j<=node_size;j++)
			{
				fin>>temp;
				itemp=atoi(temp.c_str());
				adjust[i][j]=itemp;
              //  cout<<"("<<i<<" , "<<j<<" )= "<<temp<<"  "; 
				cout<<temp<<"  ";
			}
			cout<<endl;
		}
	}
	adjust_graph.Build_Adjust_List(node_size,adjust);
	adjust_graph.Print_Adjust_List();


	fin.close();
	fout.close();
	
	system("pause");
	return 0;
}