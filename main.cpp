#include <iostream>
#include <vector>

using namespace std;

int depth[1005];
int parent[1005];

void build_tree(int current_depth, int current_parent) {
    int val;
    if (!(cin >> val)) return;
    if (val == -1) return;
    
    depth[val] = current_depth;
    parent[val] = current_parent;
    
    build_tree(current_depth + 1, val);
    build_tree(current_depth + 1, val);
}

int main() {
    int q;
    if (!(cin >> q)) return 0;
    
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    build_tree(0, -1);
    
    for (int i = 0; i < q; ++i) {
        int u = queries[i].first;
        int v = queries[i].second;
        if (depth[u] == depth[v] && parent[u] != parent[v]) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}

