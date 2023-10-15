#include<bits/stdc++.h>
using namespace std;


vector<int> vetor;
clock_t t1, t2, t3, t4;


void imprimeVetores(int N){
	cout << endl;
	for(int i = 0; i<N; i++){
		if(i != N-1) cout << vetor[i] << ", ";
		else cout << vetor[i] << "]" << endl;
	}
	cout << endl;
}
void preparaVetor(vector<int> &v, int N){
	v.clear();
	for(int i = 0; i<N; i++){
		v.push_back(rand() %1000 + 1);
	}
}


void selectionSort(vector<int> &v, int N){
	int menor;
	for(int i = 0; i<N-1; i++){
		menor = i;
		for(int j = i+1; j<N; j++){ 
			if(v[menor] > v[j]){ 
				menor = j;
			}
		}
		swap(v[menor], v[i]);
	}
}


void Merge(vector<int> &v,int pi, int M, int pf){
	int aux[pf];
	int k = 0;
	int i = pi; // isso tem que fazer pq pi nem pf nem M podem ser alterados (como voce não passa o tamanho do vetor, ele se baseia por essas variaveis)
	int j = M+1;
	while(i <= M and j <= pf){ // enquanto a fracao do vetor não estiver "vazia" ele continua
		if(v[i] > v[j]){ // se colocar >= fica estável
			aux[k] = v[j]; // coloca o valor na posição correta
			j++;
		}
		else{
			aux[k] = v[i];
			i++;
		}
		k++;
		
	}
	for(; i<=M; i++){  // se o vetor "j" que acabou, enfia o resto do vetor que sobrou la
		aux[k] = v[i];
		k++;
	}
	for(; j<=pf; j++){ // se o vetor "i" que acabou, enfia o resto do vetor que sobrou la
		aux[k] = v[j];
		k++;
	}
	for(i = 0; i<k; i++){ // deve ser feito assim, o k é a variavel que possui o tamanho da fracao do vetor;
		v[pi+i] = aux[i];   // se o pi = 5, ele comeca na posicao correta; pi+0, pi+1, pi+2 ... 
	}
}

void mergeSort(vector<int> &v, int pi, int pf){
	if(pi<pf){
		int M = (pi+pf)/2;
		mergeSort(v,pi,M); // divide tudo para direita
		mergeSort(v,M+1,pf); // divide tudo para esquerda
		Merge(v,pi,M,pf); // merga tudo
	}
}


void fazSelection(){
	preparaVetor(vetor, 10);
	cout << "Vetor Desordenado 10: " << endl;
	imprimeVetores(10);
	t1 = clock();
	selectionSort(vetor,10);
	cout << "Vetor Ordenado 10: " << endl;
	imprimeVetores(10);
	t1 = clock() - t1;
	preparaVetor(vetor, 100);
	cout << "Vetor Desordenado 100: " << endl;
	imprimeVetores(100);
	t2 = clock();
	selectionSort(vetor,100);
	cout << "Vetor Ordenado 100: " << endl;
	imprimeVetores(100);
	t2 = clock() - t2;
	preparaVetor(vetor,100000);
	t3 = clock();
	selectionSort(vetor,100000);
	t3 = clock() - t3;
	cout << endl;
	cout << "Vetor Randomico com 10 valores: ";
	cout << (float)t1/CLOCKS_PER_SEC << " segundos" <<endl;
	cout << "Vetor Randomico com 100 valores: ";
	cout << (float)t2/CLOCKS_PER_SEC << " segundos" <<endl;
	cout << "Vetor Randomico com 100000 valores: ";
	cout << (float)t3/CLOCKS_PER_SEC << " segundos" <<endl;
}


void fazMerge(){
	preparaVetor(vetor, 10);
	cout << "Vetor Desordenado 10: " << endl;
	imprimeVetores(10);
	t1 = clock();
	mergeSort(vetor,0,9);
	cout << "Vetor Ordenado 10: " << endl;
	imprimeVetores(10);
	t1 = clock() - t1;
	preparaVetor(vetor, 100);
	cout << "Vetor Desordenado 100: " << endl;
	imprimeVetores(100);
	t2 = clock();
	mergeSort(vetor,0,99);
	cout << "Vetor Ordenado 100: " << endl;
	imprimeVetores(100);
	t2 = clock() - t2;
	preparaVetor(vetor,100000);
	t3 = clock();
	mergeSort(vetor,0,99999);
	t3 = clock() - t3;
	cout << endl;
	cout << "Vetor Randomico com 10 valores: ";
	cout << (float)t1/CLOCKS_PER_SEC << " segundos" <<endl;
	cout << "Vetor Randomico com 1000 valores: ";
	cout << (float)t2/CLOCKS_PER_SEC << " segundos" <<endl;
	cout << "Vetor Randomico com 100000 valores: ";
	cout << (float)t3/CLOCKS_PER_SEC << " segundos" <<endl;
}




int main(){
	cout << "Selection Sort: " << endl;
	fazSelection();
	cout << endl;
	cout << "Merge Sort: " << endl;
	fazMerge();
	


}
