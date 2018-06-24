using namespace std;
#include <bits/stdc++.h>
int main(){
	int t,n,m,x;
	scanf("%d",&t);
	for(int i=0;i<t;++i){
		scanf("%d",&n);
		m=0;
		while(n--){
			scanf("%d",&x);
			m = max(m,x);
		}
		printf("Case %d: %d\n",(i+1),m);
	}
	return 0;
}