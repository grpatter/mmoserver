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

//common includes
#include "ObjectController.h"
#include "OCMarksmanHandlers.h"

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
bool _handleTumbleToKneeling(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties){
	PlayerObject* player = dynamic_cast<PlayerObject*>(object);
	PlayerObject* mtarget = dynamic_cast<PlayerObject*>(target);
	
	return gMarksmanManager->performTumbleToKneeling(player, mtarget, cmdProperties);
} 

//=============================================================================================================================
//
// tumbletoprone
//
bool _handleTumbleToProne(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties){
	PlayerObject* player = dynamic_cast<PlayerObject*>(object);
	PlayerObject* mtarget = dynamic_cast<PlayerObject*>(target);
	
	return gMarksmanManager->performTumbleToProne(player, mtarget, cmdProperties);
}

//=============================================================================================================================
//
// tumbletostanding
//
bool _handleTumbleToStanding(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties){
	PlayerObject* player = dynamic_cast<PlayerObject*>(object);
	PlayerObject* mtarget = dynamic_cast<PlayerObject*>(target);

	return gMarksmanManager->performTumbleToStanding(player, mtarget, cmdProperties);
} 

//=============================================================================================================================
//
// takecover
//
bool _handleTakeCover(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties){
	//TODO impl this correctly. We will need some kind of 'CoverManager' to track status and other 
	//factors from beyond this single player. See the wiki for details.
	// Waiting on a proper CombatManager
	PlayerObject* player = dynamic_cast<PlayerObject*>(object);
	PlayerObject* mtarget = dynamic_cast<PlayerObject*>(target);
	return gMarksmanManager->performTakeCover(player, mtarget, cmdProperties);
} 

//=============================================================================================================================
//
// aim
//
bool _handleAim(Object* object, Object* target, Message* message, ObjectControllerCmdProperties* cmdProperties){
	//TODO impl this correctly
	// Waiting on a proper CombatManager
	PlayerObject* player = dynamic_cast<PlayerObject*>(object);
	gMessageLib->sendCreatureAnimation(player, BString("aim"));//TODO find the correct anim
	return false;
} 

//=============================================================================================================================


