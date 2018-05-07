/***************************************************************************
*  $MCI Módulo de implementação: TBAR Teste baralho
*
*  Arquivo gerado:              TestBAR.c
*  Letras identificadoras:      TBAR
*
*  Projeto: INF 1301 - Jogo de Truco
*  Autores: gsc, tgf, jvr
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       avs   26/abr/2018 início desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Lista.h"
#include    "Baralho.h"


static const char RESET_BARALHO_CMD     [ ] = "=resetteste"       ;
static const char CRIAR_BARALHO_CMD     [ ] = "=criarbaralho"     ;
static const char DESTRUIR_BARALHO_CMD  [ ] = "=destruirbaralho"  ;
static const char CRIAR_CARTA_CMD       [ ] = "=criarcarta"       ;
static const char DESTRUIR_CARTA_CMD    [ ] = "=destruircarta"    ;
static const char OBTER_NAIPE_CMD		[ ] = "=obternaipe"		  ;
//static const char OBTER_NAIPE_CMD		[ ] = "=obternaipe"		  ;


#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_BARALHO   10
#define DIM_VT_CARTA  40

LIS_tppLista vtBaralhos[ DIM_VT_BARALHO ] ;
BAR_tppCarta vtCartas[ DIM_VT_CARTA ] ;

/************* PROTÓTIPOS DAS FUNÇÕES ENCAPSULADAS NO MÓDULO **************/
   static int ValidarInxBaralho( int inxBaralho, int Modo ) ;
   static int ValidarInxCarta( int inxCarta, int Modo ) ;

/**************  CÓDIGO DAS FUNÇÕES EXPORTADAS PELO MÓDULO  ***************/

