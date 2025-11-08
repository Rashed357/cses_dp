 
void solve(){
    int n,x; cin>>n>>x;
    int price[n],pages[n];
    rep(i,0,n)
    cin>>price[i];
    rep(i,0,n)
    cin>>pages[i];
 
    vector<int>ans(x+1,0);
 
    for(int i = 0; i<n; i++){
        for(int sum = x; sum>=price[i]; sum--)
            ans[sum] = max(ans[sum],ans[sum-price[i]]+pages[i]);
    }
 
    cout << ans[x] << endl;
}
