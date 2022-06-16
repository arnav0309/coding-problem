//https://www.spoj.com/problems/TOURIST/   
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

ll dp[105][105][105];
char ch[105][105];
ll n,m;
ll dx1[] = {1,1,0,0};
ll dx2[] = {1,0,1,0};
ll dy1[] = {0,0,1,1};
ll dy2[] = {0,1,0,1};
ll tour(ll x1,ll y1,ll x2,ll y2){
    
    if(x1>n or y1>m or x2>n or y2>m or ch[x1][y1]=='#' or ch[x2][y2]=='#'){
        return -inf;
    }
    if(x1==n and y1==m) return (ch[x1][y1]=='*');
    if(dp[x1][y1][x2]!=-1) return dp[x1][y1][x2];
    ll result = -inf;
    loop(i,0,3){
        result = std::max(result,tour(x1+dx1[i],y1+dy1[i],x2+dx2[i],y2+dy2[i]));
    }
    result+=(ch[x1][y1]=='*');
    result+=(ch[x2][y2]=='*');
    if(x1==x2 and y1==y2 and ch[x1][y1]=='*') result-=1;
    return dp[x1][y1][x2]=result;
}


int main(int argc, char const *argv[])
{

    
    file_i_o();
   ll t;
   cin>>t;
   while(t--){
    cin>>m>>n;
    memset(dp,-1,sizeof dp);
    loop(i,1,n){
        loop(j,1,m){
            cin>>ch[i][j];
        }
    }
    cout<<tour(1,1,1,1)<<endl;
   }

    return 0;

}