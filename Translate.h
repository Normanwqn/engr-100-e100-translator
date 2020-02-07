//
// Created by Norman Qining Wen on 7/2/2020.
//

#ifndef TRANSLATOR_TRANSLATE_H
#define TRANSLATOR_TRANSLATE_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Command.h"

enum opcode: char{
    HALT = 0,
    ADD,
    SUB,
    MULT,
    DIV,
    CP,
    AND,
    OR,
    NOT,
    SL,
    SR,
    CPFA,
    CPTA,
    BE,
    BNE,
    BLT,
    CALL,
    RET
};

class Translate {
public:
    char count = 0;
    explicit Translate(std::istream* read);
private:
    int lineCount = 0;
    static constexpr char endNote[] = "];\n";
    //std::vector<Command> commands;
    enum mode: bool{

    };
    std::string memoryWrapper(const std::string& arg);
    std::string twoOpTemp(const std::string& arg1,
                          const std::string& arg2, const std::string& arg3, char opchar);

    std::string twoOpTemp(const std::string& arg1,
                          const std::string& arg2, const std::string& arg3, const std::string &opchar);

    std::string oneOptemp(const std::string& target, const std::string& source);
    //Building an If function
    std::string buildIf(const std::string& arg1, const std::string& arg2, const std::string& arg3,
                        const std::string& compareType);

    void processBlock(opcode op,
            const std::string& arg1, const std::string& arg2, const std::string& arg3);
};


#endif //TRANSLATOR_TRANSLATE_H
