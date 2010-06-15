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

//common incs
#include "ObjectController.h"
#include "OCMedicHandlers.h"

#include <boost/regex.hpp>  // NOLINT
#include "MedicManager.h"
#include "ObjectController.h"
#include "ObjectControllerOpcodes.h"
#include "ObjectControllerCommandMap.h"
#include "PlayerObject.h"
#include "WorldManager.h"
#include "MessageLib/MessageLib.h"
#include "LogManager/LogManager.h"
#include "DatabaseManager/Database.h"
#include "DatabaseManager/DataBinding.h"
#include "DatabaseManager/DatabaseResult.h"
#include "Common/MessageFactory.h"
#include "Common/Message.h"
#include "ForageManager.h"

	//consts
	const char* const woundpack = "woundpack";
	const char* const stim = "stim";
	const char* const rangedstim = "ranged";
	const char* const self = "self";
	const char* const action = "action";
	const char* const constitution = "constitution";
	const char* const health = "health";
	const char* const quickness = "quickness";
	const char* const stamina = "stamina";
	const char* const strength = "strength";
//=============================================================================================================================
//
// diagnose
//

bool _handleDiagnose(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties)
{
	PlayerObject* Medic = dynamic_cast<PlayerObject*>(object);
	PlayerObject* Target = dynamic_cast<PlayerObject*>(target);
	if(Target != 0)
	{
		gMedicManager->Diagnose(Medic, Target);
		return true;
	} else {
		gMessageLib->sendSystemMessage(Medic,L"","healing_response","healing_response_b6");
		return false;
	}
}

//=============================================================================================================================
//
// healdamage
//

bool _handleHealDamage(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties)
{
	PlayerObject* Medic = dynamic_cast<PlayerObject*>(object);
	PlayerObject* Target = dynamic_cast<PlayerObject*>(Medic->getHealingTarget(Medic));

	if (gMedicManager->CheckMedicine(Medic, Target, cmdProperties, stim))
	{
		//call the event
		gMedicManager->startInjuryTreatmentEvent(Medic);
		return true;
	}else{
		return false;
	}
}

//=============================================================================================================================
//
// healwound
//

bool _handleHealWound(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties)
{
	PlayerObject* Medic = dynamic_cast<PlayerObject*>(object);
	PlayerObject* Target = dynamic_cast<PlayerObject*>(Medic->getHealingTarget(Medic));

	std::string messageResponse = gMedicManager->handleMessage(message,"(action|constitution|health|quickness|stamina|strength)");
	if (messageResponse.length() == 0)
	{
	  //you must specify a valid wound type
	  gMessageLib->sendSystemMessage(Medic,L"","healing_response","healing_response_65");
	  return false;
	}
	else
	{
		//check Medic has enough Mind
		Ham* ham = Medic->getHam();
		if(ham->checkMainPools(0, 0, 140))
		{
			if (gMedicManager->CheckMedicine(Medic, Target, cmdProperties, messageResponse))
			{
				//call the event
				gMedicManager->startWoundTreatmentEvent(Medic);
				return true;
			}
		}
		else{
			gMessageLib->sendSystemMessage(Medic,L"","healing_response","not_enough_mind");
			return false;
		}
	}
}

//=============================================================================================================================
//
// medicalforage
//

bool _handleMedicalForage(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties)
{
		PlayerObject* player = dynamic_cast<PlayerObject*>(object);
	if(player){
		gForageManager->startForage(player, ForageClass_Medic);
		return true;
	}else{
		return false;
	}
}

//=============================================================================================================================
//
// tenddamage
//

