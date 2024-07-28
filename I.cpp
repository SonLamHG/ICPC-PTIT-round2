#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200000;

vector<int> parent(MAXN);
vector<int> rrank(MAXN);
vector<int> adj[MAXN];
vector<bool> exists(MAXN, false);

void make_set(int v) {
    parent[v] = v;
    rrank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rrank[a] < rrank[b])
            swap(a, b);
        parent[b] = a;
        if (rrank[a] == rrank[b])
            rrank[a]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;  // zero-indexed
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        --P[i];  // zero-indexed
    }

    for (int i = 0; i < N; ++i)
        make_set(i);

    vector<string> result(N);
    int components = 0;

    for (int i = N - 1; i >= 0; --i) {
        int u = P[i];
        exists[u] = true;
        components++;

        for (int v : adj[u]) {
            if (exists[v]) {
                if (find_set(u) != find_set(v)) {
                    union_sets(u, v);
                    components--;
                }
            }
        }

        if (components == 1) {
            result[i] = "YES";
        } else {
            result[i] = "NO";
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
