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

int findlevel(struct node* lca,int a,int level)
{
	if(lca == NULL)  return -1;

	if(lca->data == a) return level;

	int left = findlevel(lca->left,a,level+1);

	if(left == -1) {

		return findlevel(lca->right,a,level+1);
	}

	return left;
}

int distance(struct node* root,int a,int b)
{
	struct node* lc = lca(root,a,b);
	
	return (findlevel(lc,a,0) + findlevel(lc,b,0));
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
	cout<<"Distance is"<<distance(root,5,3)<<endl;

	return 0;
}
