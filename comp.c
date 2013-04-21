/**
@brief UCS-Universidade de Caxias do Sul
@brief CARVI - Campus Universitario da Regiao dos Vinhedos
@author Daniel Costi  
@Date 21/04/2013
@brief Programa relativo a tarefa 1
*/

#include <stdio.h>
#include <math.h>

#define tv 4	///Define a quantidade de numeros que serao usados para as operacoes

///@brief Declaracao das funcoes utilizadas: 
int *ordenar (int *vi);
int *entrada (void);
void calculos (int *vec); 

///@brief Funcao que tem por objetivo ordenar os numeros recebidos pelo ponteiro vi
int *ordenar (int *vi) {

        int tmp=0;
        int j, k, m;
        int ordenado [tv];
        int pula [tv];
        int *s;

	///Inicializa vetor ordenado com valor m ximo para int com sinal, e
        ///inicializa vetor pula com valor 50...
        for (m=0;m<tv;m++) {
                ordenado [m]= 2147483646;
                pula [m] = 50;
	}

        for (j=0;j<tv;j++) {
                m=0;
                while (m<tv) {
                        for (k=0;k<tv;k++) {
                                if (m==pula[k]) {
                                        m++;
                                        tmp=1;
                                }
                        }

                        if (tmp==0) {
                                if ( *(vi+m) < ordenado[j]) {
                                        ordenado[j]=*(vi+m);
                                        pula[j]=m;
                                }
                                m++;
			}
                        tmp = 0;
                 }
        }
        s=&ordenado[0];
        return s;	///@return Retorna ponteiro do vetor com os numeros ordenados
}

///@brief Funcao que tem por objetivo solicitar ao usuario digitar numeros para posterior processamento
int *entrada (void) {

	int num;
	char term;
	int i=0;
	int vig[tv];
	int *j;

	system ("clear");

	while (i<tv) {

      		system ("clear");
		printf ("\nDigite um numero inteiro: ");
	
		if(scanf("%d%c", &num, &term) != 2 || term != '\n') {	///@brief Detectado carateres não numericos...
    			printf (" *** Caracter(es) Invalido(s) *** ");
			getchar();
		}
		else {							///@brief Inteiro valido, seguido pelo pressionamento da tecla <Enter>...
        		vig[i]=num;
			++i;
			system ("clear");
        	}
	}

	printf ("\nMostrando os numeros digitados: \n");
	for (i=0;i<tv;i++) {
	        printf ("Número %d armazenado no vetor vig[%d].\n",vig[i],i);
	}
	
	j=&vig[0];
	return j; 	///@return Retorna ponteiro do vetor com os numeros digitados pelo usuario
}

///@brief Funcao que tem por objetivo efetuar os calculos necessarios com o vetor de numeros ja ordenados
void calculos (int *vec) {

	int vetr[tv];
	int i;
	double media, tmp2, vari=0;
	long somat=0;

	///@brief transfere vetor ordenado para vetr, atraves de incremento posicao do ponteiro recebido...
	for (i=0;i<tv;i++) {
		vetr[i]=*vec++;
	}

      	///@brief Exibindo os numeros de forma ordenada, crescente, utilizando o loop para calculo de media:
        for (i=0;i<tv;i++) {
        	printf ("Valor armazenado: %d , [%d]\n",vetr[i],i);
		somat=somat+vetr[i];
        }

	tmp2 = somat;		///@brief Se for feito divisao entre inteiros, perde-se a parte fracionaria. Transferindo p/ double
	media = tmp2/tv;	

	///Calculo da variancia...

        for (i=0;i<tv;i++) {
		tmp2=pow((vetr[i]-media),2);	///@brief Operacao ^2 nao funciona! Usa-se pow(x,y)!	
		vari=vari+tmp2;		
        }	
	vari=vari/tv;	

	///@brief Exibindo os valores de soma total, media, desvio padrao populacional e variancia populacional:
	printf ("Soma total: %li\n",somat);
	printf ("Media: %a\n",media);
	printf ("Variância populacional: %f\n",vari);
	printf ("Desv. padrao populacional: %f\n",sqrt(vari));
}


///@brief Funcao principal (main)
///@param Os parametros desta funcao nao sao utilizados
int main(int argc, char** argv) {
	
	int *entra;
	int *pronto;
	int vx[tv];
	int i;

	///@brief Solicita dados ao usuario...
	entra = entrada ();
	
	///@brief Repassando os valores para vetor vx pois, pois, direto com ponteiro, não funcionou...
	for (i=0;i<tv;i++) {
		vx[i]=*entra++;
	}

	///@brief Ordenando em ordem crescente, resultado no ponteiro pronto:
        pronto = ordenar (&vx[0]);

	///@brief Calculando media, variancia e desvio padrao, mostrando resultados:
	calculos (pronto);
}

	









