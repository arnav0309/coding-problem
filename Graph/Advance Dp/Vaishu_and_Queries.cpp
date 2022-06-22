  //https://www.hackerearth.com/problem/algorithm/vaishu-and-queries-17506e73/

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


int dp[105][105][105];

int main(int argc, char const *argv[])
{

    
    file_i_o();
    int n;
    cin>>n;
    int red[105]={0};
    int blue[105]={0};
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        for(auto &ch:str){
            if(ch=='R') red[i]++;
            else blue[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int x=0;x<=100;x++){
            for(int y=0;y<=100;y++){
                if(i==1){
                    if(x>=red[i] and y>=blue[i]) dp[i][x][y]=1;
                }
                else{
                    dp[i][x][y] = dp[i-1][x][y];// not pick
                    if(x>=red[i] and y>=blue[i]) dp[i][x][y] = std::max(dp[i][x][y],1+dp[i-1][x-red[i]][y-blue[i]]);
                }
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int r,b;
        cin>>r>>b;
        cout<<dp[n][r][b]<<endl;
    }

    return 0;

}