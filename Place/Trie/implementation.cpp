#include <bits/stdc++.h>
using namespace std;

struct TrieNode {

	struct TrieNode* children[26];
	bool isEndOfWord;	
};

struct TrieNode* newnode(void)
{
	struct TrieNode* temp = (struct TrieNode*) malloc(sizeof(struct TrieNode));
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
	if(root == NULL) {
		return false;
	}
	int i;
	struct TrieNode* p = root;

	for(i = 0; i < key.size(); i++) {
		
	
	}
}



int main()
{
	
	return 0;
}
