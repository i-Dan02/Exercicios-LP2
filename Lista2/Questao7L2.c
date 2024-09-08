/*
Questão 7
    */

#include <stdio.h>

int minLinha_R(unsigned char img[480][640], int linha, int coluna, int minAtual) {
    if (coluna >= 640) {
        return minAtual;
    } else {
        if (img[linha][coluna] < minAtual) {
            minAtual = img[linha][coluna];
        }
        return minLinha_R(img, linha, coluna + 1, minAtual);
    }
}

int pixelMin_R(unsigned char img[480][640], int linha, int minAtual) {
    if (linha >= 480) {
        return minAtual;
    } else {
        int minLinha = minLinha_R(img, linha, 0, minAtual);
        return pixelMin_R(img, linha + 1, minLinha);
    }
}

int main() {
    unsigned char img[480][640];

    for (int i = 0; i < 480; i++) {
        for (int j = 0; j < 640; j++) {
            img[i][j] = (i + j) % 256;  
        }
    }

    int minPixel = pixelMin_R(img, 0, 255);  
    printf("O menor valor de pixel na imagem é: %d\n", minPixel);

    return 0;
}
