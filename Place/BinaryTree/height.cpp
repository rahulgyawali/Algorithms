#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

int height(struct node* root)
{
	if(root == NULL)
		return -1;
	return (1 + ((height(root->left) > height(root->right) ) ? height(root->left) : height(root->right))); 
}

struct node* getnode(int x)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->data = x;

	return tmp;
}



int main()
{
	struct node* root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->left->left = getnode(4);
	root->left->right = getnode(5);
	
	cout<<"The Height is "<<height(root);
	

	return 0;
}
