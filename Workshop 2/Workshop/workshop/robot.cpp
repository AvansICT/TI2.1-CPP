#include <iostream>
#include "log.hpp"
#include "robot.hpp"

namespace avans {

    Robot::Robot(uint32_t ipaddr, unsigned int id)
    {
        // initialize robot info
        info.ipaddr = ipaddr;
        dir = Up; // default direction
    }

    Robot::~Robot(void)
    {
    }
    
    //private method to log the direction change
    void Robot::logDirectionChange(direction newDir)
    {// Log de richtingsverandering (bijvoorbeeld naar een bestand of console)
        std::cout << "Richting veranderd naar: ";
        switch (newDir) {
        case Left:
            std::cout << "Links" << std::endl;
            break;
        case Right:
            std::cout << "Rechts" << std::endl;
            break;
        case Up:
            std::cout << "Boven" << std::endl;
            break;
        case Down:
            std::cout << "Beneden" << std::endl;
            break;
        default:
            std::cout << "Onbekend" << std::endl;
            break;
        }
    }

    void Robot::setDirection(direction d){
        dir = d;
        
        logDirectionChange(d);
    }

    direction Robot::getDirection(void) {
        return dir;
    }

}
