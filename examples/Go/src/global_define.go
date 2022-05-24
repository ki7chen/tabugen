// This file is auto-generated by Tabugen v0.8.1, DO NOT EDIT!
package config

import (
	"log"
	"reflect"
	"strings"
)

var (
	_ = log.Panicf
	_ = reflect.TypeOf
	_ = strings.Split
)

// 全局数值配置, 全局变量表.xlsx
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
	if len(rows) < 12 {
		log.Panicf("GlobalPropertyDefine:row length out of index, %d < 12", len(rows))
	}
	if rows[0][2] != "" {
		var value = parseStringAs(reflect.Float64, rows[0][2])
		p.GoldExchangeTimeFactor1 = value.(float64)
	}
	if rows[1][2] != "" {
		var value = parseStringAs(reflect.Float64, rows[1][2])
		p.GoldExchangeTimeFactor2 = value.(float64)
	}
	if rows[2][2] != "" {
		var value = parseStringAs(reflect.Float64, rows[2][2])
		p.GoldExchangeTimeFactor3 = value.(float64)
	}
	if rows[3][2] != "" {
		var value = parseStringAs(reflect.Uint16, rows[3][2])
		p.GoldExchangeResource1Price = value.(uint16)
	}
	if rows[4][2] != "" {
		var value = parseStringAs(reflect.Uint16, rows[4][2])
		p.GoldExchangeResource2Price = value.(uint16)
	}
	if rows[5][2] != "" {
		var value = parseStringAs(reflect.Uint16, rows[5][2])
		p.GoldExchangeResource3Price = value.(uint16)
	}
	if rows[6][2] != "" {
		var value = parseStringAs(reflect.Uint16, rows[6][2])
		p.GoldExchangeResource4Price = value.(uint16)
	}
	if rows[7][2] != "" {
		var value = parseStringAs(reflect.Uint16, rows[7][2])
		p.FreeCompleteSeconds = value.(uint16)
	}
	if rows[8][2] != "" {
		var value = parseStringAs(reflect.Uint16, rows[8][2])
		p.CancelBuildReturnPercent = value.(uint16)
	}
	if rows[9][2] != "" {
		var value = parseStringAs(reflect.Bool, rows[9][2])
		p.EnableSearch = value.(bool)
	}
	if rows[10][2] != "" {
		for _, item := range strings.Split(rows[10][2], TABUGEN_ARRAY_DELIM) {
			var value = parseStringAs(reflect.Int, item)
			p.SpawnLevelLimit = append(p.SpawnLevelLimit, value.(int))
		}
	}
	if rows[11][2] != "" {
		p.FirstRechargeReward = map[string]int{}
		for _, text := range strings.Split(rows[11][2], TABUGEN_MAP_DELIM1) {
			if text == "" {
				continue
			}
			var items = strings.Split(text, TABUGEN_MAP_DELIM2)
			var value = parseStringAs(reflect.String, items[0])
			var key = value.(string)
			value = parseStringAs(reflect.Int, items[1])
			var val = value.(int)
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