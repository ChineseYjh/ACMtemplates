#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 33333;
int wa[maxn],wb[maxn],wv[maxn],WS[maxn];
int cmp(int *r,int a,int b,int l) {
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int *r,int *sa,int n,int m) {
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++) WS[i]=0;
    for(i=0; i<n; i++) WS[x[i]=r[i]]++;
    for(i=1; i<m; i++) WS[i]+=WS[i-1];
    for(i=n-1; i>=0; i--) sa[--WS[x[i]]]=i;
    for(j=1,p=1; p<n; j*=2,m=p) {
        for(p=0,i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) WS[i]=0;
        for(i=0; i<n; i++) WS[wv[i]]++;
        for(i=1; i<m; i++) WS[i]+=WS[i-1];
        for(i=n-1; i>=0; i--) sa[--WS[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}

int main()
{
	char* str = "aabaaaab";
	int r[11]; for(int i = 0; i < strlen(str); i++) r[i] = str[i] - 'a';
	int sa[11];
	da(r, sa, strlen(str), 26);
	return 0;
}
