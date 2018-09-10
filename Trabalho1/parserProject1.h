//Universidade de Brasilia
//Departamento de Ciencia da Computacao
//Materia : Teoria e aplicacao de grafos          Periodo : 2018/2
//Professor : Dibio Leandro Borges
//Projeto : Projeto 1
//Alunos : 	Andre Cassio Barros de Souza (16/0111943)
//			Gabriel Cunha Bessa (16/0120811)

#include <bits/stdc++.h>

using namespace std;

const int GRAPH_MAX_SIZE = 500;

vector<vector<int> > graph(GRAPH_MAX_SIZE); // lista de adjacencia do grafo

vector<vector<int> > cliques; //lista de listas para receber os cliques

vector<int> nodes;	//todos os nodes do grafo

map<int, int> index_p_valor; // hash para mapear os valores, dado o index
map<int, int> valor_p_index; // hash para mapear os indexes, dado o valor

int Ler_Arquivo(string _arquivo)
{
	string linha;
	fstream arquivo;

	arquivo.open(_arquivo);
	if(!arquivo)
	{
		//algo deu errado com a leitura do arquivo.
		cout << "Arquivo nao encontrado!" << endl;
		return 0;
	}

	int index = 0; //variavel para gerar os indices nos mapas

	while(arquivo >> linha)
	{
		if(linha == "node")
		{
			int valorNovoNode; // Declaracao da variavel que vai receber o id.
			while(arquivo >> linha && linha != "id")
			{
				//Pula as linhas ate encontrar o id.
			}
			arquivo >> linha; // Faz a leitura do id.
			valorNovoNode = stoi(linha); // Transforma ele em inteiro.
			nodes.push_back(valorNovoNode);
			index_p_valor[index] = valorNovoNode;
			valor_p_index[valorNovoNode] = index++; 
		}
		else if(linha == "edge")
		{
			int origem, alvo; // Declaracao das variaveis que vao receber a origem e o destino da aresta, respectivamente.
			while(arquivo >> linha && linha != "source")
			{
				//Pula as linhas ate encontrar o source.
			}
			arquivo >> linha; // Esse recebe o valor do source.
			origem = stoi(linha); // Transforma ele em inteiro.
			while(arquivo >> linha && linha != "target")
			{
				//Pula as linhas ate encontrar o target.
			}
			arquivo >> linha; // Esse recebe o valor do source.
			alvo = stoi(linha); // Transforma ele em inteiro.
			graph[valor_p_index[origem]].push_back(valor_p_index[alvo]); // Atualiza a lista de adjacencia do grafo com a nova aresta criada.
			graph[valor_p_index[alvo]].push_back(valor_p_index[origem]); // Como o grafo eh nao direcionado, a aresta contraria tambem eh criada.

		}

	}

	return 1;
}