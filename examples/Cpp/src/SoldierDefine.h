﻿// This file is auto-generated by Tabugen v0.10.0, DO NOT EDIT!

#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>


namespace config {

// 
struct SoldierPropertyDefine 
{
    std::string  Name;                      // 士兵ID
    int          Level = 0;                 // 士兵等级
    std::string  NameID;                    // 名字
    std::string  BuildingName;              // 所属建筑
    uint32_t     BuildingLevel = 0;         // 建筑等级
    uint32_t     RequireSpace = 0;          // 登陆艇占用空间
    uint32_t     Volume = 0;                // 体积
    uint32_t     UpgradeTime = 0;           // 升级消耗的时间(秒）
    std::string  UpgradeMaterialID;         // 升级消耗的材料
    int64_t      UpgradeMaterialNum = 0;    // 升级消耗的数量
    std::string  ConsumeMaterial;           // 生产消耗的材料
    int          ConsumeMaterialNum = 0;    // 生产消耗的数量
    int          ConsumeTime = 0;           // 生产消耗的时间（秒/个）
    int          Act = 0;                   // 攻击
    int          Hp = 0;                    // 血量
    int16_t      BombLoad = 0;              // 载弹量
    uint32_t     Hurt = 0;                  // buff伤害
    double       Duration = 0.0;            // 持续时间
    double       TriggerInterval = 0.0;     // 触发间隔
    int16_t      SearchScope = 0;           // 搜索范围
    double       AtkFrequency = 0.0;        // 攻击间隔
    double       AtkRange = 0.0;            // 攻击距离
    double       MovingSpeed = 0.0;         // 移动速度
    bool         EnableBurn = false;        // 燃烧特效

    static int ParseFrom(const std::unordered_map<std::string, std::string>& fields, SoldierPropertyDefine* ptr);
};

} // namespace config
