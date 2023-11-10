#include "main.h"

void task1(char **argv, char **env);

int main(int ac, char **argv, char **env)
{
if (ac == 1)
task1(argv,env);

	return(0);

}
void task1(char *argv[], char **env)
{
/*setting variable*/

char *prompt = "$ ";
char *command = NULL, *string;
size_t n = 0;
ssize_t char_num;
int i = 0;
argv[0] = NULL;
argv[1] = NULL;
	
while(1)
	{
		if(isatty(STDIN_FILENO))
	printf("%s", prompt);/*printing prompt*/
	
	char_num = getline(&command, &n, stdin);/*getting command*/
	
	if (char_num == -1)
	{
		free(command);
		exit (EXIT_FAILURE);
	}
/*allocate space for string*/

	string = malloc(sizeof(char) * (char_num - 1));
	if (string == NULL)
		exit (EXIT_FAILURE);

/*deleting the NULL operator*/
	while(command[i] != '\0')
	{
	
		string[i-1] = command[i-1];
		i++;
	}
   argv[0] = string;
   argv[1] = NULL;
	

	if (execve(argv[0], argv, env) == -1)
    perror("execve");
    /* Handle error as needed */
	}
/*freeing*/
free(string);
free(argv);
}
