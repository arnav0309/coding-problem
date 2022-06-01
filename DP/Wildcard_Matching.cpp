// https://leetcode.com/problems/wildcard-matching/

   
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




class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        if(n==0) return m==0;
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            if(p[i-1]=='*')
                dp[0][i]=true;
            else
                break;
            
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
                //else dp[i][j]=false;;
            }
        }
        return dp[m][n];
    }
};