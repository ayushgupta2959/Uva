 using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int t,n;
    cin>>t>>std::ws;
    while(t--){
    	n=0;
    	unordered_map<string,int> m;
    	m.reserve(10000);
    	vector<string> v;
    	v.reserve(10000);
    	while(getline(cin,s) && s.length()){
	    	if (m[s]==0){
	    		v.push_back(s);	
	    	}
	    	m[s]++;
	    	n++;
    	}
    	sort(v.begin(),v.end());
    	for(auto x:v){
    		cout<<x<<" "<<fixed<<setprecision(4)<<(float)(m[x]*100)/n<<"\n";
    	}
    	if(t)
    		cout<<"\n";
    }
	return 0;
}