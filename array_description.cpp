const int mod = 1e9+7;
void solve(){
    int n,m; cin>>n>>m;
    int a[n];
    for(int i = 0; i<n; i++)
        cin>>a[i];
 
    int ans[n][m+1];
    memset(ans,0,sizeof(ans));
 
    ans[0][a[0]] = 1;
    if(a[0]==0){
        for(int i = 1; i<=m; i++)
            ans[0][i] = 1;
    }
 
    for(int i = 1; i<n; i++){
        int x = a[i];
        if(x==0){
            for(int v = 1; v<=m; v++){
                ans[i][v] = ans[i-1][v];
                if(v>1)
                    ans[i][v] = (ans[i][v] + ans[i-1][v-1])%mod;
                if(v<m)
                    ans[i][v] = (ans[i][v] + ans[i-1][v+1])%mod;
            }
        }
 
        else{
            ans[i][x] = ans[i-1][x];
            if(x>1)
                ans[i][x] = (ans[i][x] + ans[i-1][x-1]) % mod;
            if(x<m)
                ans[i][x] = (ans[i][x] + ans[i-1][x+1]) % mod;
        }
    }
 
    int ways = 0;
    for(int v = 1; v<=m; v++)
        ways = (ways + ans[n-1][v]) % mod;
 
    cout << ways << endl;
}
