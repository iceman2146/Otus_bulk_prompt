#include <iostream>
#include <vector>
#include <string>


void print_bulk_cmd(std::ostream& out, const std::vector<std::string>& commands)
{
    if (commands.empty())
        return;

    out<< "bulk:";

    for (const auto &i : commands)
    {
        out <<i;
        if(commands[commands.size()-1]!=i)
            out<<',';
        
    }
}

int main(int argc, char *argv[])
{

        std::string command;
        std::vector<std::string> commands_block;

        
        while(std::getline(std::cin, command))
        {
            if (command == "{")
            {
                
                    print_bulk_cmd(std::cout, commands_block);
                    commands_block.clear();
                
            }
            else if (command == "}")
            {
                
                    print_bulk_cmd(std::cout, commands_block);
                    commands_block.clear();
                
            }
            else
            {
                commands_block.push_back(command);
            }
        }

    
    print_bulk_cmd(std::cout, commands_block);
    
  

    return 0;
}