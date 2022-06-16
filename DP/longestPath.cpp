   
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

vector<int>g[10005];
int dp[10005];

int path(int src){
    if(dp[src]!=-1) return dp[src];
    int max_value = 0;
    int leaf =1;
    for(auto x:g[src]){
        leaf=0;
        max_value = max(max_value,path(x));
    }
    return dp[src] = leaf?0:(1+max_value);
}

int main(int argc, char const *argv[])
{

    
    file_i_o();
    memset(dp,-1,sizeof dp);
    int n,m;
    cin>>n>>m;
    loop(i,0,m-1){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    int result = INT_MIN;
    loop(i,1,n){
        result = max(result,path(i));
    }
    cout<<result;
    return 0;

}