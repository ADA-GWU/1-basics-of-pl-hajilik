#include <iostream>
#include <vector>
#include <stdexcept>
#include <chrono>
#include <sstream>
#include <numeric>
using namespace std;

vector<vector<int>> parseMatrixInput(const string& input, int& rows, int& cols) {
    vector<vector<int>> matrix;
    stringstream ss(input);
    string rowStr;
    while (getline(ss, rowStr, ';')) {
        vector<int> row;
        stringstream rowStream(rowStr);
        int value;
        while (rowStream >> value) {
            row.push_back(value);
        }
        if (matrix.empty()) {
            cols = row.size();
        }
        matrix.push_back(row);
        rows++;
    }
    return matrix;
}

vector<vector<int>> matrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    if (A[0].size() != B.size()) {
        throw invalid_argument("Number of columns in A must match number of rows in B.");
    }

    vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0; k < A[0].size(); k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int main() {
    string inputA, inputB;
    int rowsA = 0, colsA = 0, rowsB = 0, colsB = 0;

    cout << "Enter the matrix A rows separated by semicolons (e.g. '1 2; 3 4'): ";
    getline(cin, inputA);
    vector<vector<int>> A = parseMatrixInput(inputA, rowsA, colsA);

    cout << "Enter the matrix B rows separated by semicolons (e.g. '1 2; 3 4'):  ";
    getline(cin, inputB);
    vector<vector<int>> B = parseMatrixInput(inputB, rowsB, colsB);

    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> result = matrixMultiplication(A, B);
    auto end = chrono::high_resolution_clock::now();

    cout << "The result of matrix multiplication is:" << endl;
    for (const auto& row : result) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    chrono::duration<double, std::milli> duration = end - start;
    cout << "Time spent on Execution: " << duration.count() << " ms" << endl;

    return 0;
}
