#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED
//----------------------------------------------//
//-Basic Conversion Routines                   -//
//----------------------------------------------//
//-Original Implementation by: SELLAM Abdellah -//
//----------------------------------------------//
//-Contributers:                               -//
//----------------------------------------------//
//-Creation Date: August 2017                  -//
//----------------------------------------------//

//Converts a single Base64 Symbol into its Binary equivalent
int Base64Value(char B64Char)
{
    if(B64Char>='A'&&B64Char<='Z')
        return B64Char-'A';
    if(B64Char>='a'&&B64Char<='z')
        return B64Char-'a'+26;
    if(B64Char>='0'&&B64Char<='9')
        return B64Char-'0'+52;
    if(B64Char=='+')
        return 62;
    if(B64Char=='/')
        return 63;
    if(B64Char=='=')
        return 64;
}
//Converts a Base64 string into a Binary string
int Base64ToBin(char*B64Data,char*BinData,int Len64)
{
    int p=0,q=0;
    while(p<Len64)
    {
        if(B64Data[p]=='\n')
            p++;
        else
        {
            int V0=Base64Value(B64Data[p]);
            int V1=Base64Value(B64Data[p+1]);
            int V2=Base64Value(B64Data[p+2]);
            int V3=Base64Value(B64Data[p+3]);
            if(V2==64)
            {
                BinData[q]  =(V0<<2)+(V1>>4);
                q=q+1;
            }
            else if(V3==64)
            {
                BinData[q]  =(V0<<2)+(V1>>4);
                BinData[q+1]=(V1<<4)+(V2>>2);
                q=q+2;
            }
            else
            {
                BinData[q]  =(V0<<2)+(V1>>4);
                BinData[q+1]=(V1<<4)+(V2>>2);
                BinData[q+2]=(V2<<6)+V3;
                q=q+3;
            }
            p=p+4;
        }
    }
    BinData[q]=0;
    return q;
}
//Converts a single Binary Symbol into its Base64 equivalent
char Bin64Value(int BIN)
{
    if(BIN>=0&&BIN<=25)
        return BIN+'A';
    if(BIN>=26&&BIN<=51)
        return BIN+'a'-26;
    if(BIN>=52&&BIN<=61)
        return BIN+'0'-52;
    if(BIN==62)
        return '+';
    if(BIN==63)
        return '/';
    return '*';
}
//Converts a Binary string into a Base64 string
int BinToBase64(char*BIN,char*B64,int LEN)
{
    int P=0,N=0;
    while(P<LEN)
    {
        int D0=(uchar)(BIN[P]);
        int D1=(uchar)(BIN[P+1]);
        int D2=(uchar)(BIN[P+2]);
        int V0=D0>>2;
        int V1=((D0&0x03)<<4)+(D1>>4);
        int V2=((D1&0x0F)<<2)+(D2>>6);
        int V3=D2&0x3F;
        B64[N]=Bin64Value(V0);
        B64[N+1]=Bin64Value(V1);
        B64[N+2]=Bin64Value(V2);
        B64[N+3]=Bin64Value(V3);
        N+=4;
        P+=3;
    }
    B64[N]=0;
    return N;
}
//Converts a Hexadecimal string into a Binary String
int HexToBin(char*InputStr,char*InputBin)
{
    int LenStr=strlen(InputStr);
    if(LenStr%2!=0)
    {
        printf("Error: String Length Must be an Even Number!\n");
        return -1;
    }
    int LenBin=LenStr/2;
    int j=0;
    for(int i=0;i<LenBin;i++)
    {
        if(InputStr[j]>='0'&&InputStr[j]<='9')
            InputBin[i]=(InputStr[j]-'0')<<4;
        else if(InputStr[j]>='A'&&InputStr[j]<='F')
            InputBin[i]=(InputStr[j]-'A'+10)<<4;
        else if(InputStr[j]>='a'&&InputStr[j]<='f')
            InputBin[i]=(InputStr[j]-'a'+10)<<4;
        else
        {
            printf("Error: Invalid Input for HEX at Character [%d]!\n",j);
            return -1;
        }
        j++;
        if(InputStr[j]>='0'&&InputStr[j]<='9')
            InputBin[i]+=InputStr[j]-'0';
        else if(InputStr[j]>='A'&&InputStr[j]<='F')
            InputBin[i]+=InputStr[j]-'A'+10;
        else if(InputStr[j]>='a'&&InputStr[j]<='f')
            InputBin[i]+=InputStr[j]-'a'+10;
        else
        {
            printf("Error: Invalid Input for HEX at Character [%d]!\n",j);
            return -1;
        }
        j++;
    }
    return LenBin;
}

#endif // CONVERSION_H_INCLUDED
