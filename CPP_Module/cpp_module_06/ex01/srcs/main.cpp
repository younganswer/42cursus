#include "../incs/Serialize.hpp"
#include <iostream>

int	main(void) {
	{
		Data 		*data = new Data("Hello", "World", 42);
		uintptr_t 	serialized = Serialize::serialize(data);
		Data 		*deserialized = Serialize::deserialize(serialized);
		char		*str1 = (char *)data;
		char		*str2 = (char *)serialized;
		char		*str3 = (char *)deserialized;
		int			i1 = *(int *)data;
		int			i2 = *(int *)serialized;
		int			i3 = *(int *)deserialized;

		{
			std::cout << "Address of variables" << '\n';
			std::cout << "Data: " << data << '\n';
			std::cout << "Serialized: " << serialized << '\n';
			std::cout << "Deserialized: " << deserialized << '\n';
		}
		std::cout << '\n';
		{
			std::cout << "Values of Data" << '\n';
			std::cout << data->s1 << ' ' << data->s2 << '\n';
			std::cout << data->n << '\n';
		}
		std::cout << '\n';
		{
			std::cout << "Values of Deserialized" << '\n';
			std::cout << deserialized->s1 << ' ' << deserialized->s2 << '\n';
			std::cout << deserialized->n << '\n';
		}
		std::cout << '\n';
		{
			std::cout << "String value of each pointer points to" << '\n';
			std::cout << "String 1: " << str1 << '\n';
			std::cout << "String 2: " << str2 << '\n';
			std::cout << "String 3: " << str3 << '\n';
		}
		std::cout << '\n';
		{
			std::cout << "Bits of string value of each pointer points to" << '\n';
			std::cout << "String 1:";
			for (int i=0; i<8; i++) {
				std::cout << ' ' << std::bitset<8>(str1[i]);
			}
			std::cout << '\n';
			std::cout << "String 2:";
			for (int i=0; i<8; i++) {
				std::cout << ' ' << std::bitset<8>(str2[i]);
			}
			std::cout << '\n';
			std::cout << "String 3:";
			for (int i=0; i<8; i++) {
				std::cout << ' ' << std::bitset<8>(str3[i]);
			}
			std::cout << '\n';
		}
		std::cout << '\n';
		{
			std::cout << "Integer value of each pointer points to" << '\n';
			std::cout << "Integer 1: " << i1 << '\n';
			std::cout << "Integer 2: " << i2 << '\n';
			std::cout << "Integer 3: " << i3 << '\n';
		}
		std::cout << '\n';
		{
			std::cout << "Bits of integer value of each pointer points to" << '\n';
			std::cout << "Integer 1:";
			for (int i=0; i<4; i++) {
				std::cout << ' ' << std::bitset<8>(i1 >> (4 - i) * 8);
			}
			std::cout << '\n';
			std::cout << "Integer 2:";
			for (int i=0; i<4; i++) {
				std::cout << ' ' << std::bitset<8>(i2 >> (4 - i) * 8);
			}
			std::cout << '\n';
			std::cout << "Integer 3:";
			for (int i=0; i<4; i++) {
				std::cout << ' ' << std::bitset<8>(i3 >> (4 - i) * 8);
			}
			std::cout << '\n';
		}
		std::cout << '\n';
		delete data;
	}
	system("leaks $PPID 2>/dev/null 1>leaks_result && cat leaks_result | grep leaked && rm leaks_result");
	return (0);
}