#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
vector<int> arr;
vector<int> tmp;
 
void merge(int part1, int middle, int part2)
{
    int i = part1;
    int j = middle;
 
    for (int k = part1; k < part2; ++k)
    {
        if (j == part2 || (i < middle && arr[i] <= arr[j]))
        {
            tmp[k] = arr[i];
            i++;
        }
        else
        {
            tmp[k] = arr[j];
            j++;
        }
    }
    for (int i = part1; i < part2; ++i)
    {
        arr[i] = tmp[i];
    }
}
 
void mergeSort(int part1, int part2)
{
    if (part2 <= part1 + 1)
        return;
    int middle = (part1 + part2) / 2;
    mergeSort(part1, middle);
    mergeSort(middle, part2);
    merge(part1, middle, part2);
}
 
int main()
{
    int n;
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    fin >> n;
    arr.resize(n);
    tmp.resize(n);
    for(int i = 0; i < n; i++){
        fin >> arr[i];
    }
    mergeSort(0, n);
    for (int i = 0; i < n; i++)
    {
        fout << arr[i] << " ";
    }
    fin.close();
    fout.close();
 
    return 0;
}
