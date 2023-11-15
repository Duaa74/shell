#include "main.h"
/**
 *
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
		while(location_cp != NULL)
		{
			dr_lenght = strlen(location_token);
			location_path = malloc(lenght + dr_lenght + 2);
			strcpy(location_path, location_token);
			strcat(location_path, "/");
		       	strcat(location_path, command);
		       	strcat(location_path, "\0");
			if(stat(locatio_path, buf) == 0)
			{
				free(locatio_cp);
				return (location_path);
			}
			else
			{
				free(locatio_path);
				location_token = strtok(NULL, ":");
			}
		}/*loop end*/
		free(path_copy);

        if (stat(command, &buffer) == 0)
        {
            return (command);
        }


        return (NULL);

    }


    return (NULL);
}
