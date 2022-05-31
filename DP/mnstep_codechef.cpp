/*Given two stringsSandIconsists of only lowercase characters.Chef wants to
convert S to T and to achieve that he can do one of the following operations in
each step:
 •Insertacharacter at any position.
 •Deleteacharacter at any position.
   Replaceacharacter with another character at any position.
Help Chef to find the minimum number of steps needed to convertSto T.

*/
   
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
bool comp(int a, int b)
{
    return (a < b);
}

int fun(string s1,string s2){
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;

            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+ min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    return dp[m][n];
}

int main(int argc, char const *argv[])
{

    
    file_i_o();
    string s1,s2;
    cin>>s1>>s2;
    cout<<fun(s1,s2);
    return 0;

}