// Develop a “C program” to manage electricity consumption and billing information. You are required to utilize
// structures to encapsulate details about the electricity usage for different days and implement a tiered billing
// system with different rates for various consumption levels. The program should analyze and display
// comprehensive information about a customer's electricity consumption.
// Part A. Structures Definition [1+1+1 = 3 points]
// • Structure “DailyConsumption” with members day representing the day of the month, unitsConsumed
// representing units of electricity consumed on that day.
// • Structure “ElectricityBill” with members customerName representing the name of the customer, customerID
// representing the customer's unique identifier, and dailyConsumptions containing details for each day for 30
// days.
// • Structure “BillingTier” with members rate representing the rate per unit for the tier, upperLimit representing
// the upper limit for the tier(example given below). If -1.0, it indicates an unlimited upper limit.
// struct BillingTier billingTiers[] = {
//  {0.10, 50.0}, // Rate for the first 50 units
//  {0.15, 100.0}, // Rate for the next 50 units
//  {0.20, -1.0} // Rate for any units beyond 100 (unlimited)
//  };
// Part B. Functions [4+4+4 = 12 points]
// 1. Write a function “calculateTotalConsumption” to calculate and return the total units of electricity consumed.
// The function should print the total bill based on defined billing tiers as well.
// 2. Write a function “findUnitFrequency”, the function prints frequency of each day’s units consumed. E.g. 200
// units consumed on day 1, day 2 and day 7 then 200 units frequency is 3.
// 3. Write a function “Analysis” to display the days with the second highest and third lowest electricity
// consumption.

#include <stdio.h>
#include <string.h>

typedef struct
{
    int day;
    float unitscons;
} dailycons;

typedef struct
{
    char name[50];
    int id;
    dailycons dailyconsumptions[30];
} electbill;

typedef struct
{
    float rate;
    float upperlimit;
} billingtier;

billingtier billingTiers[] = {
    {0.10, 50.0},  // Rate for first 50 units
    {0.15, 100.0}, // Rate for next 50 units
    {0.20, -1.0}   // Rate beyond 100 units (unlimited)
};

int main()
{
    electbill customer1;
    customer1.id = 101;
    strcpy(customer1.name, "Alice");

    for (int i = 0; i < 30; i++)
    {
        customer1.dailyconsumptions[i].day = i + 1;
        customer1.dailyconsumptions[i].unitscons = 12.5; // example
    }

    printf("Customer: %s\n", customer1.name);
    printf("Customer ID: %d\n", customer1.id);
    printf("Day 1 consumption: %.2f units\n", customer1.dailyconsumptions[0].unitscons);

    return 0;
}