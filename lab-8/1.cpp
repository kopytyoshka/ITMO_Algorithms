#include <iostream>
#include <vector>
#include <fstream>
 
using namespace std;
 
int main() {
    ifstream input_file("input.txt");
    ofstream output_file("output.txt");
    int n, k;
    input_file >> n >> k;
    vector<vector<int>> vct(n, vector<int>(n,0));
    for (int i = 0; i < k; i++){
        int a,b;
        input_file >> a >> b;
        vct[a - 1][b - 1] = 1;
    }
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            output_file << vct[i][j] << " ";
        }
        output_file << endl;
    }
    input_file.close();
    output_file.close();
    return 0;
}
