#include "zmap.h"

#include "Object.h"
#include "PlayerObject.h"
#include "MessageLib/MessageLib.h"


zmap* zmap::ZMAP = NULL;

zmap::zmap()
{
	ZMAP = this;

	uint32 x = 0, i = 0, j = 0;

	
	// Setup the lookup array...
	i = 0;
	for(x = 0; x <= 410; x++)
	{
		for(j = 0; j <= 410; j++)
		{
			zmap_lookup[x][j] = i;
			i++;

		}
	}
}

zmap::~zmap()
{

}


void zmap::AddObject(Object *newObject)
{
	//Pesudo
	// 1. Calculate CellID
	// 2. Set CellID
	// 3. Insert object into the cell in the hast table

	uint32 CellX = ((((uint32)newObject->mPosition.x) + 8500)/150);
	uint32 CellY = ((((uint32)newObject->mPosition.y) + 8500)/150);
	uint32 FinalCell = zmap_lookup[CellY][CellX];

	


	newObject->zmapCellID = FinalCell;
	for(std::list<Object*>::iterator i = ZMapCells[FinalCell].begin(); i != ZMapCells[FinalCell].end(); i++)
	{
		if((*i)->getId() == newObject->getId())
		{
			
			return;
		}

	}
	ZMapCells[FinalCell].push_back(newObject);
	return;

}

void zmap::RemoveObject(Object *removeObject)
{
	MapHandler::iterator i = ZMapCells.find(removeObject->zmapCellID);

	if(i != ZMapCells.end())
	{
		for(std::list<Object*>::iterator i = ZMapCells[removeObject->zmapCellID].begin(); i != ZMapCells[removeObject->zmapCellID].end(); i++)
		{
			if((*i)->getId() == removeObject->getId())
			{
				
				ZMapCells[removeObject->zmapCellID].erase(i);
				break;
			}
		}
	}
	else
	{
		
	}

	return;
}

void zmap::UpdateObject(Object *updateObject)
{
	// Pesudo
	// 1. Calculate Cell
	// 2. If cell is different then current cell
	//		2a. Remove him from the current cell, insert into new cell at new cell
	//		2b. Update info....

	uint32 CellX = ((((uint32)updateObject->mPosition.x) + 8500)/150);
	uint32 CellY = ((((uint32)updateObject->mPosition.y) + 8500)/150);
	uint32 FinalCell = zmap_lookup[CellY][CellX];
	
	if(updateObject->zmapCellID != FinalCell)
	{
	
		UpdateBackCells(updateObject,FinalCell);
		UpdateFrontCells(updateObject,FinalCell);
		RemoveObject(updateObject);
		AddObject(updateObject);
	
	}
	else
	{
	
	}
}

std::list<Object*>*	zmap::GetCellContents(uint32 CellID)
{
	//Pesudo
	// 1. Return list of objects in cell
	//if(CellID) >
	
	if(CellID > (GRIDWIDTH*GRIDHEIGHT))
		return &EmptyCell;
	
	return &ZMapCells[CellID];
}

std::list<Object*>* zmap::GetChatRangeCellContents(uint32 CellID)
{
	//Pesudo
	// 1. Combine the lists of Neiboring cells to 1

	std::list<Object*>* ReturnList = new std::list<Object*>;
	std::list<Object*>::iterator it = ReturnList->begin();

	std::list<Object*> temp = *GetCellContents(CellID);
	ReturnList->splice(it, temp);

	temp = *GetCellContents(CellID + 411);
	ReturnList->splice(it, temp);

	temp = *GetCellContents(CellID - 411);
	ReturnList->splice(it, temp);

	temp = *GetCellContents(CellID + 1);
	ReturnList->splice(it, temp);

	temp = *GetCellContents(CellID - 1);
	ReturnList->splice(it, temp);

	temp = *GetCellContents(CellID + 410);
	ReturnList->splice(it, temp);

	temp = *GetCellContents(CellID + 412);
	ReturnList->splice(it, temp);

	temp = *GetCellContents(CellID - 412);
	ReturnList->splice(it, temp);

	temp = *GetCellContents(CellID - 410);
	ReturnList->splice(it, temp);


	return ReturnList;
}

