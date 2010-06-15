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
#include <cstdint>

#include "MarksmanManager.h"
#include "PlayerObject.h"
#include "Weapon.h"
#include "PostureChangeEvent.h"
#include "ObjectControllerCommandMap.h"

bool			MarksmanManager::mInsFlag = false;
MarksmanManager*	MarksmanManager::mSingleton = NULL;

MarksmanManager::MarksmanManager(MessageDispatch* dispatch){
    Dispatch = dispatch;
}

MarksmanManager::~MarksmanManager()
{
}

//--
//
// check if player object has a ranged weapon equipped
//

bool MarksmanManager::hasRangedWeaponEquipped(PlayerObject* player){
	Item* item = dynamic_cast<Item*>(player->getEquipManager()->getEquippedObject(CreatureEquipSlot_Hold_Left));
	if(item->getItemFamily() == ItemFamily_Weapon){// weapon check
		Weapon* curWeapon = dynamic_cast<Weapon*>(item);
			
		switch(curWeapon->getGroup()){
			case WeaponGroup_Flamethrower:
				return true;
			case WeaponGroup_Launcher:
				return true;
			case WeaponGroup_Carbine:
				return true;
			case WeaponGroup_Pistol:
				return true;
			case WeaponGroup_Rifle:
				return true;
			default:
				return false;
		}
	}else{
		return false;
	}
}
bool  MarksmanManager::performTumbleToKneeling(PlayerObject* player, PlayerObject* target,ObjectControllerCmdProperties* cmdProperties){
	//1:Trigger Client Animation
	//2:Trigger Fly Text
	//3:Schedule posture change Event
	//4:Return handler completion status
	
	if(player->isConnected()){
		//Anim
		gMessageLib->sendCreatureAnimation(player, BString("tumble_to_kneeling"));
		//Schedule Posture kneel event
		gMessageLib->sendSystemMessage(player,L"","cbt_spam","tum_kneeling");
		gMessageLib->sendFlyText(player,"combat_effects","go_tumbling",0,255,0);
		uint64 now = gWorldManager->GetCurrentGlobalTick();
		player->getController()->addEvent(new PostureChangeEvent(now + 700, CreaturePosture_Crouched), 700);
		
		return true;
	}else{
		return false;
	}
}


bool  MarksmanManager::performTumbleToProne(PlayerObject* player, PlayerObject* target,ObjectControllerCmdProperties* cmdProperties){
	//1:Trigger Client Animation
	//2:Trigger Fly Text
	//3:Schedule posture change Event
	//4:Return handler completion status

	if(player->isConnected()){
		//Anim
		gMessageLib->sendCreatureAnimation(player, BString("dive"));//TODO find the correct animation
		//Schedule Posture prone event
		gMessageLib->sendSystemMessage(player,L"","cbt_spam","tum_prone");
		gMessageLib->sendFlyText(player,"combat_effects","go_tumbling",0,255,0);
		uint64 now = gWorldManager->GetCurrentGlobalTick();
		player->getController()->addEvent(new PostureChangeEvent(now + 700, CreaturePosture_Prone), 700);
		return true;
	}else{
		return false;
	}
}
bool  MarksmanManager::performTumbleToStanding(PlayerObject* player, PlayerObject* target,ObjectControllerCmdProperties* cmdProperties){
	//1:Trigger Client Animation
	//2:Trigger Fly Text
	//3:Schedule posture change Event
	//4:Return handler completion status

	if(player->isConnected()){
		//Anim
		gMessageLib->sendCreatureAnimation(player, BString("tumble_to_standing"));
		gMessageLib->sendFlyText(player,"combat_effects","go_tumbling",0,255,0);
		//Schedule Posture Stand event
		gMessageLib->sendSystemMessage(player,L"","cbt_spam","tum_standing");
		uint64 now = gWorldManager->GetCurrentGlobalTick();
		player->getController()->addEvent(new PostureChangeEvent(now + 700, CreaturePosture_Upright), 700);
		return true;
	}else{
		return false;
	}
}

bool  MarksmanManager::performTakeCover(PlayerObject* player, PlayerObject* target,ObjectControllerCmdProperties* cmdProperties){
	//1:Trigger Client Animation
	//2:Trigger Fly Text
	//3:Schedule posture change Event
	//4:Return handler completion status

	if(player->isConnected()){
		//Anim
		gMessageLib->sendCreatureAnimation(player, BString("hurry_to_prone"));
		gMessageLib->sendFlyText(player,"combat_effects","go_cover",0,255,0);
		//Schedule Posture prone event
		gMessageLib->sendSystemMessage(player,L"","cbt_spam","cover_success_single");
		uint64 now = gWorldManager->GetCurrentGlobalTick();
		player->getController()->addEvent(new PostureChangeEvent(now + 700, CreaturePosture_Prone), 700);
		return true;
	}else{
		return false;
	}
}