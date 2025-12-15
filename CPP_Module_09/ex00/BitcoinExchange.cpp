// ****************************************************************************** //
//                        file: BitcoinExchange.cpp                               //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/08 09:16 by mait-all                   //
//                        Updated: 2025/12/15 09:14 by mait-all                   //
// ****************************************************************************** //

#include "BitcoinExchange.hpp"

/**
 * Initializes the Bitcoin price database by reading the given CSV file
 * and filling the provided map with date → price entries.
 *
 * @param btcPricesDB   Reference to the map that will store the date/price pairs.
 * @param btcPricesFile Path to the CSV file (data.csv).
 */
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
 * Trims leading and trailing whitespace characters from the given string.
 *
 * @param s The string to be trimmed (input).
 * @return A new string with surrounding spaces removed.
 */
std::string	ft_trim(std::string& s)
{
	size_t	start = s.find_first_not_of(" \t\r");
	if (start == std::string::npos)
		return "";
	size_t	end = s.find_last_not_of(" \t\r");
	return (s.substr(start, end - start + 1));
}

/**
 * Validates a date string formatted as YYYY-MM-DD.
 * Ensures correct format, valid month/day ranges, and leap-year handling.
 *
 * @param date The date string to validate.
 * @return true if the date is valid, false otherwise.
 */
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

/**
 * Validates a numeric value from the user input.
 * Checks that the value is non-negative and between 0 and 1000
 * The flag parameter is updated to reflect validation status.
 *
 * @param value The floating-point value to validate.
 * @param flag  Reference used to store validation error codes.
 * @return true if the value is valid, false otherwise.
 */
bool	isValidValue(std::string value, int& flag)
{
	char*		endptr;
	double		toDouble;

	toDouble = std::strtod(value.c_str(), &endptr);
	if (endptr == value.c_str() || *endptr != '\0')
	{
		flag = -1;
		return (false);
	}
	if (toDouble < 0)
	{
		flag = -2;
		return (false);
	}
	if (toDouble > 1000)
	{
		flag = -3;
		return (false);
	}
	return (true);
}

/**
 * Processes a single input line after splitting key and value.
 * Validates both date and value, performs the Bitcoin price lookup,
 * and prints the corresponding result or error message.
 *
 * @param btcPricesDB The bitcoin database that's stored in a map container
 * @param key   The date extracted from the input line.
 * @param value The value extracted from the input line.
 */
void	processLine(std::map<std::string, float>& btcPricesDB, std::string key, std::string value)
{
	std::map<std::string, float>::iterator	priceIt;
	int	flag = 0;

	if (!isValidDate(key) || value.empty())
	{
		std::cout << "Error: bad input => " << key << std::endl;
		return ;
	}

	if (!isValidValue(value, flag))
	{
		if (flag == -1)
			std::cout << "Error: bad value => " << value << std::endl;
		if (flag == -2)
			std::cout << "Error: not a positive number." << std::endl;
		if (flag == -3)
			std::cout << "Error: too large a number." << std::endl;
		return ;
	}

	priceIt = btcPricesDB.upper_bound(key);
	if (priceIt == btcPricesDB.begin())
	{
		std::cout << "Error: date is too early (before bitcoin database starts)" << std::endl;
		return ;
	}
	else
	{
		--priceIt;
		std::cout << key << " => " << value << " = "
				  << static_cast<double>(atof(value.c_str()) * priceIt->second)
				  << std::endl;
	}
}

/**
 * Starts the main program workflow.
 *
 * @param file Path to the user-provided input file.
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
		if (ft_trim(key) == "date" || ft_trim(value) == "value")
			continue;
		processLine(btcDataBase, ft_trim(key), ft_trim(value));
	}
	f.close();
}