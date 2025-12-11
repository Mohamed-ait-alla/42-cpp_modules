// ****************************************************************************** //
//                        file: BitcoinExchange.hpp                               //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/08 09:15 by mait-all                   //
//                        Updated: 2025/12/11 10:15 by mait-all                   //
// ****************************************************************************** //

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <cstdlib>


void	launch(std::string file);
void	init_db(std::map<std::string, float>& map, std::string db);

#endif /* __BITCOINEXCHANGE_HPP__ */