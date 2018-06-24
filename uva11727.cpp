using namespace std;
#include<bits/stdc++.h>
int main(){
	int T,a,b,c,i;
	i=0;
	scanf("%d",&T);
	while(i++<T){
		scanf("%d%d%d",&a,&b,&c);
		printf("Case %d: %d\n",i,max(min(a,b),min(max(a,b),c)));
	}
	return 0;
}