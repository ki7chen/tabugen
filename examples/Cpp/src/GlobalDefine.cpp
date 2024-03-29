﻿// This file is auto-generated by Tabular v0.10.0, DO NOT EDIT!

#include "GlobalDefine.h"
#include <stddef.h>
#include "Conv.h"

using namespace std;

#ifndef ASSERT
#define ASSERT assert
#endif


namespace config {

// parse GlobalPropertyDefine from string fields
int GlobalPropertyDefine::ParseFrom(const unordered_map<string, string>& fields, GlobalPropertyDefine* ptr)
{
    ASSERT(ptr != nullptr);
    ptr->GoldExchangeTimeFactor1 = parseField<double>(fields, "GoldExchangeTimeFactor1");
    ptr->GoldExchangeTimeFactor2 = parseField<double>(fields, "GoldExchangeTimeFactor2");
    ptr->GoldExchangeTimeFactor3 = parseField<double>(fields, "GoldExchangeTimeFactor3");
    ptr->GoldExchangeResource1Price = parseField<uint16_t>(fields, "GoldExchangeResource1Price");
    ptr->GoldExchangeResource2Price = parseField<uint16_t>(fields, "GoldExchangeResource2Price");
    ptr->GoldExchangeResource3Price = parseField<uint16_t>(fields, "GoldExchangeResource3Price");
    ptr->GoldExchangeResource4Price = parseField<uint16_t>(fields, "GoldExchangeResource4Price");
    ptr->FreeCompleteSeconds = parseField<uint16_t>(fields, "FreeCompleteSeconds");
    ptr->CancelBuildReturnPercent = parseField<uint16_t>(fields, "CancelBuildReturnPercent");
    ptr->EnableSearch = parseField<bool>(fields, "EnableSearch");
    ptr->SpawnLevelLimit = parseArrayField<int>(fields, "SpawnLevelLimit");
    ptr->FirstRechargeReward = parseMapField<std::string,int>(fields, "FirstRechargeReward");
    ptr->VIPItemReward = parseMapField<int,int>(fields, "VIPItemReward");
    return 0;
}


} // namespace config 
