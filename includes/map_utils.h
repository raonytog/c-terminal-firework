#ifndef MAP_UTILS_H_
#define MAP_UTILS_H_

#include "firework_utils.h"
#include <stdbool.h>

typedef struct tMap tMap;

tMap * CreateMap();

tFirework * GetMapFirework(tMap * map);

int GetMapHight (tMap * map);

int GetMapWeight (tMap * map);

void LaunchFireWorkOnMap (tMap * map);

void DestroyMap(tMap * map);

void PrintMap (tMap * map);

void ConvertTempToParticles (tMap * map);

void ClearTerminal ();

bool IsInsideTheMap (tMap * map, int x, int y);

bool ThereIsParticleNextTo (tMap * map, int x, int y);

#endif // !MAP_UTILS_H_