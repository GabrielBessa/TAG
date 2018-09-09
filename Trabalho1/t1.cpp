#include <bits/stdc++.h>
#include "parserProject1.h"

using namespace std;

//Funcao que mostra os graus de um grafo, dado a lista de adjacencia desse grafo e o vetor de existencia dele.
void Mostrar_Graus(vector<vector<int>> _graph, vector<bool> _node_exist)
{
  //Loop para acessar todos os possiveis nodes do grafo
  for (int i = 0; i <= GRAPH_MAX_SIZE; i++)
  {
    //Checa a existencia daquele node
    if (_node_exist[i])
    {
      //Printa o tamanho da lista naquele indice, que diz quantos outros nodes estao conectados a ele, logo, seu grau.
      cout << "Grau do vertice " << i << " = " << graph[i].size() << endl;
    }
  }
}

int main()
{
  string arquivo;

  cout << "Insira o nome do arquivo .gml para fazer a leitura do grafo" << endl;

  cin >> arquivo;

  if (Ler_Arquivo(arquivo + ".gml") != 1)
  {
    cout << "Programa Finalizado" << endl;
    return 0;
  }
  Mostrar_Graus(graph, node_exist);
}