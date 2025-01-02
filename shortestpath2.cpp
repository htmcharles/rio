#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

struct Edge {
    int fr, to, start_time, interval, cost;

    Edge(int fr, int to, int start_time, int interval, int cost)
        : fr(fr), to(to), start_time(start_time), interval(interval), cost(cost) {}

    int next_available(int t) const {
        if (t <= start_time) {
            return start_time - t;
        }
        if (interval == 0) {
            return -1; // Indicates no valid next time
        }
        int period = ceil(double(t - start_time) / interval);
        return (period * interval + start_time) - t;
    }
};

vector<int> dijkstra(int N, const vector<vector<Edge>> &adj, int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dists(N, numeric_limits<int>::max());

    pq.emplace(0, S);
    dists[S] = 0;

    while (!pq.empty()) {
        int t = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dists[u] < t) continue;

        for (const auto &e : adj[u]) {
            int wait = e.next_available(t);
            if (wait == -1) continue;

            int next_t = t + wait + e.cost;
            if (dists[e.to] <= next_t) continue;

            dists[e.to] = next_t;
            pq.emplace(next_t, e.to);
        }
    }

    return dists;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q, S;
    while (cin >> N >> M >> Q >> S, N || M || Q || S) {
        vector<vector<Edge>> adj(N);

        for (int i = 0; i < M; ++i) {
            int u, v, t, p, d;
            cin >> u >> v >> t >> p >> d;
            adj[u].emplace_back(u, v, t, p, d);
        }

        vector<int> dists = dijkstra(N, adj, S);

        for (int i = 0; i < Q; ++i) {
            int q;
            cin >> q;

            if (dists[q] < numeric_limits<int>::max()) {
                cout << dists[q] << '\n';
            } else {
                cout << "Impossible" << '\n';
            }
        }

        cout << '\n';
    }

    return 0;
}

