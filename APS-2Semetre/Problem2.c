#include <stdio.h>

char A[2097152];

int main(void){
	FILE *arq;
	int K, i, j, L, tamanho;
	
	//Arquivo � aberto aqui para leitura
	arq = fopen("TesteAPS-2.txt","r");
	
	//Criamos uma condi��o pra caso houver falha na abertura do arquivo
	if (arq == NULL){
		printf("Erro ao abrir arquivo");
		return 1;
	}
	
	//K determina a quantidade de casas que um policial pode checar
	//k ser� lido no array abaixo
	fscanf(arq, "%d", &K);
	
	//Var tamanho inicializada em 0;
	tamanho = 0;
	
	//Variavel tamanho utilizada pra determinar o tamanho do array
	while(!feof(arq)){
		fscanf(arq ," %c", &A[tamanho]);
		tamanho++;
	}
	
	//tamanho--, pois quando ocorre a �ltima passada no for acima ela fica com uma posi��o a mais do q o tamanho do array
	tamanho--;
	
	//For utilizado pra pegar o array do arquivo
	for(i=0; i<tamanho; i++){
		fscanf(arq, " %c", &A[i]);
	}
	
	//Inicializamos o L em 0 pois ela � nosso controle
	//De quantos ladr�es foram pegos
	L=0;

	//Iniciamos um for para percorrer todos os policiais do array
	for(i=0; i<=tamanho; i++){
		//Condicional pra caso o for acima encontrar um policial
		if (A[i] == 'P'){
			//for utilizado para ver se existem ladr�es no determinado n�mero
			//De casas ao redor do policial em quest�o
			for(j=K; j > 0; j--){
				//Se houver um ladr�o a atr�s L incrementa e T vira F
				//Para n�o haver confus�o entre os policiais sobre quem foi preso ou n�o
				//j recebe 0 para finalizar esse for e ir para o pr�ximo policial
				if (A[i - j] == 'T'){
					L = L + 1;
					A[i - j] = 'F';
					j=0;
				}
				//Mesmo caso acima, mas esse checa uma casa a frente
				else if (A[i + j] == 'T'){
					L = L + 1;
					A[i + j] = 'F';
					j=0;
				}
			}
		}
	}
	printf("Presos: %d\n", L);
	//fechamento do arquivo de leitura
	fclose(arq);
	
	//Abertura do arquivo de escrita
	arq = fopen("Resultado presos.txt", "w");
	
	//Escrita no arquivo de output
	fprintf(arq ,"Total de presos: %d", L);
	
	//Fechamento do arquivo de escrita
	fclose(arq);
	
	//Retorna 0 se tudo der certo
	return 0;
}

