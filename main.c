#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvTrie2.h"

void gerarstring(tp_no* raiz, char* palavraent){
    tp_no* no = raiz;
    if (no != NULL && no->eh_folha == 1){
        printf("%s\n", palavraent);
        return;
    }
    
    for (int i = 0; i < LETRAS; i++)
    {
        if (no->filhos[i] != NULL){
            char copiaent[strlen(palavraent)+1];
            for (int i = 0; i < strlen(palavraent); i++)
            {
                copiaent[i] = palavraent[i];             
            }
            //char straux[2] = {no->filhos[i]->letra, '\0'};
            //strcat(copiaent, straux);
            copiaent[strlen(palavraent)] = no->filhos[i]->letra;
            copiaent[strlen(palavraent)+1] = '\0';
            //printf("%s\n", palavraent);
//            printf("%s\n", copiaent);
            //gerarstring(no->filhos[i], palavraent);
            gerarstring(no->filhos[i], copiaent);
        }
    }
}

int imprimirs_no_trie(tp_no* raiz, char* substring)
{
    tp_no* no = raiz;
 	int tam = strlen(substring); 
 	int i;
    
    for(i=0; i < tam; i++)
    {
        int pos = substring[i] - 'a';
        if (no->filhos[pos] == NULL) // se a palavra nao existe na arvore retorne falso
            return 0;
        no = no->filhos[pos];   // se existe no recebe a 
    }
    gerarstring(no, substring);
    return 0;
}

int main (int argc, char *argv[]){
    tp_no * raiz = cria_no(' ');
    char palavraentrada[101];
    while(strcmp(palavraentrada,"FIM")!=0){
        printf("Digite suas palavras SOUSSA!\n");
        scanf("%s", palavraentrada); 
        insere_no_trie(raiz, palavraentrada); //insera a novas palavras na árvore até que seja digitado 'FIM'
    }
    char substring[101];
    while(1){
        printf("Digite a substring para que seja feito autcomplit!: ");
        scanf("%s", substring);
        imprimirs_no_trie(raiz,substring);
        break;
    }
    
    //print_word_in_trie(raiz, "sla");
    return 0;
}
