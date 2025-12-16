//
//  listtoko.h
//  tubes_strukturdata
//
//  Created by KHAIDIR MAULANA on 12/12/25.
//

#ifndef LISTTOKO_H
#define LISTTOKO_H

#include <string>
using namespace std;

struct infotypeToko {
    string idToko;
    string namaToko;
};

typedef struct elmToko *addressToko;

struct elmToko {
    infotypeToko info;
    addressToko next;
};

struct ListToko {
    addressToko first;
    int count;
};

void createListToko(ListToko &L);
addressToko buatElmToko(infotypeToko x);
void insertToko(ListToko &L, addressToko P);
addressToko findToko(ListToko L, string id);
void deleteToko(ListToko &L, string id);
void inputToko(infotypeToko &x);

#endif
