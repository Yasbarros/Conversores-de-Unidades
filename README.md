# Conversores-de-Unidades

## Conversor de Temperatura

### Sobre o Projeto

Este é um programa em linguagem C que realiza a conversão de temperaturas entre diferentes unidades: Celsius (C), Fahrenheit (F) e Kelvin (K). Ele faz parte de um conjunto de conversores de unidades.

### Funcionalidades

Converte temperaturas entre as seguintes unidades:

- Celsius (C)
- Fahrenheit (F)
- Kelvin (K)

### Como Funciona

O programa solicita ao usuário:

- O valor da temperatura a ser convertido.
- A unidade de origem (C, F, K).
- A unidade de destino (C, F, K).
  
Com base nas entradas, ele realiza a conversão utilizando as fórmulas matemáticas apropriadas e exibe o resultado.

### Exemplo de Uso

- Valor da temperatura: 25
- Unidade de origem: C
- Unidade de destino: F

### Saída do Programa:

"O valor convertido de C para F é: 77.00"

### Requisitos

- Compilador C (GCC)
- Sistema operacional compatível com C

### Observações

Certifique-se de inserir as unidades exatamente como especificado: C, F ou K.
O programa valida as unidades de origem e destino, exibindo uma mensagem de erro caso sejam inválidas.

### Autor

<i>Yasmim Barros de Jesus</i>

<hr>

## Conversor de Tempo

### Descrição:

Um programa simples em C que converte unidades de tempo entre horas, minutos e segundos.

### Funcionalidades:

- Converte horas para minutos
- Converte horas para segundos
- Converte minutos para horas
- Converte minutos para segundos
- Converte segundos para horas
- Converte segundos para minutos

#include <stdio.h>

int main() {
    // Código omitido para brevidade
}


### Exemplos de uso

- Converter 2 horas para minutos: escolha opção 1 e insira 2
- Converter 30 minutos para segundos: escolha opção 4 e insira 30

### Requisitos

- Compilador C (GCC)
- Sistema operacional compatível com C

### Autor

<i>Renan dos Santos Ferreira</i>

<hr>

## Conversor de velocidade

Converte as unidades de medidas de velocidade: 'km/h', 'm/s' e 'mph'.

### Exemplo de uso:
```C
Digite o valor a ser convertido: 20
Digite a unidade de medida desse valor: km/h

20 em km/h: 20.00
20 em m/s: 5.56
20 em mph: 12.43
```

### Autor
<i>Vítor Coutinho Lima</i>

<hr>

## Conversor unidade de área

Converte as unidades de medidas de área: cm² para m² ou m² para cm².

### Exemplo de uso:
```
Escolha a conversão que deseja realizar: cm² to m² ou m² para cm²
Digite o valor a ser convertido: valor numérico (20.5)
Resultado conversão.
```

### Autor
<i>Breno Arouca</i>

<hr>

## Conversor unidade de massa

Converte as unidades de medidas de massa: kg para ton e gr, gr para ton e kg, e ton para kg e gr.

### Exemplo de uso:
```
Escolha a conversão que deseja realizar: kg para ton e gr, ou gr para ton e kg, ou ton para kg e gr.
Digite valor númerico: valor (500 kg)
Resultado conversão:
Em Toneladas: 0,5 ton;
Em Gramas: 500.000 gr 
```

### Autor
<i>Gustavo de Medeiros</i>

<hr>

## Conversor de Volume

### Sobre o Projeto

Este é um programa em linguagem C desenvolvido para realizar a conversão de volumes entre diferentes unidades: Litros, Mililitros e Metros Cúbicos. Ele é uma solução prática para quem precisa trabalhar com diferentes escalas de medida no contexto de volumes.

### Funcionalidades

- Converte volumes entre:
  - Litros (L)
  - Mililitros (mL)
  - Metros Cúbicos (m³)

### Como Funciona

1. O usuário informa o valor do volume a ser convertido.  
2. Escolhe a unidade de origem (Litros, Mililitros ou Metros Cúbicos).  
3. Define a unidade de destino para conversão.  
4. O programa realiza o cálculo e exibe o resultado da conversão na tela.

### Exemplo de Uso

- **Entrada:**  
  - Valor do volume: 5  
  - Unidade de origem: Litros (L)  
  - Unidade de destino: Mililitros (mL)  
- **Saída:**  
  "5.000000 Litros = 5000.000000 Mililitros"

### Requisitos

- Compilador C (como GCC)  
- Um sistema operacional capaz de executar programas em C

### Observações

- Certifique-se de inserir valores e unidades de forma correta conforme solicitado pelo programa.  
- Caso as unidades sejam inválidas, o programa exibirá uma mensagem de erro para orientar o usuário.

### Autor
<i>Kalel Ezveither</i>

## Conversor de Comprimento

### Sobre o Projeto
Este é um programa desenvolvido na linguagem C, que tem como objetivo realizar a conversão de valores de comprimentos entre diferentes unidades, sendo elas: metro(m), centimetro(cm) e milimetro(mm).

### Funcionalidades
Converte comprimento entre:
- Metro(M)
- Centimetro(Cm)
- Milimetro(Mm)

### Como funciona
1. O usuário seleciona qual opção de conversão deseja realizar;
2. Informa o valor a ser convertido;
3. O programa realiza o fluxo lógico, realiza a conversão entre unidades e exibe no terminal o resultado.

### Exemplo de Uso
```
Conversor de Comprimento

1 - metro para centímetro
2 - metro para milímetro
3 - centímetro para metro
4 - centímetro para milímetro
5 - milímetro para metro
6 - milímetro para centímetro

Escolha uma das opções de conversão: 3
Insira o valor a ser convertido: 172.5


resultado: 1.725

```

### Observações
- O programa utiliza o padrão de ponto decimal sendo um ".", diferente do padrão brasileiro, que utiliza ",". Ou seja, valores decimais devem ser inseridos como xx.xx e não xx,xx.

### Autor
<i>Davi Macêdo Gomes</i>

---

## Conversor de Unidade de Armazenamento Digital

### Sobre o Projeto

Realiza a conversão entre diferentes unidades de dados digitais: bits, bytes, kilobytes (KB), megabytes (MB), gigabytes (GB) e terabytes (TB).

### Funcionalidades  

Converte valores entre as seguintes unidades de dados:

- Bits  
- Bytes  
- Kilobytes (KB)  
- Megabytes (MB)  
- Gigabytes (GB)  
- Terabytes (TB) 

### Como Funciona

O programa solicita ao usuário:  

1. O valor a ser convertido.  
2. A unidade de origem (bits, bytes, KB, MB, GB, TB).  
3. A unidade de destino (bits, bytes, KB, MB, GB, TB).  

### Exemplo de Uso

```
Conversor de Armazenamento Digital

Unidades Aceitas:
1 - Bits
2 - bytes
3 - kilobytes (KB)
4 - megabytes (MB)
5 - gigabytes (GB)
6 - terabytes (TB)

Informe o valor a ser convertido: 10.5
Escolha a unidade de origem: 3
Escolha a unidade de destino: 1

Resultado:
----- 10.500000 KBs ===> 86016.000000 bits -----
```

### Autor

*Paulo Hebert Rodrigues do Amaral*