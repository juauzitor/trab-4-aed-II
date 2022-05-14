#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvTrie2.h"

void gerarstring(tp_no* raiz, char* palavraent){ // Função para recursivamente ir montando a string da palavra registrada
    tp_no* no = raiz;
    if (no != NULL && no->eh_folha == 1){
        printf("%s ", palavraent);
        for(int i = 0; i < LETRAS; i++){ // For para checar se não existe mais nenhum nó folha depois de outro nó folha
            if(no->filhos[i] != 0){
                char copiaent[strlen(palavraent)]; // Stirng auxiliar para evitar mexer diretamente no vetor da substring
                strcpy(copiaent, palavraent);
                char straux[2] = {no->filhos[i]->letra, '\0'};
                strcat(copiaent, straux);
                gerarstring(no->filhos[i], copiaent);
            }
        }
        return;
    }
    for (int i = 0; i < LETRAS; i++){ // For para pecorrer o vetor de filhos buscando não nulos
        if (no->filhos[i] != NULL){
            char copiaent[strlen(palavraent)]; // Stirng auxiliar para evitar mexer diretamente no vetor da substring
            strcpy(copiaent, palavraent);
            char straux[2] = {no->filhos[i]->letra, '\0'};
            strcat(copiaent, straux);
//            printf("%s\n", copiaent);
            gerarstring(no->filhos[i], copiaent);
        }
    }
}

int imprimirs_no_trie(tp_no* raiz, char* substring){
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
        printf("Digite suas palavras SOUSSA!\nCaso queria sair digite FIM todo em maiúsculo\n");
        scanf(" %s", palavraentrada);
    if(strcmp(palavraentrada,"FIM")!=0)
        insere_no_trie(raiz, palavraentrada); //insera a novas palavras na árvore até que seja digitado 'FIM'
    }
    char substring[101];
    while(strcmp(substring,"FIM")!=0){
        printf("caso queria sair digite FIM todo em maiúsculo\n");
        printf("Digite a substring para que seja feito autcomplit!: ");
        scanf(" %s", substring);
        if(strcmp(substring,"FIM")!=0){
            printf("Palavras com %s [ ", substring);
            imprimirs_no_trie(raiz,substring);
            printf("]\n\n");
        }
    }
    return 0;
}
