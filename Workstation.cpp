/* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
   Name: Hayaturehman Ahmadzai
   Email: hahmadzai3@myseneca.ca
   Student ID: 122539166
   Created on 2021-07-20.*/

#include <iostream>
#include "Workstation.h"

namespace sdds {
    std::deque<CustomerOrder> pending {};
    std::deque<CustomerOrder> completed {};
    std::deque<CustomerOrder> incomplete {};
    Workstation::Workstation(const std::string& str) : Station(str)
    {}

    void Workstation::fill(std::ostream& os)
    {
        if (!m_orders.empty()) m_orders.front().fillItem(*this, os);
    }

    bool Workstation::attemptToMoveOrder()
    {
        bool isMoved = false;
        if (!m_orders.empty()) {
            if (m_orders.front().isItemFilled(getItemName())) {
                if (!m_pNextStation) {
                    if (m_orders.front().isFilled())
                        completed.push_back(std::move(m_orders.front()));
                    else incomplete.push_back(std::move(m_orders.front()));
                }
                else *m_pNextStation += std::move(m_orders.front());
                m_orders.pop_front();
                isMoved = true;
            }
            else if (!getQuantity()) {
                if (!m_pNextStation) incomplete.push_back(std::move(m_orders.front()));
                else *m_pNextStation += std::move(m_orders.front());
                m_orders.pop_front();
                isMoved = true;
            }
        }
        return isMoved;
    }

    void Workstation::setNextStation(Workstation *station)
    {
        if (m_pNextStation != nullptr) delete m_pNextStation;
        m_pNextStation = station;
    }

    Workstation *Workstation::getNextStation() const
    {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const
    {
        os << getItemName() << " --> " << (m_pNextStation == nullptr ? "End of Line" : m_pNextStation->getItemName()) << '\n';
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
    {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }
}