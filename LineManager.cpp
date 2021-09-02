/* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
   Name: Hayaturehman Ahmadzai
   Email: hahmadzai3@myseneca.ca
   Student ID: 122539166
   Created on 2021-07-21.*/

#include <fstream>
#include <algorithm>
#include "Utilities.h"
#include "LineManager.h"

namespace sdds {

    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
    {
        std::ifstream file_(file);
        if (!file_) throw "Failed to open the file";
        else {
            Utilities utils;
            bool more;
            size_t npos = 0;

            std::string fileLine, currWSname, nxtWSname;

            Workstation* nxtWS = nullptr;
            Workstation* currWS = nullptr;
            Workstation* firstWS = nullptr;
            while (std::getline(file_, fileLine))
            {
                currWSname = utils.extractToken(fileLine, npos, more);
                currWS = *std::find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                    return ws->getItemName() == currWSname;
                });
                activeLine.push_back(currWS);

                if (more) {
                    nxtWSname = utils.extractToken(fileLine, npos, more);
                    nxtWS = *std::find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                        return ws->getItemName() == nxtWSname;
                    });
                    currWS->setNextStation(nxtWS);
                }
            }

            for_each(stations.begin(), stations.end(), [&](Workstation* tmp) {
                firstWS = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
                    return station->getNextStation() == firstWS;
                });
            });

            m_firstStation = firstWS;
        }
        file_.close();
        m_cntCustomerOrder = pending.size();
    }

    void LineManager::linkStations()
    {
        const Workstation* ws = m_firstStation;
        size_t i{0};
        do
        {
            activeLine[i++] = const_cast<Workstation*>(ws);
            ws = ws->getNextStation();
        } while (ws != nullptr);
    }

    bool LineManager::run(std::ostream& os){
        static size_t iterations = 0;
        os << "Line Manager Iteration: " << ++iterations << std::endl;

        if (!pending.empty()) {
            *m_firstStation += std::move(pending.front());
            pending.pop_front();
        }

        std::for_each(activeLine.begin(),activeLine.end(), [&os](Workstation* ws){
            ws->fill(os);
        });
        std::for_each(activeLine.begin(),activeLine.end(), [](Workstation* ws){
            ws->attemptToMoveOrder();
        });

        return m_cntCustomerOrder == (completed.size() + incomplete.size());
    }

    void LineManager::display(std::ostream& os) const
    {
        if (!activeLine.empty())
            for (auto& i : activeLine)
                i->display(os);
    }
}