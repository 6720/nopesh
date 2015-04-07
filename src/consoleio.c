#include "consoleio.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* nopesh_read_line(void) {
        char* line = NULL;
        size_t buffersize = 0; // Have getline() allocate a buffer for us
        getline(&line, &buffersize, stdin);
        return line;
}

char** nopesh_split_line(char* line) {
        int buffersize = TOKEN_BUFFERSIZE;
        char** tokens = malloc(buffersize * sizeof(char*));

        if(!tokens) {
                fprintf(stderr, "nopesh: memory allocation error");
                exit(1);
        }

        int position = 0;
        char* token = strtok(line, TOKEN_DELIMITER);
        while(token != NULL) { // Couldn't we just do "while(token)" here?
                tokens[position] = token;
                ++position;

                if(position >= buffersize) {
                        buffersize += TOKEN_BUFFERSIZE;
                        tokens = realloc(tokens, buffersize * sizeof(char*));
                        if(!tokens) {
                                fprintf(stderr, "nopesh: memory reallocation error");
                                exit(1);
                        }
                }
                token = strtok(NULL, TOKEN_DELIMITER);
        }
        tokens[position] = NULL;
        return tokens;
}

// This is a good learning experience, but modern UNIX C stdlibs will have the 
// getline() used in the above implementation. 
/*char* nopesh_read_line(void) {
        int buffersize = READLINE_BUFFER_SIZE;
        int position = 0;
        char* buffer = malloc(sizeof(char) * buffersize);
        int c;

        if(!buffer) {
                fprintf(stderr, "nopesh: memory allocation error\n");
                exit(1);
        }

        while(1) {
                // Read a character
                c = getchar();

                // If we hit EOF or newline, replace with a NUL character and
                // return
                if(c == EOF || c == '\n') {
                        buffer[position] = '\0';
                        return buffer;
                } else {
                        buffer[position] = c;
                }
                ++position;

                // If we exceed the buffer's size, and we're not done, 
                // reallocate
                if(position >= buffersize) {
                        buffersize += READLINE_BUFFER_SIZE;
                        buffer = realloc(buffer, buffersize);
                        if(!buffer) {
                                fprintf(stderr, "nopesh: memory reallocation error");
                                exit(1);
                        }
                }
        }
}*/
