/*
"3. Thực hành code C basic (áp dụng các coding convention):
    Viết chương trình C thực hiện việc sau:
    Có 3 kiểu người: ăn xin, ăn trộm và công nhân. 
    Định nghĩa một kiểu someone_t là một struct đại diện cho 1 người gồm các trường sau:
    - type: là một chuỗi kí tự lưu kiểu người: ""anxin"", ""antrom"", ""congnhan""
    - income: là một trường lưu thông tin thu nhập của người đó. Nếu type:
        + anxin: thì income là chuỗi kí tự có giá trị ""tuytam""
        + antrom: thì income là chuỗi kí tự có giá trị ""henxui""
        + congnhan: thì income là số nguyên 2 bytes có giá trị là 500000
    - action: là một con trỏ hàm (với biến đầu vào có kiểu someone_t) trỏ tới công việc của mỗi người.  Nếu type:
        + anxin: thực hiện hàm cadge(): in ra chuỗi ""lam on lam phuoc""
        + antrom: thực hiện hàm stole(): in ra chuỗi ""!!!""
        + congnhan: thực hiện hàm work(): in ra income của người này
    Hàm main() thực hiện việc sau:
    - Tạo ngẫu nhiên N người thuộc có kiểu someone_t và lưu vào mảng có kích thước MAX_PEOPLE(cần được define). 
    - Duyệt mảng trên và thực hiện hàm action của mỗi người, các chuỗi đầu ra được in lần lượt vào file ""output.txt"""
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 3

FILE *fptr;

union income
{
    char income_str[16];
    short int income_short;
};

typedef struct 
{
    /* data */
    char *type;
    union income income;
    void (*action)(union income income);  
}someone_t;

someone_t nguoi[MAX_PEOPLE];

void cadge(union income income)
{
   printf("Lam on lam phuoc \n");
   //char *s = "Lam on lam phuoc \n";
   //fprintf(stdout,"%s",s);
   fprintf(fptr,"%s","Lam on lam phuoc");
   
}

void stole(union income income)
{
   //char *s = "!!! \n";
   printf("!!!!! \n");
   //fprintf(stdout,"%s",s);
   fprintf(fptr,"%s","!!!!! \n");
}

void work(union income income)
{
   printf("Income: %d \n",income.income_short);
   fprintf(fptr,"%d \n",income.income_short);

}


int main()
{
    int i = 0;
    nguoi[0].type = "anxin";
    nguoi[1].type = "antrom";
    nguoi[2].type = "congnhan";

    fptr = fopen("output.txt","a");
 
    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }
    for(i=0;i<MAX_PEOPLE;i++)
    {
        if(!strcmp(nguoi[i].type,"anxin"))
        {
            strcpy(nguoi[i].income.income_str,"tuytam");
            printf("%s, %s \n ",nguoi[i].type,nguoi[i].income.income_str);
            nguoi[i].action = cadge;
            (*nguoi[i].action)(nguoi[i].income);
        }
        else if(!strcmp(nguoi[i].type,"antrom"))
        {
            strcpy(nguoi[i].income.income_str,"henxui");
            printf("%s, %s \n ",nguoi[i].type,nguoi[i].income.income_str);
            nguoi[i].action = stole;
            (*nguoi[i].action)(nguoi[i].income);
        }
        else
        {
            nguoi[i].income.income_short = 5000;
            nguoi[i].action = work;
            (*nguoi[i].action)(nguoi[i].income);
        }

    }
    fclose(fptr);
    return 0;
}