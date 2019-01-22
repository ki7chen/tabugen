// This file is auto-generated by taxi v0.3.5, DO NOT EDIT!

#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include <functional>
#include "Utility/Range.h"


namespace config
{

class AutogenConfigManager
{
public:

    // Load all configurations
    static void LoadAll();

    // Clear all configurations
    static void ClearAll();

    // Read content from an asset file
    static std::string ReadFileContent(const char* filepath);
    
    // default loader
    static std::function<std::string(const char*)> reader;
};

// ȫ����ֵ����
struct GlobalPropertyDefine 
{
    float     GoldExchangeTimeFactor1 = 0.0;     // ��Ҷһ�ʱ�����1
    float     GoldExchangeTimeFactor2 = 0.0;     // ��Ҷһ�ʱ�����2
    float     GoldExchangeTimeFactor3 = 0.0;     // ��Ҷһ�ʱ�����3
    uint32_t  GoldExchangeResource1Price = 0;    // ��Ҷһ���Դ1�۸�
    uint32_t  GoldExchangeResource2Price = 0;    // ��Ҷһ���Դ2�۸�
    uint32_t  GoldExchangeResource3Price = 0;    // ��Ҷһ���Դ3�۸�
    uint32_t  GoldExchangeResource4Price = 0;    // ��Ҷһ���Դ4�۸�
    uint32_t  FreeCompleteSeconds = 0;           // ����������ʱ��
    uint32_t  CancelBuildReturnPercent = 0;      // ȡ������󷵻���Դ����

    static int Load(const char* filepath);
    static int ParseFromRows(const std::vector<std::vector<StringPiece>>& rows, GlobalPropertyDefine* ptr);
    static const GlobalPropertyDefine* Instance();
};


} // namespace config 