#include "main.h"
/**
 * get_location - finding command path
 * @command: command path to be found
 * Return: pointer to path
 */
char *get_location(char *command)
{
	char *location, *location_cp, *location_token, *location_path;
	int lenght, dr_lenght;
	struct stat buf;


	location = getenv("PATH");
	if (location)
	{
		lenght = strlen(command);
		location_cp = strdup(location);
		location_token = strtok(location_cp, ":");
	
		while(location_token != NULL)
		{
			dr_lenght = strlen(location_token);
			location_path = malloc(lenght + dr_lenght + 2);
			strcpy(location_path, location_token);
			strcat(location_path, "/");
		       	strcat(location_path, command);
		       	strcat(location_path, "\0");
	
			if(stat(location_path, &buf) == 0)
			{
				free(location_cp);
				return (location_path);
			}
			
				free(location_path);
				location_token = strtok(NULL, ":");
			}
		/*loop end*/

free(location_cp);
	}
       if (stat(command, &buf) == 0)
        {
            return strdup(command);
        }


    return (NULL);
}
