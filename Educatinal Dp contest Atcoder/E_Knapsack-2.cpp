   
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




int main(int argc, char const *argv[])
{

    
    file_i_o();
    ll n,w;
    cin>>n>>w;
    vector<ll>wt(n);
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>wt[i]>>v[i];
    }
    vector<ll>vec1(n*1000+1);
    vector<ll>vec2(n*1000+1);
    loop(i,0,n*1000){
        vec1[i]=inf;
        vec2[i]=inf;
    }
    vec1[0]=0;
    vec1[v[0]]=wt[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=n*1000;j++){
            if(v[i]>j){
                vec2[j] = vec1[j];
            }
            else{
                vec2[j] = std::min({vec2[j],vec1[j],wt[i]+vec1[j-v[i]]});
            }
        }
        loop(k,0,n*1000){
            vec1[k]= vec2[k];
            vec2[k]=inf;
        }
    }
    ll result = 0;
    for(int i=0;i<vec1.size();i++){
        if(vec1[i]<=w){
            result = i;
        }
        
    }
    
    cout<<result<<endl;

    return 0;

}