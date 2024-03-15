#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/shm.h>





typedef struct tree{
	int num;
	struct tree* sad;
	struct tree* sae;
}Tree;

Tree* createTree(){
  return NULL;
}

int treeIsEmpty(Tree* t){
  return t == NULL;

}

void insertTree(Tree** t, int num){

  if(*t == NULL)
  {
    *t = (Tree*)malloc(sizeof(Tree)); 
    (*t)->sae = NULL;
    (*t)->sad = NULL; 
    (*t)->num = num; 
  } else {
    if(num < (*t)->num) 
    
      insertTree(&(*t)->sae, num);
    }
    if(num > (*t)->num)
    {
      insertTree(&(*t)->sad, num);
    }
 }
 
 
int isInTree(Tree* t, int num) {
  
  if(treeIsEmpty(t)) { 
    return 0;
  }
  
  return t->num==num || isInTree(t->sae, num) || isInTree(t->sad, num);
}


struct Meio{
	 Tree* t;
	 int pilha[1000];
 };

int isPrime(int number) { 
    int i; 
    for (i = 2; i <= number / 2; i++)  { 
        if (number % i != 0) 
            continue; 
        else
            return 1; 
    } 
    return 0; 
} 

int main(){
	
	int memoryID = shmget(IPC_PRIVATE, sizeof(struct Meio), IPC_CREAT | 0666);
	struct Meio *meio = (struct Meio*)shmat(memoryID, NULL, 0);
	meio->t = createTree();
	//gerar numeros aleatorios;
	int pos = 0;
	for(int i = 0; i< 1000; i++){
		int num = rand() % 110 + 2;
		if(!isPrime(num)){
			meio->pilha[pos] = num;
			pos++;
		}
		
	}
	
	//~ for(int i = 0; i<pos; i++){
		//~ printf("%d", meio->pilha[i]);
		//~ printf(" ");
	//~ }
	//imprimir pilha
	
	
	//~ int num_processes = rand() % 16 + 2;	
	//~ teste->in_use = 0;
	//~ teste->contador = 1;
	

}
