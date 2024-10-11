#include <iostream>
#include <vector>
#include <stdexcept>
#include <chrono>
using namespace std;

int main() {
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter number of rows and columns for A: ";
    cin >> rowsA >> colsA;

    vector<vector<int>> A(rowsA, vector<int>(colsA));
    cout << "Enter elements for A: " << endl;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter number of rows and columns for B: ";
    cin >> rowsB >> colsB;

    vector<vector<int>> B(rowsB, vector<int>(colsB));
    cout << "Enter elements for B: " << endl;
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> B[i][j];
        }
    }

    auto start = chrono::high_resolution_clock::now();
    
    if (A[0].size() != B.size()) {
        throw invalid_argument("Hey, pay attention to number of columns in A and number of rows in B.");
    }

    vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0; k < A[0].size(); k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    auto end = chrono::high_resolution_clock::now();

    cout << "The result is:" << endl;
    for (const auto& row : result) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    chrono::duration<double, std::milli> duration = end - start;
    cout << "Multiplication duration: " << duration.count() << " ms" << endl;

    vector<vector<int>> testA = {{1, 2}, {1, 2}};
    vector<vector<int>> testB = {{1, 2}, {1, 2}};
    vector<vector<int>> expected = {{3, 6}, {3, 6}};

    vector<vector<int>> testResult(2, vector<int>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                testResult[i][j] += testA[i][k] * testB[k][j];
            }
        }
    }

    // Passed or Failed
    if (testResult == expected) {
        cout << "Passed!" << endl;
    } else {
        cout << "Failed!" << endl;
    }

    return 0;
}
