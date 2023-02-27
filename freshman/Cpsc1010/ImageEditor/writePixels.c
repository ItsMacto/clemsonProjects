/*
 * =====================================================================================
 *         Name:  Mac Howe, Pmhowe
 *         Date:  12/7/2022
 *      Section:  020
 *        Title:  PA4 "Fun With ppm Images"
 *  Description:  writes the pixel array to the file provided
 * =====================================================================================
 */

#include "defs.h"
void writePixels(pixel_t *p, int height, int width, FILE *out)
{
      for (int i = 0; i < height * width; i++)
      {
            fprintf(out, "%i %i %i\n",
                    p[i].red, p[i].green, p[i].blue);
      }
}
