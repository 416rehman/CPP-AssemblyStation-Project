/* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
   Name: Hayaturehman Ahmadzai
   Email: hahmadzai3@myseneca.ca
   Student ID: 122539166
   Created on 2021-07-09.*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <string>

namespace sdds {
    class Utilities {
        size_t m_widthField = 1;
        static char m_delimiter;
    public:
        void setFieldWidth(size_t newWidth);

        size_t getFieldWidth() const;

        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

        static void setDelimiter(char newDelimiter);

        static char getDelimiter();
    };
}


#endif //SDDS_UTILITIES_H
