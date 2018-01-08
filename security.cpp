//=========================================================
//encryption-decryption
//Your name: Omar Gonzalez
//Contact: omargb22@gmail.com
//Complier:  G++
//File type: security.cpp implementation class
//=========================================================

#include "security.h"

security::security()    //A constructor method with "r" initialized with 0 and "cryp" initialized with a space.
{
  rot = 0;     //Set attributes equal to the initial values.
  cryptogram = " ";
}

void security::decision()  //A function that holds a menu for the user. Consisting of usable functions that were declared in the public section.
{
  //1st message to ask user if they want to (Option 1)Encrypt or (option 2)Decrypt
  int choice1;
  cout<< "User Option" << endl;
  cout<<"1.Encrypt: "<<endl;
  cout<<"2.Decrypt: " <<endl;
  cout<<"choice:";
  cin>>choice1;

  //if user choose Encryption
  if(choice1==1)                                //Encrypt files if choice1 == 1.
    {
      //For encryption, asking the user whether they want to use ROT method or cryptogram
      //Option 1:Rot
      //Option 2:Cryptogram
      int choice2;  //A local variable that takes in a response from the user.
      cout<<"\n1.Encrypt using ROT: ";
      cout<<"\n2.Encrypt using cryptogram: ";
      cout<<"\n choice:";
      cin>>choice2;
      //Encrypt file using a Rot if choice2 == 1
      if(choice2==1)
        {
          int rot;  //A local variable that takes in the rotation key inputted by the user.
          cout<<"Enter ROT number: ";
          cin>>rot;
          encryptFileUsingRot(rot); //Calls encryptFileUsingRot function, passing a "rot" number to the function.

        }
         //Encrypt file using a cryptogram if choice2 == 2
      else if(choice2==2)
        {
          encryptFileUsingCrypto();             //Calls encryptFileUsingCrypto() function.
        }

    }
    //user to decryption
  else if(choice1==2)                           //Go to decryption section if choice 1 == 2.
    {
      int choice3;  //A local variable that holds the response from the user.
      cout<<"\n1.Decrypt using ROT: ";
      cout<<"\n2.Decrypt using cryptogram: ";
      cout<<"\n choice:";
      cin>>choice3;
      if(choice3==1)
        {
         int rot2;  //Local variable that holds the rotation key. Must match the key used for the encryption.
	          cout<<"Enter ROT key: ";
          cin>>rot2;
          decryptUsingRot(rot2);                //  Calls decryptUsingRot method and passes "rot2".
        }
        else if(choice3==2)
        {
            decryptFileUsingCrypto();           //Calls the decryptFileUsingCrypto function.
        }
    }
}

void security::encryptFileUsingRot(int rot)//Parameters include the rotation key which is passed from the decision function.
{
  string fileName;  //Local variable that holds what the user wants to encrypt.
  string resultFile;    //Local variable that holds the encryption file name inputted by the user.
  cout<<"Enter file name of desired encrypted file(Include suffix): ";
  cin>>fileName;
  cout<<"Enter file for the result to be stored in(Include suffix): ";
  cin>>resultFile;

  ifstream fin;
  ofstream fout;

  fin.open(fileName.data());    //Open the variable names using the data() function
  fout.open(resultFile.data());

  string word; //A local variable that stores the word that is read from the text file inputted by the user.
  while(fin>>word)  //As long as a word is read into "word", proceed.
    {
      string encword;   //A local variable that will include an encrypted word after calling the encryptWordUsingRot function.
      encword = encryptWordUsingRot(rot,word); //Call encryptWordUsingRot passing the rotation number and a word from the text file.
      fout<<encword<<" "; //Put the encrypted word into an output file with a space preceding it.
    }
  fin.close();//Close both files.
  fout.close();
}

string security::encryptWordUsingRot(int rot,string word)//Finished
{
  for(int i = 0; i < word.size();i++)
    {
      word[i]=tolower(word[i]);       //convert letters to lowercase(ASCII)
    }

  string encWord = word;
  for(int i = 0; i < encWord.size();i++)
    {
      char OG = word[i];          //set [i] char of word in OG(original gangsta) variable. Why is it okay to use c\
                                    har here and not int? DataType does not matter when loading word
        if(OG >= 'a' && OG <='z')
        {
      int newchar;
      newchar = OG + rot;         //add OG + rot and set to newchar
      if(newchar > 'z')
        newchar -=26;           //If newchar is greater that z, subtract 26. Why 26? What if ASCII is great than 1\
22? Always sub 26
      encWord[i] = newchar;       //newchar gets placed in first element of the word
        }
    }
  return encWord;                 //return new word to encryptUsingRot(int rot)
}

