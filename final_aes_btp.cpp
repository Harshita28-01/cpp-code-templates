#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
#include <string>
#include <sys/time.h>
#include <iomanip>
#include <ios>
using namespace std;
#define N 100000

typedef bitset<8> byte;
typedef bitset<32> word;

const int Nr = 10; // AES-128 requires 10 rounds of encryption
const int Nk = 4;  // Nk d

// byte S_Box[16][16];
// void Chaotic_SBox()
// {
//     double dt = 0.002;
//     double dx, dy, dz;

//     float a = 0.2; // standard parameter value selected by Rossler
//     float b = 0.1;
//     float c = 5.7;

//     double x = 0; // strange attractor with unidentified variables
//     double y = 0;
//     double z = 0;

//     unordered_set<byte> st;

//     for (int i = 0; i < N; i++)
//     {
//         // 3 coupled non-linear differential equations:
//         dx = x + (-y - z) * dt;
//         dy = y + (x + a * y) * dt;
//         dz = z + (b + z * (x - c)) * dt;
//         x = dx;
//         y = dy;
//         z = dz;

//         if (i > 200)
//         {
//             int x6 = (int)(x * 1000000) % 10;
//             int y5 = (int)(y * 100000) % 10;
//             int z4 = (int)(z * 10000) % 10;
//             int num = (x6 * 100 + y5 * 10 + z4) % 256;
//             num = abs(num);
//             byte b = bitset<8>(num);
//             st.insert(b);
//             if (st.size() == 256)
//                 break;
//         }
//     }

//     int i = 0;
//     int j = 0;

//     for (auto it : st)
//     {
//         S_Box[i][j] = it;
//         j++;
//         if (j == 16)
//         {
//             i++;
//             j = 0;
//         }
//     }
// }

// byte Inv_S_Box[16][16];
// void Chaotic_Inv_S_Box()
// {
//     vector<char> dth = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
//     unordered_map<char, int> mp;
//     mp['0'] = 0;
//     mp['1'] = 1;
//     mp['2'] = 2;
//     mp['3'] = 3;
//     mp['4'] = 4;
//     mp['5'] = 5;
//     mp['6'] = 6;
//     mp['7'] = 7;
//     mp['8'] = 8;
//     mp['9'] = 9;
//     mp['a'] = 10;
//     mp['b'] = 11;
//     mp['c'] = 12;
//     mp['d'] = 13;
//     mp['e'] = 14;
//     mp['f'] = 15;
//     for (int i = 0; i < 16; i++)
//     {
//         for (int j = 0; j < 16; j++)
//         {
//             stringstream ss;
//             int number;
//             ss << hex << S_Box[i][j].to_ulong();
//             string s = ss.str();
//             int a;
//             int b;
//             if (s.size() == 1)
//             {
//                 a = 0;
//                 b = mp[s[0]];
//             }
//             else
//             {
//                 a = mp[s[0]];
//                 b = mp[s[1]];
//             }

//             string str = "";
//             str.push_back(dth[i]);
//             str.push_back(dth[j]);
//             int intValue = stoi(str, nullptr, 16);
//             bitset<8> bitsetFromHex(intValue);

//             Inv_S_Box[a][b] = bitsetFromHex;
//         }
//     }
// }

byte S_Box[16][16] = {
    {0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76},
    {0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0},
    {0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15},
    {0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75},
    {0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84},
    {0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF},
    {0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8},
    {0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2},
    {0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73},
    {0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB},
    {0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79},
    {0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08},
    {0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A},
    {0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E},
    {0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF},
    {0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16}};

byte Inv_S_Box[16][16] = {
    {0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB},
    {0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB},
    {0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E},
    {0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25},
    {0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92},
    {0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84},
    {0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06},
    {0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B},
    {0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73},
    {0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E},
    {0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B},
    {0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4},
    {0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F},
    {0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF},
    {0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61},
    {0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D}};

