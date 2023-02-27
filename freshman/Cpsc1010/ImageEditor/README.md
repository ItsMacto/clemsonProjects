This program will present a menu to the user:
       Image manipulation program.
       1. reduce size of image #1
       2. superimpose image #2 onto image #1
       3. reduce size of superimposed image
       4. quit the program
When the user chooses 1, the program will create and save to a file a smaller version of the image (Disney.pnm, for example).
When the user chooses 2, the program will superimpose image #2 onto image #1 (ClemsonPaw.pnm superimposed onto Disney.pnm, for example).
When the user chooses 3, the program will create a reduced size of the superimposed image.
When the user chooses 4, the program will quit.



mainDriver.c file
main() function:
1. open input files for reading
2. get headers for images and create header for the reduced size image
3. declare arrays to hold the input images
4. fill the arrays for the images
5. present the menu to the user by calling showMenu()
  a. loop for multiple menu choices
    i. if or switch statement for menu choices
      1. menu choice 1
        a. malloc space for a smaller image
        b. call reduceSize() function sending the original image and the smaller image that was just declared; after the function is done, the smaller image will contain the array of the smaller image
        c. declare file pointer for smaller image output
        d. call writeHeader()
        e. call writePixels()
      2. menu choice 2
        a. malloc space for a new image for the green screen (superimposed image)
        b. call greenScreen() function sending both of the original images and the new
image that was just declared; after the function is done, the new image will contain the
array of the first image with the second image super-imposed on to it
        c. declare file pointer for smaller image output
        d. call writeHeader()
        e. call writePixels()
    3. menu choice 3
        a. malloc space for a new image for the green screen (superimposed image)
        
        b. call greenScreen() function sending both of the original images and the new
image that was just declared; after the function is done, the new image will contain the
array of the first image with the second image super-imposed on to it
        c. declare file pointer for smaller image output
        d. call writeHeader()
        e. call writePixels()
    4. quit the program
  ii. call showMenu() again
  
showMenu() function:
1. present menu to user and return their menu choice back to the function from where it was called
2. force the user to enter a valid menu choice in this function, repeatedly showing the menu until a 1, 2, 3, or 4 is chosen
 
manip.c file
reduceSize() function:
1. same code as halfSizeWritePixels() function from labs 10 & 11 except the new pixel values will be written into a
new array instead of sent to stdout
2. the new array is another parameter added to this function in addition to the original image

greenScreen() function:
1. this function will take in 3 images: both of the original images (same sized images) as well as the new image that will be
created
2. the second original image will be an image where the background is green (0 255 0)
3. the new image will be a contain the pixels of the first image whereever the background of the second image is green;
otherwise is will contain the pixels of the second image
