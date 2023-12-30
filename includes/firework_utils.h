#ifndef FIREWORK_UTILS_H_
#define FIREWORK_UTILS_H_

typedef struct tFirework tFirework;

tFirework * CreateFirework ();

void SetTerminalColor (tFirework * firework);

void SetDefaultColor ();

int GetFireworkExplosionDelay (tFirework * firework);

int GetFireworkSize (tFirework * firework);

int GetFireworkPositionX (tFirework * firework);

int GetFireworkPositionY (tFirework * firework);

void UpdateFireworkPosition (tFirework * firework,  int x, int y);

char * GetFireWorkHexColor (tFirework * firework);

void DestroyFirework (tFirework * firework);

#endif // !FIREWORK_UTILS_H_