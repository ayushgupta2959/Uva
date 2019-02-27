using namespace std;
#include <bits/stdc++.h>
/*deque<char> a;
void func2(deque<char>::iterator it){
    a.insert(it,'x');
    a.insert(it,'y');
    a.insert(it,'z');
    for(char x:a){
        cout<<x<<" ";
    }
    cout<<"\n";
}
void func1(deque<char>::iterator it){
    a.insert(it,'a');
    a.insert(it,'b');
    a.insert(it,'c');
    for(char x:a){
        cout<<x<<" ";
    }cout<<"\n";
    func2(it);
    a.insert(it,'d');
    a.insert(it,'e');
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*deque<char> a;
    //func1(a.begin());
    deque<char>::iterator it=a.begin();
    a.push_front('a');
    a.push_front('b');
    a.push_front('c');
    //func2(it);
    a.push_front('d');
    a.push_front('e');
    it = a.begin();
    //cout<<*it;
    //cout<<*(it+2);
    it+=2;
   //push_front t<<*it;
    for(char x:a){
        cout<<x<<" ";
    }*/
  /*  if(1==0&&0==0&&0==1) cout<<"j";
    else cout<<"k";
    return 0;

}*/
int main(){
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i = 10000000;
    cout<<i;
    cout<<' '<<"yes\n";
    int arr[] = {1,1,1,1,1,2,5,6,7,0,1};
    auto x = count(arr,arr+11,1);
    cout<<x;
    return 0;
}