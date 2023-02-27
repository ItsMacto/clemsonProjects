/*
 * =====================================================================================
 *         Name:  Mac Howe, Pmhowe
 *         Date:  12/7/2022
 *      Section:  020
 *        Title:  PA4 "Fun With ppm Images"
 *  Description:  containing the needed #include statements, header & pixel struct
 *  definitions, and function prototypes
 * =====================================================================================
 */

#ifndef DEFS_H
#define DEFS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct header
{
	char type[3];
	int width;
	int height;
	int maxColor;
} header_t;

typedef struct pixel
{
	int red, green, blue;
} pixel_t;

int showMenu();

header_t getHeader(FILE *in);

void writeHeader(header_t head, FILE *out);

void fillImageArray(pixel_t *p, int height, int width, FILE *in);

void writePixels(pixel_t *p, int height, int width, FILE *out);

void reduceSize(pixel_t *p, int height, int width, pixel_t *outP);

void greenScreen(pixel_t *in1, pixel_t *in2, pixel_t *out2, int height, int width);
#endif
