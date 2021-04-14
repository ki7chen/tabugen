// This file is auto-generated by Tabular v0.6.0, DO NOT EDIT!
package config

import (
	"log"
	"strings"
)

var (
	_ = strings.Split
	_ = log.Panicf
)

// 兵种属性配置, 兵种.xlsx
type SoldierPropertyDefine struct {
	Name               string  `json:"name"`                 // 士兵ID
	Level              int     `json:"level"`                // 士兵等级
	NameID             string  `json:"name_id"`              // 名字
	Description        string  `json:"description"`          // 描述
	BuildingName       string  `json:"building_name"`        // 所属建筑
	BuildingLevel      uint32  `json:"building_level"`       // 建筑等级
	RequireSpace       uint32  `json:"require_space"`        // 登陆艇占用空间
	UpgradeTime        uint32  `json:"upgrade_time"`         // 升级消耗的时间(秒）
	UpgradeMaterialID  string  `json:"upgrade_material_id"`  // 升级消耗的材料
	UpgradeMaterialNum int64   `json:"upgrade_material_num"` // 升级消耗的数量
	ConsumeMaterial    string  `json:"consume_material"`     // 生产消耗的材料
	ConsumeMaterialNum int     `json:"consume_material_num"` // 生产消耗的数量
	ConsumeTime        int     `json:"consume_time"`         // 生产消耗的时间（秒/个）
	Act                int     `json:"act"`                  // 攻击
	Hp                 int     `json:"hp"`                   // 血量
	BombLoad           int16   `json:"bomb_load"`            // 载弹量
	Duration           float32 `json:"duration"`             // 持续时间
	TriggerInterval    float32 `json:"trigger_interval"`     // 触发间隔
	SearchScope        int16   `json:"search_scope"`         // 搜索范围
	AtkFrequency       float32 `json:"atk_frequency"`        // 攻击间隔
	AtkRange           float64 `json:"atk_range"`            // 攻击距离
	MovingSpeed        float64 `json:"moving_speed"`         // 移动速度
	EnableBurn         bool    `json:"enable_burn"`          // 燃烧特效
}
