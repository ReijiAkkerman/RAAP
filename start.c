#include <stdio.h>
#include <stdlib.h>
#include "app/core/global/var/bmp_definition.h"
#include "app/core/handling/preparing_image.h"

int main(int argc, char* argv[]) {
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    char red = atoi(argv[3]);
    char green = atoi(argv[4]);
    char blue = atoi(argv[5]);
    make_full_image(width, height, red, green, blue);
    return 0;
}