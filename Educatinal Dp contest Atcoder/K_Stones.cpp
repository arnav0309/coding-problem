   
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
#define vs                 vector<string>=
#define mii                map<ll, ll>
#define ump                unordered_map<ll, ll>
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
       freopen("C:/Users/arnav/Desktop/InputOutput/input.txt", "r", stdin);
        freopen("C:/Users/arnav/Desktop/InputOutput/output.txt", "w", stdout);
    #endif 
}     




int main(int argc, char const *argv[])
 {
 
     file_i_o();
      int n,k;
      cin>>n>>k;
      vector<int>v(n);
      loop(i,0,n-1) cin>>v[i];
      vector<bool>dp(k+1,0);
      dp[0]=0;
      loop(i,1,k){
        loop(j,0,n-1){
            if(v[j]>i) continue;
            if(dp[i-v[j]]==0){
                dp[i]=1;
            }
            
        }
      }
      if(dp[k]==0) cout<<"Second";
      else cout<<"First";
     return 0;

 }