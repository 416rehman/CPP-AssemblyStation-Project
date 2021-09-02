/* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
   Name: Hayaturehman Ahmadzai
   Email: hahmadzai3@myseneca.ca
   Student ID: 122539166
   Created on 2021-07-09.*/

#include "Utilities.h"

namespace sdds {
    char Utilities::m_delimiter{};

    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const
    {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
    {
        size_t idxOfDelimiter = (str.find(getDelimiter(), next_pos));
        std::string extracted = str.substr(next_pos, idxOfDelimiter - next_pos);

        if (idxOfDelimiter == next_pos)
        {
            more = false;
            throw std::string("Failed to find the delimiter");
        }

        next_pos = idxOfDelimiter + 1;

        setFieldWidth(std::max(m_widthField, extracted.size()));
        more = idxOfDelimiter != std::string::npos;

        return extracted;
    }

    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }
}