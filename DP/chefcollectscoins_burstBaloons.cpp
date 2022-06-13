   
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

ll func(vector<ll>& v){
    int n = v.size();
    vector<vector<ll> >dp(n, vector<ll>(n,0));
    for(int len = 0;len<n;len++){
        for(int i=0,j=len;j<n;j++,i++){
            for(int k=i;k<=j;k++){
                ll left_side = (k==i)?0:dp[i][k-1];
                ll right_side = (k==j)?0:dp[k+1][j];
                ll curr_last_burst_cost = ((i==0)?1:v[i-1])*v[k]*((j==n-1)?1:v[j+1]);
                dp[i][j] = std::max(dp[i][j],left_side+right_side+curr_last_burst_cost);
            }
        }
    }
    return dp[0][n-1];
}



int main(int argc, char const *argv[])
{

    
    file_i_o();
    int t;
    std::cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        cout<<func(v)<<endl;
    }

    return 0;

}