using namespace std;
#include <bits/stdc++.h>
int main(){
	int n,b,cpp,ar,h,w;
	while(scanf("%d%d%d%d",&n,&b,&h,&w)==4){
		int r=b+1;
		for(int i=0;i<h;i++){
			scanf("%d",&cpp);
			ar=0;
			for(int j=1,x;j<=w;j++){
				scanf("%d",&x);
				ar=max(ar,x);
			}
			if(ar>=n) r=min(r,n*cpp);
		}
		if(r==b+1) printf("stay home\n");
		else printf("%d\n",r);
	}
	return 0;
}