/* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
   Name: Hayaturehman Ahmadzai
   Email: hahmadzai3@myseneca.ca
   Student ID: 122539166
   Created on 2021-07-20.*/

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {
    extern std::deque<CustomerOrder> pending;
    extern std::deque<CustomerOrder> completed;
    extern std::deque<CustomerOrder> incomplete;

    class Workstation : public Station{
        std::deque<CustomerOrder> m_orders {};
        Workstation* m_pNextStation {};

    public:
        Workstation(const std::string& str);
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);


        Workstation(const Workstation& cpyFrom) = delete; //Copy Constructor
        Workstation& operator=(const Workstation& cpyFrom) = delete; //Copy Assignment Operator
        Workstation(Workstation&& mvFrom) = delete; //Move Constructor (*this = std::move(cpyFrom);)
        Workstation& operator=(Workstation&& mvFrom) = delete; //Move Assignment Operator
    };
}


#endif //SDDS_WORKSTATION_H