/***************************************************************************
*  $FC Função: TBAR &Testar baralho
*
*  $ED Descrição da função
*     Podem ser criados até 10 baralhos guardados em um vetor, 
*     identificados pelos índices 0 a 9
*     Podem ser criadas até 40 cartas guardadas em um vetor, 
*     identificadas pelos índices 0 a 39
*
*     Comandos disponíveis:
*
*     =resetteste
*       - anula os vetores de baralhos e testes e provoca vazamento de memória.
*     =criarbaralho                 <inxBaralho>
*	- retorna um ponteiro pra cabeça do baralho
*	  que é armazenado no vtBaralhos.
*     =destruirbaralho              <inxBaralho>
*     =criarcarta                   <int>  <int> 
*	- retorna um ponteiro pra tipo carta
*	  que é armazenado no vtCartas.
*     =destruircarta                <inxCarta>   
*     =obternaipe		    <inxCarta>
*	- para o comando ter sucesso é necessário ter um
*	  ponteiro pra um tipo carta armazenado no vtCartas
*	  (deve-se usar o comando criarcarta antes).
***************************************************************************/

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )  {
  
  //VARIÁVEIS USADAS PELOS COMANDOS
  int inxBaralho  = -1 ,
	  inxCarta = -1 ,
      numLidos   = -1 ,
      CondRetEsp = -1 ;
  int ValEsp = -1 ;
  int i ;
  int numElem = -1 ;

  BAR_tpValorCarta valor;
  BAR_tpNaipeCarta naipe;

  BAR_tppCarta pCarta;

  BAR_tpValorCarta *pValorCarta = (BAR_tpValorCarta*)malloc(sizeof(BAR_tpValorCarta)) ;
  BAR_tpNaipeCarta *pNaipeCarta = (BAR_tpNaipeCarta*)malloc(sizeof(BAR_tpNaipeCarta));

  //RESET TEST
  //se o comando for "resettest":
  if ( strcmp( ComandoTeste ,	 RESET_BARALHO_CMD ) == 0 )  {

    //preenche o vetor baralhos com Null
    for( i = 0 ; i < DIM_VT_BARALHO ; i++ ) {
               vtBaralhos[ i ] = NULL ;
    }

    //preenche o vetor cartas com Null
	for( i = 0 ; i < DIM_VT_CARTA ; i++ ) {
			   vtCartas[ i ] = NULL ;
    }

    return TST_CondRetOK ;
  } //fim ativa: Efetuar reset de teste de baralho

  //CRIAR BARALHO
  //se o comando for "criarbaralho"
  else if ( strcmp( ComandoTeste , CRIAR_BARALHO_CMD ) == 0 ) {

    //conta quantos parametros foram declarados
    numLidos = LER_LerParametros( "i" , &inxBaralho ) ;

    //se for diferente de 1 retorna erro de declaração de parametro
    if ( (numLidos != 1) || (! ValidarInxBaralho( inxBaralho , VAZIO )) )  {
      return TST_CondRetParm ;
    }//fim if

    //criarbaralho retorna ponteiro pra tpLista
    vtBaralhos[ inxBaralho ] = BAR_CriarBaralho( ) ;

    //retorna TST_CondRetErro se os dois ponteiros forem diferentes
    //retorna TST_CondRetOK se os dois ponteiros forem iguais
    //0 = ponteiro Null   //1 = ponteiro não-Null
    return TST_CompararPonteiroNulo( 1 , vtBaralhos[ inxBaralho ] ,
                              "Erro em ponteiro de nova lista."  ) ;

  } //fim ativa: Testar CriarBaralho

  //DESTRUIR BARALHO
  //se o comando for "destruirbaralho"
  else if ( strcmp( ComandoTeste , DESTRUIR_BARALHO_CMD ) == 0 ) {

    //conta quantos parametros foram declarados
    numLidos = LER_LerParametros( "i" , &inxBaralho ) ;

    //se for diferente de 1 retorna erro de declaração de parametro
    if ( (numLidos != 1) || (! ValidarInxBaralho( inxBaralho , NAO_VAZIO )) )  {
      return TST_CondRetParm ;
    }//fim if

	BAR_DestruirBaralho( vtBaralhos[ inxBaralho ] ) ;
    vtBaralhos[ inxBaralho ] = NULL ;

    return TST_CondRetOK ;

  } //fim ativa: Testar DestruirBaralho

  //CRIAR CARTA
  //se o comando for "criarcarta"
	else if ( strcmp( ComandoTeste , CRIAR_CARTA_CMD ) == 0 ){
		
		//valor e naipe em tipo específico
		BAR_tpValorCarta ValorCarta ;
		BAR_tpNaipeCarta NaipeCarta ;

		//valor e naipe em int
		int valorCarta, naipeCarta;

		//conta quantos parametros foram declarados
		numLidos = LER_LerParametros( "iii" , &inxCarta, &valorCarta, &naipeCarta ) ;

		//se for diferente de 3 retorna erro de declaração de parametro
        	if ( (numLidos != 3) ){
			return TST_CondRetParm ;
		}

		//validando e transformando o parâmetro
		//int recebido em tipo especifico
		if ( (valorCarta >= 0 && valorCarta <= 9) && (naipeCarta >= 0 && naipeCarta <= 3) ) { 
			ValorCarta = (BAR_tpValorCarta) valorCarta;
			NaipeCarta = (BAR_tpNaipeCarta) naipeCarta;
		} //fim if

		//recebendo um valor e naipe invalidos
		else {
			printf("Erro de parametro invalido") ;
			return TST_CondRetParm ;
		} //fim if

		//armazena em pCarta um ponteiro pra um tipo carta criado
		vtCartas[ inxCarta ] = BAR_CriarCarta( ValorCarta, NaipeCarta ) ;

		return TST_CondRetOK ;

	} //fim ativa: Testar CriarCarta

  //DESTRUIR CARTA
  //se o comando for "destruircarta"
	else if ( strcmp( ComandoTeste , DESTRUIR_CARTA_CMD ) == 0 ) {

    //conta quantos parametros foram declarados
    numLidos = LER_LerParametros( "i" , &inxCarta ) ;

    //se for diferente de 1 retorna erro de declaração de parametro
    if ( (numLidos != 1) || (! ValidarInxCarta( inxCarta , NAO_VAZIO )) )  {
      return TST_CondRetParm ;
    }//fim if

	BAR_DestruirCarta( vtCartas[ inxCarta ] ) ;
    vtCartas[ inxCarta ] = NULL ;

    return TST_CondRetOK ;

  } //fim ativa: Testar DestruirCarta

  //OBTER NAIPE
  //se o comando for "obternaipe"
	else if ( strcmp( ComandoTeste , OBTER_NAIPE_CMD ) == 0 ) {

    //conta quantos parametros foram declarados
    numLidos = LER_LerParametros( "i" , &inxCarta) ;
	
    //se for diferente de 1 retorna erro de declaração de parametro
    if ( (numLidos != 1) || (! ValidarInxCarta( inxCarta , NAO_VAZIO )) ) {
      return TST_CondRetParm ;
    }//fim if

	else if (vtCartas[inxCarta] == NULL) {
		return TST_CondRetErro ;
	}

	naipe = BAR_ObterNaipe (vtCartas[inxCarta]) ;

	if ( naipe < 0 || naipe > 3 ) {
		return TST_CondRetErro ;
	}

    return TST_CondRetOK ;

  } //fim ativa: Testar ObterNaipe*/

return TST_CondRetNaoConhec ;

} /***************** Fim função: TBAR &Testar baralho *********************/


/***************  CÓDIGO DAS FUNÇÕES ENCAPSULADAS NO MÓDULO  **************/

/***************************************************************************
*  $FC Função: TBAR - Validar indice de baralho
***************************************************************************/
int ValidarInxBaralho( int inxBaralho, int Modo ){

	if ( ( inxBaralho <  0 ) || ( inxBaralho >= DIM_VT_BARALHO )){
		return FALSE ;
	} // if
         
    if ( Modo == VAZIO ){
		if ( vtBaralhos[ inxBaralho ] != 0 ){
			return FALSE ;
        } //fim if
	} 
	else{
		if ( vtBaralhos[ inxBaralho ] == 0 ) {
			return FALSE ;
        } //fim if
    } //fim if
         
    return TRUE ;

} /************** Fim função: TBAR &Validar indice baralho ****************/


/***************************************************************************
*  $FC Função: TBAR - Validar indice de carta
***************************************************************************/
int ValidarInxCarta( int inxCarta, int Modo ){

	if ( ( inxCarta <  0 ) || ( inxCarta >= DIM_VT_CARTA )){
		return FALSE ;
	} // if
         
    if ( Modo == VAZIO ){
		if ( vtCartas[ inxCarta ] != 0 ){
			return FALSE ;
        } //fim if
	} 
	else{
		if ( vtCartas[ inxCarta ] == 0 ) {
			return FALSE ;
        } //fim if
    } //fim if
         
    return TRUE ;

} /************** Fim função: TBAR &Validar indice carta ****************/


/********* FIM DO MÓDULO DE IMPLEMENTAÇÃO: TBAR Teste Baralho *************/

