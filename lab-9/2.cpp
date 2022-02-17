#include <fstream>
#include <vector>
 
using namespace std;
 
vector<vector<int>> Matrix;
vector<int> Color;
vector<int> Prev;
vector<int> Result;
bool Cycle_Checker = false;
int cycle_begin;
int cycle_next_vertex;
 
void DFS_VISIT(int visit_check)
{
    Color[visit_check] = -2;
    for (int i = 0; i < Matrix[visit_check].size(); i++)
    {
        if (Color[Matrix[visit_check][i]] == -1){
            DFS_VISIT(Matrix[visit_check][i]);
            Prev[Matrix[visit_check][i]] = visit_check;
        }
 
        if (Color[Matrix[visit_check][i]] == -2){
            Cycle_Checker = true;
            cycle_begin = visit_check;
            cycle_next_vertex = Matrix[visit_check][i];
        }
    }
    Color[visit_check] = -3;
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
    ifstream in("cycle.in");
    ofstream out("cycle.out");
    int n, m, vertex_in, vertex_out;
    in >> n >> m;
    Matrix.resize(n);
    Color.resize(n);
    Prev.resize(n);
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
        out << "YES" << endl;
        while (cycle_begin != cycle_next_vertex){
            Result.push_back(cycle_begin + 1);
            cycle_begin = Prev[cycle_begin];
        }
        Result.push_back(cycle_next_vertex + 1);
        for (int i = Result.size() - 1; i >= 0; i--)
            out << Result[i] << " ";
    }
    else out << "NO";
 
    return 0;
}
