#include<bits/stdc++.h>
using namespace std;
int maxbit(int* arr, int len){//get the maximal bits of the numebers in arr
	int ans = 1, p = 10;
	for(int i = 0; i < len; i++) while(arr[i] / p) p *= 10, ans++;
	return ans;
}
void radix_sort(int* arr, const int len){
	int d = maxbit(arr, len);
	int buf[len], bkt[10];//buffer and bucket
	int div = 1;
	for(int radix = 0; radix < d ; radix++){
		memset(bkt, 0, sizeof(bkt));//init the bucket
		for(int i = 0; i < len; i++) bkt[(arr[i] / div) % 10]++;//get into the bucket
		for(int i = 1; i < 10; i++) bkt[i] += bkt[i - 1];//get the rank by rolling the bucket
		for(int i = len - 1; i >= 0; i--) buf[--bkt[(arr[i] / div) % 10]] = arr[i];//fill buffer
		for(int i = 0; i < len; i++) arr[i] = buf[i];//update arr
		div *= 10;//update the div
	}
} 
int main()
{
	int a[7] = {12345, 82783, 38288, 83, 903, 85, 832};
	radix_sort(a, sizeof(a) / sizeof(int));
	return 0;
} 
