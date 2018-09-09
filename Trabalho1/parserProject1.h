#include <bits/stdc++.h>

using namespace std;

const int GRAPH_MAX_SIZE = 200;

vector<bool> node_exist(GRAPH_MAX_SIZE);

vector<vector<int>> graph(GRAPH_MAX_SIZE);

int Ler_Arquivo(string _arquivo)
{
  string linha;
  fstream arquivo;

  arquivo.open(_arquivo);
  if (!arquivo)
  {
    //algo deu errado com a leitura do arquivo.
    return 0;
  }

  while (arquivo >> linha)
  {
    //cout << linha << endl;
    if (linha == "node")
    {
      int newNode; // Declaracao da variavel que vai receber o id.
      while (arquivo >> linha && linha != "id")
      {
        //Pula as linhas ate encontrar o id.
        //cout << "Pulano a linha: " << linha << " ate achar o id" << endl;
      }
      arquivo >> linha;      // Faz a leitura do id.
      newNode = stoi(linha); // Transforma ele em inteiro.
      //cout << "Construindo node : " << newNode << endl;
      node_exist[newNode] = true; // Atuliza o vetor de nodes existentes.
    }
    else if (linha == "edge")
    {
      int source, target; // Declaracao das variaveis que vao receber a origem e o destino da aresta, respectivamente.
      while (arquivo >> linha && linha != "source")
      {
        //Pula as linhas ate encontrar o source.
        //cout << "Pulando a linha: " << linha << " ate achar source" << endl;
      }
      arquivo >> linha;     // Esse recebe o valor do source.
      source = stoi(linha); // Transforma ele em inteiro.
      while (arquivo >> linha && linha != "target")
      {
        //Pula as linhas ate encontrar o target.
        //cout << "Pulando a linha: " << linha << " ate achar target" << endl;
      }
      arquivo >> linha;     // Esse recebe o valor do source.
      target = stoi(linha); // Transforma ele em inteiro.
      //cout << "Construindo aresta de: " << source << " para: " << target << endl;
      graph[source].push_back(target); // Atualiza a lista de adjacencia do grafo com a nova aresta criada.
      graph[target].push_back(source); // Como o grafo eh nao direcionado, a aresta contraria tambem eh criada.
    }
  }

  return 1;
}