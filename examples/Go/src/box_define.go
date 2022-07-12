// This file is auto-generated by Tabugen v0.9.1, DO NOT EDIT!
package config

import (
	"log"
	"strings"
)

var (
	_ = log.Panicf
	_ = strings.Split
)

// , 随机宝箱.xlsx
type BoxProbabilityDefine struct {
	ID           string `json:"id"`           // ID
	Total        int    `json:"total"`        // 奖励总数
	Time         int    `json:"time"`         // 冷却时间
	Repeat       bool   `json:"repeat"`       // 是否可重复
	GoodsID1     string `json:"goods_id1"`    // 物品1id
	Num1         uint32 `json:"num1"`         // 物品1数量
	Probability1 uint32 `json:"probability1"` // 物品1概率
	GoodsID2     string `json:"goods_id2"`    // 物品2id
	Num2         uint32 `json:"num2"`         // 物品2数量
	Probability2 uint32 `json:"probability2"` // 物品2概率
	GoodsID3     string `json:"goods_id3"`    // 物品3id
	Num3         uint32 `json:"num3"`         // 物品3数量
	Probability3 uint32 `json:"probability3"` // 物品3概率
}

func (p *BoxProbabilityDefine) ParseFromRow(row []string) error {
	if len(row) < 13 {
		log.Panicf("BoxProbabilityDefine: row length too short %d", len(row))
	}
	if row[0] != "" {
		p.ID = row[0]
	}
	if row[1] != "" {
		p.Total = parseInt(row[1])
	}
	if row[2] != "" {
		p.Time = parseInt(row[2])
	}
	if row[3] != "" {
		p.Repeat = parseBool(row[3])
	}
	if row[4] != "" {
		p.GoodsID1 = row[4]
	}
	if row[5] != "" {
		p.Num1 = parseU32(row[5])
	}
	if row[6] != "" {
		p.Probability1 = parseU32(row[6])
	}
	if row[7] != "" {
		p.GoodsID2 = row[7]
	}
	if row[8] != "" {
		p.Num2 = parseU32(row[8])
	}
	if row[9] != "" {
		p.Probability2 = parseU32(row[9])
	}
	if row[10] != "" {
		p.GoodsID3 = row[10]
	}
	if row[11] != "" {
		p.Num3 = parseU32(row[11])
	}
	if row[12] != "" {
		p.Probability3 = parseU32(row[12])
	}
	return nil
}
