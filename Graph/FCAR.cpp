//https://www.codechef.com/problems/INSQ15_F

   
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define MP make_pair
#define pb push_back
#define X first
#define Y second

typedef long long ll;

#define INF (ll)1e18

long long dijk (int st, int end, vector<pair<int, int> > G[], int n) {
	vector<long long> dist (n, INF);
	dist[st] = 0;
	set<pair<long long, int> > q; // cost, node
	q.insert (make_pair (0, st));
	while (!q.empty ()) {
		pair<long long, int> top = *q.begin ();
		q.erase (q.begin ());
		int v = top.second;
		long long d = top.first;
		if (v == end)
			break;
		for (vector<pair<int, int> >::iterator it = G[v].begin (); it != G[v].end (); it++) {
			int v2 = it->first;
			long long cost = it->second;
			if (dist[v2] > dist[v] + cost) {
				if (dist[v2] != INF) {
					q.erase (q.find (make_pair (dist[v2], v2)));
				}
				dist[v2] = dist[v] + cost;
				q.insert (make_pair (dist[v2], v2));
			}
		}
	}
	if (dist[end] == INF) {
		return -1;
	}
	return dist[end];
}

int main()
{
	int t, n, m, i, j, x, y;
	cin >> n >> m;
	vector<int> h(n + 1), c(n + 1);
	vector<pair<int, int> > G[2 * n + 2];
	for (i = 1; i <= n; i++) {
		cin >> h[i];
	}
	//G1 from 1 to N
	//G2 from N + 1 to 2 * N
	for (i = 1; i <= n; i++) {
		cin >> c[i];
		G[i].pb (MP (n + i, c[i]));
		G[n + i].pb (MP (i, c[i]));
	}
	for (i = 1; i < m; i++) {
		cin >> x >> y;
		if (h[x] <= h[y])
			G[x].pb (MP (y, 0));
		if (h[x] >= h[y])
			G[n + x].pb (MP (n + y, 0));
		if (h[y] <= h[x])
			G[y].pb (MP (x, 0));
		if (h[y] >= h[x])
			G[n + y].pb (MP (n + x, 0));
	}
	G[0].pb(MP (1, c[1]));
	G[0].pb(MP (n + 1, c[1]));
	G[n].pb(MP (2 * n + 1, 0));
	G[2 * n].pb(MP (2 * n + 1, 0));
	cout << dijk(0, 2 * n + 1, G, 2 * n + 2);
    return 0;
}