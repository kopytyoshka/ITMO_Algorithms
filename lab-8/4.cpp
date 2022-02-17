#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
 
using namespace std;
 
map<int,int> result;
 
void bfs(vector<vector<int>> &vct, int e, queue<int> &que, set<int> &visited, int &comp){
    if (visited.find(e) == visited.end()){
//        cout << e+1 << endl;
        result.insert(pair<int,int>(e,comp));
        visited.insert(e);
    }
    else {
        if (que.empty()) return;
        int go = que.front();
        que.pop();
        bfs(vct, go, que, visited, comp);
    }
    for (int i=0; i<vct[e].size(); i++){
        if (visited.find(vct[e][i]) == visited.end()) que.push(vct[e][i]);
    }
    if (que.empty()) return;
    int go = que.front();
    que.pop();
    bfs(vct, go, que, visited, comp);
}
 
int main() {
    queue<int> que;
    set<int> visited;
    ifstream input_file("components.in");
    ofstream output_file("components.out");
 
    int n,m;
    input_file >> n >> m;
 
    vector<vector<int>> vct(n,vector<int>());
    for (int i=0; i<m; i++){
        int b,e;
        input_file >> b >> e;
        b--;
        e--;
        if (b != e){
            if (find(vct[b].begin(), vct[b].end(), e) == vct[b].end()) vct[b].push_back(e);
            if (find(vct[e].begin(), vct[e].end(), b) == vct[e].end()) vct[e].push_back(b);
        }
    }
 
    input_file.close();
 
//    for (int i=0; i<n; i++){
//        cout << i+1 << ": ";
//        for (int j=0; j<vct[i].size(); j++){
//            cout << vct[i][j]+1 << " ";
//        }
//        cout << endl;
//    }
 
    queue<int> vertices;
    for (int i=0; i<n; i++){
        vertices.push(i);
    }
 
    int comp = 0;
    while (!vertices.empty()){
        int node = vertices.front(); vertices.pop();
        if (visited.find(node) == visited.end()){
            bfs(vct, node, que, visited, comp);
//            cout << "------\n";
            comp++;
        }
    }
 
    output_file << comp << endl;
    for(auto t : result){
        output_file << t.second+1 << " ";
    }
    output_file.close();
    return 0;
}