void Print_S_Box()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            stringstream ss;
            int number;
            ss << hex << S_Box[i][j].to_ulong();
            string s = ss.str();
            cout << s << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            stringstream ss;
            int number;
            ss << hex << Inv_S_Box[i][j].to_ulong();
            string s = ss.str();
            cout << s << " ";
        }
        cout << endl;
    }
}

word Rcon[10] = {0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000,
                 0x20000000, 0x40000000, 0x80000000, 0x1b000000, 0x36000000};

/**********************************************************************/
/*                                                                    */
/*                              AES Algorithmic Implementation*/
/*                                                                    */
/**********************************************************************/

/******************************Here is the encrypted transformation function ****************************************************/
/**
 *  S Box Conversion - The first four bits are line numbers and the last four bits are column numbers
 */
void SubBytes(byte mtx[4 * 4])
{
    for (int i = 0; i < 16; ++i)
    {
        int row = mtx[i][7] * 8 + mtx[i][6] * 4 + mtx[i][5] * 2 + mtx[i][4];
        int col = mtx[i][3] * 8 + mtx[i][2] * 4 + mtx[i][1] * 2 + mtx[i][0];
        mtx[i] = S_Box[row][col];
    }
}

/**
 *  Line Transform - Byte Cyclic Shift
 */
void ShiftRows(byte mtx[4 * 4])
{
    // The second line circle moves one bit to the left
    byte temp = mtx[4];
    for (int i = 0; i < 3; ++i)
        mtx[i + 4] = mtx[i + 5];
    mtx[7] = temp;
    // The third line circle moves two places to the left
    for (int i = 0; i < 2; ++i)
    {
        temp = mtx[i + 8];
        mtx[i + 8] = mtx[i + 10];
        mtx[i + 10] = temp;
    }
    // The fourth line moves three left circles
    temp = mtx[15];
    for (int i = 3; i > 0; --i)
        mtx[i + 12] = mtx[i + 11];
    mtx[12] = temp;
}

/**
 *  Multiplication over Finite Fields GF(2^8)
 */
byte GFMul(byte a, byte b)
{
    byte p = 0;
    byte hi_bit_set;
    for (int counter = 0; counter < 8; counter++)
    {
        if ((b & byte(1)) != 0)
        {
            p ^= a;
        }
        hi_bit_set = (byte)(a & byte(0x80));
        a <<= 1;
        if (hi_bit_set != 0)
        {
            a ^= 0x1b; /* x^8 + x^4 + x^3 + x + 1 */
        }
        b >>= 1;
    }
    return p;
}

/**
 *  Column transformation
 */
void normalMixColumns(byte mtx[4 * 4])
{
    byte arr[4];
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            arr[j] = mtx[i + j * 4];

        mtx[i] = GFMul(0x02, arr[0]) ^ GFMul(0x03, arr[1]) ^ arr[2] ^ arr[3];
        mtx[i + 4] = arr[0] ^ GFMul(0x02, arr[1]) ^ GFMul(0x03, arr[2]) ^ arr[3];
        mtx[i + 8] = arr[0] ^ arr[1] ^ GFMul(0x02, arr[2]) ^ GFMul(0x03, arr[3]);
        mtx[i + 12] = GFMul(0x03, arr[0]) ^ arr[1] ^ arr[2] ^ GFMul(0x02, arr[3]);
    }
}
void optimisedMixColumns(byte mtx[4 * 4])
{
    for (int i = 0; i < 4; ++i)
    {
        mtx[i] = mtx[i] ^ mtx[i + 4] ^ mtx[i + 8] ^ mtx[i + 12] ^ S_Box[6][9];
        mtx[i + 4] = mtx[i] ^ mtx[i + 4] ^ mtx[i + 8] ^ mtx[i + 12];
        mtx[i + 8] = mtx[i] ^ mtx[i + 4] ^ mtx[i + 8] ^ mtx[i + 12] ^ S_Box[7][11];
        mtx[i + 12] = mtx[i] ^ mtx[i + 4] ^ mtx[i + 8] ^ mtx[i + 12] ^ S_Box[9][11];
        std::swap(mtx[i], mtx[i + 12]);
    }
}

