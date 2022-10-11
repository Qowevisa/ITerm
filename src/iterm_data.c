#include "../inc/iterm_data.h"
#include <stdio.h>

static inline
void
it_str_cpy_block(iterm_str_t *it_str, const char *str)
{
    while (it_str->size != ITERM_STR_SIZE && (*str)) {
        it_str->str[it_str->size++] = *str;
        str++;
    }
}

void
iterm_str_cpy(iterm_str_t *it_str, const char *str)
{
    it_str->size = 0;
    it_str_cpy_block(it_str, str);
    it_str->str[it_str->size++] = '\0'; 
}

void
iterm_str_concat(iterm_str_t *it_str, const char *str)
{
    it_str->size -= (it_str->size > 0);
    it_str_cpy_block(it_str, str);
    it_str->str[it_str->size++] = '\0'; 
}

void
iterm_ask(iterm_ask_t it_ask)
{
    // ASK? Y/n
    printf("%s %c/%c", it_ask.ask.str, it_ask.yes_symbol, it_ask.no_symbol);
}

void
iterm_ask_easy(const char *str)
{
    iterm_ask_t it_ask;
    iterm_str_cpy(&it_ask.ask, str);
    it_ask.yes_symbol = 'Y';
    it_ask.no_symbol = 'n';

    iterm_ask(it_ask);
}
