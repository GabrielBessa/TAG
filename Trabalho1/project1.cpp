//Universidade de Brasilia
//Departamento de Ciencia da Computacao
//Materia : Teoria e aplicacao de grafos          Periodo : 2018/2
//Professor : Dibio Leandro Borges
//Projeto : Projeto 1
//Alunos : 	Andre Cassio Barros de Souza (16/0111943)
//			Gabriel Cunha Bessa (16/0120811)

#include <bits/stdc++.h>
#include "parserProject1.h"

using namespace std;



//Algoritmo Bron & Kerbosh para encontrar os cliques maximais
void BK(vector<int> _r, vector<int> _p, vector<int> _x)
{
	// _r = vertices escolhidos para o clique atual
	// _p = possiveis vertices para expandir o clique atual
	// _x = vertices que nao podem fazer parte do clique atual

	// Se _p e _x estao vazios, quer dizer que todos os vertices do clique atual estao em _r
	// O clique encontrado eh armazenado no vetor "cliques"
	if(_p.empty() && _x.empty()) 
	{
		cliques.push_back(_r);
	}
	
	// Vetores para marcar os elementos na intercessao dos vetores "_p" e "_x" que estao sendo considerados ativos
	bool intercessao_p[nodes.size() + 1];
	bool intercessao_x[nodes.size() + 1];

	memset(intercessao_p,0,sizeof intercessao_p); //inicializacao dos vetores para 0 (false)
	memset(intercessao_x,0,sizeof intercessao_x);
	
	for(int i = 0; i < _p.size(); i++)
		intercessao_p[_p[i]] = 1;
	for(int i = 0; i < _x.size(); i++)
		intercessao_x[_x[i]] = 1;
	
	for(int i = 0; i < _p.size(); i++){

		// Adiciona um novo vertice, "_p[i]" ao clique que se pretende expandir
		_r.push_back(_p[i]);

		// Vetores "p2" e "x2" representam a intercessao entre os vetores "_p" e "_x", respectivamente
		// e o conjunto de vizinhos do vertice "_p[i]"
		vector<int> p2, x2;
		for(int j = 0; j < graph[_p[i]].size(); j++){

			if(intercessao_p[graph[_p[i]][j]])
				p2.push_back(graph[_p[i]][j]);
			
			if(intercessao_x[graph[_p[i]][j]])
				x2.push_back(graph[_p[i]][j]);
		}

		// Realiza uma chamada recursiva para tentar expandir o conjunto de vertices de "_r"
		// com os vertices de "p2"
		BK(_r,p2,x2);

		// Remove o vertice "_p[i]" do vetor "_r" para procurar cliques em outros conjuntos
		// de vertices nas proximas iteracoes
		_r.pop_back();

		// Remove o vertice "_p[i]" do vetor "_p" e o adiciona ao vetor "_x"
		intercessao_p[_p[i]] = 0;
		intercessao_x[_p[i]] = 1;
	}
}

void Mostrar_Cliques()
{
	// Declaracao dos vetores que serao usados no algoritmo de Bron & Kerbosh para encontrar os cliques maximais
	vector<int> r,p,x;
	// Coloca no p todos os elementos do grafo, inicialmente
	for(int i = 0; i < nodes.size(); i++)
		p.push_back(i);

	//Inicia o algoritmo para ahar os cliques maximais
	BK(r,p,x);

	//Ordena os cliques baseado em seu primeiro elemento
	sort(cliques.begin(), cliques.end());

	cout << "|-----------------------------------------------------------|" << endl;
	cout << "                       Cliques Maximais                   " << endl << endl;

	for(int i = 0 ; i < cliques.size() ; i++)
	{
		cout << "   Clique " << i+1 << " :"  << endl;
		cout << "        Tamanho : " << cliques[i].size() << endl;
		cout << "        Vertices : "  ;
		int count = 0;
		for(int w : cliques[i])
		{
			if(count)
				cout << " -> ";
			cout << index_p_valor[w] ;
			count++;
		}
		cout << endl << endl;
	}
}

