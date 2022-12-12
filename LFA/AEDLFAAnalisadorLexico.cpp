#include <bits/stdc++.h>
using namespace std;

string palavrasReservadas[] = {"int","float","string","char","bool","#include","using","if","else"};
string alfabeto = "abcdefghijlkmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string dig = "0123456789";
string operadores[] = {"+","-","*","/","%","==","!=","<",">","<=",">=","&&","||","!"};

vector<string> variaveis;
vector<string> auxVariaveis;

vector<pair<int,char> > adjList[210];
string textoAutomatos;
set<int> erroOuNao;

vector<string> linhasLog[1000];
bool vis[1000];



string concaaa = "";

//------------------------------------------------- BUSCA DOS AUTOMATOS ----------------------------------------------
void buscaAutomato(int s, int pos, set<int> &ss){
    if(textoAutomatos[pos] != ' ' and textoAutomatos[pos] != '=' and textoAutomatos[pos] != ';' and textoAutomatos[pos] != ',' and textoAutomatos[pos] != '\n') concaaa+= textoAutomatos[pos];
    if(textoAutomatos[pos] == '=' or textoAutomatos[pos] == ';' or textoAutomatos[pos] == ','){
        int count = 0;
        bool ok = true; 
        for(int i = 0; i<concaaa.size() and ok == true; i++){
            if(isdigit(concaaa[i]) == true or concaaa[i] == '.'){
                count++;
            }
            if(concaaa[i] == '"' or concaaa[i] == 39) ok = false;
        }
        if(count != concaaa.size() and ok == true){
            auxVariaveis.push_back(concaaa);
        }
        concaaa = "";
    }
    if(s == 100) ss.insert(1);
    for(auto x: adjList[s]){
        if(x.second == textoAutomatos[pos]){
            buscaAutomato(x.first, pos+1, ss);
        }
    }
    ss.insert(-1);
}


void buscaAutomatoCabecalho(int s,int pos, set<int> &ss){
    if(s == 100) ss.insert(1);
    for(auto x: adjList[s]){
        if(x.second == textoAutomatos[pos]){
            buscaAutomatoCabecalho(x.first, pos+1, ss);
        }
    }
    ss.insert(-1);
}
//   --------------------------------------------------- AUTOMATOS ------------------------------------------------

