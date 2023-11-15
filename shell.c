#include "main.h"
void shell(char **argv, char **env);
/**
 * shell - creat a simple shell.
 * @argv: arguments
 * @env: environment
 * Return: the command line arguments
*/

void shell(char **argv, char **env)
{
	pid_t proc_id;
	char *command = NULL, *string, *prompt = "$ ";
	size_t n = 0;
	ssize_t char_num;
	int i, j, status;

	argv[0] = NULL;
	argv[1] = NULL;
	while (1)
	{
	if (isatty(STDIN_FILENO))/*isatty adde */
		printf("%s", prompt);/*printing prompt*/

	char_num = getline(&command, &n, stdin);/*getting command*/
	if (char_num == -1)
	{
		free(command);
		exit(EXIT_FAILURE);
	}
/*allocate space for string*/

	string = malloc(sizeof(char) * (char_num));
	if (string == NULL)
		exit(EXIT_FAILURE);

/*deleting the NULL operator*/
	i = 0;/*reseeting i to zero after every excetuon*/

	while (command[i] != '\0')
	{
		string[i - 1] = command[i - 1];
		i++;
	}
	string[i] = '\0';
	j = 0;
	argv[j] = strtok(string, " ");

	while (argv[j])/* setting values of argv[]*/
	{
	argv[j + 1] = strtok(NULL, " ");
	 ++j;
	}
/*final_command = get_location(argv[0]);*/
/*fork must not be called if command doeasn't found*/

	/**
	 * creating a child proceess to make
	 * my shell print $ after the excution
	 */
	proc_id = fork();

	if (proc_id == -1)
	{
		free(string);
		free(command);
		/*free(final_command);*/
		exit(EXIT_FAILURE);
	}

	if (proc_id == 0)
	{
	execve(argv[0], argv, env);
	printf("%s :no such file or directory\n", argv[0]);
	}

	else
	wait(&status);
	} /*end of wile loop*/
/* Handle error as needed */

	/*freeing*/
	free(string);
	free(argv);
	free(command);
/*	free(final_command);*/
}
