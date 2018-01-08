//=========================================================
//encryption-decryption
//Your name: Omar Gonzalez
//Contact: omargb22@gmail.com
//Complier:  G++
//File type: README.txt
//=========================================================


This program that performs encryption/decryption of a text file. Encryption means you need to scramble the words of a file to become secure. Decryption means you need to apply some rules to an encrypted file in order to find the original file with its original content. An example of encryption is to replace each letter in a file with its consecutive letter in the alphabet. Therefore, ‘a’ is replaced by ‘b’, ‘b’ is replaced by ‘c’ and so on and finally ‘z’ is replaced by ‘a’. Thus, if the file contains the following message:
			I am a student at csusm
The encrypted message becomes:
			J bn b tuvefou bu dtvtn
Then if you get this encrypted message and the key is 1, it means you need to shift the alphabets in the decrypted message by 1 to the left to get the original message back.

This method is called “rot1” indicating that every alphabet rotates by 1 during the encryption. Similarly, rot10 means every alphabet should be rotated by 10 during encryption.

Another method of encryption is to create cryptogram. A cryptogram is a message or word where each letter is replaced with another letter. For example, the string:

			The birds name was squawk
might be scrambled to form
			xms kbypo zhqs fho obrhfu

Note that space or any punctuation is not scrambled. In this particular case, ‘T’ was replaced with ’x’, each ‘a’ was replaced with ‘h’. etc. We assume there is no difference between lower case or uppercase.

so, this program that performs different types of encryption or description. First, you need to ask the user to see if the user wants to do encryption or decryption. If the user wants to do encryption, you should find out if the user wants to use “rot” method or cryptogram method. If the user selects the “rot” method, you need to ask for the encryption key. For example, entering 15, means that the user wants to use “rot15” method to do encryption. If the user selects the cryptogram method, you should open the cryptogram text file where the cryptogram string is stored. The cryptogram string should contain a string of 26 letters where the first letter corresponds to letter ‘a’, the second letter corresponds to letter ‘b’ and so on. For example, your cryptogram file may contain the following message. 
				wyijkcuvdpqlzhtgabmxefonrs

which means ‘w’ corresponds to ‘a’,  ‘y’ corresponds to ‘b’ and … and finally ‘s’ corresponds to ‘z’.

The same procedure should be followed for decryption. You need to ask the user which method the user wants to use (rot or cryptogram) for encryption. Then write the routines that takes an encrypted file and does the decryption to get the original file back.
