#include "includes/firework_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tFirework {
    char hexColor[6];
    int duration;
};

tFirework * CreateFirework () {
    tFirework * firework = malloc(sizeof(tFirework));
    printf("Type firework's hex color: #");
    scanf("%s", firework->hexColor);
    IsValidHexColor(firework->hexColor);

    printf("Type firework's duration: ");
    scanf("%d", &firework->duration);


    return firework;
}

void IsValidHexColor (char * hexColor) {
    for (int i = 0; i < 6; i++) {
        if (hexColor[i] >= 'a' && hexColor[i] <= 'f') {
            return;
        }
    }

    printf("\nInvalid HexColor.\nColor changed to hexColor #000000\n\n");
    strcpy(hexColor, "000000");
    return;
}