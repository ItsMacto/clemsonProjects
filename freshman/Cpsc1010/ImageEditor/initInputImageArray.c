/*
 * =====================================================================================
 *         Name:  Mac Howe, Pmhowe
 *         Date:  12/7/2022
 *      Section:  020
 *        Title:  PA4 "Fun With ppm Images"
 *  Description:  fills the image array pointer with input from a file
 * =====================================================================================
 */

#include "defs.h"

void fillImageArray(pixel_t *p, int height, int width, FILE *in)
{
	for (int i = 0; i < height * width; i++)
	{
		fscanf(in, "%d %d %d", &p[i].red, &p[i].green, &p[i].blue);
	}
}
