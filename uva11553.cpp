using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,arr[8],board[8][8],i,j,s,ms,n;
    cin>>t;
    while(t--){
    	cin>>n;
    	ms = 1e8;
    	for(i=0;i<8;i++) arr[i] = i;
    	for(i=0;i<n;i++)
    		for(j=0;j<n;j++)
    			cin>>board[i][j];
    	do{
    		s=0;
	    	for(i=0;i<n;i++){
	    		s+=board[i][arr[i]];
	    	}
	    	if(s<ms) ms=s;
	    }while(next_permutation(arr,arr+n));
	    cout<<ms<<"\n";
    }
	return 0;
}