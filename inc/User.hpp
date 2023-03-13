/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:34:41 by owalsh            #+#    #+#             */
/*   Updated: 2023/03/13 11:38:15 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP

# include "irc.h"
# include "Message.hpp"

class Message;

class User
{
	public:
		std::string		input;
		
		User( struct pollfd pfd, const char *address );
		~User();
		
		std::string 	getUsername() const;
		std::string		getNickname() const;
		struct pollfd 	getPollFd() const;
		int 			getFd() const;
		
		void 			setUsername(std::string username);
		void 			setNickname (std::string nickname);
		void 			setPollFd(struct pollfd pfd);
		void 			buildMessage();
		Message*		getMessage() const;

		void 			parseMessage();
		
	private:
		bool			_valid;
		const char		*_address;
		std::string 	_username;
		std::string 	_nickname;
		struct pollfd	_pfd;
		Message*		_message;
		
		User();
};

#endif