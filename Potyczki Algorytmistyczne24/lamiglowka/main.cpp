#include <bits/stdc++.h>


using namespace std;
char T[2000][2000];
map<char, int> colorInRows[2000], colorInCols[2000];
vector<string> queue;

set<int> rows, cols;

bool checkRow(int row) {
    if (colorInRows[row].size() == 1) { // Jeśli w mapie jest tylko jeden kolor
        auto& pair = *(colorInRows[row].begin());

        if (pair.second == cols.size()) { // I jego ilość odpowiada rozmiarowi kolumn
            return true;
        }
    }
    return false;
}

bool checkCol(int col) {
    if (colorInCols[col].size() == 1) { // Jeśli w mapie jest tylko jeden kolor
        auto& pair = *(colorInCols[col].begin());

        if (pair.second == rows.size()) { // I jego ilość odpowiada rozmiarowi wierszy
            return true;
        }
    }
    return false;
}

void removeRow(int row) {
    for (int col : cols) { // Usuwamy wpływ tego wiersza na wszystkie kolumny, czyli -1 dla danego koloru w kazdej kolumnie
        char color = T[row][col];
        colorInCols[col][color]--;

        if (colorInCols[col][color] == 0) {
            colorInCols[col].erase(color);
        }
    }
}

void removeCol(int col) {
    for (int row : rows) { // to co wyzej
        char color = T[row][col];
        colorInRows[row][color]--;

        if (colorInRows[row][color] == 0) {
            colorInRows[row].erase(color);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        rows.insert(i);

        for (int j = 0; j < m; j++) {
            cin >> T[i][j];

            colorInRows[i][T[i][j]]++; //zliczanie kolorow w wierszach i kolumnach
            colorInCols[j][T[i][j]]++;
        }
    }
    for (int j = 0; j < m; j++) {
        cols.insert(j);		
    }

    vector<int> trash;	//wyrzucenie kolumn lub wierszy
    bool change = true;
    while (change) {
        change = false;
        trash.clear();

        for (int row : rows) {
            if (checkRow(row)) {

                char color = T[row][*cols.begin()];
                queue.push_back("R " + to_string(row + 1) + " " + color);

                trash.push_back(row);
                change = true;
                removeRow(row);
            }
        }

        for (int row : trash) {
            rows.erase(row);
        }

        trash.clear();

        for (int col : cols) {
            if (checkCol(col)) {

                char color = T[*rows.begin()][col];
                queue.push_back("K " + to_string(col + 1) + " " + color);

                trash.push_back(col);
                change = true;
                removeCol(col);
            }
        }

        for (int col : trash) {
            cols.erase(col);
        }
    }

    cout << queue.size() << "\n";
    for (auto & it : std::ranges::reverse_view(queue)) {
        cout << it << "\n";
    }

    return 0;
}
