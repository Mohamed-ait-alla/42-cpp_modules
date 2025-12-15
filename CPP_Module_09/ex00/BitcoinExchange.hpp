// ****************************************************************************** //
//                        file: BitcoinExchange.hpp                               //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/08 09:15 by mait-all                   //
//                        Updated: 2025/12/15 08:57 by mait-all                   //
// ****************************************************************************** //

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <cstdlib>
# include <sstream>
# include <iomanip>
# include <iterator>


void		launch(std::string file);
void		init_db(std::map<std::string, float>& btcPricesDB, std::string btcPricesFile);
bool		isValidDate(std::string date);
bool		isValidValue(std::string value, int& flag);
void		processLine(std::map<std::string, float>& btcPricesDB, std::string key, std::string value);
std::string	ft_trim(std::string& s);

#endif /* __BITCOINEXCHANGE_HPP__ */