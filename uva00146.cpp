using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(true){
    	cin>>s;
    	if(s=="#")	break;
    	else if(!next_permutation(s.begin(),s.end()))	cout<<"No Successor\n";
    	else	cout<<s<<"\n";
    }
	return 0;
}