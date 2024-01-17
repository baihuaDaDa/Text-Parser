#include "text.hpp"
#include <iomanip>

int main() {
    std::string str;
    std::cin >> str;
    Text *text = new UtfText(str);
    std::string parsed_line;
    unsigned long long parsed_value;
    while (text->ReadSingleChar(parsed_line, parsed_value)) {
        if (text->IfValid()) {
            std::cout << parsed_line << ' ' << std::hex << parsed_value << std::endl;
        }
    }
    if (text->IfValid())
        std::cout << std::endl << text->GetSize() << std::endl;
    return 0;
}
