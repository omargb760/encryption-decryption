// =======================================================
// encryption-decryption
// Your name: Omar Gonzalez
// Contact: omargb22@gmail.com
// Compiler:  g++
// File type: header file 1stack.h

//=======================================================
#include <iostream> //Include libraries for the use of their functions.
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#ifndef SECURITY_H
#define SECURITY_H
//Class security which will be used for crypting and decryting methods and security purposes

class security{ //Declare a class called security.

  private:
  int rot;
  string cryptogram;

  public:
  security();                          //Constructor method with default values initialized in the implementation section.
  void decision();                                      //A method which holds a menu for the user that is called in the main.
  void encryptFileUsingRot(int rot);                  //Encrypts a whole file using the rotation method. Taking in a rotation key inputted by the user
  string encryptWordUsingRot(int rot,string word);    //Encrypts a single word for the encryptFileUsingRot function. Taking in both the rotation key and a word from the encryptFileUsingRot function.
  void encryptFileUsingCrypto();                      //Encrypts a file using the cryptogram with a cryptogram.
  string decryptWordUsingRot(int rot,string word);      //Decrypts a single word using the rotation method for decryptUsingRot function. Passing the rotation key inputted by the user and a word from the decryptUsingRot function.
  void decryptUsingRot(int rot);                        //Decrypts a whole file using the rotation method. Taking in a rotation key inputted by the user.
  void decryptFileUsingCrypto();                        //Decrypts a whole file using the cryptogram method with a cryptogram.
};

#endif
