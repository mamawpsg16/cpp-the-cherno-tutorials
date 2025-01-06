#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

struct CityRecord {
	std::string name;
	uint64_t population;
	double latitude, longitude;
};

namespace std {
	template<>
	struct hash<CityRecord> {
		size_t operator()(const CityRecord& key) {
			return hash<std::string>()(key.name);
		}
	};
}
//int main() {
	//std::vector<CityRecord> cities;

	//cities.emplace_back("Philippines", 80000000, 2.4, 2.5);
	//cities.emplace_back("Paris", 24000000, 2.6, 2.7);
	//cities.emplace_back("USA", 7000000, 3, 3.5);


	/* ORDERED MAP */
	//std::map<std::string, CityRecord> cityMap;
	//cityMap["Philippines"] = CityRecord{ "Philippines", 80000000, 2.4, 2.5 };
	//cityMap["Paris"] = CityRecord{ "Paris", 24000000, 2.6, 2.7 };
	//cityMap["Australia"] = CityRecord{ "Australia", 5789012, 2.7, 2.9 };
	//cityMap["USA"] = CityRecord{ "USA", 7000000, 3, 3.5 };


	//CityRecord& philippinesData = cityMap["Philippines"];
	//std::cout << philippinesData.population << '\n';

	/*for (auto& [key, data] : cityMap)
	{
		std::cout << key << '\n';
	}*/
	//for (std::map<std::string, CityRecord>::iterator it = cityMap.begin(); it != cityMap.end(); it++)
	//{
	//	std::cout << it->first << '\t' << it->second.population << '\n';
	//}

	/* UNORDERED MAP */

	//std::unordered_map<std::string, CityRecord> cityMap;
	//cityMap["Philippines"] = CityRecord{ "Philippines", 80000000, 2.4, 2.5 };
	//cityMap["Paris"] = CityRecord{ "Paris", 24000000, 2.6, 2.7 };
	//cityMap["Australia"] = CityRecord{ "Australia", 5789012, 2.7, 2.9 };
	//cityMap["USA"] = CityRecord{ "USA", 7000000, 3, 3.5 };
	//
	//const auto& cities = cityMap;
	//if (cities.find("Philippines") != cities.end()) {

	//	const CityRecord& philippinesData = cities.at("Philippines");
	//	std::cout << philippinesData.name << "= " << philippinesData.population << '\n';
	//}
	//CityRecord& philippinesData = cityMap["Philippines"];
	//for (auto& [key, data] : cityMap)
	//for (auto& kv : cityMap)
	//{
	//		std::string key = kv.first;
	//		CityRecord& data = kv.second;

	//		std::cout << key << '=' << data.population << '\n';
	//}
	
//}