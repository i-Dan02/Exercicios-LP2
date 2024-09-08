/*
Questão 8
    */

#include <stdio.h>

int somaLinha_R(unsigned char img[480][640], int linha, int coluna) {
    if (coluna >= 640) {
        return 0;
    } else {
        return img[linha][coluna] + somaLinha_R(img, linha, coluna + 1);
    }
}

void somaPorLinhas_R(unsigned char img[480][640], int soma[480], int linha) {
    if (linha >= 480) {
        return;
    } else {
        soma[linha] = somaLinha_R(img, linha, 0);
        somaPorLinhas_R(img, soma, linha + 1);
    }
}

int main() {
    unsigned char img[480][640];
    int soma[480];

    for (int i = 0; i < 480; i++) {
        for (int j = 0; j < 640; j++) {
            img[i][j] = (i + j) % 256; 
        }
    }

    somaPorLinhas_R(img, soma, 0);

    for (int i = 0; i < 480; i++) {
        printf("Soma da linha %d: %d\n", i, soma[i]);
    }

    return 0;
}
