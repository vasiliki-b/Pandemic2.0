#pragma once

#include <list>
#include "Graph.h"
#include "Deck.h"
#include "DiseaseColour.h"

class Board
{
public:
	Board() { this->outbreakMarker = 0; this->infectionRateIndex = 0; };
	~Board();
	void increaseOutbreakMarker() { this->outbreakMarker++; };
	int getOutbreakMarker() { return outbreakMarker; };
	void increaseInfectionRate();
	int getInfectionRate() { return infectionRate[infectionRateIndex]; };
	void addCureMarker(Disease::Colour colour);
	void flipCureMarker(Disease::Colour colour);
	bool hasCure(Disease::Colour colour);
	std::string toString();

private:
	int outbreakMarker;
	int infectionRate[7] = { 2, 2, 2, 3, 3, 4 };
	int infectionRateIndex;
	bool cureMarkers[4] = { false, false, false, false };
	bool eradicatedMarkers[4] = { false, false, false, false };
};
