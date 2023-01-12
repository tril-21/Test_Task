// Convert.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

bool check_Letter(char a) {
    if (a >= 'A' && a <= 'Z') {
        return true;
    }
    else if(a >= 'a' && a <= 'z') {
        return true;
    }
    else {
        return false;
    }
}

char to_up_or_down(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (char)('a' + (c - 'A'));
    } else {
        return (char)('A' + (c - 'a'));
    }
}

int get_index(int& arr, int size) {
    int* p = &arr;
    for (int i = 0; i < size; i++) {
        if (p[i] == 0) {
            return i;
        }
    }
    return size;
}


int main()
{
    char str_begin[100];
    cin.getline(str_begin,100);

    int index[100];

    for (int i = 0; i < strlen(str_begin); i++) {
        index[i]=0;
    }
    int j;
    char other_reg_char=' ';
    bool duplicate=false;
    for (int i = get_index(*index, strlen(str_begin));i< strlen(str_begin);) {
        if (check_Letter(str_begin[i])) {
            other_reg_char = to_up_or_down(str_begin[i]);
        }
        else {
            other_reg_char = str_begin[i];
        }
        index[i] = 4;
        if (get_index(*index, strlen(str_begin)) == 0) {
            j = 1;
        }
        else {
            j = get_index(*index, strlen(str_begin));
        }
        duplicate = false;
        for (;j< strlen(str_begin);j++) {
            if (str_begin[i] == str_begin[j] || other_reg_char == str_begin[j]) {
                duplicate = true;
                index[j] = 2;
            }
        }
        if (duplicate == true)
            index[i] = 2;
        else
            index[i] = 1;
        i = get_index(*index, strlen(str_begin));
    }

    for (int i = 0; i < strlen(str_begin); i++) {
        if (index[i] == 2)
            str_begin[i] = ')';
        else
            str_begin[i] = '(';
    }
    cout << str_begin;
    return 0;
}