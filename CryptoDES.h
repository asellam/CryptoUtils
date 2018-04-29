#ifndef CRYPTODES_H_INCLUDED
#define CRYPTODES_H_INCLUDED
//----------------------------------------------//
//-Data Encryption Standard                    -//
//----------------------------------------------//
//-Original Implementation by: SELLAM Abdellah -//
//----------------------------------------------//
//-Contributers:                               -//
//----------------------------------------------//
//-Creation Date: August 2017                  -//
//----------------------------------------------//

#define MAX_ROUND 16
//Initial Permutation Table
int IP[64]={57,49,41,33,25,17, 9, 1,
            59,51,43,35,27,19,11, 3,
            61,53,45,37,29,21,13, 5,
            63,55,47,39,31,23,15, 7,
            56,48,40,32,24,16, 8, 0,
            58,50,42,34,26,18,10, 2,
            60,52,44,36,28,20,12, 4,
            62,54,46,38,30,22,14, 6};
//Final Permutation Table
int FP[64]={39,7,47,15,55,23,63,31,
            38,6,46,14,54,22,62,30,
            37,5,45,13,53,21,61,29,
            36,4,44,12,52,20,60,28,
            35,3,43,11,51,19,59,27,
            34,2,42,10,50,18,58,26,
            33,1,41, 9,49,17,57,25,
            32,0,40, 8,48,16,56,24};
//Expansion Permutation Box
int E[48]={31, 0, 1, 2, 3, 4,
            3, 4, 5, 6, 7, 8,
            7, 8, 9,10,11,12,
           11,12,13,14,15,16,
           15,16,17,18,19,20,
           19,20,21,22,23,24,
           23,24,25,26,27,28,
           27,28,29,30,31, 0};
//DES KeySchedule Permuted Choice 1
int PC1[56]={56,48,40,32,24,16, 8,
             0 ,57,49,41,33,25,17,
             9 , 1,58,50,42,34,26,
             18,10, 2,59,51,43,35,
             62,54,46,38,30,22,14,
             6 ,61,53,45,37,29,21,
             13, 5,60,52,44,36,28,
             20,12, 4,27,19,11, 3};
//DES KeySchedule Permuted Choice 2
int PC2[48]={13,16,10,23, 0, 4,
             2 ,27,14, 5,20, 9,
             22,18,11, 3,25, 7,
             15, 6,26,19,12, 1,
             40,51,30,36,46,54,
             29,39,50,44,32,47,
             43,48,38,55,33,52,
             45,41,49,35,28,31};
//DES Straight Permutation
int P[32]={15, 6,19,20,28,11,27,16,
            0,14,22,25, 4,17,30, 9,
            1, 7,23,13,31,26, 2, 8,
           18,12,29, 5,21,10, 3,24};