//   ------------------------------------------------- AUTOMATO INT ---------------------------------------------  OK!
void AutomatomatoINT(){
    // <1 vertice, permissao> 2 vertice
    adjList[1].push_back({1,' '});

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[1].push_back({2,alfabeto[i]});
    }

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[2].push_back({2,alfabeto[i]});
    }
    for(int i = 0; i<10; i++){
        adjList[2].push_back({2,dig[i]});
    }

    adjList[2].push_back({100,';'});

    adjList[2].push_back({3,' '});

    adjList[3].push_back({100,';'});

    adjList[3].push_back({1,','}); 

    adjList[3].push_back({3,' '});

    adjList[2].push_back({1,','}); 

    adjList[2].push_back({4,'='});

    adjList[3].push_back({4,'='});

    adjList[4].push_back({4,' '});

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[4].push_back({200,alfabeto[i]});
    }

    for(int i = 0; i<10; i++){
        adjList[4].push_back({5,dig[i]});
    }

    for(int i = 0; i<10; i++){
        adjList[5].push_back({5,dig[i]});
    }

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[5].push_back({200,alfabeto[i]});
    }

    adjList[5].push_back({6,' '});

    adjList[5].push_back({100,';'});

    adjList[5].push_back({1,','});

    adjList[6].push_back({100,';'});

    adjList[6].push_back({6,' '});

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[6].push_back({200,alfabeto[i]});
    }
    for(int i = 0; i<10; i++){
        adjList[6].push_back({200,dig[i]});
    }

    buscaAutomato(1,0,erroOuNao);
    for(int i = 0; i<210; i++){
        adjList[i].clear();
    }

}
    // --------------------------------------------- AUTOMATO FLOAT --------------------------------------------- OK!
    void AutomatoFloat(){
        adjList[1].push_back({1,' '});

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[1].push_back({2,alfabeto[i]});
    }

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[2].push_back({2,alfabeto[i]});
    }
    for(int i = 0; i<10; i++){
        adjList[2].push_back({2,dig[i]});
    }

    adjList[2].push_back({100,';'});

    adjList[2].push_back({3,' '});

    adjList[3].push_back({100,';'});

    adjList[3].push_back({1,','}); 

    adjList[3].push_back({3,' '});

    adjList[2].push_back({1,','}); 

    adjList[2].push_back({4,'='});

    adjList[3].push_back({4,'='});

    adjList[4].push_back({4,' '});

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[4].push_back({200,alfabeto[i]});
    }

    for(int i = 0; i<10; i++){
        adjList[4].push_back({5,dig[i]});
    }

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[5].push_back({200,alfabeto[i]});
    }

    adjList[5].push_back({6,' '});

    for(int i = 0; i<10; i++){
        adjList[5].push_back({5,dig[i]});
    }

    adjList[5].push_back({1,','});

    adjList[5].push_back({7,'.'});

    adjList[5].push_back({100,';'});

    adjList[6].push_back({6,' '});

    adjList[6].push_back({100,';'});

    for(int i = 0; i<10; i++){
        adjList[7].push_back({8,dig[i]});
    }

    for(int i = 0; i<10; i++){
        adjList[8].push_back({8,dig[i]});
    }
    
    adjList[8].push_back({1,','});

    adjList[8].push_back({9,' '});

    adjList[8].push_back({100,';'});

    adjList[9].push_back({9,' '});

    adjList[9].push_back({100,';'});

    adjList[9].push_back({1,','});

    buscaAutomato(1,0,erroOuNao);
    for(int i = 0; i<210; i++){
        adjList[i].clear();
    }

}
// -------------------------------------------------- AUTOMATO STRING ------------------------------------------  OK!
    void AutomatoString(){
    adjList[1].push_back({1,' '});

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[1].push_back({2,alfabeto[i]});
    }

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[2].push_back({2,alfabeto[i]});
    }
    for(int i = 0; i<10; i++){
        adjList[2].push_back({2,dig[i]});
    }

    adjList[2].push_back({100,';'});

    adjList[2].push_back({3,' '});

    adjList[3].push_back({100,';'});

    adjList[3].push_back({1,','}); 

    adjList[3].push_back({3,' '});

    adjList[2].push_back({1,','}); 

    adjList[2].push_back({4,'='});

    adjList[3].push_back({4,'='});

    adjList[4].push_back({4,' '});

    adjList[4].push_back({5,'"'});

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[5].push_back({5,alfabeto[i]});
    }
    for(int i = 0; i<10; i++){
        adjList[5].push_back({5,dig[i]});
    }
    adjList[5].push_back({5,' '});

    adjList[5].push_back({6,'"'});

    adjList[6].push_back({7,' '});

    adjList[6].push_back({1,','});

    adjList[7].push_back({1,','});

    adjList[7].push_back({7,' '});

    adjList[6].push_back({100,';'});

    adjList[7].push_back({100,';'});

    buscaAutomato(1,0,erroOuNao);
    for(int i = 0; i<210; i++){
        adjList[i].clear();
    }

}
// ---------------------------------------------------- AUTOMATO CHAR ----------------------------------------------- OK!
    void AutomatoChar(){
    adjList[1].push_back({1,' '});

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[1].push_back({2,alfabeto[i]});
    }

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[2].push_back({2,alfabeto[i]});
    }
    for(int i = 0; i<10; i++){
        adjList[2].push_back({2,dig[i]});
    }

    adjList[2].push_back({100,';'});

    adjList[2].push_back({3,' '});

    adjList[3].push_back({100,';'});

    adjList[3].push_back({1,','}); 

    adjList[3].push_back({3,' '});

    adjList[2].push_back({1,','}); 

    adjList[2].push_back({4,'='});

    adjList[3].push_back({4,'='});

    adjList[4].push_back({4,' '});

    adjList[4].push_back({5,39});

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[5].push_back({5,alfabeto[i]});
    }
    for(int i = 0; i<10; i++){
        adjList[5].push_back({5,dig[i]});
    }
    adjList[5].push_back({5,' '});

    adjList[5].push_back({6,39});

    adjList[6].push_back({7,' '});

    adjList[6].push_back({1,','});

    adjList[7].push_back({1,','});

    adjList[7].push_back({7,' '});

    adjList[6].push_back({100,';'});

    adjList[7].push_back({100,';'});

    buscaAutomato(1,0,erroOuNao);
    for(int i = 0; i<210; i++){
        adjList[i].clear();
    }
}
// ------------------------------------------------------- AUTOMATO BOOL ----------------------------------------- OK!
    void AutomatoBool(){

    adjList[1].push_back({1,' '});

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[1].push_back({2,alfabeto[i]});
    }

    for(int i = 0; i<alfabeto.size(); i++){
        adjList[2].push_back({2,alfabeto[i]});
    }
    for(int i = 0; i<10; i++){
        adjList[2].push_back({2,dig[i]});
    }

    adjList[2].push_back({100,';'});

    adjList[2].push_back({3,' '});

    adjList[3].push_back({100,';'});

    adjList[3].push_back({1,','}); 

    adjList[3].push_back({3,' '});

    adjList[2].push_back({1,','}); 

    adjList[2].push_back({4,'='});

    adjList[3].push_back({4,'='});

    adjList[4].push_back({4,' '});

    adjList[4].push_back({5,'1'});
    adjList[4].push_back({5,'0'});

    adjList[5].push_back({6,' '});

    adjList[5].push_back({1,','});

    adjList[5].push_back({100,';'});

    adjList[6].push_back({6,' '});

    adjList[6].push_back({100,';'});

    buscaAutomato(1,0,erroOuNao);
    for(int i = 0; i<210; i++){
        adjList[i].clear();
    }
}

