#include <stdio.h>

int board[20], n;

// Check if queen can be placed at row r and column c
int isSafe(int r, int c) {
    for (int i = 1; i < r; i++) {
        // Check column conflict OR diagonal conflict
        if (board[i] == c || (i - r) == (board[i] - c) || 
            (i - r) == (c - board[i]))
            return 0;
    }
    return 1;
}

// Backtracking function
void solve(int r) {
    if (r > n) {
        // Print solution
        printf("\nSolution:\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i] == j)
                    printf(" Q ");
                else
                    printf(" . ");
            }
            printf("\n");
        }
        return;
    }

    for (int c = 1; c <= n; c++) {
        if (isSafe(r, c)) {
            board[r] = c;      // place queen
            solve(r + 1);      // place next queen
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    solve(1);

    return 0;
}
