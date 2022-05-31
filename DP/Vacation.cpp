//https://atcoder.jp/contests/dp/tasks/dp_c

   
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




int main(int argc, char const *argv[])
{

    
    file_i_o();
    int n;
    cin>>n;
    vector<vector<int>>dp(3,vector<int>(n,0));
    int a,b,c;
    cin>>a>>b>>c;
    dp[0][0]=a;
    dp[1][0] = b;
    dp[2][0] = c;
    
    loop(i,1,n-1){
        cin>>a>>b>>c;
        dp[0][i] = a+max(dp[1][i-1],dp[2][i-1]);
        dp[1][i] = b+max(dp[0][i-1],dp[2][i-1]);
        dp[2][i] = c+max(dp[1][i-1],dp[0][i-1]);
    }
    cout<<max({dp[0][n-1],dp[1][n-1],dp[2][n-1]});
    return 0;

}