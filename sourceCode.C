/*
// encryption-decryption
// Your name: Omar Gonzalez
// contact: omargb22@gmail.com
// Compiler:  g++
// File type: main SOURCE CODE
// The purpose of this program is to encrypt and/or decrypt a message using two methods. These methods are by rotation and by using a cryptogram.
The input for encrypting and decrypting using rotation is the rotation key which is inputted by the user.
The input for encrypting and decrypting using a cryptogram is the cryptogram key which is written in a separate file and read into a variable using ifstream from the fstream class.
The encryptions are done by reading in word by word from a file created by the user that should include some text. In my program I input a file called original.txt which contains the text from the prompt. The encryption using the rotation method is then outputted into a file created and inputted by the user.
Decryption using both methods are outputted into files that the user creates. (None of the files in this program are hard coded).
*/

#include "security.h"

int main()
{
  security crypt;   //Create a object of type security.
  crypt.decision(); //Call the decision function of class security.
}
