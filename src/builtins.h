#ifndef BUILTINS_H
#define BUILTINS_H

int nopesh_num_builtins(void);

extern char* builtin_str[];

extern int (*builtin_func[])(char**);

#endif /* BUILTINS_H */
