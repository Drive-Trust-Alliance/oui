//
//  t10_vendorid.hpp
//
//  T10 registered vendor
//  see https://www.t10.org/vendorid.txt
//
//  Created by Scott Marks on 10/10/2022.
//
//

#ifndef t10_vendorid_hpp
#define t10_vendorid_hpp

#include <oui/CStringMap.hpp>

extern const CString_Lookup_Table vendor_for_vendorID;
extern const CString_Lookup_Table vendorID_for_vendor;

#endif /* t10_vendorid_hpp */
