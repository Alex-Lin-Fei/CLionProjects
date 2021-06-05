#include <stdio.h>


/*
 * exercise 1
 * */
/*
 * 表示长途电话付账记录的结构
 * */
struct PHONE_NUMBER {
    short area;
    short exchange;
    short station;
};

struct LONG_DISTANCE_BILL {
    short month;
    short day;
    short year;
    int time;
    struct PHONE_NUMBER called;
    struct PHONE_NUMBER calling;
    struct PHONE_NUMBER billed;
};


/*
 * exercise 2
 * */
struct INFO {
    char cust_name[21];
    char cust_address[41];
    char mode[21];
    enum {PURE_CASH, CASH_LOAN, LEASE} type;
    union {
        struct {

        } pure_cash;

        struct {

        } cash_loan;
        struct {

        }lease;
    } info;
};
