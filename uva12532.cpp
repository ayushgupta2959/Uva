using namespace std;
#include <bits/stdc++.h>
typedef vector<int> vi;
int LSOne(int S){ return (S & (-S));}
int A[1000005];
//Using Fenwick Tree
/*class FT{
private:
	vi ft;
public:
	FT(int n){
		ft.assign(n+1,0);
	}
	int query(int b){
		int sum = 0;
		for(;b;b-=LSOne(b))	sum+=ft[b];
		return sum;
	}
	int query(int a,int b){
		return query(b) - ((a==1)?0:query(a-1));
	}
	void adjust(int k,int v){
		int size = (int)ft.size();
		for(;k<size;k+=LSOne(k))	ft[k] += v;
	}
};
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,i,a,b,n;
    char c;
    while(cin>>n>>k){
    	FT neg(n),zero(n);
    	for(i=1;i<=n;++i){
    		cin>>A[i];
    		if(A[i]==0)	zero.adjust(i,1);
    		else if(A[i]<0)	neg.adjust(i,1);
    	}
    	while(k--){
    		cin>>c>>a>>b;	
    		if(c=='P'){
    			if(zero.query(a,b))	cout<<"0";
    			else if(neg.query(a,b)&1) cout<<"-";
    			else cout<<"+";
    		}
    		else{
    			if(A[a]*b<0)
    				neg.adjust(a,1);
    			else if(A[a]==0){
    				if(b>0) zero.adjust(a,-1);
    				else if(b<0) {
    					neg.adjust(a,1);
    					zero.adjust(a,-1);
    				}
    			}
    			else if(b==0&&A[a]<0){
    				neg.adjust(a,1);
    				zero.adjust(a,1);    				
    			}
    			else if(b==0&&A[a]>0)	zero.adjust(a,1);
    		A[a]=b;
    		}    	
    	}
    	cout<<"\n";  	
    }
	return 0;
}*/
//Using Segment Tree
class ST{
private:
	vi st;
	int n;
public:
	ST(int N){
		n = N;
		st.reserve(4*N);
		build(1,0,N-1);
	}
	void build(int p,int L,int R){
		if(L==R){
			st[p] = A[L];return;
		}
		build(p<<1,L,(L+R)/2);
		build((p<<1)+1,(L+R)/2+1,R);
		st[p] = st[p<<1]*st[(p<<1)+1];
	}
	int query(int p,int L,int R,int l,int r){
		if(L>r||l>R)	return 5;
		if (L >= l && R <= r) return st[p];
		int p1 = query(p<<1,L,(L+R)/2,l,r);
		int p2 = query((p<<1)+1,(L+R)/2+1,R,l,r);
		if(p1 == 5)	return p2;
		if(p2 == 5)	return p1;
		return p1*p2;
	}
	void update(int p,int L,int R,int idx,int val){
		if(L>idx||R<idx)	return;
		if(L==idx&&R==idx){
			st[p] = val;
			return;
		}
		update(p<<1,L,(L+R)/2,idx,val);
		update((p<<1)+1,(L+R)/2+1,R,idx,val);
		st[p] = st[p<<1]*st[(p<<1)+1];
	}
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,i,x,q;
    char c;
    while(cin>>n>>k){
    	for(i=0;i<n;i++){
    		cin>>x;
    		A[i] = (x>0)?1:((x==0)?0:-1);
    	}
    	ST st(n);
    	while(k--){
    		cin>>c>>i>>x;
    		if(c=='P'){
    			q = st.query(1,0,n-1,i-1,x-1);
    			if(q<0)	cout<<"-";
    			else if(q==0)	cout<<"0";
    			else cout<<"+";
    		}
    		else{
    			x = (x>0)?1:((x==0)?0:-1);
    			st.update(1,0,n-1,i-1,x);
    		}
    	}
    	cout<<"\n";
    }
	return 0;
}
