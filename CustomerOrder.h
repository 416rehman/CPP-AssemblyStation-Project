/* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
   Name: Hayaturehman Ahmadzai
   Email: hahmadzai3@myseneca.ca
   Student ID: 122539166
   Created on 2021-07-15.*/

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <string>
#include "Station.h"

namespace sdds {

    struct Item {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string& src) : m_itemName(src)
        {};
    };

    class CustomerOrder {
        std::string m_name;
        std::string m_product;
        size_t m_cntItem;
        Item **m_lstItem;

        static size_t m_widthField;

    public:
        CustomerOrder();
        CustomerOrder(const std::string& str);

        CustomerOrder(const CustomerOrder&){ throw "Copying Disabled"; };
        CustomerOrder& operator=(const CustomerOrder&) = delete;
        CustomerOrder(CustomerOrder&& src) noexcept;
        CustomerOrder& operator=(CustomerOrder&& src) noexcept;
        virtual ~CustomerOrder();

        bool isFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;

    };
}


#endif //SDDS_CUSTOMERORDER_H
