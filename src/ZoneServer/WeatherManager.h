#include "Utils/typedefs.h"

class WeatherRegion;

class WeatherManager
{
public:
	WeatherManager(uint64 currentTime);
	~WeatherManager();

	void update(uint64 currentTime);

private:
	void _affectSurrounding(uint32 regionId);
	uint32 mWeatherSystemCount;
	uint32 mWeatherUpdateInterval;
	uint32 mRegionsPerRow;
	uint32 mWidth;

	uint64 mLastWeatherReseed;
	uint64 mLastWeatherUpdate;

	std::vector<WeatherRegion*> mRegions;
};

