//MACAddressUtility by Volodymyr (T-Rex) Triapichko.
//This file is NOT a part of 39dylib, however, 39dylib depends on it. 

#ifndef _MACADDRESS_UTILITY_H
#define _MACADDRESS_UTILITY_H

class MACAddressUtility
{
public:
    static long GetMACAddress(unsigned char * result);
private:
#if defined(WIN32) || defined(UNDER_CE)
    static long GetMACAddressMSW(unsigned char * result);
#elif defined(__APPLE__)
    static long GetMACAddressMAC(unsigned char * result);
#elif defined(LINUX) || defined(linux)
    static long GetMACAddressLinux(unsigned char * result);
#endif
};

#endif