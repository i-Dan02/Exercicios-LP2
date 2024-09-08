/*
Questão 9
    */

#include <stdio.h>

int somaColuna_R(unsigned char img[480][640], int linha, int coluna) {
    if (linha >= 480) {
        return 0;
    } else {
        return img[linha][coluna] + somaColuna_R(img, linha + 1, coluna);
    }
}

void somaPorColunas_R(unsigned char img[480][640], int soma[640], int coluna) {
    if (coluna >= 640) {
        return;
    } else {
        soma[coluna] = somaColuna_R(img, 0, coluna);
        somaPorColunas_R(img, soma, coluna + 1);
    }
}

int main() {
    unsigned char img[480][640];
    int soma[640];

    for (int i = 0; i < 480; i++) {
        for (int j = 0; j < 640; j++) {
            img[i][j] = (i + j) % 256;  
        }
    }

    somaPorColunas_R(img, soma, 0);

    for (int i = 0; i < 640; i++) {
        printf("Soma da coluna %d: %d\n", i, soma[i]);
    }

    return 0;
}
