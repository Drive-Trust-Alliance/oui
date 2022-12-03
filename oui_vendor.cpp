//
//  oui_vendor.cpp
//  oui
//
//  Created by Scott Marks on 11/30/22.
//

#include "oui_vendor.hpp"

const char * manufacturer_for_oui(const char * oui) {
    CString_Lookup_Table::const_iterator pManufacturer = manufacturer_for_oui_table.find(oui);
    return pManufacturer == manufacturer_for_oui_table.end()
        ? NULL
        : pManufacturer->second;
}

const char * vendorID_for_vendor(const char * vendor) {
    for (CString_Lookup_Table::const_iterator pVendorID = vendorID_for_vendor_table.find(vendor);
         pVendorID != vendorID_for_vendor_table.end(); ) {
            return pVendorID->second;
    }
    return NULL;
}


const char * vendorID_for_vendor_canonically(const char * vendor) {
    for (CString_Lookup_Table::const_iterator pVendorID = vendorID_for_vendor_canonically_table.find(vendor);
         pVendorID != vendorID_for_vendor_canonically_table.end(); ) {
            return pVendorID->second;
    }
    return NULL;
}

const char * vendorID_for_vendor_canonically_if_necessary(const char * vendor) {
    const char * vendorID;
    if (NULL != (vendorID = vendorID_for_vendor(vendor)))
        return vendorID;
    if (NULL != (vendorID = vendorID_for_vendor_canonically(vendor)))
        return vendorID;
    return NULL;
}

const char * vendor_for_vendorID(const char * vendorID) {
    for (CString_Lookup_Table::const_iterator pVendor = vendor_for_vendorID_table.find(vendorID);
         pVendor != vendor_for_vendorID_table.end(); ) {
            return pVendor->second;
    }
    return NULL;
}

const char * vendor_for_vendorID_canonically(const char * vendorID) {
    for (CString_Lookup_Table::const_iterator pVendor = vendor_for_vendorID_canonically_table.find(vendorID);
         pVendor != vendor_for_vendorID_canonically_table.end(); ) {
            return pVendor->second;
    }
    return NULL;
}

const char * vendor_for_vendorID_canonically_if_necessary(const char * vendorID) {
    const char * vendor;
    if (NULL != (vendor = vendor_for_vendorID(vendorID)))
        return vendor;
    if (NULL != (vendor = vendor_for_vendorID_canonically(vendorID)))
        return vendor;
    return NULL;
}

const char * vendorID_for_oui_canonically_if_necessary(const char * oui) {
    const char * manufacturer = manufacturer_for_oui(oui);
    return manufacturer == NULL ? NULL : vendorID_for_vendor_canonically_if_necessary(manufacturer);
}

const char * oui_for_vendor_canonically_if_necessary(const char * vendor) {
    for (CString_Lookup_Table::const_iterator
         poui = oui_for_manufacturer_table.find(vendor);
         poui != oui_for_manufacturer_table.end(); ) {
        return poui->second;
    }
    
    for (CString_Canonical_Lookup_Table::const_iterator
         poui = oui_for_manufacturer_canonically_table.find(vendor);
         poui != oui_for_manufacturer_canonically_table.end(); ) {
        return poui->second;
    }
    
    return NULL;
}

const char * oui_for_vendorID_canonically_if_necessary(const char * vendorID) {
    const char * vendor=vendor_for_vendorID(vendorID);
    return vendor == NULL ? NULL : oui_for_vendor_canonically_if_necessary(vendor);
}

