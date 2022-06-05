   
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

int gameTopDown(vector<int>v,int i,int j){
    int n = v.size();
    int dp[n][n];
    memset(dp,-1,sizeof(dp));
    if(i==j) return v[i];
    if(i+1==j) return max(v[i],v[j]);
    int op1 = v[i]+min(gameTopDown(v,i+2,j),gameTopDown(v,i+1,j-1));
    int op2 = v[j]+min(gameTopDown(v,i+1,j-1),gameTopDown(v,i,j-2));
    dp[i][j] = max(op1,op2);
    return dp[i][j];
}

int game(vector<int>& v){ //Bootom up solution
    int n = v.size();
    int dp[n][n];
    memset(dp,-1,sizeof(dp));
    for(int len=0;len<n;len++){
        for(int i=0,j=len;i<=len,j<n;i++,j++){
            int a = ((i+2)<=j)?dp[i+2][j]:0;
            int b = ((i+1)<=j-1)?dp[i+1][j-1]:0;
            int c = (i<=j-2)?dp[i][j-2]:0;
            dp[i][j] = max(v[i]+min(a,b),v[j]+min(b,c));
        }
    }
        return dp[0][n-1];
    }



int main(int argc, char const *argv[])
{

    
    file_i_o();
    int n;
    cin>>n;
    vector<int>v(n);
    loop(i,0,n-1) cin>>v[i];
    cout<<game(v)<<endl;
    cout<<gameTopDown(v,0,n-1);
    return 0;

}