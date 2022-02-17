#include <fstream>
#include <vector>
#include <set>
#define INF 1000000000
 
using namespace std;
 
int main()
{
    ifstream fin("pathbgep.in");
    ofstream fout("pathbgep.out");
    int n, m, x, y, w, v, next;
    fin >> n >> m;
 
    vector<vector<pair<int, int>>> Matrix;
    vector <long long> Distance;
    set <pair<int, int>> Queue;
 
    Matrix.resize(n);
    Distance.resize(n);
 
    for (int i = 0; i < m; i++)
    {
        fin >> x >> y >> w;
        Matrix[x - 1].push_back(make_pair(w, y - 1));
        Matrix[y - 1].push_back(make_pair(w, x - 1));
    }
 
    for (int i = 0; i < n; i++)
        Distance[i] = INF;
 
    Distance[0] = 0;
    Queue.insert(make_pair(Distance[0], 0));
 
    while(!Queue.empty())
    {
        v = Queue.begin() -> second;
        Queue.erase(Queue.begin());
 
        for (int i = 0; i < Matrix[v].size(); i++)
        {
            next = Matrix[v][i].second;
            w = Matrix[v][i].first;
            if (Distance[v] + w < Distance[next])
            {
                Queue.erase(make_pair(Distance[next], next));
                Distance[next] = Distance[v] + w;
                Queue.insert(make_pair(Distance[next], next));
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (Distance[i] != INF)
            fout << Distance[i] << " ";
        else
            fout << -1 << " ";
    fout.close();
    fin.close();
    return 0;
}
