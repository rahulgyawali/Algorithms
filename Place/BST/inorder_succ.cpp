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

struct node* minimum(struct node* root)
{
	if(root == NULL) {
		
		return NULL;
	}

	while(root->left!=NULL) {

		root = root->left;
	}

	return root;
}

struct node* inorder_succ(struct node* root,struct node* x)
{
	if(x->right != NULL) return minimum(x->right);

	struct node* temp = NULL;

	while(root) {
	
		if(root->data > x->data){

			temp = root;
			root = root->left;

		}else if (root->data < x->data ) {

			root = root->right;

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

	struct node* find = search(11);
	if(find != NULL) {
	
		if(inorder_succ(root,find)) {

			cout<<inorder_succ(root,find)->data<<endl;

		}
	}

	return 0;
}
