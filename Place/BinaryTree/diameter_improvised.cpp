#include<bits/stdc++.h>
using namespace std;

struct node {																	//Defined structure of node
	int data;
	struct node* left;
	struct node* right;
};

struct node* getnode(int x)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));				//Generate New Node in Memory
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->data = x;

	return tmp;
}

int max(int a,int b)															//return max of two no.s
{
	return a>b?a:b;
}


int height(struct node* root,int& dia)													//Gets height of tree rooted at root
{
	if(root == NULL)
		return -1;

	int left = height(root->left,dia);
	int right = height(root->right,dia);

	dia = max(dia,left+right+2);

	return 1 + max(left,right);
}


int diameter(struct node* root)
{
	if(root == NULL)
		return 0;

	int dia = INT_MIN;
	int ht = height(root,dia);
	return dia;
}

int main()
{
	struct node* root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->left->left = getnode(4);
	root->left->left->left = getnode(6);
	root->left->left->left->left = getnode(8);
	root->left->right = getnode(5);
	root->left->right->right = getnode(7);
	root->left->right->right->right = getnode(9);

	cout<<"Diameter is ";
	cout<<diameter(root)<<endl;

	return 0;
}
