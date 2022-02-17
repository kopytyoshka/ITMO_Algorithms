#include <fstream>
#include <iostream>
#include <vector>
  
using namespace std;
  
vector<int> srt;
  
void deep_level(int index, vector<vector<int>> &vct, int comp, vector<int> &used) {
    used[index] = comp;
    for (int i = 0; i < vct[index].size(); i++) {
        if (used[vct[index][i]] == -1) {
            deep_level(vct[index][i], vct, comp, used);
        }
    }
    if (comp == 0) {
        srt.push_back(index);
    }
}
  
void dfs(vector<vector<int>> &vct, vector<int> &used, int n) {
    for (int i = 0; i < n; i++) {
        if (used[i] == -1) {
            deep_level(i, vct, 0, used);
        }
    }
}
  
void rdfs(vector<vector<int> > &vct, int &comp, vector<int> &used, int n) {
    for (int i = srt.size() - 1; i >= 0; i--) {
        if (used[srt[i]] == -1) {
            deep_level(srt[i], vct, comp, used);
            comp++;
        }
    }
}
  
int main() {
    ifstream input_file("cond.in");
    ofstream output_file("cond.out");
    int n, m;
    input_file >> n >> m;
    vector<vector<int>> vct(n, vector<int>());
    vector<vector<int>> rvct(n, vector<int>());
    vector<int> used(n, -1);
  
    for (int i = 0; i < m; i++) {
        int x, y;
        input_file >> x >> y;
        x--;
        y--;
        vct[x].push_back(y);
        rvct[y].push_back(x);
    }
    dfs(vct, used, n);
  
    int comp = 1;
    for (int i = 0; i < n; i++) used[i] = -1;
    rdfs(rvct, comp, used, n);
  
    output_file << comp - 1 << endl;
    for (auto t : used) {
        output_file << t << " ";
    }
  
    return 0;
}
