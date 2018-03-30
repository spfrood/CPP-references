/*
 **************************************************************************
 *                                                                        *
 *           General Purpose Hash Function Algorithms Test                *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the MIT License. *
 * http://www.opensource.org/licenses/MIT                                 *
 *                                                                        *
 **************************************************************************
*/


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "GeneralHashFunctions.h"

int main(int argc, char* argv[])
{
   const std::string key = "Then out spake brave Horatius,\nThe Captain of the Gate:\nTo every man upon this earth\nDeath cometh soon or late.\nAnd how can man die better\nThan facing fearful odds,\nFor the ashes of his fathers,\nAnd the temples of his gods.";
   
   std::cout << "General Purpose Hash Function Algorithms Test" << std::endl;
   std::cout << "By Arash Partow - 2002        " << std::endl;
   std::cout << "Key: "                          << key           << std::endl;
   std::cout << " 1. RS-Hash Function Value:   " << RSHash  (key) << std::endl;
   std::cout << " 2. JS-Hash Function Value:   " << JSHash  (key) << std::endl;
   std::cout << " 3. PJW-Hash Function Value:  " << PJWHash (key) << std::endl;
   std::cout << " 4. ELF-Hash Function Value:  " << ELFHash (key) << std::endl;
   std::cout << " 5. BKDR-Hash Function Value: " << BKDRHash(key) << std::endl;
   std::cout << " 6. SDBM-Hash Function Value: " << SDBMHash(key) << std::endl;
   std::cout << " 7. DJB-Hash Function Value:  " << DJBHash (key) << std::endl;
   std::cout << " 8. DEK-Hash Function Value:  " << DEKHash (key) << std::endl;
   std::cout << " 9. FNV-Hash Function Value:  " << FNVHash (key) << std::endl;
   std::cout << "10. BP-Hash Function Value:   " << BPHash  (key) << std::endl;
   std::cout << "11. AP-Hash Function Value:   " << APHash  (key) << std::endl;

   return 0;
}
