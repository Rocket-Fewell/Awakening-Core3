/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef RELOADCHILDOBJECTSCOMMAND_H_
#define RELOADCHILDOBJECTSOMMAND_H_

#include "server/zone/objects/building/BuildingObject.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ReloadChildObjectsCommand {
public:
	static int executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments) {
		PlayerObject* ghost = creature->getPlayerObject();

		if (ghost == nullptr || !ghost->isAdmin())
			return 1;

		ManagedReference<BuildingObject*> building = creature->getParentRecursively(SceneObjectType::BUILDING).castTo<BuildingObject*>();

		if (building == nullptr)
			return 1;

		building->destroyChildObjects();
		building->createChildObjects();

		creature->sendSystemMessage("Building child objects sucessfully reloaded.");

		return 0;
	}
};

#endif /* RELOADCHILDOBJECTSCOMMAND_H_ */
