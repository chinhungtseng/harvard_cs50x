/*
 * Crack: https://lab.cs50.io/cs50/labs/2019/x/crack/
 * ---------------------------------------------------
 * username:hash
 * 
 * brian:51.xJagtPnb6s
 * bjbrown:50GApilQSG3E2
 * emc:502sDZxA/ybHs
 * greg:50C6B0oz0HWzo
 * jana:50WUNAFdX/yjA
 * lloyd:50n0AAUD.pL8g
 * malan:50CcfIk1QrPr6
 * natmelo:50JIIyhDORqMU
 * rob:51v3Nh6ZWGHOQ
 * veronica:61v1CDwwP95bY
 * walker:508ny6Rw0aRio
 * zamyla:50cI2vYkF0YU2
 * -------------------------------------------------
 * 1. password: each password is no longer than five (5) characters and only alphabetical characters 
 *    -> 387659012 different set
 * 2. salt: a two-character string chosen from the set [a-zA-Z0-9./]  
 *    -> there are 4096(64^2) different set
 * -----------------------------------------------------------------------------------------------------
 * Pseudocode:
 * Check only have two command-line arguments (argv[0] and argv[1])
 *     if not, print error message and return 1
 * Assign hash a variable name 
 * Iterate to create the password with salt
 *     random a new hash password
 *         
 *     If the password matches the hash
 *         print the password
 *         stop the iteration, and return 0
 * */

#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check only have two command-line argument (argv[0] and argv[1]); 
    // if not, print error message and return 1
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    // Assign hash a variable name 
    string hash = argv[1];    
    
    // Assign password variable: 5 characters + 1 NULL
    char pwd[6] = "\0\0\0\0\0\0";
    // Assign salt variable: 2 characters + 1 NULL
    char salt[3];
    memcpy(salt, hash, 2);
    salt[2] = 0;
    
    // Create password list
    string pwd_list = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int lenp = 53;
    
    // Iterate hash passwrod
    for (int p0 = 0; p0 < lenp; p0++)
    {
        for (int p1 = 0; p1 < lenp; p1++)
        {
            for (int p2 = 0; p2 < lenp; p2++)
            {
                for (int p3 = 0; p3 < lenp; p3++)
                {
                    for (int p4 = 1; p4 < lenp; p4++)
                    {
                        pwd[0] = pwd_list[p4];
                        pwd[1] = pwd_list[p3];
                        pwd[2] = pwd_list[p2];
                        pwd[3] = pwd_list[p1];
                        pwd[4] = pwd_list[p0];
                        
                        if (strcmp(crypt(pwd, salt), hash) == 0)
                        {
                            printf("%s\n", pwd);
                            return 0;
                        }
                    }
                }
            }
        }
    }

}
