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

void white(FILE *tga);
void yellow(FILE *tga);
void cyan(FILE *tga);
void green(FILE *tga);
void magenta(FILE *tga);
void red(FILE *tga);
void blue(FILE *tga);
void black(FILE *tga);

void draw(int x, FILE *tga)
{
    int y;
    for(; x < 640; x++)
      for(y = 0; y < 480; y++)
      {
        if(x < 80)
        {
          white(tga);
        }
        else if(x > 80 && x <160)
        {
          yellow(tga);
        }
        else if( x > 160 && x < 240)
        {
          cyan(tga);
        }
        else if(x > 240 && x < 320)
        {
          green(tga);
        }
        else if(x > 320 && x < 400)
        {
          magenta(tga);
        }
        else if(x > 400 && x < 480)
        {
          red(tga);
        }
        else if(x > 480 && x < 560)
        {
          blue(tga);
        }
        else
        {
          black(tga);
        }

      }
}

void animate(FILE *tga)
{
  int k = 0;
  int z;

  for(z = 0; z < 24; z++)
  {
    k += 25;

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

    char filename[64];
    sprintf (filename, "anim%d.tga", z);

    tga = fopen(filename, "wb");

    create_header(header, tga);
    draw(k, tga);

    fclose(tga);
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
    draw(header.x, tga);
    animate(tga);

    fclose(tga);

  return 0;
}
