#include "../inc/iterm_error.h"
#include <stdio.h>
#include <stdlib.h>

#define STD_ERR "!ERROR ::"

void
raise_error_exp_code(const char *name, int32_t val, int32_t expect)
{
    printf("%s %s expected to be %d but was %d\n",
            STD_ERR, name, expect, val);
    exit(1);
}

void
raise_error_int_code(const char *name, int32_t val, int32_t sr, int32_t er)
{
    printf("%s %s expected to be in [%d..%d] range but was %d\n",
            STD_ERR, name, sr, er, val);
    exit(1);
}
