#include "hw3.hpp"

void write_to_the_file2(s_book *book1){ 
  std::ofstream outfile("out2.txt");

  if (!outfile.is_open()){
    std::cerr << "Error opening the file!" << std::endl;
    return ;
  }

  outfile << book1->address_counter << "\n";
  int i = 0;
  for (int j = 0; j < book1->address_counter; j++){
    address   adr(std::string(book1->all_addresses[i]),             std::string(book1->all_addresses[i + 1]), atoi(book1->all_addresses[i + 2]), atoi(book1->all_addresses[i + 3]));

    outfile << adr.get_output_addresses(book1) << "\n";
    i += 4;
  }
  outfile.close();
}


void  read_from_the_file2(s_book *book1){
  std::string line;  

  std::ifstream infile("in2.txt");
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

void sort_adr(s_book *book1){
  int sorted = 0;
  
  while (sorted == 0){
    sorted = 1;
    for(int i = 0; i < book1->address_counter * 4 - 4; i += 4){
      if (strcmp(book1->all_addresses[i], book1->all_addresses[i + 4]) > 0){
        sorted = 0;
        std::swap(book1->all_addresses[i], book1->all_addresses[i + 4]);
        std::swap(book1->all_addresses[i + 1], book1->all_addresses[i + 5]);
        std::swap(book1->all_addresses[i + 2], book1->all_addresses[i + 6]);
        std::swap(book1->all_addresses[i + 3], book1->all_addresses[i + 7]);
      }
    }
  }
}

int task2() {
  s_book    book1;

  read_from_the_file2(&book1);
  sort_adr(&book1);
  write_to_the_file2(&book1);
  free_address_storage(&book1); 

  return (0);
}