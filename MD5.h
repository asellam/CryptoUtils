#ifndef MD5_H_INCLUDED
#define MD5_H_INCLUDED

//----------------------------------------------//
//-MD5 Hashing Algorithm                       -//
//----------------------------------------------//
//-Original Implementation by: SELLAM Abdellah -//
//----------------------------------------------//
//-Contributers:                               -//
//----------------------------------------------//
//-Creation Date: May 2015                     -//
//----------------------------------------------//

//Generates the MD5 hash string for an input string
//Parameters:
//-----------
//input(in): Plain Text (String)
//output(Out): MD5 hash (String)
void MD5(char*input,char*output)
{
    UINT s[64]={7,12,17,22, 7,12,17,22, 7,12,17,22, 7,12,17,22,
                5, 9,14,20, 5, 9,14,20, 5, 9,14,20, 5, 9,14,20,
                4,11,16,23, 4,11,16,23, 4,11,16,23, 4,11,16,23,
                6,10,15,21, 6,10,15,21, 6,10,15,21, 6,10,15,21};

    UINT K[64]={0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,
                0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,
                0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,
                0x6b901122,0xfd987193,0xa679438e,0x49b40821,
                0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,
                0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
                0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,
                0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,
                0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,
                0xa4beea44,0x4bdecfa9,0xf6bb4b60,0xbebfbc70,
                0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,
                0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,
                0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,
                0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,
                0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,
                0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};

    UINT A=0x67452301;
    UINT B=0xefcdab89;
    UINT C=0x98badcfe;
    UINT D=0x10325476;
    UINT SIZE=strlen(input);
    UINT original=SIZE<<3;
    UCHAR*temp=(UCHAR*)malloc(64*(1+(SIZE-1)/64));
    strcpy((char*)temp,input);
    if(SIZE%64!=0)
    {
        temp[SIZE]=0x80;
        SIZE++;
        while(SIZE%64<56)
        {
            temp[SIZE]=0;
            SIZE++;
        }
        if(SIZE%64==56)
        {
            temp[SIZE]=(UCHAR)(original&0xFF);
            SIZE++;
            temp[SIZE]=(UCHAR)((original>>8)&0xFF);
            SIZE++;
            temp[SIZE]=(UCHAR)((original>>16)&0xFF);
            SIZE++;
            temp[SIZE]=(UCHAR)((original>>24)&0xFF);
            SIZE++;
            temp[SIZE]=0;
            SIZE++;
            temp[SIZE]=0;
            SIZE++;
            temp[SIZE]=0;
            SIZE++;
            temp[SIZE]=0;
            SIZE++;
        }
    }
    int BC512=SIZE/64;
    for(int k=0;k<BC512;k++)
    {
        UINT*M=(UINT*)(temp+k*64);
        UINT AA=A;
        UINT BB=B;
        UINT CC=C;
        UINT DD=D;
        UINT F,g;
        for(int i=0;i<64;i++)
        {
            if(i<16)
            {
                F=(B&C)|(~B&D);
                g=i;
            }
            else if(i<32)
            {
                F=(B&D)|(C&~D);
                g=(5*i+1)%16;
            }
            else if(i<48)
            {
                F=B^C^D;
                g=(3*i+5)%16;
            }
            else
            {
                F=C^(B|~D);
                g=(7*i)%16;
            }
            UINT Z=D;
            D=C;
            C=B;
            B=B+leftRotate(A+F+M[g]+K[i],s[i]);
            A=Z;
        }
        A+=AA;
        B+=BB;
        C+=CC;
        D+=DD;
    }
    free(temp);
    sprintf(output,"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",A&0xFF,(A>>8)&0xFF,(A>>16)&0xFF,(A>>24)&0xFF,B&0xFF,(B>>8)&0xFF,(B>>16)&0xFF,(B>>24)&0xFF,C&0xFF,(C>>8)&0xFF,(C>>16)&0xFF,(C>>24)&0xFF,D&0xFF,(D>>8)&0xFF,(D>>16)&0xFF,(D>>24)&0xFF);
}

#endif // MD5_H_INCLUDED
