#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

void print_bulk_cmd(std::ostream &out,
                    const std::vector<std::string> &commands) {
  if (commands.empty())
    return;

  out << "bulk:";

  for (const auto &i : commands) {
    out << i;
    if (commands[commands.size() - 1] != i)
      out << ',';
  }
}

int main(int argc, char *argv[]) {

  std::string command;
  size_t counter = 0;

  std::vector<std::string> commands_block;
  if(true)
{
  //throw std::runtime_error{ "I'd be glad to make an exception." };
}
  while (std::getline(std::cin, command)) {
    if (command == "{") {
      if (counter == 0) {
        print_bulk_cmd(std::cout, commands_block);
        commands_block.clear();
      }
      counter++;

    } else if (command == "}") {
      counter--;
      {
        print_bulk_cmd(std::cout, commands_block);
        commands_block.clear();
      }

    } else {
      commands_block.push_back(command);
    }
  }

  print_bulk_cmd(std::cout, commands_block);

  return 0;
}