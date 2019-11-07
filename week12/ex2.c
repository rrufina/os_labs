#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char ch;
    int *files = malloc(argc * sizeof(int));
    for (int i = 1; i < argc; i++) {
        files[i] = open(argv[i], O_WRONLY | O_CREAT, S_IRWXU);
    }
    while (read(0, &ch, 1)) {
        for(int i = 1; i < argc; i++) {
            write(files[i], &ch, 1);
        }
        write(1, &ch, 1);
    }
    for (int i = 1; i < argc; i++) {
        close(files[i]);
    }
    free(files);
    return 0;
}