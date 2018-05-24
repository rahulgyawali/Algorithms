#include <bits/stdc++.h>
using namespace std;

struct node {
	
	int data;
	struct node* left;
	struct node* right;
};

struct node*  getnode(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right =NULL;
	temp->data =x;
	return temp;
}

struct node* insert(struct node* root,int key)
{
	if(root == NULL) {
		
		root = getnode(key);
	}
	if(root->data > key) {

		root->left = insert(root->left,key);
	
	}else if (root->data < key) {

		root->right = insert(root->right,key);
	}

	return root;
}

struct node* search(struct node* root,int key)
{
	if(root->data == key ||  root == NULL) {
		
		return root;
	}

	if(root->data > key) {

		return  search(root->left,key);

	}else {

		return search(root->right,key);
	
	}
								    
}

struct node* max(struct node* root)
{
	if(root == NULL) {
		
		return NULL;
	}

	while(root->right!=NULL) {

		root = root->right;
	}

	return root;
}

struct node* inorder_pre(struct node* root,struct node* x)
{
	if(x->left != NULL) return max(x->left);

	struct node* temp = NULL;

	while(root) {
	
		if(root->data <  x->data){

			temp = root;
			root = root->right;

		}else if (root->data > x->data ) {

			root = root->left;

		}else{

			break;
		}
	}

	return temp;
}

void inorder(struct node* root)
{
	if(root == NULL) return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{
	struct node* root = NULL;

	root = insert(root,12);
	root = insert(root,13);
	root = insert(root,9);
	root = insert(root,11);
	root = insert(root,10);

	inorder(root);
	cout<<endl;

	struct node* find = search(root,11);
	if(find != NULL) {
	
		if(inorder_pre(root,find)) {

			cout<<inorder_pre(root,find)->data<<endl;

		}
	}

	return 0;
}
