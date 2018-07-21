using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,t,i,g,ca,x,p,maxArea,area,bestloc,caseNo;
    map<int,int> Map;
    int poles[20];
    caseNo = 1;
    while(cin>>n>>m){
    	if(n==0&&m==0) break;
    	Map.clear();
    	for(i=0;i<n;i++) cin>>poles[i];
    	cin>>t;
    	while(t--){
    		cin>>g;
    		p=0;
    		while(g--){
    			cin>>x;
    			x--;
    			p |= (1<<x);
    		}
    		cin>>ca;
    		Map[p] = ca;
    	}
    	maxArea = -1e9;
    	t=i<<n;
    	for(x=0;x<t;x++){
    		if(__builtin_popcount(x)!=m) continue;
    		area=0;
    		for(i=0;i<n;i++){
    			if(x&(1<<i)){
    			 	area += poles[i];
    			}
    		}
    		for(auto it:Map){
    			g = __builtin_popcount(x&it.first);
    			if(g>=2)area -=(g-1)*it.second;
    		}
    		if(area>maxArea){
    			maxArea = area;
    			bestloc = x;
    		}
    		else if(area == maxArea){
    			for(i=0;i<n;i++){
    				g = bestloc&(1<<i);
    				p = x&(1<<i);
    				if(p!=g){
    					if(p>g) bestloc = x; 
    					break;
    				}
    			}
    		}
    	}
    	cout<<"Case Number  "<<caseNo++<<"\n";
    	cout<<"Number of Customers: "<<maxArea<<"\n";
    	cout<<"Locations recommended:";
    	for(i=0;i<n;i++)
    		if(bestloc&(1<<i)) cout<<" "<<(i+1);
    	cout<<"\n\n";
    }
	return 0;
}
/*
using namespace std;
#include<bits/stdc++.h>
int rmask[20] = {}, mw[20], c[20];
int mx, ret;
int n, m, r;
int i;
void dfs(int idx, int n, int m, int mask, int i) {
    if(idx == m) {
        int sum = 0;
        for(i = 0; i < n; i++)
            if((mask>>i)&1)
                sum += c[i];
        for(i = 0; i < r; i++) {
            int val = __builtin_popcount(mask&rmask[i]);
            if(val >= 2)
                sum -= mw[i]*(val-1);
        }
        if(sum > mx) {
            mx = sum;
            ret = mask;
        }
        return;
    }
    for(; i < n; i++)
        dfs(idx+1, n, m, mask|(1<<i), i+1);
}
int main() {
	int cases = 0;
    while(scanf("%d %d", &n, &m) == 2 && n) {
        for(i = 0; i < n; i++)
            scanf("%d", &c[i]);
        scanf("%d", &r);
        for(i = 0; i < r; i++) {
            rmask[i] = 0;
            int x, y;
            scanf("%d", &x);
            while(x--) {
                scanf("%d", &y);
                y--;
                rmask[i] |= 1<<y;
            }
            scanf("%d", &mw[i]);        mx = 0, ret = 0;
        }

        dfs(0, n, m, 0, 0);
        printf("Case Number  %d\n", ++cases);
        printf("Number of Customers: %d\n", mx);
        printf("Locations recommended:");
        for(i = 0; i < n; i++)
            if((ret>>i)&1)
                printf(" %d", i+1);
        puts("\n");
    }
    return 0;
}
*/