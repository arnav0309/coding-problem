   
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


double dp[3005][3005];// dp[i][j]=prob to get atleast j heads in i coins
double coins(vector<double> &arr,int i,int x){
    if(x==0) return 1;
    if(i==0) return 0;
    if(dp[i][x]>-0.9) return dp[i][x];
    return dp[i][x] = coins(arr,i-1,x-1)*arr[i]+coins(arr,i-1,x)*(1-arr[i]);
}
int main(int argc, char const *argv[])
{

    
    file_i_o();
    int n;
    cin>>n;
    vector<double>arr(n+1);
    memset(dp,-1,sizeof(dp));
    loop(i,1,n){
        cin>>arr[i];
    }
    cout<<fixed<<setprecision(10)<<coins(arr,n,(n+1)/2);
    return 0;

}