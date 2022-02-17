#include <fstream>
#include <vector>
 
using namespace std;
 
vector<vector<int>> Matrix;
vector<int> Color;
vector <int> Result;
bool Cycle_Checker = false;
 
void DFS_VISIT(int visit_check)
{
    Color[visit_check] = -2;
    for (int i = 0; i < Matrix[visit_check].size(); i++)
    {
        if (Color[Matrix[visit_check][i]] == -1)
            DFS_VISIT(Matrix[visit_check][i]);
        if (Color[Matrix[visit_check][i]] == -2)
            Cycle_Checker = true;
    }
    Color[visit_check] = -3;
    Result.push_back(visit_check);
}
 
void DFS()
{
    for (int i = 0; i < Matrix.size(); i++)
        if (Color[i] == -1)
        {
            DFS_VISIT(i);
        }
}
 
int main()
{
    ifstream in("topsort.in");
    ofstream out("topsort.out");
    int n, m, vertex_in, vertex_out;
    in >> n >> m;
    Matrix.resize(n);
    Color.resize(n);
    for (int i = 0; i < Color.size(); i++)
        Color[i] = -1;
    for (int i = 0; i < m; i++)
    {
        in >> vertex_in >> vertex_out;
        vertex_in--;
        vertex_out--;
        Matrix[vertex_in].push_back(vertex_out);
    }
    DFS();
 
    if(Cycle_Checker){
        out << -1;
        return 0;
    }
 
    for (int i = Result.size() - 1; i >= 0 ; i--)
        out << Result[i] + 1 << " ";
 
    return 0;
}
