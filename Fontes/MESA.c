/***************************************************************************
*  $MCI M�dulo de implementa��o: MES  Mesa
*
*  Arquivo gerado:              MESA.c
*  Letras identificadoras:      MES
*
*  Projeto: INF 1301 Jogo de Truco
*  Autores: gsc, jvr, tgf
*
*  $HA Hist�rico de evolu��o:
*  Vers�o  		Autor  			Data    	Observa��es
*     1     gsc, jvr, tgf    11/mai/2018    in�cio desenvolvimento
***************************************************************************/

#include   <stdio.h>	//printf
#include   <stdlib.h>	//malloc, free
#include   <assert.h>	//assert

#define MESA_OWN
#include "MESA.h"
#include "BARALHO.h"
#include "LISTA.h"

#undef MESA_OWN


/************ PROT�TIPOS DAS FUN��ES ENCAPSULADAS NO M�DULO ***************/
//ainda nao ha funcoes encapsuladas no modulo


/***********  C�DIGO DAS FUN��ES EXPORTADAS PELO M�DULO  ******************/

/***************************************************************************
*  Fun��o: MES  &Criar mesa
***************************************************************************/
LIS_tppLista MES_CriarMesa() {

	//criando ponteiro pra cabeca da lista mesa
	LIS_tppLista pCabecaMesa = LIS_CriarLista (BAR_DestruirCarta) ;

	//assertiva de sa�da
	#ifdef _DEBUG
		assert( pCabecaMesa != NULL ) ;
	#endif

	return pCabecaMesa ;

} /***************** Fim fun��o: MES &Criar lista***********************/

/***************************************************************************
*  Fun��o: MES  &Criar mao
***************************************************************************/
LIS_tppLista MES_CriarMao() {

	//criando ponteiro pra cabeca da lista mao
	LIS_tppLista pCabecaMao = LIS_CriarLista (BAR_DestruirCarta) ;

	//assertiva de sa�da
	#ifdef _DEBUG
		assert( pCabecaMao != NULL ) ;
	#endif

	return pCabecaMao ;

} /***************** Fim fun��o: MES &Criar mao ***********************/

/***************************************************************************
*  Fun��o: MES  &Distribuir maos
***************************************************************************/
void MES_DistribuirMaos(LIS_tppLista pCabecaBaralho, 
						LIS_tppLista pCabecaMao1, 
						LIS_tppLista pCabecaMao2, 
						LIS_tppLista pCabecaMao3, 
						LIS_tppLista pCabecaMao4, 
						LIS_tppLista pCabecaMao5, 
						LIS_tppLista pCabecaMao6, 
						int numJogadores) {

	if (numJogadores == 2) {
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
	} //fim if
	
	else if (numJogadores == 4) {
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao3) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao3) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao3) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao4) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao4) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao4) ;	
	} //fim else if
	
	else {
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao3) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao3) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao3) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao4) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao4) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao4) ;	
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao5) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao5) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao5) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao6) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao6) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao6) ;
	} //fim else

} /***************** Fim fun��o: MES &Distribuir maos ***********************/

/***************************************************************************
*  Fun��o: MES  &Obter valor manilha
***************************************************************************/
int MES_ObterValorManilha (LIS_tppLista pCabecaMesa) {

	int valor, valorManilha ;
	BAR_tppCarta pCarta ;

	LIS_IrInicioLista(pCabecaMesa) ;

	pCarta = BAR_ObterCartaCorr(pCabecaMesa) ;

	//assertiva de sa�da
	if (pCarta == NULL) {
		return -10;
	}

	valor = BAR_ObterValor(pCarta) ;

	if (valor == 9) {
		valorManilha = 0 ;
	}
	else {
		valorManilha = valor+1 ;
	}

	return valorManilha ;
} /************ Fim fun��o: MES &Obter Valor Manilha ********************/


/***********  C�DIGO DAS FUN��ES ENCAPSULADAS NO M�DULO  *******************/
//ainda nao ha funcoes encapsuladas no modulo

/************ FIM DO M�DULO DE IMPLEMENTA��O: MES Mesa ******************/
