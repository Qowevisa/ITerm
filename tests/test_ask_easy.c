#include <iterm_data.h>
#include "./test__.h"

int main()
{
    START();

    int ret = iterm_ask_easy("Test?");
    printf("\n");
    printf("Return : %d\n", ret);

    END();
    return 0;
}
