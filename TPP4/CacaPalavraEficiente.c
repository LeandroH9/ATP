#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "CacaPalavra.h"
#include "CacaPalavraEficiente.h"
#include "CacaPalavraBusca.h"

#define MAX 20


int main(void){
char CP[MAX][MAX], copiaCP[MAX][MAX];
int dim = 20, k, i = 0, op;
char *palavras[MAX] = {"BARCELONA", "BRATISLAVA", "CAMBRIDGE", "COPENHAGUE","DUSSELDORF", "EDIMBURGO",
                      "FRANKFURT", "KIEV", "LIVERPOOL","LEEDS","MAASTRICHT", "MADRID", "MANCHESTER","LISBOA",
                      "LONDRES", "PALERMO", "PARIS", "SERVILHA", "SHEFFIED", "TURIM"};
char *palavra, reversopalavra[MAX], vizualizar = 0;
int aux[MAX], palavraSelect[MAX];
time_t t;
    srand((unsigned) time(&t));
    do{
        system("cls");
        op = Menu();
        switch(op) {
            case 1:
                i = 0;
                zerarArray(aux, dim);
                zerarArray(palavraSelect, dim);
                MatrizVazia(&CP[0][0], dim);
                for(k=0; k<2; k++){
                    do{
                        i = gerarValorAleatoria(dim);
                    }while(palavraSelect[i] == 1);
                    palavraSelect[i] = 1;
                    gerarPalavraDiagonalPrincipal(&CP[0][0], dim, palavras+i);
                }
                for(k=0; k<2; k++){
                    do{
                        i = gerarValorAleatoria(dim);
                    }while(palavraSelect[i] == 1);
                    palavraSelect[i] = 1;
                    gerarPalavraDiagonalSecundaria(&CP[0][0], dim, palavras+i);
                }
                for(k=0; k<4; k++){
                    do{
                        i = gerarValorAleatoria(dim);
                    }while(palavraSelect[i] == 1 || palavraSelect[i] == 2);
                    palavraSelect[i] = 1;
                    palavra = *(palavras + i);
                    if(verificarCruzamentoHorizon(&CP[0][0], dim, palavra, aux) == 0){
                        gerarPalavraHorizontal(&CP[0][0], dim, palavra, aux);
                    }
                }
                i=0;
                for(k=0; k<4; k++){
                    while(palavraSelect[i] == 1 || palavraSelect[i] == 2) i++;
                    palavraSelect[i] = 2;
                    palavra = *(palavras + i);
                    ReverteString(palavra, reversopalavra);
                    if(verificarCruzamentoHorizon(&CP[0][0], dim, reversopalavra, aux) == 0){
                        gerarPalavraHorizontal(&CP[0][0], dim, reversopalavra, aux);
                    }
                }
                zerarArray(aux, dim);
                i=0;
                for(k=0; k<4; k++){
                    while(palavraSelect[i] == 1 || palavraSelect[i] == 2) i++;
                    palavraSelect[i] = 1;
                    palavra = *(palavras + i);
                    if(verificarCruzamentoVertic(&CP[0][0], dim, palavra, aux) == 0){
                        gerarPalavraVertical(&CP[0][0], dim, palavra, aux);
                    }
                }
                i=0;
                for(k=0; k<4; k++){
                    while(palavraSelect[i] == 1 || palavraSelect[i] == 2) i++;
                    palavraSelect[i] = 2;
                    palavra = *(palavras + i);
                    ReverteString(palavra, reversopalavra);
                    if(verificarCruzamentoVertic(&CP[0][0], dim, reversopalavra, aux) == 0){
                        gerarPalavraVertical(&CP[0][0], dim, reversopalavra, aux);
                    }
                }
                vizualizar = 1;
                PreencherCacaPalavras(&CP[0][0], dim);
                ImprimirMatriz(&CP[0][0], dim);
                break;
            case 2:
                    if(vizualizar) {
                        printf("          \n            RESPOSTA DO CACA-PALAVRA \n");
                        MatrizVazia(&copiaCP[0][0], dim);
                        for(k=0; k<20; k++){
                            palavra = *(palavras + k);
                            if(palavraSelect[k] == 2) {
                                ReverteString(palavra, reversopalavra);
                                EncontrarPalavraCP(&CP[0][0], dim, reversopalavra, &copiaCP[0][0]);
                            }
                            else EncontrarPalavraCP(&CP[0][0], dim, palavra, &copiaCP[0][0]);
                        }
                        ImprimirMatrizColorida(&CP[0][0], dim, &copiaCP[0][0]);
                    } else printf("\n  AVISO: GERE UM CACA-PALAVRA PRIMEIRAMENTE \n ");
                    break;
            case 3: break;
        }
        printf("\n");
        system("pause");
    } while(op!=3);
    return(0);
}




