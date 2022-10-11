#include <termios.h>
#include <unistd.h>
#include <string.h>

struct termios mem;

void
toggle_echo()
{
    struct termios out_t;
    // FIXME add validations on func output
    tcgetattr(0, &out_t);
    // memcpy(&mem, &out_t, sizeof(struct termios));
    out_t.c_lflag ^= ECHO;
    out_t.c_lflag ^= ICANON;
    tcsetattr(0, TCSANOW, &out_t);
}
