using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int m,n;
 	while(true){
 		cin>>m>>n;
 		if(m==0&&n==0)	break;
 		else if(m==0||n==0)	cout<<"0";
 		else if(m==1||n==1)	cout<<max(m,n);
 		else if(m==2){
 			if(((int)(ceil((float)n/2))%2)==1)	{
 				if(n%2==0)	cout<<2*(ceil((float)n/2)+1);
 				else		cout<<2*ceil((float)n/2);
 			}
 			else								cout<<2*ceil((float)n/2);
 		}	
 		else if(n==2){
 			if(((int)(ceil((float)m/2))%2)==1)	{
 				if(m%2==0)	cout<<2*(ceil((float)m/2)+1);
 				else		cout<<2*ceil((float)m/2);
 			}
 			else								cout<<2*ceil((float)m/2);
 		}
 		else if(m==3&&n==3)	cout<<"5";
 		else if(m>3||n>3) cout<<ceil((float)m*n/2);
 		cout<<" knights may be placed on a "<<m<<" row "<<n<<" column board.\n";
 	}   
	return 0;
}