/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:10:10 by isojo-go          #+#    #+#             */
/*   Updated: 2023/03/11 15:29:53 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct s_cmd
{
	char			*str;
	int				infd;
	int				outfd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct s_data
{
	int		base_stdin;
	int		base_stdout;
	int		status;
	t_cmd	*cmd;
}			t_data;

t_data	*ft_init_data(t_data *data)
{
	int	i;

	data = (t_data *)malloc(sizeof(data));
	if (!data)
		return (NULL);
	data->base_stdin = dup(STDIN_FILENO);
	data->base_stdout = dup(STDOUT_FILENO);
	data->status = 0;
	data->cmd = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc == 1)
		return (EXIT_SUCCESS);
	data = ft_init_data(data);
	ft_parse(data, argv);
	ft_exec(data, envp);
	return(data->status);
}
