/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:25:40 by owalsh            #+#    #+#             */
/*   Updated: 2023/03/03 16:22:42 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "irc.h"

class Server
{
	public:
		Server( char *port, char *password );
		~Server( void );

		int		getListenerSocket( void );
		void	addSocket( int newFd );
		void	run( void );
		void	newConnection( void );
		void	receiveMessage( struct pollfd pfd );
		void	sendMessage( int senderFd, std::string &message );
		void	disconnect( struct pollfd pfd );
		void	clean( void );

		char	*getPort( void ) const;
		char	*getPassword( void ) const;
	
	private:
		char				*_port;
		char				*_password;
	
		struct addrinfo 	*_socketInfo;
		int					_socketFd;

		std::vector<struct pollfd>	_pollFds;
		std::map<int, User *>		_users;
		
		Server( void );
};

#endif