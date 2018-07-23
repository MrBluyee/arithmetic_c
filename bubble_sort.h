/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BUBBLE_SORT_H
#define __BUBBLE_SORT_H
/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported define -----------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

//每次比较两个相邻的元素，如果它们的顺序错误就把它们交换过来,复杂度O(N^2)
void bubble_sort(int *array,int start,int end);

#endif
