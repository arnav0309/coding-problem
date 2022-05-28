   
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

class DLLNode{
   public:
   int key;
   int value;
   DLLNode* next;
   DLLNode* prev;
   DLLNode(int key,int value){
       this->key=key;
       this->value=value;
       this->next = NULL;
       this->prev = NULL;
   }
};
unordered_map<int,DLLNode*>cache;
DLLNode* head = new DLLNode(-1,-1);
DLLNode* tail = new DLLNode(-1,-1);
int siz;
int capacity;
void addNodeAtHead(DLLNode* node){
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    return;

}
void removeNode(DLLNode* node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
}
int removeFromTail(){
    DLLNode* temp = tail->prev;
    removeNode(temp);
    return temp->key;
}
void moveToHead(DLLNode* node){
    cout<<"Accessed the key "<<node->key<<endl;
    removeNode(node);
    addNodeAtHead(node);
}

int get(int k){
    if(cache.count(k)==0){
        cout<<"Value is not present in cache"<<endl;
        return INT_MIN;
    }
    DLLNode* node = cache[k];
    
    moveToHead(node);
    return node->value;
}

void put(int k , int v){
    if(cache.count(k)==0){
        //key is not present
        DLLNode* node = new DLLNode(k,v);
        cache[k]=node;
        cout<<"Added a key "<<k<<endl;
        addNodeAtHead(node);
        capacity++;
        if(capacity > siz){
            int removeKey = removeFromTail();
            cout<<"As the cache is full we need to remove the key "<<removeKey<<endl;
            capacity--;
            cache.erase(removeKey);
        }
    }
    else{
        //key is present
        DLLNode* node = cache[k];
        node->value = v;
        //removeNode(node);
        moveToHead(node);
    }
}

int main(int argc, char const *argv[])
{

    
    file_i_o();
    cout<<"Enter size of cache"<<endl;
    cin>>siz;
    head->next = tail;
    tail->prev = head;
    int t;
    cin>>t;
    while(t--){
        char ch;
        int k,v;
        cin>>ch;
        if(ch=='p'){
            cin>>k>>v;
            put(k,v);
        }
        else{
            cin>>k;
            int v = get(k);
            cout<<"value for key "<<k<<" is "<<v<<endl;
        }
    }
    return 0;

}