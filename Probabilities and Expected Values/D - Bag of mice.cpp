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
const int N=1005;

double dp[N][N];

double fun(int b, int w) {
    if(w==0) return 0.0;
    if(b==0) return 1.0;

    if(dp[b][w]>=-0.5) return dp[b][w];
    double tot=b+w;
    double res = (double)w/tot;

    if(b>=2) {
        double bb = b/tot * (b-1)/(tot-1);

        if(w>=1) {
            double wj = w/(tot-2);
            res+=bb*wj*fun(b-2,w-1);
        }

        if(b>=3) {
            double bj = (b-2)/(tot-2);
            res+=bb*bj*fun(b-3,w);
        }
    }

    return dp[b][w]=res;

}





void solve() {

    int b,w; cin>>w>>b;

    for(int i=0; i<=b; i++) {
        for(int j=0; j<=w; j++) dp[i][j]=-1.0;
    }

    cout << fixed << setprecision(10) << fun(b,w) << "\n";
}

int main() {
    FastIO


    //int TT=1; cin>>TT; while(TT--)
    solve();

    return 0;
}
