#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/Constants.h"
#include "modules/FileManager.h"
#include "modules/Numbers.h"

/* 

Descrição: desenvolver um programa em C que implemente as funcionalidades abaixo utilizando funções recursivas.

O programa deverá:


- Criar um arquivo texto e gerar uma sequência aleatória de números separados por “;” (ponto e vírgula).O usuário deverá inserir quantos números deseja gerar no arquivo (no mínimo 100 números).

- Após a geração do arquivo, o programa deverá ter uma função para carregar o arquivo. Ao carregar o arquivo, o programa deverá armazenar os valores em um array. 

- O programa também deverá possuir as seguintes funcionalidades, após a execução das etapas anteriores: 
    - opção para inversão dos elementos do arquivo (ou seja, o programa deverá ter uma função de gerar um novo arquivo com os elementos invertidos).
    - opção de geração de um novo arquivo com os elementos ordenados.
    - opção de geração de um novo arquivo com o maior e o menor número encontrado no arquivo e a média de todos os números do arquivo.
    - opção de geração de um novo arquivo em que cada número do arquivo original é convertido para binário.

*/

int main(int argc, char *argv[]) {
	int command;

    int numbersLoaded[500] = {0};

	// Draw main menu
	while (1 == 1) {
		system("cls");
		printf("Numeros Aleatorios\n");
		printf("1 - Gerar\n");
		printf("2 - Ler arquivo\n");
		printf("3 - Gerar arquivo invertido\n");
		printf("4 - Gerar arquivo ordenado\n");
		printf("5 - Gerar arquivo maior/menor/media\n");
		printf("6 - Gerar arquivo com binarios\n");
		printf("7 - Exibir dados carregados\n");

		printf("0 - Exit\n");
		
		// Read user input
		fflush(stdin);
		printf("\nDigite a opcao: ");
		scanf("%d", &command);

		int amount;
		
		int bigger = -9999;
		int smaller = 9999;
		int sum = 0;
		int numOfNumbers = 0;
		char formatted[20] = {0};

        // Handle user input
		switch(command) {
			case 1:
				// Generate file
        
                // Read user input
                fflush(stdin);
                printf("\nDigite quantos numeros devem ser gerados: ");
                scanf("%d", &amount);

                generateFile(amount);
			    break;
			case 2:
				// Read file
                readFile(numbersLoaded);
			    break;
			case 3:
				// Generate inverted file
				reverse(numbersLoaded);
			    break;
			case 4:
				// Generate sorted file
				break;
			case 5:
				// Generate file with bigger, smaller and average
				

				for (int i = 0; i < sizeof(numbersLoaded) / sizeof(int); i++) {
					if (numbersLoaded[i] == NUMBERS_LOADED_END)
						break;

					if (numbersLoaded[i] > bigger)
						bigger = numbersLoaded[i];

					if (numbersLoaded[i] < smaller)
						smaller = numbersLoaded[i];

					sum += numbersLoaded[i];
					numOfNumbers++;
				}

				sprintf(formatted, "%d;%d;%f;", bigger, smaller, sum / numOfNumbers);
				replaceFileWithString(formatted);

			    break;
			case 6:
				// Generate file with binary values
				fflush(stdin);
                printf("\nDigite quantos numeros devem ser gerados: ");
                scanf("%d", &amount);

                generateBinaryFile(amount);
			    break;
			case 7:
				// Display values
                // Print out all the lines
                for (int i = 0; i < sizeof(numbersLoaded) / sizeof(int); i++) {
					if (numbersLoaded[i] == NUMBERS_LOADED_END)
						break;

                    printf("%d\n", numbersLoaded[i]);
                }
			    break;
			case 0:
				return 0;
			    break;
			default:
				break;
		}
		
		system("PAUSE");
	}
	
	return 0;
}