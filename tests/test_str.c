#include <iterm_data.h>
#include "./test__.h"

int
main()
{
    START();

    iterm_str_t it_str;
    iterm_str_cpy(&it_str, "Init!");
    iterm_str_concat(&it_str, " concated!");
    printf("%03u :: %s\n", it_str.size, it_str.str);

    END();
    return 0;
}
