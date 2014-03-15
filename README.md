# DES encryption and decryption

*   `command-line` command line application

*   `MFC` MFC application

## Developer Dependencies

*   Visual Studio 2010/2012

## Usage

*   

    ### in command-line:

        des.exe <mode> <keyfile> <infile> [outfile] [reoutfile] [logfile]
        
        mode:
        1 encryption
        2 decryption
        3 encryption & decryption (check)
        
        key: path of key file (8 bytes)
        
        infile: input file
        
        outfile: output file
        
        reoutfile: decrypted file after encripted (used only in encryption & decryption mode)
    
    
    ![command-line sample](./sample/command-line.png)

*   

    ### MFC
    
    ![MFC](./sample/MFC.png)
    
## Code Map

*   

    ### command-line
    
    ![command-line](./sample/command-line-code.bmp)

*   

    ### MFC
    
    ![MFC](./sample/MFC-code.bmp)
    
## Class Map

*   
    ### command-line
    
    ![command-line](./sample/command-line-class.bmp)
    
*   
    ### MFC
    
    ![MFC](./sample/MFC-class.bmp)
