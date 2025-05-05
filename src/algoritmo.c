#include <stdio.h>
#include "algoritmo.h"

#ifdef _WIN32
#include <windows.h>
#endif

// Função para validar quantidade de ingressosteste
int validaQuantidade(int qtd) {
    if (qtd <= 0 || qtd > 5) {
        return -1;
    }
    return qtd;
}

// Função para calcular valor do ingresso baseado na idade
int calculaValorIngresso(int idade) {
    if (idade <= 0) {
        return -1;
    }
    
    if (idade <= 12) {
        return 10; // Crianças
    } else if (idade >= 13 && idade <= 59) {
        return 30; // Adultos
    } else {
        return 15; // Idosos
    }
}

#ifndef TESTING
int main() {
    #ifdef _WIN32
    // Configura o terminal do Windows para UTF-8
    SetConsoleOutputCP(CP_UTF8);
    #endif
    
    int qtdBilhete, total = 0, valorIngresso;
   
    printf("Digite o número de bilhetes a serem comprados (máximo 5): ");
    scanf("%d", &qtdBilhete);

    // Verifica se a quantidade é válida
    if (validaQuantidade(qtdBilhete) == -1) {
        printf("Quantidade invalida. O numero de bilhetes deve ser entre 1 e 5.\n");
        return 1;
    }

    // Pede a idade de cada pessoa e calcula o valor
    for (int i = 1; i <= qtdBilhete; i++) {
        int idade;
        printf("Digite a idade da pessoa %d: ", i);
        scanf("%d", &idade);

        valorIngresso = calculaValorIngresso(idade);
        if (valorIngresso == -1) {
            printf("Idade invalida.\n");
            return 1;
        }

        total += valorIngresso;
    }

    // Exibe o resultado
    printf("Total a pagar: R$ %d\n", total);

    return 0;
}
#endif
