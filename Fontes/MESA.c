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
LIS_tppLista MES_CriarMesa(BAR_tppCarta vtCartas[], int numJogadores) {

	int inx; //indice do vetor
	
	//cria uma lista retornando um ponteiro pra cabeca da lista
	LIS_tppLista pCabecaMesa = LIS_CriarLista (BAR_DestruirCarta) ;

	//declara uma vari�vel que armazena a condi��o de
	//retorno de fun��es de manipula��o da lista
	LIS_tpCondRet condRetLista;

	//declara um ponteiro pra um tipo carta
	BAR_tppCarta pCarta;
	
	switch (numJogadores) {
		case 2: inx = 33; break;
		case 4: inx = 27; break;
		case 6: inx = 21; break;
		default: return NULL;
	}

	//armazena a vira no primeiro elemento da mesa
	pCarta = vtCartas[inx] ;
	
	//� inserido um elemento na lista Baralho e 
	//seu valor � um ponteiro pra um tipo Carta
	condRetLista = LIS_InserirElementoApos (pCabecaMesa, pCarta) ;

	//assertiva de sa�da
	if (condRetLista != LIS_CondRetOK){
		printf("\nN�o inseriu carta no baralho.");
		return NULL;
	}//fim if

	//elemento corrente passa a ser o primeiro
	IrInicioLista(pCabecaMesa) ;

	return pCabecaMesa ;
   
} /******************* Fim fun��o: BAR &Criar mesa *************************/

/***************************************************************************
*  Fun��o: MES  &Criar mao
***************************************************************************//*
LIS_tppLista MES_CriarMao(BAR_tppCarta vtCartas[], int numMao) {

	int inx; //indice do vetor
	
	//cria uma lista retornando um ponteiro pra cabeca da lista
	LIS_tppLista pCabecaMao = LIS_CriarLista (BAR_DestruirCarta) ;

	//declara uma vari�vel que armazena a condi��o de
	//retorno de fun��es de manipula��o da lista
	LIS_tpCondRet condRetLista;

	//declara um ponteiro pra um tipo carta
	BAR_tppCarta pCarta;
	

	//PAREI AQUI FUDEU Q TEM Q PASSAR NUMERO DE JOGADORES E NUMERO DA MAO
	switch (numMao) {
		case 1: inx = 33; break;
		case 2: inx = 27; break;
		case 3: inx = 21; break;
		case 4: inx = 21; break;
		case 5: inx = 21; break;
		case 6: inx = 21; break;
		default: return NULL;
	}

	//armazena a vira no primeiro elemento da mesa
	pCarta = vtCartas[inx] ;
	
	//� inserido um elemento na lista Baralho e 
	//seu valor � um ponteiro pra um tipo Carta
	condRetLista = LIS_InserirElementoApos (pCabecaMesa, pCarta) ;

	//assertiva de sa�da
	if (condRetLista != LIS_CondRetOK){
		printf("\nN�o inseriu carta no baralho.");
		return NULL;
	}//fim if

	//elemento corrente passa a ser o primeiro
	IrInicioLista(pCabecaMesa) ;

	return pCabecaMesa ;
   
} /******************* Fim fun��o: BAR &Criar mesa *************************/


/***********  C�DIGO DAS FUN��ES ENCAPSULADAS NO M�DULO  *******************/
//ainda nao ha funcoes encapsuladas no modulo


/************ FIM DO M�DULO DE IMPLEMENTA��O: BAR Baralho ******************/
