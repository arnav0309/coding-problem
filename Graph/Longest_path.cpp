   
#include <bits/stdc++.h>
using namespace std;

#define ff                 first
#define ss                 second
#define ll                 long long int
#define ld                 long double
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<ll, ll>
#define vi                 vector<ll>
#define vs                 vector<string>
#define mii                map<ll, ll>
#define ump                unordered_map<ll, ll>
#define all(n)               n.begin(),n.end()
#define mid(l,r)           (l+(r-l)/2)
#define pq_max             priority_queue<ll>
#define pq_min             priority_queue<int, vi, greater<ll> >
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x, y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)     type *arr = new type[n];
#define w(x)               int x; cin>>x; while(x--)
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)

// void file_i_o(){
//         ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//    #ifndef ONLINE_JUDGE
//        freopen("/home/anand/Desktop/InputOutput/input.txt", "r", stdin);
//         freopen("/home/anand/Desktop/InputOutput/output.txt", "w", stdout);
//     #endif 
// }     

ll dp[100005];
std::vector<int> g[100005];
ll longest_path(int src) {
    if(dp[src] != -1) return dp[src];
    ll max_val = 0;
    bool leaf = 1;
    for(int child : g[src]) {
        leaf = 0;
        max_val = std::max(max_val, longest_path(child));
    }
    return dp[src] = leaf ? 0 : 1 + max_val;
}

int main(int argc, char const *argv[]) {
    //clock_t begin = clock();
    //file_i_o();
    // Write your code here....
    std::memset(dp, -1, sizeof dp);
    int n, m;
    std::cin>>n>>m;
    loop(i, 0, m-1) {
        int x, y;
        std::cin>>x>>y;
        g[x].pb(y);
    }

    ll result = INT_MIN;
    loop(i, 1, n) {
        result = std::max(result, longest_path(i));
    }
    std::cout<<result<<"\n";
    return 0;
}