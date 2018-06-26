using namespace std;
#include <bits/stdc++.h>
bool check[53];
int findnext(int x){
	while(++x<=52){
		if(check[x]==false)	return x;
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int princess[3];
    int prince[2];
    int a,b,c,x,y;
    while(true){
    	memset(check,false,sizeof(check));
    	cin>>princess[0]>>princess[1]>>princess[2]>>prince[0]>>prince[1];
    	if(princess[0] == 0)	break;
    	a = min(princess[0],min(princess[1],princess[2]));
    	c = max(princess[0],max(princess[1],princess[2]));
    	b=princess[0]+princess[1]+princess[2]-a-c;
    	x = min(prince[0],prince[1]);
    	y = max(prince[0],prince[1]);
    	check[a] =check[b] =check[c] =check[x] =check[y] =true; 
    	if(y<c){
    		if(x<b)	cout<<"-1\n";
    		else			cout<<findnext(b)<<"\n";
    	}
    	else{
    		if(x<c){
    			if(x<b)	cout<<findnext(c)<<"\n";
    			else			cout<<findnext(b)<<"\n";
    		}
    		else	cout<<findnext(0)<<"\n";
    	}
    }
	return 0;
}