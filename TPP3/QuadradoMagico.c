#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

typedef enum boleano{falso = 0, verdadeiro}Boleano;
//==========================PROTOTIPOS DO PROJETO======================================
Boleano ConverteStrInteiro(int *Inteiro, int *Pos, const char *Str);
void Dimensao2d (char *N, int *num);
void AtualizaNovaPosicao (int dimlinha, int dimcoluna, int *i, int *j);
Boleano Continua(void);
void MatrizMagicaImpar(int *A, int n, int num, int term);
void MatrizMagicaDivDois(int *A, int n);
void InverterQuadrantes(int *A, int n, int limite);
void swap(int *A, int n, int i, int j, int ci);
void MatrizMagicaDivQuatro(int *A, int n);

// ===================FUNCOES PARA A INTERFACE TEXTUAL==================================
Boleano ConverteStrInteiro(int *Inteiro, int *Pos, const char *Str){
int i = 0, aux = 1;
    if (*(Str + i) == '+') i++;
    while(*(Str + i) != '\0'){
        if (*(Str + i) < 48 || *(Str + i) > 57) {
            *Pos = i;
            return(0);
        }
        *Inteiro = (*(Inteiro)*10) + *(Str + i) - 48;
        i++;
    }
    return(1);
}
void Dimensao2d (char *N, int *num) {
int posicao = 0;
    do{
        *num = 0;
        system("cls");
        printf("\n  Insira a ordem de sua Matriz Magica (entre 3 e 10): ");
        scanf("%s", N);
        if(!ConverteStrInteiro(num, &posicao, N)) {
            printf("\n  ERRO, CARACTER [%c] NAO E UM NUMERO, DIGITE UM NUMERO\n\n", *(N + posicao));
            system("pause");
        }
    } while(*num<3 || *num>10);
    return;
}
void ImprimirArray2d (int *A, int n) {
int i=0, j;
    printf("\n A constante MAGICA da Matrix %dx%d e: %d \n", n, n, n*(n*n+1)/2);
    for(; i<n; i++){
        printf("\n");
        for(j=0; j<n; j++) printf("[%3d] ", *(A + i*n + j));
    }
    return;
}
Boleano Continua(void) {
int ch;
  do {
		system("cls");
        printf("\n\n\n      Voce deseja gerar outra Matriz Magica? [S,N] : ");
		ch = getchar();
		ch= toupper(ch);
  }
  while( (ch != 'S') && (ch != 'N') );
  if(ch == 'S') return(1);
  else return(0);
}

//=======================FUNCAO PARA CALCULAR MATRIZ IMPAR==============================
void MatrizMagicaImpar(int *A, int n, int num, int term){
    int i, j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++) *(A + i*n + j) = 0;
	}
	i = 0;
	j = n/2;
	while (num <= term){
		if (i==-1 && j==n){
            j -= 1;
            i+= 2;
		}
		else {
			if (j == n) j = 0;
			if (i < 0) i=n-1;
		}
		if (*(A + i*n + j)){
			j -= 1;
			i+= 2;
			continue;
		}
		else *(A + i*n + j) = num++;
		j++; i--;
	}
}

