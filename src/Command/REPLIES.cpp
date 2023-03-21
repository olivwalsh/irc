/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   REPLIES.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:37:22 by sbeylot           #+#    #+#             */
/*   Updated: 2023/03/21 14:35:51 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

std::string RPL_WELCOME(User *user) 
{
	return ":Welcome to the Internet Relay Network " + user->getNickname() + "!" +
	user->getUsername() + "@localhost";
}

std::string RPL_YOURHOST(void) 
{
	return "Your host is localhost, running version 1.0";
}

std::string RPL_CREATED(User *user) 
{
	std::string time = user->getServer()->getStartingTime(); 
	return "This server was created " + time;
}

std::string RPL_MYINFO(void)
{
	return "localhost 1.0 aiwroO OovimnqpsrtklbeI";
}

std::string RPL_YOUREOPER() 
{
	return ":You are now an IRC operator ";
}

std::string RPL_UMODEIS(User *user)
{
	std::string mode = "+";

	std::map<char, bool>::iterator it = user->modes.begin();
	for (; it != user->modes.end(); ++it)
	{
		if (it->second == true)
			mode += it->first;
	}
	return mode;
}

std::string RPL_CHANNELMODEIS(Channel *channel)
{
	std::string mode = channel->getName() + " +";

	std::map<char, std::string>::iterator it = channel->modes.begin();
	for (; it != channel->modes.end(); ++it)
	{
		if (!it->second.empty())
			mode += it->first;
	}
	return mode;
}

// = #lll :@simon
std::string RPL_NAMREPLY(Channel *channel)
{
	std::string reply;

	if (!channel->modes['s'].empty())
		reply += '@';
	else if (!channel->modes['p'].empty())
		reply += '*';
	else
		reply += '=';
	
	reply += " " + channel->getName();
	reply += " :";

	std::vector<User *>::iterator it = channel->members.begin();
	for (; it != channel->members.end(); ++it)
	{
		if (it != channel->members.begin())
			reply += " ";
		if ((*it)->isChannelOperator(channel))
			reply += "@";
		else
			reply += " ";
		reply += (*it)->getNickname();
	}
	return reply;	
}

// #lll :End of /NAMES list
std::string RPL_ENDOFNAMES(std::string channel)
{
	return channel + " :End of /NAMES list";
}

std::string ERR_CHANOPRIVSNEEDED(std::string channel)
{
	return channel + " :You're not channel operator";
}

std::string RPL_TOPIC(Channel *channel)
{
	return channel->getName() + " :" + channel->getTopic();
}

std::string RPL_NOTOPIC(std::string channel)
{
	return channel + " :No topic is set";
}
