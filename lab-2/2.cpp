#include <fstream>
#include <vector>
#include <string>
 
using namespace std;
 
struct racing {
    int place;
    string name;
    string country;
};
 
vector<racing> arr;
vector<racing> tmp;
 
void merge(int part1, int middle, int part2)
{
    int i = part1;
    int j = middle;
 
    for (int k = part1; k < part2; ++k)
    {
        if (j == part2 || (i < middle && arr[i].country <= arr[j].country))
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
 
int main() {
    ifstream in("race.in");
    ofstream out("race.out");
 
    int n = 0;
    in >> n;
 
    arr.resize(n);
    tmp.resize(n);
 
    string country;
    string racing;
    string current_country_statement;
 
    for (int i = 0; i < n; ++i)
    {
        in >> country >> racing;
        arr[i].name = racing;
        arr[i].place = i + 1;
        arr[i].country = country;
    }
 
    mergeSort(0, n);
     
    for (int i = 0; i < n; i++)
        {
         if (current_country_statement != arr[i].country)
             {
                current_country_statement = arr[i].country;
                out << "=== " << arr[i].country << " ===" << endl;
             }
            out << arr[i].name << endl;
        }
 
    return 0;
}
