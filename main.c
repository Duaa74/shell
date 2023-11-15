#include "main.h"
/**
 * main - main function.
 * @ac: number of arguments
 * @argv: arguments
 * @env: environment
 * Return: number of arguments
*/

int main(int ac, char **argv, char **env)
{
	if (ac <= 12) /* changed from 1 to 12*/
	shell(argv, env);

	return (0);
}
