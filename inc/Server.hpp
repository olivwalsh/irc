/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:25:40 by owalsh            #+#    #+#             */
/*   Updated: 2023/03/16 17:17:52 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "irc.hpp"

class User;
class Command;

class Server
{
	public:
		Server(char *port, char *password);
		~Server(void);

		int		getListenerSocket(void);
		void	addSocket(int newFd);
		void	run(void);
		void	newConnection(void);
		void	receiveMessage(struct pollfd pfd);
		void	disconnect(User* user);
		void	clean(void);
		void	checkTime(void);
		void	checkConnection(void);
		User	*checkUser(std::string nickname);

		char	*getPort(void) const;
		char	*getPassword(void) const;
	
	private:
		char						*_port;
		char						*_password;
	
		struct addrinfo 			*_socketInfo;
		struct timeval				_start;
		int							_socketFd;

		std::vector<struct pollfd>	_pollFds;
		std::map<int, User *>		_users;
		Command*					_cmd;

		Server(void);
};

#endif