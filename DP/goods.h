#pragma once

#include "param.h"

class goods {
public:
// set
void set_value(int val);
void set_name_list(int *pre_name_list, int cur_num, int flg);
// get
int  get_value() { return value; }
int  *get_name_list() { return name_list; }


private:
  int value;
  int goods_cnt;
  int name_list[max_num];
};