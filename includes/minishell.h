/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 09:33:37 by hthomas           #+#    #+#             */
/*   Updated: 2020/07/03 13:23:38 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef minishell_H
# define minishell_H

# include <unistd.h>
# include <sys/types.h>
# include <time.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include "get_next_line.h"

# define WELCOME_MSG "────────────────────────────────\n\
────────▄███████████████▄───────\n\
───────███████████████████──────\n\
─────██████▀───██───▀███████────\n\
───████████────██────████████───\n\
──███───▀███───██───███▀───███──\n\
──████────██───██───██────████──\n\
─██████───██───██───██───██████─\n\
─██──██───██───██───██───██──██─\n\
─██───██───██──██──██───██───██─\n\
███───██───██──██──██───██───███\n\
███────██──██──██──██──██────███\n\
████───██──██──██──█───██───████\n\
██─██───██──█──██──█──██───██─██\n\
██──██──██──██─██─██──██──██──██\n\
██──███──██─██─██─██─██──███──██\n\
██───██──██──█─██─█──██──██───██\n\
██────██──██─█─██─█─██──██────██\n\
███▄───██──█─█─██─█─█───█───▄███\n\
████▄───██─█──█──█──█──█───▄████\n\
─█████───█──█─█──█─█──█───█████─\n\
───████───█──────────█───████───\n\
─────███────────────────███─────\n\
──────██────────────────██──────\n\
──────██────────────────██──────\n\
──────████████▄──▄████████──────\n\
──────████████████████████──────\n\
──────────────▀██▀──────────────\n\
────────────────────────────────\n\
──▄█████▄─██─────────────██─██──\n\
──██───▀▀─██─────────────██─██──\n\
──██▄─────██─────────────██─██──\n\
──██████▄─█████▄─▄█████▄─██─██──\n\
───▀█████─██──██─███──██─██─██──\n\
───────██─██──██─██████▀─██─██──\n\
──▄▄──▄██─██──██─███──▄▄─██─██──\n\
──▀█████▀─██──██─▀█████▀─██─██──\n\
────────────────────────────────\n"


#endif