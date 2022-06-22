   
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

vector<ll>graph[100005];
ll dp[100005][2];
ll func(int node,int c,int par){
    if(dp[node][c]!=-1) return dp[node][c];
    ll result=0,way1=1;
    for(auto child:graph[node]){
        if(child!=par){
            way1=(way1*func(child,0,node));
        }
    }
    result+=way1;
    
    if(!c){
        ll way2=1;
        for(auto child:graph[node]){
            if(child!=par){
              way2 = (way2*func(child,1,node));
            }
        }
        result+=way2;
    }
    
    return dp[node][c] = result;
}


int main(int argc, char const *argv[])
{

    
    file_i_o();
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    loop(i,0,n-2){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    std::cout<<func(1,0,-1)<<endl;
    return 0;

}