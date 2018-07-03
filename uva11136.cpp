using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,x;
    long long c;
    while((cin>>n)&&n){
    	multiset<int> m;
    	c=0;
    	while(n--){
	    	cin>>i;
	    	while(i--){
	    		cin>>x;
	    		m.insert(x);
	    	}
	    	auto s = m.begin();
	    	auto e = m.end();
	    	e--;
	    	c += ((*e)-(*s));
	    	m.erase(s);
	    	m.erase(e);
    	}
    	cout<<c<<"\n";
    }
	return 0;
}