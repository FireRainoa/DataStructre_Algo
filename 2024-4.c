/*
#### 4.一个仓库有m(m<100)件货物，其中name表示货物的名称，num(n<1000)表示货物的数量price(n<100000)表示货物的金额。请你在主函数中实现货物的输入和输出，并编写以下三个函数来实现如下功能:

- 货物中数量最多货物的名称
- 货物中价格最高货物的名称
- 仓库中所有货物的总价值
*/
#include <stdio.h>
#include <string.h>
#define m 100

typedef struct product{
    char name[20];
    int num;
    double price;
} P;

char* getmostN(P* ps, int l) {
    int maxindex = 0;
    for (int i = 0; i < l; i++) {
        if(ps[i].num > ps[maxindex].num) {
            maxindex = i;
        }
    }
    return ps[maxindex].name;
}

char* getmostP(P* ps, int l) {
    int maxindex = 0;
    for (int i = 0; i < l; i++ ){
        if (ps[i].price > ps[maxindex].price) {
            maxindex = i;
        }
    }

    // 此处不可以返回局部变量函数结束后局部变量的内存会被释放，此时返回它的地址是非法的
    return ps[maxindex].name;
}

long long getSum(P* ps, int l) {
    // 此处sum应先初始化
    // long long sum;
    long long sum = 0L;
    for (int i = 0; i < l; i++) {
        sum += ps[i].num * ps[i].price;
    }
    return sum;
}

int main() {
    struct product ps[m];
    char name[20];
    char str[] = "";
    char *str[]= {"ss", "aa"};
    int num;
    double price;
    for (int i = 0; i < m; i++) {
        scanf("%s %d %lf", name, &num, &price);
        strcpy(ps[i].name, name);
        ps[i].num = num;
        ps[i].price = price;
    }
    char* maxNum = getmostN(ps, sizeof(ps) / sizeof(ps[0]));
    char* maxPrice = getmostP(ps, sizeof(ps) / sizeof(ps[0]));
    long long sum = getSum(ps, sizeof(ps) / sizeof(ps[0]));
    printf("%s", maxNum);
    printf("%s", maxPrice);
    // sum为longlong类型,所以此处输出格式应为%lld
    printf("%lld", sum);

    return 0;
}