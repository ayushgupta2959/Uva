using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::vector<int> cost;
	cost.reserve(256);
	int t,n,p,i,l,totalCost;
	char c;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		totalCost = 0; 
		cost.assign(256,0);
		while(n--){
			cin>>c>>p;
			cost[c] = p;
		}
		cin>>n;
		n=n+1;
		while(n--){
			getline(cin,s);
			l = s.length();
			for(i=0;i<l;++i) totalCost+=cost[s[i]];
		}
		cout<<fixed<<setprecision(2)<<(double)totalCost/100<<"$\n";
	}
	return 0;
}