#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500000
#define PULA  "\n\n\n"

void Dimensao_Array(int *ptr1);
void associaRandomicamente(int *ptr, int dim);
void associaUsuario(int *ptr, int dim);
void Imprimindo_Valores_Array(int *ptr, int dim);
short menuOperacao(void);
short menuAssociar (void);
//===========================PROTOTIPOS DAS FUNCOES DE ORDENACAO QUICK E MARGE============================
void troca(int A[], int i, int j);
int calcularMediana(int A[], int inicio, int fim);
int partition(int A[], int inicio, int fim);
void quicksortMedianaDeTres(int A[], int inicio, int fim);
void MergeSort(int *List, int Ini, int Fim);
void Merge(int S[], int p, int q, int r);


//================================ ORDENACAO DOS CONJUNTOS =========================================

// =============================ORDENACAO POR MERGESORT===========================================
void MergeSort(int *List, int Ini, int Fim){
    if ( Ini < Fim ) {
        int meio = (Ini+Fim)/2;
        MergeSort(List, Ini, meio);
        MergeSort(List, meio+1, Fim);
        Merge(List, Ini, meio, Fim);
    }
}

void Merge(int S[], int p, int q, int r) {
int B[MAX], i = p, j = q+1, k = p;
    while ((i <= q) && (j <= r)){
        if (S[i] < S[j]) {
            B[k] = S[i];
            k++; i++;
        } else {
            B[k] = S[j];
            k++; j++;
        }
    }
    while (i <= q){ B[k] = S[i]; k++; i++;}
    while (j <= r){ B[k] = S[j]; k++; j++;}
    for (i = p; i <= r; i++) S[i] = B[i];
}

// =============================ORDENACAO POR QUICKSORT===========================================

void troca(int A[], int i, int j){
    int aux = A[i];
    A[i] = A[j];
    A[j] = aux;
}

int calcularMediana(int A[], int inicio, int fim) {
    int meio = (inicio + fim) / 2;
    int a = A[inicio];
    int b = A[meio];
    int c = A[fim];
    int mediana;
    if (a < b) {
        if (b < c) {
            mediana = meio;
        } else {
            if (a < c) {
                mediana = fim;
            } else {
                mediana = inicio;
            }
        }
    } else {
        if (c < b) {
            mediana = meio;
        } else {
            if (c < a) {
                mediana = fim;
            } else {
                mediana = inicio;
            }
        }
    }

    return(mediana);
}

int partition(int A[], int inicio, int fim) {
    int medianaIndice = calcularMediana(A, inicio, fim);
    troca(A, medianaIndice, fim);
    int pivo = A[fim];
    int i = inicio - 1;
    int j;
    for (j = inicio; j <= fim - 1; j++) {
        if (A[j] <= pivo) {
            i = i + 1;
            troca(A, i, j);
        }
    }
    troca(A, i + 1, fim);
    return i + 1;
}

void quicksortMedianaDeTres(int A[], int inicio, int fim) {
    if (inicio < fim) {
        int q = partition(A, inicio, fim);
        quicksortMedianaDeTres(A, inicio, q - 1);
        quicksortMedianaDeTres(A, q + 1, fim);
    }
}
//================================ MENU INICIAL COM TODAS AS OPERACOES =========================================
short menuOperacao(void){
int op = 0;
    do{
        system("CLS");
        printf("\n      ------------ ESCOLHA UMA DAS OPERACOES ------------- \n\n");

        printf("  [1] - Gerar os elementos do conjunto \n");
        printf("  [2] - Imprimir o conjunto \n");
        printf("  [3] - Ordenar por QuickSort \n");
        printf("  [4] - Ordenar por MergeSort \n");
        printf("  [5] - SAIR DA APLICACAO");
        printf("\n\n  Escolha a opcao desejada : ");
        scanf("%d", &op);
    }while(op < 1 || op > 5);
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
//==========================CALCULAR A QUANTIDADE DE ELEMENTO DE CADA CONJUNTO==========================================
void Dimensao_Array (int *ptr1) {
    int dim1, continua;
    do {
        continua = 0;
        printf("   Insira a quantidade de elementos do conjunto:  ");
        scanf("%d", &dim1);
        if (dim1 < 0 || dim1 > MAX ){
            continua = 1;
            printf("\n  Aviso: A quantidade de elementos devem estar no intervalo entre 0 e 500000 \n\n");
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

//================================ IMPRIMI OS VALORES DOS CONJUNTOS A e B =========================================
void Imprimindo_Valores_Array(int *ptr, int dim) {
int i = 0;
    for (; i < dim; i++) printf("\n [%d] = %d ",i,*(ptr+i));
    return;
}

int main(void) {
int opOperacao = 0, opAssociar = 0;
int continua = 1;
int nA = 0, qs = 0;
int A[MAX];
    do {
        continua = 1;
        opOperacao = menuOperacao();
        system("cls");
        switch(opOperacao) {
            case 1:
                    opAssociar = menuAssociar();
                    system("cls");
                    printf(PULA);
                    Dimensao_Array(&nA);
                    switch (opAssociar) {
                        case 1: associaRandomicamente(A, nA); break;
                        case 2: associaUsuario(A, nA); break;
                    }
                    printf("\n\n   Conjunto gerado com sucesso...");
                    qs = 0;
                    break;
            case 2:
                  if(nA == 0) {
                        printf("\n\n\n   Primeiro, associe elementos ao conjunto... \n ");
                        break;
                  }
                  Imprimindo_Valores_Array(A, nA);
                  break;
            case 3:
                    system("cls");
                    if(nA == 0) {
                        printf("\n\n\n   Primeiro, associe elementos ao conjunto... \n ");
                        break;
                    }
                    if (qs == 1) {
                        printf("\n  O conjunto ja foi ordenado, adicione outro conjunto ou vizualize ele  \n\n");

                        break;
                    }
                    qs = 1;
                    quicksortMedianaDeTres(A, 0, nA-1);
                    Imprimindo_Valores_Array(A, nA);
                    printf("\n\n   Conjunto ordenado pelo metodo QuickSort ... \n\n");
                    break;
            case 4:
                    system("cls");
                    if(nA == 0) {
                        printf("\n\n\n   Primeiro, associe elementos ao conjunto... \n ");
                        break;
                    }
                    if (qs == 1) {
                        printf("\n  O conjunto ja foi ordenado, adicione outro conjunto ou vizualize ele  \n\n");
                        break;
                    }
                    qs = 1;
                    MergeSort(A, 0, nA-1);
                    Imprimindo_Valores_Array(A, nA);
                    printf("\n\n   Conjunto ordenado pelo metodo MergeSort ... \n \n");
                    break;
            case 5:
                  continua = 0;
                  break;
        }
        printf(PULA);
        system("pause");
    } while(continua);
    return(0);
}