/**
 *  Round Key Plus Transform - XOR each column with the extended key
 */
void AddRoundKey(byte mtx[4 * 4], word k[4])
{
    for (int i = 0; i < 4; ++i)
    {
        word k1 = k[i] >> 24;
        word k2 = (k[i] << 8) >> 24;
        word k3 = (k[i] << 16) >> 24;
        word k4 = (k[i] << 24) >> 24;

        mtx[i] = mtx[i] ^ byte(k1.to_ulong());
        mtx[i + 4] = mtx[i + 4] ^ byte(k2.to_ulong());
        mtx[i + 8] = mtx[i + 8] ^ byte(k3.to_ulong());
        mtx[i + 12] = mtx[i + 12] ^ byte(k4.to_ulong());
    }
}

/**************************Here is the decrypted inverse transform function *******************************************************/
/**
 *  Inverse S-box transformation
 */
void InvSubBytes(byte mtx[4 * 4])
{
    for (int i = 0; i < 16; ++i)
    {
        int row = mtx[i][7] * 8 + mtx[i][6] * 4 + mtx[i][5] * 2 + mtx[i][4];
        int col = mtx[i][3] * 8 + mtx[i][2] * 4 + mtx[i][1] * 2 + mtx[i][0];
        mtx[i] = Inv_S_Box[row][col];
    }
}

/**
 *  Reverse Transform - Cyclic Right Shift in Bytes
 */
void InvShiftRows(byte mtx[4 * 4])
{
    // The second line circle moves one bit to the right
    byte temp = mtx[7];
    for (int i = 3; i > 0; --i)
        mtx[i + 4] = mtx[i + 3];
    mtx[4] = temp;
    // The third line circle moves two to the right
    for (int i = 0; i < 2; ++i)
    {
        temp = mtx[i + 8];
        mtx[i + 8] = mtx[i + 10];
        mtx[i + 10] = temp;
    }
    // Fourth line circle moves three to the right
    temp = mtx[12];
    for (int i = 0; i < 3; ++i)
        mtx[i + 12] = mtx[i + 13];
    mtx[15] = temp;
}

void normalInvMixColumns(byte mtx[4 * 4])
{
    byte arr[4];
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            arr[j] = mtx[i + j * 4];

        mtx[i] = GFMul(0x0e, arr[0]) ^ GFMul(0x0b, arr[1]) ^ GFMul(0x0d, arr[2]) ^ GFMul(0x09, arr[3]);
        mtx[i + 4] = GFMul(0x09, arr[0]) ^ GFMul(0x0e, arr[1]) ^ GFMul(0x0b, arr[2]) ^ GFMul(0x0d, arr[3]);
        mtx[i + 8] = GFMul(0x0d, arr[0]) ^ GFMul(0x09, arr[1]) ^ GFMul(0x0e, arr[2]) ^ GFMul(0x0b, arr[3]);
        mtx[i + 12] = GFMul(0x0b, arr[0]) ^ GFMul(0x0d, arr[1]) ^ GFMul(0x09, arr[2]) ^ GFMul(0x0e, arr[3]);
    }
}

void optimisedInvMixColumns(byte mtx[4 * 4])
{
    for (int i = 0; i < 4; ++i)
    {
        std::swap(mtx[i], mtx[i + 12]);
        mtx[i + 12] = mtx[i] ^ mtx[i + 4] ^ mtx[i + 8] ^ mtx[i + 12] ^ S_Box[9][11];
        mtx[i + 8] = mtx[i] ^ mtx[i + 4] ^ mtx[i + 8] ^ mtx[i + 12] ^ S_Box[7][11];
        mtx[i + 4] = mtx[i] ^ mtx[i + 4] ^ mtx[i + 8] ^ mtx[i + 12];
        mtx[i] = mtx[i] ^ mtx[i + 4] ^ mtx[i + 8] ^ mtx[i + 12] ^ S_Box[6][9];
    }
}

/******************************Following is the key extension section ***************************************************************/
/**
 * Convert four byte s to one word.
 */
