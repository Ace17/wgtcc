#ifndef _WGTCC_CODE_GEN_H_
#define _WGTCC_CODE_GEN_H_

#include <cstdio>
#include <string>

class Parser;
class Constant;

std::string AddConstant(Constant* cons);
void GenerateCode(Parser* parser, FILE* outFile);

#endif
