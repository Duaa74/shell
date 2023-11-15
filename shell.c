#include "main.h"
#include <sys/types.h>
#include <unistd.h>

void task1(char **argv, char **env);

int main(int ac, char **argv, char **env)
{
if (ac <= 12) /* changed from 1 to 12*/
task1(argv,env);

    return (0);
}

void task1(char *argv[], char **env)
{
/*setting variable*/
pid_t proc_id;
char *prompt = "$ ";
char *command = NULL, *string;
size_t n = 0;
ssize_t char_num;
int i, j,status;

argv[0] = NULL;
argv[1] = NULL;


while(1)
	{
	if(isatty(STDIN_FILENO))/*isatty adde */
	printf("%s", prompt);/*printing prompt*/

	char_num = getline(&command, &n, stdin);/*getting command*/
	
	if (char_num == -1)
	{
		free(command);
		exit (EXIT_FAILURE);
	}
/*allocate space for string*/

	string = malloc(sizeof(char) * (char_num));
	if (string == NULL)
		exit (EXIT_FAILURE);

/*deleting the NULL operator*/
	i = 0;/*reseeting i to zero after every excetuon*/

	while(command[i] != '\0')
	{
	
		string[i-1] = command[i-1];
		i++;
	}
	string[i] = '\0';
j = 0;
     	argv[j] = strtok(string," ");
   
   while (argv[j])/* setting values of argv[]*/
   {
	   argv[j+1] = strtok(NULL," ");
	   ++j;
   }
/*fork must not be called if command doeasn't found*/
   
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
    	printf("%s :no such file or directory\n",argv[1]);
	}
	
	else
	wait(&status);
	}/*end of wile loop*/
    /* Handle error as needed */
	
	/*freeing*/
	free(string);
	free(argv);
	free(command);
}
