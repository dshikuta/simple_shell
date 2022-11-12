#include "shell.h"

/**
<<<<<<< HEAD
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

int _myenv(info_t *info)

{

	print_list_str(info->env);

	return (0);

}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */

char *_getenv(info_t *info, const char *name)

{

	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);

		if (p && *p)

			return (p);

		node = node->next;

	}

	return (NULL);

}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */

int _mysetenv(info_t *info)

{

	if (info->argc != 3)

	{

		_eputs("Incorrect number of arguements\n");

		return (1);

	}

	if (_setenv(info, info->argv[1], info->argv[2]))

		return (0);

	return (1);

}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */

int _myunsetenv(info_t *info)

{

	int i;


=======
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);

	return (0);
}
/**
 * unset_alias - sets alias to string
 * @info: parameter struc
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{

	char *p, c;

	int ret;

	p = _strchr(str, '=');

	if (!p)

		return (1);

	c = *p;

	*p = 0;

	ret = delete_node_at_index(&(info->alias),

		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));

	*p = c;

	return (ret);
}
/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)

{
	char *p;

	p = _strchr(str, '=');

	if (!p)

		return (1);

	if (!*++p)

		return (unset_alias(info, str));

	unset_alias(info, str);

	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{

	char *p = NULL, *a = NULL;

	if (node)

	{
		p = _strchr(node->str, '=');

		for (a = node->str; a <= p; a++)

			_putchar(*a);

		_putchar('\'');

		_puts(p + 1);

		_puts("'\n");

		return (0);

	}

	return (1);
}
/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{

	int i = 0;

	char *p = NULL;

	ist_t *node = NULL;
>>>>>>> 01d748b56eedd4cd57cd22e367210a84075e44e7

	if (info->argc == 1)

	{
<<<<<<< HEAD

		_eputs("Too few arguements.\n");

		return (1);

	}

	for (i = 1; i <= info->argc; i++)

		_unsetenv(info, info->argv[i]);

	return (0);

}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

int populate_env_list(info_t *info)

{

	list_t *node = NULL;

	size_t i;



	for (i = 0; environ[i]; i++)

		add_node_end(&node, environ[i], 0);

	info->env = node;

	return (0);

=======
		node = info->alias;

		while (node)

		{

			print_alias(node);

			node = node->next;

		}

		return (0);

	}

	for (i = 1; info->argv[i]; i++)

	{
		p = _strchr(info->argv[i], '=');

		if (p)

			set_alias(info, info->argv[i]);

		else

			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
>>>>>>> 01d748b56eedd4cd57cd22e367210a84075e44e7
}
