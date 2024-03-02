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


void write_to_the_file(s_book *book1){ 
  std::ofstream outfile("out.txt");

  if (!outfile.is_open()){
    std::cerr << "Error opening the file!" << std::endl;
    return ;
  }
  outfile << book1->address_counter << "\n";
  int i = book1->address_counter * 4 - 1;
  for (int j = 0; j < book1->address_counter; j++){
    address   adr(std::string(book1->all_addresses[i - 3]),             std::string(book1->all_addresses[i - 2]), atoi(book1->all_addresses[i - 1]), atoi(book1->all_addresses[i]));

    outfile << adr.get_output_addresses(book1) << "\n";
    i -= 4;
  }
  outfile.close();
}


void  read_from_the_file(s_book *book1){
  std::string line;  

  std::ifstream infile("in.txt");
  if (!infile.is_open()) {
    std::cerr << "Error opening the file!" << std::endl;
    return ;
  }  
  
  infile >> book1->address_counter;
  book1->all_addresses = new char*[book1->address_counter * 4];

  for (int i = 0; i < book1->address_counter * 4; i++){
    infile >> line;
    book1->all_addresses[i] = new char[line.length() + 1];
    strcpy(book1->all_addresses[i], line.c_str());
  }
  infile.close();
 }



void free_address_storage(s_book *book1)
{
  for (int i = 0; i < book1->address_counter * 4; i++){
    delete[] book1->all_addresses[i];
  }
  delete[] book1->all_addresses;
}

int main() {
  s_book    book1;  
  read_from_the_file(&book1);
  
  write_to_the_file(&book1);
  
  
  free_address_storage(&book1);
 
  return (0);
}