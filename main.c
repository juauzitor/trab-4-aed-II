#include <stdio.h>
#include <stdlib.h>
#include "ArvTrie2.h"

int main (int argc, char *argv[]){
    tp_no * raiz = cria_no('a');
    insere_no_trie(raiz, "abacate");
    insere_no_trie(raiz, "abacaxi");
    printf("%i\n",tem_filho(raiz));
    busca_no_trie(raiz, "a");
    return 0;
}
