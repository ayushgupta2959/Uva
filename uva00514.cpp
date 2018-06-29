using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::vector<int> output;
    output.reserve(1000);
    int i,j,n;
    while(true){
    	cin>>n;
    	if(n==0)break;
    	while(cin>>output[0],output[0]){
    		for(i=1;i<n;++i)	cin>>output[i];
    		std::stack<int> station;
    		i=1;
    		j=0;
    		while(j<n){
    			if(i<=n){
    				if(output[j]==i){
    					i++;
    					j++;
    				}
    				else if(station.empty())
    					station.push(i++);
    				else if(output[j]!=station.top())
    					station.push(i++);
    				else if(output[j]==station.top()){
    					station.pop();
    					j++;
    				}
    			}
    			else if(i==n+1){
    				if(output[j]!=station.top()) break;
    				else if(output[j]==station.top()){
    					station.pop();
    					j++;
    				}
    			}
    		}
    		if(j<n)	cout<<"No\n";
    		else	cout<<"Yes\n";
    	}
    	cout<<"\n";
    }

	return 0;
}