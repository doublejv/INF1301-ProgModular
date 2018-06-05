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

#define DEIXA_VIRA 0
#define TIRA_VIRA 1

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
*  Fun��o: MES  &Criar lixo
***************************************************************************/
LIS_tppLista MES_CriarLixo() {

	//criando ponteiro pra cabeca da lista mao
	LIS_tppLista pCabecaLixo = LIS_CriarLista (BAR_DestruirCarta) ;

	//assertiva de sa�da
	#ifdef _DEBUG
		assert( pCabecaLixo != NULL ) ;
	#endif

	return pCabecaLixo ;

} /***************** Fim fun��o: MES &Criar lixo ***********************/

/***************************************************************************
*  Fun��o: MES  &Distribuir maos
***************************************************************************/
void MES_DistribuirMaos(LIS_tppLista pCabecaSuperior, int qtdJogadores) {

	LIS_tppLista pCabecaBaralho = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao1 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao2 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao3 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao4 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao5 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao6 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;

	if (qtdJogadores == 2) {
		LIS_IrInicioLista(pCabecaSuperior) ;
		pCabecaBaralho = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao1 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao2 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
	} //fim if
	
	else if (qtdJogadores == 4) {
		LIS_IrInicioLista(pCabecaSuperior) ;
		pCabecaBaralho = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao1 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao2 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao3 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao4 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
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
		LIS_IrInicioLista(pCabecaSuperior) ;
		pCabecaBaralho = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao1 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao2 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao3 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao4 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao5 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao6 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
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
*  Fun��o: MES  &Distribuir maos para testar empates
***************************************************************************/
void MES_DistribuirMaosParaTestarEmpates(LIS_tppLista pCabecaSuperior, int qtdJogadores) {

	LIS_tppLista pCabecaBaralho = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;

	LIS_tppLista pCabecaMao1 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao2 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao3 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao4 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao5 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao6 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;

	switch (qtdJogadores) {

	case 2:

		LIS_IrInicioLista(pCabecaSuperior) ;
		pCabecaBaralho = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao1 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao2 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;

		LIS_IrInicioLista(pCabecaBaralho) ;

		//preenche a mao 1
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;

		//preenche a mao 2
		LIS_AvancarElementoCorrente(pCabecaBaralho, 7) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;

		LIS_IrInicioLista(pCabecaBaralho) ;

		break;
	
	case 4:

		LIS_IrInicioLista(pCabecaSuperior) ;
		pCabecaBaralho = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao1 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao2 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao3 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao4 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;

		LIS_IrInicioLista(pCabecaBaralho) ;

		//preenche a mao 1
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;

		//preenche a mao 2
		LIS_AvancarElementoCorrente(pCabecaBaralho, 7) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;

		//preenche a mao 3
		LIS_AvancarElementoCorrente(pCabecaBaralho, 8) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao3) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao3) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao3) ;

		//preenche a mao 4
		LIS_AvancarElementoCorrente(pCabecaBaralho, 8) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao4) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao4) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao4) ;

		LIS_IrInicioLista(pCabecaBaralho) ;
		break;
	
	case 6:

		LIS_IrInicioLista(pCabecaSuperior) ;
		pCabecaBaralho = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao1 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao2 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao3 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
		LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
		pCabecaMao4 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;

		LIS_IrInicioLista(pCabecaBaralho) ;

		//preenche a mao 1
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao1) ;

		//preenche a mao 2
		LIS_AvancarElementoCorrente(pCabecaBaralho, 7) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao2) ;

		//preenche a mao 3
		LIS_AvancarElementoCorrente(pCabecaBaralho, 8) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao3) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao3) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao3) ;

		//preenche a mao 4
		LIS_AvancarElementoCorrente(pCabecaBaralho, 8) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao4) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao4) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao4) ;

		//preenche a mao 5
		LIS_IrInicioLista(pCabecaBaralho) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 4) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao5) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao5) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao5) ;

		//preenche a mao 6
		LIS_AvancarElementoCorrente(pCabecaBaralho, 14) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao6) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao6) ;
		LIS_AvancarElementoCorrente(pCabecaBaralho, 1) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaMao6) ;

		LIS_IrInicioLista(pCabecaBaralho) ;
		break;

	} //fim switch

} /***************** Fim fun��o: MES &Distribuir maos ***********************/

