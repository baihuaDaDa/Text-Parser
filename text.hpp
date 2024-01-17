#ifndef TEXT_TEXT_HPP
#define TEXT_TEXT_HPP

#include <iostream>
#include <bitset>

class Text {
protected:
    std::string binary_str;
    size_t len;
    size_t index;
    size_t cnt;
    bool valid;

public:
    Text(const std::string &);

    virtual ~Text();

    size_t GetLen() const;

    size_t GetSize() const;

    bool IfValid() const;

    void SetIndex(size_t);

    virtual bool ReadSingleChar(std::string &, unsigned long long &) = 0;

};

class UtfText : public Text {
public:
    UtfText(const std::string &);
    ~UtfText() override;
    bool ReadSingleChar(std::string &, unsigned long long &) override;

private:
    size_t GetUtfLen(const char);

};

class GbkText : public Text {
public:
    GbkText(const std::string &);
    ~GbkText() override;
    bool ReadSingleChar(std::string &, unsigned long long &) override;
};

#endif //TEXT_TEXT_HPP
