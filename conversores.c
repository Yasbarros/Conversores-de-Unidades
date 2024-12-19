#include <stdio.h>
#include <string.h>

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

void converter_tempo(int escolha, int *valor) {
    switch (escolha) {
        case 1:
            printf("%d hora(s) = %d minuto(s)\n", *valor, *valor * 60);
            break;
        case 2:
            printf("%d hora(s) = %d segundo(s)\n", *valor, *valor * 3600);
            break;
        case 3:
            printf("%d minuto(s) = %.2f hora(s)\n", *valor, (float)*valor / 60);
            break;
        case 4:
            printf("%d minuto(s) = %d segundo(s)\n", *valor, *valor * 60);
            break;
        case 5:
            printf("%d segundo(s) = %.2f hora(s)\n", *valor, (float)*valor / 3600);
            break;
        case 6:
            printf("%d segundo(s) = %.2f minuto(s)\n", *valor, (float)*valor / 60);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

int main() {
    printf("Escolha qual conversor de unidades deseja utilizar:\n");
    printf("1 - Conversor de temperaturas\n");
    printf("2 - Conversor de tempo: Horas, Min, Seg \n");
    int opcao;
    scanf("%d", &opcao);

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
    } else if (opcao == 2) {
        int escolha, valor;
        printf("Conversor de Tempo\n");
        printf("1. Horas para Minutos\n");
        printf("2. Horas para Segundos\n");
        printf("3. Minutos para Horas\n");
        printf("4. Minutos para Segundos\n");
        printf("5. Segundos para Horas\n");
        printf("6. Segundos para Minutos\n");
        printf("Escolha um numero de acordo com a conversao Desejada: ");
        scanf("%d", &escolha);
        printf("Digite o valor: ");
        scanf("%d", &valor);
        converter_tempo(escolha, &valor);
    } else {
        printf("Opção inválida!\n");
        return 1;
    }
    return 0;
}
