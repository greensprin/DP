#pragma once

#include "param.h"
#include "goods.h"

int calc_dp(int dp[dp_num][dp_weight], int name_list[dp_num][dp_weight][max_num], const int goods_list[max_num][elem], const int goods_num);
