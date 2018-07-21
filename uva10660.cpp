using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[5][5],t,n,r,x,y,dist,c,o[5][3],i,j,k,l,m,d,res[5][3];
    cin>>t;
    while(t--){
    	memset(a,0,sizeof(a));
    	cin>>n;
    	while(n--){
    		cin>>r>>c;
    		cin>>a[r][c];
    	}
    	dist = INT_MAX;
    	for(i=0;i<25;i++){
    		for(j=i+1;j<25;j++){
    			for(k=j+1;k<25;k++){
    				for(l=k+1;l<25;l++){
    					for(m=l+1;m<25;m++){
    						o[0][0] = i;o[0][1] = i/5;o[0][2]= i%5;
    						o[1][0] = j;o[1][1] = j/5;o[1][2]= j%5;
    						o[2][0] = k;o[2][1] = k/5;o[2][2]= k%5;
    						o[3][0] = l;o[3][1] = l/5;o[3][2]= l%5;
    						o[4][0] = m;o[4][1] = m/5;o[4][2]= m%5; 
    						d=0;
    						for(x=0;x<5;x++){
    							for(y=0;y<5;y++){
    								d += min((abs(x-o[0][1])+abs(y-o[0][2]))
    									,min((abs(x-o[1][1]) + abs(y-o[1][2]))
    										,min((abs(x-o[2][1]) + abs(y-o[2][2]))
    											,min((abs(x-o[3][1]) + abs(y-o[3][2]))
    												,(abs(x-o[4][1]) + abs(y-o[4][2]))))))*a[x][y];
    							}
    						}
    						if(d<dist)	{
    							dist=d;
    							for(x=0;x<5;x++){
    								for(y=0;y<3;y++){
    									res[x][y] = o[x][y];
    								}
    							}
    						}
    					}
    				}
    			}	
    		}
    	}
    	cout<<res[0][0];
    	for(x=1;x<5;x++){
    		cout<<" "<<res[x][0];
    	}
    	cout<<"\n";
    }
	return 0;
}