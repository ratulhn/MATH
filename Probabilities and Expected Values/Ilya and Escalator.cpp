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
const int N=2005;
int n,t;
double p;
double dp[N][N];

double fun(int i, int t) {
    if(t==0) return i;
    if(i==n) return i;

    if(dp[i][t]>=-0.5) return dp[i][t];

    double in = fun(i+1,t-1);
    double st = fun(i,t-1);

    return dp[i][t]=p*in+(1.0-p)*st;

}




void solve() {

    cin>>n>>p>>t;

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=t; j++) dp[i][j]=-1.0;
    }

    

    cout << fixed << setprecision(10) << fun(0,t) << "\n";


}

int main() {
    FastIO


    //int TT=1; cin>>TT; while(TT--)
    solve();

    return 0;
}
