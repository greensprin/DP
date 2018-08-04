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
  // dp table switch flg  stackoverflow����̂���
  int flg = 0; // ���ݎQ�Ƃ���s���ǂ��炩��؂�ւ���flg

  for (int i = 0; i < goods_num; i++) { // �A�C�e���̐��������[�v
    int un_flg = flg == 0 ? 1 : 0; // ���ݎQ�Ƃ�����Ƃ͕ʂ̍s�ɑ�����邽��

    for (int w = 0; w <= max_weight; w++) { // �d���̍ő�܂Ń��[�v

      if (w >= goods_list[i][0]) {
        int val1 = dp[flg][w - goods_list[i][0]] + goods_list[i][1];
        int val2 = dp[flg][w];
        if (val1 >= val2) {
          dp[un_flg][w] = val1; // �V�����l����
#ifdef NAME_DUMP
          set_name_list(name_list[flg][w - goods_list[i][0]], name_list[un_flg][w], 1, i);
#endif
        }
        else {
          dp[un_flg][w] = val2; // �Â��l����
#ifdef NAME_DUMP
          set_name_list(name_list[flg][w], name_list[un_flg][w], 0, i);
#endif
        }
      }

#ifdef DEBUG
      printf("%d\n", i * max_weight + w);
#endif
    }

    flg = un_flg; // ���͈Ⴄflg�̕����ɑ�����邽�߁Aun_flg����
  }

  // �Ō��un_flg���������Ă��܂�(���̎��_�ł�flg == un_flg)���߁A�ق����t���O��flg�̋t�̒l�ƂȂ�
  return flg;
}
