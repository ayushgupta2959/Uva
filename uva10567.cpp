using namespace std;
#include <bits/stdc++.h>
int arr[52][1000001],q,mtarr[52],mtquery[52],x,y;
string s;
string ss;
void process(){
	int l=s.length(),i,sub;
	for(i=0;i<l;i++){
		if(isupper(s[i])) sub=65;
		else sub = 71; 
		arr[s[i]-sub][mtarr[s[i]-sub]++]=i; 
	}
}
bool solve(){
	int indexReached=0,sub;
	int l=ss.length()-1,i;
	if(isupper(ss[0])) sub = 65;
	else sub = 71;
	if(l==0){
		x=y=arr[ss[0]-sub][0]; 
		return true;
	}
	if(mtarr[ss[0]-sub]){
		x=indexReached=arr[ss[0]-sub][0];
		mtquery[ss[0]-sub]++;
	}
	else return false;
	for(i=1;i<l;i++){
		if(isupper(ss[i])) sub=65;
		else sub=71;
		int z = ss[i]-sub;
		if(!mtarr[z]) return false;
		auto w = (upper_bound(arr[z]+mtquery[z],arr[z]+mtarr[z],indexReached))-arr[z];
		if(w==mtarr[z]) return false;
		indexReached=arr[z][w];
		mtquery[z]=w;
	}
	if(isupper(ss[l])) sub = 65;
	else sub = 71;
	int z = ss[i]-sub;
	auto w = (upper_bound(arr[z]+mtquery[z],arr[z]+mtarr[z],indexReached))-arr[z];
	if(w==mtarr[z]) return false;
	y = arr[z][w];
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    s.reserve(1000001);
    ss.reserve(101);
    cin>>s;
    cin>>q;
    memset(mtarr,0,sizeof(mtarr));
    process();
    while(q--){
    	cin>>ss;
    	memset(mtquery,0,sizeof(mtquery));
    	if(solve()) cout<<"Matched "<<x<<" "<<y<<"\n";
    	else cout<<"Not matched\n";
    }
    return 0;
}
 
