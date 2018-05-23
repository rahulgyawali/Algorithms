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

void levelorder(struct node* root)
{
	queue<struct node*> q;
	int n;

	q.push(root);
	
	while(!q.empty()) {
		
		n = q.size();

		while(n--) {

			struct node* temp = q.front();
			q.pop();
			cout<<temp->data<<" ";

			if(temp->left) {
				q.push(temp->left);
			}

			if(temp->right) {
				q.push(temp->right);
			}
		}
		cout<<endl;
	}
}

int main()
{
	struct node* root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->left->left = getnode(4);
	root->left->right = getnode(5);
	
	cout<<"The Height is "<<height(root);
	cout<<"The Level Wise"<<endl;

	levelorder(root);

	return 0;
}
