using namespace std;
#include <bits/stdc++.h>
#define toggleBit(S, j) (S ^= (1 << j))
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>	v;
    vector<int> z;
    int n,w,s,x;
    x = pow(2,15);
    v.reserve(x);
    z.reserve(x);
    while(cin>>n){
    	x = pow(2,n);
	    for(int i=0;i<x;++i) cin>>v[i];
	    for (int i = 0; i < x; ++i){
	    	bitset<15> b(i);
	    	s=0;
			for (int j = 0; j < n; ++j){
				s+=v[toggleBit(b,j).to_ulong()];
				toggleBit(b,j);
			}
			z[i] = s;
	    }
	    w = INT_MIN;
	    for (int i = 0; i < x; ++i){
	    	bitset<15> b(i);
			for (int j = 0; j < n; ++j){
				if((s=z[i]+z[toggleBit(b,j).to_ulong()])>w)	w=s;
				toggleBit(b,j);
			}
	    }
	    cout<<w<<"\n";
	}
    
	return 0;
}