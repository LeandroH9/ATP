/*======================================================

 LEANDRO HENRIQUE LIMA E SILVA E MILLENA GOMES DA COSTA
 TRABALHO SOBRE OPERAÇÕES DE CONJUNTOS - ARRAY/ARRANJOS

=======================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX 100
#define PULA  "\n\n\n"
#define PERTENCE "  Verifique se um elemento arbitrario pertence ao conjunto:"


void Dimensao_Array(int *ptr1);
void associaRandomicamente(int *ptr, int dim);
void associaUsuario(int *ptr, int dim);
void Trocar(int *ptr);
void ordenarConjuntos(int *ptr, int dim);
void Imprimindo_Valores_Array(int *ptr, int dim);
short menuOperacao(void);
void interseccaoConjunto (int *ptrA, int *ptrB, int *ptrAB, int dimA, int dimB, int *dimAB);
void UniaoDosConjuntos(int *ptrA, int *ptrB, int *ptrAUB, int dimA, int dimB, int *nU);
void diferencaConjunto (int *ptrAIB, int *ptrADB, int *ptrA, int dimA, int *dimADB, int dimAIB);
short buscaElemento (int *ptrAB, int elem, int dimAB);
int verificarRepeticao (int *ptr, int *ptrR, int *dimR, int dim);
void eliminarRepetidos(int *ptrR,int *ptrAB, int *dimAIB, int dim);
short menuAssociar (void);
short menuConjuntoAB(void);
short menuConjuntos (void);

//================================ MENU INICIAL COM TODAS AS OPERACOES =========================================
short menuOperacao(void){
int op = 0;
    do{
        system("CLS");
        printf("\n      ------------ ESCOLHA UMA DAS OPERACOES ------------- \n\n");

        printf("  [1] - Gerar os conjuntos A E B \n");
        printf("  [2] - Gerar Interseccao entre A e B\n");
        printf("  [3] - Gerar Uniao entre A e B\n");
        printf("  [4] - Gerar Diferenca A menos B (A - B)\n");
        printf("  [5] - Gerar Diferenca B menos A (B - A)\n");
        printf("  [6] - Vizualizar conjunto A\n");
        printf("  [7] - Vizualizar conjunto B\n");
        printf("  [8] - Verificar se um elemento arbitrario pertence ao conjunto\n");
        printf("  [9] - Verificar se ha elementos repetidos\n");
        printf(" [10] - Determinar a quantidade de elemento do conjunto\n");
        printf(" [11] - SAIR DA APLICACAO");
        printf("\n\n  Escolha a opcao desejada : ");
        scanf("%d", &op);
    }while(op < 1 || op > 11);
    return(op);
}
// ==============================MENU PARA ASSOCIAR VALORES A ARRAY==========================================
short menuAssociar(void) {
int op = 0;

 do {
    system("CLS");		// limpeza da tela
    printf("\n      ------------ DEFINA A FORMA DE COMO SERA ASSOCIADO OS VALORES AOS CONJUNTOS -------------  \n \n");
    printf("  [1] - Gerar os elementos do conjunto AUTOMATICAMENTE \n");
    printf("  [2] - Elementos introduzidos pelo USUARIO \n");
    printf("  [3] - VOLTAR \n");
    printf("\n\n Escolha a opcao desejada : ");
    scanf("%d", &op);

  } while (op < 1 || op > 3 );
  return(op);
}
// ============================= MENU COM TODAS AS OPCOES DE CONJUNTOS =================================
short menuConjuntos (void) {
int op = 0;
    do{
        system("CLS");
        printf("\n      ---------- ESCOLHA UMA DOS CONJUNTOS ------------- \n\n");

        printf("  [1] - Interseccao entre A e B\n");
        printf("  [2] - Uniao entre A e B\n");
        printf("  [3] - Diferenca A menos B (A - B)\n");
        printf("  [4] - Diferenca B menos A (B - A)\n");
        printf("  [5] - Conjunto A\n");
        printf("  [6] - Conjunto B\n");
        printf("  [7] - VOLTAR\n");
        printf("\n\n  Escolha a opcao desejada : ");
        scanf("%d", &op);
    }while(op < 1 || op > 7);
    return(op);
}
//=====================================
short menuConjuntoAB(void){
int op = 0;
    do {
    system("CLS");		// limpeza da tela
    printf("\n      ------------ DEFINA UM CONJUNTO -------------  \n \n");
    printf("  [1] - CONJUNTO A \n");
    printf("  [2] - CONJUNTO B\n");
    printf("  [3] - VOLTAR");
    printf("\n\n Escolha a opcao desejada : ");
    scanf("%d", &op);
    } while (op < 1 || op > 3 );
    return(op);
}
//==========================CALCULAR A QUANTIDADE DE ELEMENTO DE CADA CONJUNTO==========================================
void Dimensao_Array (int *ptr1) {
    int dim1, continua;
    do {
        continua = 0;
        printf("   Insira a quantidade de elementos do conjunto:  ");
        scanf("%d", &dim1);
        if (dim1 < 0 || dim1 > MAX ){
            continua = 1;
            printf("\n  Aviso: A quantidade de elementos devem estar no intervalo entre 0 e 100 \n\n");
        }
    } while (continua);
    *ptr1 = dim1;
    return;
}
//================================ OS VALORES SÃO ASSOCIADOS RANDOMICAMICAMENTE =========================================
void associaRandomicamente(int *ptr, int dim) {
    int i = 0;   // indice para percorrer o array
    time_t t;
    srand((unsigned) time(&t));
    for ( ; i < dim; i++) *(ptr+i) = rand();
    return;
}
//================================ USUARIO ASSOCIA VALORES AO CONJUNTO =========================================
void associaUsuario(int *ptr, int dim) {
    int i, n;
    printf("\n   Insira os elementos: \n\n");
    for (i=0; i<dim; i++) {
            printf(" [%d] = ", i);
            scanf("%d", &n);
            *(ptr+i) = n;
    }
    return;
}
//=============================== TROCAR OS ELEMENTOS DOS CONJUNTOS A e B PARA QUE HAJA ORDENAÇÃO ================================
void Trocar(int *ptr){
int maior;
    maior = *ptr;
    *ptr = *(ptr+1);
    *(ptr+1) = maior;
    return;
}
//================================ ORDENACAO DOS CONJUNTOS =========================================
void ordenarConjuntos(int *ptr, int dim){
int i = 1, j, continua = 1, lim;
    while((i<dim) && continua){
        continua = 0;
        lim = dim - i;
        for(j=0; j < lim; j++){
            if(*(ptr + j) > *(ptr + j + 1)){
                Trocar(ptr+j);
                continua = 1;
            }
        }
        i++;
    }
    return;
}
//================================ IMPRIMI OS VALORES DOS CONJUNTOS A e B =========================================
void Imprimindo_Valores_Array(int *ptr, int dim) {
int i = 0;   // indice para percorrer o array
    for (; i < dim; i++) printf("\n [%d] = %d ",i,*(ptr+i));
    return;
}
//================================ INTERSECCAO ENTRE OS CONJUNTOS =======================================
void interseccaoConjunto (int *ptrA, int *ptrB, int *ptrAB, int dimA, int dimB, int *dimAB) {
int i, j, k = 0;
    for (i = 0; i < dimA; i++){
        for(j = 0; j < dimB; j++) {
            if (*(ptrA + i) == *(ptrB + j)) {
                *(ptrAB + k) = *(ptrA + i);
                k++;
                break;
            }
        }
    }
    *dimAB = k;
    return;
}
//================================ UNIAO DOS CONJUNTOS =========================================
void UniaoDosConjuntos(int *ptrAUB, int *ptrA, int *ptrB, int dimA, int dimB, int *nU){
int i = 0, j = 0;
    *nU = dimA + dimB;
    for(; i<*nU; i++){
        if(i<dimA){
             *(ptrAUB+i) = *(ptrA+i);
        }
        else{
             *(ptrAUB +i) = *(ptrB+j);
            j++;
        }
    }
    return;
}
//================================ DIFERENCA ENTRE OS CONJUNTOS =======================================
void diferencaConjunto (int *ptrAIB, int *ptrADB, int *ptrA, int dimA, int *dimADB, int dimAIB){
int i, j, k = 0, aux = 0;
    for (i=0; i<dimA; i++) {
        for (j=0; j<dimAIB; j++ ) {
            if (*(ptrA+i)==*(ptrAIB + j)){
                aux = 1;
                break;
            }
        }
        if (aux == 0) {
            *(ptrADB+k) = *(ptrA+i);
            k++;
        }
        aux = 0;
    }
    *dimADB = k;
    return;
}
//=================================== BUSCA BINARIA  =============================================
short buscaElemento (int *ptrAB, int elem, int dimAB) {
int ini = 0, meio, fim = dimAB - 1;
    while (ini <= fim) {
        meio = (ini + fim)/2;
        if (elem == *(ptrAB+meio)) return (1);
        else if (elem < *(ptrAB+meio)) fim = meio - 1;
        else ini = meio + 1;
    }
    return(0);
}
//================================= VERIFICAR ELEMENTOS REPETIDOS ==============================
int verificarRepeticao (int *ptr, int *ptrR, int *dimR, int dim) {
int i, cont = 0, aux = 1;
    for (i=0; i<dim; i++) {
        while (*(ptr+i) == *(ptr+i+1)) {
            i++;
            cont = 1;
        }
        if (i<dim) {
            if (cont == 1) {
                printf(" [%d]; ",*(ptr+i));
                aux = 0;
            }
        }
        cont = 0;
        }
    for (i=0; i<dim; i++) *(ptrR + i) = *(ptr + i);
    *dimR = dim;
    if (aux) return (0); else return(1);
}
// ================================= ELIMINA OS ELEMENTOS REPETIDOS DO CONJUNTO ==========================
void eliminarRepetidos(int *ptrR,int *ptrAB, int *dimAIB, int dim){
int i, j = 0;
    for (i=0; i<dim; i++) {
        if (*(ptrR+i) == *(ptrR+i+1)) *(ptrAB + j) = *(ptrR + i);
        else  *(ptrAB + j) = *(ptrR + i);
        while( *(ptrR+i) == *(ptrR+i+1 )) i++;
        j++;
    }
    *dimAIB = j;
    return;
}
//==================================  VERIFICA SE JA EXISTE UM CONJUNTO CORRESPONDENTE ======================
short existeConjunto() {
int aux, existe;
    do {
        system("cls");
        aux = 1;
        printf("\n\n\n  JA EXISTE UM CONJUNTO CORRESPONDENTE, DESEJA INSERIR UM NOVO: [S, N] = ");
        scanf("%d", &existe);
        existe = getchar();
        existe = toupper(existe);
        if (existe == 'S' || existe == 's') {
            return (1);
        }
        else if (existe == 'N' || existe == 'n') return(0);
    } while (aux);
}

int main(void) {
int opOperacao = 0, opConjuntoAB = 0, opAssociar = 0, opConjuntos = 0;
int continua = 1, aux=1, elemento, busca, repet;
int nA = 0, nB = 0, nAIB = 0, nAUB = 0, nADB = 0, nBDA = 0, nR = 0;
int A[MAX], B[MAX], INTER[MAX], UNIAO[2*MAX], DIFAB[MAX], DIFBA[MAX], REPET[2*MAX];

    do {
        continua = 1;
        aux = 1;
        opOperacao = menuOperacao();
        system("cls");
        switch(opOperacao) {
            case 1: do{
                        opConjuntoAB = menuConjuntoAB();
                        if (opConjuntoAB == 1)  {if (nA > 0) aux = existeConjunto();}
                        if (opConjuntoAB == 2)  {if (nB > 0) aux = existeConjunto();}
                        if (opConjuntoAB == 3)  aux = 0;
                        if (!aux) break;
                        opAssociar = menuAssociar();
                        system("cls");
                    } while(opAssociar == 3);
                    if (aux) {
                        printf(PULA);
                        if (opConjuntoAB == 1) {
                            Dimensao_Array(&nA);
                            switch (opAssociar) {
                                case 1: associaRandomicamente(A, nA); break;
                                case 2: associaUsuario(A, nA); break;
                            }
                        }
                        else {
                            Dimensao_Array(&nB);
                            switch (opAssociar) {
                                case 1: associaRandomicamente(B, nB); break;
                                case 2: associaUsuario(B, nB); break;
                            }
                        }
                        printf("\n\n   Conjunto gerado com sucesso...");
                    }
                    break;
            case 2:
                    if (nA == 0 && nB == 0) printf("\n\n\n PARA CONTINUAR, gere primeiro os conjuntos A e B ");
                    else if (nA == 0) printf("\n\n\n PARA CONTINUAR, gere primeiro o conjunto A ");
                    else if (nB == 0) printf("\n\n\n PARA CONTINUAR, gere primeiro o conjunto B ");
                    if (nA == 0 || nB == 0) break;
                    interseccaoConjunto(A, B, REPET, nA, nB, &nR);
                    ordenarConjuntos(REPET, nR);
                    eliminarRepetidos(REPET, INTER, &nAIB, nR);
                    printf("\n  ELEMENTOS DO CONJUNTO INTERSECCAO DE A E B \n");
                    Imprimindo_Valores_Array(INTER, nAIB);
                    if (nR == 0) printf("\n \n             CONJUNTO VAZIO");
                    break;
            case 3: if (nA == 0 && nB == 0) printf("\n\n\n PARA CONTINUAR, gere primeiro os conjuntos A e B ");
                    else if (nA == 0) printf("\n\n\n PARA CONTINUAR, gere primeiro o conjunto A ");
                    else if (nB == 0) printf("\n\n\n PARA CONTINUAR, gere primeiro o conjunto B ");
                    if (nA == 0 || nB == 0) break;
                    UniaoDosConjuntos(REPET, A, B,  nA, nB, &nR);
                    ordenarConjuntos(REPET, nR);
                    eliminarRepetidos(REPET, UNIAO, &nAUB, nR);
                    printf("\n  ELEMENTOS DO CONJUNTO UNIAO DE A E B \n");
                    Imprimindo_Valores_Array(UNIAO, nAUB);
                    if (nR == 0) printf("\n\n             CONJUNTO VAZIO");
                    break;
            case 4: if (nA == 0 && nB == 0) printf("\n\n\n PARA CONTINUAR, gere primeiro os conjuntos A e B ");
                    else if (nA == 0) printf("\n\n\n PARA CONTINUAR, gere primeiro o conjunto A ");
                    else if (nB == 0) printf("\n\n\n PARA CONTINUAR, gere primeiro o conjunto B ");
                    if (nA == 0 || nB == 0) break;
                    interseccaoConjunto(A, B, INTER, nA, nB, &nAIB);
                    diferencaConjunto(INTER, REPET, A, nA, &nR, nAIB);
                    ordenarConjuntos(REPET, nR);
                    eliminarRepetidos(REPET, DIFAB, &nADB, nR);
                    printf("\n  ELEMENTOS DO CONJUNTO DIFERENCA ENTRE A E B \n");
                    Imprimindo_Valores_Array(DIFAB, nADB);
                    if (nR == 0) printf("\n \n             CONJUNTO VAZIO");
                    break;
            case 5: if (nA == 0 && nB == 0)
                        printf("\n\n\n PARA CONTINUAR, gere primeiro os conjuntos A e B ");
                    else if (nA == 0)
                        printf("\n\n\n PARA CONTINUAR, gere primeiro o conjunto A ");
                    else if (nB == 0)
                        printf("\n\n\n PARA CONTINUAR, gere primeiro o conjunto B ");
                    if (nA == 0 || nB == 0) break;
                    interseccaoConjunto(A, B, INTER, nA, nB, &nAIB);
                    diferencaConjunto(INTER, REPET, B, nB, &nR, nAIB);
                    ordenarConjuntos(REPET, nR);
                    eliminarRepetidos(REPET, DIFBA, &nBDA, nR);
                    printf("\n  ELEMENTOS DO CONJUNTO DIFERENCA ENTRE B E A \n");
                    Imprimindo_Valores_Array(DIFBA, nBDA);
                    if (nR == 0) printf("\n \n             CONJUNTO VAZIO");
                    break;
            case 6: if (nA == 0) {
                        printf("\n\n\n PARA CONTINUAR, gere primeiro o conjunto A ");
                        break;
                    }
                    printf("\n  ELEMENTOS DO CONJUNTO A \n");
                    ordenarConjuntos(A, nA);
                    Imprimindo_Valores_Array(A, nA);
                    if (nA == 0) printf("\n \n             CONJUNTO VAZIO");
                    break;
            case 7:if (nB == 0) {
                        printf("\n \n \n Para continuar, gere primeiro o conjunto B ");
                        break;
                    }
                    printf("\n  ELEMENTOS DO CONJUNTO B \n");
                    ordenarConjuntos(B, nB);
                    Imprimindo_Valores_Array(B, nB);
                    if (nB == 0) printf("\n \n             CONJUNTO VAZIO");
                    break;
            case 8: opConjuntos = menuConjuntos();
                    system("cls");
                    switch(opConjuntos) {
                        case 1:if (nAIB == 0) {
                                    printf("\n\n\n PARA CONTINUAR, tenha um conjunto INTERSECCAO  ");
                                    aux = 0;
                                    break;
                                }
                                printf(PULA);
                                printf(PERTENCE);
                                scanf("%d", &elemento);
                                busca = buscaElemento(INTER, elemento, nAIB);
                                break;
                        case 2:if (nAUB == 0) {
                                    printf("\n\n\n PARA CONTINUAR, tenha um conjunto UNIAO  ");
                                    aux = 0;
                                    break;
                                }
                                printf(PULA);
                                printf(PERTENCE);
                                scanf("%d", &elemento);
                                busca = buscaElemento(UNIAO, elemento, nAUB);
                                break;
                        case 3:if (nADB == 0) {
                                    printf("\n\n\n PARA CONTINUAR, tenha um conjunto DIFERENCA ENTRE A E B  ");
                                    aux = 0;
                                    break;
                                 }
                                printf(PULA);
                                printf(PERTENCE);
                                scanf("%d", &elemento);
                                busca = buscaElemento(DIFAB, elemento, nADB);
                                break;

                        case 4:if (nBDA == 0) {
                                    printf("\n\n\n PARA CONTINUAR, tenha um conjunto DIFERENCA ENTRE B E A ");
                                    aux = 0;
                                    break;
                                }
                                printf(PULA);
                                printf(PERTENCE);
                                scanf("%d", &elemento);
                                busca = buscaElemento(DIFBA, elemento, nBDA);
                                break;
                        case 5:if (nA == 0) {
                                    printf("\n\n\n PARA CONTINUAR, tenha um conjunto A  ");
                                    aux = 0;
                                    break;
                                }
                                printf(PULA);
                                printf(PERTENCE);
                                scanf("%d", &elemento);
                                busca = buscaElemento(A, elemento, nA);
                                break;
                        case 6: if (nB == 0) {
                                    printf("\n\n\n PARA CONTINUAR, tenha um conjunto B  ");
                                    aux = 0;
                                    break;
                                }
                                printf(PULA);
                                printf(PERTENCE);
                                scanf("%d", &elemento);
                                busca = buscaElemento(B, elemento, nB);
                                break;
                        case 7: aux = 0;
                    }
                    if (aux) {
                        if (busca) printf("\n\n  O ELEMENTO [%d] PERTENCE AO CONJUNTO  ", elemento);
                        else printf("\n\n  O ELEMENTO [%d] NAO PERTENCE AO CONJUNTO   ", elemento);
                    }
                    break;
            case 9: opConjuntoAB = menuConjuntoAB();
                    system("cls");
                    switch (opConjuntoAB){
                        case 1: if (nA == 0){
                                    printf("\n \n \n PARA CONTINUAR, tenha um conjunto A ");
                                    aux = 0;
                                    break;
                                }
                                printf("\n\n  Confira os valores repetidos: ");
                                ordenarConjuntos(A, nA);
                                repet = verificarRepeticao(A, REPET, &nR, nA);
                                if (repet) aux = 1;
                                else {
                                    printf("  NAO HA ELEMENTOS REPETIDOS");
                                    aux = 0;
                                }
                                break;
                        case 2: if (nB == 0){
                                    printf("\n \n \n PARA CONTINUAR, tenha um conjunto B ");
                                    aux = 0;
                                    break;
                                }
                                printf("\n\n  Confira os valores repetidos: ");
                                ordenarConjuntos(B, nB);
                                repet = verificarRepeticao(B,  REPET, &nR,  nB);
                                if (repet) aux = 1;
                                else {
                                    printf("  NAO HA ELEMENTOS REPETIDOS");
                                    aux = 0;
                                }
                                break;
                        case 3: aux = 0; break;
                    }
                    if(aux){
                        do {
                            printf(PULA);
                            system("pause");
                            system("cls");
                            aux = 1;
                            printf("\n\n\n  Voce deseja remover os elementos repetidos: [S, N] = ");
                            scanf("%d", &repet);
                            repet = getchar();
                            repet= toupper(repet);
                            if (repet == 'S' || repet == 's') {
                                if (opConjuntoAB == 1) {
                                    ordenarConjuntos(REPET, nR);
                                    eliminarRepetidos(REPET, A, &nA, nR);
                                }
                                else {
                                    ordenarConjuntos(REPET, nR);
                                    eliminarRepetidos(REPET, B, &nB, nR);
                                }
                                aux = 0;
                            }
                            else if (repet == 'N' || repet == 'n') aux = 0;
                        } while (aux);
                    }
                    break;
            case 10:opConjuntos = menuConjuntos();
                    system("cls");
                    switch(opConjuntos) {
                        case 1:if (nAIB == 0) {
                                    printf("\n\n\n PARA CONTINUAR, tenha um conjunto INTERSECCAO  ");
                                    break;
                                }
                                printf("  O CONJUNTO INTERSECCAO TEM [%d] ELEMENTOS", nAIB);
                                break;
                        case 2:if (nAUB == 0) {
                                    printf("\n\n\n PARA CONTINUAR, tenha um conjunto UNIAO  ");
                                    break;
                                }
                                printf("\n\n\n  O CONJUNTO UNIAO TEM [%d] ELEMENTOS", nAUB);
                                break;
                        case 3:if (nADB == 0) {
                                    printf("\n\n\n PARA CONTINUAR, tenha um conjunto DIFERENCA ENTRE A E B  ");
                                    break;
                                 }
                                printf("\n\n\n  O CONJUNTO DIFERENCA ENTRE A E B TEM [%d] ELEMENTOS", nADB);
                                break;
                        case 4:if (nBDA == 0) {
                                    printf("\n\n\n PARA CONTINUAR, tenha um conjunto DIFERENCA ENTRE B E A ");
                                    break;
                                }
                                printf("\n\n\n  O CONJUNTO DIFERENCA ENTRE B E A TEM [%d] ELEMENTOS", nBDA);
                                break;
                        case 5:if (nA == 0) {
                                    printf("\n\n\n PARA CONTINUAR, tenha um conjunto A  ");
                                    break;
                                }
                                printf("\n\n\n  O CONJUNTO A TEM [%d] ELEMENTOS", nA);
                                break;
                        case 6: if (nB == 0) {
                                    printf("\n\n\n PARA CONTINUAR, tenha um conjunto B  ");
                                    break;
                                }
                                printf("\n\n\n  O CONJUNTO B TEM [%d] ELEMENTOS", nB);
                                break;
                        case 7: break;
                    }
                    break;
            case 11: return(0);
        }
        printf(PULA);
        system("pause");
    } while(continua);
    return(0);
}

