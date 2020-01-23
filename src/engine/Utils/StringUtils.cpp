//
// Created by User on 15-Jan.-2020.
//

#include "StringUtils.h"

void StringUtils::split(std::vector<std::string>& buffer,const std::string& s, char separator) {

   std::size_t start = 0, end = 0;
   while ((end =s.find(separator, start)) != std::string::npos) {
      buffer.emplace_back(s.substr(start, end - start));
       start = end + 1;
   }
   buffer.emplace_back(s.substr(start));
   /*
    // method2
    size_t start=0;
    size_t end=s.find_first_of(delimiter);

    while (end <= std::string::npos)
    {
        buffer.emplace_back(s.substr(start, end-start));

        if (end == std::string::npos)
            break;

        start=end+1;
        end = s.find_first_of(delimiter, start);
    }
    */
}


