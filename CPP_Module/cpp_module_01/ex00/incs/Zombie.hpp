#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string	_name;
	
	public:
		Zombie(void);
		Zombie(const std::string &name);
		Zombie(const Zombie &ref);
		~Zombie(void);
		Zombie	&operator=(const Zombie &rhs);
	
		// Util
		void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif