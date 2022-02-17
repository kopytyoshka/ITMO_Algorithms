#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
    int numb1, numb2, sum;
    ifstream fin ("aplusb.in");
    ofstream fout("aplusb.out");
    fin >> numb1 >> numb2;
    sum = numb1 + numb2;
    fout << sum << endl;
    fin.close();
    fout.close();
    return 0;
}
