/*
Questão 6
    */

#include <stdio.h>

int maxLinha_R(unsigned char img[480][640], int linha, int coluna, int maxAtual) {
    if (coluna >= 640) {
        return maxAtual;
    } else {
        if (img[linha][coluna] > maxAtual) {
            maxAtual = img[linha][coluna];
        }
        return maxLinha_R(img, linha, coluna + 1, maxAtual);
    }
}

int pixelMax_R(unsigned char img[480][640], int linha, int maxAtual) {
    if (linha >= 480) {
        return maxAtual;
    } else {
        int maxLinha = maxLinha_R(img, linha, 0, maxAtual);
        return pixelMax_R(img, linha + 1, maxLinha);
    }
}

int main() {
    unsigned char img[480][640];

    for (int i = 0; i < 480; i++) {
        for (int j = 0; j < 640; j++) {
            img[i][j] = (i + j) % 256;  
        }
    }

    int maxPixel = pixelMax_R(img, 0, 0);
    printf("O maior valor de pixel na imagem é: %d\n", maxPixel);

    return 0;
}

