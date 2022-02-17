#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
 
void BFS(int ind, vector<vector<int>> &vct, queue<int> &q, vector<int> &used, bool &flag) {
    used[ind] = 1;
    q.push(ind);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < vct[u].size(); i++) {
            if (used[vct[u][i]] == 1 and used[u] == 1) {
                flag = false;
            }
            if (used[vct[u][i]] == 2 and used[u] == 2) {
                flag = false;
            }
            if (used[vct[u][i]] == -1) {
                if (used[u] == 1) {
                    used[vct[u][i]] = 2;
                }
                if (used[u] == 2) {
                    used[vct[u][i]] = 1;
                }
                q.push(vct[u][i]);
            }
        }
    }
}
 
int main() {
    ifstream input_file("bipartite.in");
    ofstream output_file("bipartite.out");
 
    int m, n;
    input_file >> n >> m;
    vector<vector<int>> vct(n, vector<int>());
    vector<int> used(n, -1);
 
 
    for (int i = 0; i < m; i++) {
        int x, y;
        input_file >> x >> y;
        x--;
        y--;
        vct[x].push_back(y);
        vct[y].push_back(x);
    }
 
    queue<int> q;
    bool flag = true;
 
    for (int i = 0; i < n; i++) {
        if (used[i] == -1) BFS(i, vct, q, used, flag);
    }
 
    output_file << (flag ? "YES" : "NO");
 
    return 0;
}
