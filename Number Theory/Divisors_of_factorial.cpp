   
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

// void file_i_o(){
//         ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//    #ifndef ONLINE_JUDGE
//        freopen("/home/anand/Desktop/InputOutput/input.txt", "r", stdin);
//         freopen("/home/anand/Desktop/InputOutput/output.txt", "w", stdout);
//     #endif 
// }     

#define MAX   50005
std::bitset<MAX>isPrime;
std::vector<int> primes;

void gen_prime(){
	isPrime.set();
	isPrime[0]=isPrime[1]=false;

	for(ll i=2;i*i<=MAX;i++){
		if(isPrime[i]){
			for(ll j=i;j*i<=MAX;j++){
				isPrime[j*i] = false;
			}
		}
	}
	primes.pb(2);
	for(ll i=3;i<=MAX;i+=2){
		if(isPrime[i]) primes.pb(i);
	}
}

ll division(int n){
     ll count = 1;
    	for(int i=0;primes[i]<=n;i++){
    		int num = primes[i];
    		ll ans=0;
    		while(n/num!=0){
    			ans=(ans+(n/num))%mod;
    			num=num*primes[i];

    		}
    		count = (count*(ans+1)%mod)%mod;
    	}
    	return count;
}

int main(int argc, char const *argv[])
{

    
    //file_i_o();
    gen_prime();
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	
    	cout<<division(n)<<endl;

    }

    return 0;

}