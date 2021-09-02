/* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
   Name: Hayaturehman Ahmadzai
   Email: hahmadzai3@myseneca.ca
   Student ID: 122539166
   Created on 2021-07-21.*/

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H


#include <vector>
#include "Workstation.h"

namespace sdds {
    class LineManager {
        std::vector<Workstation*> activeLine;
        size_t m_cntCustomerOrder;
        Workstation* m_firstStation;

    public:
        LineManager(const std::string& ws, const std::vector<Workstation*>& stations);
        void linkStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;
    };
}


#endif //SDDS_LINEMANAGER_H
