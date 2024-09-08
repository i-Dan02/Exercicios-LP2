/*
Questão 3
    */

#include <stdio.h>

void preencheLinhaB(unsigned char img[480][640], int linha, int coluna) {
    if (coluna >= 640) {

        return;
    } else {
        img[linha][coluna] = 0;
        preencheLinhaB(img, linha, coluna + 1);
    }
}

void geraImgGreyB_R(unsigned char img[480][640], int linha) {
    if (linha >= 480) {

        return;
        
    } else {
        
        preencheLinhaB(img, linha, 0);
        geraImgGreyB_R(img, linha + 1);
    }
}

int main() {
    unsigned char img[480][640];

    geraImgGreyB_R(img, 0);

    for (int i = 0; i < 640; i++) {
        printf("%d ", img[0][i]);
    }

    return 0;
}
