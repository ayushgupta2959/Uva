 using namespace std;
 #include <bits/stdc++.h>
 vector<string> b;
 vector<string> s;
 vector<string> v;
 int N,n;
 void rotate(){
 	int i,j;
 	for(i=0;i<n;++i)
 		for (j = 0; j < n; ++j)
 			v[j][n-1-i] = s[i][j];
	for(i=0;i<n;++i)
 		for(j = 0; j < n; ++j)
 			s[i][j] = v[i][j];
 }
 bool check(int i,int j){
 	int k,l;
 	for(k=0;k<n;++k){
 		for(l=0;l<n;++l){
 			if(s[k][l]!=b[i+k][j+l]){
 				return false;
 			}
 		}
 	}
 	return true;
 }
 int match(){
 	int i,j,count=0;
 	for(i=0;i+n<=N;i++){
 		for(j=0;j+n<=N;j++){
 			if(check(i,j)){
 				count++;
 			}
 		}
 	}
 	return count;
 }
 int main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    string t;
    t.resize(1000);
    b.resize(1000,t);
    s.resize(1000,t);
    v.resize(1000,t);
    while(true){
    	cin>>N>>n>>std::ws;
    	if(N==0)	break;
    	for(i=0;i<N;++i)	getline(cin,b[i]);
    	for(i=0;i<n;++i)	getline(cin,s[i]);
		for(i=0;i<4;++i){
			if(i){
				rotate();
				cout<<" ";
			}
			cout<<match();
		}
		cout<<"\n";

    }
 	return 0;
 }
