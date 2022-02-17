#include <fstream>
 
using namespace std;
 
int main() {
    ifstream fin("antiqs.in");
    ofstream fout("antiqs.out");
    int n;
    fin >> n; 
    int a[n];
    for (int i = 1; i <= n; i++) 
        a[i-1] = i;
    for (int i = 0; i < n; i++)
        swap(a[i], a[i / 2]);
    
    for (int i = 0; i < n; i++)
        fout << a[i] << " ";
    fin.close();
    fout.close();
    return 0;
}
