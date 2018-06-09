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

	temp = (struct node*)malloc(sizeof(struct node));
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

	p = root;

	while(p->next != NULL){
		
			p = p->next;
	}
		
	tmp = get(x);
	tmp->prev = p;
	p->next = tmp;
	
	return root;
}

struct node* add_after(struct node* root,int x,int y)
{
	struct node* tmp;
	struct node* p;
	
	p = root;

	while(p) {
	
		if(p->data == x) {
		
			tmp = get(y);
			tmp->prev = p;
			tmp->next = p->next;
			if(p->next != NULL){
				p->next->prev = tmp;
			}
			p->next = tmp;

		}

		p = p->next;
	}

	return root;
}

struct node* add_before(struct node* root,int x,int y)
{
	struct node* tmp;
	struct node* p;
	
	p = root;

	if(root->data == x) {
		tmp = get(x);
		tmp->next = root;
		root->prev = tmp;
		root = tmp;
		return root;
	}

	while(p) {
	
		if(p->data == x) {
		
			tmp = get(y);

			tmp->prev = p->prev;
			tmp->next = p;
			p->prev->next = tmp;
			p->prev = tmp;

		}

		p = p->next;
	}

	return root;
}
 
struct node* del(struct node* root,int x)
{
	struct node* tmp;
	struct node* p;

	if(root->data == x) {
		tmp = root;
		root = root->next;
		root->prev = NULL;
		free(tmp);
		return root;
	}

	p = root;

	while(p->next!=NULL){
		if(p->data == x){
			tmp = p;
			tmp->prev->next = p->next;
			tmp->next->prev = p->prev;
			free(tmp);
			return root;
		}
		p = p->next;
	}
	if(p->data == x) {
		tmp = p;
		tmp->prev->next = NULL;
		free(tmp);
		return root;
	}

	return root;
}

int main()
{
	struct node* root = NULL;

	root = add_front(root,10);
	print(root);
	root = add_front(root,9);
	print(root);
	root = add_end(root,23);
	print(root);
	root = add_after(root,10,15);
	print(root);
	root = add_before(root,15,13);
	print(root);
	root = del(root,10);
	print(root);
	root = del(root,13);
	print(root);
	root = del(root,23);
	print(root);
	
	return 0;
}
