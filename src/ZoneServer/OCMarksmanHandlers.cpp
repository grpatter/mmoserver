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

#include "ObjectController.h"
#include "ObjectControllerOpcodes.h"
#include "ObjectControllerCommandMap.h"
#include "MessageLib/MessageLib.h"
#include "LogManager/LogManager.h"
#include "DatabaseManager/Database.h"
#include "DatabaseManager/DataBinding.h"
#include "DatabaseManager/DatabaseResult.h"
#include "Common/MessageFactory.h"
#include "Common/Message.h"
#include "PlayerObject.h"
#include "MarksmanManager.h"
#include "Utils/clock.h"



//=============================================================================================================================
//
// tumbletokneeling
//
void ObjectController::_handleTumbleToKneeling(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties){
	PlayerObject* player = dynamic_cast<PlayerObject*>(mObject);
	PlayerObject* target = dynamic_cast<PlayerObject*>(gWorldManager->getObjectById(targetId));
	
	mHandlerCompleted = gMarksmanManager->performTumbleToKneeling(player, target, cmdProperties);//TODO: Change this to return a bool when ObjectController is updated
} 

//=============================================================================================================================
//
// tumbletoprone
//
void ObjectController::_handleTumbleToProne(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties){
	PlayerObject* player = dynamic_cast<PlayerObject*>(mObject);
	PlayerObject* target = dynamic_cast<PlayerObject*>(gWorldManager->getObjectById(targetId));
	
	mHandlerCompleted = gMarksmanManager->performTumbleToProne(player, target, cmdProperties);//TODO: Change this to return a bool when ObjectController is updated
}

//=============================================================================================================================
//
// tumbletostanding
//
void ObjectController::_handleTumbleToStanding(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties){
	PlayerObject* player = dynamic_cast<PlayerObject*>(mObject);
	PlayerObject* target = dynamic_cast<PlayerObject*>(gWorldManager->getObjectById(targetId));

	mHandlerCompleted = gMarksmanManager->performTumbleToStanding(player, target, cmdProperties);//TODO: Change this to return a bool when ObjectController is updated
} 

//=============================================================================================================================
//
// takecover
//
void ObjectController::_handleTakeCover(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties){
	//TODO impl this correctly. We will need some kind of 'CoverManager' to track status and other 
	//factors from beyond this single player. See the wiki for details.
	// Waiting on a proper CombatManager
	PlayerObject* player = dynamic_cast<PlayerObject*>(mObject);
	PlayerObject* target = dynamic_cast<PlayerObject*>(gWorldManager->getObjectById(targetId));
	mHandlerCompleted = gMarksmanManager->performTakeCover(player, target, cmdProperties);
} 

//=============================================================================================================================
//
// aim
//
void ObjectController::_handleAim(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties){
	//TODO impl this correctly
	// Waiting on a proper CombatManager
	PlayerObject* player = dynamic_cast<PlayerObject*>(mObject);
	gMessageLib->sendCreatureAnimation(player, BString("aim"));//TODO find the correct anim
	mHandlerCompleted = false;
} 

//=============================================================================================================================


