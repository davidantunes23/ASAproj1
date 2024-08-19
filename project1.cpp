#include <vector>
#include <stdio.h>
using namespace std;

int _X, _Y;
vector<vector<int>> _matrix;

void readInput() {
    int numPieces, x, y, dump;
    dump = scanf("%d %d", &_X, &_Y);
    _matrix.resize(_X + 1, vector<int>(_Y + 1, 0));
    dump = scanf("%d", &numPieces);
    for (int i = 0; i < numPieces; i++) {
        int price;
        dump = scanf("%d %d %d", &x, &y, &price);
        if (x <= _X && y <= _Y)
            _matrix[x][y] = price;
        if (x <= _Y && y <= _X)
            _matrix[y][x] = price; 
    }
    (void)dump;
}

int computeMaxValue() {
    for (int x = 1; x <= _X; x++) {
        for (int y = 1; y <= _Y; y++) {
            int max = 0;
            for (int i = 0; i <= x / 2; i++) {
                int cutValue = _matrix[x-i][y] + _matrix[i][y];
                if (cutValue > max)
                    max = cutValue;
            }
            for (int i = 0; i <= y / 2; i++) {
                int cutValue = _matrix[x][y-i] + _matrix[x][i];
                if (cutValue > max)
                    max = cutValue;
            }
            _matrix[x][y] = max;
        }
    }
    return _matrix[_X][_Y];
}

int main() {
    readInput();
    int res = computeMaxValue();
    printf("%d\n", res);
    return 0;
}