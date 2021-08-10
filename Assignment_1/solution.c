// *(Written by Aditya Kotwal)*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
int mod(int a)
{
    if (a < 0)
        return -a;
    return a;
}
struct shop
{
    int price;
    float quality; //ranging from 0-1
    long long int gps;
    struct shop *nxt_price;
    struct shop *nxt_quality;
    struct shop *location;
} *head_price = NULL, *head_quality = NULL;
void insert_by_price(struct shop *new_Shop, int price)
{
    struct shop *p = head_price, *q = NULL;
    if (head_price == NULL)
    {
        head_price = new_Shop;
        new_Shop->nxt_price = NULL;
    }
    else
    {
        while (p != NULL && p->price <= price)
        {
            q = p;
            p = p->nxt_price;
        }
        //if p=null then insert last || if q=null insert at first || insert in between
        if (p == NULL)
        {
            q->nxt_price = new_Shop;
            new_Shop->nxt_price = NULL;
        }
        else if (q == NULL)
        {

            new_Shop->nxt_price = head_price;
            head_price = new_Shop;
        }
        else
        {
            q->nxt_price = new_Shop;
            new_Shop->nxt_price = p;
        }
    }
}
void insert_by_quality(struct shop *newShop, float quality)
{
    struct shop *p = head_quality, *q = NULL;
    if (head_quality == NULL)
    {
        head_quality = newShop;
        newShop->nxt_price = NULL;
    }
    else
    {
        while (p != NULL && p->quality <= quality)
        {
            q = p;
            p = p->nxt_quality;
        }
        //if p=null then insert last || if q=null insert at first || insert in between
        if (p == NULL)
        {
            q->nxt_quality = newShop;
            newShop->nxt_quality = NULL;
        }
        else if (q == NULL)
        {
            newShop->nxt_quality = head_quality;
            head_quality = newShop;
        }
        else
        {
            q->nxt_quality = newShop;
            newShop->nxt_quality = p;
        }
    }
}
void display_by_price()
{
    struct shop *traverse = head_price;
    if (traverse == NULL)
    {
        printf("\nNo shops!!\n\n");
    }
    else
    {
        printf("\n\nCheap -> Expensive\nRs.");

        while (traverse->nxt_price != NULL)
        {
            printf("%d ->", traverse->price);
            traverse = traverse->nxt_price;
        }
        printf("%d\n\n", traverse->price);
    }
}
void display_by_quality()
{
    struct shop *traverse = head_quality;
    if (traverse == NULL)
    {
        printf("\nNo shops!!\n\n");
    }
    else
    {
        printf("\n\nWorst -> Best\n");
        while (traverse->nxt_quality != NULL)
        {
            printf("%.2f -> ", traverse->quality);
            traverse = traverse->nxt_quality;
        }
        printf("%.2f\n\n", traverse->quality);
    }
}
void closest(int currentlocation)
{
    struct shop *trav = head_price;
    int distance = INT_MAX;
    int price;
    float quality;
    if (trav == NULL)
    {
        printf("\nCurrently no shops registered!\n\n");
        return;
    }

    while (trav != NULL)
    {
        if (distance > mod(currentlocation - trav->gps))
        {
            price = trav->price;
            quality = trav->quality;
            distance = mod(currentlocation - trav->gps);
        }
        trav = trav->nxt_price;
    }
    printf("\n\nClosest one to you is at distance: %d\nOffers (Price:%d INR) and (Quality:%.2f)\n\n", distance, price, quality);
}
void Insert_shop(int price, float quality, long long int location)
{
    struct shop *newShop = (struct shop *)malloc(sizeof(struct shop));
    newShop->price = price;
    newShop->quality = quality;
    newShop->gps = location;
    insert_by_price(newShop, price);
    insert_by_quality(newShop, quality);
    //Currently there is no sort by Location
}
int main()
{
    int intialPos;
    printf("\nCurrently where You standing(X-axis):");
    if (scanf("%d", &intialPos) == false)
    {
        printf("\nInvalid Input!!!\n");
        return 0;
    }
    printf("\n\n----------------------------Welcome to Raghunath Bazaar Jammu----------------------------\n\n");
    int c;
    do
    {
        printf("1.Register a shop\n");
        printf("2.Find Closest Shop near me\n");
        printf("3.Sort the Shops by Price\n");
        printf("4.Sort the Shops by Quality\n");
        printf("choice:");
        scanf("%d", &c);
        if (c == 1)
        {
            int x;
            float y;
            long long Location;
            printf("Enter Price,Quality(0-1) & Locations(X-axis):\n");
            if (scanf("%d%f%lld", &x, &y, &Location) == false)
            {
                printf("Invalid Input leads to Termination of program!!!\n");
                return 0;
            }
            else
            {
                if ((y < 0 || y > 1))
                {
                    printf("\nPlease Enter Quality between '0' to '1'!\n");
                }
                else
                {

                    Insert_shop(x, y, Location);
                    printf("\nSuccessfully registered the shop.\n");
                }
            }
        }
        else if (c == 2)
        {
            closest(intialPos);
        }

        else if (c == 3)
        {
            display_by_price();
        }
        else if (c == 4)
        {
            display_by_quality();
        }

    } while (c <= 4 && c >= 1);

    return 0;
}
