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



struct node* reverse(struct node* root)
{
    struct node* now  = root;
    struct node* next;
    struct node* prev = NULL;
    
    while(now){
        next = now->next;
        now->next = prev;
        prev = now;
        now = next;
    }
    root = prev;
}
bool cmp(struct node* a,struct node* b)
{
    struct node* p =a;
    struct node* q =b;
    while(p!=NULL&&q!=NULL){
        if(p->data != q->data) {
            return false;
        }
        p = p->next;
        q = q->next;
    }
    return true;
}
bool isPalindrome(struct node *head)
{
    struct node* prev,second,slow,fast,mid;
    slow = *head;
    fast = *head;
    mid = NULL;
    
    while(fast!=NULL && fast>next !=NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        
    }
    
    if(fast != NULL){
        mid = slow;
        slow = slow->next;
    }
    
    second = slow;
    prev->next = NULL;
    second = reverse(second);
    
    bool res = cmp(head,second);
    
    second = reverse(second);
    
    if(mid != NULL){
        mid->next = second;
        prev->next = mid;
    }else{
        prev->next = second;
    }
    
    return res;
    //Your code here
}



int main()
{
	struct node* root = NULL;
	root = add_first(root,11);
	root = add_end(root,12);
	root = add_end(root,13);
	root = add_end(root,12);
	root = add_end(root,11);

	print(root);

	
	if(isPalindrome(root)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;

}
