#include <stdio.h>

int A[2097152], B[1048576], C[1048576], D[1048576];

int main(void){
	int mr, mb, i, j, k, L, memoria, tamanho;
	FILE *arq;
	
	//Abetura do arquivo de leitura
	arq = fopen("TesteAPS-3.txt", "r");
	
	//Criamos uma condição pra caso houver falha na abertura do arquivo
	if (arq == NULL){
		//Retorna 1 se não conseguir abrir o arquivo
		printf("Erro ao abrir arquivo");
		return 1;
	}
	
	//Inicializamos a var tamanho em 0
	tamanho = 0;
	
	//Variavel tamanho utilizada pra determinar o tamanho do array
	while(!feof(arq)){
		fscanf(arq ,"%d", &A[tamanho]);
		tamanho++;
	}
	
	//Fechamento do arquivo de leitura
	fclose(arq);
	
	//tamanho--, pois quando ocorre a última passada no for acima ela fica com uma posição a mais do q o tamanho do array
	tamanho--;
	
	//For utilizado para prencher o array B(Array dos ratos)
	for(i=0;i<tamanho/2;i++){
		B[i]=A[i];
	}
	
	//Inicializamos a var j em 0
	j=0;
	
	//For utilizado para preencher o array C(Array dos ratos)
	for(i=tamanho/2;i<tamanho;i++){
		C[j]=A[i];
		j++;
	}
	
	//For para reorganizar o array dos ratos em ordem crescente
	//O mesmo utilizado no problema 1
	for(i=0; i<tamanho/2; i++){
		for(j=0; j<tamanho; j++){
			if(B[j] > B[i]){
				memoria = B[i];
				B[i] = B[j];
				B[j] = memoria;
			}
		}
	}
	
	//For para reorganizar o array dos buracos em ordem crecente
	//O mesmo utilizado no problema 1
	for(i=0; i<tamanho/2; i++){
		for(j=0; j<tamanho; j++){
			if(C[j] > C[i]){
				memoria = C[i];
				C[i] = C[j];
				C[j] = memoria;
			}
		}
	}
	
	//Inicializamos a variável k em 0
	k=0;
	
	//For usado para comparar o início da array original com a dos ratos reorganizada
	//Pois já que os ratos entraram no mesmo índice de buracos, quando descobrimos a posição
	//Do primeiro rato em B podemos compara com C e descobrir em qual buraco foi usado
	//Pelo primeiro, segundo etc
	for(i=0; i<tamanho/2; i++){
		//For de j utilizado para mover apenas o segundo array
		for(j=0; j<tamanho/2; j++){
			//Se o array primordial e o reorganizado tiverem o mesmo valor,
			//logo D[k] recebe C[j] para organizar a ordem dos buracos
			if (A[i] == B[j]){
				D[k] = C[j];
				k++;
			}
		}
	}
	
	//Abertura do arquivo escrita
	arq = fopen("Ratos e Seus Buracos.txt", "w");
	
	//Inicializamos mr em 0
	mr = 0;
	
	//For pra checar qual o rato que demorou mais, pra poder mostrar
	//o tempo máximo
	for(i=0;i<tamanho/2;i++){
		mb = B[i] - C[i];
		//Aqui caso mb seja negativo, ele é multiplicado por -1 pra remover o sinal
		if(mb < 0){
			mb = mb * -1;
		}
		
		//mr recebe mb se for maior pois assim saberemos o rato q demorou mais tempo
		if (mb > mr){
			mr = mb;
		}
	}
	
	//Output do tempo máximo que os ratos demorariam
	fprintf(arq, "%d\n", mr);
	
	//For usado para demonstra o output dos buracos em ordem q os ratos se esconderam
	for(i=0; i<tamanho/2; i++){
		fprintf(arq, "%d\n", D[i]);
	}
	
	//Fechamento do arquivo de escrita
	fclose(arq);
	
	//Retorna 0 se tudo der certo
	return 0;
}
