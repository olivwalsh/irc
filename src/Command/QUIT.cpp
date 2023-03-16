/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QUIT.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:59:56 by sbeylot           #+#    #+#             */
/*   Updated: 2023/03/16 17:25:41 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

/*
	Command: QUIT
	Parameters: [<reason>]
*/

void	QUIT(User *user)
{
	std::cout << "\033[1;32minside QUIT\033[0m;" << std::endl;
	
	if (send(user->getFd(), "\n", 2, MSG_NOSIGNAL) == -1)
		perror("send");
		
	user->getServer()->disconnect(user);
}