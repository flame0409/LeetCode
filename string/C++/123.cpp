// ofsub.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

typedef          char    int8;
typedef   signed char    sint8;
typedef unsigned char    uint8;
typedef          short   int16;
typedef   signed short   sint16;
typedef unsigned short   uint16;
typedef          int     int32;
typedef   signed int     sint32;
typedef unsigned int     uint32;
typedef __int64          int64;
typedef __int64          sint64;
typedef unsigned __int64 uint64;

// sign flag
template<class T> int8 __SETS__(T x)
{
    if (sizeof(T) == 1)
        return int8(x) < 0;
    if (sizeof(T) == 2)
        return int16(x) < 0;
    if (sizeof(T) == 4)
        return int32(x) < 0;
    return int64(x) < 0;
}

// overflow flag of subtraction (x-y)
template<class T, class U> int8 __OFSUB__(T x, U y)
{
    if (sizeof(T) < sizeof(U))
    {
        U x2 = x;
        int8 sx = __SETS__(x2);
        return (sx ^ __SETS__(y)) & (sx ^ __SETS__(x2 - y));
    }
    else
    {
        T y2 = y;
        int8 sx = __SETS__(x);
        return (sx ^ __SETS__(y2)) & (sx ^ __SETS__(x - y2));
    }
}

int main()
{
    int res;
    unsigned char c1 = 0x80;
    unsigned char c2 = 0x01;
    res = __OFSUB__(c1, c2); // -128 - 1 溢出了
    cout << res << endl;
    
    
    int v10 = 0;
    unsigned __int8 v12;
    bool v11;
    do
    {
      cout<<v10<<" "<<v11<<"?"<<v12<<endl;
      v12 = __OFSUB__(v10, 30);                 // v10是否大于30，是返回1，否返回0
      v11 = v10 - 30 < 0;
      v10 += 2;
    }
    while ( v11 ^ v12 );  
    res = __OFSUB__(v10, 30); // -128 - 1 溢出了
    cout<<res;
}


