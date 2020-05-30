#ifndef CACAPALAVRABUSCA_H_INCLUDED
#define CACAPALAVRABUSCA_H_INCLUDED

void EncontrarPalavraCP(char *CP, int dim, char  *palavras, char *copiaCP);
Boleano EncontrarHorizontal(char *CP, int dim, char *palavra, int linha, int coluna);
Boleano EncontrarVertical(char *CP, int dim, char *palavra, int linha, int coluna);
Boleano EncontrarDiagonalPrincipal(char *CP, int dim, char *palavra, int linha, int coluna);
Boleano EncontrarDiagonalSecundaria(char *CP, int dim, char *palavra, int linha, int coluna);

void EncontrarPalavraCP(char *CP, int dim, char  *palavra, char *copiaCP){
int i, j, k = 0;
    for(i=0; i<dim;i++){
        for(j=0; j<dim; j++){
            if(*(CP+i*dim+j) == *(palavra+k)){
                if(EncontrarHorizontal(CP, dim, palavra, i, j)){
                    associarPalavraHorizontal(copiaCP, dim, palavra, i, j);
                    return;
                }
                if(EncontrarVertical(CP, dim, palavra, i, j)){
                    associarPalavraVertical(copiaCP, dim, palavra, i, j);
                    return;
                }
                if(EncontrarDiagonalPrincipal(CP, dim, palavra, i, j)){
                    associarPalavraDiagonalPrin(copiaCP, dim, palavra, i, j);
                    return;
                }
                if(EncontrarDiagonalSecundaria(CP, dim, palavra, i, j)){
                    associarPalavraDiagonalSecun(copiaCP, dim, palavra, i, j);
                    return;
                }
            }
        }
    }
    return;
}
Boleano EncontrarHorizontal(char *CP, int dim, char *palavra, int linha, int coluna){
int k=0;
    while(*(palavra+k) != '\0'){
        if(*(palavra+k) != *(CP + linha*dim + coluna)) return(0);
        k++; coluna++;
    }
    return(1);
}
Boleano EncontrarVertical(char *CP, int dim, char *palavra, int linha, int coluna){
int k=0;
    while(*(palavra+k) != '\0'){
        if(*(palavra+k) != *(CP + linha*dim + coluna)) return(0);
        k++; linha++;
    }
    return(1);
}
Boleano EncontrarDiagonalPrincipal(char *CP, int dim, char *palavra, int linha, int coluna){
int k=0;
    while(*(palavra+k)!= '\0'){
        if(*(palavra+k) != *(CP + linha*dim + coluna)) return(0);
        k++; coluna++; linha++;
    }
    return(1);
}

Boleano EncontrarDiagonalSecundaria(char *CP, int dim, char *palavra, int linha, int coluna){
int k=0;
    while(*(palavra+k)!= '\0'){
        if(*(palavra+k) != *(CP + linha*dim + coluna)) return(0);
        k++; coluna--; linha++;
    }
    return(1);
}

#endif // CACAPALAVRABUSCA_H_INCLUDED
