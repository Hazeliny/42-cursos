/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:48:53 by linyao            #+#    #+#             */
/*   Updated: 2024/08/14 16:21:28 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HANDLE_ERRORS_H
# define HANDLE_ERRORS_H

# include <errno.h>

# define ERR_ARGV		"Error: incorrect numbers of input arguments"
# define ERR_OPEN		"Error: opening file"
# define ERR_READ		"Error: reading file"
# define ERR_EMPTY		"Error: empty file / formatted improperly"
# define ERR_MAP		"Error: map"
# define ERR_MEMO		"Error: memory"
# define ERR_LINE		"Error: number of elements is not equal to this line"


void	terminate(char *s);

#endif
