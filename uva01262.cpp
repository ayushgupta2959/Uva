using namespace std;
#include <bits/stdc++.h>
int t,k,noSol;
char m1[5][6];
char m2[5][6];
int mt[5];
char ans[5];
int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,z,l;
    char c;
    cin>>t;
    while(t--){
    	cin>>k;
		for(i=0;i<6;i++){
			for(j=0;j<5;j++){
				cin>>m1[j][i];
			}
		}
		for(i=0;i<6;i++){
			sort(m1[i],m1[i]+6);
		}
		/*for(i=0;i<5;i++){
			for(j=0;j<6;j++){
				cout<<m1[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		memset(mt,0,sizeof(mt));
		for(i=0;i<30;i++){
			cin>>c;
			j=i%5;
			if(binary_search(m1[j],m1[j]+6,c)){
				if(mt[j]){
					int flag=0;
					for(l=0;l<mt[j];l++){ if(c==m2[j][l]) {flag=1;break;}}
					if(flag) continue;
				}
				m2[j][mt[j]++]=c;
			}			
		}
		for(i=0;i<5;i++){
			sort(m2[i],m2[i]+mt[i]);
		} 
		for(i=0;i<5;i++){
			for(j=0;j<mt[i];j++){
				cout<<m2[i][j]<<" ";
			}
			cout<<"\n";
		}
		for(i=0;i<5;i++) cout<<mt[i]<<" ";
		cout<<"\n";
		//this sol accepted
		noSol =1;
		int m,n,o,p,q,x;
		x=0;
		for(m=0;(m<mt[0])&&noSol;m++){
			for(n=0;(n<mt[1])&&noSol;n++){
				for(o=0;(o<mt[2])&&noSol;o++){
					for(p=0;(p<mt[3])&&noSol;p++){
						for(q=0;(q<mt[4])&&noSol;q++){
							x++;
							if(x==k){
								ans[0]=m2[0][m];
								ans[1]=m2[1][n];
								ans[2]=m2[2][o];
								ans[3]=m2[3][p];
								ans[4]=m2[4][q];
								noSol=0;
							}
						}
					}
				}
			}
		}
		if(noSol) cout<<"NO";
		else for(i=0;i<5;i++) cout<<ans[i];
   		cout<<"\n";


		//
		//getting WA for this solution
		/*noSol=1;
		int mul;
		i=j=z=l=0;
		//if(k==0) {
		//	cout<<"\n";
		//	continue;
		}
		while(noSol){
			//if(i==5) break;
			//if(k==0){
			//	noSol=0;
			//	break;
			//}
			mul=1;
			for(l=i+1;l<5;l++) mul*=mt[l];
			if(mul>=k) {
				ans[i]=m2[i][j];
				i++;
				j=0;
				if(i==5&&(mul-k)==0) noSol=0;
			}
			else{
				k-=mul;
				j++;
				if(j>=mt[i]) break;
			}
		}
		if(noSol) cout<<"NO";
		else for(i=0;i<5;i++) cout<<ans[i];
   		cout<<"\n";*/
    }
	return 0;
}