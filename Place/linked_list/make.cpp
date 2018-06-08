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

struct node* add_after(struct node* root,int x,int y)
{
	struct node* p = root;

	while(p) {
	
		if(p->data == y) {
		
			struct node* tmp = get(x);
			tmp->next = p->next;
			p->next = tmp;
			return root;
		}
		p = p->next;
	}

	return root;
}

struct node* add_before(struct node* root,int x,int y)
{
	struct node* tmp;

	if(root->data == y) {

		tmp = get(x);
		tmp->next = root;
		root = tmp;
		
		return root;

	}else{

		struct node* p;

		p = root;
		
		while(p->next != NULL) {

			if(p->next->data == y) {

				tmp = get(x);
				tmp->next = p->next;
				p->next = tmp;
			
				return root;
			}

			p = p->next;
		}

	}
	return root;
}

struct node* del(struct node* root,int x)
{
	struct node* p;
	struct node* tmp;

	if(root->next == NULL) {

		tmp = root;
		root = NULL;
		free(tmp);

		return root;
	}

	if(root->data == x) {

		tmp = root;
		root = root->next;
		free(tmp);

		return root;
	}

	p = root;

	while(p->next != NULL){

		if(p->next->data == x){

			tmp = p->next;
			p->next = tmp->next;
			free(tmp);

			return root;
		}

		p = p->next;
	}

	cout<<"Not Found"<<endl;

	return root;
}

int main()
{
	struct node* root = NULL;
	root = add_end(root,12);
	root = add_first(root,11);
	root = add_end(root,13);
	root = add_first(root,10);
	root = add_end(root,20);

	print(root);

	root = add_before(root,9,10);
	
	print(root);

	root = add_after(root,17,13);

	print(root);

	root = add_before(root,15,17);

	print(root);

	root = del(root,13);

	print(root);

	root = del(root,9);

	print(root);

	root = del(root,34);

	return 0;

}
