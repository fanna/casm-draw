#include<stdio.h>

typedef struct {
    char id_len;
    char map_type;
    char img_type;
    int  map_first;
    int  map_len;
    char map_entry_size;
    int  x;
    int  y;
    int  width;
    int  height;
    char bpp;
    char desc;
} HEADER;

void create_header(HEADER h, FILE *tga)
{
    fputc(h.map_type, tga);
    fputc(h.id_len, tga);
    fputc(h.img_type, tga);
    fputc(h.map_first % 256, tga);
    fputc(h.map_first / 256, tga);
    fputc(h.map_len % 256, tga);
    fputc(h.map_len / 256, tga);
    fputc(h.map_entry_size, tga);
    fputc(h.x % 256, tga);
    fputc(h.x / 256, tga);
    fputc(h.y % 256, tga);
    fputc(h.y / 256, tga);
    fputc(h.width % 256, tga);
    fputc(h.width / 256, tga);
    fputc(h.height % 256, tga);
    fputc(h.height / 256, tga);
    fputc(h.bpp, tga);
    fputc(h.desc, tga);
}

void draw(int r, int g, int b, FILE *tga)
{
    for(int x = 0; x < 640; x++)
      for(int y = 0; y < 480; y++)
      {
        if(x < 80)
        {
          fputc(100%256, tga); //B
          fputc(128%256, tga); //G
          fputc(200%256, tga); //R
        }
        else if(x > 80 && x <160)
        {
          fputc(100%256, tga); //B
          fputc(100%256, tga); //G
          fputc(243%256, tga); //R
        }
        else if( x > 160 && x < 240)
        {
          fputc(50%256, tga); //B
          fputc(180%256, tga); //G
          fputc(203%256, tga); //R
        }
        else if(x > 240 && x < 320)
        {
          fputc(150%256, tga); //B
          fputc(250%256, tga); //G
          fputc(203%256, tga); //R
        }
        else if(x > 320 && x < 400)
        {
          fputc(230%256, tga); //B
          fputc(90%256, tga); //G
          fputc(203%256, tga); //R
        }
        else if(x > 400 && x < 480)
        {
          fputc(200%256, tga); //B
          fputc(180%256, tga); //G
          fputc(23%256, tga); //R
        }
        else if(x > 480 && x < 560)
        {
          fputc(78%256, tga); //B
          fputc(111%256, tga); //G
          fputc(111%256, tga); //R
        }
        else
        {
          fputc(190%256, tga); //B
          fputc(100%256, tga); //G
          fputc(222%256, tga); //R
        }

      }
}

int main ()
{
    FILE *tga;
    HEADER header;

    header.id_len = 0;
    header.map_type = 0;
    header.img_type = 2;
    header.map_first = 0;
    header.map_len = 0;
    header.map_entry_size = 0;
    header.x = 0;
    header.y = 0;
    header.width = 640;
    header.height = 480;
    header.bpp = 24;
    header.desc= 0x20;

    tga = fopen("picture.tga", "w+");

    create_header(header, tga);
    draw(256, 256, 256, tga);

    fclose(tga);

  return 0;
}
