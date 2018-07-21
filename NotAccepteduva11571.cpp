using namespace std;
#include <bits/stdc++.h>
long long result[3];
/*int main(){
		#ifndef ONLINE_JUDGE
	   	freopen("../../input.txt", "r", stdin);
	    freopen("../../output.txt", "w", stdout);
		#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x,y,z,A,B,C,Bbyx,range;
    int t,noSol;
    cin>>t;
    while(t--){
    	cin>>A>>B>>C;
    	noSol = 1;
    	range = min(sqrt(C/3),cbrt(B))+1;
    	//cout<<range<<"\n";
    	for(x =(-range);(x<0)&&noSol;x++){
    		if(x*x>C) continue;
    		if(B%x!=0) continue;
    		Bbyx = B/x;
    		if((A-x)*(A-x) != (C + (2*Bbyx) - x*x)) continue;
    		if((A-x)*(A-x) < 4*Bbyx) continue;
    		y = (A-x-sqrt((A-x)*(A-x)-(4*Bbyx)))/2;
    		if(x==y) continue;
    		if(x*x+y*y>C) continue;
    		if(B%y!=0)continue;
    		z = A-x-y;
    		if(x==z||y==z) continue;
    		if(B%z!=0) continue;
    		if((x*x + y*y + z*z) !=C)continue;
    		noSol = 0;
    		result[0] = x;
    		result[2] = y;
    		result[1] = z;
    		sort(result,result+3);
    		cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<"\n";
    	}
    	for(x =1;(x<=range)&&noSol;x++){
    		if(x*x>C) continue;
    		if(B%x!=0) continue;
    		Bbyx = B/x;
    		if((A-x)*(A-x) != (C + (2*Bbyx) - x*x)) continue;
    		y = (A-x-sqrt((A-x)*(A-x)-(4*Bbyx)))/2;
    		if(x==y) continue;
    		if(B%y!=0)continue;
    		z = A-x-y;
    		if(x==z||y==z) continue;
    		if(B%z!=0) continue;
    		if((x*x + y*y + z*z) !=C)continue;
    		noSol = 0;
    		result[0] = x;
    		result[2] = y;
    		result[1] = z;
    		sort(result,result+3);
    		cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<"\n";
    	}
    	if(noSol) cout<<"No solution.\n";
    }
	return 0;
}*/
int main(){
        #ifndef ONLINE_JUDGE
           freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w", stdout);
        #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x,y,z,A,B,C,range,AminusX,BbyX,temp;
    int t,noSol;
    cin>>t;
    while(t--){
    	cin>>A>>B>>C;
    	noSol = 1;
    	range = min(sqrt(C/3),cbrt(B))+1;
    	for(x=-range;x<=range&&noSol;x++){
    		AminusX = A-x;
    		if(x==0||B%x!=0||x*x>C) continue;
    		BbyX = B/x;
    		if(C+2*BbyX - x*x != AminusX*AminusX) continue;
    		if(AminusX*AminusX < 4*BbyX) continue;
    		temp = sqrt(AminusX*AminusX - 4*BbyX);
    		y = (AminusX + temp)/2;
    		z = (AminusX - temp)/2;
    		if(x==y||x==z||y==z) continue;
    		noSol = 0;
    		result[0] = x;
    		result[2] = y;
    		result[1] = z;
    		sort(result,result+3);
    		cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<"\n";
    	}
    	if(noSol) cout<<"No solution.\n";
    }
    return 0;
}
/*This input also not passed*/
//Input
//1
//3464101614 2999999996297300442 5999999992594600886
//Myoutput
//No solution.
//Actual output
//-1732050805 -1 1732050807