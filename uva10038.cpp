using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bitset<3000> check;
    int t,i,count,x;
    while(cin>>t){
    	std::vector<int> v;
    	v.reserve(t);
    	check.reset();
    	cin>>v[0];
    	for(i=1;i<t;++i){
    		cin>>v[i];
    		if((x = abs(v[i]-v[i-1]))<t)	check[x] = 1;
    	}
    	count = check.count();
    	if(count == t-1)	cout<<"Jolly\n";
    	else				cout<<"Not jolly\n";
    }
	return 0;
}