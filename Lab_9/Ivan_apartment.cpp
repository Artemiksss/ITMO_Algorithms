#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& matrix, int i, int j) {
    matrix[i][j] = 'x';
    int n = matrix.size(), m = matrix[0].size();
    if (i > 0 && matrix[i-1][j] == '.') dfs(matrix, i-1, j);
    if (i < n-1 && matrix[i+1][j] == '.') dfs(matrix, i+1, j);
    if (j > 0 && matrix[i][j-1] == '.') dfs(matrix, i, j-1);
    if (j < m-1 && matrix[i][j+1] == '.') dfs(matrix, i, j+1);
}

int count_rooms(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.') {
                dfs(matrix, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int count = count_rooms(matrix);
    cout << count << endl;
    return 0;
}