//=======================FUNCAO PARA CALCULAR MATRIZ PAR DIVISIVEL POR 2======================
void MatrizMagicaDivDois(int *A, int n){
int lim = n/2, ini = 1, fim = (n*n)/4, ci = 0, cj = 0, i, j, aux;
int AUX[lim][lim];
    //QUADRANTE A
    MatrizMagicaImpar(&AUX[0][0], lim, ini, fim);
    for (i=0; i<lim; i++){
		for (j=0; j<lim; j++)
			*(A + i*n + j) = AUX[i][j];
	}
    //QUADRANTE B
    ini = fim+1; fim += (n*n)/4;
    MatrizMagicaImpar(&AUX[0][0], lim, ini, fim);
	for(i=lim; i<n; i++){
        cj=0;
        for(j=lim; j<n; j++){
            *(A + i*n + j) = AUX[ci][cj];
            cj++;
        }
        ci++;
	}
    //QUADRANTE C
    ini = fim+1; fim += (n*n)/4;
    MatrizMagicaImpar(&AUX[0][0], lim, ini, fim);
    ci=0;
    for(i=0; i<lim; i++){
        cj=0;
        for(j=lim; j<n; j++){
            *(A + i*n + j) = AUX[ci][cj];
            cj++;
        }
        ci++;
	}
    //QUADRANTE D
    ini = fim+1; fim += (n*n)/4;
    MatrizMagicaImpar(&AUX[0][0], lim, ini, fim);
    ci=0;
    for(i=lim; i<n; i++){
        cj=0;
        for(j=0; j<lim; j++){
            *(A + i*n + j) = AUX[ci][cj];
            cj++;
        }
        ci++;
	}
	InverterQuadrantes(A, n, lim);
	return;
}
void InverterQuadrantes(int *A, int n, int limite){
    int x = (n - 2)/4, ci=limite, aux, i, j;
    for(i=0; i<limite; i++){
        for(j=0; j<x; j++){
            if(i != limite/2) {
                swap(A, n, i, j, ci);
                continue;
            }
            for(j=1; j<=x; j++)
                swap(A, n, i, j, ci);
        }
        for(j=0; j<x-1; j++)
            swap(A, n,  i, n-1, ci);
        ci++;
    }
    return;
}
void swap(int *A, int n, int i, int j, int ci){
int aux;
    aux = *(A + i*n + j);
    *(A + i*n + j) = *(A + ci*n + j);
    *(A + ci*n + j) = aux;
    return;
}

//=======================FUNCAO PARA CALCULAR MATRIZ PAR DIVISIVEL POR 4======================
void MatrizMagicaDivQuatro(int *A, int n){
int i, j;
		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
				*(A + i*n + j) = (n*i) + j + 1;

		for (i=0; i<n/4; i++)
			for (j=0; j<n/4; j++)
				*(A + i*n + j)= (n*n + 1) - *(A + i*n + j);

		for (i=0; i<n/4; i++)
			for (j = 3*(n/4); j<n; j++)
				*(A + i*n + j) = (n*n + 1) - *(A + i*n + j);

		for (i = 3 * n/4; i < n; i++)
			for (j=0; j<n/4; j++)
				*(A + i*n + j) = (n*n+1) - *(A + i*n + j);

		for ( i=3 * n/4; i<n; i++)
			for ( j=3 * n/4; j<n; j++)
				*(A + i*n + j) = (n*n + 1) - *(A + i*n + j);

		for (i=n/4; i<3 * n/4; i++)
			for (j=n/4; j<3 * n/4; j++)
				*(A + i*n + j) = (n*n + 1) - *(A + i*n + j);
    return;
}

int main(void){
    char nLeitura[3];
    int QuadradoMagico[MAX][MAX], n = 0;
    do {
        Dimensao2d(nLeitura, &n);
        system("cls");
        if(n%4==0) {
            printf("\n  =======E UMA MATRIZ DE ORDEM PAR======  \n ");
            MatrizMagicaDivQuatro(&QuadradoMagico[0][0], n);
        }
        else if(n%2==0){
            printf("\n  =======E UMA MATRIZ DE ORDEM PAR======  \n ");
            MatrizMagicaDivDois(&QuadradoMagico[0][0], n);
        }
        else {
            printf("\n  =======E UMA MATRIZ DE ORDEM IMPAR======  \n ");
            int num = 1;
            MatrizMagicaImpar(&QuadradoMagico[0][0], n, num, n*n);
            }
        ImprimirArray2d(&QuadradoMagico[0][0], n);
        printf("\n\n");
        system("pause");
    } while (Continua());
    system("pause");
    return(0);
}
