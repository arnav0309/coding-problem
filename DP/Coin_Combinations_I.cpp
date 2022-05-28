//https://cses.fi/problemset/task/1635

   
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
const int MOD = (int) 1e9 + 7;

ll func(ll n,std::vector<ll> v, std::vector<ll> &dp){
    if(n==0) return dp[n]=1;

    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    dp[n]=0;
    
    loop(i,0,v.size()-1){
        dp[n]+=func(n-v[i],v,dp);
        dp[n]%=MOD;
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{

    
    file_i_o();
    ll n,x;
    cin>>n>>x;
    std::vector<ll> v(n);
    std::vector<ll> dp(x+1,-1);
    loop(i,0,n-1) cin>>v[i];
    cout<<func(x,v,dp);
    return 0;

}