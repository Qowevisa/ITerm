#ifndef __iterm_data_h
#define __iterm_data_h
#include <stdint.h>

#define ITERM_STR_SIZE 255

typedef struct iterm_str {
    char str[ITERM_STR_SIZE];
    uint8_t size;
} iterm_str_t;

void
iterm_str_cpy(iterm_str_t *it_str, const char *str);

void
iterm_str_concat(iterm_str_t *it_str, const char *str);

typedef struct iterm_ask {
    iterm_str_t ask;
    char yes_symbol;
    char no_symbol;
    uint8_t def;
} iterm_ask_t;

uint8_t
iterm_ask(iterm_ask_t it_ask);

uint8_t
iterm_ask_easy(const char *str);

uint8_t
iterm_ask_complex(const char *str, const char ys, const char ns, const uint8_t def);

#endif // __iterm_data_h
