//  SIMULATE AND IMPLEMENT Stop and Wait Protocol for Noisy Channel (Only For Output)
// File Name : stop&wait.c
// For Dev C++
// ---------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#define MAXSIZE 100
typedef struct
{
    unsigned char data[MAXSIZE];
} packet;
typedef enum
{
    data,
    ack
} frame_kind;
typedef struct
{
    frame_kind kind;
    int sq_no;
    int ack;
    packet info;
} frame;
typedef enum
{
    frame_arrival
} event_type;
typedef enum
{
    true_false
} boolean;
void frame_network_layer(packet *p)
{
    printf("\n from network arrival");
}
void to_physical_layer(frame *f)
{
    printf("\n to physical layer");
}
void wait_for_event(event_type *e)
{
    printf("\n waiting for event n");
}
void sender(void)
{
    frame s;
    packet buffer;
    event_type event;
    printf("\n ***SENDER***");
    frame_network_layer(&buffer);
    s.info = buffer;
    to_physical_layer(&s);
    wait_for_event(&event);
}
void from_physical_layer(frame *f)
{
    printf("from physical layer");
}
void to_network_layer(packet *p)
{
    printf("\n to network layer");
}
void receiver(void)
{
    frame r, s;
    event_type event;
    printf("\n ***RECEIVER***");
    wait_for_event(&event);
    from_physical_layer(&r);
    to_network_layer(&r.info);
    to_physical_layer(&s);
}
int main()
{
    sender();
    receiver();
    return 0;
    getch();
}