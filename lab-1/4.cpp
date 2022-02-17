#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
    int n, i, j;
    ifstream fin ("smallsort.in");
    ofstream fout ("smallsort.out");
    fin >> n;
    int A[n];
    int temp;
    for(i = 0; i < n; i++){
        fin >> A[i];
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    for(i = 0; i < n; i++){
        fout << A[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
