//https://atcoder.jp/contests/dp/tasks/dp_g

   
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

std::vector<int> dp(100005,-1);
vector<int>graph[100005];
int fun(int i){
    if(dp[i]!=-1) return dp[i];
     int maxVal=0;
     bool leaf =  true;
     for(int neighbour : graph[i]){
        leaf = false;
        maxVal = max(maxVal,fun(neighbour));
     }
     return dp[i]= (leaf) ? 0 : 1+maxVal;
}


int main(int argc, char const *argv[])
{

    
    file_i_o();

    int n,m;
    cin>>n>>m;
    
    while(m--){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		//graph[v].push_back(u);//for undirected
	}
    int ans = INT_MIN;
    for(int i=1;i<=n;i++){
        ans = max(ans,fun(i));
    }
    cout<<ans<<endl;

    return 0;

}