using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,s,q,j,x,time,csat,N;
    cin>>t;
    while(t--){
    	time=0;
    	csat=0;
    	N=0;
    	cin>>n>>s>>q;
    	stack<int> cargo;
    	vector<queue<int>> station;
    	station.resize(n);
    	for (int i = 0; i < n; ++i){
    		cin>>j;
    		while(j--){
    			cin>>x;
    			N++;
    			station[i].push(x-1);
    		}
    	}
    	while(N){
    		while(!cargo.empty()&&((cargo.top()==csat)||(station[csat].size()!=q))){
    			x = cargo.top();
    			cargo.pop();
    			time++;
    			if(x!=csat)	station[csat].push(x);
    			else	N--;
    		}
    		while(!station[csat].empty()&&cargo.size()!=s){
    			cargo.push(station[csat].front());
    			station[csat].pop();
    			time++;
    		}
    		if(N!=0)	time+=2;
    		csat = (csat+1)%n;
    	}
    	cout<<time<<"\n";
    }
	return 0;
}