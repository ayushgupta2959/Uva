using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long s,p;
    long long i,j,k,n,t,d;
    while(true){
    	cin>>s>>p;
    	if(s==0)	break;
    	n=1;
    	i=j=(s+1)/2;
    	k=0;
    	while(n*n<p){
    		n+=2;
    		k++;
    	}
    	n-=2;
    	n=n*n+1;
    	t=j-k;
    	i=i+k;
    	j = j+k-1;
    	d = p-n;
    	if(d<=(j-t)){
    		j=j-d;
    		cout<<"Line = "<<i<<", column = "<<j<<".\n";
    		continue;
    	}
    	d -= (j-t);
    	j = t;
    	t = i-2*k;
    	if(d<=(i-t)){
    		i=i-d;
    		cout<<"Line = "<<i<<", column = "<<j<<".\n";
    		continue;
    	}
    	d-=(i-t);
    	i=t;
    	t = j+2*k;
    	if(d<=(t-j)){
    		j=j+d;
    		cout<<"Line = "<<i<<", column = "<<j<<".\n";
    		continue;
    	}
    	d-=(t-j);
    	j=t;
    	t = i+2*k;
    	i=i+d;
    	cout<<"Line = "<<i<<", column = "<<j<<".\n";
    }
	return 0;
}