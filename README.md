TABELA DE CLASSES DE EQUIVALÊNCIA E ANÁLISE DE VALOR LIMITE
====================================================

1. QUANTIDADE DE INGRESSOS
-------------------------

Classes Válidas:
| Classe         | Descrição                    | Valores         | Resultado Esperado |
|---------------|------------------------------|----------------|-------------------|
| QV1           | Quantidade mínima            | 1              | Retorna 1        |
| QV2           | Quantidade intermediária     | 2, 3, 4        | Retorna o valor  |
| QV3           | Quantidade máxima            | 5              | Retorna 5        |

Classes Inválidas:
| Classe         | Descrição                    | Valores         | Resultado Esperado |
|---------------|------------------------------|----------------|-------------------|
| QI1           | Valores negativos            | -∞ até -1      | Retorna -1       |
| QI2           | Zero                         | 0              | Retorna -1       |
| QI3           | Acima do limite              | 6 até +∞       | Retorna -1       |

Valores Limite:
| Limite        | Valor         | Classe      | Válido/Inválido |
|---------------|---------------|-------------|------------------|
| Mínimo-1      | 0            | QI2         | Inválido         |
| Mínimo        | 1            | QV1         | Válido           |
| Máximo        | 5            | QV3         | Válido           |
| Máximo+1      | 6            | QI3         | Inválido         |

2. IDADE DOS PASSAGEIROS
------------------------

Classes Válidas:
| Classe         | Descrição                    | Valores         | Resultado Esperado |
|---------------|------------------------------|----------------|-------------------|
| IV1           | Crianças                     | 1 até 12       | R$ 10            |
| IV2           | Adultos                      | 13 até 59      | R$ 30            |
| IV3           | Idosos                       | 60 até +∞      | R$ 15            |

Classes Inválidas:
| Classe         | Descrição                    | Valores         | Resultado Esperado |
|---------------|------------------------------|----------------|-------------------|
| II1           | Valores negativos            | -∞ até -1      | Retorna -1       |
| II2           | Zero                         | 0              | Retorna -1       |

Valores Limite:
| Limite        | Valor         | Classe      | Válido/Inválido |
|---------------|---------------|-------------|------------------|
| Mínimo-1      | 0            | II2         | Inválido         |
| Mínimo        | 1            | IV1         | Válido           |
| Criança/Adulto| 12/13        | IV1/IV2     | Válido           |
| Adulto/Idoso  | 59/60        | IV2/IV3     | Válido           |

3. CASOS DE TESTE
----------------

a) Quantidade de Ingressos:
| ID  | Entrada | Resultado Esperado | Classe | Descrição                    |
|-----|---------|-------------------|---------|------------------------------|
| Q1  | -5      | -1                | QI1     | Quantidade negativa          |
| Q2  | 0       | -1                | QI2     | Quantidade zero              |
| Q3  | 1       | 1                 | QV1     | Quantidade mínima            |
| Q4  | 3       | 3                 | QV2     | Quantidade intermediária     |
| Q5  | 5       | 5                 | QV3     | Quantidade máxima            |
| Q6  | 6       | -1                | QI3     | Quantidade acima do limite   |
| Q7  | 10      | -1                | QI3     | Quantidade muito acima       |

b) Valor do Ingresso:
| ID  | Entrada | Resultado Esperado | Classe | Descrição                    |
|-----|---------|-------------------|---------|------------------------------|
| I1  | -1      | -1                | II1     | Idade negativa              |
| I2  | 0       | -1                | II2     | Idade zero                  |
| I3  | 1       | 10                | IV1     | Criança (limite inferior)   |
| I4  | 12      | 10                | IV1     | Criança (limite superior)   |
| I5  | 13      | 30                | IV2     | Adulto (limite inferior)    |
| I6  | 30      | 30                | IV2     | Adulto (meio da faixa)      |
| I7  | 59      | 30                | IV2     | Adulto (limite superior)    |
| I8  | 60      | 15                | IV3     | Idoso (limite inferior)     |
| I9  | 80      | 15                | IV3     | Idoso (idade avançada)      |

c) Casos de Teste Combinados:
| ID  | Qtd | Idades        | Total | Descrição                          |
|-----|-----|---------------|-------|-----------------------------------|
| C1  | 1   | 10           | 10    | Uma criança                       |
| C2  | 2   | 25, 65       | 45    | Um adulto e um idoso             |
| C3  | 3   | 10, 30, 70   | 55    | Criança, adulto e idoso          |
| C4  | 5   | 30,30,30,30,30| 150   | Cinco adultos (máximo)           |
| C5  | 5   | 10,10,10,10,10| 50    | Cinco crianças (mínimo)          |

OBSERVAÇÕES:
-----------
1. Particionamento de Equivalência:
   - Dividimos os dados em classes que devem ter o mesmo comportamento
   - Testamos valores representativos de cada classe
   - Reduzimos o número total de casos de teste necessários

2. Análise de Valor Limite:
   - Testamos os valores nas fronteiras das classes
   - Maior probabilidade de encontrar erros nas fronteiras
   - Complementa o particionamento de equivalência

3. Cobertura dos Testes:
   - Todas as classes válidas e inválidas são testadas
   - Todos os valores limite são verificados
   - Combinações importantes são testadas 
