/*
Questão 9
    */

#include <stdio.h>

int somaLinha_R(unsigned char img[480][640], int linha, int coluna) {
    if (coluna >= 640) {
        return 0;
    } else {
        return img[linha][coluna] + somaLinha_R(img, linha, coluna + 1);
    }
}

int somaPorTotal_R(unsigned char img[480][640], int linha) {
    if (linha >= 480) {
        return 0;
    } else {
        return somaLinha_R(img, linha, 0) + somaPorTotal_R(img, linha + 1);
    }
}

int main() {
    unsigned char img[480][640];

    for (int i = 0; i < 480; i++) {
        for (int j = 0; j < 640; j++) {
            img[i][j] = (i + j) % 256;  
    }
    }

    int somaTotal = somaPorTotal_R(img, 0);

    printf("A soma total dos pixels da imagem é: %d\n", somaTotal);

    return 0;
}
