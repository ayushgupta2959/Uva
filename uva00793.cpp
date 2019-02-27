using namespace std;
#include <bits/stdc++.h>
typedef vector<int> vi;
class UnionFind{
private:
	vi p,rank,setSize;
	int numSets;
public:
	UnionFind(int N){
		setSize.assign(N,1);
		rank.assign(N,0);
		numSets = N;
		p.reserve(N);
		for(int i=0;i<N;++i)	p[i] = i;
	}
	int findSet(int i){
		return (p[i]==i)?i:(p[i]=findSet(p[i]));
	}
	bool isSameSet(int i,int j){
		return findSet(i)==findSet(j);
	}
	void unionSet(int i,int j){
		int x = findSet(i);
		int y = findSet(j);
		if(x!=y){
			numSets--;
			if(rank[x]>rank[y]){
				p[y] = x;
				setSize[x] += setSize[y];
			}
			else{
				p[x] = y;
				setSize[y] += setSize[x];
				if(rank[x]==rank[y])	rank[y]++;
			}
		}
	}
	int numDisjointSets(int i){
		return numSets;
	}
	int sizeOfSet(int i){
		return setSize[findSet(i)];
	}
};
int main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t,n,c1,c2,sc,usc;
	char cq;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>std::ws;
		UnionFind u(n);
		sc = usc = 0;
		while(getline(cin,s)&& s.length()){
			sscanf(s.c_str(),"%c %d %d",&cq,&c1,&c2);
			c1--; c2--;
			if(cq == 'c')				u.unionSet(c1,c2);
			else if(u.isSameSet(c1,c2))	sc++;
			else						usc++;
		}
		//cin>>std::ws;
		cout<<sc<<","<<usc<<"\n";
		if(t)	cout<<"\n";
	}     
 	return 0;
 } 
