#include <iostream>

using namespace std;

#define maxn 10000

struct Tree{
    int vetPai[maxn];
    int vetFilho[maxn][2];
    int vetDados[maxn];
    int tamanho;
    int indice;
    int root;
	
	Tree(){
		for(int i=0;i<5;i++){
			vetFilho[i][0] = vetFilho[i][1] = vetDados[i] = -1;
		}
		tamanho = indice = 0;
		root = -1;
	}
	void printTree(int pos){
		if(pos == -1) return;
		cout << vetDados[pos] << " ";
		if(vetFilho[pos][0] != -1) printTree(vetFilho[pos][0]);		
		if(vetFilho[pos][1] != -1) printTree(vetFilho[pos][1]);
	}
	
	void printTree(){
		cout << "Preorder : ";
		printTree(root);
		cout << "\n";
	}
	
    int searchTree(int valor, int pos){
		if(pos == -1) return 0;
		if(valor == vetDados[pos]) return 1;
		if(vetDados[pos] > valor ) return searchTree(valor,vetFilho[pos][0]);
		return searchTree(valor,vetFilho[pos][1]);
    }
    
    int searchTree(int valor){
		return searchTree(valor, root);
	}

    void insertTree(int valor, int filho, int pai){
        if(filho == -1){
			if(pai!=-1)vetFilho[pai][valor>vetDados[pai]] = indice;
			vetDados[indice] = valor;
            indice++;
            tamanho++;
        }
        else{
            if(vetDados[filho] > valor) insertTree(valor, vetFilho[filho][0], filho);
            else insertTree(valor, vetFilho[filho][1],filho);
        }
    }
    void insertTree(int valor){
		if(searchTree(valor)){
			cout << "Esse elemento ja existe na arvore: " << valor << "\n";
		}
		else{
			if(tamanho<maxn){
				insertTree(valor, root, -1);
				if(root == -1) root = indice-1;
			}
			else cout << "Ta Cheia a Arvore\n";
		}
	}
	
	void print(){
		for(int i=0;i<tamanho;i++){
			cout << "Valor na posicao [" << i << "] = "<< vetDados[i] << "\n";
			cout << "Filho a esquerda :" << vetFilho[i][0] << "\n";
			cout << "Filho a direita  :" << vetFilho[i][1] << "\n\n";
		}
	}
};



int main(){
    Tree t;
    t.insertTree(5);
    t.insertTree(4);
    t.insertTree(3);
    t.insertTree(6);
    t.printTree();
    cout << t.searchTree(5) <<" " << t.searchTree(7) << endl;
    


}
