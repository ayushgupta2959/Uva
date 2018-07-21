using namespace std;
#include <bits/stdc++.h>
//finding maximum independent set
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define maxN 102
int color[maxN], n;
vector<int> adj[maxN];
vector<int> ans;

void Backtracking(int u, vector<int> tmp) {
    vector<int> save;
    color[u] = -1; tmp.push_back(u);
  //  printf("%d \n", u);
    for (int j=0, sizeu=adj[u].size(); j<sizeu; j++) {
        int v = adj[u][j];
        if (color[v]==0) {
            color[v] = 1;
            save.push_back(v);
        }
    }
    bool found = false;
    for (int v=u+1; v<=n; v++)
        if (color[v]==0) {
            Backtracking(v, tmp);
            found = true;
            break;
        }
    if (!found && ans.size()<=tmp.size()) ans = tmp;

    for (int j=0, sizes=save.size(); j<sizes; j++)
        color[save[j]] = 0;
    color[u] = 1; tmp.pop_back();
    for (int v=u+1; v<=n; v++)
        if (color[v]==0) {
            Backtracking(v, tmp);
            break;
        }
    color[u] = 0;
}

int main() {
	int Case, m, u, v;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &n, &m);
        for (int i=1; i<=n; i++) {
            adj[i].clear(); color[i] = 0;
        }
        while (m--) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v); adj[v].push_back(u);
        }
        ans.clear();
        Backtracking(1, ans);
        printf("%d\n", ans.size());
        if (ans.size()>0) printf("%d", ans[0]);
        for (int i=1, sizea=ans.size(); i<sizea; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}
/*int g[101][101],color[101],mt[101],n,maX;
int tmp[101],ans[101];
void solve(int x,int y){
	int reduce[n],idx=0;
	color[x]=-1;tmp[y++]=x;
	for(int j=0;j<mt[x];j++){
		if(!color[g[x][j]]){
			color[g[x][j]] = 1;
			reduce[idx++]=g[x][j];
		}
	}
	int found=0;
	for(int i=x+1;i<=n;i++){
		if(!color[i]){
			solve(i,y);
			found = 1;
			break;
		}
	}
	if((!found)&&(maX<=y)){
		maX=y;
		for(int i=0;i<maX;i++) ans[i]=tmp[i];
	}
	for(int i=0;i<idx;i++){
		color[reduce[i]]=0;
	}
	color[x]=1;y--;
	for(int i=x+1;i<=n;i++){
		if(!color[i]){
			solve(x,y);
			break;
		}
	}
	color[x]=0;
}
int main(){
	#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,m,k;
    cin>>m;
    while(m--){
    	memset(mt,0,sizeof(mt));
    	memset(color,0,sizeof(color));
    	cin>>n>>k;
    	while(k--){
    		cin>>x>>y;
    		g[x][mt[x]++]=y;
    		g[y][mt[y]++]=x;
    	}
    	maX = -1;
    	solve(1,0);
    	cout<<maX<<"\n";
    	int i;
    	for(i=0;i<maX-1;i++)
    		cout<<ans[i]<<" ";
    	cout<<ans[i]<<"\n";
    }
	return 0;
}*/