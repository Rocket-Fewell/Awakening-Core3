/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef NPCUNARMEDHEADHIT1COMMAND_H_
#define NPCUNARMEDHEADHIT1COMMAND_H_

#include "CombatQueueCommand.h"

class NpcUnarmedHeadHit1Command : public CombatQueueCommand {
public:

	NpcUnarmedHeadHit1Command(const String& name, ZoneProcessServer* server)
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

#endif //NPCUNARMEDHEADHIT1COMMAND_H_
