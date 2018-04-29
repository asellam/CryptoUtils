#ifndef CRYPTOUTILS_H_INCLUDED
#define CRYPTOUTILS_H_INCLUDED
//----------------------------------------------//
//-Crypto Security Utils                       -//
//----------------------------------------------//
//-Original Implementation by: SELLAM Abdellah -//
//----------------------------------------------//
//-Contributers:                               -//
//----------------------------------------------//
//-Creation Date: August 2017                  -//
//----------------------------------------------//

//Type Declarations

#include <string.h>
#include <stdint.h>
#include <stdlib.h>
typedef unsigned char uchar;
typedef unsigned int uint;

//CONVERSTION STUFF

//Converts a Base64 string into a Binary string
int Base64ToBin(char*B64Data,char*BinData,int Len64);
//Converts a Binary string into a Base64 string
int BinToBase64(char*BIN,char*B64,int LEN);
//Converts a Hexadecimal string into a Binary String
int HexToBin(char*InputStr,char*InputBin);

//MD5 STUFF

//Generates the MD5 hash string for an input string
void MD5(char*input,char*output);

//DES STUFF

//Encryptes a plain-text string using DES in ECB Mode
void EncryptDES(char*InputBin,char*OutputBin,char*Key);
//Decryptes a cypher-text string using DES in ECB Mode
void DecryptDES(char*InputHex,char*OutputBin,char*Key);

//AES STUFF

//Encryptes a single plain-text string using AES in ECB Mode
void EncryptAES_ECB(char*InputTxt,char*OutputTxt,char*KeyTxt,int LenTxt,int LenKey);
//Encryptes a single plain-text string using AES in CBC Mode
void EncryptAES_CBC(char*InputTxt,char*OutputTxt,char*KeyTxt,int LenTxt,int LenKey);
//Decryptes a single Cypher-text string using AES in ECB Mode
void DecryptAES_ECB(char*InputTxt,char*OutputTxt,char*KeyTxt,int LenTxt,int LenKey);
//Decryptes a single Cypher-text string using AES in CBC Mode
void DecryptAES_CBC(char*InputTxt,char*OutputTxt,char*KeyTxt,int LenTxt,int LenKey);

//IMPLEMENTATIONS
#include "Conversion.h"
#include "CryptoDES.h"
#include "CryptoAES.h"
#endif // CRYPTOUTILS_H_INCLUDED
