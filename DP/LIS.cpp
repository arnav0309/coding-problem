   
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

int lis(std::vector<int> v){   // time complexity O(n^2)
	int n = v.size();
	std::vector<int> dp(n,1);
	for (int i = 1; i < n; i++)
	{
		/* code */
		for (int j = 0; j < i; j++)
		{
			/* code */
			if(v[i]>v[j]){
				dp[i]=max(dp[i],1+dp[j]);
			}
		}
	}
	return *max_element(dp.begin(),dp.end());
}


int main(int argc, char const *argv[])
{

    
    file_i_o();
    int n;
    cin>>n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
    	/* code */
    	cin>>v[i];

    }
    cout<<lis(v);

    return 0;

}