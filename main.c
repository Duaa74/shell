#include "main.h"

int main(int ac, char **argv)
{
/*setting variables*/
	char *prompt = "($) ";
	size_t n = 0;
	char *command = NULL,*command_copy = NULL;
	ssize_t char_num;
	const char *delim = " ";
	char *token = NULL;
	int token_count = 0;
	int i;
	(void)ac; (void)argv;
	

	while (1)
	{
		printf("%s", prompt);/*print $ to screen*/
		char_num = getline(&command, &n , stdin);/*recive command*/

		if (char_num == -1)/*check if getline succefull*/
		
		{
			perror("./shs: ");
			free(command);
			return (-1);
		}
	/*copy my command*/
		command_copy = malloc(sizeof(char) * (char_num + 1));
		if (command_copy == NULL)
			return (1);
	
		/*handle error*/
		strcpy(command_copy,command);
		
		/*counting number of string*/
		token = strtok(command_copy, delim);
		while(token != NULL)
		{
			token_count++;
			token = strtok(NULL,delim);
		}
		token_count++;
		/*allocat memory to array of variable*/
		argv = malloc(sizeof(char *) * token_count);
		
		
		if (argv == NULL)
			return (2);

		/*storing strings in argv*/
		token = strtok(command, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = strdup(token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

execmd(argv);
	/*if command exeutable*/
	if (access(command, X_OK) == 0)	
	     printf("%s\n", command);/*don't forget to remove*/
	
	else
		printf("no access:");
	}
	/*freeing*/
	for (i = 0; argv[i]; i++)
		free(argv[i]);

	free(argv);
	free(command);
	free(command_copy);
		return 0;
}
