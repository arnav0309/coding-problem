/*
You're given a tree with N vertices numbered from 1 to N.A tree is defined as a
connected,undirected graph with N vertices and N-1 edges.
Your task is to find the minimum size of the vertex set in this tree such that each
edge has as least one of its end-points present in that set.

*/

   // checking
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
int dp[100005][2];
int vc(int src,int g,vector<vector<int>>&graph,vector<int>&p){
     if(graph[src].size()==0) return g;
     if(dp[src][g]!=-1) return dp[src][g];
     int sum = 0;
     for(auto child:graph[src]){
        if(child!=p[src]){
            p[child]  =src;
            if(!g){
                sum+= vc(child,1,graph,p);
            }else{
                sum+=std::min(vc(child,1,graph,p),vc(child,0,graph,p));
            }
        }
     }
     return dp[src][g] = sum+g;
}


int main(int argc, char const *argv[])
{

    
    file_i_o();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>graph(n+1,vector<int>(0));
        vector<int>p(n+1,-1);
        memset(dp,-1,sizeof dp);
        loop(i,0,n-2){
            int x,y;
            cin>>x>>y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        cout<<std::min(vc(1,0,graph,p),vc(1,1,graph,p))<<endl;
    }
    return 0;

}