using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,sum,i,j;
    int a[1005];
    cin>>t;
    while(t--){
    	cin>>n;
    	cin>>a[0];
    	sum=0;
    	for(i=1;i<n;i++){ cin>>a[i];
    		for(j=i-1;j>=0;j--) {
    			if(a[j]<=a[i]) sum++;
    		}
    	}
    	cout<<sum<<"\n";
    }
	return 0;
}