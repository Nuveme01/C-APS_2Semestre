#include <stdio.h>

int A[2097152];

int main(void){
	FILE *arq, *arqO;
	int i, j, memoria, tamanho;
	
	//Arquivo é aberto aqui
	arq = fopen("TesteAPS-1.txt","r");
	
	//Criamos uma condição pra caso houver falha na abertura do arquivo
	if (arq == NULL){
		//Retorna 1 se não conseguir abrir o arquivo
		printf("Erro ao abrir arquivo");
		return 1;
	}
	
	//inicializamos a variável tamanho em 0
	tamanho = 0;
	
	//Variavel tamanho utilizada pra determinar o tamanho do array
	while(!feof(arq)){
		fscanf(arq ,"%d", &A[tamanho]);
		tamanho++;
	}
	
	//tamanho--, pois quando ocorre a última passada no for acima ela fica com uma posição a mais do q o tamanho do array
	tamanho--;
	
	//Primeiro for mantém a primeira instância do array estável
	//enquanto o segundo for escaneia e vê qual o menor e efetua a troca
	for(i=0; i<tamanho; i++){
		//For que se movimenta enquanto o primeiro fica parado
		for(j=0; j<tamanho; j++){
			if(A[j] > A[i]){
				memoria = A[i];
				A[i] = A[j];
				A[j] = memoria;
			}
		}
	}
	
	//Aqui é dado o nome do output do arquivo
	arqO = fopen("Números Organizados.txt", "w");
	
	//For utilizado para imprimir o array no arquivo de output
	for(i=0; i<tamanho; i++){
		fprintf(arqO, "%d\n", A[i]);
	}
	
	//Fechamento de ambos os arquivo
	//Tanto o usado apenas pra input tanto quanto o de output
	fclose(arq);
	fclose(arqO);
	
	//Apenas uma demonstração visual para o usuário
	//Que o pragram terminou com sucesso
	printf("\nProgram's End\n");
	
	//Retorna 0 se tudo der certo
	return 0;
}
