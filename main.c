#include <stdio.h>
#include "includes/firework_utils.h"
#include "includes/map_utils.h"

int main () {
    tMap * map = CreateMap();
    
    printf("Preparing fireworks launch in a few seconds...\n");
    LaunchFireWorkOnMap(map);

    SetTerminalColor(GetMapFirework(map));
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\tHappy new year!");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    SetDefaultColor();
    
    DestroyMap(map);

    return 0;
}