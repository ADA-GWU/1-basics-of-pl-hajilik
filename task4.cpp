#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size;
    cout << "Enter size for matrix: ";
    cin >> size;

    vector<vector<int>> matrix(size, vector<int>(size));
    int num = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = num++;
        }
    }

    cout << "Original Matrix:" << endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    vector<vector<int>> slicedMatrix;
    for (int i = 1; i < size - 1; i++) {
        vector<int> row;
        for (int j = 1; j < size - 1; j++) {
            row.push_back(matrix[i][j]);
        }
        slicedMatrix.push_back(row);
    }

    cout << "\nSliced Matrix:" << endl;
    for (const auto& row : slicedMatrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
