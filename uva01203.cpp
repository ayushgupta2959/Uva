using namespace std;
#include <bits/stdc++.h>
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
class myComparator
{
public:
    bool operator() (const iii& x1, const iii& x2)
    {
        return (x1.second.first > x2.second.first)||((x1.second.first == x2.second.first)&&(x1.first > x2.first));
    }
};
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<iii,vector<iii>,myComparator> pq;
    string s;
    int q,p,k;
    iii x;
    while(true){
    	cin>>s;
    	if(s[0]=='#')	break;
    	cin>>q>>p;
    	pq.push(make_pair(q,make_pair(p,p)));
    }
    cin>>k;
    while(k--){
    	x = pq.top();
    	cout<<x.first<<"\n";
    	x.second.first += x.second.second;
    	pq.pop();
    	pq.push(x);
    }
    	
	return 0;
}