using namespace std;
#include<bits/stdc++.h>
int main(){
	int TC;
	scanf("%d",&TC);
	long long a,b; 
	while(TC--){
		cin>>a>>b;
		if(a>b)cout<<">";
		else if(a<b) cout<<"<";
		else cout<<"=";
		cout<<"\n";
	}
	return 0;
} 
