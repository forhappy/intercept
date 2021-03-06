#ifndef  TC_ROUTER_INCLUDED
#define  TC_ROUTER_INCLUDED

#include <xcopy.h> 

typedef struct route_item_s {
    time_t   timestamp;
#if (TC_MILLION_SUPPORT)
    uint64_t key;
#else
    uint16_t key;
#endif
    uint16_t fd;
}route_item_t;

typedef struct route_slot_s {
    uint32_t     num:6;
    route_item_t items[ROUTE_ARRAY_SIZE];
}route_slot_t;


typedef struct route_table_s {
    uint64_t     slot_full_cnt;
    uint64_t     hit;
    uint64_t     missed;
    uint64_t     lost;
    uint64_t     extra_compared;
    uint64_t     searched;
    uint64_t     total_sessions;
    route_item_t cache[ROUTE_SLOTS];
    route_slot_t slots[ROUTE_SLOTS];
}route_table_t;

int router_init(tc_pool_t *pool);

void router_add(uint32_t, uint16_t, uint32_t, uint16_t, int);
void router_update(tc_iph_t *);
void router_stat(void);
void router_destroy(tc_pool_t *);

#endif /* TC_ROUTER_INCLUDED */

