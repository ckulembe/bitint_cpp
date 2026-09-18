# BigInt em C++

## Objetivo

Este projeto tem como objetivo implementar, do zero, uma estrutura de dados para representar números inteiros maiores do que os limites dos tipos nativos do C++, como `int`, `long` e `unsigned long`.

A ideia central é criar uma versão de `BigInt`, também conhecida como bigint, capaz de armazenar valores arbitrários sem depender do tamanho fixo da arquitetura do sistema. Para isso, a estrutura utiliza uma sequência de dígitos em vez de um valor binário limitado por um tipo primitivo.

## Motivação

Os computadores têm capacidade de memória finita e os tipos inteiros convencionais também possuem limites definidos. Isso significa que, para qualquer tipo nativo, existe um valor mínimo e um valor máximo que ele consegue representar.

Quando um cálculo ultrapassa esse limite, ocorre o fenómeno conhecido como overflow. Em sistemas mais antigos, alguns inteiros eram representados por poucos bits, o que reduzia ainda mais o intervalo disponível. Por isso, estruturas como `std::string`, listas, pilhas ou vetores permitem representar valores muito maiores, desde que haja memória suficiente.

## Como funciona

Em vez de guardar o número como um único valor inteiro fixo, o `BigInt` armazena os seus dígitos em sequência. Assim, é possível realizar operações como soma, comparação, incremento e deslocamento com valores muito maiores do que os suportados pelos tipos normais.

Essa abordagem permite tratar o número como se fosse um inteiro comum, mas sem as limitações impostas pela arquitetura ou pela linguagem.

## Operações implementadas

- Adição;
- Incremento: pré-incremento e pós-incremento;
- Comparação entre valores;
- Operadores de deslocamento à esquerda;
- Operadores lógicos.

## Estrutura do projeto

```text
.
├── header/
│   └── BigInt.hpp
├── src/
│   ├── BigInt.cpp
│   └── main.cpp
├── Makefile
├── README.md
└── bigint
```

## Compilar e executar

No diretório do projeto, execute:

```bash
make
./bigint
```

O programa demonstra algumas operações básicas da classe, como soma, incremento, comparação e deslocamento.

## Conclusão

Este projeto oferece uma forma prática de compreender como grandes inteiros podem ser representados e manipulados em C++. A principal vantagem é a capacidade de trabalhar com valores que excedem os limites dos tipos nativos, preservando a precisão e expandindo as possibilidades de cálculo.