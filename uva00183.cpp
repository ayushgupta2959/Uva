using namespace std;
#include <bits/stdc++.h>
char type;
char output[50000];
int n,m,x,l;
string input;
void processB(int lr,int hr,int lc,int hc){
	cout<<lr<<hr<<lc<<hc<<'\n';
	if(lr>hr||lc>hc) return;
	int i,j,t=input[lr*m+lc],same=1;
	for(i=lr;i<=hr;i++){
		for(j=lc;j<=hc;j++){
			if(input[i*m+j]!=t){
				same=0;i=hr;j=hc;
			}
		}
	}
	if(same==1){
		cout<<(char)t;
		x++;
		if(x%50==0) cout<<'\n';
		return;
	}
	cout<<'D';
	x++;
	if(x%50==0) cout<<'\n';
	int midr,midc;
	midr = (hr+lr)/2;
	midc  =(hc+lc)/2;
	processB(lr,midr,lc,midc);
	processB(lr,midr,midc+1,hc);
	processB(midr+1,hr,lc,midc);
	processB(midr+1,hr,midc+1,hc);
}
void processD(int lr,int hr,int lc,int hc){
	if(lr>hr||lc>hc) return;
	if(input[x]=='D'){
		int midr,midc;
		midr = (hr+lr)/2;
		midc  =(hc+lc)/2;
		x++;
			processD(lr,midr,lc,midc);
			processD(lr,midr,midc+1,hc);
			processD(midr+1,hr,lc,midc);
			processD(midr+1,hr,midc+1,hc);	
		}
	else{
		for(int i=lr;i<=hr;i++)
			for(int j=lc;j<=hc;j++)
				output[i*m+j]=input[x];
		x++;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input.reserve(40000);
    while(cin>>type>>n>>m){
    	cin>>input;
    	cout<<input<<'\n';
    	x = 0;
    	if (type=='B') {
    		cout<<"D"<<right<<setw(4)<<n<<right<<setw(4)<<m;
    		processB(0,n-1,0,m-1); 
    	}
    	else{
    		cout<<"B"<<right<<setw(4)<<n<<right<<setw(4)<<m;
    		x=0;
    		processD(0,n-1,0,m-1);
    		int z = n*m;
    		for(int i=0;i<z;i++){
    			if(i%50==0)
    				cout<<'\n';
    			cout<<output[i];
    		}
    	} 
    	cout<<"\n";
    }
	return 0;
}