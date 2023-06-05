
#include <iostream>
#include <map>
#include <string>
#include <string_view>

void
print_map
(std::string_view comment, const std::map<std::string, int>& m)
{
  std::cout << comment;
 
  for (const auto& n : m)
    std::cout << n.first << " = " << n.second << "; ";

  std::cout << '\n';
}
 
int main()
{
  // Create a map of three (string, int) pairs
  std::map<std::string, int> m{{"HW0", 10}, {"HW2", 15}, {"HW3", 20}};
  print_map("1) Initial map: \n", m);
 
  m["HW0"] = 25; // update an existing value
  m["HW4"] = 30; // insert a new value
  print_map("2) Updated map (add 0 and 4): \n", m);
 
  // using operator[] with non-existent key always performs an insert
  std::cout << "3) m[HW7] = " << m["HW7"] << '\n';
  print_map("4) Updated map (check 7): \n", m);

  // ecs36b ==> next three lines are to identify particupar elements
  
  // std::map<std::string, int>::iterator it = m.lower_bound("HW2");
  // std::cout << it->first << std::endl;
  // std::cout << it->second << std::endl;

  // question: what is the type of the value attribute in std::map
  m.erase("HW2");
  print_map("5) After erase 2: \n", m);
 
  std::cout << "6) m.size() = \n" << m.size() << '\n';
  
  m.clear();
  std::cout << std::boolalpha << "7) Map is empty: \n" << m.empty() << '\n';
}
