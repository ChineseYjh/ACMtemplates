//@author: ChineseYjh
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int fa[MAX];

void init(){//fa[root] == root
	for(int i = 0; i < MAX; i++){
		fa[i] = i;
	}
}

int findset(int v){//without path compression
	while(fa[v] != v) v = fa[v];
	return v;
}

int findset_c(int v){//with path compression
	int temp = v;
	while(fa[v] != v) v = fa[v];
	while(fa[temp] != v){
		int t = fa[temp];
		fa[temp] = v;
		temp = t;
	}
	return v;
}
int union_nodes(int a, int b){//join one node to another set
	int a1 = findset(a);
	int b1 = findset(b);
	if(a1 != b1) fa[b1] = a1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	
	printf("Total time: %.3f s.\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}

