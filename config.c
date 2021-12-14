#include "config.h"
#include "json.hpp"

/**
 * Intialize Config
 * Param [out] *Config (config_t)
 * Param [in] ConfigStr (std::string)
**/

void
config_initialize(struct config_t *Config, std::string ConfigStr)
{
	nlohmann::json j = nlohmann::json::parse(ConfigStr);
	Config->Hostname = j["Hostname"];
	Config->Migrate = j["Migrate"];

}
