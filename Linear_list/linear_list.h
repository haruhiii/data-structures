/****************************
 * *********线性表************
 * **************************
 * 1.顺序表 
 * 2.链表
 *      1.单链表
 *          1.动态单链表
 *          2.静态单链表   
 *      2.双链表
 *      3.循环链表
 *          1.单循环链表
 *          2.双循环链表
 * *************************
 ***************************/
#include "../common.h"

#define S_SIZE_INIT 20
#define S_SIZE_STEP 10
/*  顺序表 
 *  
*/

/* 顺序表 */
typedef struct SequenceList SequenceList;

/*初始化 */
int s_init(SequenceList *sequence_list);
/*查看一个 */
int s_get(int index, SequenceList *sequence_list);
/*查看所有 */
void s_get_all(SequenceList *sequence_list);
/*插入 */
int s_insert(int index,Element element, SequenceList *sequence_list);
/*删除 */
int s_del(int index, SequenceList *sequence_list);
/*修改 */
int s_edit(int index,Element element, SequenceList *sequence_list);
/*销毁 */
void s_destory(SequenceList *sequence_list);
