// Copyright 2021 Fomin Vladimir
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include "../dirent-1.23.2/include/dirent.h"    // ��� ������ � ������������
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>




/// <summary>
/// �������, ������������ ������ �����
/// </summary>
/// <param name="file">������ ��� ������������� ���� �� �����</param>
/// <returns>������ �����</returns>
int getFileSize(const char* file) {
    struct stat st;
    int full_size = 0;

    if (stat(file, &st) == 0) {
        // ���� ��� �����
        if ((st.st_mode & S_IFMT) == S_IFDIR)
            return -1;
        // ���� ������� ����
        else if ((st.st_mode & S_IFMT) == S_IFREG)
            return st.st_size;
        // ���� ���-�� ���� (�����, FIFO (����������� �����) � ��.)
        else
            return -2;
    }
}

/// <summary>
/// �������, ���������� �������� ������ � ������� � �������� � ���������� ������������
/// </summary>
/// <param name="path">���� �� ��������</param>
void getSizesFromDir(char* path) {
    struct dirent* cur_file;
    DIR* dir;

    char full_file_path[200];

    // ��������� ������� ����������
    dir = opendir(path);

    // ���� ������� ������� ����������
    if (dir) {
        // ��������� ����� ������ ���������� � ���������� cur_file, ���� ����� �� ��������
        while ((cur_file = readdir(dir)) != NULL) {
            // ���������� ��������� ����� ./ � ../
            // ���� �������� ������, ������������ �� . ��� .. - ���������� ��
            if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
                // �������� ���� � ����� ����������, ��������� ������ ����������� ����������,
                // ��������� ��� �������� (����� ��� �����)
                strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
                // �������� ������ ��� -1, ���� ��� �� ����, � ��������� �����
                int cur_file_size = getFileSize(full_file_path);
                if (cur_file_size >= 0)
                    // ��� ����� �������� ��� ��� � ������
                    printf("%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);
                else if (cur_file_size == -1)
                    // ��� ��������� ����� �������� ���������� ���������� �����
                    getSizesFromDir(full_file_path);
            }
        }
        // �� �������� ������� ����������
        closedir(dir);
    }
}

/// <summary>
/// �������, ������������ ���������� ������ � ��������� ��������
/// </summary>
/// <param name="path"></param>
/// <param name="c_files"></param>
void getCountOfFiles(char* path, int* c_files) {
    struct dirent* cur_file;
    DIR* dir;

    char full_file_path[200];

    // ��������� ������� ����������
    dir = opendir(path);

    // ���� ������� ������� ����������
    if (dir) {
        // ��������� ����� ������ ���������� � ���������� cur_file, ���� ����� �� ��������
        while ((cur_file = readdir(dir)) != NULL) {
            // ���������� ��������� ����� ./ � ../
            // ���� �������� ������, ������������ �� . ��� .. - ���������� ��
            if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
                // �������� ���� � ����� ����������, ��������� ������ ����������� ����������,
                // ��������� ��� �������� (����� ��� �����)
                strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
                // �������� ������ ��� -1, ���� ��� �� ����, � ��������� �����
                int cur_file_size = getFileSize(full_file_path);
                if (cur_file_size >= 0)
                    // ��� ����� ����������� ����������
                    (*c_files)++;
                else if (cur_file_size == -1)
                    // ��� ��������� ����� �������� ���������� ���������� �����
                    getCountOfFiles(full_file_path, c_files);
            }
        }
        // �� �������� ������� ����������
        closedir(dir);
    }

}

void print_menu(){
    printf("\n1.Enter a new directory\n2.Select the sorting method\n3.View the list of files \n0.Exit the program\nInput: ");
}

void sort_menu() {
    
    printf("1.Cocktail sort\n");
    printf("2.Counting sort\n");
    printf("3.Shellsort\n");

}

