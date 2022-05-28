   
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

void selection_sort(vector<int>& v){
	int n = v.size();
	int i;
	for(i=1;i<n;i++){
		int el=v[i];
		int j=i-1;
		while(j>=0 and v[j]>el){
			v[j+1]=v[j];
			j-=1;
		}
		v[j+1]=el;
	}
}


int main(int argc, char const *argv[])
{

    
    file_i_o();
    
    vector<int>v{9,5,7,3,2,-1,0};
    selection_sort(v);
    for (int i = 0; i < v.size(); ++i)
    {
    	/* code */
    	cout<<v[i]<<" ";
    }
    return 0;

}