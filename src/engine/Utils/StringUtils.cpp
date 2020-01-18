//
// Created by User on 15-Jan.-2020.
//

#include "StringUtils.h"

void StringUtils::split(std::vector<std::string>& buffer,std::string s, char separator) {

   std::size_t start = 0, end = 0;
   while ((end =s.find(separator, start)) != std::string::npos) {
      buffer.push_back(s.substr(start, end - start));
       start = end + 1;
   }
   buffer.push_back(s.substr(start));

}
