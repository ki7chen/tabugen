// This file is auto-generated by Tabugen v0.8.1, DO NOT EDIT!

using System;
using System.Collections.Generic;

namespace Config
{

// 兵种属性配置, 兵种.xlsx
public class SoldierPropertyDefine
{
    public string  Name = "";                 // 士兵ID
    public int     Level = 0;                 // 士兵等级
    public string  NameID = "";               // 名字
    public string  Description = "";          // 描述
    public string  BuildingName = "";         // 所属建筑
    public uint    BuildingLevel = 0;         // 建筑等级
    public uint    RequireSpace = 0;          // 登陆艇占用空间
    public uint    Volume = 0;                // 体积
    public uint    UpgradeTime = 0;           // 升级消耗的时间(秒）
    public string  UpgradeMaterialID = "";    // 升级消耗的材料
    public long    UpgradeMaterialNum = 0;    // 升级消耗的数量
    public string  ConsumeMaterial = "";      // 生产消耗的材料
    public int     ConsumeMaterialNum = 0;    // 生产消耗的数量
    public int     ConsumeTime = 0;           // 生产消耗的时间（秒/个）
    public int     Act = 0;                   // 攻击
    public int     Hp = 0;                    // 血量
    public short   BombLoad = 0;              // 载弹量
    public uint    Hurt = 0;                  // buff伤害
    public float   Duration = 0.0f;           // 持续时间
    public float   TriggerInterval = 0.0f;    // 触发间隔
    public short   SearchScope = 0;           // 搜索范围
    public float   AtkFrequency = 0.0f;       // 攻击间隔
    public double  AtkRange = 0.0f;           // 攻击距离
    public double  MovingSpeed = 0.0f;        // 移动速度
    public bool    EnableBurn = false;        // 燃烧特效

    // parse object fields from a text row
    public void ParseFromRow(List<string> row)
    {
        if (row.Count < 25) {
            throw new ArgumentException(string.Format("SoldierPropertyDefine: row length too short {0}", row.Count));
        }
        if (row[0].Length > 0) {
            this.Name = row[0].Trim();
        }
        if (row[1].Length > 0) {
            this.Level = int.Parse(row[1]);
        }
        if (row[2].Length > 0) {
            this.NameID = row[2].Trim();
        }
        if (row[3].Length > 0) {
            this.Description = row[3].Trim();
        }
        if (row[4].Length > 0) {
            this.BuildingName = row[4].Trim();
        }
        if (row[5].Length > 0) {
            this.BuildingLevel = uint.Parse(row[5]);
        }
        if (row[6].Length > 0) {
            this.RequireSpace = uint.Parse(row[6]);
        }
        if (row[7].Length > 0) {
            this.Volume = uint.Parse(row[7]);
        }
        if (row[8].Length > 0) {
            this.UpgradeTime = uint.Parse(row[8]);
        }
        if (row[9].Length > 0) {
            this.UpgradeMaterialID = row[9].Trim();
        }
        if (row[10].Length > 0) {
            this.UpgradeMaterialNum = long.Parse(row[10]);
        }
        if (row[11].Length > 0) {
            this.ConsumeMaterial = row[11].Trim();
        }
        if (row[12].Length > 0) {
            this.ConsumeMaterialNum = int.Parse(row[12]);
        }
        if (row[13].Length > 0) {
            this.ConsumeTime = int.Parse(row[13]);
        }
        if (row[14].Length > 0) {
            this.Act = int.Parse(row[14]);
        }
        if (row[15].Length > 0) {
            this.Hp = int.Parse(row[15]);
        }
        if (row[16].Length > 0) {
            this.BombLoad = short.Parse(row[16]);
        }
        if (row[17].Length > 0) {
            this.Hurt = uint.Parse(row[17]);
        }
        if (row[18].Length > 0) {
            this.Duration = float.Parse(row[18]);
        }
        if (row[19].Length > 0) {
            this.TriggerInterval = float.Parse(row[19]);
        }
        if (row[20].Length > 0) {
            this.SearchScope = short.Parse(row[20]);
        }
        if (row[21].Length > 0) {
            this.AtkFrequency = float.Parse(row[21]);
        }
        if (row[22].Length > 0) {
            this.AtkRange = double.Parse(row[22]);
        }
        if (row[23].Length > 0) {
            this.MovingSpeed = double.Parse(row[23]);
        }
        if (row[24].Length > 0) {
            this.EnableBurn = bool.Parse(row[24]);
        }
    }
}


}