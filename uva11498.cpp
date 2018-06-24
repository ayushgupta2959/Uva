using namespace std;
#include<bits/stdc++.h>
int main(){
	int k,n,m,x,y;
	string r;
	scanf("%d",&k);
	while(k!=0){
		scanf("%d%d",&n,&m);
		while(k--){
			r="";
			scanf("%d%d",&x,&y);
			r = (y>m)?"N":"S";
			r = r + ((x>n)?"E":"O");
			if(x==n||y==m) r="divisa";
			cout<<r<<"\n";
		}
		scanf("%d",&k);
	}
	return 0;
}

