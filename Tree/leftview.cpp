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

void left_view(struct node* root)
{
	struct node* temp;
	int nc;
	queue<struct node*> qs;
	qs.push(root);

	while(1) {
		nc = qs.size();
		if(nc == 0) break;
		int first = nc;
		while(nc) {
			temp = qs.front();
			if(first == nc) {
				cout<<temp->data<<" ";
			}
			qs.pop();
			if(temp->left)
				qs.push(temp->left);
			if(temp->right)
				qs.push(temp->right);

			nc--;
		}
	}
}

int main()
{
	struct node* root = NULL;
	root = newnode(1);
	root->left= newnode(2);
	root->right = newnode(3);
	root->left->right = newnode(4);
	root->left->right->right = newnode(5);
	root->left->right->right = newnode(6);
	root->left->right->right->right = newnode(7);
	left_view(root);
}

