//https://atcoder.jp/contests/dp/tasks/dp_d

   
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
    int n,W;
    cin>>n>>W;
    vector<ll>v(n);
    vector<int>wt(n);
    for(int i=0;i<n;i++){
        cin>>wt[i]>>v[i];
    }


    vector<vector<ll>>dp(n+1,vector<ll>(W+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(j<wt[i-1]){
               dp[i][j] = dp[i-1][j];
            }
           else
           {
                dp[i][j] = std::max(dp[i-1][j],(v[i-1]+dp[i-1][j-wt[i-1]]));
            }
        }
    }
    cout<<dp[n][W];
    



    //cout<<knapsack(W,v,wt,n)<<endl;
    return 0;

}