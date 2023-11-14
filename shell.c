#include "main.h"
#include <sys/types.h>
#include <unistd.h>

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
pid_t proc_id;
char *prompt = "$ ";
char *command = NULL, *string;
size_t n = 0;
ssize_t char_num;
int i, status;

argv[0] = NULL;
argv[1] = NULL;


while(1)
	{
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
	i = 0;
	while(command[i] != '\0')
	{
	
		string[i-1] = command[i-1];
		i++;
	}
   argv[0] = string;
   argv[1] = NULL;
	/*creating a child proceess to make 
	 * my shell print $ after the excution*/
	proc_id = fork();

	 if(proc_id == -1)
   	 {
	    free(string);
	    free(command);
	    exit(EXIT_FAILURE);
	    }

	if (proc_id == 0)
	{	
	execve(argv[0], argv, env);
    	printf("no such file od directory\n");
	}
	
	else 
	wait(&status);
	
	}
    /* Handle error as needed */
	
	/*freeing*/
	free(string);
	free(argv);
	free(command);
}