//Funcao que mostra os graus do grafo.
void Mostrar_Graus()
{

	cout << "|-----------------------------------------------------------|" << endl;
	cout << "                     Graus dos vertices                      " << endl << endl;

	//Loop para acessar todos os possiveis nodes do grafo
	for(int i = 0 ; i < nodes.size() ; i++)
	{
		//Printa o tamanho da lista naquele indice, que diz quantos outros nodes estao conectados a ele, logo, seu grau.
			cout << "   Vertice : " << nodes[i] << "          Grau : " << graph[valor_p_index[nodes[i]]].size() << endl;
	}
	cout << endl;
	
}

//Funcao para procurar um elemento em uma lista
//Usada nesse trabalho para chegar a existencia de uma aresta que liga o _valor e algum elemento da lista
bool Procura(int _valor , vector<int> _listaAdj)
{
	for(int i = 0 ; i < _listaAdj.size(); i++)
	{
		if(_listaAdj[i] == _valor) return true;
	}
	return false;
}

//Funcao para calcular o coeficiente de aglomeracao de um node
float Coeficiente_Aglomeracao(int _node)
{

	//Essa funcao funciona da seguinte maneira:
	//para cada aresta ligada ao _node, checamos todas outras arestas de _node e checamos se existem elementos em comum
	//caso achemos uma intercessao, quer dizer que essas tres arestas formam um triangulo.
	//
	//A formuma para calcularmos o coeficiente eh : 2 * (numero de triangulos existentes) / (numero total de triangulos possiveis)

	int numerador = 0; //variavel para saber o numerador do coeficiente.	

	int tamanho = graph[_node].size(); // variavel para guardar o grau daquele vertice

	int denominador = tamanho * (tamanho -1); // variavel que guarda o denominador do coeficiente

	if(tamanho <= 1)	//para nao obter uma divisao por 0, checamos se o tamanho eh menor ou igual a um,
		return 0;		//que diz basicamente que eh impossivel formar triangulos com o node informado.
	
	int idx = 1;		//variavel para ajudar a percorrer o grafo e nao repitir os nodes.


	//Checagem das intercessoes do _node, para cada aresta selecionada e todas as outras arestas nao selecionadas
	for(int w : graph[_node])
	{
		for(int i = idx ; i < graph[_node].size() ; i++)
		{
			if(Procura(graph[_node][i],graph[w])) 
			{
				numerador++;		//Caso achemos uma intercessao, aumentamos o numero de triangulos em 1;
			} 
		}
		idx++;						//Incrementamos a variavel idx para nao percorrer pelo mesmo node
	}
	numerador *= 2;
	return (float) numerador / (float) denominador; // retorna o coeficiente
}


//Funcao para printar os coeficientes de aglomeracao e a media total
void Mostrar_Coeficientes_Aglomeracao()
{
	int contador = 0; 	//variavel para saber o numero de elementos no grafo, para calcular a media
	float soma = 0;		//variavel para saber a soma dos coeficientes, para depois dividir do total de elementos e obter a media

	cout << "|-----------------------------------------------------------|" << endl;
	cout << "                 Coeficientes de Aglomeracao                 " << endl << endl;

	//Loop para acessar todos os possiveis nodes do grafo
	for(int i = 0 ; i < nodes.size() ; i++)
	{
		float coef = Coeficiente_Aglomeracao(valor_p_index[nodes[i]]);
		cout << "   Vertice : " << nodes[i] << "          Coeficiente : " << coef << endl;
		soma += coef;
		contador++;
	}

	cout << endl << "   Coeficiente medio de aglomeracao do grafo : " << soma/(float)contador << endl << endl;

}


int main()
{
	string arquivo;

	cout << "|-----------------------------------------------------------|" << endl;
	cout << "                       Projeto 1 TAG                         " << endl << endl;
	cout << "Insira o nome do arquivo .gml para fazer a leitura do grafo:" << endl;

	cin >> arquivo;

	if(Ler_Arquivo(arquivo + ".gml") != 1)
	{
		cout << "Programa Finalizado" << endl;
		return 0;
	}

	Mostrar_Graus();
	Mostrar_Cliques();
	Mostrar_Coeficientes_Aglomeracao();

}