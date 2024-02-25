#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "process.h"

#define BUFFER_SIZE 20

int main(int argc, char **argv) {
    if (argc == 1 || argc == 2) {
        t_list *tab;
        if (argc == 2) {
            tab = process(argv[1]); // Utilizar el nuevo diccionario proporcionado
        } else {
            tab = process("dictionary.txt"); // Utilizar el diccionario por defecto
        }

        if (!tab) {
            write(2, "Error: Failed to load dictionary\n", 34);
            return 1;
        }

        int num;
        char buffer[BUFFER_SIZE];
        if (argc == 1) {
            write(1, "Enter a number: ", 17);
            read(0, buffer, BUFFER_SIZE);
            num = atoi(buffer); // Leer el valor a convertir desde la entrada estándar
        } else {
            num = atoi(argv[1]); // Usar el valor proporcionado como argumento
        }

        if (num < 0 || num > 999) {
            write(2, "Error: Number must be between 0 and 999\n", 41);
            free(tab);
            return 1;
        }

        print_number(num, tab);
        write(1, "\n", 1);

        free(tab);
        return 0;
    } else {
        write(2, "Usage:\n", 7);
        write(2, "  ", 2);
        write(2, argv[0], strlen(argv[0]));
        write(2, " <number>\n", 10);
        write(2, "  ", 2);
        write(2, argv[0], strlen(argv[0]));
        write(2, " <dictionary_file> <number>\n", 28);
        return 1;
    }
}