//DES Substitution Boxes (S-Boxes)
int SBox[8][4][16]={{{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
                     {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                     {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
                     {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
                    {{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
                     {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
                     {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
                     {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
                    {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
                     {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
                     {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
                     {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
                    {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
                     {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
                     {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
                     {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},
                    {{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
                     {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
                     {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
                     {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
                    {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
                     {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
                     {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
                     {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
                    {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
                     {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
                     {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
                     {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
                    {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
                     {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
                     {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
                     {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}};
//DES KeyHalves left rotation based on Round
int LSi[MAX_ROUND]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
//Applies main DES Key Encryption routine to the Right part
//of the 64 bits block
//Parameters:
//-----------
//K(in): 64Bits Key (int64)
//R(in): 32bits Right Part (int32)
//Return Values:
//--------------
//int: The resulting 32 bits of the DES main operation
int DES_F(int64_t K,int R)
{
    int64_t ER=0;
    for(int j=47;j>=0;j--)
    {
        ER=ER<<1;
        ER=ER+((R>>E[j])&0x01);
    }
    int64_t ERK=ER^K;
    int SERK=0;
    for(int j=0;j<8;j++)
    {
        int X=(ERK&0x01)+((ERK&0x20)>>4);
        int Y=(ERK&0x1E)>>1;
        SERK=SERK+(SBox[7-j][X][Y]<<(j*4));
        ERK=ERK>>6;
    }
    int PSERK=0;
    for(int j=0;j<32;j++)
    {
        PSERK=PSERK<<1;
        PSERK=PSERK+((SERK>>(31-P[j]))&0x01);
    }
    return PSERK;
}
//Generates a 64Bits Keys-List for DES rounds
//Parameters:
//-----------
//Key(in): Original DES Key (String)
//Keys(out): Generated Round Keys List (List of int64)
void DES_Keys(char*Key,int64_t*Keys)
{
    int C=0;
    for(int j=0;j<28;j++)
    {
        C=C<<1;
        int d=PC1[j]/8;
        int m=7-PC1[j]%8;
        C=C+((Key[d]>>m)&0x01);
    }
    int D=0;
    for(int j=28;j<56;j++)
    {
        D=D<<1;
        int d=PC1[j]/8;
        int m=7-PC1[j]%8;
        D=D+((Key[d]>>m)&0x01);
    }
    for(int I=0;I<MAX_ROUND;I++)
    {
        Keys[I]=0;
        C=((C<<LSi[I])&0x0FFFFFFF)+(C>>(28-LSi[I]));
        D=((D<<LSi[I])&0x0FFFFFFF)+(D>>(28-LSi[I]));
        for(int j=0;j<48;j++)
        {
            Keys[I]=Keys[I]<<1;
            if(PC2[j]<28)
                Keys[I]=Keys[I]+((C>>(27-PC2[j]))&0x01);
            else
                Keys[I]=Keys[I]+((D>>(55-PC2[j]))&0x01);
        }
    }
}
//Returns the Right part of a 64Bits Block
//Parameters:
//-----------
//InputS(in): 64Bits Block (String)
//Return Values:
//--------------
//int: The Right part of a 64Bits Block
int GetRight(char*InputS)
{
    int R=0;
    for(int j=31;j>=0;j--)
    {
        R=R<<1;
        int d=(7-IP[j]/8);
        int m=IP[j]%8;
        R=R+((InputS[d]>>m)&0x01);
    }
    return R;
}
//Returns the Left part of a 64Bits Block
//Parameters:
//-----------
//InputS(in): 64Bits Block (String)
//Return Values:
//--------------
//int: The Left part of a 64Bits Block
int GetLeft(char*InputS)
{
    int L=0;
    for(int j=63;j>=32;j--)
    {
        L=L<<1;
        int d=(7-IP[j]/8);
        int m=IP[j]%8;
        L=L+((InputS[d]>>m)&0x01);
    }
    return L;
}
//Encryptes a plain-text string using DES in ECB Mode
//Parameters:
//-----------
//InputBin(in): plain-text string (String)
//OutputBin(out): cypher-text string (String)
//Key(in): DES Encryption Key (String)
void EncryptDES(char*InputBin,char*OutputBin,char*Key)
{
    int LenI=strlen(InputBin);
    int A=LenI/8;
    int B=LenI%8;
    int64_t SK[MAX_ROUND];
    DES_Keys(Key,SK);
    for(int i=0;i<A;i++)
    {
        char*BlockP=&(InputBin[i*8]);
        int R=GetRight(BlockP);
        int L=GetLeft(BlockP);
        for(int I=0;I<MAX_ROUND;I++)
        {
            int F=L^DES_F(SK[I],R);
            L=R;R=F;
        }
        for(int j=0;j<8;j++)
        {
            int idxO=i*8+7-j;
            OutputBin[idxO]=0;
            for(int k=j*8+7;k>=j*8;k--)
            {
                OutputBin[idxO]=OutputBin[idxO]<<1;
                if(FP[k]<32)
                    OutputBin[idxO]=OutputBin[idxO]+((L>>FP[k])&0x01);
                else
                    OutputBin[idxO]=OutputBin[idxO]+((R>>(FP[k]-32))&0x01);
            }
        }
    }
}
//Decryptes a cypher-text string using DES in ECB Mode
//Parameters:
//-----------
//InputBin(in): cypher-text string (String)
//OutputBin(out): plain-text string (String)
//Key(in): DES Decryption Key (String)
void DecryptDES(char*InputHex,char*OutputBin,char*Key)
{
    char*InputBin=(char*)malloc(strlen(InputHex)/2+1);
    int LenI=HexToBin(InputHex,InputBin);
    int A=LenI/8;
    int B=LenI%8;
    int64_t SK[MAX_ROUND];
    DES_Keys(Key,SK);

    for(int i=0;i<A;i++)
    {
        char*BlockP=&(InputBin[i*8]);
        int R=GetLeft(BlockP);
        int L=GetRight(BlockP);
        for(int I=0;I<MAX_ROUND;I++)
        {
            int F=R^DES_F(SK[15-I],L);
            R=L;L=F;
        }

        for(int j=0;j<8;j++)
        {
            int idxO=i*8+j;
            OutputBin[idxO]=0;
            for(int k=j*8;k<j*8+8;k++)
            {
                OutputBin[idxO]=OutputBin[idxO]<<1;
                if(FP[k]<32)
                    OutputBin[idxO]=OutputBin[idxO]+((L>>(31-FP[k]))&0x01);
                else
                    OutputBin[idxO]=OutputBin[idxO]+((R>>(63-FP[k]))&0x01);
            }
        }
    }
    free(InputBin);
}
#endif // CRYPTODES_H_INCLUDED
