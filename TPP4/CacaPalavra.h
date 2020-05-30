#ifndef CACAPALAVRA_H_INCLUDED
#define CACAPALAVRA_H_INCLUDED

int Menu(void);
void ImprimirMatriz(char *CP, int dim);
void ImprimirMatrizColorida(char *CP, int dim, char *copiaCP);
void MatrizVazia(char *CP, int dim);
void zerarArray(int *aux, int dim);
int gerarValorAleatoria(int limite);
void ReverteString(char *Str, char *Rev);
void PreencherCacaPalavras(char *CP, int dim);

int Menu(void){
int op;
    do{
        system("cls");
        printf("\n==========================================\n");
        printf("            JOGO CACA-PALAVRA \n");
        printf("==========================================\n\n");
        printf(" [1] - GERAR UM NOVO CACA-PALAVRA \n");
        printf(" [2] - RESPOSTA DO CACA-PALAVRA \n");
        printf(" [3] - SAIR\n\n");
        printf(" Escolha uma opcao: ");
        scanf("%d", &op);
    } while(op < 1 || op > 3);
    return(op);
}

void ImprimirMatriz(char *CP, int dim){
int i = 0, j;
    for(; i<dim; i++){
        printf("\n");
        for(j=0; j<dim; j++){
            printf(" %c ", *(CP + i*dim + j));
        }
    }
    printf("\n");
    return;
}

void ReverteString(char *Str, char *Rev){
int i = 0, tam = strlen(Str), lim = tam -1;
   for ( ; i < tam; i++) {
    *(Rev + i) = *(Str + lim - i);
   }
   *(Rev + i) ='\0';
return;
}

void ImprimirMatrizColorida(char *CP, int dim, char *copiaCP){
int i = 0, j;
    for(; i<dim; i++){
        printf("\n");
        for(j=0; j<dim; j++){
            if(*(copiaCP + i*dim + j) != '-'){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 9);
                printf(" %c ", *(copiaCP + i*dim + j));
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
            }
            else {
                    *(copiaCP + i*dim + j) = *(CP + i*dim + j);
                    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 8);
                    printf(" %c ", *(CP + i*dim + j));
                    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
            }
        }
    }
    printf("\n");
    return;
}

void MatrizVazia(char *CP, int dim){
int i = 0, j;
    for(; i<dim; i++){
        for(j=0; j<dim; j++){
            *(CP + i*dim + j) = '-';
        }
    }
    return;
}

void zerarArray(int *aux, int dim){
    int i = 0;
    for(; i<dim; i++){
        *(aux+i) = 0;
    }
    return;
}

int gerarValorAleatoria(int limite){
int i = 0, j;
    i = rand() % limite;
    return(i);
}

void PreencherCacaPalavras(char *CP, int dim){
int i=0, j, letra;
    for(;i<dim;i++){
        for(j=0;j<dim;j++){
            letra =  65 + (rand() % 25);
            if(*(CP + i*dim+ j) == '-')
                *(CP + i*dim+ j) = letra;
        }
    }
    return;
}
//=======================================================================

#endif // CACAPALAVRA_H_INCLUDED
