#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

#include "param.h"
#include "dp.h"

//#define DEBUG

void set_name_list(int *pre_name_list, int *name_list, int flg, int cnt) {
  for (int i = 0; i < cnt; i++) {
    name_list[i] = pre_name_list[i];
  }
  if (flg == 1) name_list[cnt] = 1;
}

int calc_dp(int dp[dp_num][dp_weight], int name_list[dp_num][dp_weight][max_num], const int goods_list[max_num][elem], const int goods_num) {
  // dp table switch flg  stackoverflow回避のため
  int flg = 0; // 現在参照する行がどちらかを切り替えるflg

  for (int i = 0; i < goods_num; i++) { // アイテムの数だけループ
    int un_flg = flg == 0 ? 1 : 0; // 現在参照する方とは別の行に代入するため

    for (int w = 0; w <= max_weight; w++) { // 重さの最大までループ

      if (w >= goods_list[i][0]) {
        int val1 = dp[flg][w - goods_list[i][0]] + goods_list[i][1];
        int val2 = dp[flg][w];
        if (val1 >= val2) {
          dp[un_flg][w] = val1; // 新しい値を代入
#ifdef NAME_DUMP
          set_name_list(name_list[flg][w - goods_list[i][0]], name_list[un_flg][w], 1, i);
#endif
        }
        else {
          dp[un_flg][w] = val2; // 古い値を代入
#ifdef NAME_DUMP
          set_name_list(name_list[flg][w], name_list[un_flg][w], 0, i);
#endif
        }
      }

#ifdef DEBUG
      printf("%d\n", i * max_weight + w);
#endif
    }

    flg = un_flg; // 次は違うflgの方向に代入するため、un_flgを代入
  }

  // 最後にun_flgが代入されてしまう(この時点ではflg == un_flg)ため、ほしいフラグはflgの逆の値となる
  return flg;
}