word Word(byte &k1, byte &k2, byte &k3, byte &k4)
{
    word result(0x00000000);
    word temp;
    temp = k1.to_ulong(); // K1
    temp <<= 24;
    result |= temp;
    temp = k2.to_ulong(); // K2
    temp <<= 16;
    result |= temp;
    temp = k3.to_ulong(); // K3
    temp <<= 8;
    result |= temp;
    temp = k4.to_ulong(); // K4
    result |= temp;
    return result;
}

/**
 *  Cyclic left shift by byte
 *  That is to say, [a0, a1, a2, a3] becomes [a1, a2, a3, a0]
 */
word RotWord(word &rw)
{
    word high = rw << 8;
    word low = rw >> 24;
    return high | low;
}

/**
 *  S-box transformation for each byte in input word
 */
word SubWord(word sw)
{
    word temp;
    for (int i = 0; i < 32; i += 8)
    {
        int row = sw[i + 7] * 8 + sw[i + 6] * 4 + sw[i + 5] * 2 + sw[i + 4];
        int col = sw[i + 3] * 8 + sw[i + 2] * 4 + sw[i + 1] * 2 + sw[i];
        byte val = S_Box[row][col];
        for (int j = 0; j < 8; ++j)
            temp[i + j] = val[j];
    }
    return temp;
}

/**
 *  Key Extension Function - Extended 128-bit key to w[4*(Nr+1)]
 */
void KeyExpansion(byte key[4 * Nk], word w[4 * (Nr + 1)])
{
    word temp;
    int i = 0;
    // The first four of w [] are input key s
    while (i < Nk)
    {
        w[i] = Word(key[4 * i], key[4 * i + 1], key[4 * i + 2], key[4 * i + 3]);
        ++i;
    }

    i = Nk;

    while (i < 4 * (Nr + 1))
    {
        temp = w[i - 1]; // Record the previous word
        if (i % Nk == 0)
            w[i] = w[i - Nk] ^ SubWord(RotWord(temp)) ^ Rcon[i / Nk - 1];
        else
            w[i] = w[i - Nk] ^ temp;
        ++i;
    }
}

void KeyExpansionFibonacci(byte key[4 * Nk], word w[4 * (Nr + 1)])
{
    word temp;
    word Q[4];
    int i = 0;
    // The first four of w [] are input key s
    while (i < Nk)
    {
        Q[i] = Word(key[0 + i], key[4 + i], key[8 + i], key[12 + i]);
        i++;
    }

    w[0] = bitset<32>((Q[0].to_ulong() * Q[1].to_ulong() - Q[0].to_ulong()) % Q[2].to_ulong());
    w[1] = bitset<32>((Q[0].to_ulong() * Q[1].to_ulong() - Q[1].to_ulong()) % Q[2].to_ulong());
    i = 2;

    while (i < 4 * (Nr + 1))
    {
        w[i] = bitset<32>((SubWord(w[i - 1]).to_ulong() + w[i - 2].to_ulong() + 3 * i) % Q[3].to_ulong());
        ++i;
    }
}

/******************************Here are the encryption and decryption functions ********************************************************************/
/**
 *  encryption
 */
void normalEncrypt(byte in[4 * 4], word w[4 * (Nr + 1)])
{
    word key[4];
    for (int i = 0; i < 4; ++i)
        key[i] = w[i];
    AddRoundKey(in, key);

    for (int round = 1; round < Nr; ++round)
    {
        SubBytes(in);
        ShiftRows(in);
        normalMixColumns(in);
        for (int i = 0; i < 4; ++i)
            key[i] = w[4 * round + i];
        AddRoundKey(in, key);
    }

    SubBytes(in);
    ShiftRows(in);
    for (int i = 0; i < 4; ++i)
        key[i] = w[4 * Nr + i];
    AddRoundKey(in, key);
}

/**
 *  Decrypt
 */
