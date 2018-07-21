using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,z,A,B,C,t,noSol,xy;
    cin>>t;
    while(t--){
    	cin>>A>>B>>C;
    	noSol = 1;
	    for(x=-100;(x<101)&&noSol;x++){
	    	for(y=x+1;(y<101)&&noSol;y++){
	    		if((x*x + y*y + pow((A-x-y),2))!=C) continue;
	    		xy=x*y;
	    		if(xy==0){
	    			if(x==0) y=101;
	    			continue;
	    		}
	    		if(B%(x*y)!=0) continue;
	    		z = B/(x*y);
	    		if(x==z||y==z) continue;
	    		if((x+y+z)!=A) continue;
	    		cout<<x<<" "<<y<<" "<<z<<"\n";
	    		noSol =0;
	    	}
	    }
	    if(noSol) cout<<"No solution.\n";
	}
	return 0;
}