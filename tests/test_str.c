#include <iterm_data.h>
#include <stdio.h>

int
main()
{
    iterm_str_t it_str;
    iterm_str_cpy(&it_str, "Init!");
    iterm_str_concat(&it_str, " concated!");
    printf("%03u :: %s\n", it_str.size, it_str.str);
    return 0;
}
