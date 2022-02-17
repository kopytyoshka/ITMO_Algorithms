#include <iostream>
#include <fstream>
 
using namespace std;
 
int main(){
    int n;
    ifstream fin("isheap.in");
    ofstream fout("isheap.out");
    fin >> n;
    int a[n];
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    int flag = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if ((2 * i <= n) && (a[i] > a[2 * i]))
        {
            flag = 1;
            break;
        }
        if ((2 * i + 1 <= n) && (a[i] > a[2 * i + 1])) {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        fout << "NO" << endl;
    else
        fout << "YES" << endl;
}