// ----------------------------------------------- AUTOMATO INCLUDE -------------------------------------------- OK!
    void AutomatoInclude(){
        adjList[1].push_back({1,' '});

        adjList[1].push_back({2,'<'});

        adjList[2].push_back({3,'i'});

        adjList[3].push_back({4,'o'});

        adjList[4].push_back({5,'s'});

        adjList[5].push_back({6,'t'});

        adjList[6].push_back({7,'r'});

        adjList[7].push_back({8,'e'});

        adjList[8].push_back({9,'a'});

        adjList[9].push_back({10,'m'});

        adjList[10].push_back({100,'>'});

        

        buscaAutomatoCabecalho(1,0,erroOuNao);
        for(int i = 0; i<210; i++){
            adjList[i].clear();
        }
    }

//-------------------------------------------------- AUTOMATO USING ------------------------------------------- OK!
    void AutomatoUsing(){
        adjList[1].push_back({1,' '});

        adjList[1].push_back({2,'n'});

        adjList[2].push_back({3,'a'});

        adjList[3].push_back({4,'m'});

        adjList[4].push_back({5,'e'});

        adjList[5].push_back({6,'s'});

        adjList[6].push_back({7,'p'});

        adjList[7].push_back({8,'a'});

        adjList[8].push_back({9,'c'});

        adjList[9].push_back({10,'e'});

        adjList[10].push_back({11,' '});

        adjList[11].push_back({11,' '});

        adjList[11].push_back({12,'s'});

        adjList[12].push_back({13,'t'});

        adjList[13].push_back({14,'d'});

        adjList[14].push_back({15,' '});

        adjList[15].push_back({15,' '});

        adjList[14].push_back({100,';'});

        adjList[15].push_back({100,';'});

        buscaAutomatoCabecalho(1,0,erroOuNao);
        for(int i = 0; i<210; i++){
            adjList[i].clear();
        }
    }


// ------------------------------------------------ FUNC CHAMA AUTOMATO -------------------------------------------- OK!
    void ChamaAutomato(int valor){
    if(valor == 0){
        AutomatomatoINT();
    }
    if(valor == 1){
        AutomatoFloat();
    }
    if(valor == 2){
        AutomatoString();
    }
    if(valor == 3){
        AutomatoChar();
    }
    if(valor == 4){
        AutomatoBool();
    }
    if(valor == 5){
        AutomatoInclude();
    }
    if(valor == 6){
        AutomatoUsing();
    }
}
        
// ------------------------------------------------ CLASSE ANALISADOR GRAFICO -------------------------------------
class AnaLex{
    public:
        AnaLex(){};
        void fazArqLog(string texto){
            int linhaTexto = 1;
            string conca = "";
            //ESSE FOR E PRA FAZER O LOG DE TODAS AS DECLARACOES DE VARIAVEL
            for(int i = 0; i<texto.size(); i++){
                if(texto[i] == '\n') linhaTexto++;
                if(texto[i] == ' ' or texto[i] == '\n'){
                    //cout << conca <<  endl;
                    //cout << conca.size() << endl;
                    for(int j = 0; j<9; j++){
                        if(conca == palavrasReservadas[j]){
                            string linha = "";
                            for(int j = i; texto[j] != '\n'; j++){
                                linha += texto[j];
                            }
                            //cout << linha << endl;
                            textoAutomatos = linha;
                            concaaa = "";
                            ChamaAutomato(j);
                            if(erroOuNao.size() == 2){
                                //cout << "deu bom" << endl;
                                linhasLog[linhaTexto].push_back("LINHA " + to_string(linhaTexto) + ": ");
                                linhasLog[linhaTexto].push_back("CORRETO!");
                                vis[linhaTexto] = true;
                                for(int k = 0; k<auxVariaveis.size(); k++){
                                    variaveis.push_back(auxVariaveis[k]);
                                }
                            }
                            else{
                                //cout << "deu ruim" << endl;
                                linhasLog[linhaTexto].push_back("LINHA " + to_string(linhaTexto) + ": ");
                                linhasLog[linhaTexto].push_back("ERRO!");
                                vis[linhaTexto] = true;
                            }
                            auxVariaveis.clear();
                            erroOuNao.clear();
                        }
                    }
                    conca = "";
                }
                if(texto[i] != ' ' and texto[i] != '\t' and texto[i] != '\n'){
                    conca += texto[i];
                } 
                
            }
            // FAZER LOG PARA O RESTANTE
            conca = "";
            for(int i = 0; i<texto.size(); i++){
                if(texto[i] == ' ' or texto[i] == '\n'){
                    
                }
                if(texto[i] != ' ' and texto[i] != '\t' and texto[i] != '\n'){
                    conca += texto[i];
                } 
            }

        };

