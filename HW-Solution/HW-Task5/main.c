#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include "../dirent-1.23.2/include/dirent.h"    // ��� ������ � ������������
#include <sys/stat.h>                           // ��� ������������ ������� �����

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

int main() {
    char path[200];

    // ��������� ���� (�� ���� scanf_s ��� ������)
    printf("Input path to dir: ");
    gets(path);

    getSizesFromDir(path);

    return 0;
}