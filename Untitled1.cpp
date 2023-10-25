#include <stdio.h>
#include <stdlib.h>

//declara constante
const int MODULO = 3;

struct no {
	int numero;
	struct no *proximoNo;
};

struct diretor {
	int resto;
	struct no *proximoNo;
	struct diretor *proximoDiretor;
};

//declaracao de variaveis

struct diretor *cabeca = NULL;

//funcao procura o diretor

struct diretor *procurarDiretor(int resto) {
	struct diretor *ponteiro = cabeca;
	// varrendo a lista ate o final ou chegar no final
	while((ponteiro != NULL) && (ponteiro -> resto != resto)){
		ponteiro = ponteiro -> proximoDiretor;
	}
	if (ponteiro == NULL) {
		//criar um diretor novo
		ponteiro = (struct diretor*) malloc(sizeof(struct diretor));
		ponteiro -> resto = resto;
		ponteiro -> proximoNo = NULL;
		ponteiro -> proximoDiretor = cabeca;
		cabeca = ponteiro;
	}
	return ponteiro;
}

//funcao que insere um no na matriz esparsa

void inserir(int numero) {
	struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximoNo = ponteiroDiretor -> proximoNo;
	ponteiroDiretor -> proximoNo = novoNo;
}

//funcao que imprime a matriz esparsa

void imprimir() {
	struct diretor *ponteiroDiretor = cabeca;
	while (ponteiroDiretor != NULL) {
		struct no *ponteiroNo = ponteiroDiretor -> proximoNo;
		
		printf("%d:\t", ponteiroDiretor -> resto);
		while (ponteiroNo != NULL) {
			printf("%d\t", ponteiroNo -> numero);
			ponteiroNo = ponteiroNo -> proximoNo;
		}
		printf("\n");
		ponteiroDiretor = ponteiroDiretor -> proximoDiretor;
	}
}

//funcao remover

void remover(int numero){
	struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);
	if (ponteiroDiretor -> proximoNo != NULL) {
		
		if (ponteiroDiretor -> proximoNo -> numero == numero) {
			//caso faciç, excluir o proimeiro da lista
			struct no *ponteiroExcluit = ponteiroDiretor -> proximoNo;
			ponteiroDiretor -> proximoNo = ponteiroDiretor-> proximoNo -> proximoNo;
			free(ponteiroExcluir);
		}
	}else {
		//caso dificil, excluir algum no meio da lista
		struct no *ponteiroAnterior = ponteiroDiretor -> proximoNo;
		while ((ponteiroAnterior -> proximoNo != NULL)&& (ponteiroAnteiror -> proximoNo -> numero != numero)) {
			ponteiroAnteiror = ponteiroAnteiror -> proximoNo;
		}
		if (pobteiroAnterior -> proximoNo != NULL) {
			struct no *ponteiroExcluir = ponteiroAnterior -> proximoNo;
			ponteiroAnterior -> proximoNo = ponteiroExcluir -> proximoNo;
			free(ponteiroExcluir);
		}
	}
}

//funcao de execucao

int main(){
	int i = 0;
	time_t t;
	int numero = 0;
	srand((unsigned) time(&t));
	for (i = 0; i < 10; i++) {
		inserir(rand());
	}
	imprimir();
	printf("Digite um numero para excluir: ");
	scanf("%d", &numero);
	remover(numero);
	imprimir();
}
