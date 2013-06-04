/* 
 * File:   CountdownComponent.hpp
 * Author: kolzi
 *
 * Created on 4 czerwiec 2013, 11:06
 */

#ifndef COUNTDOWNCOMPONENT_HPP
#define	COUNTDOWNCOMPONENT_HPP

#include <queue>

#include "Component.hpp"

struct Action
{
	double time;
	std::string name;
	std::string target;
};

class CompareByTime
{
public:
	bool operator() (const Action& lhs, const Action& rhs) const
	{
		return (lhs.time < rhs.time);
	}
};

struct CountdownComponent : public Component
{
	CountdownComponent(int EID);
	CountdownComponent(int EID, double startTime);
    CountdownComponent(rapidxml::xml_node<>* componentNode);
	
	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);
	
	double startTime;
	double timeLeft;
	bool toText;
	std::priority_queue<Action, std::vector<Action>, CompareByTime> actions;
};

#endif	/* COUNTDOWNCOMPONENT_HPP */

