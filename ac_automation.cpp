//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 99999999;
//node in trie
struct node {
	node* next[26];
	node* fail;
	int sum;
} root;
//init the node in trie
void clear(node* &temp){
	temp->fail = nullptr; temp->sum = 0;
	for(int j = 0; j < 25; j++) temp->next[x] = nullptr;
}
//build trie via inserting
void Insert(char* s) {
	node* temp = root;
	for(int i = 0; s[i]; i++) {
		int x = s[i] - 'a';
		if(temp->next[x]) {
			temp = temp->next[x];
			continue;
		}
		temp = temp->next[x] = new node();
		clear(temp);
	}
	temp->sum++;
}
//build fail edges using bfs
void build_fail(){
	node* q[MAX];
	ll head = 0, tail = 1; q[head] = root;
	while(head != tail){
		//dequeue
		node* temp = q[head]; head = (head + 1) % MAX;
		for(int i = 0; i < 26; i++){
			if(temp->next[i] == nullptr) continue;
			//build fail
			if(temp == root) {
				temp->next[i]->fail = root; continue;
			}
			node* p = temp->fail;
			while(p){
				if(p->next[i] != nullptr){
					temp->fail = p->next[i];
					break;
				}
				p = p->fail;
			}
			if(!p) temp->next[i]->fail = root;
			//enqueue
			q[tail] = temp->next[i]; tail = (tail + 1) % MAX;
		}
		
	}
}
//match the string in trie
void ac_automation(char* s){
	node* p = root;
	for(int i = 0; s[i]; i++){
		//match
		int x = s[i] - 'a';
		while(!(p->next[x]) && p != root) p = p->fail;
		p = p->next[x]; if(!p) p = root;
		//others
		
	}
}
int main() {

	return 0;
}
