#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct Pilha{
    char *item;
    int topo;
    int maxN;

}Pilha;


Pilha *criarPilha(int maxN){
    Pilha *p = malloc(sizeof(Pilha));
p->maxN = maxN;
p->topo = -1;
p->item = malloc(maxN * sizeof(char));
return p;
}

void empilhar(Pilha *p, char n){
    p->item[++p->topo] = n;
}

char desempilhar(Pilha *p){
    return p->item[p->topo--];
}

int pilhaVazia(Pilha *p){
    return p->topo == -1;
}

int main(){
    int i;
    
    scanf("%d", &i);
    char *palavra = malloc(sizeof(char) * (i + 1)); // Aloca memória para a string incluindo o terminador nulo
    if (palavra == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        return 1;
    }
    scanf("%s", palavra);

    Pilha *pilha  = criarPilha(i);
    for(int a =0; a < i; a ++){
        empilhar(pilha, palavra[a]);
    }
    
    char *aux = malloc(sizeof(char) * (i +1));
    if (aux == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        free(palavra);
        return 1;
    }
    
    for (int a = 0; a < i; a++) {
        aux[a] = desempilhar(pilha); 
    }
    aux[i] = '\0';
    if (strcmp(aux, palavra) == 0) { // Usa strcmp para comparar as strings
        printf("1\n"); // É um palíndromo
    }
   
    else
    printf("0\n");

    free(palavra);
    free(aux);
    
}