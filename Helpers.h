//
// Created by user on 02.06.15.
//

#ifndef COURSEWORK_HELPERS_H
#define COURSEWORK_HELPERS_H

namespace Helpers {
    bool isFloat(std::string s);
    bool isFloatNumber(const std::string &string);
    bool isNumber(const std::string &s);
    std::string trimLeft(const std::string &str, const std::string &whitespace);
    std::string trimRight(const std::string &str, const std::string &whitespace);
    std::string trim(const std::string &str, const std::string &whitespace);
    std::string reduce(const std::string &str, const std::string &fill, const std::string &whitespace);
}

#endif //COURSEWORK_HELPERS_H
