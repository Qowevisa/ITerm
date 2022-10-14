#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include "../inc/iterm_error.h"

struct termios mem;

void
toggle_echo()
{
    struct termios out_t;
    int32_t ret;
    if ((ret = tcgetattr(0, &out_t)) != 0) {
        raise_error_func(tcgetattr(0, &out_t), ret, 0);
    }
    out_t.c_lflag ^= ECHO;
    out_t.c_lflag ^= ICANON;
    if ((ret = tcsetattr(0, TCSANOW, &out_t)) != 0) {
        raise_error_func(tcsetattr(0, TCSANOW, &out_t), ret, 0);
    }
}
