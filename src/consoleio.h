#ifndef CONSOLEIO_H
#define CONSOLEIO_H

// Used in the commented-out function in consoleio.c
// #define READLINE_BUFFER_SIZE 1024

#define TOKEN_BUFFERSIZE 64
#define TOKEN_DELIMITER " \t\r\n\a"

int nopesh_get_key(void);

char** nopesh_split_line(char* line);

char* nopesh_read_line(void);

#endif /* CONSOLEIO_H */
