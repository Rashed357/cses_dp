//Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
//For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.


#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define UNIQUE(X) (X).erase(unique(all(X)), (X)).end()
#define endl '\n'
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
 
const int inf = 1e16;
 
void solve(){
    int n,x; cin>>n>>x;
    vector<int>coin(n);
    rep(i,0,n)
    cin>>coin[i];
 
    vector<int>ans(x+3,inf);
 
    ans[0] = 0;
    for(int i = 1; i<=x; i++){
        for(int j = 0; j<n; j++){
            if(coin[j]<=i)
                ans[i] = min(ans[i],ans[i-coin[j]]+1);
        }
    }
 
    if(ans[x]==inf)
        cout<<-1<<endl;
    else
        cout<<ans[x]<<endl;
}
 
int32_t main(){
 
   ios::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
 
   //int t; cin>>t; while(t--)
   solve();
 
   return 0;
}
