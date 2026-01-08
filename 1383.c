#include <stdio.h>
#include <stdlib.h>

int verifLinha(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++) {
            int existe[10] = {0};
            if(existe[sudoku[i][j]]) {
                return 0;
            }
            existe[sudoku[i][j]] = 1;
        }
    }
    return 1;
}

int verifColun(int sudoku[9][9]) {
    for (int j = 0; j < 9; j++) {
        int existe[10] = {0};
        for (int i = 0; i < 9; i++) {
            if(existe[sudoku[i][j]]) {
                return 0;
            }
            existe[sudoku[i][j]] = 1;
        }
    }
    return 1;
}

int verifbloco(int sudoku[9][9]) {
    for (int blocoI = 0; blocoI < 9; blocoI += 3) {
        for (int blocoJ = 0; blocoJ < 9; blocoJ += 3) {
            int existe[10] = {0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (existe[sudoku[blocoI + i][blocoJ + j]]) {
                        return 0;
                    }
                    existe[sudoku[blocoI + i][blocoJ + j]] = 1;
                }
            }
        }
    }
    return 1;
}

int main() {
    int numMatriz, sudoku[9][9];
    scanf("%d", &numMatriz);
    int verifica[numMatriz];

    for (int k = 0; k < numMatriz; k++) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++) {
                    scanf("%d", &sudoku[i][j]);
            }
        }
        if (verifLinha(sudoku) && verifColun(sudoku) && verifbloco(sudoku)){
            verifica[k] = 1;
        } else {
            verifica[k] = 0;
        }
    }
    for (int k = 0; k < numMatriz; k++)
    {
        printf("Instancia %d\n", k + 1);
        printf("%s\n\n", verifica[k] == 1 ? "SIM" : "NAO");
    }
}
