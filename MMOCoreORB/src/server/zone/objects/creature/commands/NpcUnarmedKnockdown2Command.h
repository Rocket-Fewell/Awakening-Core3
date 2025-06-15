/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef NPCUNARMEDKNOCKDOWN2COMMAND_H_
#define NPCUNARMEDKNOCKDOWN2COMMAND_H_

#include "CombatQueueCommand.h"

class NpcUnarmedKnockdown2Command : public CombatQueueCommand {
public:

	NpcUnarmedKnockdown2Command(const String& name, ZoneProcessServer* server)
		: CombatQueueCommand(name, server) {
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		return doCombatAction(creature, target);
	}

};

#endif //NPCUNARMEDKNOCKDOWN2COMMAND_H_
