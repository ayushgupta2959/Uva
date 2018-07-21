using namespace std;
#include <bits/stdc++.h>
bitset<32> primes("10100000100010100010100010101100");//since max sum could be 15+16=31
bitset<17> notUsed;
int arr[17];
int n,c;
void solve(int m){
	if(m==n){
		if(primes[arr[n-1]+1]){
			cout<<arr[0];
			for(int j=1;j<n;j++)
				cout<<" "<<arr[j];
			cout<<"\n";
		}
		return;
	}
	for(int x=2;x<=n;x++){
		if(notUsed[x]){
			arr[m]=x;
			notUsed[x]=0;
			if(primes[arr[m-1]+arr[m]]) solve(m+1);
			notUsed[x]=1;
		}
	}
}
int main(){
		#ifndef ONLINE_JUDGE
	   	freopen("../../input.txt", "r", stdin);
	    freopen("../../output.txt", "w", stdout);
		#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    c=0;
    while(cin>>n){
    	memset(arr,0,sizeof(arr));
    	notUsed.set();
    	notUsed[1]=0;
    	arr[0]=1;
    	if(c) cout<<"\n";
    	cout<<"Case "<<++c<<":\n";
    	solve(1);
    }
    return 0;
}