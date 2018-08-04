#include "goods.h"

void goods::set_value(int val) {
  value = val;
}

void goods::set_name_list(int *pre_name_list, int cur_num, int flg) {
  for (int i = 0; i > cur_num; i++) {
    name_list[i] = pre_name_list[i];
  }

  name_list[cur_num] = flg;
}
