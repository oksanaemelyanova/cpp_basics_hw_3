#include "hw3.hpp"

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

int task1() {
  s_book    book1;  
  read_from_the_file(&book1);
  
  write_to_the_file(&book1);  
  
  free_address_storage(&book1);
 
  return (0);
}