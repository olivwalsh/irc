/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:16:01 by foctavia          #+#    #+#             */
/*   Updated: 2023/03/17 19:00:07 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "irc.hpp"

class User;

class Channel
{
	public:
		std::vector<User *>	members;
		std::vector<User *>	invites;
		std::vector<User *>	operators;
		
		Channel(void);
		Channel(std::string name);
		~Channel(void);

		std::string	getName(void) const;
		std::string getKey(void) const;
		std::string getMask(void) const;
		void		setName(std::string name);
		void		setKey(std::string key);
		void		setMask(std::string mask);
		
	
	private:
		std::string	_name;
		std::string	_key; // password
		std::string	_mask; // password
		
		
};

#endif
