/*

You are given a family tree with N members numbered 1...N. Every person i,
except for the founder of the family(root)has a parent denoted by P[i].P[root]=-1 by definition.
Person i is a descendant of person j if i belongs to the subtree rooted at j.
The net worth(adjusted for inflation)is given for all the members of the family.
Your task is to find the maximum difference in net worth's of two members where
one member is a descendant of the other.
You can assume that no two members of this family married each other. So it remains a "family tree".

*/

// link:- https://www.codechef.com/problems/FAMTREE
   
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

vector<ll>wt(100005);
vector<ll>p(100005);
vector<vector<ll>>graph(100005);
ll mi[100005],ma[100005];
ll ans = 0;
void famtree(ll i,ll par){
    for(auto child:graph[i]){
        if(i!=par){
            famtree(child,i);
            ma[i] = max(ma[i],ma[child]);
            mi[i] = min(mi[i],mi[child]);
        }
    }
    mi[i]=min(mi[i],wt[i]);
    ma[i] = max(ma[i],wt[i]);
    ans = max(ans,abs(wt[i]-mi[i]));
    ans = max(ans,abs(wt[i]-ma[i]));
}
int main(int argc, char const *argv[])
{

    
    file_i_o();
    ll n;
    cin>>n;
    loop(i,1,n){
        cin>>wt[i];
    }
    loop(i,1,n){
        ma[i]=-inf;
        mi[i] = inf;
    }
    ll root = 0;
    loop(i,1,n){
        cin>>p[i];
        if(p[i]==-1){
            root=i;
        }else{
            graph[p[i]].pb(i);
        }
    }
    famtree(root,0);
    cout<<ans;
    return 0;

}