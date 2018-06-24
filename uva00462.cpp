using namespace std;
#include <bits/stdc++.h>
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int mat[4][7];
 	char c;
 	int i,j=0,k=0,points1,points2,index,m,flag;
 	while(cin>>c){
 		points1=0;
 		points2=0;
 		index=-1;
 		m = INT_MIN;
 		flag=0;
 		memset(mat,0,sizeof(mat));
 		for (i = 0; i < 13; ++i){
	 		if(i!=0) cin>>c;
	 		if(c=='A')		{k=0;points1+=4;}
	 		else if(c=='K')	{k=1;points1+=3;}
	 		else if(c=='Q')	{k=2;points1+=2;}
	 		else if(c=='J')	{k=3;points1+=1;}
	 		else			k=4;
	 		cin>>c;
	 		if(c=='S')		j=0;
	 		else if(c=='H')	j=1;
	 		else if(c=='D')	j=2;
	 		else 			j=3;
	 		mat[j][k]++;
 			mat[j][5]++;
	 	}
	 	for (int i = 0; i < 4; ++i) {
	 		if(mat[i][1]==1&&mat[i][5]==1)	points1--;
	 		if(mat[i][2]==1&&mat[i][5]<=2)	points1--;
	 		if(mat[i][3]==1&&mat[i][5]<=3)	points1--;
	 	}
	 	points2 = points1;
	 	for (int i = 0; i < 4; ++i) {
	 		if(mat[i][5]==2)				points2++;
	 		else if(mat[i][5]==1)			points2 +=2;
	 		else if(mat[i][5]==0)			points2 +=2;
	 		if((mat[i][0]==1)||(mat[i][1]==1&&mat[i][5]>=2)||(mat[i][2]==1&&mat[i][5]>=3))
	 			mat[i][6] = -1;
	 	}
	 	for (int i = 0; i < 4; ++i){
	 		if(mat[i][5]>m)	{
	 			m = mat[i][5];
	 			index = i;
	 		}
	 	}
	 	if(points2<14)	cout<<"PASS\n";
	 	else if(points1>=16&&mat[0][6]==-1&&mat[1][6]==-1&&mat[2][6]==-1&&mat[3][6]==-1)
	 		cout<<"BID NO-TRUMP\n";
	 	else if(points2>=14){
	 		if(index==0)		cout<<"BID S\n";
	 		else if(index==1)	cout<<"BID H\n";
	 		else if(index==2)	cout<<"BID D\n";
	 		else				cout<<"BID C\n";
	 	}
	}
	return 0;
}