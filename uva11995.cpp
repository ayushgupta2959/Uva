using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int fs,fq,fp;
    int n,t,x;
    while(cin>>n){
    	stack<int> s;
	    queue<int> q;
	    priority_queue<int> p;
	    fs = fq = fp = 1;	
	    while(n--){
	    	cin>>t>>x;
	    	if(t==1){
	    		if(fs)	s.push(x);
	    		if(fq)	q.push(x);
	    		if(fp)	p.push(x);
	    	}
	    	else{
	    		if(fs){
	    			if((s.size())&&(s.top()==x)) s.pop();
	    			else	fs=0;
	    		}
	    		if(fq){
	    			if((q.size())&&(q.front()==x)) q.pop();
	    			else	fq=0;
	    		}if(fp){
	    			if((p.size())&&(p.top()==x)) p.pop();
	    			else	fp=0;
	    		}
	    	}
	    }
	    if(!(fs||fq||fp))	cout<<"impossible\n";
	    else if((fs&&fp)||(fp&&fq)||(fs&&fq)||(fs&&fp&&fq))	cout<<"not sure\n";
	    else if(fs)	cout<<"stack\n";
	    else if(fq)	cout<<"queue\n";
    	else if(fp)	cout<<"priority queue\n";
    }
	return 0;
}