#ifndef SHELL_H
#define SHELL_H

/***** MACROS *****/
#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"

/*** STANDARD LIBRARIES ***/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

char *_strncpy(char *dest, char *src, int num);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t num);
char *_strdup(char *str);
void free_env(char **env);
void *fill_array_with_char(void *a, int el, unsigned int len);
char *copy_memory(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all_memory(char **input, char *line);
char *_getline();
char *removeLeadingSpaces(char *str);
char *enter(char *string);
void removeHashTag(char *buff);
void display_prompt(void);
unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);
int save_history(char *input);
char **separate_commands(char *input);
void read_commands_file(char *file, char **argv);
void process_command_file(char *line, int count, FILE *fp, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);
char **parse_command(char *input);
int handle_builtin(char **cmd, int er);
int execute_command(char *input, char **argv);
void handle_signal(int sig);
void display_error_message(char *input, int counter, char **argv);
void display_illegal_number_error(char **argv, int error_count, char **cmd);
void display_file_error(char **argv, int error_count);
extern char **environ;
void create_environment_array(char **env_array);
void free_environment_array(char **env_array);
void print_unsigned_integer(unsigned int num);
void print_integer(int num);
int execute_builtin_echo(char **cmd);
int path_command(char **cmd);
char *build_command_path(char *token, char *value);
char *get_env_variable(char *name);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
int display_help(char **cmd, __attribute__((unused))int st);
int check_builtin(char **cmd);
int handle_builtin(char **cmd, int st);
void exit_bul(char **cmd, char *input, char **argv, int c, int stat);
int change_directory(char **cmd, __attribute__((unused))int st);
int display_environment(__attribute__((unused)) char **cmd,
	    __attribute__((unused)) int st);
int execute_echo(char **cmd, int st);
int display_history(__attribute__((unused))char **c,
		__attribute__((unused)) int st);


/**
 * struct _builtin - Defines a struct that conatins built-in commands
 * with their respective implementation functions
 * @command: - Built-in command
 * @function: - Pointer to custom functions that have
 * similar functionalities as the built-in commands
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

#endif /*SHELL_H*/
