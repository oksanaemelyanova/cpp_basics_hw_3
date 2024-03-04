#include "hw3.hpp"

void free_address_storage(s_book *book1)
{
  for (int i = 0; i < book1->address_counter * 4; i++){
    delete[] book1->all_addresses[i];
  }
  delete[] book1->all_addresses;
}