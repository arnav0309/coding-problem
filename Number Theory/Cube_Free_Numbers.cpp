//https://www.spoj.com/problems/CUBEFR/   
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

std::bitset<1000005>cube;
ump m;
void cubeFree(int n){
	cube.set();
	for (ll i=2;i*i*i<=n;i++)
	{
		if(cube[i])
		/* code */
		for(ll j=1;i*i*i*j<=n;j++){
			cube[i*i*i*j]=false;
		}
	}
	int g=1;
	m[1]=g;
	for(int i=2;i<1000005;i++){
		if(cube[i]) m[i]=++g;
	}
}


int main(int argc, char const *argv[])
{

    
    file_i_o();
    int t;
    cin>>t;
    cubeFree(1000005);
    for(int i=1;i<=t;i++){
    	int x;
    	cin>>x;
    	if(m.count(x)) cout<<"Case "<<i<<": "<<m[x]<<endl;
    	else  cout<<"Case "<<i<<": "<<"Not Cube Free"<<endl; 
    }

    return 0;

}