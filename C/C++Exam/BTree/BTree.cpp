#include <stdio.h>
#include <string>
#include <CString>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#define MAXLINE 100

typedef struct employee
{
	char *name;
	int pay;
	struct employee * llink;
	struct employee * rlink;
} TreeNode;

class BTree
{
private:
	TreeNode * root;
	TreeNode * ptr;
public:
	BTree();
	bool Add_Tree(TreeNode tmp_node);
	void Parse_Tree(const char choice);
	void in_order(TreeNode * ptr);
	void pre_order(TreeNode * ptr);
	void post_order(TreeNode * ptr);

};

BTree::BTree()
{
//	root=new TreeNode;
//	root->llink=root->rlink=NULL;
	root=NULL;
}

bool BTree::Add_Tree(TreeNode tmp_node)
{
	TreeNode * node;
	TreeNode * prev;
	TreeNode * bnode;
	int length;
	node=root;
	bnode=new TreeNode;
	length=strlen(tmp_node.name);
	bnode->name=new char[length+1];
	strcpy(bnode->name,tmp_node.name);
	bnode->pay=tmp_node.pay;
	bnode->llink=bnode->rlink=NULL;
	if(node==NULL)
	{	
		root=bnode;
		return true;
	}
	while(node!=NULL)	
	{
		prev=node; //something wrong
		if(tmp_node.pay < node->pay)
			node = node->llink;
		else
			node = node->rlink;		
	}
	if(tmp_node.pay < prev->pay)
		prev->llink = bnode;
	else
		prev->rlink = bnode;
}

void BTree::in_order(TreeNode * ptr)
{
	if(ptr!=NULL)
	{
		in_order(ptr->llink);
		cout<<"Name: "<<ptr->name<<" Pay: "<<ptr->pay<<endl;
		in_order(ptr->rlink);
	}
}

void BTree::pre_order(TreeNode * ptr)
{
	if(ptr!=NULL)
	{
		cout<<"Name: "<<ptr->name<<" Pay: "<<ptr->pay<<endl;
		pre_order(ptr->llink);
		pre_order(ptr->rlink);
		
	}
}

void BTree::post_order(TreeNode * ptr)
{
		if(ptr!=NULL)
	{
		post_order(ptr->llink);
		post_order(ptr->rlink);
		cout<<"Name: "<<ptr->name<<" Pay: "<<ptr->pay<<endl;
	}
}

void BTree::Parse_Tree(const char choice)
{
	switch(choice)
	{
	case 'I':
		in_order(root);
		break;
	case 'P':
		pre_order(root);
		break;
	case 'O':
		post_order(root);
		break;
	}
}
int main(void)
{
	string ifile="btree.s01";
	string ofile="btree.w01";
	int length=0;
	int j=0;
	int payment;
	ifstream fin;
	ofstream fout;

	BTree employee_btree;
	fin.open(ifile.c_str(), ios_base::in);
	fout.open(ofile.c_str(), ios_base::binary);
	TreeNode inode;
	char temp[MAXLINE];
	while(fin.good())
	{
		fin.getline(temp,MAXLINE);
		cout<<"TEMP: " << temp<<endl;
		if(((temp[0]>='A')&&(temp[0]<='Z')) || ((temp[0]>='a')&&(temp[0]<='z'))) //literal
		{
			length=strlen(temp);
			inode.name=new char[length+1];
			//for(j=0;j<length;j++) inode.name[j]='\0';
			strcpy(inode.name, temp);
			inode.llink=NULL;
			inode.rlink=NULL;
		} else //payment
		{
			inode.pay = atoi(temp);
			employee_btree.Add_Tree(inode);			
		}
		
	}

    cout<<"******** InOrder *********"<<endl;
	employee_btree.Parse_Tree('I');
	cout<<"******** PreOrder *********"<<endl;
	employee_btree.Parse_Tree('P');
	cout<<"******** PostOrder *********"<<endl;
	employee_btree.Parse_Tree('O');

	fin.close();
	fout.close();
	system("pause");
	return 0;
}