//
//  listtoko.h
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#ifndef LISTTOKO_H
#define LISTTOKO_H

#include "toko.h"

struct ListToko {
    addressToko first;
};

void createListToko(ListToko &L);
addressToko buatElmToko(infotypeToko x);
void insertToko(ListToko &L, addressToko P);
void deleteToko(ListToko &L, std::string id);
addressToko findToko(ListToko L, std::string id);

#endif
