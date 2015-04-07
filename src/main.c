#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "consoleio.h"
#include "statuscodes.h"
#include "executor.h"

void nopesh_shell_loop(void);

int main(int argc, char** argv) {
        // Yay! We have a shell!
        
        // TODO: Config
        
        // TODO: Other init
        
        // Actually run the shell
        nopesh_shell_loop();
        
        // TODO: Cleanup
        
        return 0;
}

void nopesh_shell_loop(void) {
        char* line;
        char** args;
        int status;
        do {
                printf("nopesh> "); 
                line = nopesh_read_line();
                if(line[0] == EOF || line[0] == 0) {
                        break;
                }
                args = nopesh_split_line(line);
                status = nopesh_execute(args);

                free(line);
                free(args);
        } while(status != EXIT_CODE);
}
