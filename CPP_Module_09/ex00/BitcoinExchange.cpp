// ****************************************************************************** //
//                        file: BitcoinExchange.cpp                               //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/08 09:16 by mait-all                   //
//                        Updated: 2025/12/11 12:05 by mait-all                   //
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

bool	isValidDate(std::string date)
{

	int		daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int		y, m, d;
	char	dash1, dash2;
	bool	leap;

	// basic date checking
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	// parsing date
	std::istringstream iss(date);
	iss >> y >> dash1 >> m >> dash2 >> d;
	if (iss.fail() || dash1 != '-' || dash2 != '-')
		return (false);
	// date's feilds checking
	if ((y < 0 || y > 9999) || (m < 1 || m > 12))
		return (false);
	leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
	if (leap && m == 2)
		daysInMonth[1] = 29;
	if (d < 1 || d > daysInMonth[m - 1])
		return (false);
 
	return (true);
}

bool	isValidValue(float value, int& flag)
{
	if (value < 0)
	{
		flag = -1;
		return (false);
	}
	if (value > 1000)
	{
		flag = -2;
		return (false);
	}
	return (true);
}

void	processLine(std::string key, std::string value)
{
	int	flag = 0;

	if (!isValidDate(key) || value.empty())
		std::cout << "Error: bad input => " << key << std::endl;

	if (!isValidValue(atof(value.c_str()), flag))
	{
		if (flag == -1)
			std::cout << "Error: not a positive number." << std::endl;
		if (flag == -2)
			std::cout << "Error: too large a number." << std::endl;
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
	bool							isFound = false;

	if (!f)
		throw std::runtime_error("Error: could not open file!");
	init_db(btcDataBase, "data.csv");

	while (std::getline(f, readedLine))
	{
		key = readedLine.substr(0, readedLine.find("|"));
		isFound = (readedLine.find("|") != std::string::npos) ? true : false;
		value = isFound ? readedLine.substr(readedLine.find("|") + 1) : "";
		// skipping first line
		if (key == "date" || value == "value")
			continue;
		processLine(key, value);
		// std::cout << key << " => " << value << std::endl;
	}

	std::cout << "-------------- finish --------------\n";
}