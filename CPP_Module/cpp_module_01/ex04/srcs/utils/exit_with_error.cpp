/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:11:07 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/09 23:51:33 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.hpp"

void	exit_with_error(const std::string &message, bool exit_flag);

void	exit_with_error(const std::string &message, bool exit_flag) {
	std::cerr << "\033[31mError: " << message << "\033[0m\n";
	exit(exit_flag);
}