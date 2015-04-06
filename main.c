#include <stdlib.h>
#include <stdio.h>
#include "consoleio.h"

void nopesh_shell_loop(void);

int main(int argc, char** argv) {
        // Yay! We have a shell!
        nopesh_shell_loop();
        return 0;
}

void nopesh_shell_loop(void) {
        char* line;
        char** args;
        int status;
        do {
                printf("nopesh> "); 
                line = nopesh_read_line(); // read line
                args = 0; // split line into stuff
                status = 0; // execute();

                free(line);
                free(args);
        } while(status);
}
