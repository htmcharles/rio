#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

const int iinf = 1e9 + 10;
const ll inf = 1e18 + 10;

#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

template<class TIn>
using indexed_set = tree<
    TIn, null_type, less<TIn>,
    rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

ll readint(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg) return ret;
    else return -ret;
}

int n;

vector<int> getcycle(vector<vector<int>>& adj, int start) {
    vector<int> parent(n, -1);
    vector<int> dist(n, iinf);

    queue<int> q;
    for(auto i : adj[start]) {
        dist[i] = 1;
        q.push(i);
        parent[i] = start;
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto next : adj[curr]) {
            if(dist[curr] + 1 < dist[next]) {
                dist[next] = dist[curr] + 1;
                parent[next] = curr;
                q.push(next);
            }
        }
    }

    vector<int> cycle;
    if(dist[start] != iinf) {
        int curr = parent[start];
        parent[start] = -1;
        while(curr != start) {
            cycle.push_back(curr);
            curr = parent[curr];
        }
        cycle.push_back(start);
    }

    return cycle;
}

int main() {
    fast();

    cin >> n;

    unordered_map<string, int> conv;
    vector<string> conv_back;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        conv[s] = i;
        conv_back.push_back(s);
    }

    vector<vector<int>> adj(n);

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int lines;
        cin >> lines;

        while(lines--) {
            cin.ignore();
            string line;
            getline(cin, line);
            stringstream ss;
            ss << line;

            vector<string> v;
            string temp;
            while(ss >> temp) {
                v.push_back(temp);
            }

            for(int i = 1; i < v.size(); i++) {
                if(i != v.size()-1) {
                    v[i].pop_back();
                }
                adj[conv[s]].push_back(conv[v[i]]);
            }
        }
    }

    vector<int> bestcycle;

    for(int i = 0; i < n; i++) {
        vector<int> cycle = getcycle(adj, i);
        if(bestcycle.size() == 0) {
            bestcycle.swap(cycle);
        }
        else {
            if(cycle.size() != 0 && cycle.size() < bestcycle.size()) {
                bestcycle.swap(cycle);
            }
        }
    }

    if(bestcycle.size() == 0) {
        cout << "SHIP IT" << endl;
    }
    else {
        reverse(all(bestcycle));
        for(auto i : bestcycle) {
            cout << conv_back[i] << " ";
        }
        cout << endl;
    }
}