//=====================================================
//Get Contents for a Row based on a middle cell

std::list<Object*>* zmap::GetGridContentsListRow(uint32 CellID)
{
	std::list<Object*>* ReturnList = new std::list<Object*>;
	std::list<Object*>::iterator it = ReturnList->begin();

	std::list<Object*> temp = *GetCellContents(CellID);
	ReturnList->splice(it, temp);

	for(int i = 0; i < VIEWRANGE; i++)
	{
		//if(fmod(CellID+1,))
		temp = *GetCellContents(CellID + i);
		ReturnList->splice(it, temp);
		
		temp = *GetCellContents(CellID - i);
		ReturnList->splice(it, temp);
	}

	return ReturnList;

}

std::list<Object*>* zmap::GetGridContentsListColumn(uint32 CellID)
{
	std::list<Object*>* ReturnList = new std::list<Object*>;
	std::list<Object*>::iterator it = ReturnList->begin();

	std::list<Object*> temp = *GetCellContents(CellID);
	ReturnList->splice(it, temp);

	for(int i = 1; i <= VIEWRANGE; i++)
	{
		//if(fmod(CellID+1,))
		temp = *GetCellContents(CellID + (i*GRIDWIDTH));
		ReturnList->splice(it, temp);
		
		temp = *GetCellContents(CellID - (i*GRIDWIDTH));
		ReturnList->splice(it, temp);
	}

	return ReturnList;

}

std::list<Object*>* zmap::GetViewingRangeCellContents(uint32 CellID)
{
	//Pesudo
	// 1. Combine the lists of Neiboring cells to 1

	std::list<Object*>* ReturnList = new std::list<Object*>;
	std::list<Object*>::iterator it = ReturnList->begin();

	std::list<Object*> temp = *GetCellContents(CellID);
	ReturnList->splice(it, temp);

	for(int i = 0; i < VIEWRANGE; i++)
	{
		temp = *GetGridContentsListRow(CellID + (i*GRIDWIDTH));
		ReturnList->splice(it, temp);
		
		temp = *GetGridContentsListRow(CellID - (i*GRIDWIDTH));
		ReturnList->splice(it, temp);
	}

	return ReturnList;
}

void zmap::CheckObjectIterationForDestruction(Object* toBeTested, Object* toBeUpdated)
{
	PlayerObject* us = dynamic_cast<PlayerObject*>(toBeUpdated);

	if(toBeTested->getId() != toBeUpdated->getId())
	{
		//we (updateObject) got out of range of the following (*i) objects
		//destroy them for us
		//if its a player, destroy us for him
		if(us)
		{
			gMessageLib->sendDestroyObject(toBeTested->getId(),us);
		}
				
		PlayerObject* them = dynamic_cast<PlayerObject*> (toBeTested);
		if(them)
		{
			gMessageLib->sendDestroyObject(toBeUpdated->getId(),them);
			
			//now what to do with 
			if(toBeUpdated->getType() == ObjType_Structure)
			{
				//specialized factory despawn
				
			}
		}
	}
}

