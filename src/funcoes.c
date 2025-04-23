#include "algoritmo.h"

// Função para validar quantidade de ingressos
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