   
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

void bubble_sort(vector<int>& v){
	for(int i=0;i<v.size()-1;i++){
		bool sorted = false;
		for(int j=0;j<v.size()-i-1;j++){
			if(v[j]>v[j+1]){
			swap(v[j],v[j+1]);
			sorted = true;
		}
		}
		if(not sorted) break;
		
	}
}


int main(int argc, char const *argv[])
{

    
    file_i_o();
    vector<int>v{5,6,2,6,9,0,-1};
    bubble_sort(v);
    loop(i,0,v.size()-1){
    	cout<<v[i]<<" ";
    }

    return 0;

}