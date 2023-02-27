/*
 * =====================================================================================
 *         Name:  Mac Howe, Pmhowe
 *         Date:  12/7/2022
 *      Section:  020
 *        Title:  PA4 "Fun With ppm Images"
 *  Description:  containing the main() function and a function called showMenu()
 * Takes user input and modifies the files accordingly
 * =====================================================================================
 */

#include "defs.h"

int main(int argc, char *argv[])
{

	// file pointers
	FILE *inFile = fopen(argv[1], "r");
	if (inFile == NULL)
	{
		fprintf(stderr, "File open error1.  Exiting program\n");
		exit(1);
	}
	FILE *pawFile = fopen(argv[2], "r");
	if (pawFile == NULL)
	{
		fprintf(stderr, "File open error2.  Exiting program\n");
		exit(1);
	}
	FILE *outFile1 = fopen("smallerImage1.pnm", "w");
	if (outFile1 == NULL)
	{
		fprintf(stderr, "File open error3.  Exiting program\n");
		exit(1);
	}
	FILE *outFile2 = fopen("greenScreen1.pnm", "w");
	if (outFile2 == NULL)
	{
		fprintf(stderr, "File open error4.  Exiting program\n");
		exit(1);
	}
	FILE *outFile3 = fopen("smallerImage2.pnm", "w");
	if (outFile2 == NULL)
	{
		fprintf(stderr, "File open error5.  Exiting program\n");
		exit(1);
	}

	// headers created
	header_t inHead = getHeader(inFile);
	header_t pawHead = getHeader(pawFile);
	header_t outHead = inHead;
	outHead.width = outHead.width / 2;
	outHead.height = outHead.height / 2;

	// space made for pixels
	pixel_t *inPtr = NULL, *pawPtr = NULL, *outPtr1 = NULL, *outPtr2 = NULL, *outPtr3 = NULL, *outPtr4 = NULL;
	inPtr = (pixel_t *)malloc(inHead.width * inHead.height * sizeof(pixel_t));
	pawPtr = (pixel_t *)malloc(pawHead.width * pawHead.height * sizeof(pixel_t));
	outPtr1 = (pixel_t *)malloc(outHead.width * outHead.height * sizeof(pixel_t));
	outPtr2 = (pixel_t *)malloc(inHead.width * inHead.height * sizeof(pixel_t));
	outPtr3 = (pixel_t *)malloc(inHead.width * inHead.height * sizeof(pixel_t));
	outPtr4 = (pixel_t *)malloc(outHead.width * outHead.height * sizeof(pixel_t));

	// pixel array filled
	fillImageArray(inPtr, inHead.height, inHead.width, inFile);
	fillImageArray(pawPtr, pawHead.height, pawHead.width, pawFile);

	// input from user and checks to only use once
	int input = 0, option1 = 0, option2 = 0, option3 = 0;
	// loops till 4(exit command)
	while (input != 4)
	{
		input = showMenu();
		switch (input)
		{
		// option one- reduces size of image #1 and prints to file
		case 1:
		{
			if (option1 != 0)
			{
				fprintf(stdout, "Menu 1 option already chosen.\n");
				break;
			}
			else
			{
				reduceSize(inPtr, inHead.height, inHead.width, outPtr1);
				writeHeader(outHead, outFile1);
				writePixels(outPtr1, outHead.height, outHead.width, outFile1);
				option1 = 1;
				break;
			}
		}
		// option two- superimpose image #2 onto image #1 and prints to file
		case 2:
		{
			if (option2 != 0)
			{
				fprintf(stdout, "Menu 2 option already chosen.\n");
				break;
			}
			else
			{
				greenScreen(inPtr, pawPtr, outPtr2, inHead.height, inHead.width);
				writeHeader(inHead, outFile2);
				writePixels(outPtr2, inHead.height, inHead.width, outFile2);
				option2 = 1;
				break;
			}
		}
		case 3:
		{
			if (option3 != 0)
			{
				fprintf(stdout, "Menu 3 option already chosen.\n");
				break;
			}
			else
			{
				greenScreen(inPtr, pawPtr, outPtr3, inHead.height, inHead.width);
				reduceSize(outPtr3, inHead.height, inHead.width, outPtr4);
				writeHeader(outHead, outFile3);
				writePixels(outPtr4, outHead.height, outHead.width, outFile3);
				option3 = 1;
				break;
			}
		}
		case 4:
		{
			// message for exit if wanted
			break;
		}
		default:
			printf("Invalid input\n");
		}
	}
	return 0;
}

// shows the menu and returns user input
int showMenu()
{
	int i;
	printf("Image Manipulation Program\n\n1. reduce size of image #1\n2. superimpose image #2 onto image #1\n3. reduce size of superimposed image\n4. quit the program\n");
	fscanf(stdin, "%d", &i);
	return i;
}