void normalDecrypt(byte in[4 * 4], word w[4 * (Nr + 1)])
{
    word key[4];
    for (int i = 0; i < 4; ++i)
        key[i] = w[4 * Nr + i];
    AddRoundKey(in, key);

    for (int round = Nr - 1; round > 0; --round)
    {
        InvShiftRows(in);
        InvSubBytes(in);
        for (int i = 0; i < 4; ++i)
            key[i] = w[4 * round + i];
        AddRoundKey(in, key);
        normalInvMixColumns(in);
    }

    InvShiftRows(in);
    InvSubBytes(in);
    for (int i = 0; i < 4; ++i)
        key[i] = w[i];
    AddRoundKey(in, key);
}

/**
 *  encryption
 */
void optimisedEncrypt(byte in[4 * 4], word w[4 * (Nr + 1)])
{
    word key[4];
    for (int i = 0; i < 4; ++i)
        key[i] = w[i];
    AddRoundKey(in, key);

    for (int round = 1; round < Nr; ++round)
    {
        SubBytes(in);
        ShiftRows(in);
        optimisedMixColumns(in);
        for (int i = 0; i < 4; ++i)
            key[i] = w[4 * round + i];
        AddRoundKey(in, key);
    }

    SubBytes(in);
    ShiftRows(in);
    for (int i = 0; i < 4; ++i)
        key[i] = w[4 * Nr + i];
    AddRoundKey(in, key);
}

/**
 *  Decrypt
 */
void optimisedDecrypt(byte in[4 * 4], word w[4 * (Nr + 1)])
{
    word key[4];
    for (int i = 0; i < 4; ++i)
        key[i] = w[4 * Nr + i];
    AddRoundKey(in, key);

    for (int round = Nr - 1; round > 0; --round)
    {
        InvShiftRows(in);
        InvSubBytes(in);
        for (int i = 0; i < 4; ++i)
            key[i] = w[4 * round + i];
        AddRoundKey(in, key);
        optimisedInvMixColumns(in);
    }

    InvShiftRows(in);
    InvSubBytes(in);
    for (int i = 0; i < 4; ++i)
        key[i] = w[i];
    AddRoundKey(in, key);
}

/**********************************************************************/
/*                                                                    */
/*                              Testing*/
/*                                                                    */
/**********************************************************************/

void aes(byte plain[16])
{
    struct timeval start, end;
    // start timer.
    gettimeofday(&start, NULL);
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    byte key[16] = {0x2b, 0x7e, 0x15, 0x16,
                    0x28, 0xae, 0xd2, 0xa6,
                    0xab, 0xf7, 0x15, 0x88,
                    0x09, 0xcf, 0x4f, 0x3c};

    word w[4 * (Nr + 1)];
    KeyExpansion(key, w);

    // Encryption, output ciphertext
    normalEncrypt(plain, w);
}

double normalAES(byte key[16], byte plain[16])
{
    struct timeval start, end;
    double totalTime = 0;

    gettimeofday(&start, NULL);
    word w[4 * (Nr + 1)];
    KeyExpansion(key, w);

    // Encryption, output ciphertext
    // cout << endl
    //      << "Plaintext to be encrypted:" << endl;
    // for (int i = 0; i < 16; ++i)
    // {
    //     cout << hex << plain[i].to_ulong() << " ";
    //     if ((i + 1) % 4 == 0)
    //         cout << endl;
    // }
    // cout << endl;
    normalEncrypt(plain, w);
    // cout << "Encrypted ciphertext:" << endl;
    // for (int i = 0; i < 16; ++i)
    // {
    //     cout << hex << plain[i].to_ulong() << " ";
    //     if ((i + 1) % 4 == 0)
    //         cout << endl;
    // }
    // cout << endl;

    // Decrypt, output plaintext
    normalDecrypt(plain, w);

    // cout << "Encrypted ciphertext:" << endl;
    // for (int i = 0; i < 16; ++i)
    // {
    //     cout << hex << plain[i].to_ulong() << " ";
    //     if ((i + 1) % 4 == 0)
    //         cout << endl;
    // }
    // cout << endl;

    gettimeofday(&end, NULL);
    double time_taken;

    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec -
                                start.tv_usec)) *
                 1e-6;
    return time_taken;
}

