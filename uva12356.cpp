using namespace std;
#include <bits/stdc++.h>
typedef pair<int, int> ii; 
typedef vector<ii> vii;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s,b,l,r;
    vii v;
    while(true){
    	cin>>s>>b;
    	if(s==0)	break;
    	v.reserve(s+3);
    	for (int i = 1; i < s+1; ++i){
    		v[i].first = i-1;
    		v[i].second = i+1;
    	}
    	v[1].first = 0;
    	v[s].second = 0;
    	while(b--){
    		cin>>l>>r;
    		if((v[l].first!=0)&&(v[r].second!=0)){
	    		cout<<v[l].first<<" "<<v[r].second<<"\n";
	    		v[v[l].first].second = v[r].second;
	    		v[v[r].second].first = v[l].first;
    		}
    		else if(v[l].first==0&&v[r].second==0){
    			cout<<"* *\n";
    		}
    		else if(v[l].first==0){
    			v[v[r].second].first = 0;
    			cout<<"* "<<v[r].second<<"\n";
    		}
    		else{
    			v[v[l].first].second = 0;
    			cout<<v[l].first<<" *\n";
    		}
    	}
    	cout<<"-\n";
    }
	return 0;
}