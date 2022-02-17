#include <fstream>
#include <stdlib.h>
 
using namespace std;
 
int main()
{
    int i, j;
    int n;
    int answer[3];
    double temp = 0;
    ifstream in("sortland.in");
    ofstream out("sortland.out");
 
    in >> n;
    double Sorted[n], Original[n];
    int middle = n / 2;
    for(i = 0; i < n; i++) in >> Sorted[i];
    for(i = 0; i < n; i++) Original[i] = Sorted[i];
        for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (Sorted[j] > Sorted[j + 1]) {
                temp = Sorted[j];
                Sorted[j] = Sorted[j + 1];
                Sorted[j + 1] = temp;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        if(Sorted[middle] == Original[i]) answer[1] = i + 1;
        if(Sorted[0] == Original[i]) answer[0] = i + 1;
        if(Sorted[n-1] == Original[i]) answer[2] = i + 1;
 
    }
    out << answer[0] << " " << answer[1] << " " << answer[2];
    return 0;
 
}
