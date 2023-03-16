/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PING.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:10:47 by foctavia          #+#    #+#             */
/*   Updated: 2023/03/16 19:09:29 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "irc.hpp"

/*
	Command: PING
	Parameters: <token>
*/

void	PING(User *user)
{
	std::cout << "\033[1;32minside PING\033[0m;" << std::endl;
	
	if (user->getCommand()->getParameters().empty())
	{
		user->sendMessage(user->formattedReply("409", ERR_NOORIGIN(user->getNickname())));
		return ;
	}
	
	// displayActivity(user, "PONG", SEND);
	std::cout << "[SERVER]: send PONG to " << user->getFd << std::endl;
	user->sendMessage(user->formattedMessage("PONG", user->getNickname(), ""));
}
