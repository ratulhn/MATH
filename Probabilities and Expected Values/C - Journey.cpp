#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

#define FastIO ios::sync_with_stdio(false);cin.tie(nullptr);
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << "\n";
//#include "dbgtest.h"
#define ll long long
#define all(v) v.begin(),v.end()
#define nl cout<<'\n'
#define lp(i,a,n) for(int i=a; i<n; i++)

const int M = 1e9+7;



double dfs(vector<int>g[], int u, int p) {
    double res=0.0;
    int cnt=0;
    for(auto v:g[u]) {
        if(v==p) continue;
        cnt++;
        res+=dfs(g,v,u);
    }

    if(cnt==0) return 0;

    return 1.0+(res/cnt);

}




void solve() {

    int n; cin>>n;
    vector<int>g[n+1];
    lp(i,0,n-1) {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    double res=dfs(g,1,0);

    cout << fixed << setprecision(15) << res << "\n";


}

int main() {
    FastIO


    //int TT=1; cin>>TT; while(TT--)
    solve();

    return 0;
}
