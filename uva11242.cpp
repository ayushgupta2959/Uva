using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,i,j,z;
    double maX,x;
    double f[15];
 	while(cin>>n>>m){
 		vector<double> v;
 		v.reserve(105);
 		for(i=0;i<n;i++)	cin>>f[i];
 		for(i=0;i<m;i++){
 			cin>>x;
 			for(j=0;j<n;j++)	v.emplace_back(x/f[j]);
 		}
 		sort(v.begin(),v.end());
 		z = n*m;
 		maX = 0;
 		for(i=0;i<z-1;i++){
 			if((v[i+1]/v[i])>maX) maX=v[i+1]/v[i];
 		}
 		cout<<fixed<<setprecision(2)<<maX<<"\n";
 	}
	return 0;
}