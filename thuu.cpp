#include <bits/stdc++.h>

using namespace std;
//CODE OF KIEN PT

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void Matrix(int s, vector<vector<int>>& matrix, vector<int>& rowSum, vector<int>& colSum, int row, int col) {
    if (row == 5 && col == 0) {
        for (int i = 0; i < 5; i++) {
            int sum = 0;
            for (int j = 0; j < 5; j++) {
                sum += matrix[i][j];
            }
            if (sum != rowSum[i]) {
                return;
            }
        }

        for (int j = 0; j < 5; j++) {
            int sum = 0;
            for (int i = 0; i < 5; i++) {
                sum += matrix[i][j];
            }
            if (sum != colSum[j]) {
                return;
            }
        }

        int diagonalSum1 = 0;
        int diagonalSum2 = 0;
        for (int i = 0; i < 5; i++) {
            diagonalSum1 += matrix[i][i];
            diagonalSum2 += matrix[i][4 - i];
        }
        if (diagonalSum1 != s || diagonalSum2 != s) {
            return;
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return;
    }

    for (int i = 0; i <= 9; i++) {
        matrix[row][col] = i;
        if (col == 4) {
            Matrix(s, matrix, rowSum, colSum, row + 1, 0);
        } else {
            Matrix(s, matrix, rowSum, colSum, row, col + 1);
        }
    }
}

int main() {
    int s;
    cin >> s;

    vector<vector<int>> matrix(5, vector<int>(5));
    vector<int> rowSum(5, s);
    vector<int> colSum(5, s);
    Matrix(s, matrix, rowSum, colSum, 0, 0);

    return 0;
}
