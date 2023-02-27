/*
 * =====================================================================================
 *         Name:  Mac Howe, Pmhowe
 *         Date:  12/7/2022
 *      Section:  020
 *        Title:  PA4 "Fun With ppm Images"
 *  Description:  contains the getHeader() scans file for the header and adds it to
 * pointer struct
 * =====================================================================================
 */

#include "defs.h"

header_t getHeader(FILE *in)
{
	header_t head;
	fscanf(in, "%s", head.type);
	fscanf(in, "%d %d %d", &head.width, &head.height, &head.maxColor);
	return (head);
}
