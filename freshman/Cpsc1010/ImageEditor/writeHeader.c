/*
 * =====================================================================================
 *         Name:  Mac Howe, Pmhowe
 *         Date:  12/7/2022
 *      Section:  020
 *        Title:  PA4 "Fun With ppm Images"
 *  Description:  writes the header to the file provided
 * =====================================================================================
 */

#include "defs.h"

void writeHeader(header_t head, FILE *out)
{
	fprintf(out, "%s\n%d %d %d\n", head.type, head.width, head.height, head.maxColor);
}
