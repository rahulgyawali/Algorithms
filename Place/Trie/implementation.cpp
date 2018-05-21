#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	struct TrieNode* parent;
	struct TrieNode* children[26];
	int count;	
};

struct TrieNode* newnode(void)
{
	struct TrieNode* temp = (struct TrieNode*)malloc(sizeof(struct TrieNode));
	temp->count = 0;
	temp->parent = NULL;
	int i;
	for(i = 0; i < 26 ; i++) {
		
		temp->children[i] = NULL;	
	}

	return temp;
}

void insert(struct TrieNode* root,string key)
{
	struct TrieNode* temp = root;
	int i;

	for(i = 0 ; i < key.size(); i++) {
		int index = key[i] - 'a';
		if(temp->children[index] == NULL) {

			temp->children[index] = newnode();
			temp->children[index]->parent = temp;
		}
		temp = temp->children[index];
	}

	(temp->count)++;
	
}	

struct TrieNode* search (struct TrieNode* root,string key)
{
	int i;
	struct TrieNode* p = root;

	for(i = 0; i < key.size(); i++) {
		int index = key[i] - 'a';
		if(p->children[index] == NULL) {
			return NULL;
		}
		p = p->children[index];
	}
	if((p->count) > 0) {
		return p;
	}

	return NULL;
}

void remove(struct TrieNode* root, string key)
{
	struct TrieNode* p = search(root,key);

	if(p == NULL) {
		return ;
	}

	--(p->count);

	bool leaf = true;
	int child_count = 0;

	int i;

	for(i = 0; i < 26; i++) {

		if(p->children[i] != NULL) {

			leaf = false;
			++child_count;
		}
	}

	if(!leaf) {

		return ;
	}

	struct TrieNode* par;
	
	while((p->count == 0) && p->parent!=NULL && child_count == 0) {

		child_count = 0;
		par = p->parent;

		for(i = 0; i < 26; i++) {
	
			if (par->children[i] != NULL) {

				if(par->children[i] == p) {
					par->children[i] = NULL;
					free(p);
					p = par;
				}else {

					++child_count;
				}
			}
		}
	}
}

int main()
{
	int i;
	vector<string> vr;
	int n;
	cin>>n;
	string h;
	int w = n;
	while(w--) {
		cin>>h;
		vr.push_back(h);
	}

	struct TrieNode* root = newnode();
	
	for(i = 0 ; i < n; i++) {

		insert(root,vr[i]);
	}
	

	string q;

	cout<<"ENTER TO SEARCH"<<endl;
	cin>>q;

	if(search(root,q) != NULL) {
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	int x = 2;

	while(x--) {
		cin>>q;
		remove(root,q);
		if (search(root,q) != NULL) {

			cout<<"YES"<<endl;
		}else {

			cout<<"NO"<<endl;
		}
	}

	cout<<"ENTER TO SEARCH"<<endl;
	cin>>q;

	if(search(root,q) != NULL) {
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}


	return 0;
}
