 // Marix chain multiplication  
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

long long int mcm(vi &v,int i,int j){
    if(i==j) return 0;
    ll ans =INT_MAX;
    for(int k=i;k<j;k++){
        ans = min(ans,mcm(v,i,k)+mcm(v,k+1,j)+v[i-1]*v[k]*v[j]);
    }
    return ans;
}
// int dp[100][100];
// ll mcmDp(vi &v,int i,int j){
//     if(i==j) return 0;
//    if(dp[i][j]!=-1) return dp[i][j];
//    ll ans = INT_MAX;
//     for(int k=i;k<j;k++){
//         ans = min(ans,mcmDp(v,i,k)+mcmDp(v,k+1,j)+v[i-1]*v[k]*v[j]);
//     }
//     return dp[i][j] = ans;
// }

ll mcmBu(vector<ll>&v){
    int n = v.size();
    vector<vector<ll>>dp(n,vector<ll>(n,INT_MAX));
    for(int i=0;i<n;i++) dp[i][i]=0;

    for(int len=2;len<n;len++){
        for(int i=1;i<=(n-len);i++){
            int j = i+len-1;
            //if(j==n) continue;
            //dp[i][j] = INT_MAX;
            for(int k=i;k<j;k++){
                dp[i][j] = std::min(dp[i][j],dp[i][k]+dp[k+1][j]+v[i-1]*v[k]*v[j]);
            }
        }
    }
    loop(i,0,n-1){
        loop(j,0,n-1){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[1][n-1];
}

int main(int argc, char const *argv[])
{

    
    file_i_o();
   int n;
   cin>>n;
   vi v(n);
   //memset(dp,-1,sizeof(dp));
   for(int i=0;i<n;i++){
       cin>>v[i];
   }
  //cout<<mcm(v,1,n-1)<<endl;
  //cout<<mcmDp(v,1,n-1)<<endl;
  cout<<mcmBu(v)<<endl;
    return 0;

}