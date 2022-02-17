#include <fstream>
#include <iostream>
 
using namespace std;
 
void qsort(int arr[], int part1, int part2, int k) {
    int middle = arr[(part1 + part2) / 2];
    int i = part1;
    int j = part2;
    while (i <= j) 
    {
        while (arr[i] < middle)
            i++;
        while (arr[j] > middle)
            j--;
        if (i <= j) 
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (part1 < j && k <= j)
        qsort(arr, part1, j, k);
    if (i < part2 && k >= i)
        qsort(arr, i, part2, k);
}
 
int main() {
    ifstream fin("kth.in");
    ofstream fout("kth.out");
    int n;
    int k = 0;
    fin >> n >> k;
    int arr[n];
    int a, b, c;
    fin >> a >> b >> c >> arr[0] >> arr[1];
    for (int i = 2; i < n; i++)
        arr[i] = a * arr[i - 2] + b * arr[i - 1] + c;
    qsort(arr, 0, n - 1, k - 1);
 
    fout << arr[k - 1];
 
    fin.close();
    fout.close();
 
    return 0;
}
