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
            for(int j = 0; j<textoPorLinha[i].size(); j++){
                if(textoPorLinha[i][j] == '\n' and comentario){ // Verificação para não pegar caracteres a mais no final do comentário em linha
                    comentario = false;
                    continue;
                }
                if(textoPorLinha[i][j] == '*' and textoPorLinha[i][j+1] == '/'){ // Verificação para não pegar caracteres a mais no final do comentário em bloco
                    comentario2 = false;
                    j+=2;
                    continue;
                } 
                
                if(textoPorLinha[i][j] == ' ') espaco++;//Contador de espacos em branco
                if(textoPorLinha[i][j] != ' ') espaco = 0; 

                if(textoPorLinha[i][j] == '/' and textoPorLinha[i][j+1] == '/') comentario = true; //Verifação de comentário em Linha
                if(textoPorLinha[i][j] == '/' and textoPorLinha[i][j+1] == '*') comentario2 = true; //Verifação de comentário em Bloco

                
                if((textoPorLinha[i][j] != '\n' or textoPorLinha[i].size() != 1) and (comentario != true) and (comentario2 != true) and espaco < 2){ // Verificação de tudo que não pode entrar no texto limpo
                    result+= textoPorLinha[i][j];
                }
                
            }
            
        }
        this->texto = result; //Alteração do atributo texto para o resultado limpo
     };
     void imprimeTextoArquivo(){ //Método para impressão no arquivo
        ofstream arquivo2;
            string nomeDoArquivo2 = "/home/puc/teste1.txt";
            arquivo2.open(nomeDoArquivo2.c_str(),std::ios::out|std::ios::app);
            arquivo2 << texto << endl;
            arquivo2.close();
     };

};



int main(){
    analisadorLexico obj;
    obj.leArquivo();
    //cout << obj.texto << endl;
    obj.limpaArquivo();
    //cout << obj.texto << endl;
    obj.imprimeTextoArquivo();
   
   
    
}
