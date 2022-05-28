// min heap
   
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




void downHeapify(int idx,vector<int>&arr){
	int lc = 2*idx+1;
	int rc=2*idx+2;
	if(lc>=arr.size() and rc>=arr.size()) return;
	int largest = idx;
	if(lc<arr.size() and arr[lc]<arr[largest]) largest=lc;
	if(rc<arr.size() and arr[rc]<arr[largest]) largest=rc;
	if(largest==idx) return;
	swap(arr[idx],arr[largest]);
	downHeapify(largest,arr);
}
void upHeapify(int idx,vector<int>&arr){
    if(idx==0) return;
    int pi = (idx-1)/2;
    if(arr[pi]>arr[idx]){
    	swap(arr[pi],arr[idx]);
    	upHeapify(pi,arr);
    }
    else return;
}

void insert(vector<int>&arr,int key){
	arr.push_back(key);
	upHeapify(arr.size()-1,arr);
}

int get(vector<int>&arr){
	return arr[0];
}

void removePeek(vector<int>&arr){
     swap(arr[arr.size()-1],arr[0]);
     arr.pop_back();
     downHeapify(0,arr);	
}


void buildHeap(vector<int>& arr){
	int i = arr.size()-1;
	i=(i/2)+1;
	while(i>=0){
		downHeapify(i,arr);
		i--;
	}
}

int main(int argc, char const *argv[])
{

    
    file_i_o();
    int n;
    cin>>n;
    vector<int>arr;
    while(n--){
    	int x;
    	cin>>x;
    	//insert(arr,x);
    	arr.push_back(x);
    }
    //removePeek(arr);
    buildHeap(arr);
    for (int i = 0; i < arr.size(); ++i)
    {
    	/* code */
    	cout<<arr[i]<<" ";
    }

    return 0;

}