void getFilesNameSizes(char* path, int* file_size, char** file_name,int n){
    struct dirent* cur_file;
    DIR* dir;
    char full_file_path[200];

    char tmp[200];
    int tmp_n;

    // ��������� ������� ����������
    dir = opendir(path);
    // ���� ������� ������� ����������
    if (dir) {
        // ��������� ����� ������ ���������� � ���������� cur_file, ���� ����� �� ��������
        while ((cur_file = readdir(dir)) != NULL) {
            // ���������� ��������� ����� ./ � ../
            // ���� �������� ������, ������������ �� . ��� .. - ���������� ��
            if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
                // �������� ���� � ����� ����������, ��������� ������ ����������� ����������,
                // ��������� ��� �������� (����� ��� �����)
                strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
                // �������� ������ ��� -1, ���� ��� �� ����, � ��������� �����
                int cur_file_size = getFileSize(full_file_path);
                if (cur_file_size >= 0)
                {
                    tmp_n = n;
                    file_size[n] = cur_file_size;
                    int j;
                    for (j = 0; cur_file->d_name[j] != '\0'; j++)
                    {
                        file_name[tmp_n][j] = cur_file->d_name[j];
                    }
                    file_name[tmp_n][j] = '\0';
                    tmp_n++;
                    n = tmp_n;
                    // ��� ����� ���������� ��� ��� � �����p
                }
                else if (cur_file_size == -1)
                {
                    // ��� ��������� ����� �������� ���������� ���������� �����
                    tmp_n = n;
                    getFilesNameSizes(full_file_path, file_name, file_size, n);
                }
            }
        }
        tmp_n = n;
        closedir(dir);
    }
}

void print_array(char** file_name, int* file_size, int count)
{
    printf("\n");
    for (int k = 0; k < count; k++)
    {
        printf("%s - %d B (%d kb)\n", file_name[k], file_size[k], file_size[k] / 1024);
    }
}
void print_array_reverse(char** file_name, int* file_size, int count)
{
    printf("\n");
    for (int i = count-1; i > 0; --i)
    {
        printf("%s - %d B (%d kb)\n", file_name[i], file_size[i], file_size[i] / 1024);
    }
}


/// <summary>
/// ������� ������
/// </summary>
/// <param name="Mas"></param>
/// <param name="i"></param>
void Swap(int* Mas, int i)
{
    int temp;
    temp = Mas[i];
    Mas[i] = Mas[i - 1];
    Mas[i - 1] = temp;
}

void ShakerSort(int* file_size, char** file_name, int Start, int N)
{
    int Left, Right, i;
    Left = Start;
    Right = N - 1;
    while (Left <= Right)
    {
        for (i = Right; i >= Left; i--)
            if (file_size[i - 1] > file_size[i]) {
                Swap(file_size, i);
                Swap(file_name, i);
            }
        Left++;
        for (i = Left; i <= Right; i++)
            if (file_size[i - 1] > file_size[i]) {
                Swap(file_name, i);
                Swap(file_size, i);
            }
        Right--;
    }
}

void ShellSort(char** file_name, int* file_size, int n)
{
    int i, j, step;
    int tmpn, tmps;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmps = file_size[i]; tmpn = file_name[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmps < file_size[j - step])
                {
                    file_size[j] = file_size[j - step];
                    file_name[j] = file_name[j - step];
                }
                else
                    break;
            }
            file_size[j] = tmps;
            file_name[j] = tmpn;
        }
}

