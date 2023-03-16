#include <bits/stdc++.h>

using namespace std;

// Classe que representa o analisador léxico
class analisadorLexico{

    public:
    //----------------------------------- Atributos ----------------------------------------------//
    string texto; // String que armazena todo o texto do arquivo
    vector<string> textoPorLinha; // Vetor que armazena cada linha do texto do arquivo em uma posição

    // ----------------------------------- Métodos -----------------------------------------------//

    // Método para ler o arquivo e armazenar o conteúdo na string texto e no vetor textoPorLinha
    void leArquivo(){
        ifstream arquivo; // Cria um objeto ifstream para ler o arquivo
        string nomeDoArquivo = "/home/puc/teste.txt"; // Nome do arquivo que será lido
        arquivo.open(nomeDoArquivo.c_str(),std::ios::out|std::ios::app); // Abre o arquivo
        string linha, texto = "";
        getline(arquivo,linha); // Lê a primeira linha do arquivo
        while(!arquivo.eof()){ // Enquanto não chegar ao final do arquivo
            texto += linha; // Concatena a linha lida com a string texto
            texto += '\n'; // Adiciona um caractere de quebra de linha à string texto
            getline(arquivo,linha); // Lê a próxima linha do arquivo
        }
        getline(arquivo,linha); // Lê a última linha do arquivo
        texto += linha; // Concatena a última linha lida com a string texto
        texto += '\n'; // Adiciona um caractere de quebra de linha à string texto
        arquivo.close(); // Fecha o arquivo
        this->texto = texto; // Armazena a string texto no atributo texto da classe
        string aux = ""; 
        for(int i = 0; i<texto.size(); i++){
            aux+=texto[i];
            if(texto[i] == '\n'){ // Se encontrar um caractere de quebra de linha
                textoPorLinha.push_back(aux); // Adiciona a string aux no vetor textoPorLinha
                aux = ""; // Reinicia a string aux
            }
        }
        
    };

    // Método para remover comentários e espaços em branco do arquivo
     void limpaArquivo(){
        string result = ""; // String que armazena o texto do arquivo sem comentários e espaços em branco
        bool comentario = false; // Variável que indica se a linha atual é um comentário de uma linha
        bool comentario2 = false; // Variável que indica se a linha atual é um comentário de múltiplas linhas
        int espaco = 0; // Contador de espaços em branco

        for(int i = 0; i<textoPorLinha.size(); i++){ // Para cada linha do vetor textoPorLinha
            for(int j = 0; j
