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

// --- Constantes da Relação entre as unidades de armazenamento de dados ---
#define BYTE 1.0
#define KB BYTE * 1024.0
#define MB KB * 1024.0
#define GB MB * 1024.0
#define TB GB * 1024.0
#define BIT BYTE / 8.0

// Headers das funções
double converter_temperatura(double, const char *, const char *);
double* converter_velocidade(double, char*);
void converter_tempo(int, int *);
void unidade_area();
void conversor_massa();
void converterVolume(float valor, int unidadeOrigem, int unidadeDestino);
double converter_comprimento(double, int);
double converter_unidade_de_armazenamento_digital(double, int, int);
void conversor_armazenamento_digital();

int main() {
    
    printf("Escolha qual conversor de unidades deseja utilizar:\n");
    printf("1 - Conversor de temperaturas\n");  // Adicionar numeração no menu para escolha do conversor
    printf("2 - Conversor de tempo: Horas, Min, Seg \n");
    printf("3 - Conversor de Velocidade\n");
    printf("4 - Conversor de Massa: Kg, Gr, Ton\n");
    printf("5 - Conversor de Volume: L, mL, m^3\n");
    printf("6 - Conversor de Area: cm^2, m^2\n");
    printf("7 - Conversor de comprimento: m, cm, mm\n");
    printf("8 - Conversor de armazenamento digital (Bits, Bytes, KB, MB, GB, TB)\n");

    printf("\nDigite a opção desejada: ");
    int opcao;
    scanf("%d", &opcao);
    // Adicionar na condição abaixo o numero para acesso ao seu conversor
    switch (opcao) {
    case 1:{
        double valor_temperatura;
        char origem[2], destino[2];
        printf("Conversor de Temperatura\n\n");
        printf("Digite o valor da temperatura: ");
        scanf("%lf", &valor_temperatura);

        printf("Digite a unidade de origem (C, F, K): ");
        scanf("%s", origem);

        printf("Digite a unidade de destino (C, F, K): ");
        scanf("%s", destino);

        double resultado = converter_temperatura(valor_temperatura, origem, destino);
        printf("O valor convertido de %s para %s é: %.2lf\n", origem, destino, resultado);

        break;
    }
    case 2:{
        int escolha, valor_tempo;
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
        scanf("%d", &valor_tempo);

        converter_tempo(escolha, &valor_tempo);

        break;
    }
    case 3:{
        double valor_velocidade;
        char unidade[5];

        printf("Conversor de Velocidade\n\n");
        
        printf("Digite o valor a ser convertido: ");
        scanf("%lf", &valor_velocidade);
        
        printf("Digite a unidade de medida desse valor: ");
        scanf("%4s", unidade);

        double* result = converter_velocidade(valor_velocidade, unidade);

        if(result != NULL){
            printf("\n");
            printf("%.2lf em km/h: %.2lf\n", valor_velocidade, result[0]);
            printf("%.2lf em m/s: %.2lf\n", valor_velocidade, result[1]);
            printf("%.2lf em mph: %.2lf\n", valor_velocidade, result[2]);
        }
        else
            printf("Erro: Unidade '%s' inválida. Tente 'km/h', 'm/s' ou 'mph'.\n", unidade);

        break;
    }
    case 4:{
        conversor_massa();
        break;
    }
    case 5: {
        int unidadeOrigem, unidadeDestino;
        float valor;

        printf("Conversor de Unidades de Volume\n");
        printf("Escolha a unidade de origem:\n");
        printf("1. Litros\n");
        printf("2. Mililitros\n");
        printf("3. Metros Cúbicos\n");
        printf("Sua escolha: ");
        scanf("%d", &unidadeOrigem);

        while (unidadeOrigem < 1 || unidadeOrigem > 3) {
            printf("Unidade de origem inválida!. Digite novamente:\n");
            scanf("%d", &unidadeOrigem);
        }

        printf("Digite o valor: ");
        scanf("%f", &valor);

        printf("Escolha a unidade de destino:\n");
        printf("1. Litros\n");
        printf("2. Mililitros\n");
        printf("3. Metros Cúbicos\n");
        printf("Sua escolha: ");
        scanf("%d", &unidadeDestino);

        while (unidadeDestino < 1 || unidadeDestino > 3) {
            printf("Unidade de destino inválida!. Digite novamente:\n");
            scanf("%d", &unidadeDestino);
        }

        if (unidadeOrigem == unidadeDestino) {
            printf("A unidade de origem e de destino são iguais. Valor: %.6f\n", valor);
        } else {
            converterVolume(valor, unidadeOrigem, unidadeDestino);
        }
        break;
    }
    case 6:{
        unidade_area();
        break;
    }
    case 7:{
        int escolha;  // Variável para armazenar a opção de conversão escolhida pelo usuário.
        double valor; // Variável para armazenar o valor a ser convertido.
        double resultado; // Variável para armazenar o valor convertido.

        /*
        * Exibe o menu de opções de conversão ao usuário.
        * Cada número corresponde a uma conversão entre duas unidades de comprimento.
        */
        printf(
            "Conversor de Comprimento\n\n"
            "1 - metro para centímetro\n"
            "2 - metro para milímetro\n"
            "3 - centímetro para metro\n"
            "4 - centímetro para milímetro\n"
            "5 - milímetro para metro\n"
            "6 - milímetro para centímetro\n\n"
            "Escolha uma das opções de conversão: "
        );

        /* Lê a opção escolhida pelo usuário e armazena na variável `escolha`. */
        scanf("%d", &escolha);

        /* Solicita ao usuário o valor a ser convertido. */
        printf("Insira o valor a ser convertido: ");
        scanf("%lf", &valor);

        /*
        * Realiza uma conversão de comprimento com base em um valor e uma opção fornecidos. 
        * Se a opção escolhida for inválida, o programa exibe uma mensagem de erro. 
        * Caso contrário, o resultado da conversão é exibido com três casas decimais.
        */
        resultado = converter_comprimento(valor, escolha);
        if (resultado == -1) {
            printf(
                "\n"
                "opção inválida, tente novamente.\n"
            );
            break;
        }
        printf(
            "\n"
            "resultado: %.3lf\n",
            resultado
        );
        break;

    }
    case 8:
        conversor_armazenamento_digital();
        break;
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

void conversor_massa() {
    int opcao;
    double valor;

    printf("Conversor de Massa\n");
    printf("Escolha a conversão que deseja realizar:\n");
    printf("1. Kg para Toneladas e Gramas\n");
    printf("2. Gramas para Toneladas e Quilogramas\n");
    printf("3. Toneladas para Quilogramas e Gramas\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    printf("Digite o valor numérico: ");
    scanf("%lf", &valor);

    switch (opcao) {
    case 1:
        printf("\nResultado da conversão:\n");
        printf("Em Toneladas: %.3f ton\n", valor / 1000);
        printf("Em Gramas: %.0f g\n", valor * 1000);
        break;
    case 2:
        printf("\nResultado da conversão:\n");
        printf("Em Toneladas: %.6f ton\n", valor / 1e6);
        printf("Em Quilogramas: %.3f kg\n", valor / 1000);
        break;
    case 3:
        printf("\nResultado da conversão:\n");
        printf("Em Quilogramas: %.3f kg\n", valor * 1000);
        printf("Em Gramas: %.0f g\n", valor * 1e6);
        break;
    default:
        printf("Opção inválida!\n");
    }
}

void unidade_area(){
    int op = 0;
    float entrada = 0.0;

    printf("\nTipos de Conversao\n 1 - centimetro^2 -> metro^2\n 2 - metro^2 -> centimetro^2)\n\n Escolha: ");
    scanf("%d%*c", &op);
    printf("Insira a medida de area para ser realizada a conversao: ");
    scanf("%f%*c", &entrada);
    switch (op){
    case 1:
        printf("Entrada: %.2f cm^2\n", entrada);
        printf("Conversao: %.3f m^2", entrada/10000);
        break;

    case 2:
        printf("Entrada: %.2f m^2\n", entrada);
        printf("Conversao: %.3f cm^2", entrada * 10000);
        break;
    default:
        printf("\nOpcao invalida, tente novamente!!\n");
        break;
    }
    printf("\n\n");
}

void converterVolume(float valor, int unidadeOrigem, int unidadeDestino) {
    float resultado;
    char *unidadeOrigemStr, *unidadeDestinoStr;

    // Determina as strings das unidades
    if (unidadeOrigem == 1) unidadeOrigemStr = "Litros";
    else if (unidadeOrigem == 2) unidadeOrigemStr = "Mililitros";
    else if (unidadeOrigem == 3) unidadeOrigemStr = "Metros Cúbicos";

    if (unidadeDestino == 1) unidadeDestinoStr = "Litros";
    else if (unidadeDestino == 2) unidadeDestinoStr = "Mililitros";
    else if (unidadeDestino == 3) unidadeDestinoStr = "Metros Cúbicos";

    // Conversão para a unidade de destino
    if (unidadeOrigem == 1) { // Litros
        if (unidadeDestino == 2) { // Para mililitros
            resultado = valor * 1000;
        } else if (unidadeDestino == 3) { // Para metros cúbicos
            resultado = valor / 1000;
        }
    } else if (unidadeOrigem == 2) { // Mililitros
        if (unidadeDestino == 1) { // Para litros
            resultado = valor / 1000;
        } else if (unidadeDestino == 3) { // Para metros cúbicos
            resultado = valor / 1000000;
        }
    } else if (unidadeOrigem == 3) { // Metros cúbicos
        if (unidadeDestino == 1) { // Para litros
            resultado = valor * 1000;
        } else if (unidadeDestino == 2) { // Para mililitros
            resultado = valor * 1000000;
        }
    }

    printf("%.6f %s = %.6f %s\n", valor, unidadeOrigemStr, resultado, unidadeDestinoStr);
}

double converter_comprimento(double valor, int escolha) {
    /*
    * 1. metro para centímetro (m → cm): multiplica o valor por 100.
    * 2. metro para milímetro (m → mm): multiplica o valor por 1000.
    * 3. centímetro para metro (cm → m): divide o valor por 100.
    * 4. centímetro para milímetro (cm → mm): multiplica o valor por 100.
    * 5. milímetro para centímetro (mm → cm): divide o valor por 100.
    * 6. milímetro para metro (mm → m): divide o valor por 1000.
    */

    if (escolha == 1 || escolha == 4) return valor*100.0;
    if (escolha == 3 || escolha == 5) return valor/100.0;
    if (escolha == 2) return valor*1000.0;
    if (escolha == 6) return valor/1000.0;
    return -1;
}

// Função para converter entre unidades as unidades de armazenamento de dados
double converter_unidade_de_armazenamento_digital(double valor, int unidade_origem, int unidade_destino) {
    double fator[6] = {BIT, BYTE, KB, MB, GB, TB};

    // Converte para bytes (unidade comum)
    double valor_em_bytes = valor * fator[unidade_origem - 1];
    // Converte de bytes para a unidade de destino
    return valor_em_bytes / fator[unidade_destino - 1];
}

void conversor_armazenamento_digital() {
    double valor, resultado;
    int unidade_origem, unidade_destino;
    char unidade_str[6][5] = {"bit", "byte", "KB", "MB", "GB", "TB"};

    // MENU
    printf("\n\nConversor de Armazenamento Digital\n\n");
    printf("Unidades Aceitas:\n");
    printf("1 - Bits\n");
    printf("2 - Bytes\n");
    printf("3 - Kilobytes (KB)\n");
    printf("4 - Megabytes (MB)\n");
    printf("5 - Gigabytes (GB)\n");
    printf("6 - Terabytes (TB)\n\n");

    // Valor a ser convertido
    printf("Informe o valor a ser convertido: ");
    scanf("%lf", &valor);

    // Unidade de origem
    do {
        printf("Escolha a unidade de origem: ");
        scanf("%d", &unidade_origem);
        if(unidade_origem < 1 || unidade_origem > 6) {
            printf("Erro: Escolha inválida! Por favor, escolha entre 1 a 6.\n");
        }
    } while(unidade_origem < 1 || unidade_origem > 6);

    // Unidade de destino
    do {
        printf("Escolha a unidade de destino: ");
        scanf("%d", &unidade_destino);
        if(unidade_destino < 1 || unidade_destino > 6) {
            printf("Erro: Escolha inválida! Por favor, escolha entre 1 a 6.\n");
        }
    } while(unidade_destino < 1 || unidade_destino > 6);

    resultado = converter_unidade_de_armazenamento_digital(valor, unidade_origem, unidade_destino);

    printf("\nResultado:\n----- %lf %s%c ===> %lf %s%c -----\n",
        valor,
        unidade_str[unidade_origem - 1],
        valor > 1 ? 's': '\0',
        resultado,
        unidade_str[unidade_destino -1],
        resultado > 1 ? 's': '\0'
    );
}
