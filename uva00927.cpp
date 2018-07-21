using namespace std;
#include <bits/stdc++.h>
int co[25];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int t,n,i,a;
	long long res;
 	double d,k;
 	cin>>t>>std::ws;
 	while(t--){
 		cin>>n;
 		for(i=0;i<=n;++i)	cin>>co[i];
 		cin>>d>>k;
 		a = ceil((sqrt((8*k)/d+1)));
 		a = ceil((double)(a-1)/2);
 		res = co[0];
 		for(i=1;i<=n;++i)	res += co[i]*pow(a,i);
 		cout<<res<<"\n";
 	}   
	return 0;
}

