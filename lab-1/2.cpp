#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
    long long int numb1, numb2, sum;
    ifstream fin ("aplusbb.in");
    ofstream fout ("aplusbb.out");
    fin >> numb1 >> numb2;
    numb2 = numb2 * numb2;
    sum = numb1 + numb2;
    fout << sum << endl;
    fin.close();
    fout.close();
    return 0;
}
