using namespace std;
#include <bits/stdc++.h>
typedef vector<int> vi;
class UnionFind{
private:
	vi p,setSize,rank;
	int numSet;
public:
	UnionFind(int N){
		p.reserve(N);
		for(int i=0;i<N;++i)	p[i] = i;
		setSize.assign(N,1);
		rank.assign(N,0);
		numSet = N;
	}
	int findSet(int i){
		return (p[i]==i)?i:(p[i] = findSet(p[i]));
	}
	void unionSet(int i,int j){
		int x = findSet(i);
		int y = findSet(j);
		if(x!=y){
			numSet--;
			if(rank[x]>rank[y])	{
				p[y] = x;
				setSize[x]+=setSize[y];
			}
			else{
				p[x] = y;
				setSize[y]+=setSize[x];	
				if(rank[x]==rank[y])	rank[y]++;
			}
		}
	}
	int sizeOfSet(int i){
		return setSize[findSet(i)];
	}
};
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,set,n;
    string s1,s2;
    cin>>t;
    while(t--){
    	unordered_map<string,int> m;
    	set=1;
    	cin>>n;
    	UnionFind u(n);
    	while(n--){
    		cin>>s1>>s2;
    		if(!m[s1])	m[s1] = set++;
    		if(!m[s2])	m[s2] = set++;
    		u.unionSet(m[s1]-1,m[s2]-1);
    		cout<<u.sizeOfSet(m[s2]-1)<<"\n";
    	}
    }
	return 0;
}