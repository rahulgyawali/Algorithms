#include <bits/stdc++.h>
using namespace std;
struct node {
	int data;
	struct node* left;
	struct node* right;

};

struct node*  newnode(int x)
{
	struct node* temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

void inorder(struct node* root)
{
	if(root == NULL) return ;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}

struct node* insert(struct node* root,int x)
{
	if(root == NULL) {

		root = newnode(x);
		return root;
	}
	if(root->data >=x) {
		root->left = insert(root->left,x);
	}else {
		root->right = insert(root->right,x);
	}

	return root;

}	

int main()
{
	struct node* root = NULL;
	root = insert(root,4);
	root = insert(root,3);
	root = insert(root,2);
	root = insert(root,1);
	root = insert(root,6);
	root = insert(root,7);
	inorder(root);
}

