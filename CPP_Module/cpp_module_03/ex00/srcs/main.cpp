/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:48:23 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/24 11:41:19 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

int	main(void) {
	{
		ClapTrap	jeolim("jeolim");
		jeolim.attack("Rock");
		jeolim.takeDamage(5);
		jeolim.beRepaired(5);
	}
	return (0);
}