//
//  oui.cpp
//
//  IEEE Organizationally unique identifiers
//  see https://en.wikipedia.org/wiki/Organizationally_unique_identifier
//
//  Created by Scott Marks on 09/10/2017.
//
//

#include "oui.hpp"

typedef
struct _data_pair{
    CString hex_of_oui;
    CString manufacturer;
} data_pair;
static data_pair data[]={
#define __hex__(oui) #oui
#include "oui.inc"
#undef __hex__
};


#if defined(__clang__)
[[clang::no_destroy]]
#elif defined(__GNUC__)
[[no_destroy]]
#endif
const CString_Lookup_Table manufacturer_for_oui =
    make_table(reinterpret_cast<CStringKeyValuePair *>(data), sizeof(data)/sizeof(data[0]));
#if defined(__clang__)
[[clang::no_destroy]]
#elif defined(__GNUC__)
[[no_destroy]]
#endif
const CString_Lookup_Table oui_for_manufacturer =
    make_inverse_table(reinterpret_cast<CStringKeyValuePair *>(data), sizeof(data)/sizeof(data[0]));
