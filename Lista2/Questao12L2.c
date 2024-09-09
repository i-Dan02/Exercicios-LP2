#include <stdio.h>

int quantosPixelsAbaixoDeInt_R(unsigned char img[480][640], unsigned char intensidade, int linha, int coluna) {
    if (linha >= 480) {
        return 0;
    }

    if (coluna >= 640) {
        return quantosPixelsAbaixoDeInt_R(img, intensidade, linha + 1, 0);
    }

    int count = (img[linha][coluna] < intensidade) ? 1 : 0;

    return count + quantosPixelsAbaixoDeInt_R(img, intensidade, linha, coluna + 1);
}

int quantosPixelsAbaixoDeInt_R_(unsigned char img[480][640], unsigned char intensidade) {
    return quantosPixelsAbaixoDeInt_R(img, intensidade, 0, 0);
}

int main() {
    
    unsigned char img[480][640];
    unsigned char intensidade = 200;
    int res = quantosPixelsAbaixoDeInt_R_(img, intensidade);
    printf("Pixels com intensidade menor que %d: %d\n", intensidade, res);

    return 0;
}
