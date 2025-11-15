// /**
//  * SVFIR.cpp
//  * @author 3220252746
//  */

// #include "Graphs/SVFG.h"
// #include "SVF-LLVM/SVFIRBuilder.h"
// #include "WPA/Andersen.h"

// using namespace SVF;
// using namespace llvm;
// using namespace std;

// int main(int argc, char **argv)
// {
//     int arg_num = 0;
//     int extraArgc = 4;
//     char **arg_value = new char *[argc + extraArgc];
//     for (; arg_num < argc; ++arg_num)
//     {
//         arg_value[arg_num] = argv[arg_num];
//     }
//     std::vector<std::string> moduleNameVec;

//     int orgArgNum = arg_num;
//     arg_value[arg_num++] = (char *)"-model-arrays=true";
//     arg_value[arg_num++] = (char *)"-pre-field-sensitive=false";
//     arg_value[arg_num++] = (char *)"-model-consts=true";
//     arg_value[arg_num++] = (char *)"-stat=false";
//     assert(arg_num == (orgArgNum + extraArgc) && "more extra arguments? Change the value of extraArgc");

//     moduleNameVec = OptionBase::parseOptions(arg_num, arg_value, "SVF IR", "[options] <input-bitcode...>");

//     LLVMModuleSet::getLLVMModuleSet()->buildSVFModule(moduleNameVec);

//     // Instantiate an SVFIR builder
//     SVFIRBuilder builder;
//     cout << "Generating SVFIR(PAG), call graph and ICFG ..." << endl;

//     // // // TODO: here, generate SVFIR(PAG), call graph and ICFG, and dump them to files
   

//     // // 1) 建 SVFIR / PAG
//     // SVFIR* svfir = builder.build();

//     // // 2) 导出 SVFIR / PAG
//     // svfir->dump("svfir");

//     // // 3) 取 ICFG 并导出
//     // ICFG* icfg = svfir->getICFG();
//     // icfg->dump("icfg");


//     // // 4) 构造调用图并导出
//     // const CallGraph* cg = svfir->getCallGraph();
//     // cg->dump("callgraph");

//     // //@}

//     // TODO: here, generate SVFIR(PAG), call graph and ICFG, and dump them to files
//         // TODO 部分修改为：
//     // TODO: here, generate SVFIR(PAG), call graph and ICFG, and dump them to files
//     //@{

//    // 1) 建 SVFIR / PAG
//     SVFIR* svfir = builder.build();

//     // 2) 导出 SVFIR / PAG
//     svfir->dump();

//     // 3) 取 ICFG 并导出
//     ICFG* icfg = svfir->getICFG();
//     icfg->dump();

//     // 4) 通过指针分析构造调用图并导出
//     Andersen* pta = AndersenWaveDiff::createAndersenWaveDiff(svfir);
//     pta->getCallGraph()->dump();

//     //@}

//     return 0;
// }

/**
 * SVFIR.cpp
 * @author 3220252746
 */
#include "Graphs/SVFG.h"
#include "SVF-LLVM/SVFIRBuilder.h"
#include "WPA/Andersen.h"

using namespace SVF;
using namespace llvm;
using namespace std;

int main(int argc, char **argv)
{
    int arg_num = 0;
    int extraArgc = 4;
    char **arg_value = new char *[argc + extraArgc];
    for (; arg_num < argc; ++arg_num)
    {
        arg_value[arg_num] = argv[arg_num];
    }
    std::vector<std::string> moduleNameVec;

    int orgArgNum = arg_num;
    arg_value[arg_num++] = (char *)"-model-arrays=true";
    arg_value[arg_num++] = (char *)"-pre-field-sensitive=false";
    arg_value[arg_num++] = (char *)"-model-consts=true";
    arg_value[arg_num++] = (char *)"-stat=false";
    assert(arg_num == (orgArgNum + extraArgc) && "more extra arguments? Change the value of extraArgc");

    moduleNameVec = OptionBase::parseOptions(arg_num, arg_value, "SVF IR", "[options] <input-bitcode...>");

    LLVMModuleSet::getLLVMModuleSet()->buildSVFModule(moduleNameVec);

    // Instantiate an SVFIR builder
    SVFIRBuilder builder;
    cout << "Generating SVFIR(PAG), call graph and ICFG ..." << endl;

    // TODO: here, generate SVFIR(PAG), call graph and ICFG, and dump them to files
    //@{
   // TODO: here, generate SVFIR(PAG), call graph and ICFG, and dump them to files
   //@{
   
   // 1) 建 SVFIR / PAG
   SVFIR* svfir = builder.build();
   
   // 2) 运行 Andersen 分析
   Andersen* pta = AndersenWaveDiff::createAndersenWaveDiff(svfir);
   
   // 3) dump 所有
   svfir->dump();
   pta->getICFG()->dump();  // 从 pta 获取 ICFG
   pta->getCallGraph()->dump();
   
   //@}
    
    // // 1) 建 SVFIR / PAG
    // SVFIR* svfir = builder.build();

    // // 2) 导出 SVFIR / PAG
    // svfir->dump();

    // // 3) 取 ICFG 并导出
    // ICFG* icfg = svfir->getICFG();
    // icfg->dump();

    // // 4) 通过指针分析构造调用图并导出
    // Andersen* pta = AndersenWaveDiff::createAndersenWaveDiff(svfir);
    // pta->getCallGraph()->dump();
   

    //@}

    return 0;
}
