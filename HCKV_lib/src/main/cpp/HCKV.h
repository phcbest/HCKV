//
// Created by PengHaiChen on 2022/7/22.
//

#ifndef HCKV_HCKV_H
#define HCKV_HCKV_H

#ifdef __cplusplus


namespace hckv{
    class CodeOutputData;
    class MemoryFile
}//namespace hckv

class HCKV {
    //构造函数
    HCKV(const std:string &mmapID);

    std::string m_mmapID;

}

#endif // __cplusplus
#endif //HCKV_HCKV_H
