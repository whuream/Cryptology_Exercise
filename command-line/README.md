DES encryption and decryption and check sorftware.

First argument is mode(1 stand for encryption, 2 stand for deciption, 3 stand for check : encryption and deciption)
Second argument is path of key
Third argument is path of input file

if mode is 3
Fourth argument is path of output file(selectable)
Fifth argument is path of reoutput file(selectable)
Sixth argument is path of log file(selectable)

if mode is 1 or 2
Fourth argument is path of output file(selectable)
Fifth argument is path of log file(selectable)

eg:
Cryptology.exe 3 key.txt input.txt output.txt reoutput.txt log.txt