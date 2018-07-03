using namespace std;
#include <bits/stdc++.h>
typedef pair<int, int> ii; 
typedef vector<ii> vii;
#define make_pair mp
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,i,x,t,j;
    while(cin>>m>>n){
	    vector<vii> g;
	    g.assign(n+1,vii());
	    for(i=1;i<=m;i++){
	    	cin>>x;
	    	vector<int> v;
	    	v.reserve(x);
	    	for(j=0;j<x;j++) cin>>v[j];
	    	for(j=0;j<x;j++){
	    		cin>>t;
	    		g[v[j]].push_back(ii(i,t));
	    	}
	    }
	    cout<<n<<" "<<m<<"\n";
	    for(i=1;i<=n;i++){
	    	if(!g[i].empty()){
		    	x = g[i].size();
		    	cout<<x<<" ";
		    	cout<<g[i][0].first;
		    	for(j=1;j<x;j++) cout<<" "<<g[i][j].first;
		    	cout<<"\n";
		    	cout<<g[i][0].second;
		    	for(j=1;j<x;j++) cout<<" "<<g[i][j].second;
		    	cout<<"\n";
	    	}
	    	else cout<<"0\n\n";
	    }
	}
	return 0;
}