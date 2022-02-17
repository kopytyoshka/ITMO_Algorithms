#include <fstream>
#include <vector>
#include <set>
#define INF 2e18
 
using namespace std;
 
int main()
{
     
    ifstream fin("pathsg.in");
    ofstream fout("pathsg.out");
 
    vector<vector<long long int>> Matrix;
    int n, m, x, y, w;
    fin >> n >> m;
    Matrix.resize(n);
 
    for (int i = 0; i < n; i++)
    {
        Matrix[i].resize(n);
        fill(Matrix[i].begin(), Matrix[i].end(), INF);
        Matrix[i][i] = 0;
    }
 
    for (int i = 0; i < m; i++)
    {
        fin >> x >> y >> w;
        x--;
        y--;
        Matrix[x][y] = w;
    }
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (j != k)
                    Matrix[j][k] = min(Matrix[j][k], Matrix[j][i] + Matrix[i][k]);
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fout << Matrix[i][j] << " ";
        fout << endl;
    }
 
    fin.close();
    fout.close();
    return 0;
}
