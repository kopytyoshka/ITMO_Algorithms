#include <iostream>
#include <fstream>
 
using namespace std;
 
int main() {
    ifstream input_file("input.txt");
    ofstream output_file("output.txt");
    int size;
 
    input_file >> size;
    int matrix[size][size];
 
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            input_file >> matrix[i][j];
        }
    }
    input_file.close();
 
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
           if (matrix[i][j] != matrix[j][i] || (i == j && matrix[i][j] == 1) ){
               output_file << "NO";
               output_file.close();
               return 0;
           }
        }
    }
 
    output_file << "YES";
    output_file.close();
    return 0;
}
