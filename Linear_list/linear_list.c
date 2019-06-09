
#include "linear_list.h"

/*节点元素 */
struct Element
{
    char *data;
};

struct SequenceList
{
    Element *data;  //数据起始指针
    int size_used;  //顺序表已使用大小
    int size_total; //顺序表总大小
};

/*初始化 */
int s_init(SequenceList *sequence_list)
{
    sequence_list->data = (Element *)calloc(S_SIZE_INIT, sizeof(Element)); //初始化起始指针，分配初始化空间
    if (sequence_list->data == NULL)
        return FAILURE;                      //如果分配空间失败，返回失败标志
    sequence_list->size_total = S_SIZE_INIT; //初始化总大小
    sequence_list->size_used = 0;            //初始化已使用大小
    printf("SUCCESS");
    return SUCCESS; //返回成功标志
}

/*查看一个 */
int s_get(int index, SequenceList *sequence_list)
{
    if (index >= sequence_list->size_total || index < 0)
        return FAILURE; //index参数错误，返回失败标志
    print("%s", sequence_list->data[index]);
    return SUCCESS; //返回成功标志
}

/*查看所有 */
void s_get_all(SequenceList *sequence_list)
{
    Element *e;                                                                            //用于遍历的临时变量
    for (e = sequence_list->data; e < sequence_list->data + sequence_list->size_used; e++) //遍历
    {
        print("%s", *e->data);
    }
}

/*添加 */
int s_insert(int index, Element element, SequenceList *sequence_list)
{
    Element *e; //用于遍历的临时变量
    if (index >= sequence_list->size_total || index < 0)
        return FAILURE;                                        //index参数错误，返回失败标志
    if (sequence_list->size_used == sequence_list->size_total) //可用空间不足
    {
        Element *new = (Element *)realloc(sequence_list->data, S_SIZE_STEP * sizeof(Element)); //重新分配内存
        if (!new)
            return FAILURE;                       //重新分配失败，返回失败标志
        sequence_list->data = new;                //重新分配成功，将数据指针指向新分配的内存
        sequence_list->size_total += S_SIZE_STEP; //重设总大小的值
    }
    for (e = sequence_list->data + sequence_list->size_used; e > sequence_list->data; e--) //倒序遍历
    {
        *e = *(e - 1); //将index后的数据后移
    }
    *e = element;                  //插入新数据
    sequence_list->size_used += 1; //重设已用大小的值
    return SUCCESS;                //返回成功标志
}

/*删除 */
int s_del(int index, SequenceList *sequence_list)
{
    Element *e; //用于遍历的临时变量
    if (index >= sequence_list->size_used || index < 0)
        return FAILURE;                                                                            //index参数错误，返回失败标志
    for (e = sequence_list->data + index; e < sequence_list->data + sequence_list->size_used; e++) //倒序遍历
    {
        *e = *(e + 1); //将index后的数据前移，直接覆盖index位置的数据
    }
    return SUCCESS; //返回成功标志
}

/*修改 */
int s_edit(int index, Element element, SequenceList *sequence_list)
{
    if (index >= sequence_list->size_used || index < 0)
        return FAILURE;                   //index参数错误，返回失败标志
    sequence_list->data[index] = element; //修改对应的数据
    return SUCCESS;                       //返回成功标志
}

/*销毁 */
void s_destory(SequenceList *sequence_list)
{
    free(sequence_list); //双方相应的内存
}
