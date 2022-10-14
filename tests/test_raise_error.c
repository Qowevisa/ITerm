#include <iterm_data.h>
#include "./test__.h"

int
main()
{
    START();
    SYNOPSYS("THIS TEST WILL RAISE AN ERROR AND WILL NOT HAVE END POINT");

    iterm_ask_complex("It will raise error", 'y', 'n', 2);

    END();
    return 0;
}