/***************************************************************************
*  Fun��o: &Esvaziar mesa
***************************************************************************/
void MES_EsvaziarMesa (LIS_tppLista pCabecaMesa, LIS_tppLista pCabecaLixo, int tipo) {

	switch (tipo) {

	case TIRA_VIRA:

		while (LIS_ObterQtdElem(pCabecaMesa) > 0) {
			LIS_IrFinalLista(pCabecaMesa) ;
			BAR_TransferirCarta(pCabecaMesa, pCabecaLixo) ;
		} //fim while
		break;

	case DEIXA_VIRA:

		while (LIS_ObterQtdElem(pCabecaMesa) > 1) {
			LIS_IrFinalLista(pCabecaMesa) ;
			BAR_TransferirCarta(pCabecaMesa, pCabecaLixo) ;
		} //fim while
		break;

	} //fim switch

} /******* fim fun��o EsvaziaMesa*********/

/***************************************************************************
*  Fun��o: &Transferir todas cartas pro lixo
***************************************************************************/
void MES_TransferirTodasCartasProLixo (LIS_tppLista pCabecaSuperior) {

	LIS_tppLista pCabecaBaralho = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao1 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao2 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao3 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao4 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao5 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMao6 = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaLixo = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;
	LIS_tppLista pCabecaMesa = (LIS_tppLista)malloc(sizeof(LIS_tppLista)) ;

	LIS_IrInicioLista(pCabecaSuperior) ;
	pCabecaBaralho = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
	LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
	pCabecaMao1 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
	LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
	pCabecaMao2 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
	LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
	pCabecaMao3 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
	LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
	pCabecaMao4 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
	LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
	pCabecaMao5 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
	LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
	pCabecaMao6 = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
	LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
	pCabecaLixo = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;
	LIS_AvancarElementoCorrente(pCabecaSuperior, 1) ;
	pCabecaMesa = (LIS_tppLista)LIS_ObterValor(pCabecaSuperior) ;

	while (LIS_ObterQtdElem(pCabecaBaralho) > 0) {
		LIS_IrFinalLista(pCabecaBaralho) ;
		BAR_TransferirCarta(pCabecaBaralho, pCabecaLixo) ;
	}

	while (LIS_ObterQtdElem(pCabecaMao1) > 0) {
		LIS_IrFinalLista(pCabecaMao1) ;
		BAR_TransferirCarta(pCabecaMao1, pCabecaLixo) ;
	}

	while (LIS_ObterQtdElem(pCabecaMao2) > 0) {
		LIS_IrFinalLista(pCabecaMao2) ;
		BAR_TransferirCarta(pCabecaMao2, pCabecaLixo) ;
	}

	while (LIS_ObterQtdElem(pCabecaMao3) > 0) {
		LIS_IrFinalLista(pCabecaMao3) ;
		BAR_TransferirCarta(pCabecaMao3, pCabecaLixo) ;
	}

	while (LIS_ObterQtdElem(pCabecaMao4) > 0) {
		LIS_IrFinalLista(pCabecaMao4) ;
		BAR_TransferirCarta(pCabecaMao4, pCabecaLixo) ;
	}

	while (LIS_ObterQtdElem(pCabecaMao5) > 0) {
		LIS_IrFinalLista(pCabecaMao5) ;
		BAR_TransferirCarta(pCabecaMao5, pCabecaLixo) ;
	}

	while (LIS_ObterQtdElem(pCabecaMao6) > 0) {
		LIS_IrFinalLista(pCabecaMao6) ;
		BAR_TransferirCarta(pCabecaMao6, pCabecaLixo) ;
	}

	while (LIS_ObterQtdElem(pCabecaMesa) > 0) {
		LIS_IrFinalLista(pCabecaMesa) ;
		BAR_TransferirCarta(pCabecaMesa, pCabecaLixo) ;
	}

}


/***********  C�DIGO DAS FUN��ES ENCAPSULADAS NO M�DULO  *******************/
//ainda nao ha funcoes encapsuladas no modulo

/************ FIM DO M�DULO DE IMPLEMENTA��O: MES Mesa ******************/
