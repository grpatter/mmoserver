#include "WeatherManager.h"
#include "WorldConfig.h"
#include "WorldManager.h"
#include "Utils/rand.h"
#include "ZoneTree.h"

#include "MathLib\Rectangle.h"
#include "QTRegion.h"

#include <glm/glm.hpp>

#define CLEAR_WEATHER		0
#define CLOUDY_WEATHER		1
#define LIGHT_RAIN_WEATHER	2
#define MEDIUM_RAIN_WEATHER 3
#define HEAVY_RAIN_WEATHER	4

class WeatherRegion : public RegionObject
{
public:
	WeatherRegion() : RegionObject()
	{
		currentStatus = 0;
		desiredStatus = 0;

		mSI = gWorldManager->getSI();
	}

	void updateRegion()
	{
		//Handle players that move regions. Damn trouble makers...
		Object*		object;
		ObjectSet	objList;

		if(!mSubZoneId)
		{
			mQTRegion	= mSI->getQTRegion(mPosition.x,mPosition.z);
			mSubZoneId	= (uint32)mQTRegion->getId();
			mQueryRect	= Anh_Math::Rectangle(mPosition.x - mWidth,mPosition.z - mHeight,mWidth*2,mHeight*2);
		}

		if(mParentId)
		{
			mSI->getObjectsInRange(this,&objList,ObjType_Player,mWidth);
		}

		if(mQTRegion)
		{
			mQTRegion->mTree->getObjectsInRangeContains(this,&objList,ObjType_Player,&mQueryRect);
		}

		ObjectSet::iterator objIt = objList.begin();

		while(objIt != objList.end())
		{
			object = (*objIt);

			if(!(checkKnownObjects(object)))
			{
				playerEntered(object);
			}

			++objIt;
		}

		PlayerObjectSet oldKnownObjects = mKnownPlayers;
		PlayerObjectSet::iterator objSetIt = oldKnownObjects.begin();

		while(objSetIt != oldKnownObjects.end())
		{
			object = dynamic_cast<Object*>((*objSetIt));

			if(objList.find(object) == objList.end())
			{
				this->removeKnownObject(object);
			}

			++objSetIt;
		}


		//Update the actual weather.
		if(currentStatus > desiredStatus)
		{
			--currentStatus;

			//Update players on the change.
			
		}
		else if(currentStatus < desiredStatus)
		{
			++currentStatus;

			//Update players on the change.

		}
	}

	void playerEntered(Object* object)
	{

	}

	//This is where the weather is NOW.
	uint8 currentStatus;
	//This is where the weather is going.
	uint8 desiredStatus;

	ZoneTree* mSI
	QTRegion* mQTRegion;
	uint32 mSubZoneId;
	Anh_Math::Rectangle mQueryRect;
};

WeatherManager::WeatherManager(uint64 currentTime)
{
	//===BEGIN CONFIG==
	//@todo: replace these with per-server values (when we get the db config system)

	//Weather System Count (default=1)
	mWeatherSystemCount = gWorldConfig->getConfiguration("Weather_System_Count", 1);

	//How often the weather system updates. Default is 60minutes.
	mWeatherUpdateInterval = gWorldConfig->getConfiguration("Weather_Update_Interval", 60);

	//How many regions per row?
	mRegionsPerRow = gWorldConfig->getConfiguration("Weather_System_RegionsPerRow", 16);

	//Width of the map.
	mWidth = gWorldConfig->getConfiguration("Map_width", 16384);

	//===END CONFIG===

	//Setup the regions
	uint32 regions = mRegionsPerRow * mRegionsPerRow;

	ZoneTree* SI = gWorldManager->getSI();

	uint32 blockWidth = mWidth / mRegionsPerRow;

	for(uint32 i=0; i < regions; ++i)
	{
		WeatherRegion* pRegion = new WeatherRegion();

		float x = (i*blockWidth) - mWidth/2;
		float z = mWidth - (i*blockWidth);

		pRegion->mQTRegion	= SI->getQTRegion(x,z);
		pRegion->mSubZoneId	= (uint32)pRegion->mQTRegion->getId();
		pRegion->mQueryRect	= Anh_Math::Rectangle(x,z,blockWidth,blockWidth);

		mRegions.push_back(pRegion);
	}

	//Perform the prep and first update.
	uint64 mLastWeatherReseed = 0;
	uint64 mLastWeatherUpdate = 0;

	update(currentTime);

	gLogger->log(LogManager::NOTICE, "Weather Manager Loaded.");
}

