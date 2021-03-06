#include <iostream>
#include "ShuttleFlight.h"
#include "Game.h"

ShuttleFlight::~ShuttleFlight()
{
}

void ShuttleFlight::execute()
{
    if (player->getLocation()->hasResearchStation())
    {
        std::vector<int> destinations;
        int count = 0;

        std::cout << "\n~ Where would you like to fly?" << std::endl;

        for (int i = 0; i < map->getVertexList().size(); i++)
        {
            if (dynamic_cast<CityVertex*>(map->getVertexList().at(i))->hasResearchStation() && player->getLocation() != dynamic_cast<CityVertex*>(map->getVertexList().at(i)))
            {
                destinations.push_back(i);
                count++;
                std::cout << "\t" << count << " - " << dynamic_cast<CityVertex*>(map->getVertexList().at(i))->getCity().toString() << std::endl;
            }
        }

        if (count == 0)
        {
            std::cout << "\n(!) There are no other cities with Research Stations!" << std::endl;
            player->incrementActions();
            return;
        }

        int choice = Game::getUserIntput(1, destinations.size() + 1);

        std::vector<Vertex*> cities = map->getVertexList();

        CityVertex* destination = dynamic_cast<CityVertex*>(cities.at(destinations.at(choice - 1)));
        player->setLocation(destination);
        if(player->getRoleSave()->getName() == "Medic" && board->hasCure(player->getLocation()->getCity().getColour())) {
            player->getLocation()->removeAllDiseaseCubes();
        }
    }
    else {
        std::cout << "\n(!) Your current city must have a Reasearch Station to complete this action!" << std::endl;
        player->incrementActions();
    }
}
