#include "shell.h"

int find_command(char *cmd, char **env)
{
    char *path = getenv_path(env);
    char *full_path;
    char *token;
    struct stat st;

    if (!path || !cmd)
        return (0);

    token = strtok(path, ":");
    while (token)
    {
        full_path = malloc(strlen(token) + strlen(cmd) + 2);
        if (!full_path)
            return (0);

        sprintf(full_path, "%s/%s", token, cmd);

        if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
        {
            free(cmd);
            cmd = strdup(full_path);
            free(full_path);
            return (1);
        }

        free(full_path);
        token = strtok(NULL, ":");
    }
    return (0);
}

char *getenv_path(char **env)
{
    size_t i = 0;

    while (env[i])
    {
        if (strncmp(env[i], "PATH=", 5) == 0)
            return (env[i] + 5);
        i++;
    }
    return (NULL);
}