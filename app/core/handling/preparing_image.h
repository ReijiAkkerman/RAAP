void make_full_image(int width, int height, char red, char green, char blue);
int* validate_image_size(int width, int height);
char* prepare_image_size(int width, int height);
struct BMP prepare_image_struct(int width, int height);
void complete_image_contents(char* pointer, int width, int height, char red, char green, char blue, char alpha);