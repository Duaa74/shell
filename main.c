#include "main.h"
int main(int ac, char **argv, char **env)
{
if (ac <= 12) /* changed from 1 to 12*/
shell(argv,env);

    return (0);
}
