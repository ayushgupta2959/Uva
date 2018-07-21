using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,i,j,k,l;
    string t[1000];
    int n[1000000],z;
    int miN,x;
    while(cin>>m>>std::ws){
    	for(i=0;i<m;i++){
    		getline(cin,t[i]);
    	}
    	z=0;
    	for(i=0;i<m;i++){
    		for(j=0;j<m;j++){
    			miN = INT_MAX;
    			if(t[i][j]=='1'){
    				for(k=0;k<m;k++){
    					for(l=0;l<m;l++){
    						if(t[k][l]=='3'&&(abs(i-k)+abs(j-l))<miN) miN = abs(i-k)+abs(j-l); 
    					}
    				}
    			}
    			if(miN<INT_MAX)	n[z++] = miN;
    		}
    	}
    	cout<<*max_element(n,n+z)<<"\n";
    }
	return 0;
}