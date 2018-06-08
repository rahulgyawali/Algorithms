#include <bits/stdc++.h>
using namespace std;

struct node{
	struct node* next;
	int data;
};

struct node* get(int n)
{	
	struct node* tmp;
	tmp = (struct node*)malloc(sizeof (struct node));
	tmp->data = n;
	tmp->next = NULL;
	return tmp;

}	

void print(struct node* root)
{	
	struct node* p = root;

	while(p){
	
		cout<<p->data<<" ";
		
		p = p->next;
	}
	cout<<endl;
}

struct node* add_end(struct node* root,int x)
{
	if(root == NULL) {
		
		root = get(x);
		
	}else{

		struct node* p = root;

		while(p->next != NULL) {

			p = p->next;

		}
		p->next = get(x);
	}

	return root;
}

struct node* add_first(struct node* root,int x)
{
	if(root == NULL) {

		root = get(x);

	}else{

		struct node* tmp;

		tmp = get(x);
		tmp->next = root;

		root = tmp;
	}
	
	return root;
}

int main()
{
	struct node* root = NULL;
	root = add_end(root,12);
	root = add_first(root,11);
	root = add_end(root,13);
	root = add_first(root,10);
	root = add_end(root,14);

	print(root);

	return 0;

}
