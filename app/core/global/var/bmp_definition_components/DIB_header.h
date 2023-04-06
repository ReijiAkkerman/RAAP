struct DIB_header {
    __int32_t DIB_header_size;
    __int32_t width;
    __int32_t height;
    __int16_t color_planes_amount;
    __int16_t amount_bits_on_pixel;
    __int32_t unused_1;
    __int32_t bitmap_info;
    __int32_t width_pixels_print;
    __int32_t height_pixels_print;
    __int32_t unused_2;
    __int32_t unused_3;
};