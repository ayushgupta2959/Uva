using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,result;
    char c;
    cin>>t;
    while(t--){
    	cin>>c>>m>>n;
    	if(c=='r')	result = min(m,n);
    	else if(c=='k')	result = ceil((float)m*n/2);
    	else if(c=='K')	result = ceil((float)m/2)*ceil((float)n/2);
    	else result = min(m,n);
    	cout<<result<<"\n";
    }
	return 0;
}