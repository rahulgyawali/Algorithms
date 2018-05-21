#include <bits/stdc++.h>
using namespace std;

struct TrieNode {

	struct TrieNode* children[26];
	bool isEndOfWord;	
};

struct TrieNode* newnode(void)
{
	struct TrieNode* temp = (struct TrieNode*)malloc(sizeof(struct TrieNode));
	temp->isEndOfWord = false;
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
		}
		temp = temp->children[index];
	}

	temp->isEndOfWord = true;
	
}	

bool search (struct TrieNode* root,string key)
{
	int i;
	struct TrieNode* p = root;

	for(i = 0; i < key.size(); i++) {
		int index = key[i] - 'a';
		if(p->children[index] == NULL) {
			return false;
		}
		p = p->children[index];
	}
	if(p->isEndOfWord) {
		return true;
	}

	return false;
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
	cin>>q;

	if(search(root,q) == true) {
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}
