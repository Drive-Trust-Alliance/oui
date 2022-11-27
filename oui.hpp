//
//  oui.hpp
//
//  IEEE Organizationally unique identifiers
//  see https://en.wikipedia.org/wiki/Organizationally_unique_identifier
//
//  Created by Scott Marks on 09/10/2017.
//
//

#ifndef oui_hpp
#define oui_hpp

#include <oui/CStringMap.hpp>

extern "C" const CString_Lookup_Table manufacturer_for_oui;
extern "C" const CString_Lookup_Table oui_for_manufacturer;

#endif /* oui_hpp */
