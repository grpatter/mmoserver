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
#include <cstdint>
#ifdef _MSC_VER
#include <regex>  // NOLINT
#else
#endif

#include <boost/regex.hpp>  // NOLINT
#include "JediSkillManager.h"
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



//=============================================================================================================================
//
// healallself 1
//

void ObjectController::_handleHealAllSelf1(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
	PlayerObject* Jedi = dynamic_cast<PlayerObject*>(mObject);

	int HealType = 1;

	mHandlerCompleted = gJediSkillManager->ForceHealSelfDamage(Jedi, cmdProperties, HealType);
} 

//=============================================================================================================================
//
// healallself 2
//

void ObjectController::_handleHealAllSelf2(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
	PlayerObject* Jedi = dynamic_cast<PlayerObject*>(mObject);

	int HealType = 2;

	mHandlerCompleted = gJediSkillManager->ForceHealSelfDamage(Jedi, cmdProperties, HealType);
} 

//=============================================================================================================================
//
// healhealthself 1
//

void ObjectController::_handleHealHealthSelf1(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
	PlayerObject* Jedi = dynamic_cast<PlayerObject*>(mObject);

		int HealType = 3;

	mHandlerCompleted = gJediSkillManager->ForceHealSelfDamage(Jedi, cmdProperties, HealType);
} 

//=============================================================================================================================
//
// healhealthself 2
//

void ObjectController::_handleHealHealthSelf2(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
		PlayerObject* Jedi = dynamic_cast<PlayerObject*>(mObject);

		int HealType = 4;

	mHandlerCompleted = gJediSkillManager->ForceHealSelfDamage(Jedi, cmdProperties, HealType);
} 

//=============================================================================================================================
//
// healactionself 1
//

void ObjectController::_handleHealActionSelf1(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
		PlayerObject* Jedi = dynamic_cast<PlayerObject*>(mObject);

		int HealType = 5;

	mHandlerCompleted = gJediSkillManager->ForceHealSelfDamage(Jedi, cmdProperties, HealType);
} 

//=============================================================================================================================
//
// healactionself 2
//

void ObjectController::_handleHealActionSelf2(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
		PlayerObject* Jedi = dynamic_cast<PlayerObject*>(mObject);

		int HealType = 6;

	mHandlerCompleted = gJediSkillManager->ForceHealSelfDamage(Jedi, cmdProperties, HealType);
} 

//=============================================================================================================================
//
// healmindself 1
//

void ObjectController::_handleHealMindSelf1(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
		PlayerObject* Jedi = dynamic_cast<PlayerObject*>(mObject);

		int HealType = 7;

	mHandlerCompleted = gJediSkillManager->ForceHealSelfDamage(Jedi, cmdProperties, HealType);
} 

//=============================================================================================================================
//
// healmindself 2
//

void ObjectController::_handleHealMindSelf2(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
		PlayerObject* Jedi = dynamic_cast<PlayerObject*>(mObject);

		int HealType = 8;

	mHandlerCompleted = gJediSkillManager->ForceHealSelfDamage(Jedi, cmdProperties, HealType);
} 

//=============================================================================================================================
//
// healactionwoundself 1
//

void ObjectController::_handleHealActionWoundSelf1(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healactionwoundself 2
//

void ObjectController::_handleHealActionWoundSelf2(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healhealthwoundself 1
//

void ObjectController::_handleHealHealthWoundSelf1(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healhealthwoundself 2
//

void ObjectController::_handleHealHealthWoundSelf2(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healbattlefatigueself 1
//

void ObjectController::_handleHealBattleFatigueSelf1(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healbattlefatigueself 2
//

void ObjectController::_handleHealBattleFatigueSelf2(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healmindwoundself 1
//

void ObjectController::_handleHealMindWoundSelf1(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healmindwoundself 2
//

void ObjectController::_handleHealMindWoundSelf2(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healactionwoundother 1
//

void ObjectController::_handleHealActionWoundOther1(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healactionwoundother 2
//

void ObjectController::_handleHealActionWoundOther2(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healhealthwoundother 1
//

void ObjectController::_handleHealHealthWoundOther1(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healhealthwoundother 2
//

void ObjectController::_handleHealHealthWoundOther2(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healmindwoundother 1
//

void ObjectController::_handleHealMindWoundOther1(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healmindwoundother 2
//

void ObjectController::_handleHealMindWoundOther2(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healallother 1
//

void ObjectController::_handleHealAllOther1(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healallother 2
//

void ObjectController::_handleHealAllOther2(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healstatesother
//

void ObjectController::_handleHealStatesOther(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// stopbleeding
//

void ObjectController::_handleStopBleeding(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// forcecuredisease
//

void ObjectController::_handleForceCureDisease(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// forcecurepoison
//

void ObjectController::_handleForceCurePoison(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// healstatesself
//

void ObjectController::_handleHealStatesSelf(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// totalhealother
//

void ObjectController::_handleTotalHealOther(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================
//
// totalhealself
//

void ObjectController::_handleTotalHealSelf(uint64 targetId,Message* message,ObjectControllerCmdProperties* cmdProperties)
{
} 

//=============================================================================================================================


