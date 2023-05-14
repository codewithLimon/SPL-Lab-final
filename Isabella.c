#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// define array sizes
#define NAME 100
#define BIRTH_DAY 50
#define HOUSE 30
#define PURCHASES 3

// define house names
#define HOUSE1 "Gryffindor"
#define HOUSE2 "Slytherin"

// structure to contain the data of customers
typedef struct
{
    int customer_id;
    char customer_name[NAME];
    char customer_birthday[BIRTH_DAY];
    char house_ctg[HOUSE];
    int purchase_cost_of_last_3_months[PURCHASES];
    float average_purchase;
} Customer;

// Returns 1 if the searchString is a substring of the mainString, 0 otherwise
int substringChecker(char *mainString, char *searchString)
{
    int len1 = strlen(mainString);
    int len2 = strlen(searchString);

    if (len2 > len1)
    {
        return 0;
    }

    for (int i = 0; i <= len1 - len2; i++)
    {
        int j;
        for (j = 0; j < len2; j++)
        {
            if (mainString[i + j] != searchString[j])
            {
                break;
            }
        }
        if (j == len2)
        {
            return 1;
        }
    }

    return 0;
}

// inputs

void inputs(Customer *customers, int customers_number)
{

    for (int i = 0; i < customers_number; i++)
    {
        printf("\n\nCustomer %d: \n\n", i+1);

        // set customer id automatically through the loop
        customers[i].customer_id = i;
        fflush(stdin);

        // get customer name from user
        printf("Name: ");
        gets(customers[i].customer_name);
        fflush(stdin);

        // get customer birthday from user
        printf("Birthday: ");
        gets(customers[i].customer_birthday);
        fflush(stdin);

        // get customer house from user
        printf("House: ");
        gets(customers[i].house_ctg);
        fflush(stdin);

        // get customer last three month purchase cost hisory from user
        // and calculate the average purchase then store it on structure
        printf("Purchase: ");
        fflush(stdin);

        int sum = 0;

        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &customers[i].purchase_cost_of_last_3_months[j]);
            sum += customers[i].purchase_cost_of_last_3_months[j];
            
        }

        customers[i].average_purchase = sum / 3;
        fflush(stdin);
    }
}

int main()
{
     system("cls");
    int size;

    printf("Num of Customer: ");
    scanf("%d", &size);

    fflush(stdin);

    Customer customers[size];
    inputs(customers, size);

    int max, max2, max3;
    max3 = max = max2 = customers[0].average_purchase;
    int index1, index2, index3;

    int flag = 0;

    for (int i = 0; i < size; i++)
    {
        if (strcmp(customers[i].house_ctg, HOUSE1) == 0)
        {
            flag = 1;

            if (substringChecker(customers[i].customer_name, "est") == 1)
            {
                if (customers[i].average_purchase > max)
                {
                    max3 = max2;
                    max2 = max;
                    max = customers[i].average_purchase;
                    index1 = i;
                }
                else if (customers[i].average_purchase > max2)
                {
                    max3 = max2;
                    max2 = customers[i].average_purchase;
                    index2 = i;
                }
                else if (customers[i].average_purchase > max3)
                {
                    max3 = customers[i].average_purchase;
                    index3 = i;
                }
            }
        }

        else if (strcmp(customers[i].house_ctg, HOUSE2) == 0)
        {
            flag = 2;

            if (substringChecker(customers[i].customer_name, "rus") == 1)
            {
                if (customers[i].average_purchase > max)
                {
                    max3 = max2;
                    max2 = max;
                    max = customers[i].average_purchase;
                    index1 = i;
                }
                else if (customers[i].average_purchase > max2)
                {
                    max3 = max2;
                    max2 = customers[i].average_purchase;
                    index2 = i;
                }
                else if (customers[i].average_purchase > max3)
                {
                    max3 = customers[i].average_purchase;
                    index3 = i;
                }
            }
        }
    }


    printf("\nList of Loyal Customers: \n");

    printf("\nGryffindor: \n");

    if (flag != 1)
    {
        printf("Nil");
    }
    else
    {
        printf("%s | %s | %f",customers[index1].customer_name,customers[index1].customer_birthday,customers[index1].purchase_cost_of_last_3_months);

        if(index2!=NULL){
            printf("%s | %s | %f",customers[index2].customer_name,customers[index2].customer_birthday,customers[index2].purchase_cost_of_last_3_months);
        }
        if(index3!=NULL){
            printf("%s | %s | %f",customers[index3].customer_name,customers[index3].customer_birthday,customers[index3].purchase_cost_of_last_3_months);
        }
    }


    printf("\n\nSlytherin: \n");
    if (flag != 2)
    {
        printf("Nil");
    }
    else
    {
        printf("%s | %s | %f",customers[index1].customer_name,customers[index1].customer_birthday,customers[index1].purchase_cost_of_last_3_months);

        if(index2!=NULL){
            printf("%s | %s | %f",customers[index2].customer_name,customers[index2].customer_birthday,customers[index2].purchase_cost_of_last_3_months);
        }
        if(index3!=NULL){
            printf("%s | %s | %f",customers[index3].customer_name,customers[index3].customer_birthday,customers[index3].purchase_cost_of_last_3_months);
        }
    }

}