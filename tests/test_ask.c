#include <iterm_data.h>
#include "./test__.h"

int main()
{
    START();

    int ret = iterm_ask_complex("Test complex", 'l', 'n', 1);
    printf("\n");
    printf("Return : %d\n", ret);

    END();
    return 0;
}
