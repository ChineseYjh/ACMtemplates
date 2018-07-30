#include<bits/stdc++.h>
using namespace std;
#define MAX 1000010
#define INF 0x3f3f3f3f
int f[MAX], ch[MAX][2], key[MAX], size[MAX], cnt[MAX];//non-zero
int sz, root;

inline int get(int x) {
	return x == ch[f[x]][1];
}

inline void clear(int x) {
	if(x) f[x] = ch[x][0] = ch[x][1] = key[x] = size[x] = cnt[x] = 0, sz--;
}

inline void update(int x) {
	if(x) {
		size[x] = cnt[x];
		if(ch[x][0]) size[x] += size[ch[x][0]];
		if(ch[x][1]) size[x] += size[ch[x][1]];
	}
}

inline void rotate(int x) {
	int old = f[x], oldf = f[old], which = get(x);
	ch[old][which] = ch[x][!which]; f[ch[old][which]] = old;
	ch[x][!which] = old; f[old] = x;
	f[x] = oldf;
	if(oldf) ch[oldf][ch[oldf][1] == old] = x;
	update(x);
	update(old);
}

//to root 
inline void splay(int x) {
	for(int fa; fa = f[x]; rotate(x)) {
		if(f[fa]) rotate(get(x)==get(fa) ? fa : x);
	}
	root = x;
}

// f[x] == goal
inline void splay(int x, int goal) {
	for(int fa; fa = f[x], fa != goal; rotate(x)) {
		if(f[fa]) rotate(get(x)==get(fa) ? fa : x);
		if(f[x] == goal) break;
	}
	if(goal == 0) root = x;
}

inline void insert(int x) {
	if(!root) {
		root = ++sz, ch[sz][0] = ch[sz][1] = f[sz] = 0, size[sz] = cnt[sz] = 1, key[sz] = v;
		return;
	}
	int now = root, fa = 0;
	for(;;){
		if(key[now] == v){
			cnt[now]++;
			update(now); update(fa);
			splay(now);
			break;
		}
		fa = now;
		now = ch[now][key[now] < v];
		if(!now){
			sz++; size[sz] = cnt[sz] = 1;
			ch[sz][0] = ch[sz][1] = 0;
			f[sz] = fa; ch[fa][key[fa] < v] = sz;
			key[sz] = v;
			update(fa);
			splay(now);
			break;
		}
	}
}

inline int find(int v){
	int now = root, ans = 0;
	while(now){
		if(key[now] > v){
			now = ch[now][0];
		}
		else{
			ans += (ch[now][0] ? size[ch[now][0]] : 0);
			if(key[now] == v) {
				//splay(now);
				return ans + 1;
			} else {
				ans += cnt[now];
				now = ch[now][1];
			}
		}
	}
	return now;
}

inline int findx(int x){
	if(x > sz) return INF;
	int now = root;
	for(;;){
		if(ch[now][0] && size[ch[now][0]] >= x) now = ch[now][0];
		else{
			int temp = cnt[now] + (ch[now][0] ? size[ch[now][0]] : 0);
			if(x <= temp) return key[now];
			x -= temp;
			now = ch[now][1];
		}
	}
}

inline int pre(){
	int now = ch[root][0];
	while(ch[now][1]) now = ch[now][1];
	return now;
}

inline int next(){
	int now = ch[root][1];
	while(ch[now][0]) now = ch[now][0];
	return now;
}

inline bool del(int v){
	if(find(v) == 0) return false;
	if(cnt[root] > 1){
		cnt[root]--;
		update(root);
		return true;
	}
	if(!ch[root][0] && !ch[root][1]){
		clear(root); root = 0;
	}
	else if(!ch[root][0]){
		int old = root; root = ch[root][1];
		clear(old); f[root] = 0;
		update(root);
	}
	else if(!ch[root][1]){
		int old = root; root = ch[root][0];
		clear(old); f[root] = 0;
		update(root);
	}
	else{
		int left = pre(), old = root;
		splay(left);
		ch[root][1] = ch[old][1]; f[ch[old][1]] = root;
		clear(old); update(root);
	}
	return true;
}






