/*
---------------------------------------------------------------------------------------
This source file is part of SWG:ANH (Star Wars Galaxies - A New Hope - Server Emulator)

For more information, visit http://www.swganh.com

Copyright (c) 2006 - 2010 The SWG:ANH Team
---------------------------------------------------------------------------------------
Use of this source code is governed by the GPL v3 license that can be found
in the COPYING file or at http://www.gnu.org/licenses/gpl-3.0.html

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
---------------------------------------------------------------------------------------
*/

#include "JediSkillManager.h"
#include "ObjectControllerCommandMap.h"
#include "ObjectControllerOpcodes.h"
#include "PlayerObject.h"

#include "MessageLib/MessageLib.h"


#ifndef min
#define min(a,b)(((a)<(b))?(a):(b))
#endif

bool			    JediSkillManager::mInsFlag = false;
JediSkillManager*	JediSkillManager::mSingleton = NULL;

//consts
const char* const self = "self";
const char* const action = "action";
const char* const health = "health";
const char* const mind = "mind";



JediSkillManager::JediSkillManager(MessageDispatch* dispatch)
{
    Dispatch = dispatch;
}


JediSkillManager::~JediSkillManager()
{
}


// Used for Force Healing self damage pools.

bool JediSkillManager::ForceHealSelfDamage(PlayerObject* Jedi, ObjectControllerCmdProperties* cmdProperties, int HealType)
{


	// Do you need healing?
	int Health = Jedi->getHam()->mHealth.getCurrentHitPoints();
	int Action = Jedi->getHam()->mAction.getCurrentHitPoints();
	int Mind = Jedi->getHam()->mMind.getCurrentHitPoints();
	int MaxHealth = Jedi->getHam()->mHealth.getMaxHitPoints();
	int MaxAction = Jedi->getHam()->mAction.getMaxHitPoints();
	int MaxMind = Jedi->getHam()->mMind.getMaxHitPoints();


	if (Health == MaxHealth) {
		if (Action == MaxAction) {
		   if (Mind == MaxMind) {
				gMessageLib->sendSystemMessage(Jedi,L"","jedi_spam","no_damage_heal_self");
				return false;
		}
		}
	}


	/*	
	 *  The following is a switch that depending on healtype set in the opcode handler, will do different heal commands.
	 *	Proceedure: Heal damage, math to calculate how much was healed, system messages, more math to caculate 
	 *	the force cost based upon the max amount retreived from Pre-CU archives and points healed for.
	 */

	// Need to define constant ints like this so compiler doesn't freak... Might re-do this.

	// All type heal1 ints
		int H = Health-MaxHealth;
		int A = Action-MaxAction;
		int M = Mind-MaxMind;
		int cost1 = min((H+A+M / 3), 340);
		int cost2 = min((H+A+M / 3), 470);

	// Individual pool type heal1 ints
		int costH1 = min(H, 65);
		int costH2 = min(H, 100);
		int costA1 = min(A, 65);
		int costA2 = min(A, 100);
		int costM1 = min(M, 65);
		int costM2 = min(M, 100);



	switch (HealType) {
	case 1:
		Jedi->getHam()->updatePropertyValue(HamBar_Health, HamProperty_CurrentHitpoints, 500);
		Jedi->getHam()->updatePropertyValue(HamBar_Action, HamProperty_CurrentHitpoints, 500);
		Jedi->getHam()->updatePropertyValue(HamBar_Mind, HamProperty_CurrentHitpoints, 500);
		gMessageLib->sendSystemMessage(Jedi, L"", "jedi_spam", "heal_self", "jedi_spam", "health_damage", L"", -H);
		gMessageLib->sendSystemMessage(Jedi, L"", "jedi_spam", "heal_self", "jedi_spam", "action_damage", L"", -A);
		gMessageLib->sendSystemMessage(Jedi, L"", "jedi_spam", "heal_self", "jedi_spam", "mind_damage", L"", -M);
		Jedi->getHam()->setCurrentForce(-cost1);
			break;
	case 2:
		Jedi->getHam()->updatePropertyValue(HamBar_Health, HamProperty_CurrentHitpoints, 1500);
		Jedi->getHam()->updatePropertyValue(HamBar_Action, HamProperty_CurrentHitpoints, 1500);
		Jedi->getHam()->updatePropertyValue(HamBar_Mind, HamProperty_CurrentHitpoints, 1500);
		gMessageLib->sendSystemMessage(Jedi, L"", "jedi_spam", "heal_self", "jedi_spam", "health_damage", L"", -H);
		gMessageLib->sendSystemMessage(Jedi, L"", "jedi_spam", "heal_self", "jedi_spam", "action_damage", L"", -A);
		gMessageLib->sendSystemMessage(Jedi, L"", "jedi_spam", "heal_self", "jedi_spam", "mind_damage", L"", -M);
		Jedi->getHam()->setCurrentForce(-cost2);
			break;
	case 3:
		Jedi->getHam()->updatePropertyValue(HamBar_Health, HamProperty_CurrentHitpoints, 500);
		gMessageLib->sendSystemMessage(Jedi, L"", "jedi_spam", "heal_self", "jedi_spam", "health_damage", L"", -H);
		Jedi->getHam()->setCurrentForce(-costH1);
			break;
	case 4:
		Jedi->getHam()->updatePropertyValue(HamBar_Health, HamProperty_CurrentHitpoints, 1500);
		gMessageLib->sendSystemMessage(Jedi, L"", "jedi_spam", "heal_self", "jedi_spam", "health_damage", L"", -H);
		Jedi->getHam()->setCurrentForce(-costH2);
			break;
	case 5:
		Jedi->getHam()->updatePropertyValue(HamBar_Action, HamProperty_CurrentHitpoints, 500);
		gMessageLib->sendSystemMessage(Jedi, L"", "jedi_spam", "heal_self", "jedi_spam", "action_damage", L"", -A);
		Jedi->getHam()->setCurrentForce(-costA1);
			break;
	case 6:
		Jedi->getHam()->updatePropertyValue(HamBar_Action, HamProperty_CurrentHitpoints, 1500);
		gMessageLib->sendSystemMessage(Jedi, L"", "jedi_spam", "heal_self", "jedi_spam", "action_damage", L"", -A);
		Jedi->getHam()->setCurrentForce(-costA2);
			break;
	case 7:
		Jedi->getHam()->updatePropertyValue(HamBar_Mind, HamProperty_CurrentHitpoints, 500);
		gMessageLib->sendSystemMessage(Jedi, L"", "jedi_spam", "heal_self", "jedi_spam", "mind_damage", L"", -M);
		Jedi->getHam()->setCurrentForce(-costM1);
			break;
	case 8:
		Jedi->getHam()->updatePropertyValue(HamBar_Mind, HamProperty_CurrentHitpoints, 1500);
		gMessageLib->sendSystemMessage(Jedi, L"", "jedi_spam", "heal_self", "jedi_spam", "mind_damage", L"", -M);
		Jedi->getHam()->setCurrentForce(-costM2);
			break;
	default:
		break;
	}

	//CE
	gMessageLib->sendPlayClientEffectLocMessage("clienteffect/pl_force_heal_self.cef",Jedi->mPosition,Jedi);


	return true;
}