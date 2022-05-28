// trie implementation  
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

class node{
public:
	int data;
	bool isTerminal=false;
	unordered_map<char, node*> children;
	node(char ch){
		this->data = data;
		this->isTerminal = false;
	}
};
class Trie{
public:
	node* root;
    Trie(){
    	this->root = new node('\0');
    }

    void insert(string str){
    	node* temp = this->root;
    	loop(i,0,str.size()-1){
    		char ch = str[i];
    		if(temp->children.count(ch)){
    			temp = temp->children[ch];
    		} else {
    			node * n = new node(ch);
    			temp->children[ch]=n;
    			temp=n;
    		}
    	}
    	temp->isTerminal=true;
    	return;
    }

    bool search(string str){
    	node* temp = this->root;
    	loop(i,0,str.size()-1){
    		char ch = str[i];
    		if(temp->children.count(ch)){
    			temp = temp->children[ch];
    		}
    		else return false;
    		}	
    		return temp->isTerminal==true;
    }

    void helperDfs(node* temp,string str,string osf){
    	if(temp == NULL) return;
    	if(temp->isTerminal==true){

    		cout<<str+osf<<endl;
    	}
    	for(auto ch: temp->children){
    		helperDfs(ch.ss,str,osf+ch.ff);
    	}
    }

    void printPrefix(string str){
    	node* temp = this->root;
    	loop(i,0,str.size()-1){
    		char ch = str[i];
    		if(temp->children.count(ch)){
    			temp=temp->children[ch];
    		} else {
    			cout<<"Query string is not present as prefix\n";
    			return;
    		}
          }
          helperDfs(temp,str,"");
    	}
    	
};


int main(int argc, char const *argv[])
{

    
    file_i_o();
    string str;
    int t;
    cin>>t;
    Trie tr;
    while(t--){
    	cin>>str;
      tr.insert(str);
    }
    int query;
    cin>>query;
    while(query--){
    	cin>>str;
    	cout<<((tr.search(str)==true)?"Yes" : "No")<<endl;
    }
    int p;
    cin>>p;
    while(p--){
    	cin>>str;
        cout<<"Prefixes are"<<endl;
    	tr.printPrefix(str);
    }
    
    return 0;

}