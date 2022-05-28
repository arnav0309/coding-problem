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

void preorder_iterative(Node* root){
	if(root==NULL) return;
	stack<Node*>st;
	st.push(root);
	while(!st.empty()){
		cout<<st.top()->data<<" ";
		Node* curr = st.top();
		st.pop();
		if(curr->right){
			st.push(curr->right);
		}
		if (curr->left)
		{
			/* code */
			st.push(curr->left);
		}
	}
	return;
}

void preorder(Node* root){
	if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
	if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(Node* root){
	if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(int argc, char const *argv[])
{

    
    file_i_o();
    
    Node* root = build();
     preorder(root);
    cout<<endl;
    // postorder(root);
    // cout<<endl;
    // inorder(root);
    preorder_iterative(root);

    return 0;

}