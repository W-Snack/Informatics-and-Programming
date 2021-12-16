/*Copyright 2021 Vladimir Fomin*/

/*Actions with arrays:
Поменять местами правую и левую половину массива
	  Реализовать 2 способами:
		1. С использованием доп массива
		2. Без доп массива*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int size, el1, method;
	int* array;
	int* array_reverse;
	int el, tmp, tmp2;

	printf("This program swaps the right and left parts of the array\n");
	printf("Choose a solution method:\n 1.Reverse array With second array\n 2.Reverse array Without second array\n 3.The product of odd array elements\n 4.The product of array elements with odd indexes\n 5.The product of the elements of the array is odd in value\n 6.Swap elements with the specified indexes\n");
	scanf_s("%d", &method);
	printf("Input size of the array\n");
	scanf_s("%d", &size);

	array = (int*)malloc(size * sizeof(int));
	if (!array) {
		printf("Error. Required memory is not allocated\n");
		exit(1);
	}

	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}

	array_reverse = (int*)malloc(size * sizeof(int));
	if (!array_reverse) {
		printf("Error. Required memory is not allocated\n");
		exit(1);
	}
	for (int i = 0; i < size; i++) {
		array_reverse[i] = 0;
	}

	printf("Input array\n");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &el1);
		array[i] = el1;
	}

	int mult = 1; int i, j;
	switch (method)
	{
	case 1:
		for (int i = size / 2, j = 0; i < size; i++, j++) {
			array_reverse[j] = array[i];
		}
		for (int i = 0, j = size / 2 + size % 2; j < size; i++, j++) {
			array_reverse[j] = array[i];
		}
		printf("The resulting array: ");
		for (int i = 0; i < size; i++) {
			if (method == 2) {
				printf("%d ", array[i]);
			}
			else {
				printf("%d ", array_reverse[i]);
			}
		}

		break;
	case 2:
		for (int i = 0, j = size / 2; j < size; i++, j++) {
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		if(size%2!=0){
			array[size - 1] = tmp;
			for (int i = size - 1; i >= size / 2 + 1; i--)
			{
				array[i] = array[i - 1];
			}
			array[size / 2 + 1] = tmp;
		}
		printf("The resulting array: ");
		for (int i = 0; i < size; i++) {
			if (method == 2) {
				printf("%d ", array[i]);
			}
			else {
				printf("%d ", array_reverse[i]);
			}
		}

		break;
	case 3:
		for (int i = 0; i < size; i++) {
			if (((i+1) % 2) != 0) {
				mult *= array[i];
			}
		}
		printf("The product of odd array elements = %d\n", mult);
		break;
	case 4:
		for (int i = 0; i < size; i++) {
			if ((i % 2) != 0) {
				mult *= array[i];
			}
		}
		printf("The product of array elements with odd indexes = %d\n", mult);
		break;
	case 5:
		for (int i = 0; i < size; i++) {
			if ((array[i] % 2) != 0) {
				mult *= array[i];
			}
		}
		printf("The product of the elements of the array is odd in value = %d\n", mult);
		break;
	case 6:
		printf("Input indexes: ");
		scanf_s("%d %d", &i, &j);
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		printf("The resulting array: ");
		for (int i = 0; i < size; i++) 
			printf("%d ", array[i]);
		break;
	}
	free(array);
	free(array_reverse);
	return 0;
}