// This file is auto-generated by Tabugen v0.6.9, DO NOT EDIT!

using System;
using System.Collections.Generic;

namespace Config
{

public class ProbabilityGoodsDefine 
{
    public string GoodsID = "";       // 物品1id
    public uint Num = 0;            // 物品1数量
    public uint Probability = 0;    // 物品1概率
};

// , 随机宝箱.xlsx
public class BoxProbabilityDefine
{
    public string                    ID = "";             // ID
    public int                       Total = 0;           // 奖励总数
    public int                       Time = 0;            // 冷却时间
    public bool                      Repeat = false;      // 是否可重复
    public ProbabilityGoodsDefine[] ProbabilityGoods = null; 

    // parse object fields from a text row
    public void ParseFromRow(List<string> row)
    {
        if (row.Count < 13) {
            throw new ArgumentException(string.Format("BoxProbabilityDefine: row length too short {0}", row.Count));
        }
        if (row[0].Length > 0) {
            this.ID = row[0].Trim();
        }
        if (row[1].Length > 0) {
            this.Total = int.Parse(row[1]);
        }
        if (row[2].Length > 0) {
            this.Time = int.Parse(row[2]);
        }
        if (row[3].Length > 0) {
            this.Repeat = AutogenConfigManager.ParseBool(row[3]);
        }
        this.ProbabilityGoods = new ProbabilityGoodsDefine[3];
        for (int i = 4, j = 0; i < 13; i += 3, j++) 
        {
            ProbabilityGoodsDefine item = new ProbabilityGoodsDefine();
            if (row[i + 0].Length > 0) 
            {
                item.GoodsID = row[i + 0].Trim();
            }
            if (row[i + 1].Length > 0) 
            {
                item.Num = uint.Parse(row[i + 1]);
            }
            if (row[i + 2].Length > 0) 
            {
                item.Probability = uint.Parse(row[i + 2]);
            }
            this.ProbabilityGoods[j] = item;
        }
    }
}


public class AutogenConfigManager 
{    
    public const char TABUGEN_CSV_SEP = ',';           // CSV field delimiter
    public const char TABUGEN_CSV_QUOTE = '"';          // CSV field quote
    public const char TABUGEN_ARRAY_DELIM = ',';       // array item delimiter
    public const char TABUGEN_MAP_DELIM1 = ';';        // map item delimiter
    public const char TABUGEN_MAP_DELIM2 = '=';        // map key-value delimiter
    
    // self-defined boolean value parse
    public static bool ParseBool(string text)
    {
        if (text == null || text.Length == 0) {
            return false;
        }
        return string.Equals(text, "1") ||
            string.Equals(text, "Y") || 
            string.Equals(text, "ON");
    }
}


}
