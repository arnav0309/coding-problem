#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<vi> vmi;
typedef vector<vpi> vmpi;

const int INF = 1e9 + 19;
const int LIM = 1e5 + 15;

void file_i_o(){
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   #ifndef ONLINE_JUDGE
       freopen("/home/anand/Desktop/InputOutput/input.txt", "r", stdin);
        freopen("/home/anand/Desktop/InputOutput/output.txt", "w", stdout);
    #endif 
}     






void dijkstra(int s,vb &mark,vi &dist,vmpi G)
{
    //fill(all(dist), +INF);
    //fill(all(mark), false);
    
    priority_queue<pi, vpi, less<pi> > pq;
    pq.push({dist[s] = 0, s});
    while (!pq.empty()) {
        int u = pq.top().se;
        pq.pop();
        
        if (mark[u]) continue; else mark[u] = true;
        for(auto v : G[u])
        {
            if (dist[v.fi] > dist[u] + v.se)
            {
                dist[v.fi] = dist[u] + v.se;
                pq.push({dist[v.fi], v.fi});
            }
        }
    }
}

int main()
{
	file_i_o();
   int testcase;
   cin>>testcase;
   while(testcase--){
   	int n, m;
   	cin >> n >> m;
    vmpi G;
    G.resize(n + 1);
    vb mark(n + 1, false);
   vi dist(n + 1,+INF);
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        G[u].pb({v, c});
    }

    int s, t;
    cin >> s >> t;

    dijkstra(s,mark,dist,G);
    if (dist[t] == INF)
        cout << "NO"<<endl;
    else 
      cout << dist[t]<<endl;


   }
    
        
    return 0;
}