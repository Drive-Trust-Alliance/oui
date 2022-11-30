//
//  oui_vendor.cpp
//  oui
//
//  Created by Scott Marks on 11/30/22.
//

#include "oui_vendor.hpp"

const char * vendorID_for_manufacturer_canonically_if_necessary(const char * manufacturer) {
    for (CString_Lookup_Table::const_iterator pVendorID = vendorID_for_vendor.find(manufacturer);
         pVendorID != vendorID_for_vendor.end(); ) {
            return pVendorID->second;
    }
    
    for (CString_Canonical_Lookup_Table::const_iterator pVendorID = vendorID_for_vendor_canonically.find(manufacturer);
         pVendorID != vendorID_for_vendor_canonically.end(); ) {
            return pVendorID->second;
    }
    
    return NULL;
}

const char * vendorID_for_oui_canonically_if_necessary(const char * oui) {
    CString_Lookup_Table::const_iterator pManufacturer = manufacturer_for_oui.find(oui);
    return pManufacturer == manufacturer_for_oui.end()
        ? NULL
        : vendorID_for_manufacturer_canonically_if_necessary(pManufacturer->second);
}

const char * oui_for_vendor_canonically_if_necessary(const char * vendor) {
    for (CString_Lookup_Table::const_iterator
         poui = oui_for_manufacturer.find(vendor);
         poui != oui_for_manufacturer.end(); ) {
        return poui->second;
    }
    
    for (CString_Canonical_Lookup_Table::const_iterator
         poui = oui_for_manufacturer_canonically.find(vendor);
         poui != oui_for_manufacturer_canonically.end(); ) {
        return poui->second;
    }
    
    return NULL;
}

const char * oui_for_vendorID_canonically_if_necessary(const char * vendorID) {
    CString_Lookup_Table::const_iterator pVendor = vendor_for_vendorID.find(vendorID);
    return pVendor == vendor_for_vendorID.end()
        ? NULL
        : oui_for_vendor_canonically_if_necessary(pVendor->second);
}

