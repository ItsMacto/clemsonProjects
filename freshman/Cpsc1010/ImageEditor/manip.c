/*
 * =====================================================================================
 *         Name:  Mac Howe, Pmhowe
 *         Date:  12/7/2022
 *      Section:  020
 *        Title:  PA4 "Fun With ppm Images"
 *  Description:  contains two functions: reduceSize() and greenScreen()
 * reduce size halfs the height and width of the immage array
 * green screen fills and array with image one untill the pixle is not green then uses
 * image 2
 * =====================================================================================
 */

#include "defs.h"

void reduceSize(pixel_t *p, int height, int width, pixel_t *outP)
{
	int x = 0, y = 0;
	for (int i = 0; i < height; i += 2)
	{
		for (int j = 0; j < width; j += 2)
		{
			outP[y] = p[x + j];
			y++;
		}
		x += width * 2;
	}
}

void greenScreen(pixel_t *in1, pixel_t *in2, pixel_t *out2, int height, int width)
{
	for (int i = 0; i < height * width; i++)
	{
		if (in2[i].red == 0 && in2[i].green == 255 && in2[i].blue == 0)
		{
			out2[i] = in1[i];
		}
		else
		{
			out2[i] = in2[i];
		}
	}
}