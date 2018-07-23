/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __QUICK_SORT_H
#define __QUICK_SORT_H
//快速排序基于二分思想,平均时间复杂度O(NlogN)
/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported define -----------------------------------------------------------*/
//字符串间排序,首字母,默认长度为10
#define STRING_LEN 10
/* Exported macro ------------------------------------------------------------*/
//数值排序
void quick_sort_int(int *array,int start,int end);
//字符串内排序
void quick_sort_char(char *array,int start,int end);
//字符串间排序
void quick_sort_string(char (*array)[STRING_LEN],int start,int end);

#endif
