#include "text.hpp"

int main() {
    std::string str;
    std::cin >> str;
    Text *text = new UtfText(str);
    std::string parsed_line;
    while (text->ReadSingleChar(parsed_line)) {
        std::cout << parsed_line;
    }
    return 0;
}
