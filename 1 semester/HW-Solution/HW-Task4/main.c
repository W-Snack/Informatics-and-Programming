// Copyright 2021 Fomin Vladimir

/*
* electronnaya cassa
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE  10


void print_menu(){
	printf("To scan the product, press 1\n");
	printf("To get information about the product, press 2\n");
	printf("To add product data to the receipt, press 3\n");
	printf("To calculate the total amount to be paid, press 4\n");
	printf("To display the final receipt, press 5\n");
	printf("To display the menu again, press 6 \n");
	printf("To stop programm, print 0\n");
}

int generateRandomArray(int* array, int size, int min, int max) {
	for (int i = 0; i < size; i++) {
		array[i] = rand() % (max - min + 1) + min;
	}
	return array;
}

int scanProduct(int* array, int size) {
	int bar;
	while (1) {
		printf("Input the barcode of the product: ");
		scanf_s("%d", &bar);
		for (int i = 0; i < size; i++) {
			if (array[i] == bar) {
				printf("The scan was successful\n");
				return i;
			}
		}
		printf("Barcode not found. Please retry\n");
	}
}

	



int main() {
	char products[SIZE][30] = { {"Bread 300g"}, {"Milk 1L"}, {"Butter 250g"}, {"Cheese 300g"}, {"Honey 300g"}, {"Meat 1kg"}, {"Fish 1kg"}, {"Onion 1kg"}, {"Apple 1kg"}, {"Carrot 1kg"} };
	int cost[SIZE] = {20, 60, 80, 120, 125, 300, 250, 15, 50, 30};
	int barcode[SIZE];
	int discount[SIZE];
	int cart[100];
	generateRandomArray(barcode, SIZE, 1000, 9999);
	generateRandomArray(discount, SIZE, 0, 100);
	/*for (int i = 0; i < SIZE; i++) {
		printf("%d ", barcode[i]);
	}*/
	
	int us_choice; int id_item; int storage=0;	float sum = 0;

	printf("\nWelcome!\n");
	print_menu();
	printf("Input: ");
	scanf_s("%d",&us_choice);

	do{
		switch (us_choice) {
		case 1: 
			id_item = scanProduct(barcode, SIZE);
			break;
		case 2:
			printf("Scanned product: \n");
			printf("Barcode |\tName\t    | Price  | Discount\n");
			printf("# %d  | %10s\t    |     %d | %5d%%\n", barcode[id_item], products[id_item], cost[id_item], discount[id_item]);
			break;
		case 3:
			printf("Product added\n");
			cart[storage] = id_item;
			storage++;
			break;
		case 4:
			printf("Your products: \n");
			for (int i = 0; i < SIZE; i++)
			{
				int count = 0;
				for (int j = 0; j < storage; j++)
				{
					if (barcode[i] == barcode[cart[j]])
					{
						count++;
					}
				}
				if (count > 0)
				{
					float sumprod = (float)cost[i] * count;
					float totalproduct = sumprod - (((float)discount[i] / 100 ) * sumprod);
					sum += totalproduct;
					printf("%s\t  %d x %d\n", products[i], count, cost[i]);
					printf("Cost ............... %.2f\n", sumprod);
					printf("Cost including discount ............... %.2f\n\n", totalproduct);
				}
			}
			printf("Total cost .......... %.2f\n", sum);
			break;
		case 5:
			printf("\nYour receipt: \n\n");
			sum = 0;
			float totaldiscount = 0;
			for (int i = 0; i < SIZE; i++)
			{
				int k = 0;
				for (int j = 0; j < storage; j++)
				{
					if (barcode[i] == barcode[cart[j]])
					{
						k++;
					}
				}
				if (k > 0)
				{
					float sumprod = (float)cost[i] * k;
					float totalproduct = sumprod - (((float)discount[i] / 100) * sumprod);
					sum += sumprod;
					totaldiscount += sumprod - totalproduct;
					printf("%s\n", products[i]);
					printf("Cost ............... %.2f\n", sumprod);
					printf("Total discount............... -%.2f\n", sumprod - totalproduct);
					printf("Total cost ............... %.2f\n", sumprod - (sumprod - totalproduct));
				}
			}
			printf("\n<<=========================>>\n");
			printf("\nIN TOTAL .................... %.2f\n", sum);
			printf("TOTAL DISCOUNT .................... -%.2f\n", totaldiscount);
			printf("TOTAL AMOUNT .................... %.2f\n", sum - totaldiscount);
			sum = 0;
			for (int i = 0; i < 100; i++) {
				cart[i] = 20;
			}
			break;
		case 6:
			print_menu();
			break;
		default:
			printf("Incorrect input\n");
			break;
		}
		us_choice = '\n';
		printf("Input: ");
		scanf_s("%d",&us_choice);
	} while (us_choice != 0);
	
	return 0;
}