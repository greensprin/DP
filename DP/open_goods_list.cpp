#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

#include "param.h"
#include "open_goods_list.h"

int open_goods_list(const char *file_path, int goods_list[max_num][elem], char name[max_num][str_len]) {
  // ファイルを開く
  FILE *fp = fopen(file_path, "r");
  if (fp == nullptr) {
    printf("this file is not found!\n");
	  return 0;
  }

  // ファイルを1行ずつ読み込み
  char goods_name[str_len] = {};
  int weight = 0, value = 0;
  int goods_cnt = 0;
  for (int i = 0; fscanf(fp, "%s %d %d", goods_name, &weight, &value) != EOF; i++) {
    if (i >= max_num) {
      printf("this goods_list was reached to max goods_num. So canceled to read goods_list");
      break;
    }

    // goods_listへ格納
    strcpy(name[i], goods_name);
    goods_list[i][0] = weight;
    goods_list[i][1] = value;
		goods_cnt++;
  }

  fclose(fp);

  return goods_cnt;
}
