#include <iostream>
#include "config.h"
#include "json.hpp"

CONFIG* Conf = new CONFIG;

static
std::string decrypt_xor(char* encString) {
	std::string decString = "";
	int key = 81;

	for (char c = *encString; c; c=*++encString) {
		if (c == -1) {
			break;
		}
		decString += (c ^ key) % 255;
	}
	return decString;
}

int main()
{
	std::string res(decrypt_xor((char*) CONFIG_BUFFER));
	config_initialize(Conf, res);
	std::cout << Conf->Hostname << " " << Conf->Migrate;
}
