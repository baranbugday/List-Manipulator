# List Manipulator (C++)

A basic c++ program to manipulate a vector object with user inputs. Includes features
such as adding a number to the vector, scanning the vector for a spesific number, taking
the mean value of the numbers included in the vector, displaying smallest and largest
number, clearing the list and quitting the cmd interface.

# Number Guessing Game (C++)

A cmd game with the purpose of guessing the 4-digit number with different digits.
Count of the digits that are guessed correctly is shown as the output. The sign in front of 
the output shows that if the positions of the digits are correct or not. In order to win
the player must get the output of +4 which means all the digits are correct(4) and they
are all positioned correct(+). For example:

Random generated number is : 1678

User input is              : 1843

Output is                  : +1 -1

User input is              : 1687

Output is                  : +2 -2

# Image Processing Functions Using OpenCV (Python)

### Grey Level Slicing

A band pass filter function written for 8-bit images monochrome images.

### Filter Image

A function that contains 5 different filters which is x directional highpass filter,
y-directional highpass filter, Laplacian filter, uniform averaging filter, Gaussian
averaging filter. OpenCV imread function is configured for 8-bit monochrome images.
Function pads the image by using the function padding below(padImage) after padding the
3x3 kernel is applied. Then using the cropping function below(cropImage) returns the 
original sized image.

##### Pad Image

A function with parameters of (img,nrp,ncr). Function is designed to change the size of
the (nr, nc) image to (nrp, ncr) and put the old image data to the center of the new
image.

##### Crop Image

A function with parameters of (img, cropArray). cropArray parameter contains the desired
upper-left and bottom-right cordinates coordinates for cropping.

