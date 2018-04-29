#include <ctype.h>
#include <stdio.h>
#include "CryptoUtils.h"

int main()
{
    char CypherTextAES[1024],Base64AES[1024];
    char*PlainTextAES="CryptoUtils Test String!!!";
    EncryptAES_CBC(PlainTextAES,CypherTextAES,"CryptoUtils");
    int CypherLen=16+((strlen(PlainTextAES)-1)/16)*16;
    int Base64Len=BinToBase64(CypherTextAES,Base64AES,CypherLen);
    puts(Base64AES);
    return 0;
}
