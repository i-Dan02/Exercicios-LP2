/*
Questão 5
    */

#include <stdio.h>
#include <stdlib.h>

unsigned char geraGreyPixel(int tipo) {
    int intensidade;
    if (tipo < 0) {
        intensidade = rand() % 128;
    } else if (tipo > 0) {
        intensidade = 128 + rand() % 128;
    } else {
        intensidade = rand() % 256;
    }
    return (unsigned char) intensidade;
}

void preencheLinhaRandom(unsigned char img[480][640], int tipo, int linha, int coluna) {
    if (coluna >= 640) {
        return;
    } else {
        img[linha][coluna] = geraGreyPixel(tipo);
        preencheLinhaRandom(img, tipo, linha, coluna + 1);
    }
}

void geraImgGrey_R(unsigned char img[480][640], int tipo, int linha) {
    if (linha >= 480) {
        return;
    } else {
        preencheLinhaRandom(img, tipo, linha, 0);
        geraImgGrey_R(img, tipo, linha + 1);
    }
}

int main() {
    unsigned char img[480][640];
    int tipo = 0;  
    geraImgGrey_R(img, tipo, 0);

    for (int i = 0; i < 640; i++) {
        printf("%d ", img[0][i]);
    }

    return 0;
}