void security::encryptFileUsingCrypto()
{
  string cryptogramFile;
  string resultCrypto;
  string dataFile;
  ifstream finData;
  ifstream finCryp;
  ofstream fout;

  cout<<"Enter file name containing cryptogram(Include suffix): ";
  cin>>cryptogramFile;
  cout<<"Enter file name you would like to encrypt(Include suffix): ";
  cin>>dataFile;
  cout<<"Enter the resulting filename(Include suffix): ";
  cin>>resultCrypto;

  finData.open(dataFile.data());//Open file containing the message
  finCryp.open(cryptogramFile.data());//Open file containing the cryptogram
  fout.open(resultCrypto.data());//Open file where the encrypted message will be placed

 string cryptogramKey;
 string data;

 finCryp>>cryptogramKey;//Read in the cryptogram key into cryptogramKey variable.

 while(finData>>data)//While a word is read into the variable data
   {
     string encWord = data;   //store word into encWord variable
     for(int i = 0; i < encWord.size();i++)// i less than size of word
       {
                 char character = encWord[i];//set first character from word to character
                 character = tolower(character);//change each character to a lower case letter
                 if(character >= 'a' && character <= 'z')
                   {
                     char newChar = cryptogramKey[character -'a'];
                     encWord[i] = newChar;
                   }
       }
     fout<<encWord<<" ";
   }
finData.close();
finCryp.close();
fout.close();
}

void security:: decryptUsingRot(int rot)
{
    string decrypFile;
    string resultFile;
    ifstream fin;
    ofstream fout;

    cout<<"Enter file name that you would like to decrypt: ";
    cin>>decrypFile;
    cout<<"Enter file name to store the result: ";
    cin>>resultFile;
fin.open(decrypFile.data());
fout.open(resultFile.data());

 string word;
  while(fin>>word)
    {
      string decword;
      decword = decryptWordUsingRot(rot,word);
      fout<<decword<<" ";
    }
  fin.close();
  fout.close();
}

string security:: decryptWordUsingRot(int rot,string word)
{
   for(int i = 0; i < word.size();i++)
    {
      word[i]=tolower(word[i]);       //convert letters to lowercase(ASCII)
    }

  string decWord = word;
  for(int i = 0; i < decWord.size();i++)
    {
      char OG = word[i];          //set [i] char of word in OG(original gangsta) variable. Why is it okay to use c\
                                    har here and not int? DataType does not matter when loading word
        if(OG >= 'a' && OG <='z')
        {
      int newchar;
      newchar = OG - rot;         //add OG + rot and set to newchar
      if(newchar > 'z')
        newchar -=26;           //If newchar is greater that z, subtract 26. Why 26? What if ASCII is great than 1\
22? Always sub 26
      decWord[i] = newchar;       //"newchar" gets placed in first element of the word.
        }
    }
  return decWord;                 //Return new word to encryptUsingRot(int rot).
}

void security:: decryptFileUsingCrypto()
{
  string cryptogramFile;    //Local variables that will include the file name that are inputted by the user.
  string resultCrypto;
  string dataFile;
  ifstream finData;
  ifstream finCryp;
  ofstream fout;

  cout<<"Enter file name containing cryptogram(Include suffix): ";
  cin>>cryptogramFile;
  cout<<"Enter file name you would like to decrypt(Include suffix): ";
  cin>>dataFile;
  cout<<"Enter the resulting filename(Include suffix): ";
  cin>>resultCrypto;

  finData.open(dataFile.data());//Open file containing the message
  finCryp.open(cryptogramFile.data());//Open file containing the cryptogram
  fout.open(resultCrypto.data());//Open file where the encrypted message will be placed

 string cryptogramKey;
 string data;

 finCryp>>cryptogramKey;//Read in the cryptogram key into cryptogramKey variable.

 while(finData>>data)//While a word is read into the variable data
   {
     string encWord = data;   //store word into encWord variable
     for(int i = 0; i < encWord.size();i++)// i less than size of word
       {
                 char character = encWord[i];//set first character from word to character
                 character = tolower(character);//change each character to a lower case letter
                 if(character >= 'a' && character <= 'z')
                   {
                       int index = cryptogramKey.find(character,0);
                     char newChar ='a' + index;
                     encWord[i] = newChar;
                   }
       }
     fout<<encWord<<" ";
   }
finData.close();    //Close files.
finCryp.close();
fout.close();
}
