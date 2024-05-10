#include<iostream>
#include<cstddef>
using namespace std;
struct Node
{
	int key;
	Node *next;
};
void adHead(Node *&pHead,int data);
void adLast(Node *&pHead,int data);
void getList(Node *pHead);
void removeHead(Node *&pHead);
void removeLast(Node *&Last);
void adAfterX(Node *pHead,int data,int x);
void removeAfterX(Node *&pHead,int x);
bool findX(Node *pHead,int x);

Node *newNode(int data);
int main()
{Node *pHead=new Node;
//delete pHead;
	adHead(pHead,1);
	adHead(pHead,2);
	adHead(pHead,3);
	adHead(pHead,4);
	cout<<"truoc khi them\n";
	getList(pHead);
	cout<<"sau khi them\n";
	adAfterX(pHead,5,3);
	getList(pHead);
//	adLast(pHead,6);
//	adLast(pHead,7);
//	getList(pHead);
//	removeHead(pHead);
//	getList(pHead);
	
	
}
void adHead(Node *&pHead,int data)
{
	Node *tam=new Node;
	tam->key=data;
	tam->next=NULL;
	if(pHead==NULL)
	pHead=tam;
	else 
	{
		tam->next=pHead;
		pHead=tam;
	}
}
void getList(Node *pHead)
{
	while(pHead!=NULL)
	{
		cout<<"\n"<<pHead->key;
		pHead=pHead->next;
	}
}
void adLast(Node *&pHead,int data)
{
	
	if(pHead==NULL)
	pHead=newNode(data);
	else 
	{
	while(pHead->next!=NULL)
	pHead=pHead->next;
	pHead->next=newNode(data);	
	}	
}
Node *newNode(int data){
	Node *tam=new Node;
	tam->key=data;
	tam->next=NULL;
	return tam;
}
void removeHead(Node *&pHead)
{
	if(pHead==NULL)
	cout<<"danh sach rong";
	else
	{
	Node *tam=new Node;
	tam=pHead;
	pHead=tam->next;
	delete tam;}	
}
bool findX(Node *pHead,int x)
{
	while (pHead!=NULL)
	{
		if(pHead->key==x)
		break;
		else
		{
			pHead=pHead->next;
		}
	}
	if(pHead!=NULL)
	return true;
	else
	return false;
}
void adAfterX(Node *pHead,int data,int x)
{
Node *temp=new Node();
temp->key=data;
temp->next=NULL;
	if(findX(pHead,x)==true)
	{
		while(pHead->key!=x)
		{pHead=pHead->next;}
		temp->next=pHead->next;
		pHead->next=temp;
	}	
}
void removeAfterX(Node *pHead,int x)
{
	if(findX(pHead,x)==true)
	{
	  while(pHead->key!=x)
	  {while(pHead->next->key!=x)
	  	pHead=pHead->next;}
	  	Node *temp=pHead->next;
	  	pHead->next=pHead->next->next;
	  	delete temp;
	  
	  	
	}
}
//xoa phan tu dau,cuoi,xoa phan tu x
//xoa toan bo danh sach
//dem so luong node/phan tu trong danh sach 
