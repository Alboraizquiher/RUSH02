#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "types.h"

#define DICTIONARY_SIZE 36
#define BUFFER_SIZE 100

t_list *process(char *file) {
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        write(2, "Error: Unable to open dictionary file\n", 39);
        return NULL;
    }

    t_list *tab = malloc(sizeof(t_list) * DICTIONARY_SIZE);
    if (tab == NULL) {
        close(fd);
        write(2, "Error: Memory allocation failed\n", 31);
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    int index;
    while (read(fd, buffer, BUFFER_SIZE) > 0) {
        sscanf(buffer, "%d: %s", &index, buffer);
        tab[index].nb = index;
        tab[index].val = strdup(buffer);
    }

    close(fd);
    return tab;
}

void print_number(int n, t_list *tab) {
    
}
