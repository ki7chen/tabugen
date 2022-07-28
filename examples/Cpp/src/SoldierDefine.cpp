// This file is auto-generated by Tabular v0.9.1, DO NOT EDIT!

#include "SoldierDefine.h"
#include <stddef.h>
#include <assert.h>
#include <memory>
#include <fstream>
#include "Conv.h"
#include "StringUtil.h"

using namespace std;

#ifndef ASSERT
#define ASSERT assert
#endif


namespace config {

// parse data object from an csv row
int SoldierPropertyDefine::ParseFrom(std::unordered_map<std::string, std::string>& record, SoldierPropertyDefine* ptr)
{
    ASSERT(ptr != nullptr);
    ptr->Name = record["Name"];
    ptr->Level = to<int>(record["Level"]);
    ptr->NameID = record["NameID"];
    ptr->Description = record["Description"];
    ptr->BuildingName = record["BuildingName"];
    ptr->BuildingLevel = to<uint32_t>(record["BuildingLevel"]);
    ptr->RequireSpace = to<uint32_t>(record["RequireSpace"]);
    ptr->Volume = to<uint32_t>(record["Volume"]);
    ptr->UpgradeTime = to<uint32_t>(record["UpgradeTime"]);
    ptr->UpgradeMaterialID = record["UpgradeMaterialID"];
    ptr->UpgradeMaterialNum = to<int64_t>(record["UpgradeMaterialNum"]);
    ptr->ConsumeMaterial = record["ConsumeMaterial"];
    ptr->ConsumeMaterialNum = to<int>(record["ConsumeMaterialNum"]);
    ptr->ConsumeTime = to<int>(record["ConsumeTime"]);
    ptr->Act = to<int>(record["Act"]);
    ptr->Hp = to<int>(record["Hp"]);
    ptr->BombLoad = to<int16_t>(record["BombLoad"]);
    ptr->Hurt = to<uint32_t>(record["Hurt"]);
    ptr->Duration = to<float>(record["Duration"]);
    ptr->TriggerInterval = to<float>(record["TriggerInterval"]);
    ptr->SearchScope = to<int16_t>(record["SearchScope"]);
    ptr->AtkFrequency = to<float>(record["AtkFrequency"]);
    ptr->AtkRange = to<double>(record["AtkRange"]);
    ptr->MovingSpeed = to<double>(record["MovingSpeed"]);
    ptr->EnableBurn = to<bool>(record["EnableBurn"]);
    return 0;
}


} // namespace config 
