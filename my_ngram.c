#include <stdio.h>
#define MAX_ARRAY_SIZE 120
void fill_array(int* array, int size_array, char* str) {
    int index = 0;
    while(str[index] != '\0') {
        if (str[index] != '"') {
            array[str[index]] += 1;
        }
        index += 1;
    }
}

void print_array(int* array, int size_array) {
    int index = 0;
    while(index < size_array) {
        if (array[index] > 0) {
            printf("%c:%d\n", index, array[index]);
        }
        index += 1;
    }
}

int main(int ac, char **av) {
    int index = 1;
    int array[MAX_ARRAY_SIZE] = {0};
    while(index < ac) {
        fill_array(&array[0], MAX_ARRAY_SIZE, av[index]);
        index += 1;
    }
    print_array(&array[0], MAX_ARRAY_SIZE);
    return 0;
}
   