# TAG

## Projeto 1

Universidade de Brasília
Departamento de Ciência da Computação
Teoria e Aplicação de Grafos, Turma A, 1/2018
Prof. Díbio

Em 1977, no artigo “W. W. Zachary, An information flow model for conflict and fission in small
groups, Journal of Anthropological Research 33, 452-473 (1977).” uma rede social de amizades entre
34 integrantes de um grupo de karatê foi descrita e apresentada como um grafo para estudos. Os dados
estão em http://www-personal.umich.edu/~mejn/netdata/karate.zip em formato GML, e em http://www-
personal.umich.edu/~mejn/netdata/readgml.zip há um “parser” em C para os dados. O projeto consiste
em escrever um programa em C/C++ que lê o arquivo (karate.zip), monta com esses dados um grafo
não direcionado, sem pesos, usando listas de adjacências, e então calcular e imprimir como saída (tela)
o seguinte:

- [x] O vértice, e seu respectivo grau (para todos os vértices);
- [x] Todos os cliques maximais (indicando o número de vértices e quais);
- [x] O Coeficiente de Aglomeração de cada vértice;
- [x] O Coeficiente médio de Aglomeração do Grafo. 