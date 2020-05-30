#ifndef CACAPALAVRAEFICIENTE_H_INCLUDED
#define CACAPALAVRAEFICIENTE_H_INCLUDED

typedef enum boleano{falso, verdadeiro} Boleano;

Boleano verificarCruzamentoHorizon(char *CP, int dim, char *palavra, int *aux);
Boleano verificarCorrespHorizon(char *CP, int dim, char *palavra, int linha, int coluna);
void associarPalavraHorizontal(char *CP, int dim, char *palavra, int linha, int coluna);
Boleano EncontrarEspacoVazioHorizontal(char *CP, int dim, char *palavra, int linha, int coluna);
void gerarPalavraHorizontal(char *CP, int dim, char *palavra, int *aux);

Boleano verificarCorrespVertic(char *CP, int dim, char *palavra, int linha, int coluna);
Boleano verificarCruzamentoVertic(char *CP, int dim, char *palavra, int *aux);
void gerarPalavraVertical(char *CP, int dim, char *palavra, int *aux);
void associarPalavraVertical(char *CP, int dim, char *palavra, int linha, int coluna);
Boleano EncontrarEspacoVazioVertical(char *CP, int dim, char *palavra, int linha, int coluna);

Boleano verificarCorrespondenciaDiagonal(char *CP, int dim, int linha, int coluna);
void gerarPalavraDiagonalPrincipal(char *CP, int dim, char **palavra);
void associarPalavraDiagonalPrin(char *CP, char dim, char *palavra, int linha, int coluna);

void gerarPalavraDiagonalSecundaria(char *CP, int dim, char **palavra);
void associarPalavraDiagonalSecun(char *CP, char dim, char *palavra, int linha, int coluna);
Boleano verificarCorresDiagonalSecun(char *CP, int dim, char *palavra, int linha, int coluna);
//==========================================================================================================
//==========================================================================================================
//==========================================================================================================
Boleano verificarCruzamentoHorizon(char *CP, int dim, char *palavra, int *aux){
    int i = 0, j, tamanho;
    tamanho = strlen(palavra);
    for(;i<dim; i++){
        for(j=0; tamanho < (dim-j) && *(aux+i) == 0; j++)
            if(verificarCorrespHorizon(CP, dim, palavra, i, j)) {
                *(aux+i) = 1;
                associarPalavraHorizontal(CP, dim, palavra, i, j);
                return(1);
            }
    }
    return(0);
}
Boleano verificarCorrespHorizon(char *CP, int dim, char *palavra, int linha, int coluna){
int k = 0, auxiliar = 0;
    while(*(palavra+k) != '\0'){
            if (*(CP + linha*dim + coluna) == *(palavra+k)) auxiliar = 1;
            else if (*(CP + linha*dim + coluna) == '-') ;
            else return(0);
            coluna++; k++;
    }
    if(auxiliar) return(1);
    return(0);
}
void associarPalavraHorizontal(char *CP, int dim, char *palavra, int linha, int coluna){
int k = 0;
    while(*(palavra + k) != '\0'){
        *(CP + linha*dim + coluna) = *(palavra + k);
        coluna++; k++;
    }
    return;
}
void gerarPalavraHorizontal(char *CP, int dim, char *palavra, int *aux){
int i = 0, j, tamanho;
    tamanho = strlen(palavra);
    do{
        j = gerarValorAleatoria(dim);
        i = gerarValorAleatoria(dim);
    }while(tamanho > dim-j || *(aux+i)==1 || !EncontrarEspacoVazioHorizontal(CP, dim, palavra, i, j));
    *(aux+i)=1;
    associarPalavraHorizontal(CP, dim, palavra, i, j);
    return;
}
Boleano EncontrarEspacoVazioHorizontal(char *CP, int dim, char *palavra, int linha, int coluna){
int k = 0;
    while(*(palavra+k) != '\0'){
        if(*(CP + linha*dim + coluna) != '-') return(0);
        coluna++; k++;
    }
    return(1);
}
//==========================================================================================================
//==========================================================================================================
//==========================================================================================================
Boleano verificarCruzamentoVertic(char *CP, int dim, char *palavra, int *aux){
    int i = 0, j, tamanho;
    tamanho = strlen(palavra);
    for(;i<dim; i++){
        for(j=0; tamanho < (dim-i) && *(aux+j) == 0; j++)
            if(verificarCorrespVertic(CP, dim, palavra, i, j)) {
                *(aux+j) = 1;
                associarPalavraVertical(CP, dim, palavra, i, j);
                return(1);
            }
    }
    return(0);
}
Boleano verificarCorrespVertic(char *CP, int dim, char *palavra, int linha, int coluna){
int k = 0, auxiliar = 0;
    while(*(palavra+k) != '\0'){
            if (*(CP + linha*dim + coluna) == *(palavra+k)) auxiliar = 1;
            else if (*(CP + linha*dim + coluna) == '-') ;
            else return(0);
            linha++; k++;
    }
    if(auxiliar) return(1);
    return(0);
}
void gerarPalavraVertical(char *CP, int dim, char *palavra, int *aux){
int i = 0, j, tamanho, contagem = 0;
    tamanho = strlen(palavra);
    do{
        j = gerarValorAleatoria(dim);
        i = gerarValorAleatoria(dim);
        contagem++;
        if (contagem > 2000) return;
    }while(tamanho > dim-i || *(aux+j)==1 || EncontrarEspacoVazioVertical(CP, dim, palavra, i, j) == 0);
    *(aux+j) = 1;
    associarPalavraVertical(CP, dim, palavra, i, j);
    return;
}