WeatherManager::~WeatherManager()
{
	std::vector<WeatherRegion*>::iterator it = mRegions.begin();
	std::vector<WeatherRegion*>::iterator end = mRegions.end();
	while(it != end)
	{
		delete (*it);
		mRegions.erase(it);

		it = mRegions.begin();
	}
}

void WeatherManager::update(uint64 currentTime)
{
	//First we need to check and see if we should be randomizing things.
	if((currentTime - mLastWeatherReseed) > mWeatherUpdateInterval)
	{
		//We need a clean slate;
		for(uint32 i=0; i < mRegions.size(); ++i)
		{
			mRegions[i]->desiredStatus = 0;
		}

		//We need to reseed.
		for(uint32 i=0; i < mWeatherSystemCount; ++i)
		{
			//First lets get a random region.
			uint32 regionId = gRandom->getRand() % mRegions.size();
			WeatherRegion* region = mRegions[regionId];
			
			//This region will be a STORM
			region->desiredStatus = HEAVY_RAIN_WEATHER;
			_affectSurrounding(regionId);
		}
	}

	//Now we begin updating. This includes "phasing" in and out depending on shifts.
	if((currentTime - mLastWeatherUpdate) > 30000)
	{
		for(unsigned int i=0; i < mRegions.size(); ++i)
			mRegions[i]->updateRegion();
	}
}

/*void WeatherManager::_affectSurrounding(uint32 regionId)
{
	WeatherRegion* Region = mRegions[regionId];
	std::vector<uint32> modified;
	
	bool touchesLeft = false;
	bool touchesRight = false;
	bool touchesTop = false;
	bool touchesBottom = false;

	if(regionId % mRegionsPerRow == 0)
		touchesLeft = true;

	if((regionId+1) % mRegionsPerRow == 0)
		touchesRight = true;

	if((regionId - mRegionsPerRow) < 0)
		touchesTop = true;

	if((regionId + mRegionsPerRow) >= mRegions.size())
		touchesBottom = true;

	//Left
	if(!touchesLeft)
	{
		if(!touchesTop && (mRegions[regionId-mRegionsPerRow-1]->desiredStatus == 0))
		{
			//Top Left
			mRegions[regionId-mRegionsPerRow-1]->desiredStatus = (Region->desiredStatus - 1);
			modified.push_back(regionId-mRegionsPerRow-1);
		}

		if(!touchesBottom && (mRegions[regionId+mRegionsPerRow-1]->desiredStatus == 0))
		{
			//Bottom Left
			mRegions[regionId+mRegionsPerRow-1]->desiredStatus = (Region->desiredStatus - 1);
			modified.push_back(regionId+mRegionsPerRow-1);
		}

		if(mRegions[regionId-1]->desiredStatus == 0)
		{
			//Left
			mRegions[regionId-1]->desiredStatus = (Region->desiredStatus - 1);
			modified.push_back(regionId-1);
		}
	}

	if(!touchesTop && (mRegions[regionId-mRegionsPerRow]->desiredStatus == 0))
	{
		//Middle Top
		mRegions[regionId-mRegionsPerRow]->desiredStatus = (Region->desiredStatus - 1);
		modified.push_back(regionId-mRegionsPerRow);
	}
	
	if(!touchesBottom && (mRegions[regionId+mRegionsPerRow]->desiredStatus == 0))
	{
		//Middle Bottom
		mRegions[regionId+mRegionsPerRow]->desiredStatus = (Region->desiredStatus - 1);
		modified.push_back(regionId+mRegionsPerRow);
	}

	//Right
	if(!touchesRight)
	{
		if(!touchesTop && (mRegions[regionId-mRegionsPerRow+1]->desiredStatus == 0))
		{
			//Top Right
			mRegions[regionId-mRegionsPerRow+1]->desiredStatus = (Region->desiredStatus - 1);
			modified.push_back(regionId-mRegionsPerRow+1);
		}

		if(!touchesBottom && (mRegions[regionId+mRegionsPerRow+1]->desiredStatus == 0))
		{
			//Bottom Right
			mRegions[regionId+mRegionsPerRow+1]->desiredStatus = (Region->desiredStatus - 1);
			modified.push_back(regionId+mRegionsPerRow+1);
		}

		if(mRegions[regionId+1]->desiredStatus == 0)
		{
			//Right
			mRegions[regionId+1]->desiredStatus = (Region->desiredStatus - 1);
			modified.push_back(regionId+1);
		}
	}

	//We already set the 1s we don't need to set any 0s
	if(Region->desiredStatus != 2)
	{
		for(unsigned int i=0; i < modified.size(); ++i)
			_affectSurrounding(modified[i]);
	}
}*/