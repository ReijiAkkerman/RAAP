project(RAAP)

set(source 

start.c
app/core/global/var/bmp_definition.c
app/core/handling/preparing_image.c

)

add_executable(a.out ${source})