#include <iterm_data.h>
#include "./test__.h"

int main()
{
    START();

    iterm_ask_complex("Test complex", 'l', 'n', 1);
    printf("\n");

    END();
    return 0;
}
