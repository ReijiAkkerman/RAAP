#include <stdio.h>
#include <stdlib.h>

#include "../global/var/bmp_definition.h"

#include "preparing_image.h"

void make_full_image(int width, int height, char red, char green, char blue) {
    int* height_n_width = validate_image_size(width, height);
    char* image_contents = prepare_image_size(height_n_width[1], height_n_width[0]);
    struct BMP bmp = prepare_image_struct(height_n_width[1], height_n_width[0]);
    struct BMP* p_bmp = &bmp;
    complete_image_contents(image_contents, height_n_width[1], height_n_width[0], red, green, blue, 0x00);

    FILE* fp = fopen("image.bmp", "wb");
    fwrite(&BMP_header_name, sizeof(BMP_header_name), 1, fp);
    fwrite(p_bmp, sizeof(bmp), 1, fp);
    fwrite(image_contents, height_n_width[0] * height_n_width[1] * 3, 1, fp);
    fclose(fp);
}

int* validate_image_size(int width, int height) {
    int* p_array = malloc(2 * sizeof(int));
    if((width % 4) != 0) width += (width % 4);
    if((height % 4) != 0) height += (height % 4);
    p_array[0] = height;
    p_array[1] = width;
    return p_array;
}

char* prepare_image_size(int width, int height) {
    char* image_contents = malloc(width * height * 3);
    return image_contents;
}

struct BMP prepare_image_struct(int width, int height) {
    struct BMP bmp;

    bmp.header1.BMP_file_size = 54 + (width * height * 3);
    bmp.header1.unused_1 = 0;
    bmp.header1.pixel_array_start = 54;

    bmp.header2.DIB_header_size = 40;
    bmp.header2.width = width;
    bmp.header2.height = height;
    bmp.header2.color_planes_amount = 1;
    bmp.header2.amount_bits_on_pixel = 24;
    bmp.header2.unused_1 = 0;
    bmp.header2.bitmap_info = 48;
    bmp.header2.width_pixels_print = 2835;
    bmp.header2.height_pixels_print = 2835;
    bmp.header2.unused_2 = 0;
    bmp.header2.unused_3 = 0;

    return bmp;
}

void complete_image_contents(char* pointer, int width, int height, char red, char green, char blue, char alpha) {
    for(register int i = 0; i < height; i++) {
        for(register int j = 0; j < width; j++) {
            for(register char k = 0; k < 3; k++) {
                switch(k) {
                    case 0:
                        pointer[(i * width * 3) + (j * 3) + k] = blue;
                        break;
                    case 1:
                        pointer[(i * width * 3) + (j * 3) + k] = green;
                        break;
                    case 2:
                        pointer[(i * width * 3) + (j * 3) + k] = red;
                        break;
                    case 3:
                        pointer[(i * width * 3) + (j * 3) + k] = alpha;
                        break;
                }
            }
        }
    }
}