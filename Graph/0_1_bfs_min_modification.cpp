   
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




std::vector< std::vector<std::pair<int, int> > > g;
int label(int i, int j, char d, int n, int m) {
    if(d == 'U') {
        i--;
    } else if (d == 'L') {
        j--;
    } else if(d == 'R') {
        j++;
    } else if(d == 'D') {
        i++;
    }
    if(i < 0 or j < 0 or i >= n or j >= m) return -1;
    return (i*m + j);
}
char dir(int x) {
    if(x == 0) return 'L';
    if(x == 1) return 'U';
    if(x == 2) return 'R';
    if(x == 3) return 'D';

}
int bfs(int n, int m) {
    std::deque<int> qu;
    std::vector<int> dist(n*m, INT_MAX);
    int src = 0, dest = (n-1)*m + (m-1);
    dist[src] = 0;
    qu.pb(src);
    while(not qu.empty()) {
        int curr = qu.front();
        qu.pop_front();
        for(auto n : g[curr]) {
            if(dist[n.ff] > dist[curr] + n.ss) {
                dist[n.ff] = dist[curr] + n.ss;
                if(n.ss == 0) {
                    qu.push_front(n.ff);
                } else {
                    qu.pb(n.ff);
                }
            }
        }
    }
    return dist[dest];
}
int min_modifications(std::vector<std::vector<char> > &mat, int n, int m) {
    g.resize(n*m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int d = 0; d < 4; d++) {
                int l = label(i, j, dir(d), n, m);
                if(l == -1) continue;
                if(dir(d) == mat[i][j]) {
                    g[i*m+j].pb({l, 0});
                } else {
                    g[i*m+j].pb({l, 1});
                }
            }
        }
    }
    // for(auto &v : g) {
    //     for(auto &el : v) {
    //         std::cout<<el.ff<<"->"<<el.ss<<" , ";
    //     }
    //     std::cout<<"\n";
    // }
    return bfs(n, m);
}

int main(int argc, char const *argv[]) {
    //clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n, m;
    std::cin>>n>>m;
    std::vector<std::vector<char> > mat(n, std::vector<char> (m, ' '));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin>>mat[i][j];
        }
    }
    std::cout<<min_modifications(mat, n, m)<<"\n";
    
    return 0;
}