void zmap::UpdateBackCells(Object* updateObject, uint32 newCell)
{
	//are all the cells on our lefz or right valid ??
	//arnt we looking to the other side of the map ???
	

	//ZMAP Northbound! TODO: Sync with game
	if((updateObject->zmapCellID + 411) == newCell)
	{
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents((updateObject->zmapCellID - 411));
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 412));
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 410));
		FinalList.splice(it, temp);


		for(std::list<Object*>::iterator i = FinalList.begin(); i != FinalList.end(); i++)
		{
			CheckObjectIterationForDestruction((*i),updateObject);
		}

		return;
	}

	//ZMAP Southbound! TODO: Sync with game
	else if((updateObject->zmapCellID - 411) == newCell)
	{
		
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();
		
		std::list<Object*> temp = *GetCellContents(updateObject->zmapCellID + 411);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID + 412);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID + 410);
		FinalList.splice(it, temp);

		for(std::list<Object*>::iterator i = FinalList.begin(); i != FinalList.end(); i++)
		{
			CheckObjectIterationForDestruction((*i),updateObject);			
		}

		return;
	}

		//ZMAP Westbound! TODO: Sync with game
	else if((updateObject->zmapCellID - 1) == newCell)
	{
		
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents(updateObject->zmapCellID - 410);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID + 1 );
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID + 412);
		FinalList.splice(it, temp);

		for(std::list<Object*>::iterator i = FinalList.begin(); i != FinalList.end(); i++)
		{
			CheckObjectIterationForDestruction((*i),updateObject);
		}

		return;
	}

			//ZMAP Eastbound! TODO: Sync with game
	else if((updateObject->zmapCellID + 1) == newCell)
	{
		
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents(updateObject->zmapCellID + 410);
		FinalList.splice(it, temp);
		
		temp = *GetCellContents(updateObject->zmapCellID - 1 );
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID - 412);
		FinalList.splice(it, temp);

		for(std::list<Object*>::iterator i = FinalList.begin(); i != FinalList.end(); i++)
		{
			CheckObjectIterationForDestruction((*i),updateObject);
		}

		return;
	}

	// NorthEastbound
	else if((updateObject->zmapCellID + 412) == newCell)
	{
		
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents(updateObject->zmapCellID + 410);
		FinalList.splice(it, temp);
		
		temp = *GetCellContents(updateObject->zmapCellID - 410);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID - 1 );
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID - 412);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID - 411);
		FinalList.splice(it, temp);

		for(std::list<Object*>::iterator i = FinalList.begin(); i != FinalList.end(); i++)
		{
			CheckObjectIterationForDestruction((*i),updateObject);
		}

		return;
	}

	// NorthWestbound
	else if((updateObject->zmapCellID + 410) == newCell)
	{
		
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents(updateObject->zmapCellID - 412);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID - 410);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID + 1 );
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID + 412);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID - 411);
		FinalList.splice(it, temp);

		for(std::list<Object*>::iterator i = FinalList.begin(); i != FinalList.end(); i++)
		{
			CheckObjectIterationForDestruction((*i),updateObject);
			
		}

		return;
	}

		// SouthWestbound
	else if((updateObject->zmapCellID - 412) == newCell)
	{
		
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents(updateObject->zmapCellID + 410);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID - 410);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID + 1 );
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID + 412);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID + 411);
		FinalList.splice(it, temp);

		for(std::list<Object*>::iterator i = FinalList.begin(); i != FinalList.end(); i++)
		{
			CheckObjectIterationForDestruction((*i),updateObject);
		}

		return;
	}

		// SouthEastbound
	else if((updateObject->zmapCellID - 410) == newCell)
	{
		
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents(updateObject->zmapCellID + 412);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID + 410);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID - 1 );
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID - 412);
		FinalList.splice(it, temp);

		temp = *GetCellContents(updateObject->zmapCellID + 411);
		FinalList.splice(it, temp);

		for(std::list<Object*>::iterator i = FinalList.begin(); i != FinalList.end(); i++)
		{
			CheckObjectIterationForDestruction((*i),updateObject);
		}

		return;
	}
	
}

void zmap::CheckObjectIterationForCreation(Object* toBeTested, Object* toBeUpdated)
{
	PlayerObject* us = dynamic_cast<PlayerObject*>(toBeUpdated);

	if(toBeTested->getId() != toBeUpdated->getId())
	{
		//we (toBeUpdated) need to create the following objects
		//if its a player create us for him
		
		if(us)
		{
			gMessageLib->sendCreateObject(toBeTested,us);
		}
				
		PlayerObject* them = dynamic_cast<PlayerObject*> (toBeTested);
		if(them)
		{
			gMessageLib->sendCreateObject(toBeUpdated,them);
		}
	}
}


