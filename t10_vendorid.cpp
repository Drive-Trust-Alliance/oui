//
//  t10_vendorid.cpp
//
//  T10 registered vendor
//  see https://www.t10.org/vendorid.txt
//
//  Created by Scott Marks on 10/10/2022.
//
//

#include "t10_vendorid.hpp"
typedef
struct _data_pair{
    CString vendorid;
    CString vendor;
} data_pair;
static data_pair data[]={
#include "t10_vendorid.inc"
};


#if defined(__clang__)
[[clang::no_destroy]]
#elif defined(__GNUC__)
[[no_destroy]]
#endif
const CString_Lookup_Table vendor_for_vendorID =
    make_table(reinterpret_cast<CStringKeyValuePair *>(data), sizeof(data)/sizeof(data[0]));

#if defined(__clang__)
[[clang::no_destroy]]
#elif defined(__GNUC__)
[[no_destroy]]
#endif
const CString_Lookup_Table vendorID_for_vendor =
    make_inverse_table(reinterpret_cast<CStringKeyValuePair *>(data), sizeof(data)/sizeof(data[0]));

#if defined(__clang__)
[[clang::no_destroy]]
#elif defined(__GNUC__)
[[no_destroy]]
#endif
const CString_Canonical_Lookup_Table vendorID_for_vendor_canonically =
    make_canonical_inverse_table(reinterpret_cast<CStringKeyValuePair *>(data), sizeof(data)/sizeof(data[0]));
