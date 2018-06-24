using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,p,c,rc,j;
	double price,rprice;
	string r,name,rname;
	j=0;
	while(true){
		rprice = DBL_MAX;
		rc = INT_MIN;
		cin>>n>>p>>std::ws;
		if(n==0&&p==0)	break;
		if(j++!=0)	cout<<"\n";
		while(n--)	getline(cin,r);
		for(int i=0;i<p;i++){
			getline(cin,name);
			cin>>price>>c>>std::ws;
			if(c>rc){
				rc = c;
				rprice = price;
				rname = name;
			}
			else if((c==rc)&&(price<rprice)){
				rprice = price;
				rname = name;
			}
			while(c--)	getline(cin,r);
		}
		cout<<"RFP #"<<j<<"\n";
		cout<<rname<<"\n";
	}
	return 0;
}