double optimisedAES(byte key[16], byte plain[16])
{
    struct timeval start, end;
    double totalTime = 0;
    gettimeofday(&start, NULL);
    word w[4 * (Nr + 1)];
    KeyExpansionFibonacci(key, w);

    // Encryption, output ciphertext
    // cout << endl
    //      << "Plaintext to be encrypted:" << endl;
    // for (int i = 0; i < 16; ++i)
    // {
    //     cout << hex << plain[i].to_ulong() << " ";
    //     if ((i + 1) % 4 == 0)
    //         cout << endl;
    // }
    // cout << endl;
    optimisedEncrypt(plain, w);
    // cout << "Encrypted ciphertext:" << endl;
    // for (int i = 0; i < 16; ++i)
    // {
    //     cout << hex << plain[i].to_ulong() << " ";
    //     if ((i + 1) % 4 == 0)
    //         cout << endl;
    // }
    // cout << endl;

    // Decrypt, output plaintext
    optimisedDecrypt(plain, w);
    // cout << "Decrypted plaintext:" << endl;
    // for (int i = 0; i < 16; ++i)
    // {
    //     cout << hex << plain[i].to_ulong() << " ";
    //     if ((i + 1) % 4 == 0)
    //         cout << endl;
    // }
    // cout << endl;

    gettimeofday(&end, NULL);
    double time_taken;

    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec -
                                start.tv_usec)) *
                 1e-6;
    return time_taken;
}

// DES Integration

bitset<64> key;
bitset<48> subKey[16];

int IP[] = {58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6,
            64, 56, 48, 40, 32, 24, 16, 8,
            57, 49, 41, 33, 25, 17, 9, 1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7};

int IP_1[] = {40, 8, 48, 16, 56, 24, 64, 32,
              39, 7, 47, 15, 55, 23, 63, 31,
              38, 6, 46, 14, 54, 22, 62, 30,
              37, 5, 45, 13, 53, 21, 61, 29,
              36, 4, 44, 12, 52, 20, 60, 28,
              35, 3, 43, 11, 51, 19, 59, 27,
              34, 2, 42, 10, 50, 18, 58, 26,
              33, 1, 41, 9, 49, 17, 57, 25};

int PC_1[] = {57, 49, 41, 33, 25, 17, 9,
              1, 58, 50, 42, 34, 26, 18,
              10, 2, 59, 51, 43, 35, 27,
              19, 11, 3, 60, 52, 44, 36,
              63, 55, 47, 39, 31, 23, 15,
              7, 62, 54, 46, 38, 30, 22,
              14, 6, 61, 53, 45, 37, 29,
              21, 13, 5, 28, 20, 12, 4};

int PC_2[] = {14, 17, 11, 24, 1, 5,
              3, 28, 15, 6, 21, 10,
              23, 19, 12, 4, 26, 8,
              16, 7, 27, 20, 13, 2,
              41, 52, 31, 37, 47, 55,
              30, 40, 51, 45, 33, 48,
              44, 49, 39, 56, 34, 53,
              46, 42, 50, 36, 29, 32};

