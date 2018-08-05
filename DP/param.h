#pragma once

#define NAME_DUMP // 選択されたものが何だったかを出力するもの（実装途中:現在の実装ではメモリが足りない）

// 初期設定値
const unsigned int max_num =  100;//6; // アイテムの許容される最大個数
const unsigned int elem = 2; // アイテム内の要素数
const unsigned int max_weight = 10000; //8; // 最大の重さ

const unsigned int dp_num = 2;
const unsigned int dp_weight = max_weight + 10;

const unsigned int str_len = 256;