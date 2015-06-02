//
// Created by user on 02.06.15.
//

#include <iosfwd>
#include <ios>
#include <sstream>
#include "Helpers.h"

namespace Helpers {

    bool isFloat(std::string s) {
        std::istringstream iss(s);
        float f;
        iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
        // Check the entire string was consumed and if either failbit or badbit is set
        return iss.eof() && !iss.fail();
    }

    bool isFloatNumber(const std::string& string){
        std::string::const_iterator it = string.begin();
        bool decimalPoint = false;
        int minSize = 0;
        if(string.size()>0 && (string[0] == '-' || string[0] == '+')){
            it++;
            minSize++;
        }
        while(it != string.end()){
            if(*it == '.'){
                if(!decimalPoint) decimalPoint = true;
                else break;
            }else if(!std::isdigit(*it) && ((*it!='f') || it+1 != string.end() || !decimalPoint)){
                break;
            }
            ++it;
        }
        return string.size()>minSize && it == string.end();
    }

    bool isNumber(const std::string& s)
    {
        return !s.empty() && std::find_if(s.begin(),
                                          s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
    }

    std::string trimLeft(const std::string& str,
                                  const std::string& whitespace = " \t")
    {
        const auto strBegin = str.find_first_not_of(whitespace);

        if (strBegin == std::string::npos)
            return ""; // no content

        return str.substr(strBegin);
    }

    std::string trimRight(const std::string& str,
                                   const std::string& whitespace = " \t")
    {
        return str.substr(0, str.find_last_not_of(whitespace));
    }

    std::string trim(const std::string& str,
                              const std::string& whitespace = " \t")
    {
        return trimRight(trimLeft(str, whitespace), whitespace);
    }

    std::string reduce(const std::string& str,
                                const std::string& fill = " ",
                                const std::string& whitespace = " \t")
    {
        // trim first
        auto result = trim(str, whitespace);

        // replace sub ranges
        auto beginSpace = result.find_first_of(whitespace);
        while (beginSpace != std::string::npos)
        {
            const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
            const auto range = endSpace - beginSpace;

            result.replace(beginSpace, range, fill);

            const auto newStart = beginSpace + fill.length();
            beginSpace = result.find_first_of(whitespace, newStart);
        }

        return result;
    }

}