int shiftBits[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int E[] = {32, 1, 2, 3, 4, 5,
           4, 5, 6, 7, 8, 9,
           8, 9, 10, 11, 12, 13,
           12, 13, 14, 15, 16, 17,
           16, 17, 18, 19, 20, 21,
           20, 21, 22, 23, 24, 25,
           24, 25, 26, 27, 28, 29,
           28, 29, 30, 31, 32, 1};

int S_BOX[8][4][16] = {
    {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
     {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
     {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
     {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},
    {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
     {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
     {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
     {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},
    {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
     {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
     {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
     {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},
    {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
     {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
     {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
     {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},
    {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
     {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
     {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
     {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},
    {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
     {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
     {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
     {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},
    {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
     {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
     {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
     {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},
    {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
     {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
     {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
     {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}};

int P[] = {16, 7, 20, 21,
           29, 12, 28, 17,
           1, 15, 23, 26,
           5, 18, 31, 10,
           2, 8, 24, 14,
           32, 27, 3, 9,
           19, 13, 30, 6,
           22, 11, 4, 25};

bitset<32> f(bitset<32> R, bitset<48> k)
{
    bitset<48> expandR;
    for (int i = 0; i < 48; ++i)
        expandR[47 - i] = R[32 - E[i]];
    expandR = expandR ^ k;
    bitset<32> output;
    int x = 0;
    for (int i = 0; i < 48; i = i + 6)
    {
        int row = expandR[47 - i] * 2 + expandR[47 - i - 5];
        int col = expandR[47 - i - 1] * 8 + expandR[47 - i - 2] * 4 + expandR[47 - i - 3] * 2 + expandR[47 - i - 4];
        int num = S_BOX[i / 6][row][col];
        bitset<4> binary(num);
        output[31 - x] = binary[3];
        output[31 - x - 1] = binary[2];
        output[31 - x - 2] = binary[1];
        output[31 - x - 3] = binary[0];
        x += 4;
    }
    bitset<32> tmp = output;
    for (int i = 0; i < 32; ++i)
        output[31 - i] = tmp[32 - P[i]];
    return output;
}

bitset<28> leftShift(bitset<28> k, int shift)
{
    bitset<28> tmp = k;
    for (int i = 27; i >= 0; --i)
    {
        if (i - shift < 0)
            k[i] = tmp[i - shift + 28];
        else
            k[i] = tmp[i - shift];
    }
    return k;
}

void generateKeys()
{
    bitset<56> realKey;
    bitset<28> left;
    bitset<28> right;
    bitset<48> compressKey;
    for (int i = 0; i < 56; ++i)
        realKey[55 - i] = key[64 - PC_1[i]];
    for (int round = 0; round < 16; ++round)
    {
        for (int i = 28; i < 56; ++i)
            left[i - 28] = realKey[i];
        for (int i = 0; i < 28; ++i)
            right[i] = realKey[i];
        left = leftShift(left, shiftBits[round]);
        right = leftShift(right, shiftBits[round]);
        for (int i = 28; i < 56; ++i)
            realKey[i] = left[i - 28];
        for (int i = 0; i < 28; ++i)
            realKey[i] = right[i];
        for (int i = 0; i < 48; ++i)
            compressKey[47 - i] = realKey[56 - PC_2[i]];
        subKey[round] = compressKey;
    }
}

bitset<64> charToBitset(const char s[8])
{
    bitset<64> bits;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            bits[i * 8 + j] = ((s[i] >> j) & 1);
    return bits;
}

string BitsetTostring(bitset<64> bit)
{
    string res;
    for (int i = 0; i < 8; ++i)
    {
        char c = 0x00;
        for (int j = 7; j >= 0; j--)
        {
            c = c + bit[i * 8 + j];
            if (j != 0)
                c = c * 2; // left shift
        }
        res.push_back(c);
    }
    return res;
}
/**
 *  DES加密
 */
bitset<64> encrypt(bitset<64> &plain)
{
    bitset<64> cipher;
    bitset<64> currentBits;
    bitset<32> left;
    bitset<32> right;
    bitset<32> newLeft;
    for (int i = 0; i < 64; ++i)
        currentBits[63 - i] = plain[64 - IP[i]];
    for (int i = 32; i < 64; ++i)
        left[i - 32] = currentBits[i];
    for (int i = 0; i < 32; ++i)
        right[i] = currentBits[i];
    for (int round = 0; round < 16; ++round)
    {
        newLeft = right;
        right = left ^ f(right, subKey[round]);
        left = newLeft;
    }
    for (int i = 0; i < 32; ++i)
        cipher[i] = left[i];
    for (int i = 32; i < 64; ++i)
        cipher[i] = right[i - 32];
    currentBits = cipher;
    for (int i = 0; i < 64; ++i)
        cipher[63 - i] = currentBits[64 - IP_1[i]];
    return cipher;
}

/**
 *  DES解密
 */
bitset<64> decrypt(bitset<64> &cipher)
{
    bitset<64> plain;
    bitset<64> currentBits;
    bitset<32> left;
    bitset<32> right;
    bitset<32> newLeft;
    for (int i = 0; i < 64; ++i)
        currentBits[63 - i] = cipher[64 - IP[i]];
    for (int i = 32; i < 64; ++i)
        left[i - 32] = currentBits[i];
    for (int i = 0; i < 32; ++i)
        right[i] = currentBits[i];
    for (int round = 0; round < 16; ++round)
    {
        newLeft = right;
        right = left ^ f(right, subKey[15 - round]);
        left = newLeft;
    }
    for (int i = 0; i < 32; ++i)
        plain[i] = left[i];
    for (int i = 32; i < 64; ++i)
        plain[i] = right[i - 32];
    currentBits = plain;
    for (int i = 0; i < 64; ++i)
        plain[63 - i] = currentBits[64 - IP_1[i]];
    return plain;
}

double DES(byte largeKey[16], byte largePlain[16])
{
    struct timeval start, end;
    double totalTime = 0;
    gettimeofday(&start, NULL);

    bitset<64> plain = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            plain[i * 8 + j] = largePlain[i][j];
        }
    }
    generateKeys();
    bitset<64> cipher = encrypt(plain);
    bitset<64> temp_plain = decrypt(cipher);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            plain[i * 8 + j] = largePlain[i + 8][j];
        }
    }
    generateKeys();
    cipher = encrypt(plain);
    temp_plain = decrypt(cipher);
    gettimeofday(&end, NULL);
    double time_taken;

    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec -
                                start.tv_usec)) *
                 1e-6;
    return time_taken;
}

int main()
{
    byte key[16] = {0x2b, 0x7e, 0x15, 0x16,
                    0x28, 0xae, 0xd2, 0xa6,
                    0xab, 0xf7, 0x15, 0x88,
                    0x09, 0xcf, 0x4f, 0x3c};

    byte plain[16] = {0x32, 0x88, 0x31, 0xe0,
                      0x43, 0x5a, 0x31, 0x37,
                      0xf6, 0x30, 0x98, 0x07,
                      0xa8, 0x8d, 0xa2, 0x34};

    byte referenceOutput[16];
    memcpy(referenceOutput, plain, sizeof(plain));
    aes(referenceOutput);

    int totalChanges = 0;

    // Iterate through each bit position (0 to 7)
    for (size_t bitPos = 0; bitPos < 8; ++bitPos)
    {
        int bitChanges = 0;

        // Iterate through each element in the plain array
        for (size_t i = 0; i < 16; ++i)
        {
            // Create a modified input by flipping the bit at bitPos
            byte temp[16];
            memcpy(temp, plain, sizeof(plain));
            temp[i][bitPos] = !temp[i][bitPos];

            aes(temp);

            // Calculate the Hamming distance between reference and modified outputs
            int changes = (referenceOutput[i] ^ temp[i]).count();
            bitChanges += changes;

            temp[i][bitPos] = !temp[i][bitPos];
        }

        totalChanges += bitChanges;

        cout << "Bit " << bitPos << ": " << bitChanges << " bits change." << endl;
    }

    double avalancheEffect = static_cast<double>(totalChanges) / (8 * 8 * 16);
    cout << "Avalanche Effect: " << avalancheEffect << endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 127);
    int noOfTestCases = 500;
    double normalAESTime = 0, DESTime = 0, optimisedAESTime = 0;
    for (int i = 0; i < noOfTestCases; i++)
    {
        for (int i = 0; i < 16; i++)
        {
            key[i] = distribution(gen);
            plain[i] = distribution(gen);
        }
        normalAESTime += normalAES(key, plain);
        DESTime += DES(key, plain);
        optimisedAESTime += optimisedAES(key, plain);
    }
    cout << "Original AES Time: " << (normalAESTime / noOfTestCases) << endl;
    cout << "DES Time: " << (DESTime / noOfTestCases) << endl;
    cout << "Optimised AES Time: " << (optimisedAESTime / noOfTestCases) << endl;
    return 0;
}
