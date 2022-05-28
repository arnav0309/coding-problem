   
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


class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

Node* build(){
	int d;
	cin>>d;
	if(d==-1) return NULL;
	Node* root = new Node(d);
	root->left=build();
	root->right = build();
	return root;
}

int height(Node* root){
   if(root == NULL) return 0;
   if(root->left == NULL and root->right==NULL) return 0;
   int lh = height(root->left);
   int rh = height(root->right);
   return max(lh,rh)+1;
}

int diameter(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL and root->right == NULL) return 0;
    int left = diameter(root->left);
    int right = diameter(root->right);
    int lh = height(root->left);
    int rh = height(root->right);
    int via_node = lh+rh+(root->left!=NULL)+(root->right!=NULL);
    return max({lh,rh,via_node});
}

int main(int argc, char const *argv[])
{

    
    file_i_o();
    
    Node* root = build();
    cout<<diameter(root);

    return 0;

}