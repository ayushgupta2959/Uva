using namespace std;
#include <bits/stdc++.h>
#define num 2000000000
#define c 1000000
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,l,i1,j1,a;
    long long b;
    for(i=1;i<2001;i++){
    	if(pow(i,4)>num) break;
    	i1 = 2001-i;
    	for(j=i;j<i1;j++){
    		if(i*pow(j,3)>num) break;
    		j1 = i1 -j;
    		for(k=j;k<j1;k++){
    			if((i*j*k*k)>num) break;
    			b = i*j*k;
    			a = i+j+k;
    			if(b==c) continue;
    			if((a*c)%(b-c)!=0) continue;
    			l = (a*c)/(b-c);
    			if(k>l) continue;
    			if(a+l>2000) continue;
    			if(b*l>num) continue;
    			cout<<fixed<<setprecision(2)<<(double)i/100<<" "<<(double)j/100<<" "<<(double)k/100<<" "<<(double)l/100<<"\n";
    		}
    	}
    }
	return 0;
}