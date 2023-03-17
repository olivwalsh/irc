/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KILL.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:37:00 by foctavia          #+#    #+#             */
/*   Updated: 2023/03/17 12:16:25 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

/*
	Command: KILL
	Parameters: <nickname> <comment>
*/

void	KILL(User *user)
{
	// std::cout << "\033[1;32minside KILL\033[0m;" << std::endl;
	
	// if (user->getMode() == OPER)
	{
		std::vector<std::string> args = user->getCommand()->getParameters();
		
		if (args.size() < 2)
			return user->sendMessage(user->formattedReply("461", ERR_NEEDMOREPARAMS(user->getCommand()->getName())));
		
		User	*target = user->getServer()->checkUser(args.at(0));

		if (target == NULL)
			return user->sendMessage(user->formattedReply("401", ERR_NOSUCHNICK(args.at(0))));

		else
			user->getServer()->disconnect(target);
	}
	// else
	// {
	// 	user->sendMessage(user->formattedReply("481", ERR_NOPRIVILEGES(user->getNickname)));
	// 	return ;
	// }
}