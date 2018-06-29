using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l;
    string s;
    while(getline(cin,s)){
    	list<char> v;
    	l = s.length();
    	auto j = v.end();
    	for(i=0;i<l;i++){
    		if(s[i]=='[')	j=v.end();
    		else if(s[i]==']')	j=v.begin();
    		else	{
    			v.insert(j,s[i]);
    			j--;
    		}
    	}
    	copy(v.rbegin(), v.rend(), ostream_iterator<char>(cout));
    	cout<<"\n";
    }
	return 0;
}