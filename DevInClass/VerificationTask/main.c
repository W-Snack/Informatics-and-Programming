// Copyright 2021 FirstName LastName

/*
* ��������� ���������� ���������� ������ N �������. ������ ������� ������� ���������� � ���, � ����� ����������� ����� �� ������. ����� ����� ���������� ��� ������ ���� ���������������� � ������ ���� ������ ������:

�������� �� ����������,
���������� ������� ����, ��� � ��� ������.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, count_f, count_lot;
	count_lot = 0;
	int is_true = 1;
	int* friends;
	int* people;
	scanf_s("%d", &N);
	friends = (int*)malloc(N * sizeof(int));
	people = (int*)malloc(N * sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < N; ++i)
	{
		people[i] = i+1;
		
	}


	while (count_lot<N)
	{
		char ch;
		int a;
		int i = 0;
		do {
			scanf_s("%c", &ch);
			if (ch >= 48 && ch <= 57) {
				a = ch - '0';
				friends[i] = a;
				i++;
				count_lot++;
			}
			else continue;
		} while (ch != '\n');
	}
	for (int i = 0; i < N; i++) {
		if (friends[i] >= N) {
			is_true = 0;
		}
	}
	if (!is_true) {
		printf("False information\n");
	}
	else {
		printf("A possible dating option:\nHuman : his acquaintances\n");
		for (int i = 1; i <= N; i++) {
			int j = 0;
			srand(time(NULL));

			// ���������� ��������� ������������
			for (int i = N - 1; i >= 1; i--)
			{
				int j = rand() % (i + 1);

				int tmp = people[j];
				people[j] = people[i];
				people[i] = tmp;
			}
			printf("%d : ", i);
			while (j < friends[i - 1]) {
					printf("%d ", people[j]);
				j++;
			}
			printf("\n");
		}
	}
	free(people);
	free(friends);
	return 0;
}