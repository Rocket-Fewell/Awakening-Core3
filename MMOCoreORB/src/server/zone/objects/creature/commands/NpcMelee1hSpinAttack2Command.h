/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef NPCMELEE1HSPINATTACK2COMMAND_H_
#define NPCMELEE1HSPINATTACK2COMMAND_H_

#include "CombatQueueCommand.h"

class NpcMelee1hSpinAttack2Command : public CombatQueueCommand {
public:

	NpcMelee1hSpinAttack2Command(const String& name, ZoneProcessServer* server)
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

#endif //NPCMELEE1HSPINATTACK2COMMAND_H_
