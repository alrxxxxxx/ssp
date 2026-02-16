#ifndef FILEIO_H
#define FILEIO_H

#include "stack.h"

int save_two_stacks(const char* filename, Stack* orig, Stack* sorted);
int print_from_file(const char *filename);

#endif