#include <bits/stdc++.h>

using namespace std;


class analisadorLexico{

    public:
    //----------------------------------- Atributos ----------------------------------------------//
    string texto;
    
    vector<string> textoPorLinha;
    
    map<string,int> tabelaIdentificadores;
    map<string,int>::iterator it;
    
    string palavrasReservadas[9] = {"var","read","write","if","then","(",")",":",";"};
    string operadorLogico[3] = {">","<","="};
    string operadorMatematico[4] = {"+","-","*","/"};
    string comparadorLogico[3] = {"and","or","not"};
    

    // ----------------------------------- Métodos -----------------------------------------------//
    void leArquivo(){
        ifstream arquivo;
        string nomeDoArquivo = "C:/Users/20211002800150/Desktop/teste.txt";
        arquivo.open(nomeDoArquivo.c_str(),std::ios::out|std::ios::app);
        string linha, texto = "";
        getline(arquivo,linha);
        while(!arquivo.eof()){
            texto += linha;
            texto += '\n';
            getline(arquivo,linha);
        }
        getline(arquivo,linha);
        texto += linha;
        texto += '\n';
        arquivo.close();
        this->texto = texto;
        string aux = ""; 
        for(int i = 0; i<(int)texto.size(); i++){
            aux+=texto[i];
            if(texto[i] == '\n'){
                textoPorLinha.push_back(aux);
                aux = "";
            }
        }
        
    }
     void limpaArquivo(){
        // função responsável por limpar o conteúdo do arquivo
        // inicialização das variáveis locais
        string result = "";
        bool comentario = false;
        bool comentario2 = false;
        int espaco = 0;

        // percorre o vetor de linhas do arquivo
        for(int i = 0; i<(int)textoPorLinha.size(); i++){
            // percorre os caracteres de cada linha
            for(int j = 0; j<(int)textoPorLinha[i].size(); j++){
                // caso o caractere atual seja uma quebra de linha e esteja dentro de um comentário, indica que o comentário foi finalizado
                if(textoPorLinha[i][j] == '\n' and comentario){
                    comentario = false;
                    continue;
                }
                // caso o caractere atual e o próximo formem o fim de um comentário, indica que o comentário foi finalizado
                if(textoPorLinha[i][j] == '*' and textoPorLinha[i][j+1] == '/'){
                    comentario2 = false;
                    j+=2;
                    continue;
                } 
                
                // conta o número de espaços consecutivos
                if(textoPorLinha[i][j] == ' ') espaco++;
                if(textoPorLinha[i][j] != ' ') espaco = 0;

                // verifica se o caractere atual e o próximo formam o início de um comentário
                if(textoPorLinha[i][j] == '/' and textoPorLinha[i][j+1] == '/') comentario = true;
                if(textoPorLinha[i][j] == '/' and textoPorLinha[i][j+1] == '*') comentario2 = true;

                // caso o caractere atual não seja uma quebra de linha ou a linha não tenha tamanho 1 e não esteja dentro de um comentário,
                // adiciona o caractere à string resultante, exceto se houver mais de um espaço consecutivo
                if((textoPorLinha[i][j] != '\n' or (int)textoPorLinha[i].size() != 1) and (comentario != true) and (comentario2 != true) and espaco < 2){
                    result+= textoPorLinha[i][j];
                }
                
            }
            
        }
        // atualiza o conteúdo do arquivo
        this->texto = result;
    }
     void imprimeTextoArquivo(){
        // função responsável por imprimir o conteúdo do arquivo limpo em um novo arquivo
        // abre o arquivo para escrita
        ofstream arquivo2;
        string nomeDoArquivo2 = "C:/Users/20211002800150/desktop/teste1.txt";
        arquivo2.open(nomeDoArquivo2.c_str(),std::ios::out|std::ios::app);
        // escreve o conteúdo do arquivo limpo no novo arquivo
        arquivo2 << texto << endl;
        // fecha o arquivo
        arquivo2.close();
    }

