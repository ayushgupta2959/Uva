using namespace std;
 #include <bits/stdc++.h>
 int main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,y,k,val,j;
    cin>>t;
    j=1;
    while(t--){
    	vector<string> v;
    	v.reserve(52);
    	y = 0;
    	k=26;
    	copy_n(istream_iterator<string>(cin),52,back_inserter(v));
    	for (int i = 0; i < 3; ++i){
    		if(v[k].at(0)<='9'&&v[k].at(0)>='2')	val= v[k].at(0)-48;
    		else									val= 10;
    		y+=val;
    		k = k-11+val;
    	}
    	y--;
    	if(k<=y)	k=26-k+y;
    	cout<<"Case "<<j++<<": "<<v[k]<<"\n";
    }
 	return 0;
 } 
