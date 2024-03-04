#ifndef HW3_H
# define HW3_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

struct  s_book{
  int address_counter = 0;
  char **all_addresses;
  std::string output_address;
};

class address{
private:
  std::string city;
  std::string street;
  int house;
  int apartment;

public:  
  address(std::string city, std::string street, int house, int apartment) {
    this->apartment = apartment;
    this->city = city;
    this->house = house;
    this->street = street;
  };

  std::string get_output_addresses(s_book *book1){
    std::string  address_string;

    address_string += city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    return address_string;
  }
};

int task1();
int task2();
void free_address_storage(s_book *book1);

#endif