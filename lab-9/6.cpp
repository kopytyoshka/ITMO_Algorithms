#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
 
int dfs(int ind, vector<vector<int>> &vct, vector<int> &used) {
    if (used[ind] != -1) {
        return used[ind];
    }
    used[ind] = -2;
    for (int i = 0; i < vct[ind].size(); i++) {
        if (dfs(vct[ind][i], vct, used) == -2) {
            used[ind] = 2;
        }
    }
    return used[ind];
}
 
 
int main() {
    ifstream input_file("game.in");
    ofstream output_file("game.out");
 
    int n, m, s;
    input_file >> n >> m >> s;
 
    vector<vector<int>> vct(n, vector<int>());
    vector<int> used(n, -1);
 
    for (int i = 0; i < m; i++) {
        int x, y;
        input_file >> x >> y;
        x--;
        y--;
        vct[x].push_back(y);
    }
 
    int ans = dfs(s - 1, vct, used);
 
    if (ans == 2) {
        output_file << "First player wins";
    } else {
        output_file << "Second player wins";
    }
 
 
    return 0;
}
