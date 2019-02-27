using namespace std;
#include <bits/stdc++.h>
int A[505][505];
int stMax[2020][2020];
int stMin[2020][2020];
int resultMax,resultMin;
class ST{
//private:
	//vector<vi> stMax,stMin      //using vector of int and then those reserve steps increased 
public:							 //processing time by 0.01 sec so better declare the tree globally 
	int n,m;					
	ST(int N,int M){
		n = N;
		m = M;
		//stMin.reserve(n<<2);
		//for(int i=0;i<n;i++)	stMin[i].reserve(m<<2);
		//stMax.reserve(n<<2);
		//for(int i=0;i<n;i++)	stMax[i].reserve(m<<2);
		build_x(1,0,n-1);
	}
	void build_y(int px,int Lx,int Rx,int py,int Ly,int Ry){
		if(Ly==Ry){
			if(Lx==Rx){
				stMin[px][py] = stMax[px][py] = A[Lx][Ly];
			}
			else{
				stMin[px][py] = min(stMin[px<<1][py],stMin[(px<<1)|1][py]);
				stMax[px][py] = max(stMax[px<<1][py],stMax[(px<<1)|1][py]);
			}
		}
		else{
			build_y(px,Lx,Rx,py<<1,Ly,(Ly+Ry)/2);
			build_y(px,Lx,Rx,(py<<1)|1,(Ly+Ry)/2+1,Ry);
			stMin[px][py] = min(stMin[px][py<<1],stMin[px][(py<<1)|1]);
			stMax[px][py] = max(stMax[px][py<<1],stMax[px][(py<<1)|1]);
		}
	}
	void build_x(int px,int Lx,int Rx){
		if(Lx!=Rx){
			build_x(px<<1,Lx,(Lx+Rx)/2);
			build_x((px<<1)|1,(Lx+Rx)/2+1,Rx);
		}
		build_y(px,Lx,Rx,1,0,m-1);
	}
	void query_y(int px,int py,int Ly,int Ry,int ly,int ry){
		if(Ly>ry||ly>Ry)	return;
		if(Ly>=ly&&Ry<=ry){
			resultMin = min(resultMin,stMin[px][py]);
			resultMax = max(resultMax,stMax[px][py]);
			return;
		}
		query_y(px,py<<1,Ly,(Ly+Ry)/2,ly,ry);
		query_y(px,(py<<1)|1,(Ly+Ry)/2+1,Ry,ly,ry);
	}
	void query_x(int px,int Lx,int Rx,int lx,int rx,int ly,int ry){
		if(lx>Rx||Lx>rx)	return;
		if(Lx>=lx&&Rx<=rx)	{
			query_y(px,1,0,m-1,ly,ry);
			return;
		}
		query_x(px<<1,Lx,(Lx+Rx)/2,lx,rx,ly,ry);
		query_x(px<<1|1,(Lx+Rx)/2+1,Rx,lx,rx,ly,ry);
	}
	void update_y(int px,int Lx,int Rx,int py,int Ly,int Ry,int x,int y,int val){
		if(Ly==Ry){
			if(Lx==Rx){
				stMin[px][py] = stMax[px][py] = val;
			}
			else{
				stMin[px][py] = min(stMin[px<<1][py],stMin[(px<<1)|1][py]);
				stMax[px][py] = max(stMax[px<<1][py],stMax[(px<<1)|1][py]);
			}
		}
		else{
			int mid = (Ly+Ry)/2;
			if(y<=mid)	update_y(px,Lx,Rx,py<<1,Ly,mid,x,y,val);
			else		update_y(px,Lx,Rx,(py<<1)|1,mid+1,Ry,x,y,val);
			stMin[px][py] = min(stMin[px][py<<1],stMin[px][(py<<1)|1]);
			stMax[px][py] = max(stMax[px][py<<1],stMax[px][(py<<1)|1]);
		}

	}
	void update_x(int px,int Lx,int Rx,int x,int y,int val){
		if(Lx!=Rx){
			int mid = (Lx+Rx)/2;
			if(x<=mid)	update_x(px<<1,Lx,mid,x,y,val);
			else		update_x((px<<1)|1,mid+1,Rx,x,y,val);
		}
		update_y(px,Lx,Rx,1,0,m-1,x,y,val);
	}
};
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n,i,k,a,b,c,d,j;
 	char e;
 	while(cin>>n){
 		for(i=0;i<n;i++)
 			for(j=0;j<n;j++)
 				cin>>A[i][j];
 		cin>>k;
 		ST st(n,n);
 		while(k--){
 			resultMin = INT_MAX;
 			resultMax = INT_MIN;
 			cin>>e;
 			if(e=='q'){
 				cin>>a>>b>>c>>d;
 				st.query_x(1,0,n-1,a-1,c-1,b-1,d-1);
 				cout<<resultMax<<" "<<resultMin<<"\n";
 			}
 			else{
 				cin>>a>>b>>c;
 				st.update_x(1,0,n-1,a-1,b-1,c);
 			}	
 		}
 	}
	return 0;
}
 
