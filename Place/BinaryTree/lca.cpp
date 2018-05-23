#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* getnode(int x)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->data = x;

	return tmp;
}

struct node* lca(struct node* root,int n1,int n2)
{
	if(root == NULL) return NULL;

	if(root->data == n1 || root->data == n2) {

		return root;
	}

	struct node* l = lca(root->left,n1,n2);
	struct node* r = lca(root->right,n1,n2);

	if(l && r) return root;

	return (l!=NULL)?l:r;
}

int main()
{
	struct node* root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->left->left = getnode(4);
	root->left->left->left = getnode(6);
	root->left->right = getnode(5);
	
	cout<<"The LCA is "<<(lca(root,5,3))->data<<endl;
	

	return 0;
}