void CountingSort(char** file_name, int* file_size, int n)
{
    int k;
    int sortedMassSize[2000] = { 0 };
    char sortedMassName[2000][200];
    for (int i = 0; i < n; i++)
    {
        k = 0;
        for (int j = 0; j < n; j++)
        {
            if (file_size[i] > file_size[j])
                k++;
        }
        sortedMassSize[k] = file_size[i];
        strcpy(sortedMassName[k], file_name[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (sortedMassSize[i] != 0)
        {
            file_size[i] = sortedMassSize[i];
            file_name[i] = sortedMassName[i];
        }
    }
}

void methodOfCalculation(int n, int *mass, int *sortedMass, char **file_names, char **sortedMassName)
{
    int k;
    for (int i = 0; i < n; i++)
    {
        k = 0;
        for (int j = 0; j < n; j++)
        {
            if (mass[i] > mass[j])
                k++;
        }
        sortedMass[k] = mass[i];
        sortedMassName[k] = file_names[i];
    }
}

int main() {
    char path[200];
    int c_files = 0; int us_choice; int n = 0; int sort_method; int time; int print_method; double time_spent; clock_t end; clock_t begin;

    printf("Welcome!\n");
    // ��������� ���� (�� ���� scanf_s ��� ������)
    printf("Input path to dir: ");
    gets(path);
    getCountOfFiles(path, &c_files);
    
    print_menu();
    scanf_s("%d", &us_choice);
    do {

        int* file_size = (int*)malloc(c_files * sizeof(int*));
        char** file_name = (char**)malloc(c_files * sizeof(char*));
        for (int i = 0; i != c_files; i++)
        {
            file_name[i] = (char*)malloc(c_files * 10 * sizeof(char));
        }
        getFilesNameSizes(path, file_size, file_name, n);

        int* sortedMass;
        sortedMass = (int*)malloc(c_files * sizeof(int));
        char** sortedMassName = (char**)malloc(c_files * sizeof(char*));
        for (int i = 0; i != c_files; i++)
        {
            sortedMassName[i] = (char*)malloc(c_files * 10 * sizeof(char));
        }

        switch (us_choice) {
        case 1:
            printf("Input path to dir: ");
            gets(path);
            getCountOfFiles(path, &c_files);
            break;
        case 2:
            sort_menu();
            printf("Input: ");
            scanf_s("%d", &sort_method);
            switch (sort_method) {
            case 1:
                begin = clock();
                ShakerSort(file_size, file_name, 0, c_files);
                end = clock();
                time_spent = ((double)(end - begin)) / CLOCKS_PER_SEC;
                printf("Choose in which order to display the list:\n");
                printf("1.In ascending order\n2.In descending order\nInput: ");
                scanf_s("%d", &print_method);
                switch (print_method)
                {
                case 1:
                    print_array(file_name, file_size, c_files);
                    printf("\nExecution time: %lf (ms)\n", time_spent);
                    break;
                case 2:
                    print_array_reverse(file_name, file_size, c_files);
                    printf("\nExecution time: %lf (ms)\n", time_spent);
                    break;
                }
            default: break;
                break;
            case 2:
                
                begin = clock();
                CountingSort(file_name, file_size, c_files);
                end = clock();
                time_spent = ((double)(end - begin)) / CLOCKS_PER_SEC;
                printf("Choose in which order to display the list:\n");
                printf("1.In ascending order\n2.In descending order\nInput: ");
                scanf_s("%d", &print_method);
                switch (print_method)
                {
                case 1:
                    print_array(file_name, file_size, c_files);
                    printf("\nExecution time: %lf (ms)\n", time_spent);
                    break;
                case 2:
                    print_array_reverse(file_name, file_size, c_files);
                    printf("\nExecution time: %lf (ms)\n", time_spent);
                    break;
                }
                break;
            case 3:
                begin = clock();
                ShellSort(file_name, file_size, c_files);
                end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("Choose in which order to display the list:\n");
                printf("1.In ascending order\n2.In descending order\nInput: ");
                scanf_s("%d",&print_method);
                switch (print_method)
                {
                case 1:
                    print_array(file_name, file_size, c_files);
                    printf("\nExecution time: %lf (ms)\n", time_spent);
                    break;
                case 2:
                    print_array_reverse(file_name, file_size, c_files);
                    printf("\nExecution time: %lf (ms)\n", time_spent);
                    break;
                }
                break;
            }
            break;
        case 3:
            print_array(file_name, file_size, c_files);
            break;

        case 0: break;
        }
        print_menu();
        scanf_s("%d", &us_choice);
    } while (us_choice != 0);

    


    return 0;
}