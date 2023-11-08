#include "main.h"

int main(void)
{
	char *prompt = "duaa $ ";
	size_t n = 0;
	char *command = NULL;
	ssize_t char_num = 0;
  
	while (1)
	{
		printf("%s", prompt);
		char_num = getline(&command, &n , stdin);
		if (char_num == -1)
		
		{
			perror("./main: ");
			free(command);
			return (-1);
		}	
	
		printf("%s\n", command);
		
	}
	
	
	return 0;
}
