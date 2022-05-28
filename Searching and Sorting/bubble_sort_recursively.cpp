   
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

void bubble_recursive(vector<int>& v,int i,int n){
   if(n==1) return;
   if(i==n-1){
   	for(int i=0;i<v.size();i++){
   		cout<<v[i]<<" ";
   	}
    cout<<endl;
   	bubble_recursive(v,0,n-1);
    return;
   }

   if(v[i]>v[i+1]){
   	swap(v[i],v[i+1]);
   }
   bubble_recursive(v,i+1,n);   
}


int main(int argc, char const *argv[])
{

    
    file_i_o();
    std::vector<int> v{2,7,5,9,3,0,-1};
    bubble_recursive(v,0,v.size());

    return 0;

}