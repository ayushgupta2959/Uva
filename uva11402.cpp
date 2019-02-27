using namespace std;
#include <bits/stdc++.h>
typedef vector<int> vi;
vi A;
class SegmentTree{
public:
	vi st,lazy;
	int n;
	int left(int p) { return p<<1; }
	int right(int p) { return (p<<1)|1;}
	void build(int p,int L,int R){
		if(L==R) { 
			st[p] = A[L];
			return;
		}
		build(left(p),L,(L+R)/2);
		build(right(p),(L+R)/2+1,R);
		int p1 = st[left(p)];
		int p2 = st[right(p)];
		st[p] = operate(p1,p2);
	}
	//code to modify with each implementation
	//////////////////////////////////////////////////////////////////////////
	int operate(int p1,int p2){
		return p1+p2;
	}
	void propagate(int p,int L,int R,int val){
		if(val == 'F')			st[p] = R-L+1;
		else if(val == 'E')		st[p] = 0;
		else					st[p] = (R-L+1) - st[p];
		int p1 = left(p);
		int p2 = right(p);
		int x;
		if(L!=R){
			if(val=='E' || val =='F'){
				lazy[p1] = lazy[p2] = val;
				lazy[p] = 0;
				return;
			}
			if((x =lazy[p1])!=0){
				if(x=='I')	lazy[p1] = 0;
				else lazy[p1] = (x=='F')?'E':'F';
			}
			else	lazy[p1] = val;
			if((x =lazy[p2])!=0){
				if(x=='I')	lazy[p2] = 0;
				else lazy[p2] = (x=='F')?'E':'F';
			}
			else	lazy[p2] = val;
		}
		lazy[p] = 0;
	}
	int outOfRange(){
		return 0;//value to return during query when query range is out of segment range 
	}
	//////////////////////////////////////////////////////////////////////////
	int queryRange(int p,int L,int R,int l,int r){
		if(L>R||l>r)	return outOfRange();
		if(lazy[p]!=0) propagate(p,L,R,lazy[p]);
		if(L>r||l>R)	return outOfRange();
		if(L>=l&&R<=r)	return st[p];
		int p1 = queryRange(left(p),L,(L+R)/2,l,r);
		int p2 = queryRange(right(p),(L+R)/2+1,R,l,r);
		return operate(p1,p2);
	}
	void updateRange(int p,int L,int R,int l,int r,int new_value){
		if(L>R||l>r)	return;
		if(lazy[p]!=0) propagate(p,L,R,lazy[p]);
		if(L>r||l>R)	return;
		if(L>=l&&R<=r){
			propagate(p,L,R,new_value);
			return;
		}
		updateRange(left(p),L,(L+R)/2,l,r,new_value);
		updateRange(right(p),(L+R)/2+1,R,l,r,new_value);
		st[p] = operate(st[left(p)],st[right(p)]);
	}
	int queryRange(int l,int r){
		return queryRange(1,0,n-1,l,r);
	}
	void updateRange(int l,int r,int new_value){
		return updateRange(1,0,n-1,l,r,new_value);
	}
	SegmentTree(){
		n = A.size();
		st.assign(4*n,0);
		lazy.assign(4*n,0);
		build(1,0,n-1);
	}
};
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    A.reserve(1024000);
    int t,m,T,q,cas,Q,l,i;
    string s;
    s.reserve(55);		
    char ch;
    cin>>t;
    cas = 1;
    while(t--){
    	A.clear();
    	cin>>m;
    	while(m--){
    		cin>>T>>std::ws;
    		getline(cin,s);
    		l = s.length();
    		while(T--)	for(i=0;i<l;++i) A.emplace_back(s[i] -'0');
    	}
    	SegmentTree st;
    	cin>>q;
    	cout<<"Case "<<cas++<<":\n";
    	Q=1;
    	while(q--){
    		cin>>ch>>m>>T;
    		if(ch=='S')	cout<<"Q"<<Q++<<": "<<st.queryRange(m,T)<<"\n";
    		else st.updateRange(m,T,ch);
    	}
    }
	return 0;
}