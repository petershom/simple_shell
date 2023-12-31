#include "shell.h"

/**
 * _myexit - Exit the shell.
 * @info: Structure containing potential arguments, used to maintain
 *        constant function prototype.
 * Return: Exits with a given exit status.
 *        (0) if info.argv[0] is not "exit".
 */
int my_exit(info_t *info)
{
    int exit_status;

    if (info->argv[1])  /* Check for an exit argument */
    {
        exit_status = _err_atoi(info->argv[1]);
        if (exit_status == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
            return (1);
        }
        info->err_num = _err_atoi(info->argv[1]);
        return (-2);
    }
    info->err_num = -1;
    return (-2);
}

/**
 * _mycd - Change the current directory of the process.
 * @info: Structure containing potential arguments, used to maintain
 *        constant function prototype.
 * Return: Always 0.
 */
int my_cd(info_t *info)
{
    char *s, *dir, buffer[1024];
    int chdir_ret;

    s = getcwd(buffer, 1024);
    if (!s)
        _puts("TODO: >>getcwd failure emsg here<<\n");
    if (!info->argv[1])
    {
        dir = _getenv(info, "HOME=");
        if (!dir)
            chdir_ret = /* TODO: Determine what this should be. */
                chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir);
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            _puts(s);
            _putchar('\n');
            return (1);
        }
        _puts(_getenv(info, "OLDPWD="));
        _putchar('\n');
        chdir_ret = /* TODO: Determine what this should be. */
            chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
    }
    else
        chdir_ret = chdir(info->argv[1]);
    if (chdir_ret == -1)
    {
        print_error(info, "can't cd to ");
        _eputs(info->argv[1]);
        _eputchar('\n');
    }
    else
    {
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}

/**
 * _myhelp - Provide help information.
 * @info: Structure containing potential arguments, used to maintain
 *        constant function prototype.
 * Return: Always 0.
 */
int my_help(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;
    _puts("Help call works. Function not yet implemented.\n");
    if (0)
        _puts(*arg_array); /* Temporary, unused workaround */
    return (0);
}

