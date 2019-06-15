#ifndef _WGTCC_CODE_GEN_H_
#define _WGTCC_CODE_GEN_H_

#include <cstdio>
#include <string>

class TranslationUnit;
class Constant;

std::string AddConstant(Constant* cons);
void GenerateCode(TranslationUnit* unit, FILE* outFile);

#endif
