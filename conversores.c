#include <stdio.h>
#include <string.h>

//Espaço para criação de funções de conversão de unidades

double converter_temperatura(double valor, const char *origem, const char *destino) {
    double resultado;

    if (strcmp(origem, "C") == 0) { 
        if (strcmp(destino, "F") == 0) {
            resultado = valor * 9.0 / 5.0 + 32; 
        } else if (strcmp(destino, "K") == 0) {
            resultado = valor + 273.15; 
        } else {
            resultado = valor; 
        }
    } else if (strcmp(origem, "F") == 0) { 
        if (strcmp(destino, "C") == 0) {
            resultado = (valor - 32) * 5.0 / 9.0; 
        } else if (strcmp(destino, "K") == 0) {
            resultado = (valor - 32) * 5.0 / 9.0 + 273.15; 
        } else {
            resultado = valor; 
        }
    } else if (strcmp(origem, "K") == 0) { 
        if (strcmp(destino, "C") == 0) {
            resultado = valor - 273.15; 
        } else if (strcmp(destino, "F") == 0) {
            resultado = (valor - 273.15) * 9.0 / 5.0 + 32; 
        } else {
            resultado = valor;
        }
    } else {
        printf("Unidade de origem inválida!\n");
        resultado = 0.0; 
    }

    return resultado;
}

int main() {
    
    printf("Escolha qual conversor de unidades deseja utilizar:\n");
    printf("1 - Conversor de temperaturas\n");  // Adicionar numeração no menu para escolha do conversor
    printf("Digite a opção desejada: ");
    int opcao;
    scanf("%d", &opcao);

    // Adicionar na condição abaixo o numero para acesso ao seu conversor 
    if (opcao == 1) {
        double valor;
        char origem[2], destino[2];
        printf("Digite o valor da temperatura: ");
        scanf("%lf", &valor);

        printf("Digite a unidade de origem (C, F, K): ");
        scanf("%s", origem);

        printf("Digite a unidade de destino (C, F, K): ");
        scanf("%s", destino);

        double resultado = converter_temperatura(valor, origem, destino);
        printf("O valor convertido de %s para %s é: %.2lf\n", origem, destino, resultado);

    }else{
        printf("Opção inválida!\n");
        return 1;
    }
    
    return 0;
}
