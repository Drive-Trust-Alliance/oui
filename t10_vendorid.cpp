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
    const char *vendorid;
    const char *vendor;
} data_pair;
static data_pair data[]={
#include "t10_vendorid.inc"
};

static
std::unordered_map<std::string,std::string>make_table() {
    std::unordered_map<std::string,std::string>t;
    for (data_pair *p=&data[0], *pend=&data[sizeof(data)/sizeof(data[0])]; p!=pend; p++)
        t[p->vendorid]=p->vendor;
    t.reserve( t.size() );
    return t;
}

#if defined(__clang__)
[[clang::no_destroy]]
#elif defined(__GNUC__)
[[no_destroy]]
#endif
const std::unordered_map<std::string // vendor id as registered
                        ,std::string // vendor
                        >vendor_for_vendorid=make_table();
