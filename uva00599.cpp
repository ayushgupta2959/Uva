using namespace std;
#include <bits/stdc++.h>
int main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int t,e,l,x;
    cin>>t>>std::ws;
    while(t--){
    	bitset<30> b;
    	e=0;
    	while(true){
	    	getline(cin,s);
	    	if(s[0]=='*') break;
	    	b.set(s[1]-65);
	    	b.set(s[3]-65);
	    	e++;
	  	}
	  	getline(cin,s);
	  	l=(s.length()+1)/2;
	  	x=l-b.count();
	  	cout<<"There are "<<l-e-x<<" tree(s) and "<<x<<" acorn(s).\n";
    }
    return 0;
 } 
