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
typedef struct _data_pair{const char *hex_of_oui; const char *manufacturer;} data_pair;
static data_pair data[]={
#define __hex__(oui) #oui
#include "oui.inc"
#undef __hex__
};

static
std::unordered_map<std::string,std::string>make_table() {
    std::unordered_map<std::string,std::string>t;
    for (data_pair *p=&data[0], *pend=&data[sizeof(data)/sizeof(data[0])]; p!=pend; p++)
        t[p->hex_of_oui]=p->manufacturer;
    t.reserve( t.size() );
    return t;
}

const std::unordered_map<std::string,std::string>manufacturer_for_oui=make_table();
