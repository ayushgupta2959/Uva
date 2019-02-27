using namespace std;
#include <bits/stdc++.h>
int n,m,q,l,u,result,i,j,low,hig;
//approach 2 time 0.810
//storing matrix as array of array of diagonal elements
int arr[1005][505],mt[1005];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m){
    	if(n==0&&m==0) break;
    	memset(mt,0,sizeof(mt));
    	for(i=0;i<n;i++)
    		for(j=0;j<m;j++)
    			cin>>arr[i-j+m][mt[i-j+m]++];
    	cin>>q;
    	/*for(i=1;i<(n+m);i++){
    		for(j=0;j<mt[i];j++)
    			{cout<<arr[i][j];}
    		cout<<"\n";
    	}*/
    	while(q--){
    		cin>>l>>u;
    		result=0;
    		for(i=n+m-1;i>=0;i--){
    			low=lower_bound(arr[i],arr[i]+mt[i],l)-arr[i];
    			hig=upper_bound(arr[i]+low,arr[i]+mt[i],u)-arr[i];
    			result=max(result,hig-low);
    		}
    		cout<<result<<"\n";
    	}
    	cout<<"-\n";
    }
    return 0;
}
//approach 1 time 1.012
/*int arr[500][500];
void solve(){
	int i,j,k,maX;
	result=0;
	for(i=0;i<n;i++){
		k=lower_bound(arr[i],arr[i]+m,l)-arr[i];
		j=i;
		maX=0;
		while(j<n&&k<m){
			if(arr[j++][k++]<=u) maX++;
			else break;
		}
		if(result<maX) result=maX;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j;
    while(cin>>n>>m){
    	if(n==0) break;
    	for(i=0;i<n;i++)
    		for(j=0;j<m;j++)
    			cin>>arr[i][j];
    	cin>>q;

    	while(q--){
    		cin>>l>>u;
    		solve();
    		cout<<result<<"\n";
    	}
    	cout<<"-\n";
    }
	return 0;
}*/