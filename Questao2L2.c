/*
Questão 2
    */

#include <stdio.h>


void preencheLinha(unsigned char img[480][640], unsigned char pixel, int linha, int coluna) {
    if (coluna >= 640) {
    
    return;
        
    } else {
       
        img[linha][coluna] = pixel;
       
        preencheLinha(img, pixel, linha, coluna + 1);
    }
}


void geraImgGreyFull_R(unsigned char img[480][640], unsigned char pixel, int linha) {
    if (linha >= 480) {
        
        return;
    } else {
        
        preencheLinha(img, pixel, linha, 0);
        
        geraImgGreyFull_R(img, pixel, linha + 1);
    }
}

int main() {
    unsigned char img[480][640];
    unsigned char pixel = 128;  

    
    geraImgGreyFull_R(img, pixel, 0);

    for (int i = 0; i < 640; i++) {
        printf("%d ", img[0][i]);
    }

    return 0;
}
