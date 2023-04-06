#include "bmp_definition_components/main_header.h"
#include "bmp_definition_components/DIB_header.h"

extern short int BMP_header_name;

struct BMP {
    struct main_header header1;
    struct DIB_header header2;
};