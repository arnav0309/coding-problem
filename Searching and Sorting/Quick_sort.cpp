   
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

int partition(vector<int>& v,int lo,int hi){
	int m = lo;
	int pivot = hi;
	for (int i = lo; i < hi; i++)
	{
		/* code */
		if(v[i]<v[pivot]){
			swap(v[i],v[m]);
			m++;
		}
	}
	swap(v[pivot],v[m]);
	return m;
}

int randomPivotAlgo(std::vector<int>& v,int lo,int hi){
	int n = rand();
	int pivot = lo+(n%(hi-lo+1));
	swap(v[pivot],v[hi]);
	return partition(v,lo,hi);
}

void Quicksort(std::vector<int>& v,int lo,int hi){
	if(lo<hi){
		int pivot_index = randomPivotAlgo(v,lo,hi);
		Quicksort(v,lo,pivot_index-1);
		Quicksort(v,pivot_index+1,hi);
	}
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
    Quicksort(v,0,n-1);
    for (int i = 0; i < n; i++)
    {
    	/* code */
    	cout<<v[i]<<" ";
    }
    return 0;

}