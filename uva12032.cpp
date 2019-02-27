using namespace std;
#include <bits/stdc++.h>
int n;
int arr[100009];
bool process(int k){
	int i;
	for(i=0;i<n;i++){
		if(arr[i]==k) k--;
	}
	if(k<0) return false;
	return true;
}
int bisection(int x){
	int result = -1;
	int l,h,m;
	l=x,h=10000000;
	while(l<h){
		m = l + (h-l)/2;
		cout<<l<<" "<<m<<" "
		if(process(m)) {
			result = m;
			h = m-1;
		}
		else{
			l = m+1;
		}
	}
	return result;
}
int process2(int k){
	int cnt = count(arr,arr+n,k);
	for(int i=k;) 
}
int main(){
	#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,x,c,p;
    cin>>t;
    c=1;
    while(t--){
    	cin>>n;
    	cin>>arr[0];
    	p=arr[0];
    	for(i=1;i<n;i++){
    		cin>>x;
    		arr[i] = x-p;
    		p=x;
    	}
    	for(i=0;i<n;i++){
    		cout<<arr[i]<<' ';
    	}
    	cout<<'\n';
    	x = max_element(arr,arr+n) - arr;
    	cout<<"Case "<<c++<<": "<<bisection(arr[x])<<'\n';
    }
	return 0;
}