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
    

    // ----------------------------------- Métodos -----------------------------------------------//
    void leArquivo(){
        ifstream arquivo;
        string nomeDoArquivo = "/home/puc/teste.txt";
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
        
    };
     void limpaArquivo(){
        string result = "";
        bool comentario = false;
        bool comentario2 = false;
        int espaco = 0;

        for(int i = 0; i<(int)textoPorLinha.size(); i++){
            for(int j = 0; j<(int)textoPorLinha[i].size(); j++){
                if(textoPorLinha[i][j] == '\n' and comentario){
                    comentario = false;
                    continue;
                }
                if(textoPorLinha[i][j] == '*' and textoPorLinha[i][j+1] == '/'){
                    comentario2 = false;
                    j+=2;
                    continue;
                } 
                
                if(textoPorLinha[i][j] == ' ') espaco++;
                if(textoPorLinha[i][j] != ' ') espaco = 0;

                if(textoPorLinha[i][j] == '/' and textoPorLinha[i][j+1] == '/') comentario = true;
                if(textoPorLinha[i][j] == '/' and textoPorLinha[i][j+1] == '*') comentario2 = true;

                
                if((textoPorLinha[i][j] != '\n' or textoPorLinha[i].size() != 1) and (comentario != true) and (comentario2 != true) and espaco < 2){
                    result+= textoPorLinha[i][j];
                }
                
            }
            
        }
        this->texto = result;
     };
     void imprimeTextoArquivo(){
        ofstream arquivo2;
            string nomeDoArquivo2 = "/home/puc/teste1.txt";
            arquivo2.open(nomeDoArquivo2.c_str(),std::ios::out|std::ios::app);
            arquivo2 << texto << endl;
            arquivo2.close();
     };
     void fazTokens(string texto){
		 
		 string textoTokens = "";
		 
		 string conca = "";
		 
		 int countID = 1;
		 
		 
		 for(int i = 0; i<texto.size(); i++){
			 conca += texto[i];
			 if(texto[i] == " "){
				 //procura no vetor de palavras reservadas;
				 for(int j = 0; j<9; j++){
					 if(palavrasReservadas[j] == conca){
							textoTokens += "[" + palavrasReservadas[j] + ",]";
					 }
				 }
				 
				 // identificadores
				 if(tabelaIdentificadores[conca].find(conca) == it.end()){
					 tabelaIdentificadores[conca] = countID;
					 textoTokens += "[id," +  to_string(countID) + "]";
					 countID++; 
				 }
				 else{
					 textoTokens += "[id," +  tabelaIdentificadores[conca] + "]";
				 }
				 
			 }
		 }
	 }
     

};



int main(){
    analisadorLexico obj;
    obj.leArquivo();
    //cout << obj.texto << endl;
    obj.limpaArquivo();
    //cout << obj.texto << endl;
    obj.imprimeTextoArquivo();
   
   
    
}


// comecei a parte de fazer os tokens, lembrar de ter duplicidade na linha (verificao de palavra reservada nao faz parar abaixo), 
//falta verificar algumas palavras de tokens como "<" etc
