//https://atcoder.jp/contests/dp/tasks/dp_p   
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

void file_i_o(){
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   #ifndef ONLINE_JUDGE
       freopen("/home/anand/Desktop/InputOutput/input.txt", "r", stdin);
        freopen("/home/anand/Desktop/InputOutput/output.txt", "w", stdout);
    #endif 
}     

std::vector<int> g[100005];
ll dp[100005][2];
ll fun(int node, int u,int parent){
    if(dp[node][u]!=-1) return dp[node][u];
    ll ans=0;
    ll u0 = 1;
    for(auto child:g[node]){
    	if(child!=parent) u0=(u0*fun(child,0,node))%mod;
    }
    ans+=u0;
    if(not u){
    	ll u1=1;
    	for(auto child : g[node]){
    		if(child!=parent) u1=(u1*fun(child,1,node))%mod;
    	}
    	ans=(ans%mod+u1%mod)%mod;
    }
    return dp[node][u] = ans;
}


int main(int argc, char const *argv[])
{

    
    file_i_o();
    int n;
    std::cin>>n;
    std::memset(dp, -1, sizeof dp);
    loop(i, 0, n-2) {
        int x, y;
        std::cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    std::cout<<fun(1, 0, -1)<<"\n";

    return 0;

}