#include <iostream>
#include <fstream>
 
using namespace std;
 
string arr[1000], result[1000];
long int n, m, k;
 
void radixSorting(int position)
{
    char symb = 'a';
    int j = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int g = 0; g < n; g++) 
        {
            if (arr[g][position] == symb)
            {
                result[j] = arr[g];
                j++;
            }
        }
        symb++;
    }
    for (int i = 0; i < n; i++)
        arr[i] = result[i];
}
 
int main()
{
    ifstream fin("radixsort.in");
    ofstream fout("radixsort.out");
    fin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        fin >> arr[i];
    for (int i = m - 1; i >= m - k; i--)
        radixSorting(i);
    for (int i = 0; i < n; i++)
        fout << arr[i] << endl;
 
    fin.close();
    fout.close();
 
    return 0;
}