void zmap::ObjectCreationIteration(std::list<Object*>* FinalList, Object* updateObject)
{
	//at some point we need to throttle ObjectCreates!!!
	//one possibility would be to only send one grid at a time and keep track of up / unup dated Grids

	for(std::list<Object*>::iterator i = FinalList->begin(); i != FinalList->end(); i++)
	{
		CheckObjectIterationForCreation((*i),updateObject);
	}
}

void zmap::UpdateFrontCells(Object* updateObject, uint32 newCell)
{

	//ZMAP Northbound! TODO: Sync with game
	if((updateObject->zmapCellID + 411) == newCell)
	{
	
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents((updateObject->zmapCellID + 411) + 411);
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID + 411) + 412);
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID + 411) + 410);
		FinalList.splice(it, temp);

		ObjectCreationIteration(&FinalList,updateObject);

		return;
	}

	//ZMAP Southbound! TODO: Sync with game
	else if((updateObject->zmapCellID - 411) == newCell)
	{
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents((updateObject->zmapCellID - 411) - 411);
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 411) - 412);
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 411) -410);
		FinalList.splice(it, temp);
	 
		ObjectCreationIteration(&FinalList,updateObject);

		return;
	}

			//ZMAP Eastbound! TODO: Sync with game
	else if((updateObject->zmapCellID + 1) == newCell)
	{
	
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents((updateObject->zmapCellID + 1) + 412);
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID + 1) + 1 );
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID + 1) - 410);
		FinalList.splice(it, temp);

		ObjectCreationIteration(&FinalList,updateObject);

		return;
	}

		//ZMAP Westbound! TODO: Sync with game
	else if((updateObject->zmapCellID - 1) == newCell)
	{
		
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents((updateObject->zmapCellID - 1) - 412);
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 1) - 1 );
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 1) + 410);
		FinalList.splice(it, temp);

		ObjectCreationIteration(&FinalList,updateObject);

		return;
	}

	// NorthEastbound
	else if((updateObject->zmapCellID + 412) == newCell)
	{
		
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents((updateObject->zmapCellID + 412) + 410);//
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID + 412) - 410);//
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID + 412) + 1 );//
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID + 412) + 412);//
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID + 412) + 411);//
		FinalList.splice(it, temp);

		ObjectCreationIteration(&FinalList,updateObject);

		return;
	}

	// NorthWestbound
	else if((updateObject->zmapCellID + 410) == newCell)
	{
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents((updateObject->zmapCellID + 410) - 412);
		FinalList.splice(it, temp);

		std::list<Object*> objList2 = *GetCellContents((updateObject->zmapCellID + 410) + 410);
		FinalList.splice(it, temp);

		std::list<Object*> objList3 = *GetCellContents((updateObject->zmapCellID + 410) - 1 );
		FinalList.splice(it, temp);

		std::list<Object*> objList4 = *GetCellContents((updateObject->zmapCellID + 410) + 412);
		FinalList.splice(it, temp);

		std::list<Object*> objList5 = *GetCellContents((updateObject->zmapCellID + 410) + 411);
		FinalList.splice(it, temp);

		ObjectCreationIteration(&FinalList,updateObject);

		return;
	}

		// SouthWestbound
	else if((updateObject->zmapCellID - 412) == newCell)
	{
		
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents((updateObject->zmapCellID - 412) + 410);
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 412) - 410);
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 412) - 1 );
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 412) - 412);
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 412) - 411);
		FinalList.splice(it, temp);

		ObjectCreationIteration(&FinalList,updateObject);

		return;
	}

		// SouthEestbound
	else if((updateObject->zmapCellID - 410) == newCell)
	{
		
		std::list<Object*> FinalList;
		std::list<Object*>::iterator it = FinalList.end();

		std::list<Object*> temp = *GetCellContents((updateObject->zmapCellID - 410) + 412);//
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 410) - 410);//
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 410) + 1 );//
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 410) - 412);//
		FinalList.splice(it, temp);

		temp = *GetCellContents((updateObject->zmapCellID - 410) - 411);//
		FinalList.splice(it, temp);

		ObjectCreationIteration(&FinalList,updateObject);

		return;
	}


	else
	{
		
	}
}