void associarPalavraVertical(char *CP, int dim, char *palavra, int linha, int coluna){
int k = 0;
    while(*(palavra + k) != '\0'){
        *(CP + linha*dim + coluna) = *(palavra + k);
        linha++; k++;
    }
    return;
}

Boleano EncontrarEspacoVazioVertical(char *CP, int dim, char *palavra, int linha, int coluna){
int k = 0;
    while(*(palavra+k) != '\0'){
        if(*(CP + linha*dim + coluna) != '-') return(0);
        linha++; k++;
    }
    return(1);
}

//===========================ASSOCIAR VALORES AO CACA PALAVRA PELAS DIAGONAIS E SUAS CORRESPONDENTES ==========================

void gerarPalavraDiagonalPrincipal(char *CP, int dim, char **palavra){
int i = 0, j, tamanho;
    tamanho = strlen(*palavra);
    do{
        j = gerarValorAleatoria(dim);
        i = gerarValorAleatoria(dim);
    }while(tamanho > (dim-j) || tamanho > (dim-i) || verificarCorrespondenciaDiagonal(CP, dim, i, j));
    associarPalavraDiagonalPrin(CP, dim, *palavra, i, j);
    return;
}
Boleano verificarCorrespondenciaDiagonal(char *CP, int dim, int linha, int coluna){
    while(linha < dim && coluna < dim){
        if(*(CP + linha*dim + coluna) != '-') return(1);
        coluna++; linha++;
    }
    return(0);
}
void associarPalavraDiagonalPrin(char *CP, char dim, char *palavra, int linha, int coluna){
int k = 0;
    while(*(palavra + k) != '\0'){
        *(CP + linha*dim + coluna) = *(palavra + k);
        linha++; coluna++; k++;
    }
    return;
}

void gerarPalavraDiagonalSecundaria(char *CP, int dim, char **palavra){
int i = 0, j, tamanho;
    tamanho = strlen(*palavra);
    do{
        j = gerarValorAleatoria(dim);
        i = gerarValorAleatoria(dim);
    }while(j - tamanho < 0 || tamanho > dim-i || !verificarCorresDiagonalSecun(CP, dim, *palavra, i, j));
    associarPalavraDiagonalSecun(CP, dim, *palavra, i, j);
    return;
}

void associarPalavraDiagonalSecun(char *CP, char dim, char *palavra, int linha, int coluna){
int k = 0;
    while(*(palavra + k) != '\0'){
        *(CP + linha*dim + coluna) = *(palavra + k);
        linha++; coluna--; k++;
    }
    return;
}
Boleano verificarCorresDiagonalSecun(char *CP, int dim, char *palavra, int linha, int coluna){
int k = 0;
    while(*(palavra+k) != '\0'){
        if(*(CP + linha*dim + coluna) != '-'){
            if(*(palavra + k) != *(CP + linha*dim + coluna)) return(0);
        }
        linha++; coluna--; k++;
    }
    return(1);
}
//===============================================================
//==============================================================================================
#endif // CACAPALAVRAEFICIENTE_H_INCLUDED
