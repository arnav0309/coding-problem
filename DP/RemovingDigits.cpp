//https://cses.fi/problemset/task/1637

   
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

vi getdigits(int n){
	vi v;
	while(n){
		if(n%10!=0){
			v.pb(n%10);
		}
		n/=10;
	}
	return v;
}


int main(int argc, char const *argv[])
{

    
    file_i_o();
    int n;
    cin>>n;
    vi dp(n+1,inf);
    loop(i,1,9) dp[i]=1;
    loop(i,10,n){
    	vi digits = getdigits(i);
    	for(auto j:digits){
    		dp[i]=min(dp[i],1+dp[i-j]);
    	}

    }
    cout<<dp[n];

    return 0;

}