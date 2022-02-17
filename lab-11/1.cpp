#include<fstream>
#include<vector>
#define INF 1000000000000000
 
using namespace std;
 
vector<vector<long long>> g;
vector<bool> used;
vector<long long> dist;
 
void Dijkstra(long long start, int n)
{
    dist[start] = 0;
    for (long long i = 0; i < n; i++)
    {
        long long v = -1;
        for (long long j = 0; j < n; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        if (dist[v] == INF)
            break;
        used[v] = true;
        for (long long j = 0; j < n; j++)
            if (dist[v] + g[v][j] < dist[j])
                dist[j] = dist[v] + g[v][j];
    }
}
 
int main()
{
    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");
    int n, begin, end, v;
 
    fin >> n >> begin >> end;
 
    g.resize(n, vector<long long> (n));
    used.resize(n, false);
    dist.resize(n, INF);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            fin >> v;
            v < 0 ? g[i][j] = INF : g[i][j] = v;
        }
    begin--;
    Dijkstra(begin, n);
    end--;
    dist[end] != INF ? fout << dist[end] : fout << "-1" << endl;
 
    fin.close();
    fout.close();
    return 0;
}
