
//Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.

#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define UNIQUE(X) (X).erase(unique(all(X)), (X)).end()
#define endl '\n'
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
 
const int mod = 1e9+7;
 
void solve(){
    int n,x; cin>>n>>x;
    vector<int>coins(n);
    rep(i,0,n)
    cin>>coins[i];
 
    vector<int>ans(x+3,0);
    ans[0] = 1;
 
    for(int i = 1; i<=x; i++){
        for(int j = 0; j<n; j++){
            if(i>=coins[j]){
                ans[i] += ans[i-coins[j]];
                ans[i] %= mod;
            }
        }
    }
 
    cout << ans[x] << endl;
}
 
int32_t main(){
 
   ios::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
 
   //int t; cin>>t; while(t--)
   solve();
 
   return 0;
}
