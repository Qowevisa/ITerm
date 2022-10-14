#include "../inc/iterm_data.h"
#include "../inc/iterm_util.h"
#include "../inc/iterm_error.h"
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
    it_str->str[it_str->size] = '\0'; 
}

uint8_t
iterm_ask(iterm_ask_t it_ask)
{
    printf("%s %c/%c",
            it_ask.ask.str,
            it_ask.yes_symbol - 32*(it_ask.def==0),
            it_ask.no_symbol - 32*(it_ask.def==1)
        );
    toggle_echo();
    char c;
    while (1) {
        c = fgetc(stdin);
        if (c == it_ask.yes_symbol || c == it_ask.no_symbol || c == 10) {
            toggle_echo();
            return (c == it_ask.no_symbol) || (it_ask.def && (c == 10));
        }
    }
}

uint8_t
iterm_ask_complex(const char *str, const char ys, const char ns, const uint8_t def)
{
    if (def > 1) { raise_error_int(def, 0, 1); }

    iterm_ask_t it_ask;
    iterm_str_cpy(&it_ask.ask, str);
    it_ask.yes_symbol = ys;
    it_ask.no_symbol = ns;
    it_ask.def = def;

    return iterm_ask(it_ask);
}

uint8_t
iterm_ask_easy(const char *str)
{
    return iterm_ask_complex(str, 'y', 'n', 0);
}
