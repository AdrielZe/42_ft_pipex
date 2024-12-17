/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:14:00 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/17 18:33:53 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> 
# include <unistd.h> 
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "../libft/libft.h"

char	*search_valid_path(char *cmd, char **envp);

#endif