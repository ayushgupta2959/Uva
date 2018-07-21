using namespace std;
#include <bits/stdc++.h>
long long s,d,sXord;
long long sum,sumFive,maX;
int amt[12];
void solve(int n){
	if(n<5){
		amt[n] = s;
		sumFive+=s;
		sum+=s;
		solve(n+1);
		sumFive = sumFive-s+d;
		sum = sum-s+d;
		amt[n]^=sXord;
		solve(n+1);
		sumFive -= d;
		sum -= d;
		return;
	}
	if(sumFive>0) return;
	if(n==12) {
		if(sum>maX) maX=sum;
		return;
	}
	amt[n] = s;
	sum+=s;
	sumFive = sumFive - amt[n-5] + s;
	solve(n+1);
	sumFive = sumFive-s+d;
		sum = sum-s+d;
		amt[n]^=sXord;
		solve(n+1);
		sumFive = sumFive - d + amt[n-5];
		sum -= d;
		amt[n] =0;
		return; 
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>s>>d){
    	d = -d;
    	maX = 0;
    	sumFive=0;
    	sum =0 ;
    	sXord = s^d;
    	memset(amt,0,sizeof(amt));
    	solve(0);
    	if(maX>0) cout<<maX<<"\n";
    	else cout<<"Deficit\n";
    }
	return 0;
}