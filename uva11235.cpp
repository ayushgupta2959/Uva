using namespace std;
#include <bits/stdc++.h>
typedef vector<int> vi;
//only for query
class SegmentTree{
private:
  vi st,A;
  int n;
public:
  int left(int p){
    return p<<1;
  }
  int right(int p){
    return (p<<1)+1;
  }
  //code to modify with each tree implementation
  /////////////////////////////////////////////////////////////////////
                        //range max
  int operate(int p1,int p2){
    return max(p1,p2);
  }
  int outOfRange(){
    return INT_MIN;
  }
  /////////////////////////////////////////////////////////////////////
  void build(int p,int L,int R){
    if(L==R){
      st[p] = A[R];
      return;
    }
    build(left(p),L,(L+R)/2);
    build(right(p),(L+R)/2+1,R);
    st[p] = operate(st[left(p)],st[right(p)]);
  }
  int queryRange(int p,int L,int R,int l,int r){
    if(L>R||l>R||L>r||l>r) return outOfRange();
    if(L>=l&&R<=r)  return st[p];
    int p1 = queryRange(left(p),L,(L+R)/2,l,r);
    int p2 = queryRange(right(p),(L+R)/2+1,R,l,r);
    if(p1 == outOfRange())  return p2;
    if(p2 == outOfRange())  return p1;
    return operate(p1,p2);
  }
  int queryRange(int l,int r){
    return queryRange(1,0,n-1,l,r);
  }
  SegmentTree(vi _A){
    A = _A;
    n = _A.size();
    st.reserve(4*n);
    build(1,0,n-1);
  }
};

int main(){
  #ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,q,i,j,k,c,cnt1,cnt2,cnt3;
  while(true){
    cin>>n;
    i=j=0;
    if(!n) break;
    cin>>q;
    vi v,count,start;
    v.reserve(n);count.reserve(n),start.reserve(n);
    copy_n(istream_iterator<int>(cin),n,back_inserter(v));
    vector<int>::iterator it = v.begin();
    while(it!=v.end()){
      auto x = lower_bound(it,v.end(),*it);
      auto y = upper_bound(it,v.end(),*it);
      c = (y-it) - (x-it);
      for(i=0;i<c;i++){
        count.push_back(c);
        start.push_back(j);
      }
      j = j+i;
      it = y;
    }
    SegmentTree s(count); 
    for(i=0;i<q;i++){
      cin>>j>>c;
      j--;c--;
      if(v[j]==v[c])  {cout<<(c-j+1)<<"\n"; continue;}
      k = count[j]+start[j]-1;
      cnt1 = k-j+1;
      cnt2 = c-start[c]+1;
      cnt3 = s.queryRange(k+1,start[c]-1);
      cout<<max(cnt1,max(cnt2,cnt3))<<"\n";
    }
  }  
  return 0;
}