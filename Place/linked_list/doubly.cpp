#include <bits/stdc++.h>
using namespace std;

struct node{

	struct node* next;
	struct node* prev;
	int data;
};

void print(struct node* root)
{
	struct node* p;
	
	p = root;

	while(p) {

		cout<<p->data<<" ";
		p = p->next;
	}

	cout<<endl;

}

struct node* get(int x)
{
	struct node* temp;

	temp = (struct node*)sizeof(struct node);
	temp->data =  x;
       	temp->prev = NULL;
	temp->next = NULL;

	return temp;
}

struct node* add_front(struct node* root,int x)
{
	struct node* tmp;
	
	tmp = get(x);
	tmp->prev = NULL;
	tmp->next = root;

	if(root != NULL) {
	
		root->prev = tmp;
	}	
	
	root = tmp;

	return root;
}

struct node* add_end(struct node* root,int x)
{
	struct node* p;
	struct node* tmp;

	if(root == NULL) {

		tmp = get(x);
		root = tmp;

		return root;
	}else{
		p = root;

		while(p->next != NULL){
		
			p = p->next;
		}
		tmp = get(x);
		tmp->prev = p;
		p->next = tmp;
	}
	return root;
}

struct node* add_after(struct node* root,int x,int y)
{
	struct node* tmp;
	struct node* p;
	
	p = root;

	while(p->next != NULL) {
	
		if(p->data == x) {
		
			tmp = get(y);


		}

		p = p->next;
	}

	return root;
}

int main()
{


	return 0;
}
