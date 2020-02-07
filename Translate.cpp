//
// Created by Norman Qining Wen on 7/2/2020.
//

#include "Translate.h"
std::string Translate::memoryWrapper(const std::string& arg){
    return std::string ("memory[" + arg + "]");
}
std::string Translate::twoOpTemp(const std::string& arg1,
                      const std::string& arg2, const std::string& arg3, char opchar){
    lineCount ++;
    return std::string (memoryWrapper(arg1) + " = " + memoryWrapper(arg2) + opchar +";\n");
}
std::string Translate::twoOpTemp(const std::string& arg1,
                      const std::string& arg2, const std::string& arg3, const std::string &opchar){
    lineCount ++;
    return std::string (memoryWrapper(arg1) + " = " + memoryWrapper(arg2) + opchar +";\n");
}
std::string Translate::oneOptemp(const std::string& target, const std::string& source){
    lineCount ++;
    return (std::string(memoryWrapper(target) + " = " + memoryWrapper(source) + ";\n"));
}
std::string Translate::buildIf(const std::string& arg1, const std::string& arg2, const std::string& arg3,
                    const std::string& compareType){

}


Translate::Translate(std::istream* read){

}
//Given a 4 lines, process
//
void Translate::processBlock(opcode op,
        const std::string &arg1, const std::string &arg2, const std::string &arg3) {
    char in;
    opcode code;
    std::string line;
    code = static_cast<opcode> (in);
    switch (op) {
        case HALT:
            line = "return 0;";
            break;
        case ADD:
            line = twoOpTemp(arg1, arg2, arg3, '+');
            break;
        case SUB:
            line = twoOpTemp(arg1, arg2, arg3, '-');
            break;
        case MULT:
            line = twoOpTemp(arg1, arg2, arg3, '*');
            break;
        case DIV:
            line = twoOpTemp(arg1, arg2, arg3, '/');
            break;
        case CP:
            line = oneOptemp(arg1, arg2);
            break;
        case AND:
            line = twoOpTemp(arg1, arg2, arg3, '&');
            break;
        case OR:
            line = twoOpTemp(arg1, arg2, arg3, '|');
        case NOT:
            line.append(memoryWrapper(arg1));
            line.append("~");
            line.append(memoryWrapper(arg2));
            line.append(endNote);
            break;
        case SL:
            line = twoOpTemp(arg1, arg2, arg3, "<<");
            break;
        case SR:
            line = twoOpTemp(arg1, arg2, arg3, ">>");
            break;
        case CPFA:
            line = oneOptemp(arg1, arg2 + memoryWrapper(arg3));
            break;
        case CPTA:
            line = oneOptemp(arg2 + memoryWrapper(arg3), arg1);
            break;
        case BE:

            break;
        case BNE:
            break;
        case BLT:
            break;
        case CALL:
            break;
        case RET:
            break;
    }
}


