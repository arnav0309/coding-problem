   
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

class TrieNode{
public:

    TrieNode *left;
    TrieNode *right;
};

void insert(ll x,TrieNode *temp){
    TrieNode *curr = temp;
    for(int i=31;i>=0;i--){
        int bit = (x>>i)&1;
        if(bit==0){
            if(curr->left==NULL) {
                
                curr->left = new TrieNode();
            }
            
                curr=curr->left;
            
        }else{
            if(curr->right==NULL) {
                curr->right = new TrieNode();
            }
            curr=curr->right;
        }
    }
}
ll findMaxXor(TrieNode *temp,int x){
    ll curr_xor = 0;
    TrieNode *curr = temp;
    for(int i=31;i>=0;i--){
        int bit = (x>>i)&1;
        if(bit==0){
            if(curr->right!=NULL){
                curr=curr->right;
                curr_xor+=(1<<i);
            }else{
            curr= curr->left;
            }
        }
        else{
            if(curr->left!=NULL){
                curr=curr->left;
                curr_xor+=(1<<i);
            }else{
            curr= curr->right;
            }
        }
    }
    return curr_xor;
}


int main(int argc, char const *argv[])
{

    
    file_i_o();
    int n;
    cin>>n;
    
    ll result = INT_MIN;
    TrieNode *temp = new TrieNode();
    if(n>0){
        ll x;
        cin>>x;
        insert(x,temp);
        n--;
    }
    while(n--){ 
        ll x;
        cin>>x;
        result = max(result,findMaxXor(temp,x));
        insert(x,temp);
    }
    cout<<result<<endl;
    return 0;

}
