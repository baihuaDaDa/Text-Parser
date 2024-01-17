#include "text.hpp"

Text::~Text() = default;

Text::Text(const std::string &str) : binary_str(str), index(0), cnt(0), valid(true) {
    len = binary_str.size();
}

size_t Text::GetLen() const {
    return len;
}

void Text::SetIndex(size_t _index) {
    index = _index;
}

size_t Text::GetSize() const {
    return cnt;
}

bool Text::IfValid() const {
    return valid;
}

UtfText::UtfText(const std::string &str) : Text(str) {}

bool UtfText::ReadSingleChar(std::string &parsed_line, unsigned long long &parsed_value) {
    if (index == len) return false;
    size_t _len = GetUtfLen(binary_str[index]);
    if (_len == 0 && _len + index > index) {
        valid = false;
        return false;
    }
    parsed_line = binary_str.substr(index, _len);
    parsed_value = std::bitset<8>(parsed_line[0] & (0xff >> (_len + 1))).to_ullong();
    for (size_t i = 1; i < _len; i++) {
        parsed_value = (parsed_value << 6) + std::bitset<6>(parsed_line[i]).to_ullong();
    }
    index += _len;
    cnt++;
    return true;
}

size_t UtfText::GetUtfLen(const char head_byte) {
    unsigned char mask = 0x80;
    size_t _len = 0;
    while (head_byte & mask) {
        _len++;
        if (_len > 3) return 0;
        mask >>= 1;
    }
    if (_len == 0) _len = 1;
    return _len;
}

UtfText::~UtfText() = default;

