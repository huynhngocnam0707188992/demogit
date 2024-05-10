#include<iostream>
using namespace std;
struct Node
{
	int key;
	Node*left;
	Node*right;
 } ;
void addNode(Node *&root,int data );
void preOder(Node *root);
void inOder(Node *root);
void postder(Node *root);
 Node* newNode(int data);
void getNode(Node *root);
Node *deleteNode(Node* root,int x);
Node *findMinNode(Node *root);
Node *findNode(Node *root,int x); 
Node *xoayTrai(Node*root);
int main()
{
	Node *root=NULL;
	
	addNode(root,8);
    addNode(root,1);
    addNode(root,9);
    addNode(root,7);
    addNode(root,5);
    addNode(root,6);
    addNode(root,4);
    addNode(root,3);
    addNode(root,2);
    addNode(root,0);
    
    cout<<"\n inoder";
    inOder(root);
    cout<<"\n preoder";
    preOder(root);
    cout<<"\n postoder";
    postder(root);
	deleteNode(root,4);
	cout<<"\n sau xoa";
	inOder(root);
	cout<<"\n tim kiem ";
	Node* tam=findNode(root,6);
	cout<<tam->key;
	
	
	
	
	return 0;
}
Node *newNode(int data)
{
    Node* temp = new Node;
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void addNode(Node*& root,int data ){
	if(root== NULL )
	{
		root=newNode(data);
		
	}
	else
	if(root !=NULL)
	{
		if(data<root->key)
		{
			addNode(root->left,data);
		}
		else if(data>root->key)
		{
			addNode(root->right,data);
		}
		
	}
}
void getNode(Node* root)
{
	cout<<" "<<root->key;
}

void preOder(Node* root)
{
if(root!=NULL)
   {
	getNode(root);
	preOder(root->left);
	preOder(root->right);	
   }
	
}
void inOder(Node* root)
{
if(root!=NULL)
	 {
		inOder(root->left);
		getNode(root);
		inOder(root->right);
		return;
	 } 

	 
}
void postder(Node* root)
{
if(root!=NULL)
	{
		postder(root->left);
		postder(root->right);
		getNode(root);
	}

}
Node *findMinNode(Node *root)
{
	while(root->left != NULL)
	{
		root=root->left;
	}
	return root;
}
Node *deleteNode(Node* root,int x)
{
	if(root == NULL)
	  return root;
	else if(x<root->key)
	  root->left=deleteNode(root->left,x);
	else if(x>root->key)
	 root->right=deleteNode(root->right,x);
	else if(root->key==x)
	{
	   if(root->left== NULL)
	    {
		 Node* tam=root->right;
		 delete root;
		 return tam;	
	    }
	  else if(root->right==NULL)
	        {
	         Node* tam=root->left;
	    	 delete root;
	    	 return tam;
		    }   
		    else
	      	{
		      Node *tam=findMinNode(root->right);
		      root->key=tam->key;
		      root->right= deleteNode(root->right,tam->key);
	    	}
	
	}
	return root;
}
Node *findNode(Node *root,int x)
{
	if(root==NULL) return root;
	else if(x<root->key)
	 root->left=findNode(root->left,x);
	else if(x>root->key)
	 root->right=findNode(root->right,x);
	else if(root->key==x)
     	{
		Node* tam=root;
		return tam;
	    } 
	return root; 
}
Node * xoaNode( Node * root,int x)
{
	
}



Node *xoayTrai(Node*root)
{
	if(root== NULL) return root;
	else
	{
		Node *tam1=root;//nut
		tam1->left=root->left;//nut trai
		tam1->right=root->right;//nut phai
		
		root=root->right;
		root->left=tam1;
		root->left->right=tam1->right->left;		
	}
}