        void imprimeArqLog(){
            string texto = "";
            int numLinhas = ContaNumeroDeLinhas();
            for(int i = 0; i<numLinhas; i++){
                for(int j = 0; j<linhasLog[i].size(); j++){
                    texto+= linhasLog[i][j];
                }
                texto+= '\n';
            }
            ofstream arquivo2;
            string nomeDoArquivo2 = "C:/Users/mateu/Desktop/arqLog.txt";
            arquivo2.open(nomeDoArquivo2.c_str(),std::ios::out|std::ios::app);
            arquivo2 << texto << endl;
            arquivo2.close();
        };
        string lerArquivoDeEntrada(){ // ok!
            ifstream arquivo;
            string nomeDoArquivo = "C:/Users/mateu/Desktop/arqEntrada.txt";
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
            return texto;
        };
        void fazBackup(string texto){ //ok!
            ofstream arquivo2;
            string nomeDoArquivo2 = "C:/Users/mateu/Desktop/arqBackup.txt";
            arquivo2.open(nomeDoArquivo2.c_str(),std::ios::out|std::ios::app);
            arquivo2 << texto << endl;
            arquivo2.close();
        };
        void ImprimeTokensArquivo(string texto){ // ok!
            ofstream arquivo2;
            string nomeDoArquivo2 = "C:/Users/mateu/Desktop/arqTokens.txt";
            arquivo2.open(nomeDoArquivo2.c_str(),std::ios::out|std::ios::app);
            arquivo2 << texto << endl;
            arquivo2.close();
        };
        void fazTextoTokens(string texto){ // ok!
            int countLinha = 1;
            string textoTokens = "TOKENS SEM ATRIBUTOS: \n";
            vector<string>tokensPorLinha; 
            //for que passa por cada caracter do código
            // verificar os tokens regulares sem atributos:
            for(int i = 0; i<(int)texto.size(); i++){
                if(texto[i] == '\n'){
                    textoTokens += "LINHA " + to_string(countLinha) + ": ";
                    for(int j = 0; j<tokensPorLinha.size(); j++){
                        if(j == tokensPorLinha.size() - 1){
                            textoTokens += "[" + tokensPorLinha[j] + "]" + '\n';
                        }
                        else{
                            textoTokens += "[" + tokensPorLinha[j] + "]" + ", ";
                        }
                    }
                    if(tokensPorLinha.size() == 0) textoTokens += '\n';
                    countLinha++;
                    tokensPorLinha.clear();
                }
                if(texto[i] == '+'){
                    tokensPorLinha.push_back("ADD");
                }
                if(texto[i] == '-'){
                    tokensPorLinha.push_back("SUB");
                }
                if(texto[i] == '*'){
                    if(texto[i+1] == '/'){
                        tokensPorLinha.push_back("CMF");
                        i++;
                    }
                    else{
                        tokensPorLinha.push_back("MUL");
                    } 
                }
                if(texto[i] == '/'){
                    bool ok = true;
                    if(texto[i+1] == '/'){
                        tokensPorLinha.push_back("CM");
                        i++;
                        ok = false;
                    }
                    if(texto[i+1] == '*'){
                        tokensPorLinha.push_back("CMA");
                        i++;
                        ok = false;
                    }
                    if(ok == true){
                        tokensPorLinha.push_back("DIV");
                    }
                }
                if(texto[i] == '%'){
                    tokensPorLinha.push_back("RES");
                }
                if(texto[i] == '='){
                    if(texto[i+1] == '='){
                        tokensPorLinha.push_back("IGU");
                        i++;
                    }
                    else{
                        tokensPorLinha.push_back("IG");
                    }
                }
                if(texto[i] == '!'){
                    if(texto[i+1] == '='){
                        tokensPorLinha.push_back("DIF");
                        i++;
                    }
                    else{
                        tokensPorLinha.push_back("NOT");
                    }
                }
                if(texto[i] == '<'){
                    if(texto[i+1] == '='){
                        tokensPorLinha.push_back("MEI");
                        i++;
                    }
                    else{
                        tokensPorLinha.push_back("ME");
                    }
                }
                if(texto[i] == '>'){
                    if(texto[i+1] == '='){
                        tokensPorLinha.push_back("MAI");
                        i++;
                    }
                    else{
                        tokensPorLinha.push_back("MA");
                    }
                }
                if(texto[i] == '&'){
                    if(texto[i+1] == '&'){
                        tokensPorLinha.push_back("AND");
                        i++;
                    }
                }
                if(texto[i] == '|'){
                    if(texto[i+1] == '|'){
                        tokensPorLinha.push_back("OR");
                        i++;
                    }
                }
                if(texto[i] == '{'){
                    tokensPorLinha.push_back("CA");
                }
                if(texto[i] == '}'){
                    tokensPorLinha.push_back("CF");
                }
                if(texto[i] == '('){
                    tokensPorLinha.push_back("PA");
                }
                if(texto[i] == ')'){
                    tokensPorLinha.push_back("PF");
                }
                if(texto[i] == ';'){
                    tokensPorLinha.push_back("PV");
                }
                if(texto[i] == '#'){
                    tokensPorLinha.push_back("CE");
                }
                if(texto[i] == '.'){
                    tokensPorLinha.push_back("PT");
                }
                if(texto[i] == ' '){
                    tokensPorLinha.push_back("EB");
                }
                if(texto[i] == '"'){
                    tokensPorLinha.push_back("AD");
                }
                if(texto[i] == 39){
                    tokensPorLinha.push_back("AS");
                }
            }
            // verificar tokens com atributos:
            textoTokens += '\n';
            textoTokens += "TOKENS COM ATRIBUTOS: \n";
            textoTokens+= '\n';
            tokensPorLinha.clear();
            countLinha = 1;
            string conca2 = "";
            for(int i = 0; i<(int)texto.size(); i++){
                if(texto[i] != ' ' and texto[i] != '\n' and texto[i] != '\t' and texto[i] != ';'){
                    conca2 += texto[i];
                }
                for(int j = 0; j<10; j++){
                    if(texto[i] == dig[j]){
                        tokensPorLinha.push_back("DIG");
                    }
                }
                if(texto[i] == ' ' or texto[i] == '\n'){
                    //cout << conca2 << endl;
                    //cout << conca2.size() << endl;
                    for(int j = 0; j<variaveis.size(); j++){
                        if(conca2 == variaveis[j]){
                            tokensPorLinha.push_back("VAR");
                        }
                    }
                    for(int j = 0; j<14; j++){
                        if(conca2 == operadores[j]){
                            tokensPorLinha.push_back("OP");
                        }
                    }
                    conca2 = "";
                }
                if(texto[i] == '\n'){
                    textoTokens += "LINHA " + to_string(countLinha) + ": ";
                    for(int j = 0; j<tokensPorLinha.size(); j++){
                        if(j == tokensPorLinha.size() - 1){
                            textoTokens += "[" + tokensPorLinha[j] + "]" + '\n';
                        }
                        else{
                            textoTokens += "[" + tokensPorLinha[j] + "]" + ", ";
                        }
                    }
                    if(tokensPorLinha.size() == 0) textoTokens += '\n';
                    countLinha++;
                    tokensPorLinha.clear();
                }
            }
            ImprimeTokensArquivo(textoTokens);
        };

        int ContaNumeroDeLinhas(){
            ifstream arquivo;
            string nomeDoArquivo = "C:/Users/mateu/Desktop/arqEntrada.txt";
            arquivo.open(nomeDoArquivo.c_str(),std::ios::out|std::ios::app);
            string linha;
            int count = 1;
            getline(arquivo,linha);
            while(!arquivo.eof()){
                count++;
                getline(arquivo,linha);
            }
            arquivo.close();
            return count;
        };
};

int main(){
    AnaLex obj;
    string texto = obj.lerArquivoDeEntrada();
    obj.fazBackup(texto);
    obj.fazArqLog(texto);
    obj.fazTextoTokens(texto);
    obj.imprimeArqLog();
}
