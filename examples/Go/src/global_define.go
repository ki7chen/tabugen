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

// , 全局变量表.xlsx
type GlobalPropertyDefine struct {
	GoldExchangeTimeFactor1    float64        `json:"gold_exchange_time_factor1"`    // 金币兑换时间参数1
	GoldExchangeTimeFactor2    float64        `json:"gold_exchange_time_factor2"`    // 金币兑换时间参数2
	GoldExchangeTimeFactor3    float64        `json:"gold_exchange_time_factor3"`    // 金币兑换时间参数3
	GoldExchangeResource1Price uint16         `json:"gold_exchange_resource1_price"` // 金币兑换资源1价格
	GoldExchangeResource2Price uint16         `json:"gold_exchange_resource2_price"` // 金币兑换资源2价格
	GoldExchangeResource3Price uint16         `json:"gold_exchange_resource3_price"` // 金币兑换资源3价格
	GoldExchangeResource4Price uint16         `json:"gold_exchange_resource4_price"` // 金币兑换资源4价格
	FreeCompleteSeconds        uint16         `json:"free_complete_seconds"`         // 免费立即完成时间
	CancelBuildReturnPercent   uint16         `json:"cancel_build_return_percent"`   // 取消建造后返还资源比例
	EnableSearch               bool           `json:"enable_search"`                 // 开启搜索
	SpawnLevelLimit            []int          `json:"spawn_level_limit"`             // 最大刷新个数显示
	FirstRechargeReward        map[string]int `json:"first_recharge_reward"`         // 首充奖励
}

func (p *GlobalPropertyDefine) ParseFromRows(rows [][]string) error {
	if len(rows) < 9 {
		log.Panicf("GlobalPropertyDefine:row length out of index, %d < 9", len(rows))
	}
	if rows[0][2] != "" {
		p.GoldExchangeResource1Price = parseU16(rows[0][2])
	}
	if rows[1][2] != "" {
		p.GoldExchangeResource2Price = parseU16(rows[1][2])
	}
	if rows[2][2] != "" {
		p.GoldExchangeResource3Price = parseU16(rows[2][2])
	}
	if rows[3][2] != "" {
		p.GoldExchangeResource4Price = parseU16(rows[3][2])
	}
	if rows[4][2] != "" {
		p.FreeCompleteSeconds = parseU16(rows[4][2])
	}
	if rows[5][2] != "" {
		p.CancelBuildReturnPercent = parseU16(rows[5][2])
	}
	if rows[6][2] != "" {
		p.EnableSearch = parseBool(rows[6][2])
	}
	if rows[7][2] != "" {
		for _, item := range strings.Split(rows[7][2], TABUGEN_ARRAY_DELIM) {
			var value = parseInt(item)
			p.SpawnLevelLimit = append(p.SpawnLevelLimit, value)
		}
	}
	if rows[8][2] != "" {
		p.FirstRechargeReward = map[string]int{}
		for _, text := range strings.Split(rows[8][2], TABUGEN_MAP_DELIM1) {
			if text == "" {
				continue
			}
			var items = strings.Split(text, TABUGEN_MAP_DELIM2)
			var key = strings.TrimSpace(items[0])
			var val = parseInt(items[1])
			p.FirstRechargeReward[key] = val
		}
	}
	return nil
}

func (p *GlobalPropertyDefine) Unmarshal(data []byte) error {
	rows, err := ReadCSVRows(data)
	if err != nil {
		log.Printf("GlobalPropertyDefine: csv read all, %v", err)
		return err
	}
	if err := p.ParseFromRows(rows); err != nil {
		log.Printf("GlobalPropertyDefine: parse row %d, %v", len(rows), err)
		return err
	}
	return nil
}
