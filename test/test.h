#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include "../src/algoritmo.h"
#include "miniunit-master/miniunit.h"

// Testes para validação de quantidade de ingressos
MU_TEST(test_quantidade_ingressos) {
    // Valores inválidos (menores que 1)
    if (validaQuantidade(-1) != -1) return "Falha: quantidade negativa deveria ser inválida";
    if (validaQuantidade(0) != -1) return "Falha: quantidade zero deveria ser inválida";
    
    // Valores válidos (entre 1 e 5)
    if (validaQuantidade(1) != 1) return "Falha: quantidade 1 deveria ser válida";
    if (validaQuantidade(3) != 3) return "Falha: quantidade 3 deveria ser válida";
    if (validaQuantidade(5) != 5) return "Falha: quantidade 5 deveria ser válida";
    
    // Valores inválidos (maiores que 5)
    if (validaQuantidade(6) != -1) return "Falha: quantidade 6 deveria ser inválida";
    if (validaQuantidade(10) != -1) return "Falha: quantidade 10 deveria ser inválida";
    
    return 0;
}

// Testes para cálculo do valor do ingresso
MU_TEST(test_valor_ingresso) {
    // Valores inválidos (idade negativa ou zero)
    if (calculaValorIngresso(-5) != -1) return "Falha: idade negativa deveria ser inválida";
    if (calculaValorIngresso(0) != -1) return "Falha: idade zero deveria ser inválida";
    
    // Valores limite para crianças (até 12 anos)
    if (calculaValorIngresso(1) != 10) return "Falha: criança de 1 ano deveria pagar R$10";
    if (calculaValorIngresso(12) != 10) return "Falha: criança de 12 anos deveria pagar R$10";
    
    // Valores limite para adultos (13 a 59 anos)
    if (calculaValorIngresso(13) != 30) return "Falha: pessoa de 13 anos deveria pagar R$30";
    if (calculaValorIngresso(30) != 30) return "Falha: pessoa de 30 anos deveria pagar R$30";
    if (calculaValorIngresso(59) != 30) return "Falha: pessoa de 59 anos deveria pagar R$30";
    
    // Valores limite para idosos (60 anos ou mais)
    if (calculaValorIngresso(60) != 15) return "Falha: pessoa de 60 anos deveria pagar R$15";
    if (calculaValorIngresso(80) != 15) return "Falha: pessoa de 80 anos deveria pagar R$15";
    if (calculaValorIngresso(100) != 15) return "Falha: pessoa de 100 anos deveria pagar R$15";
    
    return 0;
}

// Teste para verificar o valor total dos ingressos
MU_TEST(test_valor_total) {
    // Teste com valores válidos
    int idades[] = {10, 25, 65};  // Criança (10), Adulto (30), Idoso (15)
    int total = calculaValorIngresso(10) + calculaValorIngresso(25) + calculaValorIngresso(65);
    if (total != 55) return "Falha: valor total para criança + adulto + idoso deveria ser R$55";
    
    // Teste com valor máximo possível (5 adultos)
    total = calculaValorIngresso(30) * 5;  // 5 adultos (30 * 5)
    if (total != 150) return "Falha: valor máximo para 5 adultos deveria ser R$150";
    
    // Teste com valor mínimo possível (1 criança)
    total = calculaValorIngresso(10);  // 1 criança
    if (total != 10) return "Falha: valor mínimo para 1 criança deveria ser R$10";
    
    return 0;
}

char* test_suite() {
    mu_run_test(test_quantidade_ingressos);
    mu_run_test(test_valor_ingresso);
    mu_run_test(test_valor_total);
    return 0;
}

#endif // TEST_H 