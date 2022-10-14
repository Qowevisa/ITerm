#ifndef __iterm_error_h
#define __iterm_error_h
#include <stdint.h>

void
raise_error_exp_code(const char *name, int32_t val, int32_t expect);

void
raise_error_int_code(const char *name, int32_t val, int32_t sr, int32_t er);

#define raise_error_exp(val, e) raise_error_exp_code(#val, val, e)

#define raise_error_int(val, sr, ed) raise_error_int_code(#val, val, sr, ed)

#endif // __iterm_error_h
