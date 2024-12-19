#include <stdio.h>
#include <string.h>


// --- Unidades de Velocidade ---
#define KMH "km/h"
#define MS "m/s"
#define MPH "mph"


// --- Constantes de Conversão - Velociadade ---
#define KMH_TO_MS 3.6
#define KMH_TO_MPH 0.621371
#define MS_TO_MPH 2.23694


// Headers das funções
double converter_temperatura(double, const char *, const char *);
double* converter_velocidade(double, char*);
void converter_tempo(int, int *);


int main() {
    
    printf("Escolha qual conversor de unidades deseja utilizar:\n");
    printf("1 - Conversor de temperaturas\n");  // Adicionar numeração no menu para escolha do conversor
    printf("2 - Conversor de tempo: Horas, Min, Seg \n");
    printf("3 - Conversor de Velocidade\n");
    printf("Digite a opção desejada: ");
    int opcao;
    scanf("%d", &opcao);

    // Adicionar na condição abaixo o numero para acesso ao seu conversor
    switch (opcao) {
    case 1:
        double valor;
        char origem[2], destino[2];
        printf("Conversor de Temperatura\n\n");
        printf("Digite o valor da temperatura: ");
        scanf("%lf", &valor);

        printf("Digite a unidade de origem (C, F, K): ");
        scanf("%s", origem);

        printf("Digite a unidade de destino (C, F, K): ");
        scanf("%s", destino);

        double resultado = converter_temperatura(valor, origem, destino);
        printf("O valor convertido de %s para %s é: %.2lf\n", origem, destino, resultado);

        break;
    case 2:
        int escolha, valor;
        printf("Conversor de Tempo\n\n");
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

        break;
    case 3:
        double valor;
        char unidade[5];

        printf("Conversor de Velocidade\n\n");
        
        printf("Digite o valor a ser convertido: ");
        scanf("%lf", &valor);
        
        print("Digite a unidade de medida desse valor: ");
        scanf("%4s", unidade);

        double* result = converter_velocidade(valor, unidade);

        if(result != NULL){
            printf("%.2lf %s em km/h: %.2lf\n", valor, unidade, result[0]);
            printf("%.2lf %s em m/s: %.2lf\n", valor, unidade, result[1]);
            printf("%.2lf %s em mph: %.2lf\n", valor, unidade, result[2]);
        }
        else
            printf("Erro: Unidade '%s' inválida. Tente 'km/h', 'm/s' ou 'mph'.\n", unidade);

    default:
        printf("Opção inválida!\n");
        break;
    } 
    
    return 0;
}


// Espaço para criação de funções de conversão de unidades

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


double* converter_velocidade(double valor, char *unidade){
    // [0] - km/h; [1] - m/s; [2] - mph
    static double result[3] = {0.0, 0.0, 0.0};

    // Converte se a unidade de medida for km/h
    if(strcmp(unidade, KMH) == 0) {
        result[0] = valor;
        result[1] = valor / KMH_TO_MS;
        result[2] = valor * KMH_TO_MPH;

        // retorna um ponteiro pro vetor dos resultados
        return result;
    }

    // Converte se a unidade de medida for m/s
    if(strcmp(unidade, MS) == 0) {
        result[0] = valor * KMH_TO_MS;
        result[1] = valor;
        result[2] = valor * MS_TO_MPH;

        // retorna um ponteiro pro vetor dos resultados
        return result;
    }

    // Converte se a unidade de medida for mph
    if(strcmp(unidade, MPH) == 0) {
        result[0] = valor / KMH_TO_MPH;
        result[1] = valor / MS_TO_MPH;
        result[2] = valor;

        // retorna um ponteiro pro vetor dos resultados
        return result;
    }

    // Caso não consiga converter
    return NULL;
}