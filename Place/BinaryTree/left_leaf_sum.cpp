#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

bool isleaf(struct node* root)
{
	if(root == NULL) {
		
		return false;
	}

	if(root->left == NULL && root->right == NULL) {
		
		return true;
	}

	return false;
}

struct node* getnode(int x)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->data = x;

	return tmp;
}

int llsum(struct node* root)
{
	if(root == NULL) return 0;
	int res = 0;

	if(root!=NULL) {

		if(isleaf(root->left)) {

			res += root->left->data;
		}else {

			res += llsum(root->left);
		}	

		res += llsum(root->right);
	}

	return res;
}

int main()
{
	struct node* root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->left->left = getnode(4);
	root->right->left = getnode(5);

	int x = llsum(root);

	cout<<"Left Leaf sum is "<<x<<endl;
	

	return 0;
}
