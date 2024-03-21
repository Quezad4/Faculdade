#include <iostream>

using namespace std;


struct Tree{
    int vetPai[100000];
    int vetFilho[100000][2];
    int vetDados[100000];
    int tamanho;
    int indice;



    int searchTree(int valor){
       
    }

    void insertTree(int valor, int filho){
        if(tamanho == 0){
             vetDados[indice] = valor;
             indice++;
             tamanho++;
        }
        if(filho != -1){
            if(vetDados[filho] < valor){
                 insertTree(valor, vetFilho[filho][0]);
                 
            }
            else{
                insertTree(valor, vetFilho[filho][1]);
                vetFilho[filho][1] = tal coisa
            }
        }
        vetDados[indice] = valor;
        

    }
};



int main(){
    Tree t;
    t.tamanho = 0;
    cout << t.tamanho << endl;


}
