// ****************************************************************************** //
//                        file: BitcoinExchange.cpp                               //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/08 09:16 by mait-all                   //
//                        Updated: 2025/12/11 10:19 by mait-all                   //
// ****************************************************************************** //

#include "BitcoinExchange.hpp"







void	init_db(std::map<std::string, float>& btcPricesDB, std::string btcPricesFile)
{
	std::ifstream	dbFile(btcPricesFile.c_str());
	std::string 	readedLine;
	std::string		key;
	std::string		value;

	// check if data.csv is open or not
	if (!dbFile)
		throw std::runtime_error("Error: could not open *data.csv* file!");

	// skiping the first line: the header
	std::getline(dbFile, readedLine);

	// start reading from data.csv and fill out our map container
	while (std::getline(dbFile, readedLine))
	{
		key = readedLine.substr(0, readedLine.find(","));
		value = readedLine.substr(readedLine.find(",") + 1);
		btcPricesDB.insert(std::make_pair(key, atof(value.c_str())));
	}
	
	
	
}

/**
*
*
*
*
*/

void	launch(std::string file)
{
	std::map<std::string, float>	btcDataBase;
	std::ifstream					f(file.c_str());
	std::string						readedLine;
	std::string						key;
	std::string						value;

	if (!f)
		throw std::runtime_error("Error: could not open file!");
	init_db(btcDataBase, "data.csv");

	while (std::getline(f, readedLine))
	{
		key = readedLine.substr(0, readedLine.find("|"));
		value = readedLine.substr(readedLine.find("|") + 1);
		// skipping first line
		if (key == "Date" || value == "value")
			continue;
		
	}


}