     void fazTokens(string texto){
		 
		 string textoTokens = "";
		 string conca = "";
		 int countID = 1;
         bool ok = true;
		 // repetição que passa por todos os caracteres do texto
		 for(int i = 0; i<(int)texto.size(); i++){
             if(texto[i] == '\n') textoTokens += '\n';
			 if(texto[i] != ' ' and texto[i] != '\t' and texto[i] != '\n')conca += texto[i];
			 if(texto[i] == ' ' ){
                //cout << conca << "conca" << endl;

				 //procura no vetor de palavras reservadas;
				 for(int j = 0; j<9; j++){
					 if(palavrasReservadas[j] == conca){
							textoTokens += "[" + palavrasReservadas[j] + ", PR]";
                            ok = false;
					 }
				 }
                 //procura no vetor de operadores logicos;
                 for(int j = 0; j<3; j++){
                    if(operadorLogico[j] == conca){
                        textoTokens += "[OL, " + operadorLogico[j] + "]";
                        ok = false;
                    }
                 }
                 //procura no vetor de operadores matematico;
                 for(int j = 0; j<4; j++){
                    if(operadorMatematico[j] == conca){
                        textoTokens += "[OM, " + operadorMatematico[j] + "]";
                        ok = false;
                    }
                 }
                 //procura no vetor de comparaçoes logicas;
                 for(int j = 0; j<3; j++){
                    if(comparadorLogico[j] == conca){
                        textoTokens += "[CL, " + comparadorLogico[j] + "]";
                        ok = false;
                    }
                 }
                 // verifica se é inicio de frase
                    bool ok2 = true;
                    string concafrase = "";
                    if((int)conca.size() == 1 and conca[0] == 34){
                    ok = false;
                    int j;
                    for(j = i+1; ok2 == true; j++){
                        if(texto[j] == 34){
                            ok2 = false;
                            
                        }
                        else if(texto[j] != 34){
                            concafrase += texto[j];
                        }
                    }
                    i = j;
                    textoTokens += "[FR, " + concafrase + "]";
                 } 
                 //verifica se é numero
                    bool ok3 = true;
                    for(int j = 0; j<(int)conca.size() and ok3 == true; j++){
                        if(isdigit(conca[j]) == false){
                            ok3 = false;
                        }
                    }
                    if(ok3 == true){ 
                        textoTokens += "[nu, " + conca + "]";
                        ok = false;
                    }

				 // identificadores
                 bool ok4 = true;
                 if(ok){
                    for(int j = 0; j<(int)conca.size() and ok4 == true; j++){
                        if(isalpha(conca[j]) == false) ok4 = false;
                    }
                    if(ok4){
                        if(!tabelaIdentificadores[conca]){
                            tabelaIdentificadores[conca] = countID;
                            textoTokens += "[id, " +  to_string(countID) + ", " + conca + "]";
                            countID++; 
                        }
                        else{
                            textoTokens += "[id, " +  to_string(tabelaIdentificadores[conca]) + ", " + conca + "]";
                        }
                    }
                    //se nao for nada acima, é pq é um eerro
                    else textoTokens += "[ERRO]";
                 }
                 conca = "";
                 ok = true;
				
			 }
             
		 }
         //passa o resultado do texto para um arquivo;
        ofstream arquivo2;
        string nomeDoArquivo2 = "C:/Users/20211002800150/desktop/tokens.txt";
        arquivo2.open(nomeDoArquivo2.c_str(),std::ios::out|std::ios::app);
        // escreve o conteúdo do arquivo limpo no novo arquivo
        arquivo2 << textoTokens << endl;
        // fecha o arquivo
        arquivo2.close();
	 }
     
};



int main(){
    analisadorLexico obj;
    obj.leArquivo();
    //cout << obj.texto << endl;
    obj.limpaArquivo();
    //cout << obj.texto << endl;
    obj.imprimeTextoArquivo();
    obj.fazTokens(obj.texto);
   
   
    
}



