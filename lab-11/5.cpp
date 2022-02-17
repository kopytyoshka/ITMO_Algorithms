#include <fstream>
#include <vector>
#include <iostream>
#define INF 10000000
 
using namespace std;
 
int main()
{
    ifstream fin("negcycle.in");
    ofstream fout("negcycle.out");
    int n, find_a_cycle;
    fin >> n;
    vector<vector<int>> Matrix;
    vector<int> Parents;
    vector<int> Distance;
    Parents.resize(n);
    Distance.resize(n);
    Matrix.resize(n);
 
    for (int i = 0; i < n; i++)
    {
        Parents[i] = -1;
        Matrix[i].resize(n);
        for (int j = 0; j < n; j++)
            fin >> Matrix[i][j];
    }
    for (int k = 0; k < n; k++)
    {
        find_a_cycle = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (Matrix[i][j] != INF)
                    if (Distance[j] > Distance[i] + Matrix[i][j])
                    {
                        Distance[j] = max(-INF, Distance[i] + Matrix[i][j]);
                        Parents[j] = i;
                        find_a_cycle = j;
                    }
    }
 
    if (find_a_cycle > -1)
    {
        int x = find_a_cycle;
        for (int i = 0; i < n; ++i)
            x = Parents[x];
 
        vector<int> Path;
        for (int i = x; !(i == x && Path.size() > 1); i = Parents[i])
        {
            Path.push_back(i + 1);
        }
 
        fout << "YES" << endl;
        fout << Path.size() + 1 << endl;
        fout << Path[0] << " ";
        for (int i = Path.size() - 1; i >= 0; i--)
            fout << Path[i] << " ";
    }
    else
        fout << "NO";
 
    fin.close();
    fout.close();
    return 0;
}
