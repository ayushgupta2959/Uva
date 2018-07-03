using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x,n,a,i,mx;
    cin>>t;
    while(t--){
    	cin>>n;
    	unordered_map<int,int> m;
    	x=0;
    	mx =0;
	    for(i=1;i<=n;i++){
	    	cin>>a;
	    	if(i-m[a]>x) (++x);
	    	else{
	    		mx = max(x,mx);
	    		x = i-m[a];
	    	}
	    	m[a] = i;
	    }	
	    cout<<max(x,mx)<<"\n";
	}    
	return 0;
}