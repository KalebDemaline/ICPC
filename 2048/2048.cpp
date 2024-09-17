#include <iostream>
#include <vector>

using namespace std;

void moveRight(int arr[4], bool combined[4], int index) {
    for (int i = index + 1; i <= 3; ++i) {
        if (arr[i] == arr[index]) {
            if (combined[i]) {
                arr[i - 1] = arr[index];
                arr[index] = 0;
                return;
            }
            else {
                arr[i] = arr[i] << 1;
                arr[index] = 0;
                combined[i] = true;
                return;
            }
        }
        else if (arr[i] != 0 && arr[i] != arr[index]) {
            if (i - 1 != index) {
                arr[i - 1] = arr[index];
                arr[index] = 0;
                return;
            }
            else {
                return;
            }
        }
    } // means nothing right of the array

    arr[3] = arr[index];
    arr[index] = 0;
}

void moveLeft(int arr[4], bool combined[4], int index) {
    for (int i = index - 1; i >= 0; --i) {
        if (arr[i] == arr[index]) {
            if (combined[i]) {
                arr[i + 1] = arr[index];
                arr[index] = 0;
                return;
            }
            else {
                arr[i] = arr[i] << 1;
                arr[index] = 0;
                combined[i] = true;
                return;
            }
        }
        else if (arr[i] != 0 && arr[i] != arr[index]) {
            if (i + 1 != index) {
                arr[i + 1] = arr[index];
                arr[index] = 0;
                return;
            }
            else {
                return;
            }
        }
    }// if we get out of loop that means that there was nothing to the left

    arr[0] = arr[index];
    arr[index] = 0;

}

void moveArray(int arr[4], bool right) {
    bool combined[4] = { false, false, false, false };
    if (right) {
        for (int i = 2; i > -1; --i) {
            if (arr[i]) {
                moveRight(arr, combined, i);
            }
        }
    }
    else {
        for (int i = 1; i < 4; ++i) {
            if (arr[i]) {
                moveLeft(arr, combined, i);
            }
        }
    }
}

void printArray(int arr[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void convertColArray(int cols[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; ++j) {
            swap(cols[j][i], cols[i][j]);
        }
    }
}

int main(int argc, char* argv[]) {
    int board[4][4];
    int cols[4][4];

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> board[i][j];
            cols[j][i] = board[i][j];
        }
    }

    int move; // 0 = left, 1 = up, 2 = right, 3 = down

    cin >> move;

    if (move == 0) {
        for (int i = 0; i < 4; ++i) {
            moveArray(board[i], false);
        }
        printArray(board);
    }
    else if (move == 1) {
        for (int i = 0; i < 4; ++i) {
            moveArray(cols[i], false);
        }
        convertColArray(cols);
        printArray(cols);
    }
    else if (move == 2) {
        for (int i = 0; i < 4; ++i) {
            moveArray(board[i], true);
        }
        printArray(board);
    }
    else {
        for (int i = 0; i < 4; ++i) {
            moveArray(cols[i], true);
        }
        convertColArray(cols);
        printArray(cols);
    }
}