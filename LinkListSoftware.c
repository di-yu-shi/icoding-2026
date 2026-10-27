#include <stdio.h>
#include <stdlib.h>
// #include "lab52.h"
#include <stdbool.h>
#include <string.h>

#define GOODS_FILE_NAME "goodsinfo.txt"
#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 30
#define MAX_DISCOUNT_LEN 30
typedef struct {
char goods_id[MAX_ID_LEN];
char goods_name[MAX_NAME_LEN];
int goods_price;
char goods_discount[MAX_DISCOUNT_LEN];
int goods_amount;
int goods_remain;
} GoodsInfo;

typedef struct node
{
GoodsInfo data;
struct node *next;
} GoodsList;

GoodsInfo read_goods_info();
void init_list(GoodsList **pL);
void destory_list(GoodsList **pL);
void destory_list_and_file(GoodsList **pL);
int save_to_file(GoodsList *L);
void output_one_item(GoodsList *L);
void output_all_items(GoodsList *L);
bool insert_item(GoodsList *L, GoodsInfo item, int choice);
bool delete_item(GoodsList *L, char* goods_id);
GoodsList* search_item(GoodsList *L, char* goods_id);
bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info);
void bubble_sort(GoodsList *L);
int read_line(char str[], int n);

extern int CurrentCnt;

int main()
{
    GoodsInfo goodsInfo;
    char str[100];
    GoodsList *list = NULL;
    init_list(&list);
    while (true)
    {
        int op;
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                output_all_items(list);
                break;
            case 2:
                goodsInfo = read_goods_info();
                read_line(str, sizeof(str));
                change_item(list, str, goodsInfo);
                break;
            case 3:
                goodsInfo = read_goods_info();
                int pos;
                scanf("%d", &pos);
                insert_item(list, goodsInfo, pos);
                break;
            case 4:
                read_line(str, sizeof(str));
                delete_item(list, str);
                break;
            case 5:
                read_line(str, sizeof(str));
                search_item(list, str);
                break;
            case 6:
                save_to_file(list);
                destory_list(&list);
                break;
            case 7:
                bubble_sort(list);
                break;
            case 8:
                destory_list_and_file(&list);
                break;
            default:
                destory_list(&list);
                return 0;
                break;
        }
    }
    destory_list(&list);
    return 0;
}

GoodsInfo read_goods_info()
{
    GoodsInfo cur;
    read_line(cur.goods_id, sizeof(cur.goods_id));
    read_line(cur.goods_name, sizeof(cur.goods_name));
    scanf("%d", &cur.goods_price);
    read_line(cur.goods_discount, sizeof(cur.goods_discount));
    scanf("%d", &cur.goods_amount);
    scanf("%d", &cur.goods_remain);
    return cur;
}

void init_list(GoodsList **pL)
{
    FILE *p = fopen(GOODS_FILE_NAME, "r");
    GoodsInfo tmp;
    *pL = (GoodsList *)malloc(sizeof(GoodsList));
    GoodsList *lst = *pL;
    CurrentCnt = 0;
    while (fscanf(p, "%s\t%s\t%d\t%s\t%d\t%d\n", tmp.goods_id, tmp.goods_name, &tmp.goods_price, tmp.goods_discount, &tmp.goods_amount, &tmp.goods_remain) != EOF)
    {
        GoodsList *cur = (GoodsList *)malloc(sizeof(GoodsList));
        cur -> data = tmp;
        cur -> next = NULL;
        lst -> next = cur;
        lst = cur;
        CurrentCnt++;
    }
    fclose(p);
}

void destory_list(GoodsList **pL)
{
    GoodsList *cur = *pL;
    while (cur -> next != NULL)
    {
        GoodsList *tmp = cur;
        cur = cur -> next;
        free(tmp);
    }
    free(cur);
    *pL = NULL;
    CurrentCnt = 0;
}

void destory_list_and_file(GoodsList **pL)
{
    destory_list(pL);
    remove("goodsinfo.txt");
}

int save_to_file(GoodsList *L)
{
    FILE *p = fopen("goodsinfo.txt", "w");
    int cnt = 0;
    while (L -> next != NULL)
    {
        fprintf(p, "%s\t%s\t%d\t%s\t%d\t%d\n", L -> next -> data.goods_id, L -> next -> data.goods_name, L -> next -> data.goods_price, L -> next -> data.goods_discount, L -> next -> data.goods_amount, L -> next -> data.goods_remain);
        cnt++;
        L = L -> next;
    }
    fclose(p);
    return cnt;
}

void output_one_item(GoodsList *L)
{
    printf("%s\n%s\n%d\n%s\n%d\n%d\n", L -> data.goods_id, L -> data.goods_name, L -> data.goods_price, L -> data.goods_discount, L -> data.goods_amount, L -> data.goods_remain);
}

void output_all_items(GoodsList *L)
{
    while (L -> next != NULL)
    {
        output_one_item(L -> next);
        L = L -> next;
    }
}

bool insert_item(GoodsList *L, GoodsInfo item, int choice)
{
    if (choice == 0)
    {
        choice = CurrentCnt + 1;
    }
    if (choice > CurrentCnt + 1)
    {
        return false;
    }
    for (int i = 1; i <= choice - 1; i++)
    {
        L = L -> next;
    }
    GoodsList *cur = (GoodsList *)malloc(sizeof(GoodsList));
    cur -> data = item;
    cur -> next = L -> next;
    L -> next = cur;
    CurrentCnt++;
    return true;
}

bool delete_item(GoodsList *L, char* goods_id)
{
    while (L -> next != NULL)
    {
        if (strcmp(L -> next -> data.goods_id, goods_id) == 0)
        {
            GoodsList *tmp = L -> next;
            L -> next = tmp -> next;
            free(tmp);
            CurrentCnt--;
            return true;
        }
        L = L -> next;
    }
    return false;
}

GoodsList* search_item(GoodsList *L, char* goods_id)
{
    while (L -> next != NULL)
    {
        if (strcmp(L -> next -> data.goods_id, goods_id) == 0)
        {
            return L -> next;
        }
        L = L -> next;
    }
    return NULL;
}

bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info)
{
    while (L -> next != NULL)
    {
        if (strcmp(L -> next -> data.goods_id, goods_id) == 0)
        {
            L -> next -> data = new_info;
            return true;
        }
        L = L -> next;
    }
    return false;
}

void bubble_sort(GoodsList *L)
{
    GoodsList *cur = L;
    for (int i = 1; i <= CurrentCnt; i++)
    {
        int curPrice = cur -> next -> data.goods_price;
        GoodsList *ans = NULL, *tmp = cur -> next;
        for (int j = i + 1; j <= CurrentCnt; j++)
        {
            if (tmp -> next -> data.goods_price < curPrice)
            {
                curPrice = tmp -> next -> data.goods_price;
                ans = tmp;
            }
            tmp = tmp -> next;
        }
        if (ans != NULL)
        {
            GoodsInfo swp = cur -> next -> data;
            cur -> next -> data = ans -> next -> data;
            ans -> next -> data = swp;
        }
        cur = cur -> next;
    }
}