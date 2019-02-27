using namespace std;
#include <bits/stdc++.h>
int n,m,total;
int arr[1005];
bool checkCapacity(int capacity){
	int currCapacity=0,nb=0,nc=0;
	while(nb<n){
		if(arr[nb]>capacity) return false;
		if((currCapacity + arr[nb])>capacity) currCapacity =0;
		if(currCapacity == 0) nc++;
		if(nc>m) return false;
		currCapacity += arr[nb++];
	}
	return true;
}
int solve(){
	int low = 0;
	int high = total;
	int mid,best;
	best = high +1;
	while(low<=high){
		mid = low + (high-low)/2;

		if(checkCapacity(mid)) {
			high =mid-1;
			best = mid;
		}
		else low = mid+1;
	}
	return best;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    while(cin>>n>>m){
    	total=0;
    	for(i=0;i<n;i++) {
    		cin>>arr[i];
    		total += arr[i];
    	}	
    	cout<<solve()<<"\n";
    }
	return 0;
}