bool _handleTendDamage(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties)
{
	PlayerObject* Medic = dynamic_cast<PlayerObject*>(object);
	PlayerObject* Target = dynamic_cast<PlayerObject*>(Medic->getHealingTarget(Medic));

	//check Medic has enough Mind
	Ham* ham = Medic->getHam();
	if(ham->checkMainPools(cmdProperties->mHealthCost, cmdProperties->mActionCost, cmdProperties->mMindCost))
	{
		if (gMedicManager->HealDamage(Medic, Target, 0, cmdProperties, "tendDamage"))
		{
			ham->updatePropertyValue(HamBar_Focus ,HamProperty_Wounds, 5);
			ham->updatePropertyValue(HamBar_Willpower ,HamProperty_Wounds, 5);
			ham->updateBattleFatigue(2, true);
			//call the event
			gMedicManager->startInjuryTreatmentEvent(Medic);
			return true;
		}else{
			return false;
		}
	}
	else{
		gMessageLib->sendSystemMessage(Medic,L"","healing_response","not_enough_mind");
		return false;
	}

}

//=============================================================================================================================
//
// tendwound
//

bool _handleTendWound(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties)
{
	PlayerObject* Medic = dynamic_cast<PlayerObject*>(object);
	PlayerObject* Target = dynamic_cast<PlayerObject*>(Medic->getHealingTarget(Medic));
	//TODO:: add medic droid
	/*EMLocationType loc = Medic->getPlayerLocation();
	if(loc != EMLocation_Cantina || loc != EMLocation_Camp || loc != EMLocation_PlayerStructure)
	{
		return;
	}*/
	std::string messageResponse = gMedicManager->handleMessage(message,"(action|constitution|health|quickness|stamina|strength)");
	if (messageResponse.length() == 0)
	{
	  //you must specify a valid wound type
	  gMessageLib->sendSystemMessage(Medic,L"","healing_response","healing_response_65");
	  return false;
	}
	else
	{
		//check Medic has enough Mind
		Ham* ham = Medic->getHam();
		if(ham->checkMainPools(0, 0, 500))
		{
			if (gMedicManager->HealWound(Medic, Target, 0, cmdProperties, messageResponse + "tendwound"))
			{
				ham->updatePropertyValue(HamBar_Focus ,HamProperty_Wounds, 5);
				ham->updatePropertyValue(HamBar_Willpower ,HamProperty_Wounds, 5);
				ham->updateBattleFatigue(2, true);
				//call the event
				gMedicManager->startWoundTreatmentEvent(Medic);
				return true;
			}else{
				return false;
			}
		}
		else{
			gMessageLib->sendSystemMessage(Medic,L"","healing_response","not_enough_mind");
			return false;
		}

	}
	
}

//=============================================================================================================================
//
// firstaid
//

bool _handleFirstAid(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties)
{
	//PlayerObject* Medic = dynamic_cast<PlayerObject*>(object);
	//gMessageLib->sendSystemMessage(Medic, "First Aid has not been implemented yet. Sorry.");
	return false;
}

//=============================================================================================================================
//
// quickheal
//

bool _handleQuickHeal(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties)
{
	PlayerObject* Medic = dynamic_cast<PlayerObject*>(object);
	PlayerObject* Target = dynamic_cast<PlayerObject*>(Medic->getHealingTarget(Medic));

	//check Medic has enough Mind
	Ham* ham = Medic->getHam();
	if(ham->checkMainPools(0, 0, cmdProperties->mMindCost))
	{
		if (gMedicManager->HealDamage(Medic, Target, 0, cmdProperties, "quickHeal"))
		{
			ham->updatePropertyValue(HamBar_Focus ,HamProperty_Wounds, 10);
			ham->updatePropertyValue(HamBar_Willpower ,HamProperty_Wounds, 10);
			ham->updateBattleFatigue(2, true);
			//call the event
			gMedicManager->startQuickHealInjuryTreatmentEvent(Medic);
			return true;
		}else{
			return false;
		}
	}
	else{
		gMessageLib->sendSystemMessage(Medic,L"","healing_response","not_enough_mind");
		return false;
	}
}

//=============================================================================================================================
//
// dragincapacitatedplayer
//

bool _handleDragIncapacitatedPlayer(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties)
{
	//PlayerObject* Medic = dynamic_cast<PlayerObject*>(mObject);
	//gMessageLib->sendSystemMessage(Medic, "Drag has not been implemented yet. Sorry.");
	return false;
}

//=============================================================================================================================

