using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l;
    while(true){
    	vector<string> v;
    	v.reserve(100000);
    	cin>>l;
    	if(l==0) break;
    	copy_n(istream_iterator<string>(cin),l-1,inserter(v,v.begin()));
    	string curdir = "+x";
    	for (string& s:v){
    		if(s == "No")	continue;
    		if(curdir=="+x"){
    			curdir = s;
    		}
    		else if(curdir =="-x"){
    			curdir = ((s[0]=='+')?s.replace(0,1,"-"):s.replace(0,1,"+"));
    		}
    		else if(curdir == s){
    			curdir = "-x";	
    		}
    		else if(curdir[1]==s[1]){
    			curdir = "+x";
    		}
    	}
    	cout<<curdir<<"\n";
    }
	return 0;
}