using namespace std;
#include <bits/stdc++.h>
pair<int,int> f,l,arr[14];
int noSol,n,m;
bitset<14> notUsed;
void solve(int x,int j){
	if(j>n) return;
	if(!noSol) return;
	if(x==l.first&&j==n){
		noSol=0;
		return;
	}
	for(int i=0;i<m&&noSol;i++){
		if(notUsed[i]){
			if(arr[i].first==x) {
				notUsed[i] = 0;
				solve(arr[i].second,j+1);
				notUsed[i] = 1;
			}
			else if(arr[i].second==x){
				notUsed[i] = 0;
				solve(arr[i].first,j+1);
				notUsed[i] = 1;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m){
    	noSol=1;
    	notUsed.set();
    	cin>>f.first>>f.second;
    	cin>>l.first>>l.second;
    	for(int i=0;i<m;i++)
    		cin>>arr[i].first>>arr[i].second;
    	solve(f.second,0);
    	if(noSol) cout<<"NO\n";
    	else cout<<"YES\n";
    }
	return 0;
}