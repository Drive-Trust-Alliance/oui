//
//  oui_vendor.hpp
//  oui
//
//  Created by Scott Marks on 11/30/22.
//

#ifndef oui_vendor_hpp
#define oui_vendor_hpp

#include "oui.hpp"
#include "t10_vendorid.hpp"

extern "C" const char * vendorID_for_manufacturer_canonically_if_necessary(const char * manufacturer);
extern "C" const char * vendorID_for_oui_canonically_if_necessary(const char * oui);
extern "C" const char * oui_for_vendor_canonically_if_necessary(const char * vendor) ;
extern "C" const char * oui_for_vendorID_canonically_if_necessary(const char * vendorID) ;

#endif /* oui_vendor_hpp */
