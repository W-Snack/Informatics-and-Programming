// Copyright 2021 Vladimir Fomin

/*
* «Быки и коровы»
* Игрок выбирает длину загадываемого числа – n (от 2 до 5).
* Компьютер «задумывает» n-значное число с неповторяющимися цифрами.
* Компьютер сообщает, сколько цифр угадано без совпадения с их позициями в загаданном числе
* Игрок делает попытки, пока не отгадает всю последовательность.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int size = 1;
	printf("This program is for playing in 'Cows and bulls'\n");
	while(size) {
		int size_correct = 0;
		printf("If you want to play 'Cows and bulls' input size of number(from 2 to 5), else print 0\n");
		while (!size_correct) {
			scanf_s("%d", &size);
			if (size > 5) {
				printf("Number too big\nTry again\n");
			}
			else if (size < 2) {
				printf("Number is too small\nTry again\n");
			}
			else size_correct++;
		}
		int* number;
		int* us_number;
		int user_num;
		int is_correct = 0;
		number = (int*)malloc(size * sizeof(int));
		us_number = (int*)malloc(size * sizeof(int));
		if (!number || !us_number) {
			printf("Error. Required memory is not allocated\n");
			exit(1);
		}
		for (int i = 0; i < size; i++) {
			number[i] = 0;
			us_number[i] = 0;
		}
		while (!is_correct && size) {
			//generate number

			srand(time(NULL));
			for (int i = 0; i < size; ++i)
			{
				int j = rand() % (i + 1);
				number[i] = number[j];
				number[j] = i + 1;
			}
			
			//user try's
			printf("Input the expected value\n");
			scanf_s("%d", &user_num);
			do {
				int count_bull, count_cow;
				count_bull = 0; count_cow = 0;
				int cow[5] = { 0 };
				int bull[5] = { 0 };
				int bull_pos[5] = { 0 };
				//split a number into digits
				for (int i = size - 1; i != -1; i--) {
					us_number[i] = user_num % 10;
					user_num /= 10;
				}
				//count of 'cow' and 'bull'
				for (int pos_n = 0; pos_n < size; pos_n++) {
					for (int pos_u = 0; pos_u < size; pos_u++) {
						if (number[pos_n] == us_number[pos_u]) {
							if (pos_n != pos_u) {
								cow[count_cow] = number[pos_n];
								count_cow++;
							}
						}
					}
					if (number[pos_n] == us_number[pos_n]) {
						bull[count_bull] = number[pos_n];
						bull_pos[count_bull] = pos_n;
						count_bull++;
					}

				}
				//result of check
				if (count_bull == size) {
					is_correct = 1;
				}
				else {
					printf("Your number is incorrect\n");
					printf("You caught:\n");
					printf("%d cows:", count_cow);
					for (int i = 0; i < count_cow; i++) {
						printf("%d ", cow[i]);
					}
					printf("\n%d bulls:", count_bull);
					for (int i = 0; i < count_bull; i++) {
						printf("%d in postion %d, ", bull[i], bull_pos[i]+1);
					}
					printf("\nInput next value\n");
					scanf_s("%d", &user_num);
				}
			} while (!is_correct);
			printf("\nYou guessed the number!\n");
			free(us_number);
			free(number);
		} 
	}
	printf("GoodBye!\n");
	return 0;
}