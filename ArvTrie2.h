#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define LETRAS 26

 

typedef struct tp_no {
    char letra;
    struct tp_no* filhos[LETRAS];
    int eh_folha;
} tp_no;
 
tp_no* cria_no(char letra) {
    tp_no* no = (tp_no*) malloc (sizeof(tp_no));
    int i;
    if (no != NULL) {
    	no->eh_folha = 0;
    	no->letra = letra;
	    for (i=0; i<LETRAS; i++)
    	    no->filhos[i] = NULL;
	}
    return no;
}

tp_no* insere_no_trie(tp_no* raiz, char* palavra) {
    tp_no* no = raiz;
 	int tam = strlen(palavra);
    int i;
    for (i=0; i < tam; i++) {
    	//palavras est�o em min�sculo
        int ind = (int) palavra[i] - 'a';
        if (no->filhos[ind] == NULL) {
            no->filhos[ind] = cria_no(palavra[i]);
        }
        no = no->filhos[ind];
    }
    no->eh_folha = 1;
    return raiz;
}
 
int busca_no_trie(tp_no* raiz, char* palavra)
{
    tp_no* no = raiz;
 	int tam = strlen(palavra); 
 	int i;
    for(i=0; i < tam; i++)
    {
        int pos = palavra[i] - 'a';
        if (no->filhos[pos] == NULL)
            return 0;
        no = no->filhos[pos];
    }
    if (no != NULL && no->eh_folha == 1)
        return 1;
    return 0;
}

int tem_filho(tp_no* raiz)
{
	int i;
	for (i = 0; i < LETRAS; i++)
		if (raiz->filhos[i])
			return 1;	
	return 0;
}

int remove_no_trie(tp_no **raiz, char* palavra)
{
	if (*raiz == NULL)
		return 0;

	// Enquanto n�o alcan�ar o final da palavra
	if (*palavra)
	{
		if (*raiz != NULL && (*raiz)->filhos[*palavra - 'a'] != NULL &&
			remove_no_trie(&((*raiz)->filhos[*palavra - 'a']), palavra + 1) &&
			(*raiz)->eh_folha == 0)
		{
			if (!tem_filho(*raiz))
			{
				free(*raiz);
				(*raiz) = NULL;
				return 1;
			}
			else {
				(*raiz)->filhos[*palavra - 'a'] = NULL;
				return 0;
			}
		}
	}

	// Se chegou no final da palavra a ser removida
	if (*palavra == '\0' && (*raiz)->eh_folha)
	{
		// Se o n� � folha e n�o tem filhos
		if (!tem_filho(*raiz))
		{
			free(*raiz); 
			(*raiz) = NULL;
			return 1; // remove os n�s ancestrais n�o-folha
		}

		// se o n� corrente � um n� folha e tem filhos
		else
		{
			// Marca o n� corrente como n� n�o folha
			(*raiz)->eh_folha = 0;
			return 0;	   // N�o exclui os pais
		}
	}

	return 0;
}

// Print words in trie tree
int print_word_in_trie(tp_no* raiz, char* palavra)
{
    tp_no * no = raiz;
    for (int i = 0; i < LETRAS; i++) {
        if (no->filhos[i] == NULL)
            return 0;
        printf("%c", no->letra);
        no = no->filhos[i];
    }
}
