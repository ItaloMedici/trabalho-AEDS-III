# Trabalho AEDS III
Trabalho em desenvolvimento dentro do curso AEDSIII

## Objetivo do Trabalho
Elaborar um sistema onde o usuário passara um arquivo e uma forma de pesquisa de sua escolha. Esse programa deverá retornar quais as principais palavras repetidas no código e seus respectivos contares, atráves da forma de pesquisa inserida. 

Formas de pesquisas:
- Pesquisa Binaria Sequencial
- Pesquisa Sequencial
- Arvore Binária
- ...

Ao final do programa, deverá conter também o tempo gasto pela pesquisa passada como forma comparar quais pesquisas tomam menos tempo.

## Começando

Clone o Repositório
```
$ git clone https://github.com/ItaloMedici/trabalho-AEDS-III
```

Compile
```
$ gcc -o main.c libs/sequentialSearch.c libs/binarySearch.c libs/separator.c libs/utils.c libs/routes.c libs/binTreeSearch.c
```

Rode
```
$ ./main (tipo de pesquisa) file.txt
```