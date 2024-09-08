/*
Questão 1
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


void geraLinhaR(unsigned char lin[640], int tipo, int pos) {
    if (pos >= 640) {
        
        return;
    } else {
        
        lin[pos] = geraGreyPixel(tipo);
        
        geraLinhaR(lin, tipo, pos + 1);
    }
}

int main() {
    unsigned char linha[640];
    int tipo = 0;  

    geraLinhaR(linha, tipo, 0);

    for (int i = 0; i < 640; i++) {
        printf("%d ", linha[i]);
    }

    return 0;
}
