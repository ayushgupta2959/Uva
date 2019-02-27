using namespace std;
#include <bits/stdc++.h>
int main(){
	#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int arr[6]={1,2,3,4,5,6};
 	auto x=lower_bound(arr+6,arr+6,5);
 	cout<<(x-arr);   
	return 0;
}