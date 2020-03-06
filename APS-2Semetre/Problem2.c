#include <stdio.h>

char A[2097152];

int main(void){
	FILE *arq;
	int K, i, j, L, tamanho;
	
	//Arquivo é aberto aqui para leitura
	arq = fopen("TesteAPS-2.txt","r");
	
	//Criamos uma condição pra caso houver falha na abertura do arquivo
	if (arq == NULL){
		printf("Erro ao abrir arquivo");
		return 1;
	}
	
	//K determina a quantidade de casas que um policial pode checar
	//k será lido no array abaixo
	fscanf(arq, "%d", &K);
	
	//Var tamanho inicializada em 0;
	tamanho = 0;
	
	//Variavel tamanho utilizada pra determinar o tamanho do array
	while(!feof(arq)){
		fscanf(arq ," %c", &A[tamanho]);
		tamanho++;
	}
	
	//tamanho--, pois quando ocorre a última passada no for acima ela fica com uma posição a mais do q o tamanho do array
	tamanho--;
	
	//For utilizado pra pegar o array do arquivo
	for(i=0; i<tamanho; i++){
		fscanf(arq, " %c", &A[i]);
	}
	
	//Inicializamos o L em 0 pois ela é nosso controle
	//De quantos ladrões foram pegos
	L=0;

	//Iniciamos um for para percorrer todos os policiais do array
	for(i=0; i<=tamanho; i++){
		//Condicional pra caso o for acima encontrar um policial
		if (A[i] == 'P'){
			//for utilizado para ver se existem ladrões no determinado número
			//De casas ao redor do policial em questão
			for(j=K; j > 0; j--){
				//Se houver um ladrão a atrás L incrementa e T vira F
				//Para não haver confusão entre os policiais sobre quem foi preso ou não
				//j recebe 0 para finalizar esse for e ir para o próximo policial
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

